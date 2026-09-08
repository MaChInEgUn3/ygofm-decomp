/* 163/163, 3 differing (recovered 2026-09-08). RECOVERED FROM GIT: this
 * candidate was written 2026-08-21, taken to 3, and then DELETED in 4eb106d
 * when Unchiga's port replaced the function -- so for two weeks the only
 * copy of it was in history and PARKED.txt's prose. src/func_80040588.c
 * still holds the ASSEMBLY-DEBT transcription (register pins on s3/s6/v0/v1/
 * a0 and three `__asm__` blocks) and the debt is retired only on MATCH.
 * Compiled at `-O2 -G8 -msplit-addresses` with `as -G4`, which are the rows
 * already in build.py for this function.
 * gp=2, at=0.
 *
 * The full recipe is in the PARKED.txt entry: `g`/`q`/`h`/`tb` as locals
 * inside the guard, `goto again;` back into the middle of the body,
 * `idx = e[0x17];` as the body's FIRST statement, `c66`/`n` named, plus the
 * two declarations that carry most of it -- `D_8009B424_IS_SCALAR` (the
 * unsized array lets gcc hoist a %hi into a callee-saved register, five
 * instructions long and one saved register too many) and `D_8009B146_SIZED`
 * with `as -G4` (eight bytes at -G4 makes each reference one indivisible
 * pseudo so the %hi/%lo pairs stay adjacent, 9 -> 4).
 *
 * The residue is THREE instructions and one of them: retail emits
 * `lhu $a2,6($s1)` / `addiu $a3,$s5,0x20` / `sw $zero,D_8009B424` and we
 * emit the same three as `addiu` / `sw` / `lhu`. Statement order does NOT
 * decide it, and that is now PROVED rather than assumed: all 24 orderings
 * of the three argument loads and the store were measured
 * (2026-09-08) and the best is 3 -- the original order, `u4/k18/st/u6` and
 * `u4/u6/k18/st` tie it, thirteen are 4 and six are 5. So the scheduler is
 * choosing, and the source cannot reach it by moving statements.
 *
 * Also measured and DEAD on this base, 2026-09-08: naming the fourth
 * argument `hp = h + 0x20;` at three positions (3 each -- the func_80025F3C
 * rule that a constant argument cannot be hoisted by naming it, confirmed),
 * routing the SECOND call through the same name (+2/160), naming the inline
 * `*(s16 *)(e + 0x1A)` read at four positions (7, 7, 3, 9) and a fifth (7),
 * and `do { D_8009B424 = 0; } while (0);` (11).
 * From the August pass, all 3 or worse: naming all three argument loads
 * (which is what took it from 4 to 3), both sums named, `(s16)` casts moved
 * onto the named reads, two other `do { } while (0);` groupings, `volatile`
 * on the global, and the full flag sweep (3 at the installed row, 81+
 * everywhere else).
 *
 * What is NOT yet tried: anything that makes the store and the load
 * CONFLICT in gcc's dependence test. Both are provably disjoint here (a
 * gp-relative scalar against a constant scratchpad address), so the
 * scheduler is free, and no statement order can constrain it. The permuter
 * has never produced a single output for this function.
 */
#define D_8009B146_SIZED
#define D_8009B424_IS_SCALAR
#include "common.h"

void func_80040588(void) {
    u8 *g;
    u8 *q;
    u8 *h;
    u8 *e;
    u8 *tb;
    ObjFn fn;
    s32 t;
    s32 idx;
    s32 c66;
    s32 n;
    s32 u4;
    s32 u6;
    s32 k18;
    s32 a3;
    s32 i;

    i = D_800EFE3A[0];

    if (i >= 0) {
        g = (u8 *)0x1F800344;
        q = (u8 *)0x1F800320;
        h = (u8 *)0x1F800378;
        tb = D_800E9D90;

        do {
            e = (u8 *)D_800EFE48 + i * 0x70;
            i = *(s16 *)(e + 2);
        again:
            fn = *(ObjFn *)(e + 0x24);
            if (fn != (ObjFn)0) {
                fn(e);
            }
            if (((*(u16 *)(e + 8) & 0xC0) ^ 0xC0) == 0) {
                *(s32 *)(q + 0) = *(s32 *)(e + 4);
                idx = e[0x17];
                *(s32 *)(q + 0x14) = *(s32 *)(e + 0xC);
                *(s32 *)(q + 4) = *(s32 *)(e + 0x30);
                *(s32 *)(q + 8) = *(s32 *)(e + 0x3C);
                *(s32 *)(q + 0x10) = *(s32 *)(e + 0x40);
                *(u16 *)(q + 0xE) = *(u16 *)(e + 0x5C);
                c66 = e[0x66];
                n = *(u16 *)(e + 0x14);
                t = *(s32 *)(tb + idx * 4);
                *(u16 *)(q + 0xC) = c66;
                a3 = n | 0x10000;

                if ((*(u16 *)(e + 8) & 8) == 0) {
                    *(u16 *)(q + 4) = *(u16 *)(q + 4) - D_8009B146[0];
                    *(u16 *)(q + 6) = *(u16 *)(q + 6) - D_8009B148[0];
                }

                if ((*(u16 *)(e + 8) & 4) != 0) {
                    u4 = *(u16 *)(q + 4);
                    k18 = *(s16 *)(e + 0x18);
                    u6 = *(u16 *)(q + 6);
                    D_8009B424 = 0;
                    if (func_80041F90(e, (s16)u4 + k18,
                                      (s16)u6 + *(s16 *)(e + 0x1A),
                                      h + 0x20) <= 0) {
                        goto next;
                    }
                    if (D_8009B424 != 0) {
                        goto again;
                    }
                    g[3] = 9;
                    *(s32 *)(g + 4) = *(s32 *)(q + 0x14);
                    g[7] = 0x2C;
                    if ((*(s32 *)(q + 0) & 0x40000000) != 0) {
                        func_80082840(g, 1);
                    }
                    a3 = *(u16 *)(e + 0x14) | 0xF0000;
                } else {
                    if ((*(s32 *)(q + 0) & 0x8000000) == 0) {
                        *(s32 *)(q + 0x20) = e[0x22] * 0x1680;
                        *(s32 *)(q + 0x1C) = *(s32 *)(e + 0x44);
                        *(s32 *)(q + 0x18) = *(s32 *)(e + 0x48);
                        *(u16 *)(q + 4) = *(u16 *)(q + 4) + *(u16 *)(q + 0x18);
                        *(u16 *)(q + 6) = *(u16 *)(q + 6) + *(u16 *)(q + 0x1A);
                        a3 = *(u16 *)(e + 0x14) | 0x30000;
                    }
                }

                func_80042188(q, g, t, a3, h + 0x20);
            }
        next:
            ;
        } while (i >= 0);
    }
}
