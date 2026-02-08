#include <windows.h>
#include <stdio.h>
#include <string.h>

#include "../../../packages/config.h"
#include "../tip/tips.h"
#include "search.h"

void searchExternals(const char *ext, const char *pathEnv, int *extHeader) {
    char copy[MAX_PATH_LEN];
    strncpy(copy, pathEnv, sizeof(copy));
    copy[sizeof(copy)-1] = '\0';

    char *dir = strtok(copy, ";");

    while (dir != NULL) {
        if (strstr(dir, "externals") == NULL) { // If dir are externals, continue and go to next dir
            dir = strtok(NULL, ";");
            continue;
        }

        Tip tips[MAX_TIPS];
        int tipCount = 0;
        loadTips(dir, tips, &tipCount);

        char searchPath[MAX_PATH_LEN];
        snprintf(searchPath, sizeof(searchPath), "%s\\*.%s", dir, ext);

        WIN32_FIND_DATA findFileData;
        HANDLE hFind = FindFirstFile(searchPath, &findFileData);

        if (hFind != INVALID_HANDLE_VALUE) {
            if (!*extHeader) {
                printf("====================== Externals Command ======================\n"); // Visual
                *extHeader = 1;
            }

            do { // Loop to show
                const char* dot = strrchr(findFileData.cFileName, '.');
                size_t len = dot ? (size_t)(dot - findFileData.cFileName) : strlen(findFileData.cFileName);


                int foundTip = 0;
                for (int i = 0; i < tipCount; i++) {
                    if (strncmp(findFileData.cFileName, tips[i].command, len) == 0) {
                        printf("%.*s: %s\n", (int)len, findFileData.cFileName, tips[i].tip);
                        foundTip = 1;
                        break;
                    }
                }

                if (!foundTip) {
                    printf("%.*s\n", (int)len, findFileData.cFileName);
                }

            } while (FindNextFile(hFind, &findFileData) != 0);

            FindClose(hFind);
        }

        dir = strtok(NULL, ";");
    }

}