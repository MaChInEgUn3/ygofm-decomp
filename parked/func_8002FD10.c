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
