#include "common.h"

/* The two `addu`s put the *index* first -- `addu $v0,$a2,$t1` and
 * `addu $a0,$v0,$t0` -- which `b[i]` and `&t[c]` do not give; hence the
 * explicit integer arithmetic. See the operand-order note in DECISIONS.md. */

void func_80072640(void) {
    s32 n = func_8007058C();
    s32 i = 0;
    u8 *b = D_800EAE88;
    Rec12 *t = D_801AB000;

    do {
        s32 c = *(u8 *)(i + (s32)b);
        Rec12 *r = (Rec12 *)(c * 12 + (s32)t);

        if (r->unk0 != 0 && r->unk8 < 0x14) {
            D_800F5B98[n] = c;

            return;
        }
        i++;
    } while (i < 5);

    D_800F5B98[n] = 0;
}
