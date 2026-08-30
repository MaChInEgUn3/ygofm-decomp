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

/* Same *D_8009B45C struct/entry layout as func_80045114.c (arr[16], stride
   0x30, f0 at offset 0). */
struct Entry {
    u8 f0;
    u8 pad[0x30 - 1];
};

struct S8009B45C {
    char pad0[0x4C];
    s16 f4C;    /* entry count */
    char pad1[0x80 - 0x4E];
    struct Entry arr[16];
};

extern struct S8009B45C *D_8009B45C;

/* Scans entries [1, count) for one carrying a space (0x20), the 0x11
   CD-track marker, or a '$' (0x24) in f0; returns 1 on the first hit. */
s32 func_80045484(void) {
    s32 i;

    for (i = 1; i < D_8009B45C->f4C; i++) {
        s32 c = D_8009B45C->arr[i].f0;
        if (c == 0x20) {
            goto found;
        }
        if (c < 0x21) {
            if (c == 0x11) {
                goto found;
            }
            continue;
        } else {
            if (c != 0x24) {
                continue;
            }
        }
    found:
        return 1;
    }
    return 0;
}
