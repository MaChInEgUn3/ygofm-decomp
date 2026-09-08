/* +2 at 227/225, 104 differing, CENSUS = `nop` ONLY (2026-09-08). THE FIRST REAL C THIS FUNCTION HAS EVER HAD.
 * src/func_80018608.c is an ASSEMBLY-DEBT transcription whose instructions
 * are written as `.word`, and `git log --all -- parked/func_80018608.c` is
 * empty, so nothing was thrown away here -- it had simply never been
 * attempted. Written from the m2c draft plus the listing in one pass.
 * gp=15, at=0, so default flags; three symbols are read `%hi`/`%lo` while
 * fifteen gp-relative accesses remain, which rules out `as -G0` and makes
 * the `.data` arms the only route: D_8009B0F4, D_8009B134 and D_8009B36A.
 *
 * Shape: an init guard on D_8009B23A's 0x8000 bit, then a comparison TREE
 * (not a jump table -- four cases, range 4, below gcc 2.8's threshold) on
 * `D_8009B174 & 0x1F` with cases 2, 3, 4 and 5 in address order. Case 4 runs
 * two identical 40-iteration loops over the 6-byte records of D_801A7E20,
 * the second starting at +0xF0, each summing two 9-bit fields of
 * D_801D4244[rec - 1] times ten and storing the sums divided by 40 (the
 * 0x66666667 reciprocal with `sra 4`).
 *
 * THE CENSUS IS THE WHOLE DIAGNOSIS and the difference count is useless
 * here: `lw` and `sw` are both -2 and everything else is within one. Retail
 * saves FOUR callee-saved registers -- $s0 for the mode, $s1 for
 * D_800F2848's full address, $s2 for its `%hi` half, $s3 for the constant 3
 * -- and we save two. Every remaining difference is downstream of that.
 *
 * The named constant 3 (`three = 3;` before the guard, used for both
 * `D_8009B174 = 3` in case 2 and `D_8009B23A = 3` in case 5) buys one of the
 * two: -2 to -1. Retail materialises 3 once, in the dispatch tree's own
 * `beq`, and keeps it to the end.
 *
 * Measured and DEAD, all worse: a `u8 *f = D_800F2848;` base local hoisted
 * above the guard and used everywhere (+2/108), the same with the named 3
 * (+3/220), the local scoped to case 2 only (+3/224), and scoped to the
 * entry branch only (+3/224). The base local is ONE register and retail
 * wants TWO -- the `%hi` half in $s2 and the full address in $s1, with the
 * `[0]` store going through `%lo(D_800F2848)($s2)` and the others through
 * `N($s1)`. No source spelling tried produces that pair, and the local
 * overshoots by three where the gap is one.
 * -1/218 -> +1/134, and the lever is a DEAD ASSIGNMENT: `f = D_800F2848;`
 * written above the entry guard and never read, with every reference to the
 * symbol left inline. That buys one of the two missing registers -- the
 * census goes from five divergent opcodes to four, `lui` comes right, and
 * `lw`/`sw` improve from -2 to -1. The mechanism is func_80031574's rule at
 * function scope: gcc emits `lui %hi` / `addiu %lo` for the assignment,
 * cannot fold it away because the pseudo is allocated, and then reuses the
 * `lui` half for every `%lo(D_800F2848)($r)` reference in both arms -- which
 * is exactly retail's $s2, with $s1 the full address.
 * The candidate is now +1 rather than -1, so it swapped sides of exact
 * length; it wins on every other key (census 4 against 5, and 134 against
 * 218), which is what the ranking says to prefer.
 *
 * Measured and DEAD from the -1 base: a base local USED for the +2/+4
 * accesses with the symbol kept for [0] (+3/224, and +3 with the assignment
 * moved above `three`), the local used only in case 2 (+3/224), used only in
 * the entry branch (+3/224), a second dead local derived from it (`g = f +
 * 2;`, does not compile as written and is not the axis), and a dead local
 * for D_800E9F10 as well (+1/134, identical -- gcc drops the second one).
 * Every spelling that USES the local costs three, and the only one that pays
 * is the one that does not.
 * AND THEN THE OPPOSITE, same night: the +1/134 candidate above is NOT the
 * one installed. Reading the built listing of the spelling that USES the
 * local -- the one rejected at "+3" three times -- its census is ONE opcode
 * and that opcode is `nop`: 20 against 23, with the frame, all FOUR
 * callee-saved saves, and every real instruction already correct. The +3 was
 * three load-delay slots, not three missing instructions, and the
 * difference count had been hiding that behind a positional shift.
 *
 * So the installed candidate reads the local (`u8 *f = D_800F2848;` above
 * the guard, used for the +2 and +4 accesses, with the [0] accesses left on
 * the symbol so the `%hi` half stays its own pseudo), and two further edits
 * take it from +3/224 to +2/104:
 *   - DROP the named constant 3 entirely. Retail materialises it with
 *     `addiu $s3,$zero,3` in the DELAY SLOT of the dispatch's own
 *     `lbu D_8009B174`, and a hoisted `three` is already in a register there
 *     so the slot takes a `nop`. Removing the name, or assigning it just
 *     before or just after `mode = D_8009B174 & 0x1F;`, are all +2/108 --
 *     the same number, so the name is simply not wanted once the local is.
 *   - the case 2 reads in retail's order: `+4` before the `+2` pair
 *     (+2/108 -> +2/104). Naming the +4 value instead, either whole or with
 *     the `- 2` moved to the store, is 108 both ways.
 *
 * This is installed AGAINST the strict ranking key, deliberately. By
 * (|length|, census, differences) the +1/134 candidate wins on the first
 * term. But its census is four divergent opcodes including `lw -1, sw -1`,
 * i.e. a whole callee-saved register missing, while this one is two
 * load-delay `nop`s and nothing else. WORKFLOW's own caveat applies: the
 * ranking assumes the length error is one fault, and a nearly-empty census
 * is closer than a small length error with structure behind it.
 *
 * Measured and dead on the way: dead-assignment chains to allocate both
 * address halves (`d2 = f;` +3, `d2 = f + 4;` +3, `d2 = D_800F2848 + 4;`
 * +1/134 identical, the same reordered +1/134), `f = D_800F2848 + 2;` as
 * the dead one (-1/218), and the full flag sweep from the local-used base,
 * whose best row is `-mno-split-addresses` at -4/177.
 * What is left: TWO load-delay `nop`s. Every other instruction in 225 is
 * accounted for.
 */
#define D_8009B0F4_IN_DATA
#define D_8009B134_IN_DATA
#define D_8009B36A_IN_DATA
#include "common.h"

void func_80018608(void) {
    s32 mode;
    u8 *f;
    u8 *e;
    u8 *g;
    s32 i;
    s32 j;
    s32 sa;
    s32 sb;
    s32 w;
    s32 h;

    f = D_800F2848;
    if ((D_8009B23A & 0x8000) == 0) {
        D_8009B23A |= 0x8000;
        func_80024734();
        *(s16 *)D_800F2848 = 0x4B0;
        *(s16 *)(f + 4) = 0x358;
        *(s16 *)(f + 2) = 0x16C0;
        func_8001352C();
        D_8009B174 = 2;
        func_800157DC();
        return;
    }

    mode = D_8009B174 & 0x1F;
    switch (mode) {
    case 2:
        *(s16 *)D_800F2848 = *(s16 *)D_800F2848 - 2;
        *(s16 *)(f + 4) = *(s16 *)(f + 4) - 2;
        h = *(u16 *)(f + 2) - 0x10;
        *(s16 *)(f + 2) = h;
        if ((s16)h < 0x401) {
            *(s16 *)D_800F2848 = 0x258;
            *(s16 *)(f + 4) = 0x100;
            *(s16 *)(f + 2) = 0x400;
            D_8009B174 = 3;
        }
        func_8001352C();
        return;

    case 3:
        if ((D_8009B174 & 0x80) == 0) {
            D_8009B174 |= 0x80;
            D_8009B162 = 2;
            e = &D_800E9F10[D_8009B1D5 * 0x70];
            D_8009B1B4 = e;
            *(s16 *)(e + 0xC) = 0xAE;
        }
        if (D_8009B162 == 0) {
            D_8009B174 = 4;
        }
        return;

    case 4:
        if (((D_8009B0F4 & 0x2000030) | D_8009B134) == 0) {
            func_8003FF08(D_8009B36A);
            func_80024824();
            sa = 0;
            sb = 0;
            g = D_801A7E20;
            i = 0;
            do {
                i += 1;
                j = *(s16 *)g;
                j = j - 1;
                w = D_801D4244[j];
                sa += (w & 0x1FF) * 10;
                sb += ((w >> 9) & 0x1FF) * 10;
                g += 6;
            } while (i < 0x28);

            sa = sa / 40;
            sb = sb / 40;
            *(s16 *)((u8 *)D_800E9FF0 + 0xE) = sa;
            *(s16 *)((u8 *)D_800E9FF0 + 0x10) = sb;

            sa = 0;
            sb = 0;
            g = D_801A7E20 + 0xF0;
            i = 0;
            do {
                i += 1;
                j = *(s16 *)g;
                j = j - 1;
                w = D_801D4244[j];
                sa += (w & 0x1FF) * 10;
                sb += ((w >> 9) & 0x1FF) * 10;
                g += 6;
            } while (i < 0x28);

            D_8009B174 = 5;
            *(s16 *)((u8 *)D_800E9FF0 + 0x2E) = sa / 40;
            *(s16 *)((u8 *)D_800E9FF0 + 0x30) = sb / 40;
        }
        return;

    case 5:
        func_800176D0();
        D_8009B1EC = mode;
        D_8009B23A = 3;
        *(s32 *)(&D_800E9F10[D_8009B1D5 * 0x70] + 8) = (s32)D_800EA030;
        return;
    }
}
