#define D_800EAE98_IS_PTR_TABLE
#include "common.h"

void func_8002FED8(u8 *arg0, u8 *arg1) {
    s32 t;
    s32 n;
    s32 c;
    u8 *p;

    if ((*(u16 *)(arg0 + 4) & 0x8000) == 0) {
        *(u16 *)(arg0 + 4) |= 0x8000;
        *(s16 *)(arg0 + 6) = 0;
    }
    t = (*(u16 *)(arg0 + 6) + 0x20) & 0xFFF;
    *(u16 *)(arg0 + 6) = t;
    n = func_800866A0(t) * 24 / 4096;
    if (n == 0) {
        n = 1;
    }
    if (n == 0x18) {
        n = 0x17;
    }
    c = n - 0x68;
    arg1[0xE] = c;
    arg1[0xD] = c;
    arg1[0xC] = c;
    p = D_800EAE98[0];
    if (p != (u8 *)0) {
        c = (n + 0x18) / 2 - 0x80;
        p[0xE] = c;
        p[0xD] = c;
        p[0xC] = c;
    }
    p = D_800EAE98[5];
    if (p != (u8 *)0) {
        c = (n + 0x18) / 2 - 0x80;
        p[0xE] = c;
        p[0xD] = c;
        p[0xC] = c;
    }
}
