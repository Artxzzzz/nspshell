#include "config.h"
#include "../builtin/builtin.h"

#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <windows.h>
#include <direct.h>
#include <lmcons.h>

/* ==================== CONSTANTS ==================== */

const char *prompt = " >> ";
const char *version = "v1.0.9";

const struct builtin builtins[] = { // name, tip, function
    {"cd", "alter actual directory", cd},
    {"exit", "exit of the shell" , exitfunc},
    {"pwd", "show actual directory", pwd},
    {"help", "show this message", help},
    {"alias", "set aliases to command", alias}
};

const size_t builtinSize = sizeof(builtins) / sizeof(builtins[0]);

// ===================================================

char actualPath[MAX_PATH];
char configFolder[MAX_PATH];
char pathCopy[MAX_PATH_LEN];

void init(char *username, char *hostname) {
    BOOL WINAPI CtrlHandler(DWORD fdwCtrlType);

    SetConsoleCtrlHandler(CtrlHandler, TRUE);
    SetConsoleOutputCP(CP_UTF8);

    DWORD usernameLen = UNLEN+1;
    GetUserNameA(username, &usernameLen);

    DWORD hostnameLen = MAX_COMPUTERNAME_LENGTH + 1;
    GetComputerNameA(hostname, &hostnameLen);

    char* home = getenv("HOME");
    if (home == NULL) home = getenv("USERPROFILE");
    if (home == NULL) home = ".";

    strncpy(actualPath, home, MAX_PATH - 1);
    actualPath[MAX_PATH - 1] = '\0';
    strncpy(configFolder, home, MAX_PATH - 1);
    configFolder[MAX_PATH - 1] = '\0';

    snprintf(configFolder, MAX_PATH, "%s\\.config\\nspsh", home);

    snprintf(pathCopy, MAX_PATH_LEN, "%s\\config.cfg", configFolder);

    char baseConfig[MAX_PATH];
    snprintf(baseConfig, MAX_PATH, "%s\\.config", home);
    _mkdir(baseConfig);
    _mkdir(configFolder);


    load(pathCopy, aliasses, &count);


    SetCurrentDirectoryA(actualPath);
}

