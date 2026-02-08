#include "../../../packages/config.h"
#include "tips.h"

#include <stdio.h>
#include <string.h>

int loadTips(const char* dir, Tip* tips, int* tipCount) {
    char tipPath[MAX_PATH_LEN];
    snprintf(tipPath, sizeof(tipPath), "%s\\tips.txt", dir);

    FILE* f = fopen(tipPath, "r");
    if (!f) return 0;

    char buffer[MAX_TIP_LEN];

    *tipCount = 0;

    while (fgets(buffer, sizeof(buffer), f) && *tipCount < MAX_TIPS)  {
        char *semicolon = strchr(buffer, ';');
        if (semicolon) *semicolon = '\0';

        char *dash = strchr(buffer, '-');
        if (!dash) continue;

        *dash = '\0';

        strncpy(tips[*tipCount].command, buffer, MAX_TIP_LEN-1);
        tips[*tipCount].command[MAX_TIP_LEN-1] = '\0';

        strncpy(tips[*tipCount].tip, dash+1, MAX_TIP_LEN-1);
        tips[*tipCount].tip[MAX_TIP_LEN-1] = '\0';

        (*tipCount)++;
    }

    fclose(f);

    return 1;

}
