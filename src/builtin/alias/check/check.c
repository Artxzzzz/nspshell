#include <string.h>

#include "check.h"
#include "../alias.h"

int isAlias(char check[]) {
    for (int i = 0; i < count; i++) {
        if (strcmp(aliasses[i].aliasses, check) == 0) {
            return 1;
        }
    }

    return 0;
}