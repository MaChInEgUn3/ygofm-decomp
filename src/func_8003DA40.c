
#include "common.h"

void func_80039794(void);
u8 *func_8003D46C(s32 arg0, s32 arg1);
void func_80043230(u8 *arg0, s32 arg1, s32 arg2, s32 arg3);

void func_8003DA40(u8 *p) {
    u8 *e;
    u8 *q;
    s32 f;
    s32 g;
    s32 v;
    s32 h;

    f = D_8009B3C1;
    if ((f & 0x80) == 0) {
        D_8009B3C1 = f | 0x80;
        e = func_800400AC(func_8004002C(), 2);
        func_800404CC(e, 0x20, -0x40, 3, 2, 0, 0xB, 0x20C);
        *(s16 *)(e + 8) = *(u16 *)(e + 8) | 0x28;
        func_80042918(e);
        func_800428EC(e, (s8)(*(u8 *)&D_8009AF76 - 2));
        *(s32 *)p = (s32)e;
        func_80043178(e);
        *(s16 *)(e + 0x60) = -0x400;
        q = func_8003D46C(0xD0, 0);
        *(s16 *)(q + 0x34) = *(u16 *)(q + 0x34) | 4;
        do {
            func_80039794();
        } while (*(s32 *)(q + 0x30) == 0);
        func_80039934(q, *(s16 *)(e + 0x30), *(s16 *)(e + 0x32));
    }

    e = *(u8 **)p;
    q = (u8 *)&D_800EB0F8[p[0x1A]];
    g = D_8009B3C1;

    if ((g & 0x40) != 0) {
        func_80039794();
        if ((*(u16 *)(q + 0x34) & 0x2000) != 0) {
            D_8009B3C1 = 0;
        }
    } else {
        v = *(u16 *)(e + 0x60) + 0x20;
        *(s16 *)(e + 0x60) = v;
        if ((s16)v >= 0) {
            *(s16 *)(e + 0x30) = 0x20;
            *(s16 *)(e + 0x32) = 0x50;
            h = *(u16 *)(q + 0x34);
            D_8009B3C1 = g | 0x40;
            *(s16 *)(q + 0x34) = h & 0xFFFB;
        } else {
            func_80043230(e, 0x20, 0x50, (s16)v);
        }
        func_80039934(q, *(s16 *)(e + 0x30), *(s16 *)(e + 0x32));
    }
}
