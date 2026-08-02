#define D_8009B45C_IS_AGGREGATE
#include "common.h"

void func_80044DC0(s16 arg0) {
    u8 sp10[4];
    s32 v;

    v = (u16)(D_8009B45C[0][0x533]
              * (((arg0 + 1) * *(u16 *)(D_8009B45C[0] + 0x42)) >> 8)) >> 3;
    sp10[0] = v * D_8009B45C[0][0x514] >> 7;
    sp10[3] = 0;
    if (D_8009B45C[0][0x48] == 0) {
        sp10[1] = 0;
        sp10[2] = v * D_8009B45C[0][0x515] >> 7;
    } else {
        sp10[1] = v * D_8009B45C[0][0x515] >> 7;
        sp10[2] = 0;
    }
    func_8007CDC0(sp10);
    *(s16 *)(D_8009B45C[0] + 0x510) = arg0;
}
