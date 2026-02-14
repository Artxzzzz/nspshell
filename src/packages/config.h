#ifndef CONFIG_H
#define CONFIG_H

#include <stddef.h>

/* ==================== CONSTANTS ==================== */

#define MAX_PATH_LEN 4096
#define MAX_TIP_LEN 1024
#define MAX_TIPS 100

#define MAX_ALIAS 1000
#define MAX_ALIAS_LEN 1024

#define MAX_CMD_LEN 256

extern const char *prompt;
extern const char *version;

typedef int (*builtinFunc)(int argc, char **argv);

struct builtin {
    const char *name;
    const char *tip;
    builtinFunc func;
};

extern const struct builtin builtins[];

extern const size_t builtinSize;

// ===================================================

extern char configFolder[];
extern char actualPath[];
extern char pathCopy[];

void init(void);

#endif
