#include "common.h"

void func_80071FC8(void) {
    u8 *r;
    s32 want;
    s32 k;
    s32 out;
    s32 lo;
    s32 hi;
    s32 i;

    want = D_800F5B98[func_8007058C()];
    k = D_800F5B98[func_8007058C()];
    out = func_8007058C();

    func_800707C4(k, &lo, &hi);

    i = lo;
    if (i <= hi) {
        do {
            r = (u8 *)&D_801AB000[i];
            if (k == 1 || k == 3 || k == 6 || k == 8) {
                if ((*(u16 *)(r + 6) & 0x4000) != 0) {
                    continue;
                }
            }
            if (*(s16 *)r != 0) {
                if ((*(u16 *)(r + 6) & 0x1000) != 0) {
                    if (want == 2) {
                        break;
                    }
                } else {
                    if (want == 1) {
                        break;
                    }
                }
            } else {
                if (want == 0) {
                    break;
                }
            }
            i++;
        } while (i <= hi);
    }

    if (i > hi) {
        D_800F5B98[out] = 0;
    } else {
        D_800F5B98[out] = i;
    }
}
