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

/* function_ranges.txt boundary bug: 0x80030D5C is listed as its own
   1-instruction "function" (just the leading `lbu $v1, 0x3E3($gp)`), but
   that load feeds directly into the very next instruction's `andi`/branch
   at 0x80030D64 -- it is this function's real entry point, not a separate
   one. Landed as a single unit spanning both F entries (0x80030D5C folds
   in 0x80030D60 via --exclude). */

extern u8 D_80090D44[];
extern u8 D_8009B2EB;
extern u16 D_8009B2C8;
extern u32 D_8009B0F4[4];

extern void func_80030250(u32 a0, int a1, int a2, int a3, int a4, int a5, int a6);
extern s32 func_80030294(void);
extern void func_8003594C(s32 a0);

/* Sibling of func_80030CB0: same one-time-init guard (bit
   0x80 of D_8009B2EB) around func_80030250, but adds a
   second guard (bit 0x40) that, once set, just checks the duel-pending
   mask D_8009B0F4 and clears itself instead of re-polling. Before that bit
   is set, polls func_80030294(): a zero result means "still pending" (do
   nothing), negative clears the init guard, and positive notifies via
   func_8003594C(D_8009B2C8) and sets the 0x40 bit. */
void func_80030D5C(void) {
    u8 flags = D_8009B2EB;

    if (!(flags & 0x80)) {
        D_8009B2EB = flags | 0x80;
        D_8009B2C8 = 0;
        func_80030250((u32)D_80090D44, 0x1D, 0, 0, 5, 2, 1);
    }

    {
        u8 flags2 = D_8009B2EB;
        if (flags2 & 0x40) {
            u32 val = D_8009B0F4[0];
            asm volatile("" ::: "memory");
            if (val & 0x2000000) {
                return;
            }
            D_8009B2EB = flags2 & 0xBF;
            return;
        }
    }

    {
        s32 result = func_80030294();
        if (result == 0) {
            return;
        }
        if (result < 0) {
            D_8009B2EB = 0;
            return;
        }
    }

    func_8003594C(D_8009B2C8);
    {
        u8 flags3 = D_8009B2EB;
        D_8009B2EB = flags3 | 0x40;
    }
}
