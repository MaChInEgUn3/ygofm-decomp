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

/* MATCHED 0/74, G0:nosplit (claude-w2, 2026-08-28).  Reclaimed from the
 * blacklist ("Stops SPU sound-effect voice(s) ... 240 bytes", 0 attempt
 * rows, no sketch on disk).
 *
 * Stops every SPU sound-effect voice whose (type1,type2) pair equals
 * (arg0&0xFF, arg1&0xFF) in D_8009B458's 0x28-stride slot array at +0x180
 * (count s16 at +0x510).  Per hit: func_8004A7C0(i) -- the already-landed
 * single-slot stopper, src/func_8004A7C0.c -- and OR that slot's voice-bit
 * word from the 0x80011434 table into an accumulated mask.  Drain the mask
 * through the same func_80076ED0 / func_80077090 settle loop the sibling
 * uses, then clear byte +4 of the 0x18-stride record arg0&0xFF at
 * D_8009B458+0.
 *
 * FOUR levers, each needed, in the order they were found:
 *  1. -G0 with ONE EXTERN ALIAS PER ABSOLUTE RELOAD SITE
 *     (project_g0_licm_fresh_name_per_reload).  Plain -G8 addresses
 *     D_8009B458 through $gp (3 words short); plain -G0 lets LICM hoist the
 *     shared `lui` out of the loop.  D_8009B458 / _b / _c are the same
 *     address under three names, one per lui the target emits.
 *  2. An EMPTY LAUNDER on the arg1 copy inside the loop
 *     (project_empty_register_launder_placement_lever).  The target masks
 *     arg1 every iteration (`andi v0,s5,0xff` in the bne's delay slot);
 *     without the launder gcc hoists that andi into the preheader.
 *  3. PINS on the two peer masks, t1->s4 and a1v->s5.  Their relative
 *     allocation is a pure tie-break and gcc picks it backwards; the alias
 *     trick does not apply (one use site each).  t1 must be s32 holding
 *     `arg0 & 0xFF`, not a u8 copy -- a u8 t1 re-masks at the use site
 *     inside the loop instead of once in the preheader.
 *  4. The 0x80011434 table base.  The target materialises it ACROSS TWO
 *     REGISTERS (`lui v0,0x8001` / `addiu s3,v0,5172`); the sibling's
 *     one-register "+r" idiom cannot express that, so the low half arrives
 *     through a two-operand asm whose input is pinned to v0.  The pin must
 *     be a BARE declaration with the assignment placed after `t1 = ...`:
 *     initialising at the declaration emits the lui before the andi
 *     (project_leading_load_before_prologue_register_pin_side_effect --
 *     same hoist, one statement's worth). */

extern u8 *D_8009B458;
extern u8 *D_8009B458;
extern u8 *D_8009B458;
extern void func_8004A7C0(s32 idx);
extern void func_80076ED0(s32 a0, s32 a1);
extern s32 func_80077090(s32 a0);

void func_8004B374(s32 arg0, s32 arg1) {
    u8 *base;
    s32 mask;
    s32 i;
    s32 off;
    s32 *tbl;
    s32 v0;
    register s32 t1 asm("s4");
    register s32 a1v asm("s5") = arg1;

    base = D_8009B458;
    i = 0;
    mask = 0;
    if (*(s16 *)(base + 0x510) > 0) {
        register s32 hi asm("v0");
        s32 lo;

        t1 = arg0 & 0xFF;
        hi = 0x80010000;
        __asm__("addiu %0, %1, 0x1434" : "=r"(lo) : "r"(hi));
        tbl = (s32 *)lo;
        off = 0;
        do {
            u8 *p = base + off;
            __asm__("" : "+r"(a1v));
            if (p[0x183] == t1 && p[0x185] == (u8)a1v) {
                func_8004A7C0(i);
                mask |= *tbl;
            }
            tbl++;
            off += 0x28;
            base = D_8009B458;
        } while (++i < *(s16 *)(base + 0x510));
    }

    if (mask != 0) {
        do {
            func_80076ED0(0, mask);
            v0 = func_80077090(mask);
        } while (v0 != 2 && v0 != 0);
    }

    {
        u8 *q = D_8009B458 + ((u8)arg0) * 0x18;
        q[4] = 0;
    }
}
