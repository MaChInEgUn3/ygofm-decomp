#include "common.h"

s32 func_80047B68(u16 arg0) {
    u8 *p = D_8009B45C;
    u16 v;

    if (*(u16 *)(p + 0x442) == arg0) {
        return 1;
    }
    v = *(u16 *)(p + 0x40);
    *(u16 *)(p + 0x442) = arg0;
    *(u16 *)(p + 0x40) = v | 2;
    func_80047788(arg0 & 0xFFFF);
    return 1;
}
