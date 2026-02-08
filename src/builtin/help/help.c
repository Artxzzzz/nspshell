#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../../packages/config.h"
#include "tip/tips.h"
#include "search/search.h"

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
