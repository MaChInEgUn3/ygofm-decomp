#include "common.h"

void func_8005A074(s32 arg0) {
    s32 r = func_8005F174();

    if (r == 1 && func_8005F18C() == r) {
        return;
    }
    {
        u8 *p = D_800F2B20;

        *(u16 *)(p + 0xA) = (arg0 < 0 ? -arg0 : arg0) * 2;
        *(u16 *)(p + 8) = 0;
    }
}

