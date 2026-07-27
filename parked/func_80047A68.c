#define D_8009B45C_IS_AGGREGATE
#include "common.h"

void func_80047A68(void) {
    s32 mask = 0;
    s32 bit = 0x100000;
    s32 i = 0;
    u8 *p = D_8009B45C[0];
    u16 limit = *(u16 *)(p + 4);

    do {
        if (*(u16 *)(p + 0x404) >= limit) {
            mask |= bit;
        }

        bit <<= 1;
        i++;
        p += 2;
    } while (i < 4);

    func_80076ED0(0, mask);
}
