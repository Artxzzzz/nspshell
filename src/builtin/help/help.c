#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#include "../../packages/config.h"


void searchExternals(char *ext, const char *pathEnv, int *extHeader) {
    char copy[4096];
    strncpy(copy, pathEnv, sizeof(copy));
    copy[sizeof(copy)-1] = '\0';

    char *dir = strtok(copy, ";");

    while (dir != NULL) {
        if (strstr(dir, "externals") == NULL) { // If dir are externals, continue and go to next dir
            dir = strtok(NULL, ";");
            continue;
        }

        char searchPath[4096];

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

                printf("%.*s\n", (int)len, findFileData.cFileName);

            } while (FindNextFile(hFind, &findFileData) != 0);

            FindClose(hFind);
        }

        dir = strtok(NULL, ";");
    }
}

int help(char *args) {
    (void)args; // invalidate args

    const char *pathEnv = getenv("PATH");  // Get env from path
    int inPath = strstr(pathEnv, "externals") != NULL; // a bool if externals in path

    /* ==================== Built-In Help ==================== */

    printf("====================== Built-in Command ======================\n"); // Visual

    for (int func = 0; func < builtinSize; func++) {
        printf("%s: %s\n", builtins[func].name, builtins[func].tip);
    }

    // ======================================================= 


    // Externals

    if (inPath) {
        int extHeader = 0;
        const char* exts[] = {"exe", "bat", "cmd"};

        for (int ext = 0; ext < sizeof(exts) / sizeof(exts[0]); ext++) {
            searchExternals(exts[ext], pathEnv, &extHeader);
        }
    } 


    return 0;
}
