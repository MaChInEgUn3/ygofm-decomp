#include "common.h"

u8 func_8007058C(void) {
    u8 *p = D_800F5BE8.cursor;
    u8 v = *p;

    D_800F5BE8.cursor = p + 1;
    return v;
}
