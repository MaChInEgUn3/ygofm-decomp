#include "common.h"

void func_80037DA4(u8 *p) {
    u8 **cp;
    u8 *c;
    u8 *base;
    s32 op;
    s32 op2;
    s32 a1;
    s32 a2;
    s32 v;
    s32 t;
    s32 off;
    s32 r;

    p[0x62] = 0;
    cp = (u8 **)(p + *(s8 *)(p + 0x58) * 4);
    c = *cp;
    op = *c;
    *cp = c + 1;
    op2 = op;
    a2 = 0;

    if ((op & 0x10) != 0) {
        p[0x54] = D_8009B320;
        return;
    }
    if ((op & 0x20) != 0) {
        a1 = D_8009B338 + 0x8000;
        goto push;
    }
    if ((op & 0x40) != 0) {
        a1 = D_8009B338 + 0xD100;
        goto push;
    }

    a1 = 0;
    switch (op & 0xF) {
    case 0:
        a1 = (D_801D4244[D_8009B338 - 1] >> 26) & 0x1F;
        break;
    case 1:
        t = D_801D4244[D_8009B338 - 1];
        a1 = (t >> 22) & 0xF;
        v = (t >> 26) & 0x1F;
        if ((u32)(v - 0x14) < 4) {
            p[0x62] = v;
        }
        a1 = a1 + 0x17;
        break;
    case 2:
        a1 = (D_801D4244[D_8009B338 - 1] >> 18) & 0xF;
        a1 = a1 + 0x17;
        if (a1 == 0x17) {
            a2 = 1;
        }
        break;
    }

    if ((op2 & 0x80) != 0) {
        a1 = a1 + 0x8300;
    push:
        p[0x58] = p[0x58] + 1;
        a2 = a1;
        if (a1 > 0xCFFF) {
            off = 0xFFFF3000;
            base = D_801C0000;
            goto lookup;
        }
        if (a1 > 0x7FFF) {
            base = D_801D5800;
            off = -0x8000;
            do {
            lookup:
                r = ((s32)base & 0xFFFF0000) +
                    *(u16 *)(base + (a1 + off) * 2);
            } while (0);
        } else {
            if (a1 >= 0x500) {
                a2 = a1 - 0x100;
            }
            r = ((s32)D_801B0000 & 0xFFFF0000) +
                *(u16 *)(D_801C0000 + a2 * 2);
        }
        *(s32 *)(p + *(s8 *)(p + 0x58) * 4) = r;
        return;
    }

    *(u16 *)(p + 0x34) = *(u16 *)(p + 0x34) | 0x80;
    if ((a2 & 0xFF) == 0) {
        func_80036C14(p, a1);
    }
    *(u16 *)(p + 0x34) = *(u16 *)(p + 0x34) & 0xFF7F;
    *(u16 *)(p + 0x38) = *(u16 *)(p + 0x38) + 0x10;
}
