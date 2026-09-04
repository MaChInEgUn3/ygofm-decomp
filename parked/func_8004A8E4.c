/* 11 differing at 23/23, from 17. RECOVERED from git 2026-09-04 (the Unchiga
 * merge deleted it and put a transcription in src/).
 *
 * TWO COUPLED LEVERS, and the coupling matrix is the finding:
 *
 *     u8 v (narrowing) alone .................... 16
 *      before the test alone .......... 17  (nothing)
 *     narrowing + borrow ........................ 18  (WORSE than either)
 *     narrowing + block-2 split ................. 11  <- installed
 *     narrowing + borrow + split ................ 12
 *     borrow + split ............................ 17
 *     block-2 split alone ....................... 17
 *
 * So the pair that works is the narrowing and the split, and adding the third
 * edit COSTS one. The permuter found the three-way version and scored 12; the
 * two-way decomposition is 11, i.e. reading what it changed beat its own
 * output.  in its output is  under -D__CHAR_UNSIGNED__ and is
 * semantically identical here, because e[3] is a byte and every use promotes.
 *
 * What is left is still the pair of trading faults described below: retail
 * loads D_8009B458 ONCE into $a2 and reuses it, spending the instruction it
 * saves on , a copy of the byte. A base local shares the
 * load and costs two instructions to gcc's fold of 0x180 into the displacement
 * (-2, three spellings); a second name for the byte does not produce the copy
 * (11, two spellings: a fresh name, and ).
 */
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
