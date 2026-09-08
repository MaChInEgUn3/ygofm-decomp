/* 11 differing at 23/23 (2026-09-06; was 11 with the _IS_AGGREGATE arm and
 * -msplit-addresses, a different 11). gp=0, at=0, so D_8009B458 takes its
 * real pointer-scalar declaration with the assembler at -G0 (build.py row);
 * retail loads it bare into $a2 ONCE and keeps it for both blocks. The
 * exact-length shape: `e = D_8009B458; b = e; e = e + off;` -- the load into
 * e then modified in place is what stops gcc folding the 0x180 into the lbu
 * displacement (a base local with `e = b + off`, `e = b; e = e + off;`, a
 * two-statement off, the one-expression sums and an (s32) cast sum are all
 * -2, the fold plus the lost copy), and b carries the base into block 2.
 * Residue: retail has no base copy (the load lands in $a2 directly) and
 * instead copies the byte v into $v0 before the *24 chain; ours copies the
 * base (`addu $a2,$a1`) and multiplies v in place. `off = v;` then
 * `b + off * 24`, `e = b; e = e + off * 24;`, `off = v; off = off * 24;`
 * and a fresh s32 name for the byte are all 11. Permuter (2026-09-06, from
 * this base): best re-scores 7 at 23/23 and is the duplicated-identical-arms
 * trick (`if (e) {A} else {A}` round block 2) plus `off = arg0 * 40; off =
 * off + 0x180;` -- an allocation hint, not source; output-240-1 is 8 the
 * same way. Also 11 from this base: a `do { } while (0)` round block 2,
 * round `off = v * 24` alone, `e = b + v * 24` inline, `off = v; e = e +
 * off * 24;`, `w = v; off = w * 24;`. Every `e = b + off` spelling with b
 * the load's own name folds 0x180 into the lbu and is -2 (`(u8 *)(off +
 * (s32)b)`, `&b[off]`, `off = 0` after, a pinned off is -1); reading e[3]
 * inline twice is +1. sweep_try flat at 11. What retail says: the base
 * load's OWN pseudo is the long-lived one ($a2, no copy), `off` is $v0 in
 * block 1 and the product is $v1 in block 2 (two pseudos), and the byte is
 * COPIED into $v0 before the *24 chain -- a copy a promoted u8 never
 * produces here. Discriminator not established.
 *
 * 2026-09-08: THE ADDRESS AXIS IS NOW EXHAUSTED, not merely sampled.
 * Sixteen spellings of the block-1 address were measured and every one
 * except the installed `e = D_8009B458; b = e; e = e + off;` is -2:
 * six more base-local forms (`e = b + 0x180; e = e + arg0 * 40;`,
 * `b + 0x180 + off`, `&b[off]`, `e = b; e += off;`, the (s32) cast sum,
 * and the subtraction-of-a-negation `b - -off`), the two-statement
 * `off = arg0 * 40; off = off + 0x180;` on top of each, and -- the one
 * that had never been tried -- the POINTER SYMBOL WRITTEN INLINE, both
 * blocks (v1) or block 1 only (v2). Inline is -2 as well, so gcc commons
 * the two loads by itself AND still folds. Block 2 alone inline is +1.
 * The rule that falls out: whenever the base is a value gcc can NAME --
 * a local, or the pointer symbol -- it reassociates `b + (i * 40 +
 * 0x180)` and folds the constant into the lbu displacement. The only
 * thing that stops it is the load's OWN pseudo modified in place, and
 * that spelling is what costs the base copy retail does not have.
 * Also dead at 11 (2026-09-08): the product written into the byte's own
 * name with `off` holding the copy (`off = v; v = off * 24;`, 15), the
 * same through a separate `e = b; e = e + v;` (15), the multiply hand-
 * expanded as `(off * 2 + off) * 8` (15), and `v = v * 24;` on one name
 * (15) -- all four need `v` declared `s32`, and that declaration alone
 * is worth -4, which is why they read as regressions. `u8 v` is
 * load-bearing.
 * The residue is ONE instruction's worth of allocation: retail spends
 * its 23rd instruction copying the BYTE into $v0 in the beq's delay
 * slot, and we spend ours copying the BASE before the block.
 *
 * 2026-09-08, second pass, read with the difflib ALIGNMENT rather than the
 * positional diff: the residue is exactly THREE blocks -- the base's
 * register name, our extra `addu $a2,$a1,$zero` where retail has none, and
 * block 2's chain running `$v0 <- $v1` where retail runs `$v1 <- $v0` after
 * a copy.
 *
 * And the fold's mechanism is now PROVED rather than inferred. `u16 off`
 * with the derived form (`b = D_8009B458; e = b + off;`, NO base copy at
 * all) is 23/23 and 12: the truncation stops gcc reassociating
 * `b + (arg0 * 40 + 0x180)`, so the constant stays in the offset and the
 * +0x180 is NOT folded into the load -- which every s32 spelling of the
 * sixteen above does. It costs an `andi $v0,$v0,65535` exactly where retail
 * has `addiu $v0,$v0,384`, so it trades the base copy for a mask and the
 * count is one worse; `s16 off` is +1/21. But it settles what sixteen dead
 * spellings could only suggest: the fold is REASSOCIATION, and the only
 * things that block it are a value gcc cannot re-derive -- a truncation, or
 * the load's own pseudo modified in place, which is what costs the copy.
 * Also re-measured on this base: a dead `e = D_8009B458;` beside the used
 * `b` (11) and the byte copied into `off` before the multiply (11). */
#include "common.h"

s32 func_8004A8E4(s32 arg0) {
    u8 *e;
    s32 off;
    u8 v;
    u8 *b;

    off = arg0 * 40 + 0x180;
    e = D_8009B458;
    b = e;
    e = e + off;
    v = e[3];
    if (v != 0x63) {
        off = v * 24;
        e = b;
        e = e + off;
        v = e[6];
        if ((v & 0xF) != 0) {
            e[6] = v - 1;
        }
    }
    return arg0;
}
