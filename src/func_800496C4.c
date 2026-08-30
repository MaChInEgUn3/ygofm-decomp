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

/* Blacklist reclamation (blacklist.txt:637), LANDED 0/38 (claude-w2,
   tangOS reclamation pass). Old sketch was lost; rebuilt from scratch off
   the raw disassembly (scout.py dossier gives the logic unambiguously).

   a3 = a0 (unconditional alias kept alive the whole function); t0 = 0;
   a1 = sign_extend_16(a1_raw); D_8009B458->f818 = 0 ALWAYS (it sits in
   the guard branch's own delay slot, so it runs on both paths); if
   (a1 == -1) { if (D_8009B458->rec.f0 != a1) return -1; } then:
   rec->f0=t0(0); rec->f4=a3; v1=(a3->f12<<9)+0xA20; rec->f8=v1;
   rec->f10=a3->fC-v1; rec->f18=a3->f18; rec->f14=a2; rec->f1B=a3->f19;
   return 0.

   TWO real levers closed the old "21/38 at 36w, 2 short" ceiling:

   1. THE PHANTOM STACK FRAME (the reason this stayed blacklisted -- a
      true LEAF with a genuine 8-byte `addiu sp,sp,-8`/`+8` frame despite
      no calls and no address-taken local anywhere in the logic; every
      prior plain rendering allocated NO frame at all, since gcc 2.8.1
      -O2 has nothing to spill). FIX: an explicitly declared but never
      READ local array (`char unused_frame[8];`) is enough on its own to
      make gcc reserve the matching stack space -- gcc allocates frame
      space for a declared local's storage class before any later
      dead-store/unused-variable elimination removes its actual reads,
      so a large-enough dead local reproduces a frame the real source
      almost certainly needed for something this decompilation doesn't
      need to know about. (A struct-by-value-parameter ABI-home-slot
      hypothesis was tried FIRST and also matched the frame size, but
      produced a completely different, wrong internal shape -- a real
      stack spill+reload for the "struct" field reads that target never
      does -- so it was a false lead; the dead-local explanation is both
      simpler and the one that actually reproduces target's instructions.)
   2. THE REC POINTER: every `D_8009B458->rec.fieldX = ...;` func_80073900
      independently recomputes the FULL absolute offset (base+0x4A4+X)
      instead of reusing one shared base. Target computes `rec =
      (u8*)D_8009B458 + 0x4A4` ONCE (`addiu a0,a0,1188`) and writes all
      6 fields via SMALL offsets from that one pointer. Introducing an
      explicit `struct Rec *rec = &D_8009B458->rec;` local (used for
      every subsequent field func_80073900) reproduced this exactly and closed
      most of the remaining gap by itself (30/38 -> 7/38).

   Two small residuals closed the last 7 words: (a) the `a1==-1` guard's
   branch polarity -- `bne`/`beq` -- had to be checked against the raw
   bytes directly rather than trusted from the old blacklist prose (which
   had it backwards: the check runs when a1==-1, not a1!=-1, even though
   both compile to a similar-looking guard clause). (b) statement order in
   the tail block: target reads `a3->f19` BEFORE writing `rec->f14=a2`,
   not after (an explicit `f19val` temp reproduces the func_800738F0-then-func_80073900
   order). The remaining prologue reorder (a `lui` for D_8009B458
   floating before vs after `move a3,a0`/`move t0,zero`) turned out to be
   flag-dependent -- G0:nosplit reproduces it correctly; G8/G0:split do
   not -- so this landed as G0:nosplit specifically, not the G8:split
   default most of this family prefers. */

struct Rec {
    s16 f0;
    char pad4[0x4 - 0x2];
    void *f4;
    s32 f8;
    char pad10[0x10 - 0xC];
    s32 f10;
    s32 f14;
    char pad18[0x18 - 0x18];
    u8 f18;
    char pad1B[0x1B - 0x19];
    u8 f1B;
};

struct Obj {
    char pad0[0xC];
    s32 fC;
    char pad10[0x12 - 0x10];
    u16 f12;
    char pad14[0x18 - 0x14];
    u8 f18;
    u8 f19;
};

struct Container {
    char pad0[0x4A4];
    struct Rec rec;
    char pad2[0x818 - 0x4A4 - 0x1C];
    s32 f818;
};

extern struct Container *D_8009B458;

s32 func_800496C4(struct Obj *a0, s32 a1_raw, s32 a2) {
    struct Obj *a3 = a0;
    register s16 t0 asm("t0") = 0;
    s16 a1;
    s32 v1;
    char unused_frame[8];
    (void) unused_frame;

    a1 = (s16) a1_raw;
    D_8009B458->f818 = 0;
    if (a1 == -1) {
        if (D_8009B458->rec.f0 != a1) {
            return -1;
        }
    }

    {
        struct Rec *rec = &D_8009B458->rec;
        u8 f19val;
        rec->f0 = t0;
        rec->f4 = a3;
        v1 = (a3->f12 << 9) + 0xA20;
        rec->f8 = v1;
        rec->f10 = a3->fC - v1;
        rec->f18 = a3->f18;
        f19val = a3->f19;
        rec->f14 = a2;
        rec->f1B = f19val;
    }
    return 0;
}
