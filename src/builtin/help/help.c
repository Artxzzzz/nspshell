#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#include "../../packages/config.h"
#include "tip/tips.h"
#include "search/search.h"

int help(int argc, char **argv) {
    const char *pathEnv = getenv("PATH");  // Get env from path
    int inPath = strstr(pathEnv, "externals") != NULL; // a bool if externals in path


    if (argc > 1) {
        for (int c = 0; argv[1][c] != '\0'; c++) argv[1][c] = tolower((unsigned char) argv[1][c]);

        for (int func = 0; func < builtinSize; func++) {

            if (strcmp(argv[1], builtins[func].name) == 0) {
                printf("%s: %s\n", builtins[func].name, builtins[func].tip);
                return 0;
            }
        }

    char copy[MAX_PATH_LEN];
    strncpy(copy, pathEnv, sizeof(copy));
    copy[sizeof(copy)-1] = '\0';

    char *dir = strtok(copy, ";");

    Tip tips[MAX_TIPS];
    int tipCount = 0;

    while (dir != NULL) {
        if (strstr(dir, "externals") == NULL) { // If dir not are externals, continue and go to next dir
            dir = strtok(NULL, ";");
            continue;
        }
        
        tipCount = 0;
        loadTips(dir, tips, &tipCount);

        for (int func = 0; func < tipCount; func++) {
            if (strcmp(argv[1], tips[func].command) == 0) {
                printf("%s: %s\n", tips[func].command, tips[func].tip);
                return 0;
            }
        }

        dir = strtok(NULL, ";");
    }

        printf("%s: not found\n", argv[1]);
        return 1;
    }

    /* ==================== Built-In Help ==================== */

    printf("\n---------- Built-in Command ---------- \n"); // Visual

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
