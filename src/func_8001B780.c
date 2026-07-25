#include "common.h"

void func_8001B780(u8 *arg0) {
    s8 v = *(s8 *)(arg0 + 0xE);
    u8 *p = *(u8 **)(arg0 + 4);

    *(s16 *)(p + 0x30) = v * 60 + 0xE;
    *(s16 *)(p + 0x32) = 0xC2;
}
