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

/* Blacklist reclamation, 2026-08-28 (w2): 3/23 -> 0/23, matching at ALL FOUR
   flag combos.  SPU voice-attribute setup, sibling of src/func_8004A6F8.c
   0x6C below (same 0x60100 mode constant, same D_8009B458 pointer, same
   func_80077450 tail).  Sets voice = D_80011434[idx], mode = 0x60100,
   pitch/fields 0x4FA and 0x4FC to 0, field 0x4E4 to 5, then hands the
   attribute record to func_80077450.

   THE RESIDUAL WAS A LOAD-VERSUS-STORE ALIASING CONSTRAINT, NOT THE
   PROLOGUE.  Both this function and func_8004A6F8 were recorded as stuck on
   "gcc hoists the ra-save into the slot target gives the global's lw", i.e.
   prologue placement, "which no value-level lever reaches".  The
   observation is exact; the causality is backwards.  gcc is not hoisting
   the save -- it CANNOT SINK IT, because the two loads either side of it
   are C loads and gcc will not move a load above a store it cannot
   disambiguate.  `sw ra,16(sp)` is such a store, so it is pinned above both
   loads and they pile up behind it.

   The fix takes both loads out of gcc's memory-op set, and it is
   COMPOSE-OR-NOTHING -- this function's own header already records the
   pointer-load half as tried and DEAD at 9-11/23, because alone it is:
     1. emit the D_8009B458 pointer load from a NON-VOLATILE extended asm
        with no memory clobber (a pure computation to the scheduler, free to
        float above the save);
     2. emit the table-value load the same way;
     3. order the two with a FAKE DEPENDENCY -- the value load takes the
        pointer as an extra, UNUSED input operand.  The "r"(v1) below is
        func_800738F0 by nothing in the asm text; it exists only so this load cannot
        be scheduled before the pointer load.  Marking the load volatile
        instead does NOT work: that pins it rather than ordering it.
     4. anchor the constant's low half.  With 1-3 in place the function is
        one word off: `ori` sinks to just before its use, where the target
        computes it four instructions earlier, right after the two loads.
        Splitting `attrHi | 0x100` out into its own statement with an empty
        launder holds it there.

   MEASURED MINIMAL: with the ordering fixed, NEITHER half of the 0x60100
   constant needs inline asm any more.  Earlier passes needed
   __asm__("lui %0, 6") to get the high half into the first slot; plain C
   plus the launder is now byte-identical, and so is the low half.  Only the
   three loads/address asms below remain, each verified load-bearing by
   removal. */

struct S8009B458 {
    char pad0[0x4C0];
    s32 f4C0;
    s32 f4C4;
    char pad1[0x4E4 - 0x4C8];
    s32 f4E4;
    char pad2[0x4FA - 0x4E8];
    u16 f4FA;
    u16 f4FC;
};

extern u32 D_80011434[];
extern struct S8009B458 *D_8009B458;
extern void func_80077450(s32 *);

void func_8004A764(s32 idx)
{
    register u32 attrHi __asm__("a1");
    register u32 *tableAddr __asm__("a0");
    register struct S8009B458 *v1 __asm__("v1");
    register u32 voice __asm__("v0");

    attrHi = 0x60000;
    __asm__("" : "+r"(attrHi));
    {
        u32 *tbase = D_80011434;
        s32 scaled;
        __asm__("" : "+r"(tbase));
        scaled = idx * 4;
        /* target's add is `addu a0,a0,v0` (scaled + base); the natural
           pointer expression canonicalises to `addu a0,v0,a0` */
        __asm__("addu %0, %1, %2" : "=r"(tableAddr) : "r"(scaled), "r"(tbase));
    }
    __asm__("lui %0, %%hi(D_8009B458)\n\t"
            "lw %0, %%lo(D_8009B458)(%0)" : "=r"(v1));
    /* "r"(v1) is a fake dependency: unused by the asm text, it orders this
       load after the pointer load above */
    __asm__("lw %0, 0(%1)" : "=r"(voice) : "r"(tableAddr), "r"(v1));
    __asm__("" : "+r"(voice));

    attrHi = attrHi | 0x100;
    __asm__("" : "+r"(attrHi));

    v1->f4C0 = voice;
    v1->f4C4 = attrHi;
    v1->f4FA = 0;
    v1->f4FC = 0;
    voice = 5;
    v1->f4E4 = voice;
    func_80077450(&v1->f4C0);
}
