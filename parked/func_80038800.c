#include "common.h"

void func_80038800(u8 *arg0) {
    u8 **slot = (u8 **)(arg0 + *(s8 *)(arg0 + 0x58) * 4);
    u8 *p = *slot;
    s32 v = *p;

    *slot = p + 1;

    if ((v & 0x7F) == 0) {
        func_8003FF34();
    } else {
        func_8003FF58(v & 0x7F);
    }

    if (v & 0x80) {
        arg0[0x51] = 0xD;
        D_8009B350 = 1;
    }
}
