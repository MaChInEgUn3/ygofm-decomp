/* 4 differing at 102/102 (2026-09-12; was 5, was 7). Flags: -O2 -G8
 * -fno-strength-reduce, as -G0.
 *
 * 5 -> 4 is ONE LINE MOVED: `q = e;` goes LAST among the four preheader
 * initialisations instead of first. The permuter found it inside a candidate
 * that also carried an uninitialised read (`if (o)` with two identical arms,
 * the reject class WORKFLOW names); decomposed, the read and the other two
 * edits it carried -- `m = base - -1` and `e = D_801A8000 + (6 * (idx * 4))`
 * -- are worth EXACTLY NOTHING alone or together, and the reordering is the
 * whole gain. The permuter's own ranking is the wrong way round here: its
 * best score (90) re-scores to 5 and this one (150) to 4.
 *
 * BASE-LOCAL AXIS DEAD, and re-measured on THIS base rather than trusted from
 * the 2026-09-06 note: `s32 *t = D_801D5608;` at five positions (first
 * statement, before `base`, before `i = 0`, before `q = e`, under both
 * preheader orders) is 101 against 102 every time -- the local removes the
 * loop pass's hoisted invariant and the function comes out an instruction
 * short. Splitting the use so only `t[0]` goes through the local is 103. Ten
 * measurements, all worse.
 *
 * The 4 left: retail puts the `lui %hi` / `addiu %lo` pair for D_801D5608 at
 * the START of the preheader, between `i = 0` and `q = e`; gcc's loop pass
 * emits a hoisted invariant at the END of the preheader, after every source
 * statement. No source ORDER reaches it -- eight have been measured across
 * the two entries -- because the position is the loop pass's, not the
 * source's. Reaching it needs the address to be a source statement that does
 * NOT fold, and the base local folds.
 */
#include "common.h"

void func_80060E70(u8 *p, s32 idx, s32 flag) {
    u16 *w;
    u8 *e;
    u8 *q;
    u8 *r;
    u8 *s;
    u8 *o;
    s32 i;
    s32 y;
    s32 base;
    s32 n;
    s32 m;
    s32 k;

    e = D_801A8000 + idx * 0x18;
    *(s16 *)(e + 8) = flag;
    (*(u8 **)e)[0x68] = flag;
    base = 0x18;
    if (flag != 0) {
        base = 0x1A;
    }

    i = 0;
    y = 0;
    s = p + 2;
    q = e;

    do {
        n = (*(u16 *)(q + 0xA) = *(u16 *)p);
        m = *(u16 *)p;
        if (m != 0) {
            n = m;
            m = base;
            if (((D_801D4244[n - 1] >> 26) & 0x1F) >= 0x14) {
                m = base + 1;
            }
            D_801D5608[0] = n;
            k = *(u16 *)s;
            D_8009B338 = n;
            D_801D5608[1] = k;
        }

        o = func_80035BE4(idx + 1, m, *(s16 *)(e + 4), *(s16 *)(e + 6),
                          0x120, 0xB0);
        *(s16 *)(o + 0x3A) = y;
        w = (u16 *)(q + 0xA);
        if (*(u16 *)s == 0) {
            o[0x54] = 4;
            *w = *w | 0x8000;
        }
        if (i != 0) {
            *(u16 *)(o + 0x34) = *(u16 *)(o + 0x34) | 0x40;
        }
        func_80039A14(o);
        s += 4;
        p += 4;
        q += 2;
        i++;
        y += 0x16;
    } while (i < 7);
}
