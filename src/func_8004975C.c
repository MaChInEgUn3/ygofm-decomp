#define D_8009B458_IS_AGGREGATE
#include "common.h"

s32 func_8004975C(s32 arg0, s16 arg1) {
    u8 *p = D_8009B458[0];
    s32 v = *(s16 *)(p + 0x4A4);

    if (v == arg1) {
        u8 *q = p + 0x4A4;

        func_800771B0(*(s32 *)(q + 0x14));

        if (func_80077150(arg0, *(s32 *)(q + 0x10)) == *(s32 *)(q + 0x10)) {
            *(s32 *)(q + 0xC) = arg0;
            return v;
        }

        return -1;
    }

    return -1;
}
