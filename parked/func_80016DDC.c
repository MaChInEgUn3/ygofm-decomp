/* Natural form: 11 differing instructions.
 *
 * Replacing the guard with `a = d == 0; if (a) return;` reaches 1 -- using the
 * variable for the early test makes it live before the abs and fixes the whole
 * register assignment of the band selection. That is not plausible source and
 * it is not this candidate; it is recorded here so the next attempt knows the
 * register assignment is reachable and the remaining instruction is
 * `subu $a1,$zero,$a1`, retail negating the copy where gcc negates the
 * original. Do not start from the artificial guard: it is one instruction out
 * and structurally wrong, which is a worse place to start than eleven out and
 * right.
 *
 * 2026-09-04, re-measured after this file was RECOVERED from git -- the
 * Unchiga merge deleted it and put a transcription in src/. Still 11 at 37/37.
 * The note above explains the artificial guard by "making the variable live
 * before the abs", so eight plausible spellings of that were tried and every
 * one is WORSE:
 *   `s32 a = d;` as an initialiser above the guard                      12
 *   the same with the guard testing `a` instead of `d`                  12
 *   the same with `step` declared before `a`                            12
 *   the same with the abs written as a ternary                          12
 *   the difference computed into `a` first and `d = a;` after it,
 *     so `a` is live from the first statement, guard on `a`             12
 *   the same with the guard on `d`                                      12
 *   `step = 9;` hoisted above the abs                             -1 and 28
 *   `step = 9;` hoisted above the early-return guard               -1 and 29
 * So "live before the abs" is not the mechanism, or not one an initialiser
 * reaches. What the artificial guard actually does is assign a BOOLEAN to `a`
 * -- a different value, not a copy of `d` -- which is why copy propagation
 * cannot then rewrite the negation. That is the thing to attack.
 *
 * The residue read as two faults rather than eleven differences:
 *   1. `a` and `step` have exchanged registers ($a1 against $a2), which
 *      accounts for ten of the eleven; and
 *   2. one real instruction -- retail has `subu $a1,$zero,$a1`, negating the
 *      COPY, where we get `subu $a2,$zero,$v1`, negating the original,
 *      because gcc knows the copy still equals `d` and propagates it.
 */
#include "common.h"

void func_80016DDC(u8 *arg0) {
    s32 d = *(s16 *)(arg0 + 0x12) - *(s16 *)(arg0 + 0x14);
    s32 a;
    s32 step;

    if (d == 0) {
        return;
    }

    a = d;
    if (a < 0) {
        a = -a;
    }

    step = 9;
    if (a >= 0x12C) {
        step = 0x13;
    }
    if (a >= 0x3E8) {
        step = 0x2F;
    }
    if (a >= 0xBB8) {
        step = 0x61;
    }

    if (d > 0) {
        d -= step;
        if (d < 0) {
            d = 0;
        }
    } else {
        d += step;
        if (d > 0) {
            d = 0;
        }
    }

    *(u16 *)(arg0 + 0x12) = *(u16 *)(arg0 + 0x14) + d;
}
