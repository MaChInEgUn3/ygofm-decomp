#include "common.h"

s32 func_80049A64(u8 *arg0, s32 arg1) {
    s32 tag;
    u8 *p;

    D_8009B458[0x500] = 1;
    tag = *(s32 *)arg0;

    if (tag != 0x53455170 && tag != 0x6468544D && tag != 0x2054444B &&
        tag != 0x3154444B) {
        return -1;
    }

    p = D_8009B458;
    if (*(s16 *)(p + 0x7E0) == -1) {
        *(u8 **)(p + 0x7E8) = arg0;
        *(s16 *)(p + 0x7E0) = arg1;
        *(s16 *)(p + 0x7E2) = 2;
        p[0x500] = 0;

        return 0;
    }

    p[0x500] = 0;

    return -1;
}
