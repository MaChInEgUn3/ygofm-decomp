#define D_8009B45C_IS_AGGREGATE
#include "common.h"

s32 func_80047F38(u8 arg0) {
    s32 mask = 0;
    s32 bit = 1;
    s32 i = 0;
    u8 *p = D_8009B45C[0];

    do {
        if ((*(p + i + 0x410) & 0xF) == arg0) {
            mask |= bit;
        }

        i++;
        bit <<= 1;
    } while (i < 4);

    if (mask != 0) {
        func_80076ED0(0, mask << 20);
    }

    return mask;
}
