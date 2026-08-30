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

/* Same 80-entry table and layout as table_insert_800f5918.c. */
struct Entry {
    s32 val;    /* 0x0 */
    s32 key;    /* 0x4 */
};

extern struct Entry D_800F5918[80];

/* Sentinel value some caller passes for "no match possible"; short-circuits
   without touching the table. Address of a PSY-Q LIBHMD.LIB structure
   (func_80089E20), used here only as a magic pointer value, not for its
   library contents. */
extern s32 func_80089E20[];

/* Reverse lookup: finds the entry whose val matches, returns its key (or -1
   if val is the sentinel, or if no entry matches after scanning all 80). */
s32 func_800601D0(s32 val) {
    struct Entry *e = D_800F5918;
    s32 i;
    if (val == (s32) func_80089E20) {
        return -1;
    }
    for (i = 0; i < 80; i++, e++) {
        if (e->val == val) {
            return e->key;
        }
    }
    return -1;
}
