#include "helpers.h"

#if defined(_WIN32) || defined(_WIN64)
    #include <windows.h>
    void msleep(float seconds) {
        Sleep((DWORD)(seconds * 1000));
    }
            
#else
    #include <unistd.h>
    void msleep(float seconds) {
        usleep(seconds * 1000000);
    }
#endif