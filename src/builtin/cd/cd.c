#include <windows.h>
#include <stdio.h>
#include <string.h>

#include "..\\..\\packages\\config.h"

int cd(char *path) {
    char fullPath[MAX_PATH];

    if (path[0] == '\0' || path[0] == '~') {
        char *home = getenv("HOME");
        if (!home) home = getenv("USERPROFILE");

        if (home) {
            static char expanded[MAX_PATH];

            if (path[0] == '\0') {
                snprintf(expanded, sizeof(expanded), "%s", home);
            }else {
                snprintf(expanded, sizeof(expanded), "%s%s", home, path + 1);
            }

            path = expanded;
        }
    }


    if (!SetCurrentDirectoryA(path)) {
        DWORD err = GetLastError();
        switch(err) {
            case ERROR_FILE_NOT_FOUND:
            case ERROR_PATH_NOT_FOUND:
                printf("cd: No such file or directory\n");
                break;
            case ERROR_ACCESS_DENIED:
                printf("cd: Permission denied\n");
                break;
            default:
                printf("cd: Unknown error (%lu)\n", err);
        }
        return 1;
    }

    if (!GetCurrentDirectoryA(MAX_PATH, fullPath)) {
        printf("cd: Failed to get current directory\n");
        return 1;
    }

    if (!GetLongPathNameA(fullPath, actualPath, MAX_PATH)) {
        strcpy(actualPath, fullPath);
    }

    return 0;
}
