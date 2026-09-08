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
 * Permuter next.
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
