#include "common.h"

void func_8007308C(void) {
    u8 *t;
    u8 *r;
    u8 *e;
    u8 *s;
    u8 *a;
    s32 want;
    s32 out;
    s32 i;
    s32 j;
    s32 v;
    u16 f;

    want = D_800F5B98[func_8007058C()];
    out = func_8007058C();
    i = 1;
    t = (u8 *)D_801AB000;
    r = t + 0xC;
    a = (u8 *)D_800F5BE8;
    *(s16 *)(a + 0x98) = 0;
    s = a;

    while (i < 6) {
        if (*(s16 *)r == 0) {
            continue;
        }
        if ((*(u16 *)(r + 6) & 0x4000) != 0) {
            continue;
        }

        for (j = 0x38, e = t + 0x2A0; j < 0x3D; j++, e += 0xC) {
            if (*(s16 *)e == 0) {
                continue;
            }
            f = *(u16 *)(e + 6);
            if ((f & 0x4000) != 0) {
                continue;
            }
            if ((f & 0x800) != 0) {
                continue;
            }
            if (want != 0) {
                if ((f & 0x1000) != 0) {
                    continue;
                }
            }
            v = *(s16 *)(r + 2) - *(s16 *)(e + 2);
            v += func_8002CB80(*(s8 *)(r + 9), *(s8 *)(e + 9));
            if (*(u16 *)(s + 0x98) < v) {
                *(s16 *)(s + 0x98) = v;
                *(s8 *)(s + 0x9A) = i;
                *(s8 *)(s + 0x9B) = j;
            }
        }
    }

    if (D_800F5C80[0] != 0) {
        D_800F5B98[out] = 0;
    } else {
        D_800F5B98[out] = 1;
    }
}
