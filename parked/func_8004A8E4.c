/* 11 differing at 23/23, from 17. RECOVERED from git 2026-09-04 (the Unchiga
 * merge deleted it and put a transcription in src/).
 *
 * TWO COUPLED LEVERS, and the coupling matrix is the finding:
 *
 *     u8 v (narrowing) alone ......................... 16
 *     `off = v;` before the test, alone .............. 17  (nothing)
 *     narrowing + that borrow ........................ 18  (WORSE than either)
 *     narrowing + block-2 split ...................... 11  <- installed
 *     narrowing + borrow + split ..................... 12
 *     borrow + split ................................. 17
 *     block-2 split alone ............................ 17
 *
 * So the pair that works is the narrowing and the split, and adding the third
 * edit COSTS one. The permuter found the three-way version and scored 12; the
 * two-way decomposition is 11 -- reading what it changed beat its own output,
 * which is the first time that has happened here rather than the usual case of
 * a permuter win being implausible.
 *
 * Its `char v` is `u8` under -D__CHAR_UNSIGNED__ and is semantically identical
 * here, because e[3] is a byte and every use of v promotes to int, so the
 * narrowing goes in as written rather than being a width bug.
 *
 * What is left is the pair of trading faults: retail loads D_8009B458 ONCE
 * into $a2 and reuses it for both address computations, spending the
 * instruction it saves on `addu $v0,$v1,$zero`, a copy of the byte it just
 * read. A base local shares the load and costs two instructions to gcc's fold
 * of 0x180 into the load displacement (-2, three spellings). A second name for
 * the byte does not produce the copy (11, two spellings: a fresh local, and
 * `off = v; off = off * 24;`).
 */
/* 2026-09-05: the scalar arm with `as -G0` (retail loads the pointer ONCE
 * into $a2 and reuses it, which is what that arm gives) is -2 at 21/23 in
 * eight spellings: the 0x180 folds into the lbu displacement whatever the
 * base/offset naming, pinning or two-statement split, and the copy of v that
 * feeds the *24 never appears. The aggregate arm at 11 stays installed.
 * 2026-09-05, second pass, twelve more on the aggregate arm: a base local
 * `b = D_8009B458[0]` (which is what retail's single $a2 load says) is -2
 * whatever surrounds it -- `e = b + off` plain, pinned, with `off` pinned,
 * `e = b; e = e + off;`, the integer sum `(u8 *)((s32)b + off)`, and a
 * fresh `s32 c = e[3]` for the compare with `v = c` inside the arm. The
 * fold is combine substituting the single-use `off` def into `e = b + off`
 * and the 384 into the lbu; only the symbol form's self-referencing
 * `e = e + off` on the loaded pointer blocks it. The double read
 * `if (e[3] != 0x63) { v = e[3]; ...` does NOT give retail's delay-slot
 * copy `addu $v0,$v1,$zero` -- CSE folds it with no copy on either arm
 * (symbol form 17, base-local form -2). Permuter: never run from this base. */
#define D_8009B458_IS_AGGREGATE
#include "common.h"

s32 func_8004A8E4(s32 arg0) {
    u8 *e;
    s32 off;
    u8 v;

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
        e = D_8009B458[0];
        e = e + off;
        v = e[6];
        if ((v & 0xF) != 0) {
            e[6] = v - 1;
        }
    }
    return arg0;
}
