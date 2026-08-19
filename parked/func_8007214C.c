#include "common.h"

void func_8007214C(void) {
    u8 *r;
    s32 want;
    s32 k;
    s32 m;
    s32 out;
    s32 lo;
    s32 hi;
    s32 i;

    want = D_800F5B98[func_8007058C()];
    k = D_800F5B98[func_8007058C()];
    m = D_800F5B98[func_8007058C()];
    out = func_8007058C();

    func_800707C4(k, &lo, &hi);

    for (i = lo; i <= hi; i++) {
        r = (u8 *)&D_801AB000[i];
        if (*(s16 *)r != want) {
            continue;
        }
        if (k == 1 || k == 3 || k == 6 || k == 8) {
            if ((*(u16 *)(r + 6) & 0x4000) != 0) {
                continue;
            }
        }
        if (m == 1 && k >= 5 && (*(u16 *)(r + 6) & 0x1000) != 0) {
            continue;
        }
        break;
    }

    if (i <= hi) {
        D_800F5B98[out] = i;
    } else {
        D_800F5B98[out] = 0;
    }
}
