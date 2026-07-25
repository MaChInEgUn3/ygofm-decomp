#include "common.h"

void func_8002E00C(u8 *arg0) {
    u8 *p = arg0;
    s32 i;

    *(s16 *)(arg0 + 0x3C) = -1;
    i = 0;
    do {
        func_8004036C(*(s32 *)p);
        *(s32 *)p = 0;
        *(s16 *)(p + 4) = 0;
        i++;
        p += 0x14;
    } while (i < 3);
}
