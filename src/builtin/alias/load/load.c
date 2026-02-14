#include "../../../packages/config.h"
#include "../alias.h"
#include "load.h"

#include <stdio.h>
#include <string.h>

int load(char* dir, aliasStruct* aliasses, int* count) {
    FILE* f = fopen(dir, "r");
    if (!f) return 0;

    char buffer[MAX_ALIAS_LEN];

    *count = 0;

    while (fgets(buffer, sizeof(buffer), f) && *count < MAX_ALIAS)  {

        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        }

        char *dash = strchr(buffer, '\t');
        if (!dash) continue;

        *dash = '\0';

        strncpy(aliasses[*count].aliasses, buffer, MAX_ALIAS_LEN-1);
        aliasses[*count].aliasses[MAX_ALIAS_LEN-1] = '\0';

        strncpy(aliasses[*count].command, dash+1, MAX_ALIAS_LEN-1);
        aliasses[*count].command[MAX_ALIAS_LEN-1] = '\0';

        (*count)++;
    }

    fclose(f);

    return 1;

}
