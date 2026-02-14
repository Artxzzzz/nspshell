#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "alias.h"
#include "../../packages/config.h"

aliasStruct aliasses[MAX_ALIAS];
int count = 0;

int alias(int argc, char **argv) {
    count = 0;
    load(pathCopy, aliasses, &count);

    if (argc < 2) {
        printf("Use: alias <name> <command> or alias --remove <name>\n");
        
        return 1;
    }

    if (strcmp(argv[1], "--remove") == 0) {
        if (argc < 3) {
            printf("Use: alias --remove <name>\n");
            return 1;
        }

        return removeAlias(argv[2]);
    }


    if (argc < 3) {
        printf("Use: alias <aliasses> <command>\n");
        return 1;
    }

    char *aliasName = argv[1];
    char *cmd = argv[2];

    size_t len = strlen(aliasName) + strlen(cmd) + 3;
    char *asmb = malloc(len);

    if (asmb == NULL) {
        printf("Error to concat alias\n");
        return 1;
    }

    for (int i = 0; i < count; i++) {
        if (strcmp(aliasName, aliasses[i].aliasses) == 0) {
            printf("alias: aldery have a alias with <%s> name.\n", aliasName);

            free(asmb);
            return 1;
        }
    }

    snprintf(asmb, len, "%s\t%s\n", aliasName, cmd);

    append(asmb);
    
    count = 0;
    load(pathCopy, aliasses, &count);

    free(asmb);

    return 0;
}