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

/* D_800EFE38[a1]/D_800F2878[a1] are the per-category (0..6) linked-list
   head / fallback-slot tables that func_800400AC.c reads and
   writes (see run_D_800EFE38_callback_list.c for the D_800EFE38 walk).
   Resets both to -1 for every category, zeroes the two call counters at
   D_8009B410/D_8009B412, then clears the 0x80-status-bit field (f8, u16 at
   offset 8 in the 0x70-byte Slot struct from func_800400AC.c)
   for all 96 pool slots so get_or_init treats every slot as uninitialized. */
extern s16 D_800EFE38[];
extern s16 D_800F2878[];
extern u16 D_8009B410;
extern u16 D_8009B412;

typedef struct {
    u8 pad0[8];
    u16 f8;
    u8 pad10[0x70 - 0xA];
} Slot;

extern Slot D_800EFE48[];

void func_80040390(void) {
    /* i/val pinned to their target hardware registers: pinning is what
       makes gcc schedule the two single-instruction setups (i=0, val=-1)
       BEFORE the two lui/addiu address computations below -- unpinned,
       every declaration/statement ordering tried func_8008FAF0 the address
       computations first instead (see config/blacklist.txt history for
       this address). The two pointers are left as plain locals: pinning
       them too makes gcc materialize their lui directly into the pinned
       register instead of the scratch v0 the target uses. */
    register s32 i asm("v1");
    register s16 val asm("a2");
    s16 *p2878;
    s16 *pefe38;
    s32 j;
    Slot *rec;

    i = 0;
    val = -1;
    p2878 = D_800F2878;
    pefe38 = D_800EFE38;
    D_8009B410 = 0;
    D_8009B412 = 0;

    /* pefe38's increment is deferred into the loop-branch's delay slot by
       giving it as the SECOND part of the for-loop's increment clause;
       p2878's increment stays inline in the body right after its store. */
    for (; i < 7; i++, pefe38++) {
        *pefe38 = val;
        *p2878 = val;
        p2878++;
    }

    rec = D_800EFE48;
    for (j = 95; j >= 0; j--, rec++) {
        rec->f8 = 0;
    }
}
