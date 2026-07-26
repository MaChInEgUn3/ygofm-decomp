#include "common.h"

void func_80017DB4(u8 *arg0) {
    u8 *p = &D_801A7AD8[arg0[0x6A] * 28];

    if ((*(u32 *)(p + 0x14) & 0xA0000000) == 0xA0000000) {
        if (*(s8 *)(D_8009B1C8 + 0x1F) != 0) {
            arg0[0x67] = *(*(u8 **)(p + 4) + 4) + 1;
            if (*(s8 *)(D_8009B1C8 + 0x1F) < 0) {
                arg0[0x67] = 0xFF;
            }
        }
    }
}
