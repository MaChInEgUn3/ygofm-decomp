#include "common.h"

void func_80071700(void) {
    s32 lo;
    s32 hi;
    s32 out;
    u8 *e;
    s32 one;
    s32 mode;
    s32 sel;
    s32 fp;
    s32 sv;
    s32 i;
    s32 bestv;
    s32 besti;
    s16 v;

    sel = D_800F5B98[func_8007058C()];
    besti = 0;
    mode = D_800F5B98[func_8007058C()];
    bestv = -1;
    fp = D_800F5B98[func_8007058C()];
    sv = D_800F5B98[func_8007058C()];
    out = func_8007058C();

    func_80070738(mode, &lo, &hi);

    i = lo;
    if (hi >= i) {
        one = 1;
        e = (u8 *)D_801AB000 + i * 0xC;
        do {
            if (*(s16 *)e != 0) {
                if (mode == one || mode == 4 || mode == 5) {
                    if ((*(u16 *)(e + 6) & 0x4000) != 0) {
                        goto next;
                    }
                }
                if (mode == 4) {
                    if ((*(u16 *)(e + 6) & 0x800) != 0) {
                        goto next;
                    }
                }
                if (mode == 5) {
                    if ((*(u16 *)(e + 6) & 0x800) == 0) {
                        goto next;
                    }
                }
                if ((u32)(mode - 3) < 3 && (*(u16 *)(e + 6) & 0x1000) != 0 &&
                    fp == one) {
                    goto next;
                }
                if (func_80070920(sv, i) == 0) {
                    if (sel != one) {
                        v = *(s16 *)(e + 2);
                        if (bestv < v) {
                            bestv = v;
                            besti = i;
                        }
                    }
                    if (sel != 0) {
                        v = *(s16 *)(e + 4);
                        if (bestv < v) {
                            bestv = v;
                            besti = i;
                        }
                    }
                }
            }
        next:
            i++;
            e += 0xC;
        } while (hi >= i);
    }

    D_800F5B98[out] = besti;
}
