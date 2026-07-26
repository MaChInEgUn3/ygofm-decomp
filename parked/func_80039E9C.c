/* Needs -fno-strength-reduce; see the park note. */
#include "common.h"

void func_80039E9C(void) {
    s32 i = 2;
    s32 m = -1;
    Rec4C *b = D_800EB010;
    Rec4C *r = b + 2;

    do {
        s32 j = 2;
        s32 *w = &r->w[2];

        r->unk30 = m;
        r->unk32 = 0;
        r->unk3A = 0;
        r->unk3B = 0;

        do {
            w[0] = 0;
            w[3] = 0;
            w[6] = 0;
            w[9] = 0;
            w--;
            j--;
        } while (j >= 0);

        i--;
        r--;
    } while (i >= 0);

    {
        s32 v = -1;
        s32 k = 4;
        s8 *c = D_8015C410;
        s8 *q = c + 4;

        do {
            *q = v;
            k--;
            q--;
        } while (k >= 0);
    }
}
