#include "common.h"

void func_80022F98(u8 *arg0, u8 *arg1) {
    u8 *p;
    s32 dx;
    s32 dy;
    s32 k;

    if (arg1 == 0) {
        return;
    }
    p = *(u8 **)arg0;
    dx = *(u16 *)(arg1 + 0x30) - *(u16 *)(p + 0x30);
    *(s16 *)(arg1 + 0x28) = dx;
    dy = *(u16 *)(arg1 + 0x32) - *(u16 *)(p + 0x32);
    *(s16 *)(arg1 + 0x2A) = dy;
    k = arg0[0x17];
    arg1[0x6C] = 1;
    *(VoidFn *)(arg1 + 0x24) = func_80022EEC;
    *(s16 *)(arg1 + 0x2C) = k;
}
