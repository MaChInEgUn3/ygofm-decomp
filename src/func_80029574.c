#include "common.h"

void func_80029574(s32 arg0) {
    u8 *p = &D_800EA0E8[arg0 * 64];

    *(s32 *)(p + 4) = 0;
    *(s32 *)p = 0;
}
