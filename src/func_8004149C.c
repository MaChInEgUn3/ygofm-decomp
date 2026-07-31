#include "common.h"

s32 func_8004149C(u8 *arg0, u8 *arg1) {
    u8 *p = arg1 + ((func_8008E590() % arg1[0]) * 2 + 1);

    *(s32 *)(arg0 + 0x50) = *(s32 *)(arg0 + 0x54) + ((p[1] << 8) | p[0]);
    *(u16 *)(arg0 + 0x58) = 0;
    return 1;
}
