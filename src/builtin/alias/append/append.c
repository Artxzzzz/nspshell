#include <stdio.h>
#include <string.h>

#include "append.h"
#include "../alias.h"
#include "../../../packages/config.h"

int append(char *cont) {
    FILE *f;

    f = fopen(pathCopy, "a");

    if (f == NULL) {
        perror("fopen");
        return 1;
    }

    fprintf(f, "%s", cont);

    fclose(f);
    return 0;
}