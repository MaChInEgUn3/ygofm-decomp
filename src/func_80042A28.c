#include "common.h"

void func_80042A28(u8 *arg0) {
    s32 v = (*(s16 *)(arg0 + 0x32) << 8) | arg0[0x63];

    v += *(s16 *)(arg0 + 0x38);
    arg0[0x63] = v;
    *(s16 *)(arg0 + 0x32) = v >> 8;
}
