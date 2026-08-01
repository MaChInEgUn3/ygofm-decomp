#include "common.h"
void func_80039140(u8 *arg0);

void func_80039934(u8 *arg0, s32 arg1, s32 arg2) {
    u8 *p;

    p = *(u8 **)(arg0 + 0x28);
    *(s16 *)(arg0 + 0x3C) = arg1;
    *(s16 *)(arg0 + 0x40) = arg2;
    if (p != (u8 *)0) {
        *(s16 *)(p + 0x30) = arg1;
        *(s16 *)(p + 0x32) = arg2;
    }
    p = *(u8 **)(arg0 + 0x2C);
    if (p != (u8 *)0) {
        if (*(s16 *)(p + 0x1E) == 4) {
            func_80039140(arg0);
        } else {
            *(s16 *)(p + 0x30) = arg1;
            *(s16 *)(p + 0x32) = arg2;
        }
    }
    p = *(u8 **)(arg0 + 0x30);
    if (p != (u8 *)0) {
        if (*(s16 *)(p + 0x1E) == 4) {
            func_80036DBC(arg0);
        } else {
            *(s16 *)(p + 0x30) = *(u16 *)(arg0 + 0x3E) + arg1 - 0x10;
            *(s16 *)(p + 0x32) = *(u16 *)(arg0 + 0x42) + arg2 - 0x10;
        }
    }
}
