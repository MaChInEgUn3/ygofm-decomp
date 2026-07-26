#include "common.h"

s32 func_80077090(s32 arg0) {
    s32 found = -1;
    s32 i;
    s32 r;

    for (i = 0; i < 0x18; i++) {
        s32 m = 1 << i;

        if (arg0 & m) {
            found = i;
            break;
        }
    }

    if (found == -1) {
        r = -1;
    } else {
        s32 off = found * 16;
        u16 n;

        off += (s32)D_80092B88[0];
        n = *(u16 *)(off + 0xC);

        if ((D_80092B14[0] & (1 << found)) == 0) {
            r = (n != 0) * 2;
        } else if (n == 0) {
            r = 3;
        } else {
            r = 1;
        }
    }

    return r;
}
