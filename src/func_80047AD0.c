#include "common.h"

s32 func_80047AD0(s32 arg0) {
    u8 *p = D_8009B45C;
    s32 i = arg0 & 0xFFFF;

    if (*(s32 *)(*(u8 **)(p + 0x448) + i * 8 + 4) == 0) {
        return 1;
    }

    if (*(u16 *)(p + 0x442) == i) {
        return 1;
    }

    func_80047A68();
    func_8004763C();

    {
        u8 *q = D_8009B45C;

        *(s16 *)(q + 0x442) = arg0;
        *(u16 *)(q + 0x40) |= 2;
        func_80047788(i);
    }

    return 1;
}
