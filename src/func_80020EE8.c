#include "common.h"

void func_80020EE8(u8 *arg0) {
    u8 v;

    if (func_80042B98(arg0) == 0) {
        *(u16 *)(arg0 + 8) |= 4;
    }

    v = arg0[0x21] - 2;
    arg0[0x21] = v;
    if (v < 0xC0) {
        /* func_8004036C is already matched taking s32; its callee
           func_8004020C is still undecompiled and declared the same way, so
           the cast stays here rather than rippling a retype through seven
           files for no change in generated code. */
        func_8004036C((s32)arg0);
    }
}
