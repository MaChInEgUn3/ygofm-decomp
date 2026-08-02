#include "common.h"

void func_80019BD0(u8 *arg0) {
    s32 n;
    s32 f;

    if (func_80042B98(arg0) == 0) {
        *(s16 *)(arg0 + 0x2E) = 0x40;
        *(u16 *)(arg0 + 8) |= 4;
        if (arg0[0x21] != 0) {
            *(s16 *)(arg0 + 0x2E) = 0xC0;
        }
    }
    n = arg0[0x21] + 8;
    f = arg0[0x6C];
    arg0[0x21] = n;
    if (f & 0x40) {
        if ((s8)n >= 0) {
            u8 *tbl = D_801A7AD8;
            u8 *e = &tbl[arg0[0x6A] * 28];

            arg0[0x21] = 0;
            *(u16 *)(e + 0x16) &= 0xDFFF;
            if ((arg0[0x22] | arg0[0x20]) == 0) {
                *(u16 *)(arg0 + 8) &= 0xFFFB;
            }
            arg0[0x6C] = 0;
            *(s32 *)(arg0 + 0x24) = 0;
        }
    } else if (arg0[0x21] >= *(s16 *)(arg0 + 0x2E)) {
        arg0[0x6C] = f | 0x40;
        arg0[0x21] = 0xC0;
        arg0[0x67] = 0;
    }
}
