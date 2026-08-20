#include "common.h"

void func_8004A940(s32 x, s32 y) {
    u8 *b;
    u8 *e;
    s32 i;
    s32 n;
    s32 best;
    s32 bi;
    s32 tx;
    s32 ty;
    s32 o;
    s32 arg;

    bi = -1;

    b = D_8009B458;
    for (i = 0; i < *(s16 *)(D_8009B458 + 0x510); i++, b += 0x28) {
        if (b[0x183] == 0x63) {
            return;
        }
    }

    b = D_8009B458;
    for (i = 0; i < *(s16 *)(D_8009B458 + 0x510); i++, b += 0x28) {
        if (b[0x18D] == 0) {
            goto founda;
        }
    }

    b = D_8009B458;
    n = *(s16 *)(b + 0x510);
    tx = x & 0xFF;
    ty = y & 0xFF;
    o = 0;
    for (i = 0; i < n; i++, o += 0x28) {
        e = b + o;
        if (e[0x183] == tx && e[0x185] == ty) {
            arg = e[0x183];
            goto foundb;
        }
        b = D_8009B458;
        n = *(s16 *)(b + 0x510);
    }

    b = D_8009B458;
    for (i = 0; i < *(s16 *)(D_8009B458 + 0x510); i++, b += 0x28) {
        if (b[0x18D] == 0) {
            goto founda;
        }
    }

    b = D_8009B458;
    best = 0xFFFF;
    n = *(s16 *)(b + 0x510);
    e = b;
    for (i = 0; i < n; i++, e += 0x28) {
        if (*(u16 *)(e + 0x19E) < (u32)best) {
            best = *(u16 *)(e + 0x19E);
            bi = i;
        }
    }

    if ((u32)0xFFFE < (u32)best) {
        return;
    }
    i = bi;

founda:
    arg = x & 0xFF;
foundb:
    func_8004A8E4(i, arg);
}
