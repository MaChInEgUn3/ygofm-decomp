#define D_8009B0C1_IS_AGGREGATE
#define D_8009B398_IS_AGGREGATE
#include "common.h"

void func_80039794(void) {
    u8 *p;
    u8 *q;
    u8 *t;
    s32 i;
    s32 j;
    s32 f;
    s32 v;
    s32 k;

    p = (u8 *)D_800EB0F8;
    j = 4;
    q = p + 0x30;
    t = (u8 *)D_801D9000;

    for (; j != 0; q += 0x64, j--, p += 0x64) {
        if ((*(u16 *)(q + 4) & 0x8000) == 0) {
            continue;
        }

        D_8009B35A = 0;

        if ((*(u16 *)(q + 4) & 0x2000) == 0) {
            i = -1;
            D_8009B35A = -1;
            while (1) {
                func_800393B0(p);
                f = *(u16 *)(q + 4);
                i++;
                if ((f & 0x2000) != 0) {
                    if ((f & 8) != 0) {
                        *(s32 *)q = func_800374F4(p);
                    }
                    break;
                }
                if ((f & 0x1C00) != 0) {
                    goto reset;
                }
                if (i >= D_8009B0C1[0]) {
                    break;
                }
                continue;
reset:
                D_8009B35A = -1;
            }
        } else {
            f = *(u16 *)(q + 4);
            if ((f & 8) != 0) {
                if ((D_8009B398[0] & 0xC0) != 0) {
                    *(s16 *)(q + 4) = f & 0xFFF7;
                    func_8004036C(*(s32 *)q);
                    *(s32 *)q = 0;
                    func_8003FEE0(0xB);
                }
            }
        }

        v = D_8009B35A;
        k = -1;
        if (v >= 0) {
            k = *(u16 *)(t + v * 4 + 2) & 7;
            if (k == 4) {
                k = D_8009B356;
            } else {
                D_8009B356 = k;
            }
        }
        func_8003B50C(k);
        func_80039D64(p);
    }
}
