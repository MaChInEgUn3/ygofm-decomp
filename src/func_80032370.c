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

/* Clears any of the 16 handle slots in D_801D07BC whose associated
   D_801D0250 flag byte is 0, then compacts the array, removing zeroed
   slots and shifting the remaining handles down to the front. */

extern s16 D_801D07BC[16];

void func_80032370(void) {
    register s16 *base asm("a2");
    register u8 *flags asm("a0");
    register s32 i asm("a1");
    s16 handle;
    u8 flag;
    s16 *v1;
    s16 *readp;
    s16 *writep;

    {
        register u32 hi asm("v0");
        __asm__("lui %0,%%hi(D_801D07BC)" : "=r" (hi));
        __asm__("addiu %0,%1,%%lo(D_801D07BC)" : "=r" (base) : "r" (hi));
    }
    flags = (u8 *)base - 0x56C;

    i = 15;
    v1 = base + 15;
    for (; i >= 0; i--) {
        handle = *v1;
        if (handle != 0) {
            flag = flags[handle - 1];
            if (flag == 0) {
                *v1 = 0;
            }
        }
        v1--;
    }

    readp = base;
    writep = base;
    for (i = 0; i < 16; i++) {
        s16 val = *readp;
        if (val != 0) {
            if (readp != writep) {
                *writep = val;
                *readp = 0;
            }
            writep++;
        }
        readp++;
    }
}
