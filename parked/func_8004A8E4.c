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
 * and a fresh s32 name for the byte are all 11. Permuter next. */
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
