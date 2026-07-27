#include "common.h"

/* Sibling of func_80072640; the two `addu`s put the index first, hence the
 * explicit integer arithmetic. */
void func_800726F4(void) {
    s32 *t = D_800F5B98;
    s32 c = t[func_8007058C()];
    s32 n = func_8007058C();
    s32 i = 0;
    u8 *b = D_800EAE88;
    Rec12 *tb = D_801AB000;

    do {
        s32 k = *(u8 *)(i + (s32)b);
        Rec12 *r = (Rec12 *)(k * 12 + (s32)tb);

        if (r->unk0 != 0 && r->unk8 == c) {
            t[n] = k;

            return;
        }
        i++;
    } while (i < 5);

    D_800F5B98[n] = 0;
}
