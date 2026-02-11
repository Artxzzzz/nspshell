#ifndef CONFIG_H
#define CONFIG_H

#include <stddef.h>

/* ==================== CONSTANTS ==================== */

#define MAX_PATH_LEN 4096
#define MAX_TIP_LEN 1024
#define MAX_TIPS 100

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

extern char actualPath[];
void initPath(void);

#endif
