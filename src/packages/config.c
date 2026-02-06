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
    {"exit", exitfunc},
    {"pwd", pwd}
};

const size_t builtinSize = sizeof(builtins) / sizeof(builtins[0]);

// ===================================================

char actualPath[MAX_PATH];

void initPath() {
    char* home = getenv("HOME");
    if (home == NULL) home = getenv("USERPROFILE");
    if (home == NULL) home = ".";

    strncpy(actualPath, home, MAX_PATH - 1);
    actualPath[MAX_PATH - 1] = '\0';

    SetCurrentDirectoryA(actualPath);
}

