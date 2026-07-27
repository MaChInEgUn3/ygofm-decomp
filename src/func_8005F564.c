#include "common.h"

s32 func_8005F564(void) {
    s8 v = D_8009B07A;

    if (v < 0) {
        return 0;
    }

    D_8009B07A = D_8009B07A + 1;

    return v > 0;
}
