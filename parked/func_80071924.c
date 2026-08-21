#include "common.h"

void func_80070738(s32 arg0, s32 *arg1, s32 *arg2);

void func_80071924(void) {
    s32 sp10;
    s32 sp14;
    s32 *tbl;
    u8 *r;
    s32 a;
    s32 b;
    s32 c;
    s32 d;
    s32 k;
    s32 best;
    s32 lim;
    s32 one;
    s32 i;
    s32 x;
    s32 y;

    tbl = D_800F5B98;
    a = tbl[func_8007058C()];
    best = 0;
    b = tbl[func_8007058C()];
    lim = 0x270F;
    c = tbl[func_8007058C()];
    d = tbl[func_8007058C()];
    k = func_8007058C();
    func_80070738(b, &sp10, &sp14);

    i = sp10;
    if (sp14 >= i) {
        r = (u8 *)&D_801AB000[i];
        do {
            if (*(s16 *)r != 0) {
                if ((b == 1 || b == 4 || b == 5) &&
                    (*(u16 *)(r + 6) & 0x4000) != 0) {
                    goto next;
                }
                if (b == 4 && (*(u16 *)(r + 6) & 0x800) != 0) {
                    goto next;
                }
                if (b == 5 && (*(u16 *)(r + 6) & 0x800) == 0) {
                    goto next;
                }
                if ((u32)(b - 3) < 3 && (*(u16 *)(r + 6) & 0x1000) != 0 &&
                    c == 1) {
                    goto next;
                }
                if (func_80070920(d, i) != 0) {
                    goto next;
                }
                if (a == 0) {
                    x = *(s16 *)(r + 2);
                } else if (a == 1) {
                    x = *(s16 *)(r + 4);
                } else {
                    y = *(s16 *)(r + 2);
                    x = *(s16 *)(r + 4);
                    if (x < y) {
                        if (y < lim) {
                            lim = y;
                            best = i;
                        }
                        goto next;
                    }
                }
                if (x < lim) {
                    lim = x;
                    best = i;
                }
            }
        next:
            i++;
            r += 0xC;
        } while (sp14 >= i);
    }

    D_800F5B98[k] = best;
}
