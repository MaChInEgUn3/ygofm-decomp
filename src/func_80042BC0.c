#include "common.h"

void func_80042BC0(u8 *arg0) {
    s32 v = arg0[0xC] - *(s16 *)(arg0 + 0x60);

    if (v > 0) {
        arg0[0xE] = v;
        arg0[0xD] = v;
        arg0[0xC] = v;
    } else {
        func_8004036C((s32)arg0);
    }
}
