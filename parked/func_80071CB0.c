#include "common.h"

void func_80071CB0(void) {
    s32 buf[2][5];
    u8 *tb;
    u8 *t;
    u8 *e;
    s32 i;
    s32 k;
    s32 sel;
    s32 idx;
    s32 ok;
    s32 best;
    s32 best2;

    sel = D_800F5B98[func_8007058C()];
    idx = func_8007058C();
    ok = 1;

    for (k = 0; k < 2; k++) {
        for (i = 0; i < 5; i++) {
            buf[k][i] = 0;
        }
    }

    k = 0;
    best = 0;
    tb = D_801AB00C;
    t = tb - 0xC;

    do {
        for (i = 0; i < 5; i++) {
            if (buf[0][i] == 0 &&
                *(s16 *)(tb + i * 0xC + 2) > *(s16 *)(t + best * 0xC + 2)) {
                best = i + 1;
            }
        }
        if (best != 0) {
            buf[0][best - 1] = 1;
        }

        best2 = 0;
        e = D_801AB2A0;
        for (i = 0; i < 5; i++) {
            if (buf[1][i] == 0 &&
                (sel == 0 || (*(u16 *)(e + i * 0xC + 6) & 0x1000) == 0) &&
                *(s16 *)(e + i * 0xC + 2) > *(s16 *)(t + best2 * 0xC + 2)) {
                best2 = i + 0x38;
            }
        }
        if (best2 == 0) {
            goto done;
        }
        buf[1][best2 - 0x38] = 1;
        if (*(s16 *)(t + best * 0xC + 2) <= *(s16 *)(t + best2 * 0xC + 2)) {
            ok = 0;
            goto done;
        }
        k++;
        best = 0;
    } while (k < 5);

done:
    if (k == 0) {
        ok = 0;
    }
    D_800F5B98[idx] = ok;
}
