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

/* Manifest mis-split: function_ranges.txt cuts this into 4 F entries
   (func_8004CABC + func_8004CAE0 + func_8004CAF8 + func_8004CB04); the
   inner two end in a bare `beq`/`jr $ra` with no separate epilogue, so
   nothing else in the ROM calls them standalone. Absorbed here via
   --exclude 0x8004CAE0 0x8004CAF8 0x8004CB04.

   Walks D_8009B458's record[count@0x7FA] array (records start at offset
   0x53C, stride 0x2C, flag byte at offset 0 of each record) checking
   that every record's flag == 1: returns 3 if count is 0 or every
   record checked is flagged, 1 as soon as an unflagged record is found. */
struct S8009B458 {
    char pad[0x7FA];
    u16 f7FA;
};

extern struct S8009B458 *D_8009B458;

s32 func_8004CABC(void) {
    register u8 *a0 asm("a0");
    register s32 v0 asm("v0");

    a0 = (u8 *) D_8009B458;
    v0 = ((struct S8009B458 *) a0)->f7FA;
    if (v0 == 0) {
        goto ret3;
    }
    {
        register s32 v1 asm("v1") = 0;
        register s32 a2 asm("a2") = 1;
        register s32 a1 asm("a1") = v0;

        for (;;) {
            u8 flag = *(a0 + 0x53C);
            v1 = v1 + 1;
            if (flag != a2) {
                return 1;
            }
            if (v1 >= a1) {
                goto ret3;
            }
            a0 += 0x2C;
        }
    }
ret3:
    return 3;
}
