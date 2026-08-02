#define D_8009B360_IS_SCALAR
#define D_8009B361_IS_SCALAR
#define D_8009B364_IS_SCALAR
#define D_8009B369_IS_SCALAR
#define D_8009B370_IS_SCALAR
#define D_8009B372_IS_SCALAR
#define D_8009B374_IS_SCALAR
#define D_8009B368_IS_SCALAR
#define D_8009B36A_IS_SCALAR
#define D_8009B26C_IS_SCALAR
#include "common.h"

void func_80038530(u8 *p) {
    s32 v;
    s32 b;

    D_8009B360 = -1;
    b = *(*(u8 **)(p + (*(s8 *)(p + 0x58) << 2)))++;
    D_8009B361 = b;
    b = *(*(u8 **)(p + (*(s8 *)(p + 0x58) << 2)))++;
    D_8009B370 = b;
    b = *(*(u8 **)(p + (*(s8 *)(p + 0x58) << 2)))++;
    D_8009B372 = b;
    b = *(*(u8 **)(p + (*(s8 *)(p + 0x58) << 2)))++;
    D_8009B364 = b;

    D_8009B36A = func_80036D3C(p);

    v = *(u8 *)&D_8009B361;
    D_8009B374 = 0x72A0;
    if ((u32)(v - 9) < 8) {
        D_8009B374 = 0x7280;
    }
    if ((s8)v == 0x11) {
        D_8009B374 = 0x7290;
    }
    if ((s8)v == 0x26) {
        D_8009B374 = 0x72B0;
    }

    D_8009B368 = 2;
    D_8009B369 = 0;
    D_8009B26C = 3;
}
