#include <string.h>

#include "getAlias.h"

char *getAlias(char *cmd) {
    for (int i = 0; i < count; i++) {
        if (strcmp(aliasses[i].aliasses, cmd) == 0) {
            return aliasses[i].command;
        }
    }

    return cmd;
}
