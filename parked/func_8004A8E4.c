/* 17 differing at 23/23, every one a register name. RECOVERED from git
 * 2026-09-04 (the Unchiga merge deleted it and put a transcription in src/).
 *
 * The residue read as structure rather than as a count. Retail loads
 * D_8009B458 ONCE into $a2 and reuses it for both address computations, where
 * we emit a second `lw` -- and the lengths still match, because retail spends
 * its extra instruction on `addu $v0,$v1,$zero`, a COPY of the byte it just
 * read, which we do not have. So the two faults are "share the base" and "a
 * second name for the byte", and they trade against each other.
 *
 * Six spellings measured 2026-09-04, none better than 17:
 *   a `u8 *b` base local read once, used by both blocks        -2 and 21
 *   the same plus a second name for the byte                   -2 and 21
 *   the same with `+ 0x180` moved into the address expression  -2 and 20
 *   the second block split into `e = D_8009B458[0]; e = e + off;`  17
 *   the same plus a second name for the byte                       17
 *   the same with the names exchanged between the two blocks       17
 * The three base-local rows confirm the note that was already here: a base
 * local re-enables the fold gcc makes of 0x180 into the load displacement,
 * which is what costs the two instructions. The three split rows are
 * byte-identical to the base, i.e. the wrong axis.
 * Permuter started on it 2026-09-04; 23 instructions is inside the band where
 * WORKFLOW calls that mandatory.
 */
#define D_8009B458_IS_AGGREGATE
#include "common.h"

s32 func_8004A8E4(s32 arg0) {
    u8 *e;
    s32 off;
    s32 v;

    off = arg0 * 40 + 0x180;
    /* Two statements against one name. As `e = D_8009B458[0] + off;` gcc folds
     * the 0x180 into the load displacement (`lbu ...,387`) and flips the
     * addu's operands; the split keeps retail's `addiu $v0,$v0,384` and
     * `addu $a1,$a2,$v0`. A base local re-enables the fold -- four spellings
     * with one all came out -2. */
    e = D_8009B458[0];
    e = e + off;
    v = e[3];
    if (v != 0x63) {
        off = v * 24;
        e = D_8009B458[0] + off;
        v = e[6];
        if ((v & 0xF) != 0) {
            e[6] = v - 1;
        }
    }
    return arg0;
}
