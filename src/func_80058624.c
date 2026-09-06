/* MATCH 2026-09-06. Parked at 1 for weeks on the pan's absolute value:
 * retail copies the quotient into the result (`addu $v1,$v0`) and negates
 * the COPY in place; `v = w; if (w < 0) v = -v;` lets copy propagation
 * negate w into v instead. The sibling func_8005A6A8's spelling is the
 * fix: `w = v < 0; if (w) v = -v;` -- the condition through the same name
 * as the quotient, which keeps v its own register. Everything else as the
 * park had it (the two square roots, the 700 subtracted after the second
 * call, the named listener fields).
 */
#include "common.h"

void func_80058624(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 st[2];
    s8 *pp;
    u8 *p;
    s32 dx;
    s32 dz;
    s32 a;
    s32 b;
    s32 c;
    s32 d;
    s32 ex;
    s32 ez;
    s32 n;
    s32 r;
    s32 dd;
    s32 v;
    s32 w;

    dx = *(s32 *)D_800F56F0 - arg2;
    p = D_800F56F0;
    dz = *(s32 *)(p + 8) - arg3;
    pp = (s8 *)&st[1];
    st[0] = 0;
    st[1] = 0;
    r = func_80086E50(dx * dx + dz * dz);
    b = *(s32 *)(p + 8);
    c = *(s32 *)(p + 0xC);
    d = *(s32 *)(p + 0x14);
    ez = d - b;
    a = *(s32 *)D_800F56F0;
    ex = a - c;
    n = c * b - a * d;
    dd = func_80086E50(ez * ez + ex * ex);
    r = r - 0x2BC;

    st[0] = 0xFF;
    *pp = 0;
    if (r > 0) {
        v = 0xFF - r / 12;
        if (v < 0x10) {
            v = 0x10;
        }
        st[0] = v;
    }

    if (dd != 0) {
        r = (arg2 * ez + arg3 * ex + n) / dd;
        w = r / 16;
        v = w;
        w = v < 0;
        if (w) {
            v = -v;
        }
        if (v >= 0x80) {
            v = 0x7F;
        }
        w = v;
        if (r <= 0) {
            w = -w;
        }
        *pp = w;
    }

    if (arg1 != 0) {
        func_80048658(arg0 & 0xFFFF, st[0], *(s8 *)&st[1]);
    } else {
        func_80048A28(arg0 & 0xFFFF, st[0], *(s8 *)&st[1]);
    }
}
