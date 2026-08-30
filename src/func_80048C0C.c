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

/* Same *D_8009B45C struct as func_8004703C.c/func_8004666C.c. Scans the
   4-entry id table at 0x404; for each slot whose id matches and whose bit
   (1 << slot) is set in the 0x434 flags byte, stores val into the matching
   slot of the byte array at 0x428. No-op if val is 0. */
struct S8009B45C {
    char pad0[0x404];
    u16 ids[4];  /* 0x404 */
    char pad1[0x428 - 0x404 - 8];
    u8 vals[4];  /* 0x428 */
    char pad2[0x434 - 0x428 - 4];
    u8 flags;    /* 0x434 */
};

extern struct S8009B45C *D_8009B45C;

void func_80048C0C(u16 id, u8 val) {
    s32 i;
    u8 bit;

    if (val == 0) {
        return;
    }
    bit = 1;
    for (i = 0; i < 4; i++) {
        if (D_8009B45C->ids[i] == id && (D_8009B45C->flags & bit)) {
            D_8009B45C->vals[i] = val;
        }
        bit <<= 1;
    }
}
