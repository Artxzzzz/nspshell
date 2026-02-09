#include "config.h"
#include "../builtin/builtin.h"

#include <stdlib.h>
#include <stddef.h>
#include <windows.h>

/* ==================== CONSTANTS ==================== */

const char *prompt = " >> ";
const char *version = "v1.0.7";
typedef int (*builtinFunc)(char *args);

const struct builtin builtins[] = { // name, tip, function
    {"cd", "alter actual directory", cd},
    {"exit", "exit of the shell" , exitfunc},
    {"pwd", "show actual directory", pwd},
    {"help", "show this message", help}
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

