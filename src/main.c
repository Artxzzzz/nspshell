#include "packages/config.h"
#include "welcome/welcome.h"
#include "exec/exec.h"

#include <stdio.h>
#include <string.h>

int main() {
    welcomeMessage();
    initPath();

    while (1) {
        char command[256];

        printf("[%s]", actualPath); // Show actualPath
        printf(prompt); // Show prompt

        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0;

        if (command[0] == '\0') { // prevents ": Command not found"
            continue;
        }

        exec(command); // Execute command
    }

    return 0;
}