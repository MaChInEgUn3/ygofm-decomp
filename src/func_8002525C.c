/* PORTED from Unchiga's decompilation of SLUS_014.11, shared 2026-08-30.
 * His C, his comments; the identifiers are rewritten to this repo's address
 * form and nothing else was touched. Verified the only way that counts here:
 * tools_src/build.py rebuilds the retail image byte-for-byte with this in it.
 *
 * Self-contained by design -- it keeps his declarations rather than ours,
 * because a declaration is a codegen input and his are what this C matched
 * under. See docs/MERGE_UNCHIGA.md and tools_src/install_ported.py.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef int s32;

/* func_8002525C (0x8002525C, 76 words).
 *
 * Player-widget timer decrement / event fire.  Three entry paths off the
 * D_8009B220 flag word: no duel running -> build a kind-6 Obj and fire event
 * 0x1C; bit 0x40 clear with D_8009B22A idle -> decrement the OTHER player's
 * widget (index ^ 1); bit 0x20 set -> ask func_8001F364 and, when it declines,
 * clear 0x20 and build a kind-7 Obj instead; bit 0x20 clear -> decrement THIS
 * player's widget.  The decrement itself is shared: field14 -= D_8009AF38[s0]
 * * 10, clamped at 0, then the whole flag word is cleared.
 *
 * EXTENT.  0x8002525C, not 0x80025260: the `lh v0,714(gp)` that computes
 * s0 = D_8009B1D2 - 0x157 sits one instruction BEFORE the prologue, and the
 * `addiu s0,v0,-343` that finishes it is the delay slot of the first jal --
 * so it must be func_800738F0 pre-call.  config/function_ranges.txt already carries the
 * corrected single entry (F 8002525C R 130).
 *
 * Reclaimed from config/blacklist.txt.  The banked entry func_800738F0 30/76 and its
 * own sketch header listed FIVE levers as measured-and-dead, two of which are
 * in the match.  Every one of those negatives was taken on a base that still
 * had the block-order bug below, and re-measuring them after the base was
 * fixed is the entire story:
 *
 *  1. THE `flags & 0x20` ARMS WERE THE WRONG WAY ROUND, worth 24.  The ROM's
 *     `beqz v0,0x80025330` makes the func_8001F364 path the FALL-THROUGH.
 *     Neither `if (!(flag & 0x20)) { <decrement> }` nor the if/else with the
 *     call path as the `then` arm expresses that -- gcc re-inverts both.  A
 *     bare forward `goto setup_b` to a label placed AFTER the function's own
 *     tail and `return` is the only spelling that holds; the SOURCE's physical
 *     block order is what decides it.
 *
 *  2. `flag` MUST BE s32, NOT u16, worth 1.  As a u16 it reaches
 *     func_8001F364 through an `andi a0,a0,0xffff`; the ROM's jal delay slot
 *     there is a plain `nop`.
 *
 *  3. `register u8 *base asm("v0")`.  Banked as a REGRESSION (8/76 vs 6/76)
 *     with a -dg conflict-set analysis explaining why: a hard-register local
 *     is live function-wide, so pinned `base` blocked $v0's reuse for the
 *     D_8009AF38 address.  True, and irrelevant -- that reuse is restored by
 *     fixes 4 and 5, and with them the pin is required.
 *
 *  4. AT `setup_b`, LOAD `idx` BEFORE `base`.  The ROM fills the `lbu v1`
 *     load-delay slot with the `addiu v0,v0,-24592` that finishes base's
 *     address; writing base first leaves a `nop` there instead.
 *
 *  5. AN EMPTY `"+r"` LAUNDER ON `rec`, worth the last 2.  Banked as
 *     26/76-at-77w ("the launder itself costs the word") -- again true only
 *     on the old base.  Without it gcc SINKS the `addu` that forms rec past
 *     the D_8009AF38 chain to fill that chain's own load-delay slot, which
 *     both moves the addu and lets the chain take $v1 instead of the $v0 the
 *     ROM frees by killing base at the addu.  The launder pins rec where it
 *     is computed and the ROM's `nop` at 0x8002534C comes back.
 *
 *  6. `(u32) base` IN THE SUM, worth the last 1.  All six pointer spellings
 *     of `base + idx * 0x20` emit `addu a0,v0,v1`; casting base to an integer
 *     changes the operand rank and gives the ROM's `addu a0,v1,v0`.
 *
 * The sketch's third banked fix -- two alias spellings of D_800E9FF0, one per
 * goto site -- is NOT needed and is not used here: with 4/5/6 in place the
 * single symbol is 0/76, so this unit adds no symbol to the link.
 *
 * -G8 -msplit-addresses (the other three combos are 59/85/87).
 * Derivation in match/sketches/func_8002525C.c.
 */

struct WidgetEntry {
    u8 pad0[0x12];
    s16 field12;
    s16 field14;
    u8 pad1[0x18 - 0x16];
    s8 field18;
    u8 pad2[0x20 - 0x19];
};

struct Obj {
    s16 field0;
    s16 field2;
    u8 pad[0x1A - 4];
    s16 field1A;
};

extern s16 D_8009B1D2;
extern u16 D_8009B220;
extern u16 D_8009B210;
extern s16 D_8009B22A;
extern u8 D_8009B1D5;
extern u8 D_8009AF38[4];
extern struct WidgetEntry D_800E9FF0[2];

extern s32 func_80024E24(void);
extern s32 func_80025028(s32);
extern struct Obj *func_8002C68C(s32);
extern s32 func_8001F364(s32);
extern void func_8003FEE0(s32);

void func_8002525C(void) {
    s32 s0;
    s32 flag;
    s32 idx;
    register u8 *base asm("v0");
    struct WidgetEntry *rec;
    struct Obj *obj;
    s32 delta;
    s16 v1;

    s0 = D_8009B1D2 - 0x157;
    if (func_80024E24() == 0) {
        if (func_80025028(0x2AF) != 0) {
            s0 = 5;
        }
        obj = func_8002C68C(6);
    } else {
        flag = D_8009B220;
        if (!(flag & 0x40)) {
            D_8009B220 = flag | 0x60;
            if (D_8009B22A == 0) {
                base = (u8 *) D_800E9FF0;
                idx = D_8009B1D5 ^ 1;
                goto decrement;
            }
            D_8009B210 = 0;
        }
        if (!(D_8009B220 & 0x20)) {
            goto setup_b;
        }
        if (func_8001F364(flag) != 0) {
            return;
        }
        D_8009B220 &= 0xFFDF;
        obj = func_8002C68C(7);
    }
    obj->field0 = 0xA0;
    obj->field2 = 0x78;
    obj->field1A = (s16) s0;
    func_8003FEE0(0x1C);
    return;

setup_b:
    idx = D_8009B1D5;
    base = (u8 *) D_800E9FF0;

decrement:
    rec = (struct WidgetEntry *) (idx * 0x20 + (u32) base);
    __asm__ volatile("" : "+r" (rec));
    delta = D_8009AF38[s0] * 10;
    v1 = rec->field14 - delta;
    rec->field14 = v1;
    if (v1 < 0) {
        rec->field14 = 0;
    }
    D_8009B220 = 0;
}
