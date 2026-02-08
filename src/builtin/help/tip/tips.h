#ifndef TIPS_H
#define TIPS_H

#include "../../../packages/config.h"

typedef struct {
    char command[MAX_TIP_LEN];
    char tip[MAX_TIP_LEN];
} Tip;

int loadTips(const char* dir, Tip* tips, int* tipCount);

#endif
