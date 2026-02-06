#include <windows.h>
#include <stdio.h>

int main(int argc, char *argv[]) {

    char *path;
    if (argc < 2) {
        path = ".";
    } else {
        path = argv[1];
    }

    char searchPath[MAX_PATH];
    snprintf(searchPath, MAX_PATH, "%s\\*", path);

    WIN32_FIND_DATAA fd;
    HANDLE hFind = FindFirstFileA(searchPath, &fd);

    if (hFind == INVALID_HANDLE_VALUE) {
        printf("ls: Cannot open directory %s\n", path);
        return 1;
    }

    do {
        printf("%s\n", fd.cFileName);
    } while (FindNextFileA(hFind, &fd));

    FindClose(hFind);
    
    return 0;
}
