#include <stdio.h>

#include "../helpers/helpers.h"
#include "../packages/config.h"

void welcomeMessage(void) {
    printf("Welcome to NSPShell [%s]\n", version);

    for (int dot = 0; dot < 3; dot++) {
        printf(".");
        msleep(.50);
    }

    printf("\n\n");
}