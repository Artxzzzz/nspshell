#include <windows.h>
#include <stdio.h>

#include "exec.h"
#include "../packages/config.h"


void exec(char *cmd) {
    /* ==================== Built-In ==================== */

    for (int i = 0; i < builtinSize; i++) {
        size_t len = strlen(builtins[i].name);

        if (strncmp(cmd, builtins[i].name, len) == 0 &&
            (cmd[len] == '\0' || cmd[len] == ' ')) 
        {
            char *args = cmd + len;
            if (*args == ' ') args++;

            builtins[i].func(args);
            return;
        }
    }

    // ================================================== 


    STARTUPINFO si = {0};
    PROCESS_INFORMATION pi = {0};
    si.cb = sizeof(si);

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