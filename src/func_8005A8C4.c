#define D_800FE240_IN_DATA
#include "common.h"

s32 func_8005A8C4(s32 arg0, s32 arg1) {
    s32 used;
    s32 room;
    u8 *p;
    s32 n;

    used = D_800FE240 - (s32)D_800A5768;
    used -= D_8009AFA2 * 140000;
    room = 0x222E0 - used;
    p = &D_800F2C40[arg0 * 3616];
    if (arg1 < 0) {
        arg1 = func_80059520(arg0)[3];
    }
    n = *(u16 *)(p + 0xE00);
    if (arg1 == 5) {
        room -= n * 2;
    } else {
        room -= n;
    }
    return room < 0x401;
}
