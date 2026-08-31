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

/* Counts entries in D_801AB000[start..end] (12-byte-stride struct, f0
   s16 nonzero-check, f6 bit-0x4000 flag) matching a type-dependent rule,
   writes the count to D_800F5B98[idx2]. idx1/idx2 are cursor draws from
   func_8007058C(); type=D_800F5B98[idx1] selects a range via
   func_800707C4(type,&start,&end). Sibling of find_equip_slot_for_card.c
   (same Entry layout) and the equip_score_best_slot.c family. */

struct Entry {
    s16 f0;
    char pad[4];
    u16 f6;
    char pad2[4];
};

extern s32 D_800F5B98[];
extern struct Entry D_801AB000[];
extern s32 func_8007058C(void);
extern void func_800707C4(s32 type, s32 *start, s32 *end);

void func_80071EB8(void) {
    register s32 type asm("s0");
    register s32 count asm("s1");
    s32 *table = D_800F5B98;
    s32 idx1;
    s32 idx2;
    s32 start;
    s32 end;
    s32 i;

    idx1 = func_8007058C();
    type = table[idx1];
    idx2 = func_8007058C();
    count = 0;

    func_800707C4(type, &start, &end);

    for (i = start; i <= end; i++) {
        struct Entry *e = &D_801AB000[i];
        if (e->f0 != 0) {
            if (type == 1 || type == 3 || type == 6 || type == 8) {
                if (!(e->f6 & 0x4000)) {
                    count++;
                }
            } else {
                count++;
            }
        }
    }

    D_800F5B98[idx2] = count;
}
