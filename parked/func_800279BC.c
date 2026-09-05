/* 9 differing at 271/271 (2026-09-05; was 14, then 12). The mask constant 0x90000000
 * used in the search loop is NAMED, and the name is a BORROW: `r`, the arm's
 * result variable, assigned right after `n = 0; j = 0;` at the top of the
 * block. The same assignment just before the loop or inside it is 14 -- the
 * position is the lever, not the naming. Found by score_permuter_outputs.py
 * in a stored output; decomposed from the preprocessed source by hand.
 * The 12: the loop counter i in $a2 (retail) against $a0, the D_800907D8 /
 * D_801A7AD8 pair rotated behind it, and `r - 4` computed in place ($a1)
 * where ours takes $a3. Dead at 12: `r -= 4;` (13), both `i = 0xA;` sites
 * pinned with `do { } while (0);` (12), either alone (12, 12), and a shared
 * `ten` name for the constant (12).
 * 12 -> 9 (permuter): the record offset `(D_8009B1D5 ^ 1) * 0x1A4` computed
 * into `i` -- the loop counter, dead at that point -- and `h` formed from it.
 * The permuter's other output borrows `i` for the flag word read instead
 * (`i = *(s32 *)(h + 0x14); if ((i & r) == r)`), also 9; both together are
 * -1 and 254, so it is one borrow or the other, not both. The 9 left: the
 * counter and the 10 in $t0 against $a2, `r - 4` into $a3, and a `sll`/`addu`
 * pair through $t0. The permuter from this base: 3480 iterations, no output.
 */
/* 12 differing at 271/271 (2026-09-05; was 14). The mask constant 0x90000000
 * used in the search loop is NAMED, and the name is a BORROW: `r`, the arm's
 * result variable, assigned right after `n = 0; j = 0;` at the top of the
 * block. The same assignment just before the loop or inside it is 14 -- the
 * position is the lever, not the naming. Found by score_permuter_outputs.py
 * in a stored output; decomposed from the preprocessed source by hand.
 * The 12: the loop counter i in $a2 (retail) against $a0, the D_800907D8 /
 * D_801A7AD8 pair rotated behind it, and `r - 4` computed in place ($a1)
 * where ours takes $a3. Dead at 12: `r -= 4;` (13), both `i = 0xA;` sites
 * pinned with `do { } while (0);` (12), either alone (12, 12), and a shared
 * `ten` name for the constant (12). Permuter started from this base.
 */
#include "common.h"

s32 func_800279BC(void) {
    u8 *a[6];
    u8 *b[6];
    u8 *c[6];
    u8 **pb;
    u8 **pc;
    u8 **pa;
    u8 *e;
    u8 *f;
    u8 *h;
    u8 *g;
    s32 i;
    s32 j;
    s32 n;
    s32 k;
    s32 r;
    s32 u;

    D_800EAE91[0] = 0;
    if ((D_8009B16C & 0x1000) == 0) {
        i = 0xA;
        if ((func_8008E590() & 3) == 0) {
            func_80026D18(c, 0xA, 0x17);
            func_80026D18(b, 5, -1);
            e = c[0];
            if (e != 0) {
                pc = c;
                do {
                    f = b[0];
                    if (f != 0) {
                        pb = b;
                        do {
                            if (func_80019A08(*(s16 *)(e + 0xC), *(s16 *)(f + 0xC)) != 0) {
                                goto hit;
                            }
                            pb++;
                            f = *pb;
                        } while (f != 0);
                    }
                    pc++;
                    e = *pc;
                } while (e != 0);
            }
            k = func_80026D18(c, 0xA, 0x14);
            if (k != 0) {
                k = k - 1;
                if (k != 0) {
                    k = func_800358FC(k + 1);
                }
                D_800EAE88[9] = *(s8 *)(c[k] + 0x18) % 5 + 6;
                D_800EAE88[0xA] = 0;
                D_800EAE88[0xB] = 0;
                return 0;
            }
            goto scan;
        hit:
            D_800EAE88[9] = *(s8 *)(e + 0x18) % 5 + 6;
            D_800EAE88[0xA] = *(s8 *)(f + 0x18) % 5 + 1;
            D_800EAE88[0xB] = 0;
            return 0;
        }
    scan:
        i = 0xA;
        do {
            g = D_801A7AD8 + D_800907D8[i + D_8009B1D5 * 0x14] * 0x1C;
            i++;
            if ((*(s32 *)(g + 0x14) & 0xC0000000) == 0x80000000) {
                r = func_800278A0((u8 **)g);
                if (r < 0) {
                    goto neg;
                }
            check:
                if (*(s8 *)(D_8009B1C8 + 0x19) != 0) {
                    goto plain;
                }
                u = *(s8 *)(g + 0x18);
                D_800EAE88[0xA] = r % 5 + 0x38;
                D_800EAE88[0xB] = 0;
                D_800EAE88[9] = u % 5 + 1;
                return 0;
            neg:
                if ((func_8008E590() & 3) != 0) {
                    goto more;
                }
                r = func_8002778C((u8 **)g);
                if (r >= 0) {
                    goto check;
                }
            plain:
                r = *(s8 *)(g + 0x18) % 15;
                D_800EAE88[0xA] = 0;
                D_800EAE88[0xB] = 1;
                r = (s8)r - 4;
                D_800EAE88[9] = r;
                return 0;
            more:
                if ((func_8008E590() & 1) == 0) {
                    goto plain;
                }
                n = 0;
                j = 0;
                r = 0x90000000;
                pa = a;
                i = (D_8009B1D5 ^ 1) * 0x1A4;
                h = D_801A7AD8 + 0x8C + i;
                do {
                    if ((*(s32 *)(h + 0x14) & r) == r) {
                        *pa = h;
                        pa++;
                        n++;
                    }
                    j++;
                    h += 0x1C;
                } while (j < 5);
                if (n == 0) {
                    goto plain;
                }
                r = n - 1;
                if (r != 0) {
                    r = func_800358FC(n);
                }
                r = *(s8 *)(a[r] + 0x18);
                goto check;
            }
        } while (i < 0xF);
    }
    return 0;
}
