#include "common.h"

s32 func_80044544(u8 *arg0, s32 arg1) {
    s32 i = 0;
    s32 total = 0;

    if (arg1 > 0) {
        do {
            s32 v = *(s32 *)(arg0 + 0x18);

            total += v / 8192;
            if ((v & 0x1FFF) != 0) {
                total++;
            }
            i++;
            arg0 += 0x28;
        } while (i < arg1);
    }

    return 15 - total;
}
