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

/* Guardian-star advantage between two monsters, in ATK/DEF points.

   Each card's stats word D_801D4244[card_id - 1] packs two 4-bit guardian
   star ids: bits 22-25 (star 1) and bits 18-21 (star 2).  The monster
   instance's flag word f16 bit 0x200 records which of its two stars the
   player selected at summon time, so this picks that star for each side and
   hands the pair to func_8002CB80 -- the guardian-star wheel, which returns
   +500 / -500 / 0 (it splits ids 1-6 into a 6-star cycle and 7-10 into a
   4-star cycle, and returns 0 across the two cycles).

   NOTE for whoever owns naming: src/calc_wrap_scroll_delta.c is
   func_8002CB80 under a "menu/list scroll helper" label, and that reading
   looks wrong -- its 6/4 wraps are the two guardian-star wheels and its
   +/-500 is the standard guardian-star ATK modifier, not a scroll delta.
   Bytes are unaffected either way; only the name and comment are.

   A null second operand short-circuits to 0 (no comparison to make). */

struct Obj {
    char pad0[0xC];
    s16 fC;     /* 0xC: card id, 1-based index into D_801D4244 */
    char padE[0x16 - 0xE];
    u16 f16;    /* 0x16: instance flags; 0x200 selects star 2 over star 1 */
};

extern s32 D_801D4244[];
extern s32 func_8002CB80(s32 a0, s32 a1);

s32 func_8001EE44(struct Obj *a, struct Obj *b) {
    s32 n0;
    s32 n1;

    if (b == 0) {
        return 0;
    }

    if (a->f16 & 0x200) {
        n0 = (D_801D4244[a->fC - 1] >> 18) & 0xF;
    } else {
        n0 = (D_801D4244[a->fC - 1] >> 22) & 0xF;
    }

    if (b->f16 & 0x200) {
        n1 = D_801D4244[b->fC - 1] >> 18;
    } else {
        n1 = D_801D4244[b->fC - 1] >> 22;
    }
    n1 = n1 & 0xF;

    return func_8002CB80(n0, n1);
}
