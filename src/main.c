#include "packages/config.h"
#include "welcome/welcome.h"
#include "exec/exec.h"

#include <stdio.h>
#include <string.h>
#include <windows.h>

BOOL WINAPI CtrlHandler(DWORD fdwCtrlType);

int main(int argc, char **argv) {
    SetConsoleCtrlHandler(CtrlHandler, TRUE);
    SetConsoleOutputCP(CP_UTF8);
    int skip = 0;

    if (argc > 1) {
        if (strcmp(argv[1], "--version") == 0) {
            printf("NSPShell %s\n", version);
            return 0;
        }
        else if (strcmp(argv[1], "--skip") == 0) {
            skip = 1;
        }
    }

    if (!skip) welcomeMessage();
    init();

    while (1) {
        char command[MAX_CMD_LEN] = {0};
        
        printf("[%s]", actualPath); // Show actualPath
        printf(prompt); // Show prompt

        if (!fgets(command, sizeof(command), stdin)) {

            if (feof(stdin)) {
                printf("^C\n");
                continue;
            }
        }

        command[strcspn(command, "\n")] = 0;

        if (command[0] == '\0') { // prevents ": Command not found"
            continue;
        }

        exec(command); // Execute command
    }

    return 0;
}