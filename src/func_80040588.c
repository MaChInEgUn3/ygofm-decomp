/* MATCH. Real C -- this retires the ASSEMBLY-DEBT transcription that stood
 * here. The candidate was written 2026-08-21, taken to 3 differences, DELETED
 * in 4eb106d when a port replaced the function, and recovered from git on
 * 2026-09-08; the last three differences closed the same day.
 *
 * The recipe is in the PARKED.txt entry: `g`/`q`/`h`/`tb` as locals inside the
 * guard, `goto again;` back into the middle of the body, `idx = e[0x17];` as
 * the body's first statement, `c66`/`n` named, plus `D_8009B424_IS_VOLATILE`
 * (see below) and `D_8009B146_SIZED` with `as -G4`.
 *
 * THE LAST THREE: retail emits `lhu $a2,6($s1)` BEFORE `sw $zero,D_8009B424`
 * and we emitted it after. All 24 orderings of the three argument loads and
 * the store were measured and none moves it, because the two are provably
 * disjoint -- a gp-relative scalar against a constant scratchpad address --
 * so gcc is free to order them however its priority computation lands.
 *
 * What closes it: **a volatile access is ordered only against OTHER volatile
 * accesses.** Marking the load alone is 3. Marking the store alone is 3.
 * Marking the `u4` load and the store is 3. Marking THE LOAD THAT MOVES and
 * THE STORE together is a MATCH. That is the whole mechanism, and it is why
 * every single-sided attempt in this park's history read as "volatile does
 * not help here" -- each one was measured alone.
 *
 * Written as the declaration rather than an lvalue cast: `D_8009B424` takes
 * its `_IS_VOLATILE` arm (the guard already existed, added for another
 * function) and the scratchpad read is `*(volatile u16 *)(q + 6)`. 0x1F800320
 * is PSX scratchpad RAM, so a volatile read of it is what the original would
 * have written. `*(volatile s32 *)&D_8009B424 = 0;` with the scalar arm is
 * the same MATCH; the guard is the honest spelling.
 */
#define D_8009B146_SIZED
#define D_8009B424_IS_VOLATILE
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
                    u6 = *(volatile u16 *)(q + 6);
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
