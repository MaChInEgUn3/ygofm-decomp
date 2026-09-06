/* 286/286 and 91 truly-different instructions (2026-09-06, first pass; the
 * positional count reads 238 because ours orders the copy loops differently
 * and the diff has no alignment pass). gp=35, at=0, default flags; sweep_try
 * flat, and both scheduler flags are worse (+3 and +1).
 * Shape that got it to exact length, in the order the levers landed:
 *   - the dispatch is a `switch` on the mode byte with cases 1, 2, 3 -- an
 *     if/else chain on the same values is -7. gcc reuses the register that
 *     holds `arg0 & 0xFF` as the constant 1 for case 1's test, which is why
 *     retail's tree reads `beq $v1,$a1`;
 *   - D_8009AF18 written INLINE at almost every use (a `p` local reassigned
 *     per block costs a sixth saved register: -5 and a whole $s2 row);
 *   - `t = *q;` as the copy loops' first statement (+2, the leading nop);
 *   - case 2 needs its OWN name for the unk28 countdown, or gcc cross-jumps
 *     its `bgtz`/`sw` into case 3's and the two arms lose four instructions;
 *   - case 1's join reads the record BEFORE bumping D_8009B0F8 (one nop);
 *   - case 2's `x = p->unk30; y = p->unk32;` named and stored back through
 *     the SYMBOL, not through a base local: the local is -3 (both spellings
 *     of the local, z1 and z2, are 283).
 * Residue, and it is one fault cascading: retail masks into $a1 and loads the
 * record into $a0; we mask into $a0 and load into $a1, and every argument
 * register downstream rotates. Measured and worth nothing on that axis (all
 * exactly 238): the mask as a named local before or after the counter, a `u8`
 * local for it, `a = arg0;` then the mask, the record read before the
 * counter, a `z = 1;` pseudo before the mask (four placements), reading the
 * mode straight off the symbol, and both `+= 1` spellings of the two
 * counters. A `u8 arg0` parameter does not compile against functions.h.
 * The second residue is the copy loops' schedule: retail runs
 * nop/lw *q/sll/lw base/i++ and we run sll/i++/lw *q/lw base/nop. Six body
 * orders measured (q++ moved, the address grouped base-first, a named
 * destination pointer -- that one is -1 and 187, the record used directly
 * instead of through a copy -- +2). Note the prototype change this needed:
 * func_80013C28 takes the DMA channel word in $a0, and func_8007DD50's
 * parameter had to lose its `(void)` so the registration still compiles;
 * func_800140A0 re-measured and still MATCHes. */
#include "common.h"

extern u8 *D_8009AF18;
extern s32 *D_8009B0F8;

void func_8007E3D0(s32 *arg0, s32 arg1, s32 arg2);
void func_8007DDD4(void);
void func_80077150(s32 *arg0, s32 arg1);
void func_800771B0(s32 arg0);
s32 func_80081DE8(u8 *arg0, s32 *arg1);

void func_80013C28(s32 arg0) {
    u8 *p;
    u8 *e;
    u8 *g;
    s32 *d;
    s32 *q;
    s32 *b;
    s32 i;
    s32 n;
    s32 c;
    s32 t;
    s32 m;
    s32 x;
    s32 y;
    s32 n2;

    D_8009B114 += 1;
    if ((arg0 & 0xFF) == 1) {
        D_8009B138 += 1;
        p = D_8009AF18;
        switch (p[0x46]) {
        case 1:
            if ((D_8009B0F4 & 0x200000) == 0) {
                i = 0;
                if ((D_8009B0F4 & 0x40000000) == 0) {
                    func_8007E3D0(*(s32 **)(p + 8), 0x200, 0);
                } else {
                    e = p;
                    q = D_8009B0F8;
                    do {
                        t = *q;
                        *(s32 *)(i * 4 + *(s32 *)(e + 8)) = t;
                        i++;
                        q++;
                    } while (i < 0x200);
                }
                *(s32 *)(D_8009AF18 + 8) = *(s32 *)(D_8009AF18 + 8) + 0x800;
            }
            n = *(s32 *)(D_8009AF18 + 0x10) - 0x800;
            D_8009B0F8 += 0x200;
            *(s32 *)(D_8009AF18 + 0x10) = n;
            if (n <= 0) {
                func_8007DDD4();
                func_8007E860((void (*)(void))0);
            }
            e = D_8009AF18;
            n = *(s32 *)(e + 0x28) - 0x800;
            *(s32 *)(e + 0x28) = n;
            if (n <= 0) {
                *(s32 *)(e + 0x1C) = 0;
                if (*(s32 *)(e + 0x20) != 0) {
                    c = *(s32 *)(e + 0x40);
                    *(s32 *)(e + 0x40) = c + 1;
                    (*(void (**)(u8 *, s32))(e + 0x20))(e, c);
                }
                *(s32 *)(e + 0x28) = *(s32 *)(e + 0x1C);
            }
            if (*(s32 *)(D_8009AF18 + 0x10) <= 0) {
                goto clear;
            }
            return;
        case 2:
            b = *(s32 **)(p + (*(u16 *)(p + 0x44) & 1) * 4 + 8);
            i = 0;
            if ((D_8009B0F4 & 0x40000000) == 0) {
                func_8007E3D0(b, 0x200, 0);
            } else {
                d = b;
                q = D_8009B0F8;
                do {
                    t = *q;
                    q++;
                    i++;
                    *d = t;
                    d++;
                } while (i < 0x200);
                D_8009B0F8 += 0x200;
            }
            n2 = *(s32 *)(D_8009AF18 + 0x10) - 0x800;
            *(s32 *)(D_8009AF18 + 0x10) = n2;
            if (n2 <= 0) {
                func_8007DDD4();
                func_8007E860((void (*)(void))0);
            }
            x = *(u16 *)(D_8009AF18 + 0x30);
            y = *(u16 *)(D_8009AF18 + 0x32);
            *(s16 *)D_8009AF18 = x;
            *(s16 *)(D_8009AF18 + 2) = y;
            while (func_80081DE8(D_8009AF18, b) != 0) {
            }
            if (D_8009B0F4 & 0x20000) {
                *(s16 *)(D_8009AF18 + 0x30) = *(u16 *)(D_8009AF18 + 0x30) + 0x40;
            } else {
                g = D_8009AF18;
                t = *(u16 *)(g + 0x32) + 0x10;
                *(s16 *)(g + 0x32) = t;
                if ((t & 0xFF) == 0) {
                    *(s16 *)(g + 0x32) = (t ^ 0x100) & 0x100;
                    *(s16 *)(g + 0x30) = *(u16 *)(g + 0x30) + 0x40;
                }
            }
            e = D_8009AF18;
            n2 = *(s32 *)(e + 0x28) - 0x800;
            *(s32 *)(e + 0x28) = n2;
            if (n2 <= 0) {
                *(s32 *)(e + 0x1C) = 0;
                if (*(s32 *)(e + 0x20) != 0) {
                    c = *(s32 *)(e + 0x40);
                    *(s32 *)(e + 0x40) = c + 1;
                    (*(void (**)(u8 *, s32))(e + 0x20))(e, c);
                }
                *(s32 *)(e + 0x28) = *(s32 *)(e + 0x1C);
            }
            break;
        case 3:
            m = 0x800;
            n = *(s32 *)(p + 0x28);
            b = *(s32 **)(p + 8);
            if (n < m) {
                m = n;
            }
            i = 0;
            if ((D_8009B0F4 & 0x40000000) == 0) {
                func_8007E3D0(b, m / 4, 0);
            } else {
                d = b;
                q = D_8009B0F8;
                while (i < m / 4) {
                    i++;
                    t = *q;
                    q++;
                    *d = t;
                    d++;
                }
                D_8009B0F8 = (s32 *)((s32)D_8009B0F8 + m);
            }
            n = *(s32 *)(D_8009AF18 + 0x10) - 0x800;
            *(s32 *)(D_8009AF18 + 0x10) = n;
            if (n <= 0) {
                func_8007DDD4();
                func_8007E860((void (*)(void))0);
            }
            func_800771B0(*(s32 *)(D_8009AF18 + 0x30));
            func_80077150(b, m);
            e = D_8009AF18;
            n = *(s32 *)(e + 0x28) - 0x800;
            *(s32 *)(e + 0x30) = *(s32 *)(e + 0x30) + m;
            *(s32 *)(e + 0x28) = n;
            if (n <= 0) {
                *(s32 *)(e + 0x1C) = 0;
                if (*(s32 *)(e + 0x20) != 0) {
                    c = *(s32 *)(e + 0x40);
                    *(s32 *)(e + 0x40) = c + 1;
                    (*(void (**)(u8 *, s32))(e + 0x20))(e, c);
                }
                *(s32 *)(e + 0x28) = *(s32 *)(e + 0x1C);
            }
            break;
        }
        g = D_8009AF18;
        t = *(u16 *)(g + 0x44) + 1;
        n = *(s32 *)(g + 0x10);
        *(u16 *)(g + 0x44) = t;
        if (n <= 0) {
clear:
            D_8009B0F4 &= ~0x100;
        }
    }
}
