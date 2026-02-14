#ifndef LOAD_H
#define LOAD_H

#include "../../../packages/config.h"

typedef struct {
    char aliasses[MAX_ALIAS_LEN];
    char command[MAX_ALIAS_LEN];
} aliasStruct;

int load(char* dir, aliasStruct* aliasses, int* count);

#endif
