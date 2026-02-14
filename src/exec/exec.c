#include <windows.h>
#include <stdio.h>
#include <string.h>

#include "exec.h"
#include "../packages/config.h"
#include "../builtin/alias/alias.h"

BOOL WINAPI CtrlHandler(DWORD fdwCtrlType) {
    switch (fdwCtrlType) {
        case CTRL_C_EVENT:
            return TRUE; 
        default:
            return FALSE;
    }
}

void exec(char *cmd) {
    char first[256];
    char *space = strchr(cmd, ' ');

    if (space) {
        size_t len = space - cmd;
        strncpy(first, cmd, len);
        first[len] = '\0';
    } else {
        strcpy(first, cmd);
    }

    if (isAlias(first)) {
        char newCmd[MAX_CMD_LEN];
        snprintf(newCmd, MAX_CMD_LEN, "%s%s", getAlias(first), space ? space : "");
        strncpy(cmd, newCmd, MAX_CMD_LEN);
    }

    /* ==================== Built-In ==================== */

    for (int i = 0; i < builtinSize; i++) {
        size_t len = strlen(builtins[i].name);

        if (strncmp(cmd, builtins[i].name, len) == 0 &&
            (cmd[len] == '\0' || cmd[len] == ' ')) 
        {
            char *args = cmd + len;
            if (*args == ' ') args++;

            char *argv[64];
            int argc = 0;

            argv[argc++] = builtins[i].name;

            char *tok = args;

            while (*tok && argc < 63) {
                while (*tok == ' ') tok++;
                if (*tok == '\0') break;

                if (*tok == '"' || *tok == '\'') {
                    char quote = *tok++;
                    argv[argc++] = tok;
                    while (*tok && *tok != quote) tok++;
                    if (*tok == quote) *tok = '\0';
                    tok++;
                } else {
                    argv[argc++] = tok;
                    while (*tok && *tok != ' ') tok++;
                }

                if (*tok) *tok++ = '\0';
            }

            argv[argc] = NULL;

            builtins[i].func(argc, argv);


            return;
        }
    }

    // ================================================== 


    STARTUPINFO si = {0};
    PROCESS_INFORMATION pi = {0};
    si.cb = sizeof(si);

    SetConsoleCtrlHandler(CtrlHandler, TRUE);

    if (!CreateProcess(
        NULL,
        cmd,
        NULL,
        NULL,
        FALSE,
        0,
        NULL,
        NULL,
        &si,
        &pi
    )) {
        printf("%s: Command not found\n", cmd);
        return;
    }

    WaitForSingleObject(pi.hProcess, INFINITE);
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

}