#include "common.h"

u8 func_80049600(s32 arg0) {
    u8 v = arg0;

    if (v >= 0x15) {
        return 0xFF;
    }
    if (v == 0) {
        return 0xFF;
    }
    *(u16 *)(D_8009B458 + 0x510) = arg0 & 0xFF;

    return v;
}
