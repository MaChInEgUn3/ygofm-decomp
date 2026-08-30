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

/* Scans D_8009B458's inventory slots (44 bytes each) for the entry with
   the lowest qty (offset 0x19E) matching itemId (offset 0x183) that has
   its 0x18D flag set, returning its index or -1 if none qualify. */

struct Container {
    char pad0[0x510];
    s16 count;
};

extern struct Container *D_8009B458;

s32 func_8004A854(u8 itemId) {
    s32 bestIdx = -1;
    u32 bestQty;
    s32 i;

    __asm__("li %0, 0xffff" : "=r" (bestQty));

    for (i = 0; i < D_8009B458->count; i++) {
        u8 *e = (u8 *)D_8009B458 + i * 0x28;
        u16 qty = *(u16 *)(e + 0x19E);

        if ((bestQty & 0xFFFF) >= qty && *(u8 *)(e + 0x183) == itemId && *(u8 *)(e + 0x18D)) {
            bestQty = qty;
            bestIdx = i;
        }
    }

    return bestIdx;
}
