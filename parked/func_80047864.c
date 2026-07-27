#define D_8009B45C_IS_AGGREGATE
#include "common.h"

void func_80047864(s32 arg0) {
    u8 *p;
    u8 *q;
    u8 *r;
    s32 v = 0x100000;

    if (arg0 != 0) {
        v <<= arg0;
    }

    p = D_8009B45C[0];
    *(s32 *)(p + 0x3C4) = v;
    *(s32 *)(p + 0x3C8) = 3;
    q = p + arg0 * 2;
    r = p + arg0;
    *(u16 *)(p + 0x3CC) = (u32)(*(u16 *)(q + 0x414) * r[0x424]) >> 8;
    *(u16 *)(p + 0x3CE) = (u32)(*(u16 *)(q + 0x41C) * r[0x424]) >> 8;

    func_80077450(p + 0x3C4);
}
