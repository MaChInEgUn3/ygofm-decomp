#define D_8009B458_IS_AGGREGATE
#include "common.h"

void func_8004B6E8(u8 arg0, s32 arg1) {
    s32 off = arg0 * 24;
    u8 *p = D_8009B458[0];

    p += off;
    p[0] = arg1;
}
