/* 14 differing at 248/248 (2026-09-06, first written from the m2c draft). The
 * memory-card format/read/verify/write state machine on the D_8009B3EB mode
 * nibble, with cases 1 -> 2 -> 3 falling through inside nested ifs (a jump
 * table, so only the full build proves it). What paid, in order: D_801D5648
 * as an unsized array (retail wants cc1psx's own pair, gp=62 rules out -G);
 * the ack argument assigned AFTER the directory call in case 1, not before
 * (+1 -> -3: it was surviving the call in a callee-saved register); the
 * done block (D_8009B3FA |= 0x1000) placed after the write call at the end of
 * case 3 with gotos from cases 0 and 2; case 0's inner arm returning on
 * both paths (m2c's break exits the OUTER switch); cases 2 and 3 with a
 * named state read, re-read after the func_8003E46C call, and the write
 * block as case 3's fall-through with the rest out of line; the write
 * call written in BOTH arms of the source select with the global tested
 * and passed directly (a named copy lets CSE fold the else arm to 0); and
 * D_8009B3C4 += 0x80 before the D_8009B3C2 update.
 * Residue: the two state reads land in $a3 where retail has $a0 (case 2)
 * and $v1 (case 3); one name, two names, u8, and four declaration orders
 * are all 14. Permuter next. */
#include "common.h"

void func_8003E46C(s32 arg0, s32 arg1);
s32 func_8008BC90(s32 arg0);
void func_8008C638(s32 arg0, u8 *arg1, u8 *arg2, s32 arg3, s32 arg4);
void func_8008C858(s32 arg0, u8 *arg1, u8 *arg2, s32 arg3, s32 arg4);
s32 func_8008CA78(s32 arg0, u8 *arg1, u8 *arg2, s32 *arg3, s32 arg4, s32 arg5);

void func_8003EED0(void) {
    s32 sp18;
    s32 m;
    s32 a;
    s32 v;
    s32 w;
    s32 c2;
    u8 t;
    u8 *dst;

    if ((D_8009B3C1 & 0x80) == 0) {
        D_8009B3C1 |= 0x80;
        func_8003E46C(0xC0, 0);
        D_8009B3EB = 0;
    }
    m = D_8009B3EB & 0xF;
    switch (m) {
    case 0:
        if ((D_8009B3EB & 0x80) == 0) {
            D_8009B3EB |= 0x80;
            D_801D5648[0] = (D_8009B3F9 >> 4) + 1;
            while (func_8008BC90(D_8009B3F9) == 0) {
            }
            goto done;
        }
        switch (D_8009B3F4) {
        case 1:
            a = 0xC1;
            goto ack;
        default:
            return;
        case 0:
        case 3:
            D_8009B3EB = 1;
            t = D_8009B3F9 ^ 0x10;
            D_8009B3F9 = t;
            if (t != 0) {
                D_8009B3EB = 0;
            }
            return;
        case 2:
            a = 0xDA;
            goto ack;
        case 4:
            a = 0xC3;
            goto ack;
        }
    case 1:
        D_801D5648[0] = (D_8009B3F9 >> 4) + 1;
        if (func_8008CA78(D_8009B3F9, D_800EFE18, D_800EFBC0, &sp18, 0, 0xF) != 0) {
            a = 0xDA;
            goto ack;
        }
        a = 0xC3;
        if (sp18 == 0) {
            goto ack;
        }
        t = D_8009B3F9 ^ 0x10;
        D_8009B3F9 = t;
        if (t != 0) {
            D_8009B3EB = m;
            return;
        }
        D_8009B3EB = 2;
    case 2:
        w = D_8009B3EB;
        if ((w & 0x80) == 0) {
            D_8009B3EB = w | 0x80;
            D_8009B3EC = 0;
            D_801D5648[0] = (D_8009B3F9 >> 4) + 1;
            func_8008C638(D_8009B3F9, D_800EFE18, D_801DC000, D_8009B3C4, 0x480);
            goto done;
        }
        if ((w & 0x40) == 0) {
            D_8009B3EB = w | 0x40;
            a = 0xDA;
            if (D_8009B3F4 != 0) {
                goto ack;
            }
        }
        dst = (u8 *)D_8009B3D0;
        if (D_8009B3F9 != 0) {
            dst = D_8009B3E0;
        }
        if (func_8003D288(dst, D_801DC000) == 0) {
            a = 0xC3;
            if (D_8009B3EC == 0) {
                D_8009B3EC += 1;
                D_8009B3EB &= 0xBF;
                func_8008C638(D_8009B3F9, D_800EFE18, D_801DC000, D_8009B3C4 + 0x680, 0x480);
                goto done;
            }
            goto ack;
        }
        t = D_8009B3F9 ^ 0x10;
        D_8009B3F9 = t;
        if (t != 0) {
            D_8009B3EB = 2;
            return;
        }
        D_8009B3EB = 3;
    case 3:
        w = D_8009B3EB;
        if ((w & 0x80) == 0) {
            D_8009B3EB = w | 0xC0;
            func_8003E46C(0xC4, 0);
            w = D_8009B3EB;
        }
        if (w & 0x40) {
        write:
            D_8009B3EB &= 0xBF;
            if (D_8009B3F9 != 0) {
                func_8008C858(D_8009B3F9, D_800EFE18, D_8009B3E0, D_8009B3C4, 0x80);
            } else {
                func_8008C858(D_8009B3F9, D_800EFE18, (u8 *)D_8009B3D0, D_8009B3C4, 0x80);
            }
        done:
            D_8009B3FA |= 0x1000;
            return;
        }
        if (D_8009B3F4 != 0) {
            a = 0xC5;
            goto ack;
        }
        D_8009B3EB = w | 0x40;
        t = D_8009B3F9 ^ 0x10;
        D_8009B3F9 = t;
        if (t == 0) {
            D_8009B3D0 += 0x80;
            D_8009B3E0 += 0x80;
            D_8009B3C4 += 0x80;
            c2 = D_8009B3C2 - 0x80;
            D_8009B3C2 = c2;
            if ((c2 & 0xFFFF) == 0) {
                D_8009B3EF = 1;
                a = 0xC6;
                goto ack;
            }
        }
        goto write;
    }
    return;

ack:
    func_8003E46C(a, 0x18);
}
