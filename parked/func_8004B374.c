/* 13 differing at 74/74 under default -O2 -G8 with the assembler at -G0
 * (PER_FUNC_AS_FLAGS); 11 under -G0 -mno-split-addresses, where two of the
 * 11 are the D_80011434 pair assembled through $s3 instead of cc1psx's own
 * pair via $v0 -- so the -G8 route is the one whose instruction stream is
 * right and the one installed. PURE C, 2026-09-05.
 *
 * The 21 of the previous park were one mechanism, now CLOSED: gcc hoisted
 * the per-iteration `andi $v0,$s5,0xFF` (arg1's mask) out of the
 * call-bearing loop because the loop had NOTE_INSN_LOOP_BEG/END. Written as a
 * `goto` loop (label at the top, `if (i < n) goto top;` at the bottom) the
 * loop pass never runs on it, the mask stays inside, the `nop` in the compare's
 * delay slot goes away, and the residue is register names only (29). Then:
 *   29 -> 22  `a1 = arg1;` named at the top, masked at the use
 *   22 -> 11  `mask = 0;` written BEFORE `i = 0;`
 * Dead: `i = 0; mask = i;` (22), a shared zero name (11), off/tbl orderings
 * (16, 17), `off = i` (11), both params named (22).
 * The residue is i / mask / off rotated through $s0-$s2: allocation only.
 */
#include "common.h"

void func_8004B374(s32 arg0, s32 arg1) {
    u8 *base;
    s32 mask;
    s32 i;
    s32 off;
    s32 *tbl;
    s32 v0;
    s32 t1;
    u8 *p;
    s32 a1;

    a1 = arg1;
    base = D_8009B458;
    mask = 0;
    i = mask;
    if (*(s16 *)(base + 0x510) > 0) {
        t1 = arg0 & 0xFF;
        tbl = D_80011434;
        off = 0;
        top:
            p = base + off;
            if (p[0x183] == t1 && p[0x185] == (u8)a1) {
                func_8004A7C0(i);
                mask |= *tbl;
            }
            tbl++;
            off += 0x28;
            base = D_8009B458;
            i++;
            if (i < *(s16 *)(base + 0x510)) goto top;
    }

    if (mask != 0) {
        do {
            func_80076ED0(0, mask);
            v0 = func_80077090(mask);
        } while (v0 != 2 && v0 != 0);
    }

    {
        u8 *q = D_8009B458 + ((u8)arg0) * 0x18;
        q[4] = 0;
    }
}
