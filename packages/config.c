#include "config.h"
#include <stdlib.h>

/* ==================== CONSTANTS ==================== */

const char *prompt = " >>";
const char *version = "v0.0.2-alpha";

// ===================================================

char *actualPath = NULL;
void initPath() {
    char* home = getenv("HOME");
    actualPath = (home != NULL) ? home : getenv("USERPROFILE");
}