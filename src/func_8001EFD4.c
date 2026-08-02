#include "common.h"

s32 func_8001EFD4(u8 *arg0, u8 *arg1) {
    u8 *a = &D_801A7AD8[arg0[0x6A] * 28];
    u8 *b;
    s32 got;
    s32 want;
    s32 r;

    if (arg1 == (u8 *)0) {
        return func_800170C8(a) & 0xFFFF;
    }
    b = &D_801A7AD8[arg1[0x6A] * 28];
    got = func_800170C8(b);
    want = got & 0xFFFF;
    if (*(u16 *)(b + 0x16) & 0x800) {
        want = (u32)got >> 16;
    }
    if (*(u16 *)(a + 0x16) & 0x800) {
        r = func_8001EF78(a, b);
    } else {
        r = func_8001EF1C(a, b);
    }
    if (r != want) {
        return r - want;
    }
    if ((*(u16 *)(a + 0x16) & 0x800) || (*(u16 *)(b + 0x16) & 0x800)) {
        return 0;
    }
    return -1;
}
