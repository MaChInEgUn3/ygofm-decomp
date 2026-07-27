#include "common.h"

void func_800320BC(u8 *arg0, s32 arg1) {
    s32 k = arg1;
    s32 *t;
    u8 *r = arg0 + 0x2D58;
    s32 i = 0;

    k--;
    t = &D_801D4244[k];

    do {
        if (r[5] == 0) {
            r[5] = 1;
            *(s16 *)(r - 4) = arg1;
            r[2] = (*t >> 26) & 0x1F;
            *(s16 *)(r - 2) = (*t & 0x1FF) * 10;
            *(s16 *)r = ((*t >> 9) & 0x1FF) * 10;
            func_80032C48(arg0 + 0x2D50);
            func_8003201C(arg0);

            return;
        }
        i++;
        r += 0x10;
    } while (i < 0x28);
}
