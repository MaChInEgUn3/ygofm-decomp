#define D_8009B45C_IS_AGGREGATE
#include "common.h"

void func_80044F58(s32 arg0) {
    u8 buf[4];
    u8 *p;

    D_8009B45C[0][0x533] = 7;

    buf[0] = arg0;
    buf[3] = 0;

    if (D_8009B45C[0][0x48] == 0) {
        buf[1] = 0;
        buf[2] = arg0;
    } else {
        buf[1] = arg0;
        buf[2] = 0;
    }

    func_8007CDC0(buf);

    p = D_8009B45C[0];
    p[0x49] = arg0;
    *(u16 *)(p + 0x510) = arg0;
    *(u16 *)(D_8009B45C[0] + 0x512) = 0;
}
