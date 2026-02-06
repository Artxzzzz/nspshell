#ifndef COLORS_H
#define COLORS_H

typedef struct {
    const char *name;
    const char *value;
} Colors;

const Colors COLORS[] = {
    {"BLACK",   "\x1b[30m"},
    {"RED",     "\x1b[31m"},
    {"GREEN",   "\x1b[32m"},
    {"YELLOW",  "\x1b[33m"},
    {"BLUE",    "\x1b[34m"},
    {"MAGENTA", "\x1b[35m"},
    {"CYAN",    "\x1b[36m"},
    {"GRAY",   "\x1b[37m"},
    {"WHITE",   "\x1b[0m"},
};

const int COLORSIZE = sizeof(COLORS)/sizeof(COLORS[0]);

#endif
