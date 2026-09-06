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
 * produces here. Discriminator not established. */
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
