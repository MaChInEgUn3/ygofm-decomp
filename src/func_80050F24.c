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

/* func_80050F24 -- gate-threshold recompute for one D_800F2C40 record
   (0xE20-byte stride, idx = param 0).

   rec = &D_800F2C40[idx * 0xE20]; slot = rec[0xDFE];
   entry = *(u16 *)(rec + (slot+3)*118 + 0x7C4).  If entry != 0, call
   func_80057AF4(idx, slot + 3, 1) -- NOTE: the second argument is
   slot + 3, NOT this function's own second parameter.  ROM 0x80050F68
   writes `addiu a1, v0, 3` and nothing rewrites a1 before the jal, so
   `idx3` IS the argument; a prior decode func_800738F0 a1 as a pass-through of
   arg1 (which is in fact unused) because the call site itself emits no
   move either way.  thresh = entry*2/3, clamped UP to a minimum of 0x3C;
   overridden entirely by *(u16 *)(rec+0xCF8 + slot*2 + 0xC) if nonzero.
   Then func_80059F18(1, -1, idx^1, thresh) and up to two
   func_8005F180(x) calls off the 0x80/0x40 bits of (rec+0xCF8)[slot+0xA].

   Matched 0/82 at -G8 -mno-split-addresses -fno-schedule-insns (w1,
   2026-08-30) off the banked 17/82.  The load-bearing pieces, in order:
   idx3 as the call argument (above); the base pointer kept alive into
   `sub = off + base` and released by an empty launder BEFORE the $4
   clobber (order matters: the clobber inside base's live range func_8008FAF0 a0
   in its conflict set); -fno-schedule-insns so sched1 cannot hoist the
   base lui above the off chain (the saves then interleave to the ROM's
   own order); the magic divide constant homed in v1 ahead of the
   doubling; a keep-alive on the scaled index so the tval address gets a
   fresh destination; and a keep-alive on sub after its last func_800738F0 so the
   final addu is non-destructive.  Every asm here is empty -- zero
   emitted instructions.  Full search history:
   match/sketches/func_80050F24.c. */

extern u8 D_800F2C40[];
extern void func_80057AF4(s32 a0, s32 a1, s32 a2);
extern s32 func_80059F18(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_8005F180(s32 a0);

void func_80050F24(s32 idx0, s32 arg1) {
    register s32 idx asm("s3") = idx0;
    u8 *rec;
    register s32 s0 asm("s0");
    register u8 *sub asm("s2");
    u8 slot;
    u16 tval;

    {
        register s32 off asm("v1") = idx * 0xE20;
        u8 *base;
        s32 idx3;
        base = D_800F2C40;
        rec = base + off;
        slot = rec[0xDFE];
        base += 0xCF8;
        idx3 = slot + 3;
        {
            u8 *p = rec + idx3 * 118;
            s0 = *(u16 *) (p + 0x7C4);
        }
        sub = off + base;
        if (s0 != 0) {
            __asm__ volatile("" : "+r" (base));
            __asm__ volatile("" : : : "$4");
            func_80057AF4(idx, idx3, 1);
        }
    }

    {
        register s32 magic asm("v1") = 0x55555556;
        register s32 doubled asm("v0") = s0 * 2;
        __asm__ volatile("" : : "r" (magic));
        s0 = doubled / 3;
    }
    if (s0 < 0x3C) {
        s0 = 0x3C;
    }

    slot = rec[0xDFE];
    {
        s32 sc = slot * 2;
        u8 *addr = sub + sc;
        __asm__ volatile("" : : "r" (sc));
        tval = *(u16 *) (addr + 0xC);
    }
    if (tval != 0) {
        s0 = tval;
    }

    func_80059F18(1, -1, idx ^ 1, s0);

    slot = rec[0xDFE];
    func_8005F180((!(*(sub + slot + 0xA) & 0x80)) << 1);

    slot = rec[0xDFE];
    {
        u8 *q2 = sub + slot;
        if (q2[0xA] & 0x40) {
            func_8005F180(1);
        }
    }
    __asm__ volatile("" : : "r" (sub));
}
