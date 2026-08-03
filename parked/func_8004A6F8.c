
#include "common.h"

void func_8004A6F8(s32 arg0, u8 *arg1) {
    s32 *t = &D_80011434[arg0];
    u8 *p = D_8009B458;
    s32 v = *t;

    *(s32 *)(p + 0x4C4) = 0x60100;
    *(s32 *)(p + 0x4C0) = v;
    *(u16 *)(p + 0x4FA) = *(u16 *)(arg1 + 0x20);
    *(u16 *)(p + 0x4FC) = *(u16 *)(arg1 + 0x22);
    *(s32 *)(p + 0x4E4) = *(u16 *)(arg1 + 0x24);

    func_80077450(p + 0x4C0);
}
