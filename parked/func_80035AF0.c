#include "common.h"

u8 *func_80035AF0(s32 arg0, s32 arg1, s32 arg2) {
    Rec64 *p;
    u16 *q;

    p = &D_800EB0F8[arg0];
    arg2 |= 0x8000;
    p->unk5A = 8;
    p->unk5B = 0xC;
    p->unk53 = 2;
    q = (u16 *)&D_80090E58[arg0 * 2];
    p->unk57 = arg0;
    p->unk36 = arg1;
    p->unk54 = 0;
    p->unk34 = arg2;
    p->unk38 = 0;
    p->unk3A = 0;
    p->unk59 = 0;
    p->unk61 = 0;
    p->unk5C = q[0];
    p->unk5E = q[1] - q[0];
    return (u8 *)p;
}
