/* 161/161, censo VAZIO, 14 differing (2026-09-08). Beats the August park's
 * +1/25 on every key: exact length, no opcode over- or under-produced, and
 * the residue is ONE register pair repeated in two identical blocks.
 * src/func_80027508.c still holds the ASSEMBLY-DEBT transcription (two
 * `register ... asm("a0"/"a1")` pins and one `__asm__` that materialises the
 * 23). This retires it only on MATCH.
 * gp=1, at=0, default flags.
 *
 * Written fresh from the listing rather than from the August recipe, and it
 * reached 161/161 on the FIRST draft -- the August entry's +1 was the
 * `t[idx - 1]` fold, and the two-statement form (`i = *(s16 *)(e + 0xC);
 * i = i - 1;`) that entry names is in this draft from the start. Levers:
 *   - a second name for the TAIL's index (`j`, where the first block's is
 *     `i`): 34 -> 26. Two reads of the same field in two phases are two
 *     values; one name is one pseudo and it rotates $v0/$v1 at both sites.
 *   - `d %= 5; d += 0xB;` as TWO compound assignments against one name:
 *     26 -> 14. Retail's `subu $a1,$a1,$v0` / `addiu $a1,$a1,11` writes the
 *     modulo into `d`'s own register, and no single-expression form gets
 *     there. On the 34-difference base this same edit was worth NOTHING
 *     (34), which is the standing warning about a spelling measured while
 *     another fault is open.
 *
 * The residue, identical in both blocks (7 each): retail keeps the signed
 * byte in $a1 and the `%hi(D_800EAE88)` half in $a2, and we have them
 * exchanged.
 *
 * Measured and DEAD on this base, all 14 unless noted -- the axis is closed
 * by hand: the `o` local dropped for the symbol inline (+1/24), `o`
 * assigned before `c`, between `c` and `d`, or as `&D_800EAE88[0]`; two
 * names for `o`, one per block (26); `c` dropped so `d = (s8)e[0x18]`;
 * `u8 c`; `s8 d` (18); `d = d % 5; d = d + 0xB;` non-compound; the explicit
 * `d = c << 24; d = d >> 24;` (-4/93); `c`/`d` declaration order swapped.
 * And on the 34-difference base, all 34: `d = d % 5 + 0xB;` with the store
 * after it, `d = d % 5;` then `o[0] = d + 0xB;`, the hand-expanded
 * `d - d / 5 * 5`, `t` assigned after `i`, `t` or `o` hoisted above the four
 * entry guards, four declaration orders, `w` dropped for `t[j]` inline, and
 * one name for the raw byte and its sign extension (38).
 *
 * SECOND HAND PASS, 2026-09-08, ~50 more measurements and the axis is CLOSED.
 * All 14 unless noted:
 *   - per-block names: `c` alone, `r` alone (both 14); `c`+`d` together, `d`
 *     alone (26); `o` alone (24). Sharing across the two blocks is right.
 *   - borrowing a dead name for the byte or its sign extension: `d` as `i`
 *     (19), `d` as `w` (16), `c` as `i` (19), `c` as `w` (16). This is the
 *     lever that closed func_8002E128 and it is worthless here.
 *   - a dead `i = 0;` at the top of each block.
 *   - the symbol written inline for ONE store while the rest go through the
 *     local: offset 0 (14), offset 1 (14), the shared offset 8 (+1/24).
 *   - the shared `o[8] = 1;` written out in both blocks instead of the
 *     `goto` (+3/72), which confirms the goto.
 *   - `do { } while (0);` round the byte read (+5), the base assignment
 *     (+6), the sign extension (+6) or the modulo (55). The pin that fixed
 *     func_8005F3B8's identical $s1/$s2 residue does not transfer: this
 *     block is crossed by a `goto` into the tail and the loop node breaks
 *     the layout.
 *   - `s16 d` (+2/89); the stores as `*(u8 *)(o + K)` casts (14).
 *   - the FULL flag sweep through sweep_try.py: default `O2 G8` is the best
 *     row at 14; `as -G2` and `as -G4` tie it and every other row is 115 or
 *     worse.
 *   - `r %= 5; r += 1;` -- the EXACT spelling that took `d` from 26 to 14 --
 *     is 30 on `r`. The two modulos in one function want opposite forms,
 *     because retail writes `d`'s result into `d`'s own register and `r`'s
 *     into a fresh $v0. Third time an idiom has wanted opposite spellings at
 *     two sites of one function (func_80026DC8, func_80036C14 are the
 *     others).
 * Permuter ran to 2763 iterations from this base and produced no output at
 * all, i.e. it never beat 14 either.
 */
#include "common.h"

s32 func_80027508(void) {
    u8 *e;
    u8 *o;
    s32 *t;
    s32 i;
    s32 j;
    s32 r;
    s32 c;
    s32 d;
    s32 w;

    if (!((func_8008E590() & 1) || func_80026DC8())) {
        return 0;
    }
    if (!((func_8008E590() & 1) || func_80027060())) {
        return 0;
    }
    if (!((func_8008E590() & 3) || func_8002712C())) {
        return 0;
    }
    if (!func_80027228()) {
        return 0;
    }

    e = &D_801A7AD8[(D_8009B1D5 * 0xF + func_800358FC(5)) * 28];
    t = D_801D4244;
    i = *(s16 *)(e + 0xC);
    i = i - 1;
    if (((t[i] >> 0x1A) & 0x1F) < 0x14) {
        r = func_80026C0C(5);
        if (r < 0) {
            r = func_800358FC(5);
        }
        c = e[0x18];
        d = (s8)c;
        o = D_800EAE88;
        o[1] = 0;
        o[6] = r % 5 + 1;
        d %= 5;
        d += 0xB;
        o[0] = d;
        o[7] = func_8008E590() & 1;
        goto one;
    }

    r = func_80026C0C(0xA);
    if (r < 0) {
        r = func_800358FC(5);
    }
    c = e[0x18];
    d = (s8)c;
    o = D_800EAE88;
    o[1] = 0;
    o[7] = 0;
    o[6] = r % 5 + 6;
    d %= 5;
        d += 0xB;
        o[0] = d;
    o[8] = func_8008E590() & 1;

    j = *(s16 *)(e + 0xC);
    j = j - 1;
    w = t[j];
    if (((w >> 0x1A) & 0x1F) == 0x17) {
one:
        o[8] = 1;
    }
    return 0;
}
