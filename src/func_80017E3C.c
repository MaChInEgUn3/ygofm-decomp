#include "common.h"

void func_80017E3C(u8 *arg0) {
    u8 *r = D_801A7AD8 + arg0[0x6A] * 28;
    s32 f;

    if (!(*(u16 *)(r + 0x16) & 0x2000)) {
        arg0[0x67] = 0;
    }

    f = *(u16 *)(arg0 + 8) & 0xFFFB;
    *(u16 *)(arg0 + 8) = f;

    if (*(u16 *)(r + 0x16) & 0x1800) {
        *(u16 *)(arg0 + 8) = f | 4;
        arg0[0x21] = 0;

        if (*(u16 *)(r + 0x16) & 0x1000) {
            arg0[0x21] = 0x80;
        }

        arg0[0x22] = 0;

        if (*(u16 *)(r + 0x16) & 0x800) {
            arg0[0x22] = 0xC0;
        }
    }

    *(s32 *)(arg0 + 0xC) = 0x808080;

    if (*(u16 *)(r + 0x16) & 0x4000) {
        *(s32 *)(arg0 + 0xC) = 0x404040;
    }
}
