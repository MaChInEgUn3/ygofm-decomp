/* 131 differing at 280/280 (2026-09-06, first pass, never parked before).
 * gp=36, at=3: the three byte flags at the end take their _IN_DATA arms;
 * D_8009B260 too (bare lbu). Block 1 (the 0x8000 init) is the residue that
 * matters: retail's preheader is `i = 0`, then the four loop invariants
 * (D_8015C424, D_80090918, func_8001EC70 as a pair-plus-copy, D_800E9EF0)
 * hoisted to the TOP of the block by sched1, then the flag store and the two
 * record set-ups, with the cursor's `la D_800EA030` LEFT IN PLACE between
 * the two records. Ours moves that la to the top with the rest. Measured
 * and worthless for it: the cursor assigned at the top / between the records
 * / right before the loop / as `(u8 *)D_800EA030 + i * 12`; index form
 * D_800EA030[i] (i then eliminated by the giv, -1); while/for spellings; a
 * do { } while (0) round the block, round the setup only, round everything
 * but i = 0; -fno-schedule-insns (+6, worse everywhere); a goto loop keeps
 * the la in place but then nothing hoists and the handler address is
 * re-materialised per iteration (+3). Source-level base locals (b, tb, eb)
 * land where the hoisted ones do, but a local for the handler address is
 * REG_EQUIV-propagated away (or its init moved to the first use), and the
 * pair-plus-copy shape only comes from loop hoisting + cse2. The two
 * pre-loop records and the loop share ONE record name (`a`), and the loop
 * constants 0x48000 / 0xB4 / 1 stay unhoisted only when written against
 * reused names (`y`, `k`). Tail: the 0x13 arm wants `n = D_8009B1B9` and
 * `w = p->unk14` named BEFORE the halfword store (retail hoists both), the
 * >= 5 arm wants `w` read after the two halfword stores but retail keeps
 * the lw after them where ours hoists it (struct-member spellings of either
 * side change nothing: sA/sB/sC all 131), same in the < 5 arm. */
#define D_8009B260_IN_DATA
#define D_8009B369_IN_DATA
#define D_8009B269_IN_DATA
#define D_8009B26C_IN_DATA
#define D_800E9EF0_IS_PTR_VOLATILE
#include "common.h"

extern u8 *D_8009B21C;
extern u8 D_80090918[];

void func_8001EC70(void);
void func_800156DC(void);
void func_80015C84(void);
s32 func_8008E590(void);
void func_80059C18(s32 arg0);
void func_8003FF88(s32 arg0);
s32 func_80042B40(s32 arg0);

void func_80018FEC(void) {
    s32 f;
    s32 i;
    u8 *p;
    u8 *q;
    u8 *g;
    u8 *b;
    s32 y;
    s32 n;
    u8 d;
    s32 o;
    s32 k;
    u8 *a;
    u8 *r;
    s32 w;
    s32 m;
    Rec20 *e2;
    s32 x;

    f = D_8009B23A;
    if ((f & 0x8000) == 0) {
        i = 0;
        D_8009B23A = f | 0x8000;
        D_8009B1B4 = D_800E9F10 + D_8009B1D5 * 0x70;
        a = D_8009B214;
        *(s16 *)(a + 0x28) = -0x40;
        *(s16 *)(a + 0x2C) = 0x10;
        a[0x6C] = 1;
        *(void (**)(void))(a + 0x24) = func_8001EC70;
        *(u16 *)(a + 0x2A) = *(u16 *)(a + 0x32);
        a = D_8009B21C;
        *(s16 *)(a + 0x28) = 0x180;
        *(s16 *)(a + 0x2C) = 0x10;
        a[0x6C] = 1;
        *(void (**)(void))(a + 0x24) = func_8001EC70;
        *(u16 *)(a + 0x2A) = *(u16 *)(a + 0x32);
        do {
            a = D_800EA030[i].unk0;
            y = 0x48000;
            b = D_8015C424;
            g = b + a[0x6A] * 28 + y;
            q = D_80090918 + (*(s16 *)(g + 0x36C0) - 0x11) * 3;
            *(s16 *)(a + 0x28) = q[1] - 0x1A;
            y = q[2];
            k = 0xB4;
            *(s16 *)(a + 0x2C) = k;
            k = 1;
            a[0x6C] = k;
            *(void (**)(void))(a + 0x24) = func_8001EC70;
            y = y - 0x1E;
            *(s16 *)(a + 0x2A) = y;
            i++;
            D_800E9EF0[q[0]] = a;
            D_800EA030[i].unk0 = (u8 *)0;
        } while (i < 5);
        D_800E9EF0[i] = (u8 *)0;
        func_8004036C(*(s32 *)(D_8009B1B4 + 4));
        D_8009B162 = 8;
        D_8009B1D0 = 0;
        D_8009B1B9 = 0;
        D_8009B17C = (u8 *)0;
        D_8009B23A |= 0x4000;
        func_80015C84();
        o = 2;
        k = o;
        D_800E9ECF[0] = k;
        func_8003FF58(o);
        return;
    }
    if (f & 0x4000) {
        if (f & 0x2000) {
            if ((D_8009B260 & 1) == 0) {
                D_8009B23A = f & 0xBFFF;
                D_8009B1B9 = 0;
                D_8009B1D0 = 0;
            }
        } else {
            r = D_8009B17C;
            if (r != 0) {
                if (r[0x1D] == 0) {
                    return;
                }
                func_8003FEE0(0x1D);
                if (func_80042B40(1) == 0) {
                    D_8009B23A |= 0x2000;
                    return;
                }
            }
            p = func_8002C604(0x13);
            D_8009B17C = p;
            *(s16 *)p = (func_8008E590() & 0xFF) + 0x20;
            x = func_800358FC(0xB0);
            n = D_8009B1B9;
            w = *(s32 *)(p + 0x14);
            *(s16 *)(p + 2) = x + 0x20;
            *(s32 *)(p + 0x14) = w + ((n & 3) << 13);
            n = n + 1;
            D_8009B1B9 = n;
        }
    } else if (f & 0x2000) {
        D_8009B1D0 = D_8009B1D0 - 1;
        if ((s16)D_8009B1D0 > 0) {
            return;
        }
        if ((s8)D_8009B1B9 >= 5) {
            D_8009B23A = (f & 0xDFFF) | 0x1000;
            p = func_8002C604(0x13);
            *(s16 *)p = 0xA0;
            *(s16 *)(p + 2) = 0x78;
            w = *(s32 *)(p + 0x14);
            D_8009B17C = p;
            *(s32 *)(p + 0x14) = w + 0x8000;
        } else {
            D_8009B1D0 = 4;
            p = func_8002C604(0);
            n = (s8)D_8009B1B9;
            q = D_800E9EF0[n];
            m = (n << 12) + 0xA000;
            *(s16 *)p = *(u16 *)(q + 0x30) + 0x1A;
            *(s32 *)(p + 0x14) += m;
            *(s16 *)(p + 0x1A) = 9;
            *(s16 *)(p + 2) = *(u16 *)(D_800E9EF0[n] + 0x32) + 0x1E;
            func_8003FEE0(0x17);
            D_8009B1B9 += 1;
        }
    } else if (f & 0x1000) {
        if (D_8009B17C[0x1D] != 0) {
            D_8009B23A = f & 0xEFFF;
            func_8003FEE0(0x1D);
            func_8002C68C(0x18);
            func_8003FF88(0x8021);
        }
    } else {
        func_800156DC();
        *(u16 *)D_800EF658 = 0x309;
        d = D_8009B1D5;
        D_800E9FF0[d].unk0[0] = 0x28;
        D_8009B165 = d;
        e2 = &D_800E9FF0[D_8009B1D5 ^ 1];
        e2->unk14 = 0;
        *(s16 *)&e2->unk0[0x12] = 0;
        func_800472A8(0x7310);
        func_80059C18(0x7310);
        o = 1;
        D_8009B369 = o;
        D_8009B269 = 3;
        D_8009B26C = o;
    }
}
