/* ASSEMBLY DEBT -- this is a TRANSCRIPTION, not a decompilation.
 * Ordinary MIPS written into an inline asm block to force a match. It is
 * byte-exact and therefore invisible to build.py, which is exactly the
 * problem: the oracle cannot tell transcribed assembly from real C, so
 * nothing but this comment stops it being counted as done.
 * Counted by tools_src/asm_debt.py; the standard is in docs/ASM_DEBT.md.
 */
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

/* Track/tempo-stream setup on D_8009B458 (BigState). Resets record0's
   stream position and the byte-stream func_800738F0 limit, reads a 2-byte
   "division" field via func_8004BCA8(rec0), reads a 4-byte
   value via func_8004BC2C(rec0) and keeps its top 3 bytes as the raw
   tempo (usec/quarter-note), computes the per-tick timer rate as
   60000000/tempoRaw scaled *100/115 (verified magic-multiply constant --
   gcc's own division-by-115 idiom reproduces the target's exact
   instruction sequence, no need to hand-roll it -- but it must stay
   UNSIGNED (u32), or gcc emits a signed-division overflow guard the
   target does not have), clamped to 0xFF and right-shifted by 1
   (division==0x18/0x3C) or 2 (division==0x1E), writes the result into
   record0's f14/f16 timer fields, then calls func_8004BAE4(rec0)
   purely for its side effect (return discarded). Finally re-derives
   D_8009B458->unk804 from tempoDiv (once inside a >=0x60 guard, then
   again unconditionally -- both stores are present in the target).

   D_8009B458 is re-fetched via a fresh absolute lui+lw at every access
   site rather than cached across the three calls -- this codebase's
   documented pattern for this exact global (see init_spu_voices.c,
   process_timer_burst_records_8004c8c8.c). record0's own pointer is
   pinned to $s0 (the function's only saved register in the target) so
   gcc doesn't also spill one of the transient BigState reloads into a
   second saved register. */

typedef struct {
    u32 f0;                /* 0x0: stream-func_800738F0 position */
    u8 pad4[0x14 - 4];
    u16 f14;                /* 0x14: timer accumulator */
    u16 f16;                /* 0x16: timer increment */
} Rec0;

typedef struct {
    u8 pad0[0x7EC];
    u32 limit;              /* 0x7EC: byte-stream func_800738F0 limit */
    u32 unk7F0;              /* 0x7F0 */
    u32 unk7F4;              /* 0x7F4 */
    u16 unk7F8;              /* 0x7F8 */
    u16 unk7FA;              /* 0x7FA */
    u16 tempoDiv;             /* 0x7FC: PPQN-ish divisor selector */
    u8 pad7FE[0x801 - 0x7FE];
    u8 unk801;                /* 0x801 */
    u8 pad802[0x804 - 0x802];
    s32 unk804;               /* 0x804 */
    u32 tempoUsec;             /* 0x808: microseconds per quarter note */
} BigState;

extern BigState *D_8009B458;
extern s32 func_8004BCA8(s32 a0);
extern s32 func_8004BC2C(s32 a0);
extern s32 func_8004BAE4(s32 a0);

s32 func_8004BCE8(void) {
    register BigState *rv1 asm("v1");
    register Rec0 *rec0 asm("s0");
    register BigState *rv0 asm("v0");
    register BigState *ra0 asm("a0");
    s32 division;
    s32 packed4;
    u32 tempoUsec;
    u32 mask;

    rv1 = D_8009B458;
    __asm__ volatile("addiu %0, %1, 0x518" : "=r"(rec0) : "r"(rv1));
    rv1->unk801 = 0;

    __asm__ volatile("lui %0, %%hi(D_8009B458)\n\tlw %0, %%lo(D_8009B458)(%0)" : "=r"(rv0));
    rv0->unk7F0 = 0;
    rv0->unk7F4 = 0;

    *(u32 *)((u8 *)rv1 + 0x518) = 8;
    division = func_8004BCA8((s32)rec0);

    __asm__ volatile("lui %0, %%hi(D_8009B458)\n\tlw %0, %%lo(D_8009B458)(%0)" : "=r"(rv1));
    rv1->tempoDiv = (u16)division;
    rv1->unk7FA = 1;
    rv1->unk7F8 = 0;
    rv1->limit = 0x10000;
    packed4 = func_8004BC2C((s32)rec0);

    tempoUsec = (u32)packed4 >> 8;

    ra0 = D_8009B458;
    ra0->tempoUsec = tempoUsec;

    tempoUsec = 60000000u / tempoUsec;
    tempoUsec = tempoUsec * 100u / 115u;
    if (tempoUsec >= 0x100) {
        tempoUsec = 0xFF;
    }

    switch (ra0->tempoDiv) {
    case 0x3C:
    case 0x18:
        tempoUsec >>= 1;
        break;
    case 0x1E:
        tempoUsec >>= 2;
        break;
    }

    mask = tempoUsec & 0xFF;
    rec0->f16 = mask;
    rec0->f14 = mask;
    func_8004BAE4((s32)rec0);

    __asm__ volatile("lui %0, %%hi(D_8009B458)\n\tlw %0, %%lo(D_8009B458)(%0)" : "=r"(rv1));
    if (rv1->tempoDiv >= 0x60) {
        rv1->unk804 = rv1->tempoDiv;
    } else {
        rv1->unk804 = 0;
    }

    __asm__ volatile("lui %0, %%hi(D_8009B458)\n\tlw %0, %%lo(D_8009B458)(%0)" : "=r"(rv1));
    rv1->unk804 = rv1->tempoDiv;

    return 1;
}
