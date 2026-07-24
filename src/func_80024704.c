#include "common.h"

/* Three-way compare of two signed 16-bit values. */
s32 func_80024704(s16 *arg0, s16 *arg1) {
    if (*arg0 == *arg1) {
        return 0;
    }
    if (*arg1 < *arg0) {
        return 1;
    }
    return -1;
}
