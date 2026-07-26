#include "common.h"

s32 func_8001700C(u8 *arg0) {
    u16 f = *(u16 *)(arg0 + 0x16);

    if (f & 0x8000) {
        if (!(f & 0x4000)) {
            return 1;
        }
    }

    return 0;
}
