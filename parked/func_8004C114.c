#include "common.h"

void func_8004C114(u8 *o, s32 st, u8 d1, u8 d2) {
    u8 *p;
    u8 *e;
    s32 ch;
    s32 i;
    s32 off;
    u8 c;

    ch = st & 0xF;
    switch (st & 0xF0) {
    case 0x80:
        func_8004B374(ch, d1, d2);
        return;
    case 0x90:
        if (d2 != 0) {
            func_8004ADE8(ch, d1, d2);
            return;
        }
        func_8004B374(ch, d1, 0);
        return;
    case 0xB0:
        if (d1 == 0x63) {
            if (d2 == 0x14) {
                p = D_8009B458;
                if (*(u16 *)(p + 0x7F8) != 0) {
                    for (i = 0, off = 0x518; i < *(u16 *)(p + 0x7FA); i++, off += 0x2C) {
                        e = p + off;
                        e[0x26] = d2;
                        e[0x25] = e[0x24];
                        e[0x2A] = e[0x29];
                        *(u16 *)(e + 0x1A) = *(u16 *)(e + 0x18);
                        p = D_8009B458;
                        *(s32 *)(e + 4) = *(s32 *)e;
                        *(s32 *)(e + 0x20) = *(s32 *)(e + 0x1C);
                    }
                    *(s32 *)(D_8009B458 + 0x7F4) = *(s32 *)(D_8009B458 + 0x7F0);
                } else {
                    o[0x26] = 0x7F;
                    *(s32 *)(o + 4) = *(s32 *)o;
                }
            } else if (d2 == 0x1E) {
                c = o[0x26];
                if (c != 0) {
                    if (c < 0x7F) {
                        o[0x26] = c - 1;
                    }
                    p = D_8009B458;
                    if (*(u16 *)(p + 0x7F8) != 0) {
                        for (i = 0, off = 0x518; i < *(u16 *)(p + 0x7FA); i++, off += 0x2C) {
                            e = p + off;
                            e[0x24] = e[0x25];
                            e[0x29] = e[0x2A];
                            *(u16 *)(e + 0x18) = *(u16 *)(e + 0x1A);
                            p = D_8009B458;
                            *(s32 *)e = *(s32 *)(e + 4);
                            *(s32 *)(e + 0x1C) = *(s32 *)(e + 0x20);
                        }
                        *(s32 *)(D_8009B458 + 0x7F0) = *(s32 *)(D_8009B458 + 0x7F4);
                    } else {
                        *(s32 *)o = *(s32 *)(o + 4);
                    }
                }
            }
        }
        if (d1 == 6) {
            p = D_8009B458;
            if (p[ch * 24 + 0x12] == 0x14) {
                if (*(u16 *)(p + 0x7F8) != 0) {
                    for (i = 0, off = 0; i < *(u16 *)(p + 0x7FA); i++, off += 0x2C) {
                        p[off + 0x53E] = d2;
                        p = D_8009B458;
                    }
                } else {
                    o[0x26] = d2;
                    return;
                }
            }
        }
        func_8004B49C(ch, d1, d2);
        return;
    case 0xC0:
        func_8004B6E8(ch, d1);
        return;
    case 0xE0:
        func_8004B70C(ch, d1, d2);
        return;
    }
}
