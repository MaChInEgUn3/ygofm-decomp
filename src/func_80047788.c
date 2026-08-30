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

/* Boundary-bug chain: F-entries 0x80047788/0x800477FC/0x80047800 (true span
   0x80047788-0x80047864, 55 insns) -- carve with
   --exclude 0x800477FC 0x80047800.
   Shares the D_8009B45C BigState global with func_800471D0.c (which supplies
   this function's first callee's real prototype) and with the still-unmatched
   func_80045BE8 (leaf_tail_branch_group family; only its address is needed
   here).

   LANDED 0/55 (w1, 2026-08-29), G0:-mno-split-addresses, exact word count.
   Three levers, all load-bearing:

   1. asm volatile("" : "+r"(v0)); right after the rounding-divide if-block,
      before computing t0 = v0 >> 11 then t0 + 1 -- blocks gcc's delay-slot
      filler from duplicating the shift into the branch-taken path (target
      computes it once, post-merge).

   2. Hoisting the 0x801E6800 literal into a barriered local
      (s32 a1const = 0x801E6800; asm volatile("" : "+r"(a1const));) fixes the
      instruction-order swap between that literal's li and the idx*8
      computation. A bare named local WITHOUT the barrier regresses hard (adds
      a whole extra saved register and 8 bytes of frame).

   3. THE LAST WORD. Residual was a single commutative operand-order swap:
      target addu v1,s0,v1 vs candidate addu v1,v1,s0 in the elem-pointer
      computation. The fix is BOTH halves together -- put the index first AND
      cast the loaded pointer to s32 so the whole thing is integer addition:
          elem = (struct ArrElem *)(idx8 + (s32)D_8009B45C->f448);
      Neither half alone works: keeping pointer arithmetic and only swapping
      the operands (idx8 + (char *)...->f448) still emits addu v1,v1,s0,
      because gcc canonicalizes a POINTER + integer PLUS with the pointer as
      operand 0 regardless of source order; casting to s32 without swapping
      ((s32)...->f448 + idx8) likewise stays addu v1,v1,s0. Only integer +
      integer preserves the written operand order. This extends
      project_pointer_arith_beats_array_sugar_for_addu_order with the
      operand-ORDER case: to control which register lands in rs vs rt of an
      addu, take the expression out of pointer arithmetic entirely.
      The memory's own "isolate to a bare inline asm addu" lever was tried
      twice here (as a separate elemAddr local and writing directly into
      elem) and regressed to 39/55 both times -- do not reach for it when the
      base is itself a memory load inside the asm operand. */

struct S8009B45C {
    char pad0[0x2];
    u16 f2;
    char pad4[0x438 - 0x4];
    s32 f438;
    char pad43C[0x448 - 0x43C];
    void *f448;
};

struct ArrElem {
    u16 f0;
    char pad2[2];
    s32 f4;
};

/* type-0x51 variant of func_80045BE8's LocalBuf record. */
struct LocalBuf51 {
    u8 type;
    char pad1[0x4 - 0x1];
    s32 f4;
    char pad8[0xC - 0x8];
    s32 fC;
    char pad10[0x30 - 0x10];
};

extern struct S8009B45C *D_8009B45C;
extern void func_800471D0(s32 a0, s32 a1, s32 a2, s32 a3, s32 arg5, s32 arg6);
extern void func_80045BE8(struct LocalBuf51 *a0);

void func_80047788(s32 a0) {
    s32 t0, v0;
    s32 idx8;
    struct ArrElem *elem;
    struct LocalBuf51 buf;

    t0 = D_8009B45C->f2 << 3;
    v0 = t0 + 0x7FF;
    if (v0 < 0) {
        v0 = t0 + 0xFFE;
    }
    asm volatile("" : "+r"(v0));
    t0 = v0 >> 11;
    t0 = t0 + 1;

    {
        s32 a1const = 0x801E6800;
        asm volatile("" : "+r"(a1const));
        idx8 = (s32)(u16)a0 << 3;
        elem = (struct ArrElem *)(idx8 + (s32)D_8009B45C->f448);
        func_800471D0(D_8009B45C->f438, a1const, t0 + elem->f0, elem->f4, 0x800, 0x10);
    }

    buf.type = 0x51;
    buf.f4 = D_8009B45C->f438;
    buf.fC = 0x801E6800;
    func_80045BE8(&buf);

    idx8 = (s32)((char *)D_8009B45C->f448 + idx8);
    elem = (struct ArrElem *)idx8;
    D_8009B45C->f438 = D_8009B45C->f438 + elem->f4;
}
