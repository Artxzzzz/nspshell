#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#include "../../packages/config.h"

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

            snprintf(searchPath, sizeof(searchPath), "%s\\*.exe", dir);

            WIN32_FIND_DATA findFileData;
            HANDLE hFind = FindFirstFile(searchPath, &findFileData);

            if (hFind != INVALID_HANDLE_VALUE) {
                printf("====================== Externals Command ======================\n"); // Visual

                do { // Loop to show
                    printf("%s\n", findFileData.cFileName);
                } while (FindNextFile(hFind, &findFileData) != 0);

                FindClose(hFind);
            }

            dir = strtok(NULL, ";");
            
        } 

    }

    return 0;
}
