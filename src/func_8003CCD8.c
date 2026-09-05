#define D_8009B0C8_IS_AGGREGATE
#define D_8009B0D8_IS_SIZED
#define D_8009B39C_IS_SCALAR
#define D_8009B3A2_IS_SCALAR
#define D_8009B3A4_IS_VOLATILE
#define D_8009B3A6_IS_VOLATILE
#define D_8009B398_IS_VOLATILE
#define D_8009B39A_IS_VOLATILE
#define D_8009B394_IS_VOLATILE
#define D_8009B396_IS_VOLATILE
#include "common.h"

void func_8003CCD8(void) {
    s32 i;
    u32 rep;
    u32 cur;
    u32 newly;
    u32 c;
    u32 n;
    u8 v;

    rep = 0;
    cur = D_8009B3A8;
    D_8009B3A8 = 0;
    c = cur;
    newly = (D_8009B390 ^ cur) & cur;
    n = newly;
    D_8009B390 = cur;

    for (i = 31; i >= 0; i--) {
        rep <<= 1;
        if (c & 0x80000000) {
            if (n & 0x80000000) {
                rep |= 1;
            }
            v = D_800EF6B0[i] + D_8009B0D8[0];
            D_800EF6B0[i] = v;
            if (v >= D_8009B39C) {
                D_800EF6B0[i] = D_8009B3A2;
                rep |= 1;
            }
        } else {
            D_800EF6B0[i] = 0;
        }
        c <<= 1;
        n <<= 1;
    }

    if (D_8009B0C8[0] != 0) {
        D_8009B3B0 |= rep;
        D_8009B3B4 |= newly;
    } else {
        newly |= D_8009B3B4;
        rep |= D_8009B3B0;
        D_8009B3B0 = 0;
        D_8009B3B4 = 0;
    }
    D_8009B3A4 = cur;
    D_8009B3A6 = cur >> 16;
    D_8009B398 = newly;
    D_8009B39A = newly >> 16;
    D_8009B394 = rep;
    D_8009B396 = rep >> 16;
}
