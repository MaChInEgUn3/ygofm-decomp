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

/* RENAMED func_80024D34 (was func_80024D34), TENTATIVE -- live
   func_80073900-trace 2026-08-28, user RE notes (relayed via dev-80/overseer): slot
   20; evidence thinner than the other renames in this batch, flagged
   TENTATIVE pending confirmation.

   Card-record funnel family (func_800249E0 @0x800249E0 is the sibling
   entry point). Takes a raw slot arg (a0): if its high bit is set the value
   is remapped (a0&0x7F)+0xF -- the same run-length decode used by
   func_80018DB4's D_800907CC table. The remapped index s0
   is then used two ways: (1) reserves a record slot via
   func_800249E0(s0) and stores the returned slot pointer's target once
   func_80024C1C() below returns; (2) looks up a header at
   D_8015C424 + s0*0x1C + 0x48000 + 0x36B8 -- this resolves to the fixed
   absolute address 0x801A7ADC + s0*0x1C, i.e. D_801A7AD8[s0]+4 (the same
   0x1C-stride record array func_800249E0 itself indexes), func_800738F0 as a s16
   card id. That id plus D_800908A0[s0]'s two s16 fields feed
   func_80024C1C to build the on-field icon object, which then
   gets tagged with s0 in its f6A slot.

   The D_8015C424 extern (not D_801A7AD8) is required for the match: gcc's
   MIPS address legitimiser only splits the 0x48000 bank into its own
   lui+ori (rather than folding it into the symbol's relocation, which would
   produce a different, wrong instruction shape) when the offset is carried
   through a plain byte array rather than the record struct type -- same
   family as src/func_80027DF8.c's "struct Blob" note. The bank must also be
   materialized through a tiny raw-asm block, not a plain `s32 bank = ...`
   local, or gcc constant-folds it into D_8015C424's own addiu instead of
   keeping it as a separate addend (project_runtime_var_offset_defeats_addr_fold).

   Documented residual, now resolved (12/37 -> 0/37): target groups
   (D_8015C424_base + s0*0x1C) FIRST, then adds the bank SECOND, and keeps
   the base materialised in a register from the OUTSET of that sequence;
   naive reassociation always did the addition the other way round. Forcing
   the base into its own named local (`base = D_8015C424;`), declared right
   after the bank asm block and before the multiply, reproduces the target's
   exact instruction order and register choice. */

struct Hdr {
    s16 f0; /* card id, 0-based */
};

struct Rec4 {
    s16 f0;
    s16 f2;
};

struct Obj {
    char pad[0x6A];
    u8 f6A; /* slot index, set post-spawn */
};

extern u8 D_8015C424[0x1C * 0x80];
extern struct Rec4 D_800908A0[0x80];
extern void *func_800249E0(void);
extern struct Obj *func_80024C1C(s32 cardId, s32 x, s32 y);

void func_80024D34(s32 a0) {
    /* func_800249E0 takes its slot arg implicitly: $a0 is never
       reloaded between this function's own prologue and the call, so the
       untouched input register carries straight through. Declaring the
       call with an explicit argument here forces a spurious re-materialise
       of a0 and desyncs the whole tail's scheduling. */
    void **slotPtr = (void **) func_800249E0();
    s32 s0 = a0;
    s32 bank;
    u8 *base;
    u8 *p;
    struct Hdr *hdr;
    struct Obj *obj;

    if (s0 & 0x80) {
        s0 = (s0 & 0x7F) + 0xF;
    }

    __asm__ volatile("lui %0, 0x4\n\tori %0, %0, 0x8000" : "=r" (bank));

    base = D_8015C424;
    p = base + s0 * 0x1C;
    p = p + bank;
    hdr = *(struct Hdr **) (p + 0x36B8);

    obj = func_80024C1C(hdr->f0, D_800908A0[s0].f0, D_800908A0[s0].f2);
    *slotPtr = obj;
    obj->f6A = s0;
}
