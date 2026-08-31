/* PARKED CANDIDATE PORTED from Unchiga's tree (docs/MERGE_UNCHIGA.md).
 * Installed here because HIS base is closer than the one this tree
 * reached: the counts are in PARKED.txt. Measure it with the flags on
 * the next line -- they are his unit's, and try_func's default flags
 * report a different number.
 * FLAGS: -G8 -mno-split-addresses
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef int s32;

/* func_8002CCE4 -- set-or-clear one bit in the D_801D0000+1560 bitmap.
   25 instructions, 0x8002CCE4..0x8002CD48. Merged with the fall-through
   set-bit helper previously seen at 0x8002CD24 (see config/blacklist.txt):
   that address is not an independently-called function, it is this
   function's own "set bit" path, reached by a direct branch (not jal)
   from the test below, sharing idx computed up front. No other src file
   or raw .s references func_8002CD24 as a symbol, so it needs no ELF
   symbol of its own -- the `goto setbit` below reproduces the branch with
   no ceremony.

   RESOLVED, 2026-08-30 (claude-w2): this was carried on the blacklist as
   part of a "register-role-swap family" (func_8002827C/func_800282BC/
   func_80035700/func_80032BD4) believed to need an unknown/unresolved
   trick. It does not -- the real cause was a genuine gcc 2.8.1 local-alloc
   TIE (two independent values, the branch's shared (a0&7) and the
   set-arm's own address-vs-mask ordering, and separately the clear arm's
   own bit-index-vs-constant-vs-shift-result triple), not a missing
   language feature. Closed with three C-level levers, none of them exotic:
   (1) `register` pins reproducing the ROM's own register choices once the
   real scheduling ties (below) were found and fixed; (2) a bare
   `__asm__ volatile("")` ordering barrier between two independent,
   same-cost computations that gcc's list scheduler otherwise floats
   without regard to source order; (3) giving a constant its OWN pinned
   register (`c asm("v0")`) instead of letting it share the destination of
   the shift that consumes it, when the target keeps it in a fresh
   register. See match/sketches/func_8002CCE4.c's header for the full
   6-step derivation (each with the exact ROM instructions it matched) and
   what was tried and reverted. Worth re-checking whether
   func_8002827C/func_800282BC/func_80035700/func_80032BD4 fall to the same
   three levers rather than truly needing something new. */

extern u8 D_801D0000[];
extern u8 D_801D0000_b[];

void func_8002CCE4(s32 a0) {
    s32 idx;
    register s32 bit asm("a1");
    register u8 *p asm("v1");

    idx = (a0 & 0x7FF) >> 3;
    bit = a0 & 7;
    if (!(a0 & 0x8000)) {
        goto setbit;
    }
    {
        register s32 bit2 asm("v1");
        register s32 c asm("v0");
        register s32 mask asm("a0");
        __asm__ volatile("" : "+r" (a0));      /* forces the ROM's SECOND andi */
        bit2 = a0 & 7;
        c = 128;
        mask = c >> bit2;
        __asm__ volatile("");                  /* forces mask-before-pointer, matching the ROM */
        p = D_801D0000 + idx;
        p[1560] = p[1560] & ~mask;
    }
    return;
setbit:
    {
        s32 c = 128;
        u8 v;
        p = D_801D0000_b + idx;
        v = p[1560];
        c >>= bit;
        v |= c;
        p[1560] = v;
    }
}
