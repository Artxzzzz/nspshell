#include "packages/config.h"
#include "welcome/welcome.h"
#include "exec/exec.h"

#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <lmcons.h>

#define MAGENTA "\x1b[35m"
#define RESET "\x1b[0m"

int main(int argc, char **argv) {
    char username[UNLEN+1];
    char hostname[MAX_COMPUTERNAME_LENGTH + 1];
    init(username, hostname);

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

    if (!skip) welcomeMessage(); // If dont have the skip flag, show welcome message
    
    while (1) {
        char command[MAX_CMD_LEN] = {0};

        printf(
            "(%s%s%s@%s%s%s) %s",
            MAGENTA,
            username,
            RESET,
            MAGENTA,
            hostname,
            RESET,
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