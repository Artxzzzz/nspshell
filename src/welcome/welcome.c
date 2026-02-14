#include <stdio.h>

#include "../helpers/helpers.h"
#include "../packages/config.h"
#include "welcome.h"

char *logo[] = {
" ██████   █████  █████████  ███████████   █████████  █████   █████ ██████████ █████       █████      \n",
"░░██████ ░░███  ███░░░░░███░░███░░░░░███ ███░░░░░███░░███   ░░███ ░░███░░░░░█░░███       ░░███       \n",
" ░███░███ ░███ ░███    ░░░  ░███    ░███░███    ░░░  ░███    ░███  ░███  █ ░  ░███        ░███       \n",
" ░███░░███░███ ░░█████████  ░██████████ ░░█████████  ░███████████  ░██████    ░███        ░███       \n",
" ░███ ░░██████  ░░░░░░░░███ ░███░░░░░░   ░░░░░░░░███ ░███░░░░░███  ░███░░█    ░███        ░███       \n",
" ░███  ░░█████  ███    ░███ ░███         ███    ░███ ░███    ░███  ░███ ░   █ ░███      █ ░███      █\n",
" █████  ░░█████░░█████████  █████       ░░█████████  █████   █████ ██████████ ███████████ ███████████\n",
"░░░░░    ░░░░░  ░░░░░░░░░  ░░░░░         ░░░░░░░░░  ░░░░░   ░░░░░ ░░░░░░░░░░ ░░░░░░░░░░░ ░░░░░░░░░░░ \n"
};

int lines = sizeof(logo) / sizeof(logo[0]);

void welcomeMessage(void) {
    float interval = .07;

    // Logo
    int lenLogo = sizeof(logo)/sizeof(logo[0]);
    printf("\n\n");
    for (int i = 0; i < lenLogo; i++) {
        printf("%s", logo[i]);
        msleep(interval);
    }

    printf("\n\n");

    // Banner config
    char line0[200];
    int bannerWidth = 56;
    int vlen = snprintf(NULL, 0, "NSPShell [%s]", version);
    int paddingLeft = (bannerWidth - 2 - vlen) / 2;
    int paddingRight = bannerWidth - 2 - vlen - paddingLeft;

    snprintf(line0, sizeof(line0), "*%*sNSPShell [%s]%*s*", paddingLeft, "", version, paddingRight, "");

    const char *initMsg[] = {
        "********************************************************",
        line0,
        "*  This system is for personal or limited use only.    *",
        "*  Commercial use is not permitted without permission. *",
        "*  License terms apply.                                *",
        "*  Type 'help' to get started.                         *",
        "*                                                      *",
        "********************************************************",
        ""
    };

    // Show banner
    printf("\x1b[31m");
    int len = sizeof(initMsg)/sizeof(initMsg[0]);
    for (int i = 0; i < len; i++) {
        printf("%s\n", initMsg[i]);
        fflush(stdout);
        msleep(interval);
    }

    printf("\x1b[0m");    
}
