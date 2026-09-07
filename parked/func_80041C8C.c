/* 2026-09-05 permuter (1475 iterations): its best output re-scores 3 through
 * try_func by reading `p` UNINITIALISED in `if (p) { read } else { read }`
 * round the preheader read -- the entry-live-pseudo class of func_80046768,
 * not installable. Legal spellings of the same idea: `p = (u8 *)0;`,
 * `p = arg0;`, `p = arg0 + 8;` as a first statement and a do/while(0) pin are
 * all 8; `if (arg0 != 0)` with identical arms is 10. Mechanism named, no
 * spelling found.
 * 2026-09-05, still 8 ($a0/$a1 for the opcode pointer): while (1) with the
 * read at the top and break (-7), goto-top unrotated do/while (-12), and
 * `op = *p; p++;` (8, identical) -- the loop form is right and the residue is
 * allocation only. Permuter next.
 * 2026-09-07, the scorer's 8 -> 3 output decomposed and DEAD. The output is
 * `if (p) { read } else { read }` reading p uninitialised, and the two halves
 * of it were measured together for the first time (the park had only ever
 * measured them apart, which is the coupled-levers case). Duplicated identical
 * arms with p initialised first -- `p = arg0 + 8;`, `p = arg0;`, conditions
 * `p`, `p != 0`, `arg0 != 0`, and no init with `if (arg0 + 8)` -- are all 10,
 * five spellings scoring identically, which is the wrong-axis tell: gcc merges
 * the arms whatever the condition, and the 3 came from the uninitialised read
 * alone. An entry-live pseudo spelled LEGALLY as an extra parameter is also
 * dead: `(u8 *arg0, u8 *p)`, `(u8 *arg0, s32 op)` and both together are 8,
 * unchanged. Six spellings of the pointer read (two statements, a named
 * offset, a named base, declaration order, the embedded `op = *(p = ...)`)
 * are 8 or 12. The whole residue is p in $a0 where retail has $a1, eight
 * sites, nothing else in the listing differs. */
#include "common.h"

void func_80041C8C(u8 *arg0) {
    u8 *p;
    s32 op;
    s32 val;

    p = *(u8 **)(arg0 + 0x50) + *(u16 *)(arg0 + 0x58);
    op = *p++;
    while (op >= 0xF0) {
        if (D_80090FEC[op ^ 0xFF](arg0) == -1) {
            return;
        }
        p = *(u8 **)(arg0 + 0x50) + *(u16 *)(arg0 + 0x58);
        op = *p++;
    }
    *(s16 *)(arg0 + 0x5A) = op;
    *(s32 *)(arg0 + 0x4C) =
        *(s32 *)(arg0 + 0x54) + ((p[1] << 8) | p[0]);
    *(u16 *)(arg0 + 0x58) += 3;
}
