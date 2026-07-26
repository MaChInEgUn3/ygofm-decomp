#include "common.h"

void func_80038798(u8 *arg0) {
    s32 v = func_80036D3C(arg0) & 0xFFFF;

    if (v & 0x8000) {
        func_8003FF88(v);
        D_8009B33C = func_80036D3C(arg0);
        arg0[0x51] = 0x11;
        D_8009B350 = 1;
    } else {
        func_8003FEE0(v);
    }
}
