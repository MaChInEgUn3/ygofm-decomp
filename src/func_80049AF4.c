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

/* Sibling of func_80049BAC.c (74.7% coddog match, same S8009B458 struct
   and near-identical logic shape): D_8009B458->f500=1; if(f7E0==-1) {
   f500=0; return; } f7EC=0x10000; f7DC=f7E8; func_8004C77C(D_8009B458);
   then a==0 -> f7E2=4, else f502=1;f7E2=1; then f500=0 unconditionally.
   func_8004C77C(D_8009B458*) confirmed via func_80049BAC.c's own header.

   Rebuilt from the blacklist note's fully-solved logic (sketch lost).
   Recorded residual: "clean 2-way register-role swap, param vs the
   shared literal 1". CORRECTION on inspection of the raw scout dossier
   disassembly (ground truth): the ACTUAL target bytes show `addu
   $s0,$a0,$zero` (param -> s0) BEFORE `addiu $s1,$zero,1` (constant ->
   s1) -- i.e. param IS in s0 and the constant IS in s1 in the real ROM,
   the OPPOSITE of what the old note's prose describes ("target keeps the
   parameter in s1 ... constant ... in s0"). The note's target/candidate
   labels look swapped; every pin attempt recorded there would have been
   fighting the wrong direction. Applying the sibling's proven fresh-
   pointer-alias-per-reload convention (6 separate lui+lw reload sites in
   the raw disasm, matching func_80049BAC.c's _b/_c/_d pattern) with a
   PLAIN, unpinned `one` local for the shared literal. */

struct S8009B458 {
    char pad0[0x500];
    u8 field500;
    char pad501[0x502 - 0x501];
    u8 field502;
    char pad503[0x7DC - 0x503];
    u32 field7DC;
    s16 field7E0;
    u16 field7E2;
    char pad7E4[0x7E8 - 0x7E4];
    u32 field7E8;
    u32 field7EC;
};

extern struct S8009B458 *D_8009B458;
extern struct S8009B458 *D_8009B458;
extern struct S8009B458 *D_8009B458;
extern struct S8009B458 *D_8009B458;
extern struct S8009B458 *D_8009B458;
extern struct S8009B458 *D_8009B458;
extern void func_8004C77C(struct S8009B458 *a0);

void func_80049AF4(s32 a0) {
    register s32 one asm("s1") = 1;

    D_8009B458->field500 = one;

    if (D_8009B458->field7E0 == -1) {
        D_8009B458->field500 = 0;
        return;
    }
    D_8009B458->field7EC = 0x10000;
    D_8009B458->field7DC = D_8009B458->field7E8;
    func_8004C77C(D_8009B458);

    if ((a0 & 0xFF) == 0) {
        D_8009B458->field7E2 = 4;
    } else {
        D_8009B458->field502 = one;
        D_8009B458->field7E2 = 1;
    }

    D_8009B458->field500 = 0;
}
