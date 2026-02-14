#ifndef ALIAS_H
#define ALIAS_H

#include "load/load.h"
#include "check/check.h"
#include "append/append.h"
#include "get/getAlias.h"
#include "remove/remove.h"

int alias(int argc, char **argv);

extern aliasStruct aliasses[];
extern int count;

#endif
