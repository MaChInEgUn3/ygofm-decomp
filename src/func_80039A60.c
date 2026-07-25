#include "common.h"

void func_80039A60(u8 *arg0) {
    *(u16 *)(arg0 + 0x34) |= 0xA00;

    do {
        func_800393B0(arg0);
    } while (!(*(u16 *)(arg0 + 0x34) & 0x2000));
}
