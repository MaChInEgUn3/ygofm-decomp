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

/* Same *D_8009B458 struct as func_80049600.c (f510 = item
   count, 1..20). Walks the 0x28-byte item array starting at offset 0x180
   and, for each item whose durability (f1E) is non-zero and whose type
   byte (f3) is below 0x10, decrements the durability by 1; otherwise
   resets it to 0. */
struct Item {
    char pad[3];
    u8 f3;
    char pad2[0x1E - 4];
    u16 f1E;
    char pad3[0x28 - 0x20];
};

struct S8009B458 {
    char pad0[0x180];
    struct Item items[20];
    char pad1[0x510 - (0x180 + 20 * 0x28)];
    s16 f510;
};

extern struct S8009B458 *D_8009B458;

void func_8004C84C(void) {
    s32 i;

    for (i = 0; i < D_8009B458->f510; i++) {
        struct Item *item = &D_8009B458->items[i];
        if (item->f1E != 0 && item->f3 < 0x10) {
            item->f1E -= 1;
        } else {
            item->f1E = 0;
        }
    }
}
