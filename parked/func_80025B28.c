#include "common.h"

void func_80025B28(u8 *arg0) {
    s32 v = arg0[0x22] + 8;
    s32 f = arg0[0x6C];

    arg0[0x22] = v;

    if (!(f & 0x80) && (u8)v >= 0x28) {
        u8 *r = D_801A7AD8 + arg0[0x6A] * 28;

        arg0[0x6C] = f | 0x80;
        *(u16 *)(r + 0x16) &= 0xDFFF;
        arg0[0x67] = 0;
    }

    if (arg0[0x22] < 0x40) {
        u8 *r = D_801A7AD8 + arg0[0x6A] * 28;

        arg0[0x22] = 0;
        arg0[0x6C] = 0;
        *(s32 *)(arg0 + 0x24) = 0;
        *(u16 *)(r + 0x16) &= 0xCBFF;
        func_80018080(arg0);
    }
}
