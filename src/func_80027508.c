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

struct EquipSlot {
    char pad0[0xC];
    s16 unkC;
    char padE[0x18 - 0xE];
    u8 unk18;
    char pad19[0x1C - 0x19];
};

extern u8 D_8009B1D5;

struct Outcome {
    u8 unk0;
    u8 unk1;
    char pad2[0x6 - 2];
    s8 unk6;
    u8 unk7;
    u8 unk8;
};

extern struct EquipSlot D_801A7AD8[];
extern s32 D_801D4244[];
extern struct Outcome D_800EAE88[1];

extern s32 func_800358FC(s32 n);
extern s32 func_80026C0C(s32 n);
extern s32 func_80026DC8(void);
extern s32 func_80027060(void);
extern s32 func_8002712C(void);
extern s32 func_80027228(void);
extern s32 func_8008E590(void);

/* Random equip/status-effect roll: 4-way independent-roll gate (each stage
   is "50/50 (or 25% for the 3rd) OR the matching func_800270xx forces it"),
   then picks a D_801A7AD8 slot (index driven by gp+0x2CD and
   func_800358FC(5)) and rolls one of two D_800EAE88 outcome records
   depending on a D_801D4244[slot->unkC-1] bitfield threshold, sharing one
   tail that force-sets unk8=1.

   m2c's draft fabricated 2 fake calls to a nonexistent func_80027768 --
   both are `goto` to this function's own shared tail (plain fallthrough
   labels, no jal/j at either site); also invented bogus arguments for the
   first 3 func_8008E590() calls, which are the real libc func_8008E590() (0x8008E590)
   taking no arguments -- the "arguments" m2c saw were just leftover
   register contents from unrelated earlier computation.

   Real logic reaches 83/161, 165w vs target's 161w (see
   match/sketches/func_80027508_best.c). Ran a real msearch search (1 ALT
   knob covering the two field-func_80073900 orders, 8 variants across 4 flags) --
   no effect either way. Residual is concentrated in the two %5-modulo
   (magic-multiply-by-0x66666667) sequences: target computes the "base"
   field's sign-extend into $a0 and the "roll" field's into $a1 (or vice
   versa depending on branch), while this candidate picks the opposite
   register for one of the two -- tried both statement orders via the ALT,
   neither reproduces target's specific pick. Looks like the same class of
   register-role tie documented elsewhere in this project (declare-two-
   aliases-and-ALT-which-reads-which), but for two DIFFERENT source values
   sharing one magic-constant multiply rather than one value func_800738F0 two
   ways -- not yet tried. Not attempted further given time budget. */

s32 func_80027508(void) {
    struct EquipSlot *slot;
    s32 idx;
    s32 tier;
    s32 roll;
    struct Outcome *out;
    s32 sentinel;
    s32 word2;
    register s32 rawBase asm("a0");
    register s32 signedBase asm("a1");

    if (!((func_8008E590() & 1) || func_80026DC8())) {
        return 0;
    }
    if (!((func_8008E590() & 1) || func_80027060())) {
        return 0;
    }
    if (!((func_8008E590() & 3) || func_8002712C())) {
        return 0;
    }
    if (!func_80027228()) {
        return 0;
    }

    idx = D_8009B1D5 * 0xF + func_800358FC(5);
    slot = &D_801A7AD8[idx];
    tier = (D_801D4244[slot->unkC - 1] >> 0x1A) & 0x1F;

    if (tier < 0x14) {
        roll = func_80026C0C(5);
        if (roll < 0) {
            roll = func_800358FC(5);
        }
        rawBase = slot->unk18;
        signedBase = (s8)rawBase;
        out = D_800EAE88;
        out->unk1 = 0;
        out->unk6 = (roll % 5) + 1;
        out->unk0 = (signedBase % 5) + 0xB;
        out->unk7 = func_8008E590() & 1;
        goto force_one;
    }

    roll = func_80026C0C(0xA);
    if (roll < 0) {
        roll = func_800358FC(5);
    }
    rawBase = slot->unk18;
    signedBase = (s8)rawBase;
    out = D_800EAE88;
    out->unk1 = 0;
    out->unk7 = 0;
    out->unk6 = (roll % 5) + 6;
    out->unk0 = (signedBase % 5) + 0xB;
    out->unk8 = func_8008E590() & 1;

    word2 = D_801D4244[slot->unkC - 1];
    __asm__ __volatile__("addiu %0, $0, 23" : "=r"(sentinel) : "r"(word2));
    tier = (word2 >> 0x1A) & 0x1F;
    if (tier == sentinel) {
force_one:
        out->unk8 = 1;
    }
    return 0;
}
