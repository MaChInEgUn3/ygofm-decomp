#include "common.h"

s32 func_8004C420(u8 *p) {
    s32 c;
    u32 v;
    s32 b;
    s32 e;
    s32 t;
    s32 d;

    e = 0;
    c = func_8004BAE4(p);
    d = c;

    if ((c & 0x80) == 0) {
        v = p[0x29];
        p[0x28] = 1;
    } else {
        v = c;
        if ((c & 0xFF) != 0xFF) {
            p[0x29] = c;
        }
        p[0x28] = 0;
    }

    t = D_80011484[(v >> 4) & 0xF];

    if (t != 0) {
        b = d;
        if (p[0x28] == 0) {
            b = func_8004BAE4(p);
        }
        if (t == 2) {
            e = func_8004BAE4(p);
        }
        func_8004C114(p, (u8)v, (u8)b, (u8)e);
    } else if ((c & 0xFF) != 0xF0) {
        if ((c & 0xFF) != 0xFF) {
            goto other;
        }
        func_8004BE88(p, (u8)func_8004BAE4(p));
    } else {
        func_8004C0AC(p);
    }

    return 0;

other:
    func_8004BE80();
    return 0;
}
