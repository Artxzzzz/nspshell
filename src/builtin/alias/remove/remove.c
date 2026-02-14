#include <stdio.h>
#include <string.h>

#include "remove.h"
#include "../alias.h"
#include "../../../packages/config.h"

int removeAlias(const char *name) {
    FILE *f = fopen(pathCopy, "w");
    if (!f) {
        perror("fopen");
        return 1;
    }

    int found = 0;

    for (int i = 0; i < count; i++) {
        if (strcmp(aliasses[i].aliasses, name) == 0) {
            found = 1;
            continue;
        }

        fprintf(f, "%s\t%s\n",
            aliasses[i].aliasses,
            aliasses[i].command
        );
    }

    fclose(f);

    if (!found) {
        printf("alias: \"%s\" not found\n", name);
        return 1;
    }

    printf("alias: \"%s\" removed\n", name);

    count = 0;
    load(pathCopy, aliasses, &count);

    return 0;
}
