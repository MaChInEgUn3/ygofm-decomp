/* 2 differing at 112/112 (2026-09-05, was 11) under default -O2 -G8 with the assembler at -G0
 * (PER_FUNC_AS_FLAGS), 2026-09-05. PURE C; src/ holds a transcription with
 * asm reloads, register pins and scheduling fences.
 *
 * Was +2 at 114/112 and 99 with an extra callee-saved register: gcc hoisted
 * the literal 0x63 out of the call-bearing loop into $s6. THE LEVER IS THE
 * LOOP FORM: loop 2 written as a `goto` loop (label at the top, `if (i < n)
 * goto top2;` at the bottom) carries no NOTE_INSN_LOOP_BEG/END, so gcc 2.8's
 * loop pass never sees it and never hoists the invariant. +2/99 -> 0/51 on
 * that alone. `while (1)` with a `break` still has the notes and is still +2.
 * Then, in order:
 *   51 -> 51  loop-3 constants as literals: two `addiu 127` instead of a copy
 *   51 -> 27  ONE POINTER NAME PER LOOP (r1, r3): one `r` across three loops
 *             is a global-alloc pseudo that cannot take the base's dying $v0
 *   27 -> 20  loop 2's cursor is `base` itself (`base = base + off;` and the
 *             bottom `base = D_8009B458;` reload), no second name
 *   20 -> 17  `tbl++; off += 0x28;` AFTER the func_80076ED0 call
 *   17 -> 16  loop-3 constants named with their store widths (u8 b40, u8
 *             b7f, s32 w7f) assigned before `o18 = i;`
 *   16 -> 11  default -G8 / as -G0: D_80011434 as cc1psx's own pair via $v0
 * The 11 are two allocation faults: mask and k40 exchanged ($s4/$s5) at nine
 * sites, and `addu $a0,$s1` (the call argument) scheduled after the address
 * add instead of before it. Dead at 11: `i = 0` for `i = mask`, a shared
 * zero name, k40 assigned first / used for a third store (-1 length), the
 * argument named at the top of the body, `key = *tbl` first, base[0] first.
 *
 *   11 ->  2  `do { } while (0);` round loop 2's whole guarded block (the
 *             base load, the `if (count > 0)`, the goto loop). The permuter
 *             found it as a pin round the entire middle of the function;
 *             decomposed, loop 2's block alone is the whole effect (loop 1
 *             alone 11, loop 3's preheader alone 11, loops 1+2 2). It fixes
 *             mask/k40's $s4/$s5 at all nine sites -- a register-allocation
 *             use of the idiom, the func_8005F3B8 class.
 * The last 2 are `addu $a0,$s1` (the func_8004A764 argument) scheduled
 * after `base = base + off` where retail has it before. Dead at 2: the
 * argument named plain or pinned before the address (2, 2), `key = *tbl`
 * first (2), a pin round the address and the key read (7), a fresh cursor
 * name for the body (+2), the pin from `top2:` to the back edge only (+2,
 * 101 -- the first run of it printed nothing because a permuter was
 * restarting in the same second; re-measured with none running).
 */
#include "common.h"

void func_8004A518(void) {
    u8 *base;
    u8 *r1;
    u8 *r3;
    s32 mask;
    s32 i;
    s32 o1;
    s32 off;
    s32 *tbl;
    s32 key;
    s32 k40;
    s32 c72;
    s32 cff;
    s32 one;
    s32 o18;
    u8 b40;
    u8 b7f;
    s32 w7f;

    mask = 0;
    i = mask;
    c72 = 0x72;
    one = 1;
    cff = 0xFF;
    o1 = 0x518;
    base = D_8009B458;
    *(s16 *)(base + 0x512) = 0x7F;
    do {
        r1 = D_8009B458 + o1;
        i++;
        *(s32 *)(r1 + 0) = 0;
        *(s32 *)(r1 + 4) = 0;
        r1[0x26] = 0;
        *(s32 *)(r1 + 0x1C) = 0;
        *(s32 *)(r1 + 8) = 0;
        *(s32 *)(r1 + 0xC) = 0;
        *(s16 *)(r1 + 0x14) = c72;
        *(s16 *)(r1 + 0x16) = c72;
        r1[0x24] = one;
        *(s32 *)(r1 + 0x10) = 0;
        *(s16 *)(r1 + 0x18) = 0;
        r1[0x27] = 0;
        r1[0x28] = cff;
        r1[0x29] = 0;
        r1[0x2B] = 0;
        o1 += 0x2C;
    } while (i < 16);

    do {
    base = D_8009B458;
    if (*(s16 *)(base + 0x510) > 0) {
        i = 0;
        k40 = 0x40;
        tbl = D_80011434;
        off = 0x180;
    top2:
            base = base + off;
            key = *tbl;
            base[3] = 0x63;
            base[0] = i;
            base[0xD] = 0;
            base[0xF] = 0;
            base[0xC] = 0x40;
            *(s16 *)(base + 0x1A) = k40;
            *(s16 *)(base + 0x1C) = k40;
            *(s16 *)(base + 0x1E) = 0;
            func_8004A764(i);
            func_80076ED0(0, key);
            tbl++;
            off += 0x28;
            base = D_8009B458;
            i++;
            mask |= key;
        if (i < *(s16 *)(base + 0x510)) goto top2;
    }
    } while (0);

    i = 0;
    b40 = 0x40;
    b7f = 0x7F;
    w7f = 0x7F;
    o18 = i;
    do {
        r3 = D_8009B458 + o18;
        i++;
        r3[1] = b40;
        r3[3] = b7f;
        r3[4] = 0;
        r3[5] = b7f;
        r3[7] = b40;
        *(s32 *)(r3 + 8) = w7f;
        *(s32 *)(r3 + 0xC) = w7f;
        r3[0x10] = 0;
        *(s16 *)(r3 + 0x14) = 0;
        r3[6] = 0;
        o18 += 0x18;
    } while (i < 16);

    func_80076ED0(0, mask);
}
