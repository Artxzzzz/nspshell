#include "packages/config.h"
#include "welcome/welcome.h"
#include "exec/exec.h"

#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <lmcons.h>

BOOL WINAPI CtrlHandler(DWORD fdwCtrlType);

int main(int argc, char **argv) {
    SetConsoleCtrlHandler(CtrlHandler, TRUE);
    SetConsoleOutputCP(CP_UTF8);
    int skip = 0;
    static const char *MAGENTA = "\x1b[35m";
    static const char *RESET = "\x1b[0m";

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
    
    char username[UNLEN+1];
    DWORD username_len = UNLEN+1;
    GetUserNameA(username, &username_len);

    char hostname[MAX_COMPUTERNAME_LENGTH + 1];
    DWORD hostname_len = sizeof(hostname);
    GetComputerNameA(hostname, &hostname_len);
    init();

    while (1) {
        char command[MAX_CMD_LEN] = {0};

        printf(
            "(%s%s%s@%s%s%s) %s", 
            MAGENTA, username, RESET, 
            MAGENTA, hostname, RESET, 
            actualPath
        ); // Show user, host and actualPath
        
        printf("%s", prompt); // Show prompt

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