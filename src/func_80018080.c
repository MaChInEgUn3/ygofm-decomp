#include "common.h"

void func_80018080(u8 *arg0) {
    u8 *r;

    arg0[0x22] = 0;
    *(u16 *)(arg0 + 8) = *(u16 *)(arg0 + 8) & 0xFFFB;
    r = D_801A7AD8 + arg0[0x6A] * 28;

    if (*(u16 *)(r + 0x16) & 0x1000) {
        arg0[0x22] = 0x80;
    }

    arg0[0x21] = 0;

    if (*(u16 *)(r + 0x16) & 0x800) {
        arg0[0x21] = 0xC0;
    }

    *(s32 *)(arg0 + 0xC) = 0x808080;

    if (*(u16 *)(r + 0x16) & 0x4000) {
        *(s32 *)(arg0 + 0xC) = 0x404040;
    }

    func_80017DB4(arg0);

    if (!(*(u16 *)(r + 0x16) & 0x2000)) {
        arg0[0x67] = 0;
    }
}
