#include "common.h"

void func_80039F44(u8 *arg0) {
    *(u16 *)(arg0 + 0x34) = 0x68;
    arg0[0x32] = 0;
    arg0[0x33] = 0;
    arg0[0x31] = 0;
    *(u16 *)(arg0 + 0x36) = 0xB2;
    *(u16 *)(arg0 + 0x3E) = (u8)func_8008E590() + 0x3C;
}
