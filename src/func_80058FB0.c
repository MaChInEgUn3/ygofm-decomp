#include "common.h"

void func_80058FB0(s32 arg0, u8 *arg1) {
    u8 *p = &D_800F2C40[arg0 * 3616];

    *(u16 *)(arg1 + 0) = *(u16 *)(p + 0xDD0);
    *(u16 *)(arg1 + 2) = *(u16 *)(p + 0xDD2);
    *(u16 *)(arg1 + 4) = *(u16 *)(p + 0xDD4);
    *(u16 *)(arg1 + 6) = *(u16 *)(p + 0xDD6);
}
