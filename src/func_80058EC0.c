#include "common.h"

u16 func_80058EC0(s32 arg0) {
    u8 *base = D_800F2C40;
    s32 off = arg0 * 3616;
    s32 i = base[off + 0xBF5];

    return *(u16 *)(base + (i * 118 + off) + 0x7C4);
}
