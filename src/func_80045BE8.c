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

/* MATCHED 0/44, G0:nosplit (claude-w2, 2026-08-28).
 * CORRECTION TO ITS BLACKLIST REASON, which calls this a
 * leaf_tail_branch_group member and "not a callable C function".  It has
 * NINE jal callers in the ROM -- it is unambiguously a called function.
 * The reason's structural observation is accurate and its conclusion is
 * not: the branch at 0x80045C00 does jump into the separate F entry
 * 0x80045C90, but that entry is the two-instruction `jr ra; move v0,zero`
 * return-0 tail this function owns, exactly the shape WORKFLOW tells
 * workers to fold in with --exclude.  Put the `return 0` textually LAST in
 * the source and gcc emits the branch and the shared tail by itself.
 *
 * Appends one 0x30-byte record to D_8009B45C's queue at +0x80 (0x30 stride,
 * count s16 at +0x4C, capacity 0x10) and returns 1; returns 0 when full.
 * The 0x30-byte copy is a struct assignment, which gcc 2.8.1 expands to its
 * four-register block-move LOOP. */

typedef struct { s32 w[12]; } Blk48;

extern u8 *D_8009B45C;
extern u8 *D_8009B45C;
extern u8 *D_8009B45C;

s32 func_80045BE8(Blk48 *src) {
    u8 *b1;
    u8 *b2;
    u8 *b3;
    s32 n1;
    s32 n2;
    s32 one;

    b1 = D_8009B45C;
    n1 = *(s16 *)(b1 + 0x4C);
    if (n1 >= 0x10) {
        goto full;
    }
    {
        u8 *d = b1 + n1 * 48;
        d[0x80] = *(u8 *)src;
    }

    b2 = D_8009B45C;
    n2 = *(s16 *)(b2 + 0x4C);
    {
        u8 *d = b2 + n2 * 48;
        *(Blk48 *)(d + 0x80) = *src;
    }

    b3 = D_8009B45C;
    one = 1;
    *(u16 *)(b3 + 0x4C) = *(u16 *)(b3 + 0x4C) + one;
    return one;
full:
    return 0;
}
