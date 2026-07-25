#include "common.h"

void func_80042A50(u8 *arg0) {
    s32 v = (*(s16 *)(arg0 + 0x34) << 8) | arg0[0x64];

    v += *(s16 *)(arg0 + 0x3A);
    arg0[0x64] = v;
    *(s16 *)(arg0 + 0x34) = v >> 8;
}
