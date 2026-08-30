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

/* MATCHED 0/69, G0:nosplit --keep-large-ori (claude-w2, 2026-08-28).
 * Reclaimed from the blacklist, recorded there at 59/69 with three named
 * unsolved issues; all three fell, and the one the entry called "cause
 * unknown" turned out to be the load-bearing one.
 *
 * Stops the SPU voices bound to one sound id.  Bit 15 set is the "delete"
 * path: func_800464F0(id) then the argument-less func_80045114 (that
 * signature is established by the matched sibling src/func_800473F0.c),
 * and a genuine early return -- the raw j at 0x80047DEC is a jump to this
 * function's own epilogue, which m2c renders as a bogus call.  A
 * 0x4000-class id is first translated through D_8009B45C's u16 table at
 * +0x44C, indexed by the low 5 bits plus 32 when bit 8 is set, and 0xFFFF
 * means "nothing to do".  The remaining id is compared against the four
 * live ids at +0x404; each hit accumulates 0x100000<<i into a key mask,
 * clears bit i of the +0x434 byte and notifies func_80047C70, and a
 * non-empty mask ends in func_80076ED0(0, mask).
 *
 * WHY --keep-large-ori IS NOT OPTIONAL: the 0xFFFF sentinel compiles to
 * ori $v0,$zero,0xFFFF at 0x80047E2C.  match/cmp.sh and msearch preserve
 * ori for N >= 0x8000, but the build rewrites it to a sign-extending addiu
 * without this flag -- so the unit verifies 0-diff and BUILDS WRONG.
 * msearch prints the NOTE itself; do not drop the flag from unit_flags.
 *
 * THE THREE RECORDED BLOCKERS, and what each actually was:
 *  1. "D_8009B45C compiles gp-relative under G8 but the ROM wants
 *     absolute, and -G0 makes it WORSE (67-70/69, needs an extra
 *     callee-saved register)".  Both halves are true and the resolution is
 *     -G0 -mno-split-addresses SPECIFICALLY.  Under -msplit-addresses the
 *     lui is a separate loop-invariant insn, so gcc hoists it into that
 *     extra callee-saved register; with the lui and lw fused, the load
 *     cannot cross the func_80047C70 call inside the loop and the target's
 *     per-iteration reload falls out on its own.  Two aliases, one per
 *     site.
 *  2. "The first two instructions are a redundant a1/a0 register copy that
 *     plain single-parameter C never reproduces, cause unknown".  They are
 *     not redundant: a1 is the parameter and a0 is a SEPARATE id variable
 *     that the 0x4000 path overwrites.  gcc proves id == param on the
 *     other path and folds the copy away, so the fix is an empty launder
 *     on the parameter copy plus a pin of id to a0.
 *  3. "Assorted prologue/loop-init scheduling ties, unaffected by every
 *     reordering tried".  Only one of them was real, and it is a source
 *     order after all: bit = 1 must be the FIRST statement of the
 *     post-lookup init block, which is what func_8008FAF0 li s2,1 in the bne delay
 *     slot.  Everything else was downstream of issues 1 and 2. */

extern u8 *D_8009B45C;
extern u8 *D_8009B45C;
extern void func_800464F0(s32 id);
extern void func_80045114(void);
extern s32 func_80047C70(void *a0);
extern void func_80076ED0(s32 a0, s32 a1);

void func_80047DB0(s32 param) {
    s32 mask;
    s32 i;
    s32 bit;
    s32 vbit;
    s32 idm;
    s32 p;
    register s32 id asm("a0");

    p = param;
    __asm__("" : "+r"(p));
    id = p;
    if (p & 0x8000) {
        func_800464F0(id);
        func_80045114();
        return;
    }

    if ((p & 0xF000) == 0x4000) {
        u8 *b = D_8009B45C;
        s32 lo = (p & 0x1F) << 1;
        s32 hi = ((p & 0x100) != 0) << 6;
        id = *(u16 *)(b + (lo + hi) + 0x44C);
        if (id == 0xFFFF) {
            return;
        }
    }
    bit = 1;
    mask = 0;
    vbit = 0x100000;
    i = mask;
    idm = id & 0xFFFF;
    do {
        u8 *q = D_8009B45C;
        if (*(u16 *)(q + (i << 1) + 0x404) == idm) {
            mask |= vbit;
            q[0x434] = q[0x434] & ~bit;
            func_80047C70((void *)vbit);
        }
        bit <<= 1;
        i++;
        vbit <<= 1;
    } while (i < 4);
    if (mask != 0) {
        func_80076ED0(0, mask);
    }
}
