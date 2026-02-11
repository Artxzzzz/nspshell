#include <stdio.h>
#include "pwd.h"
#include "../../packages/config.h"

int pwd(int argc, char **argv) {
    (void)argc;
    (void)argv;
    printf("%s\n", actualPath);
    return 0;
}