#include "common.h"

void func_80049EC8(s32 arg0, s32 arg1) {
    u8 *p = D_8009B458;
    s32 mode = *(s16 *)(p + 0x7E2);

    *(s16 *)(p + 0x7E4) = arg0 & 0x7F;
    *(s16 *)(p + 0x7E6) = arg1 & 0x7F;
    if (mode != 2) {
        func_8004A2F8();
    }
}
