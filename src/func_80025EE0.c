#include "common.h"

void func_80025EE0(void) {
    u8 *p;

    if (func_80024E24() == 0) {
        p = (u8 *)func_8002C68C(0x12);
        *(s16 *)p = 0xA0;
        *(s16 *)(p + 2) = 0x78;
        *(s16 *)(p + 0x1A) = 1;
        func_8003FEE0(2);
    } else {
        D_8009B220 = 0;
    }
}
