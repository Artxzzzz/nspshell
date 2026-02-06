#ifndef CONFIG_H
#define CONFIG_H

#include <stddef.h>

/* ==================== CONSTANTS ==================== */

extern const char *prompt;
extern const char *version;

typedef int (*builtinFunc)(char *args);

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
