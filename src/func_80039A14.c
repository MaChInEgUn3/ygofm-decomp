#include "common.h"

void func_80039A14(u8 *arg0) {
    *(u16 *)(arg0 + 0x34) |= 0x800;

    do {
        func_800393B0(arg0);
    } while (!(*(u16 *)(arg0 + 0x34) & 0x2000));
}
