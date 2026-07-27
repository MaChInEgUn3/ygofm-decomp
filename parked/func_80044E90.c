#define D_8009B45C_IS_AGGREGATE
#include "common.h"

void func_80044E90(s32 arg0) {
    s32 a = arg0;

    if ((u16)(arg0 - 1) < 0x80) {
        D_8009B45C[0][0x514] = -0x80 - a;
        D_8009B45C[0][0x515] = 0x80;
    } else if ((u16)(arg0 + 0x80) < 0x80) {
        D_8009B45C[0][0x514] = 0x80;
        D_8009B45C[0][0x515] = -0x80 - a;
    } else {
        D_8009B45C[0][0x514] = 0x80;
        D_8009B45C[0][0x515] = 0x80;
    }

    func_80044DC0(*(s16 *)(D_8009B45C[0] + 0x510));
}
