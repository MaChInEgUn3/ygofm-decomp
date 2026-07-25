#include "common.h"

void func_80049F10(s32 arg0, s32 arg1) {
    u8 *p = D_8009B458;
    s32 mode = *(s16 *)(p + 0x7E2);

    *(s16 *)(p + 0x514) = arg0;
    *(s16 *)(p + 0x516) = arg1;
    if (mode != 2) {
        func_8004A2F8();
    }
}
