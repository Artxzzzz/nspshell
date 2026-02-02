#include "config.h"
#include "../builtin/builtin.h"

#include <stdlib.h>
#include <stddef.h>
#include <windows.h>

/* ==================== CONSTANTS ==================== */

const char *prompt = " >> ";
const char *version = "v0.1.2-beta";
typedef int (*builtinFunc)(char *args);

const struct builtin builtins[] = {
    {"cd", cd},
    {"exit", exitfunc}
};

const size_t builtinSize = sizeof(builtins) / sizeof(builtins[0]);

// ===================================================

char *actualPath = NULL;
void initPath() {
    char* home = getenv("HOME");
    actualPath = (home != NULL) ? home : getenv("USERPROFILE");

    if (actualPath != NULL) {
        // Sincroniza diretório real do processo com actualPath
        SetCurrentDirectoryA(actualPath);
    }
}
