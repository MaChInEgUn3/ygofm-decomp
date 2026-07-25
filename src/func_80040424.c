#include "common.h"

void func_80040424(u8 *arg0, s32 arg1) {
    if (arg0[0x69] != arg1) {
        arg0[0x69] = arg1;
        *(u16 *)(arg0 + 8) &= 0xFFEF;
    }
}
