#define D_8009B458_IS_AGGREGATE
#include "common.h"

void func_8004A27C(s32 arg0, s32 arg1, s32 arg2) {
    u8 *p = D_8009B458[0];
    s32 t;

    *(u16 *)(p + 0x4CC) = 0;
    *(u16 *)(p + 0x4CE) = 0;
    t = D_80011434[arg0];
    *(s32 *)(p + 0x4C4) = 0xF;
    *(s32 *)(p + 0x4C0) = t;
    *(u16 *)(p + 0x4C8) = (arg1 * *(u16 *)(p + 0x514)) >> 7;
    *(u16 *)(p + 0x4CA) = (arg2 * *(u16 *)(p + 0x516)) >> 7;

    func_80077450(p + 0x4C0);
}
