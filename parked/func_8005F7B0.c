/* 5 differing at 30/30 (2026-09-05). Residue: the prologue's `sw $ra` --
 * retail stores it right after the argument copy, before the first global
 * read and the buf constants; gcc's second scheduler sinks it below them.
 * Measured 2026-09-05: buf[3] stored first (5), the four stores pinned (9),
 * the D_8009B07B read named before the stores (5), -fno-schedule-insns2
 * (9), -fno-schedule-insns (5). The same `sw $ra` placement is the residue
 * of func_8004A764 and func_8004A6F8; whatever pins it there is not a
 * source-order lever. gp=5, at=0, default flags.
 */
#include "common.h"

void func_8005F7B0(s32 arg0, s32 arg1) {
    s16 buf[4];
    s32 t;
    s32 f;

    buf[0] = arg0;
    buf[1] = 0;
    buf[2] = 0;
    buf[3] = 5;

    if (D_8009B07B == 1 && D_8009B07C == 1) {
        return;
    }

    t = D_8009B07A;
    if (t < 0) {
        f = 0;
    } else {
        D_8009B07A = (u8)D_8009B07A + 1;
        f = t > 0;
    }

    func_8005F91C(f, buf, buf, arg1);
}
