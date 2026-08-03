#define D_8009B45C_IS_AGGREGATE
#include "common.h"

void func_80045334(s32 a) {
    Cmd2C c;
    u8 *b;
    s32 x;
    s32 k;
    s32 m;
    u8 *t;
    s32 p0;
    s32 p1;
    u8 v;

    b = D_8009B45C[0];
    x = a;
    v = b[0x4A];
    if ((v & 0x80) == 0) {
        return;
    }
    if ((v & 0x40) == 0) {
        if ((u32)(x & 0xFFFF) > 0x9FFF) {
            return;
        }
    }
    if ((a & 0x8000) == 0) {
        return;
    }
    *(s16 *)(b + 0x534) = a;
    m = a & 0xF000;
    switch (m) {
    case 0x8000:
        x = a + m;
        t = *(u8 **)(b + 0x51C);
        k = 0x50;
        break;
    case 0x9000:
        x = a + 0x7000;
        t = *(u8 **)(b + 0x518);
        k = 0x60;
        break;
    default:
        x = x + 0x6000;
        k = 0x70;
        t = *(u8 **)(D_8009B45C[0] + 0x520);
        break;
    }
    p0 = *(s32 *)t;
    p1 = (s32)(t + 8);
    func_800464F0();
    c.unk0 = 0x21;
    c.unk2 = x;
    c.unk4 = p0;
    c.unk8 = k;
    c.unkC = p1;
    func_80045BE8(&c);
    *(u16 *)(D_8009B45C[0] + 0x40) = (*(u16 *)(D_8009B45C[0] + 0x40) | 1) & 0xFFFB;
}
