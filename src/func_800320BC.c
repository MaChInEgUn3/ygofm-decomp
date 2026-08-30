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

/* MATCHED 0/50 on ALL FOUR flag combos (2026-08-28, w1).

   WHAT IT DOES. Scans 40 slots of stride 0x10 from arg0+0x2D54 for the first
   whose byte at +9 is zero, claims it, fills it from the packed s32 record
   D_801D4244[arg1-1] -- slot+0 = arg1, slot+2 = (rec & 0x1FF) * 10,
   slot+4 = ((rec >> 9) & 0x1FF) * 10, slot+6 = (rec >> 26) & 0x1F, both
   shifts signed -- then calls func_80032C48(arg0 + 0x2D50) and
   func_8003201C(arg0). If no slot is free after 40 tries it returns.

   TWO m2c ARTIFACTS CORRECTED: the tail `j 0x80032174` is rendered as a call
   to a function of that name, but the address is inside this function's own
   extent -- it is the shared epilogue, a plain return; and func_80032C48 is
   given three arguments because $a1/$a2/$a3 happen to be live, while
   src/func_80031EE4.c already declares and matched it as
   func_80032C48(void *).

   THREE FIXES, and the third is the one that had this stuck at 43/50:
     1. arg1 is s32, not s16. Target does `addiu v0,a1,-1` straight off the
        incoming register; an s16 parameter makes gcc re-narrow with sll/sra.
     2. The record address is computed BASE FIRST -- name D_801D4244 as its
        own local, then apply the index -- which fixes the lui/addiu ordering.
     3. AN EMPTY REGISTER-ONLY LAUNDER ON THE LOOP POINTER, AT THE TOP OF THE
        LOOP BODY: `__asm__("" : "+r" (p));`. Without it gcc splits the
        induction variable in two, `addiu t0,s0,11608` for the increment and
        `addiu a2,s0,11606` for the accesses, re-basing everything on p-2 --
        one extra word and the whole body shifts. Target keeps ONE pointer at
        arg0+0x2D58 and reaches every field from it at -4, -2, 0, +2, +5.
        Four pointer spellings had failed to stop that fold (u8* with
        *(s16*)(p-4) casts, s16* with p[-2]/p[-1], a separate alias inside
        the if, and a struct anchored at 0x2D54 with positive offsets); the
        launder blocks it at zero word cost. Found on func_8005611C, whose
        64-entry loop had the identical fold, and transferred here in one
        compile. */


extern s32 D_801D4244[];
extern void func_8003201C(s32 a0);
extern void func_80032C48(void *a0);

void func_800320BC(s32 arg0, s32 arg1) {
    s32 *rec;
    s16 *p;
    register s32 i asm("a0");

    i = 0;
    {
        s32 *base = D_801D4244;
        s32 idx = arg1 - 1;
        rec = &base[idx];
    }
    p = (s16 *) (arg0 + 0x2D58);
    do {
        __asm__("" : "+r" (p));
        if (((u8 *) p)[5] == 0) {
            ((u8 *) p)[5] = 1;
            p[-2] = (s16) arg1;
            ((u8 *) p)[2] = (u8) ((*rec >> 26) & 0x1F);
            p[-1] = (s16) ((*rec & 0x1FF) * 10);
            p[0] = (s16) (((*rec >> 9) & 0x1FF) * 10);
            func_80032C48((void *) (arg0 + 0x2D50));
            func_8003201C(arg0);
            return;
        }
        i += 1;
        p += 8;
    } while (i < 40);
}
