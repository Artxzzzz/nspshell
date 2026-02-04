#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "colors.h"

int main(int argc, char *argv[]) { 
    if (argc < 2) {
        printf("Use: color <color>\n");
        return 1;
    }

    char *color = argv[1];
    for (int i = 0; color[i]; i++) 
        color[i] = toupper((unsigned char)color[i]);

    for (int idx = 0; idx < COLORSIZE; idx++) {
        if (strcmp(COLORS[idx].name, color) == 0) {
            printf("%s", COLORS[idx].value);
            return 0;
        }
    }

    printf("color: '%s' dont found", color);
    return 1;
}
