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

/* 0/192, -G8 -msplit-addresses. Duel-round overlay-object build/teardown:
   toggle on D_8009B27C & 0x4000 -- clear it and build three D_800EFE48
   slots plus a display object, or set it and tear the same things down.
   Same slot idiom as func_800323F8's tail (find_free_slot ->
   get_or_init -> configure -> func_800428EC -> store).
   (w4 first sketch 2026-08-29; w1 landed 2026-08-30.)

   Levers that mattered, in the order they closed the residual:

   1. `D_800EAE98` is a fixed RECORD at that address with pointer-sized
      fields at +0x0/+0x14/+0x28, not an array of live pointers to
      dereference -- `*(s32 *) ((u8 *) D_800EAE98 + 0x14) = slot;`, never
      `D_800EAE98[0]` re-func_800738F0 as a value (that extra `lw` was the entire
      register-rotation residual a prior pass had filed as unrelated).
   2. PER-OBJECT -G, PER-SYMBOL SWEPT: the ROM reaches D_8009B27C/280/
      290/29C/2A0 off $gp (-G8 unit) but reaches D_8009B0F4, D_8009B134,
      D_800EAE98, D_801AF000, D_800E9ECF via absolute lui/lw pairs, so all
      five must stay oversized/unsized -- sizing any one fails to link
      ("small-data section too large") or mis-addresses once (1) is fixed.
   3. TWO REGISTER-ROLE TIES closed with GA-3-style register variables,
      writing each operation's result into the ROM's own register in
      place (`t0F4 &= mask0F4; t0F4 |= t134;`, not one combined
      expression) rather than a launder.
   4. TWO SCHEDULING TIES (right content/count, wrong position) closed
      with a bare `__asm__ volatile ("")` barrier each: one between the
      two self-referencing lui/lw pairs (D_8009B0F4 vs D_8009B134,
      forcing the ROM's "finish one before starting the next" instead of
      gcc's "group both luis, then both loads"), one between the
      obj+0x30/0x38 stores and the f4val = *(obj+4) func_800738F0.
   5. THE SHARED 0xFFFFFF CONSTANT's `lui v1,0xff` half sits BEFORE the
      obj+0x30/0x38 stores in the ROM; its `ori v1,v1,0xffff` half doesn't
      land until first use, well after them. A single `ffMask = 0xFFFFFF;`
      at the use site lets gcc schedule both halves together there
      (SCHED-1: an undivided constant load can't split itself). Splitting
      the C-level build into a hard-register initialiser at the position
      the lui belongs (`register s32 ffMask asm("v1") = 0xFF0000;` -- low
      16 bits already zero, so this alone emits `lui v1,0xff`) plus a
      LAUNDER right after it reproduces the split; the initialiser ALONE
      was not enough, gcc deferred materialisation to first use regardless
      of declaration position until the launder pinned it in place.
      `ffMask |= 0xFFFF;` at the original use site supplies the `ori`.

   Uncarved before this landing (no asm/nonmatchings dir, no src stub),
   extent clean at 0x8002F630..0x8002F930, next F is a separate 7-insn
   function -- no --exclude needed. */

extern u16 D_8009B27C;
extern u8 *D_8009B280;
extern u8 *D_8009B290;
extern u16 D_8009B29C;
extern u8 *D_8009B2A0;
/* PER-OBJECT -G: the ROM reaches D_8009B27C/280/290/29C/2A0 off $gp (so the
   unit is -G8) but reaches these five with absolute lui/lw pairs, so they
   must NOT be in small data.  Declared oversized to keep them out -- at -G8
   the scalar forms both mis-address AND overflow .sdata, so the link fails
   outright.  Same lever as func_800323F8's D_8009B146/148. */
extern s32 D_8009B0F4[8];
extern s32 D_8009B134[8];
extern u8 *D_800EAE98[8];
extern u8 D_801AF000[];
extern u8 D_800E9ECF[16];

extern void func_8002F4C0(void);
extern s32 func_8002E3B4(void);
extern void func_8002E00C(u8 **slotp);
extern void func_80014E1C(s32 a0, s32 a1, s32 a2, s32 a3,
                          void (*a4)(void), s32 a5, s32 a6);
extern void func_800137E4(void);
extern void func_80015B00(void);
extern void func_80040510(u8 *s, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5,
                          s32 a6, s32 a7, s32 a8, s32 a9);
extern s32 func_8004002C(void);
extern u8 *func_800400AC(s32 idx, s32 kind);
extern void func_800428A8(u8 *s, s32 a1, s32 a2, s32 a3, s32 a4,
                                  s32 a5, s32 a6, s32 a7, u8 *a8);
extern void func_800428EC(u8 *s, s32 n);
extern void func_800427DC(u8 *s, s32 n);
extern void func_800157DC(void);
extern void func_80015998(void);
extern s32 func_8004703C(void);
extern void func_8004036C(u8 *p);

void func_8002F630(void) {
    u8 *slot;
    u8 *obj;
    u8 *src;
    s32 flags;

    if (func_8002E3B4() == 0) {
        src = D_8009B290;
        D_8009B290 = src + 2;
        D_8009B29C = (u16) (src[0] | (src[1] << 8));
        func_80014E1C(0, 0, 0x1FA7, 0x32, func_8002F4C0, 0, 0);
        func_800137E4();
    }

    flags = D_8009B27C;
    /* The ROM opens `andi $v0,$a1,0x4000 / bnez .L8002F8B4`, so the
       FALL-THROUGH is the !(flags & 0x4000) BUILD path and that body belongs
       FIRST in the source; the teardown is the tail block.  Written the other
       way round (if (flags & 0x4000) { teardown } ... ) gcc inverts the
       branch and lays the teardown inline: 153/192, first divergence 0x88. */
    if (!(flags & 0x4000)) {
        {
            register s32 mask0F4 asm("v0") = 0x2000030;
            register s32 t0F4 asm("v1");
            register s32 t134 asm("a0");
            t0F4 = D_8009B0F4[0];
            __asm__ volatile ("");
            t134 = D_8009B134[0];
            t0F4 &= mask0F4;
            t0F4 |= t134;
            if (t0F4 != 0) {
                return;
            }
        }
        D_8009B27C = (u16) (flags | 0x4000);
        if (D_8009B2A0 != 0) {
            *(u16 *) (D_8009B2A0 + 8) &= 0xFFBF;
        }
        func_8002E00C(D_800EAE98);

        slot = func_800400AC(func_8004002C(), 2);
        func_800428A8(slot, 0, 0, 0, 0, 0, 0x17, 4, D_801AF000);
        func_800428EC(slot, 1);
        *(u16 *) (slot + 8) |= 0x28;
        *(s32 *) (slot + 4) |= 0x1000000;
        D_800EAE98[0] = slot;

        slot = func_800400AC(func_8004002C(), 1);
        func_80040510(slot, 0, 0, 0x140, 0xF0, 0, 0, 0x19, 0, 0xF5);
        func_800428EC(slot, -1);
        *(s32 *) ((u8 *) D_800EAE98 + 0x14) = (s32) slot;

        slot = func_800400AC(func_8004002C(), 1);
        func_80040510(slot, 0x100, 0, 0x40, 0xF0, 0, 0, 0x19, 0, 0xF5);
        func_800428EC(slot, -1);
        *(s32 *) ((u8 *) D_800EAE98 + 0x28) = (s32) slot;

        obj = func_800400AC(func_8004002C(), 4);
        func_800427DC(obj, 0);
        {
            register s32 f4val asm("v0");
            register s32 f140 asm("a0") = 0xF00140;
            register s32 ffMask asm("v1") = 0xFF0000;
            __asm__ volatile ("" : "+r"(ffMask));
            *(s32 *) (obj + 0x30) = 0x140;
            *(s32 *) (obj + 0x38) = 0xF00000;
            __asm__ volatile ("");
            f4val = *(s32 *) (obj + 4);
            ffMask |= 0xFFFF;
            *(s32 *) (obj + 0x3C) = ffMask;
            *(s32 *) (obj + 0x44) = ffMask;
            *(s32 *) (obj + 0x28) = 0;
            ffMask = 0x60000000;
            *(s32 *) (obj + 0x40) = f140;
            D_8009B280 = obj;
            f4val |= ffMask;
            *(s32 *) (obj + 4) = f4val;
        }
        func_800157DC();
        D_800E9ECF[0] = 4;
        func_80015998();
        return;
    }

    if (func_8004703C() & 0x80) {
        return;
    }
    func_80015B00();
    if (D_8009B2A0 != 0) {
        *(u16 *) (D_8009B2A0 + 8) |= 0x40;
    }
    func_8004036C(D_8009B280);
    func_8002E00C(D_800EAE98);
    D_8009B27C = 0;
}
