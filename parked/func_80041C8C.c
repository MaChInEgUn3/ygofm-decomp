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
 * allocation only. Permuter next. */
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
