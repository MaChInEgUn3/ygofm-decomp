
#include "common.h"

s32 func_8004BC2C(u8 *arg0);
s32 func_8004BE6C(s32 *arg0, s32 arg1);

void func_8004BE88(u8 *p, s32 arg1) {
    u8 *e;
    u8 *f;
    u32 v;
    u32 i;
    s32 off;
    s32 mode;
    s32 t;
    s32 z;

    mode = arg1 & 0xFF;

    switch (mode) {
    case 0x2F:
        p[0x24] = 1;
        goto one;

    case 0x51:
        z = 0;
        v = func_8004BAE4(p) << 16;
        v = v | (func_8004BAE4(p) << 8);
        v = v | func_8004BAE4(p);
        e = D_8009B458;
        *(s32 *)(e + 0x808) = v;
        v = 0x3938700 / v;
        v = v * 100 / 115;
        if (v >= 0x100) {
            v = 0xFF;
        }
        t = *(u16 *)(e + 0x7FC);
        switch (t) {
        case 0x3C:
        case 0x18:
            v = v >> 1;
            break;
        case 0x1E:
            v = v >> 2;
            break;
        }
        f = D_8009B458;
        if (*(u16 *)(f + 0x7FA) != 0) {
            off = z;
            i = z;
            do {
                *(s16 *)(f + off + 0x52E) = v;
                *(s16 *)(f + off + 0x52C) = v;
                off += 0x2C;
                i++;
            } while (i < *(u16 *)(f + 0x7FA));
        }
        break;

    case 0x54:
        func_8004BAE4(p);
        func_8004BAE4(p);
        func_8004BAE4(p);
        goto three;

    case 0x58:
        func_8004BAE4(p);
        func_8004BC2C(p);
        break;

    case 0x59:
    three:
        func_8004BAE4(p);
        func_8004BAE4(p);
    one:
        func_8004BAE4(p);
        break;

    case 0 ... 0xF:
    default:
        func_8004BE6C((s32 *)p, func_8004BB34(p));
        break;
    }
}
