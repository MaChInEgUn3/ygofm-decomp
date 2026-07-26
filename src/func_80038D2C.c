#include "common.h"

void func_80038D2C(u8 *arg0) {
    s32 v = func_80036D3C(arg0);

    v &= 0xFFFF;

    if (v & 0x4000) {
        func_8002CCE4(v & 0xBFFF);

        return;
    }
    {
        s32 w = func_80036D3C(arg0);

        w &= 0xFFFF;

        if (func_8002CCA8(v) != 0) {
            s32 *p = (s32 *)(arg0 + *(s8 *)(arg0 + 0x58) * 4);

            *p = (*p & 0xFFFF0000) | w;
        }
    }
}
