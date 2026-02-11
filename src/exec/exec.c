#include <windows.h>
#include <stdio.h>
#include <string.h>

#include "exec.h"
#include "../packages/config.h"

BOOL WINAPI CtrlHandler(DWORD fdwCtrlType) {
    switch (fdwCtrlType) {
        case CTRL_C_EVENT:
            return TRUE; 
        default:
            return FALSE;
    }
}

void exec(char *cmd) {
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

            char *tok = strtok(args, " ");
            while (tok && argc < 63) {
                argv[argc++] = tok;
                tok = strtok(NULL, " ");
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