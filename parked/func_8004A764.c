#define D_8009B458_IS_AGGREGATE
#include "common.h"

void func_8004A764(s32 arg0) {
    u8 *p = D_8009B458[0];

    *(s32 *)(p + 0x4C0) = D_80011434[arg0];
    *(s32 *)(p + 0x4C4) = 0x60100;
    *(u16 *)(p + 0x4FA) = 0;
    *(u16 *)(p + 0x4FC) = 0;
    *(s32 *)(p + 0x4E4) = 5;

    func_80077450(p + 0x4C0);
}
