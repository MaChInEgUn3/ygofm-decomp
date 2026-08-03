#define FUNC_80017F04_FULL
#include "common.h"
/* Both are stored as function pointers only, so the parameter list is
 * immaterial here; these must match the real definitions, which grew a
 * second parameter after this candidate was parked. */
void func_80016D04(u8 *arg0, s32 arg1);

u8 *func_80017F04(u8 *arg0, s32 arg1, s32 arg2) {
    u8 *p = func_800400AC(func_8004002C(), 6);

    s32 *tbl = D_801D4244;

    p[0x67] = 0;
    p[0x69] = 0;
    p[0x68] = (tbl[*(s16 *)(arg0 + 0xC) - 1] >> 26) & 0x1F;
    p[0x6A] = ((u32)arg0 - (u32)D_801A7AD8) / 28;
    p[0x6B] = (*(u8 **)(arg0 + 4))[2];
    *(s16 *)(p + 0x30) = arg1;
    *(s16 *)(p + 0x32) = arg2;
    *(s32 *)(p + 4) |= 0x1000000;
    *(void **)(p + 0x10) = func_80016778;
    func_80042918(p);
    *(void **)(p + 0x4C) = func_80016D04;
    func_80017E3C(p);
    func_80017DB4(p);
    return p;
}
