/* 2026-09-05, still 8: retail materialises the D_800EAE98 base into $s0 AFTER
 * the first call's argument setup (sh D_8009B2A4, a0 = a1 = 0, the func_8002FB78
 * address) and we do it first. Four placements of `p = D_800EAE98;`: before the
 * stores (8, installed), after the three stores (8), after the func_80014E1C
 * call (17), after func_80039E9C (45), between the first two stores (8). The
 * position of the assignment does not move where gcc materialises it here. */
#define D_8009B146_SIZED
#define D_80010000_SIZED
#define D_800EAE98_SIZED
#include "common.h"

void func_8002FB78(void);
u8 *func_8002E3FC(void);

void func_8002FD10(s32 arg0) {
    u8 *p;
    u8 *q;
    s16 *e;
    s32 i;
    s32 c;
    s32 d;
    s32 t;

    D_8009B2A4 = arg0;
    p = D_800EAE98;
    D_8009B148[0] = 0;
    D_8009B146[0] = 0;
    D_8009B2A0 = (u8 *)0;
    func_80014E1C(0, (u8 *)0, 0x1E57, 0x31, func_8002FB78, 0, 0);
    i = 0;
    func_80039E9C();
    *(s16 *)(p + 0x3C) = -1;
    do {
        *(s32 *)(p + 0) = 0;
        *(s16 *)(p + 4) = 0;
        p += 0x14;
        i++;
    } while (i < 3);

    func_800137E4();

    do {
    } while (func_80082324(0xA) != 0);

    i = 0;
    q = D_80010000[0];
    D_800E9D70[0] = 0x380;
    D_800E9D70[2] = 0x18;
    D_800E9D70[4] = 0x380;
    e = &D_800E9D70[4];
    D_800E9D70[3] = 0x30;
    D_800E9D70[1] = 0;
    e[1] = 0xF0;
    e[2] = 0x40;
    e[3] = 1;

    do {
        func_80081DE8(D_800E9D70, q);
        func_80081DE8(&D_800E9D70[4], q + 0x900);
        i++;
        c = *(u16 *)&D_800E9D70[5] + 1;
        D_800E9D70[5] = c;
        t = (s16)c < 0x100;
        d = i / 5;
        D_800E9D70[0] = (i % 5) * 0x18 + 0x380;
        D_800E9D70[1] = d * 0x30;
        if (t == 0) {
            D_800E9D70[5] = 0xF0;
            D_800E9D70[4] = D_800E9D70[4] + 0x40;
        }
        q += 0x980;
    } while (i < 0x19);

    D_8009B2A0 = func_8002E3FC();
}
