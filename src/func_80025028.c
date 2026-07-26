#include "common.h"

s32 func_80025028(s32 arg0) {
    s32 i = 0;
    s32 o = D_8009B1D5 * 20;

    D_8009B22A = 0;

    do {
        u8 *r = &D_801A7AD8[D_800907D8[i + o] * 28];

        if (*(u16 *)(r + 0x16) & 0x8000) {
            if (*(s16 *)(r + 0xC) == arg0) {
                u8 *obj = *(u8 **)r;

                D_8009B22A = arg0;
                D_8009B1B8 = obj[0x6A];

                return arg0;
            }
        }
        i++;
    } while (i < 5);

    return 0;
}
