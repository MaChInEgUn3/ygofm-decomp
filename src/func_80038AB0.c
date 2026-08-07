#include "common.h"

void func_80038AB0(u8 *arg0) {
    u8 **slot;
    u8 *q;
    s16 c;
    s32 v;

    slot = (u8 **)(arg0 + *(s8 *)(arg0 + 0x58) * 4);
    q = *slot;
    c = *q;
    *slot = q + 1;
    v = c;
    if (v > 0) {
        func_8002CCE4(v + 0x1F);
        func_8002CCE4(v + 0x6E0);
    }
}
