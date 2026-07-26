#include "common.h"

u8 *func_80040468(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    u16 v;

    arg0[0x67] = arg1;
    arg0[0x68] = arg2;
    arg0[0x69] = arg3;
    arg0[0x66] = arg4;
    arg0[0x5E] = arg4 >> 16;
    arg0[0x5F] = arg4 >> 8;
    *(u16 *)(arg0 + 0x40) = arg5 & 0x3F0;
    *(u16 *)(arg0 + 0x42) = (arg5 & 0xF) + 0xF0;

    v = *(u16 *)(arg0 + 8) & 0xFFDF;
    *(u16 *)(arg0 + 8) = v;
    if (arg5 & 0x8000) {
        *(u16 *)(arg0 + 8) = v | 0x20;
    }

    return arg0;
}
