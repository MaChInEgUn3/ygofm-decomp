#include "common.h"

void func_8001B7AC(u8 *p) {
    Rec0C *e;
    u8 *o;
    u8 *q;
    s32 v;

    e = &D_800EA030[*(s8 *)(p + 0xE)];
    q = e->unk0;
    *(u16 *)(q + 0x32) = *(u16 *)(q + 0x32) - 4;

    o = func_800400AC(func_8004002C(), 1);

    func_80040510(o, *(s16 *)(e->unk0 + 0x30), *(s16 *)(e->unk0 + 0x32), 0x10,
                  0x10, p[0x15] << 4, 0xB8, 0xB, 0x250, 0xFC);
    func_80042918(o);

    func_800428EC(o, (s8)(e->unk0[0x16] + 1));

    *(u8 **)&e->unk4[0] = o;

    v = p[0x15] + 1;
    p[0x15] = v;
    e->unk9 = v;
    func_8003FEE0(0x2F);
}
