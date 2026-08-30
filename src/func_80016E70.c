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

/* Draws the paired digit-sprite readout for both players' D_800E9FF0 slots.
   D_8009B1D5 selects which side (0 or 1) currently renders in the "active"
   grey shade (0x808080) vs the dim shade (0x404040); the other side always
   gets the opposite shade. Each side draws two digit groups (4-digit then
   2-digit) offset from the shared position struct at arg0->unk50, using
   field12/field18 from the corresponding D_800E9FF0 entry as the value. */

struct WidgetEntry {
    u8 pad0[0x12];
    s16 field12;
    s16 field14;
    u8 pad1[0x18 - 0x16];
    s8 field18;
    u8 pad2[0x20 - 0x19];
};

struct Pos {
    u8 pad0[0x30];
    u16 unk30;
    u16 unk32;
};

struct Widget {
    u8 pad0[0x50];
    struct Pos *unk50;
};

/* GPU packet scratch buffer used to feed func_80016D2C. */
struct DigitPacket {
    u32 unk0;
    u16 unk4;
    u16 unk6;
    u32 unk8;
    u16 unkC;
    u16 unkE;
    u32 unk10;
    u32 unk14;
};

extern struct WidgetEntry D_800E9FF0[2];
extern u8 D_8009B1D5;
void func_80016DDC(struct WidgetEntry *);
void func_80016D2C(void *, void *, s32, s32);

#define SCRATCH ((struct DigitPacket *) 0x1F800320)

void func_80016E70(struct Widget *arg0) {
    struct Pos *pos;
    struct DigitPacket *scratch;
    register u32 tmp10 asm("v1");

    func_80016DDC(&D_800E9FF0[0]);
    func_80016DDC(&D_800E9FF0[1]);
    pos = arg0->unk50;

    scratch = SCRATCH;
    tmp10 = 0xF10100;
    scratch->unk10 = tmp10;
    scratch->unk0 = 0x09000000;
    scratch->unkC = 0x1E;
    scratch->unkE = 0x5800;
    scratch->unk8 = 0x80008;
    scratch->unk14 = 0x808080;
    if (D_8009B1D5 == 0) {
        scratch->unk14 = 0x404040;
    }

    scratch->unk4 = pos->unk30 - 3;
    scratch->unk6 = pos->unk32 - 0xD;
    func_80016D2C(pos, scratch, D_800E9FF0[1].field12, 4);

    scratch->unk4 = pos->unk30 + 0xE;
    scratch->unk6 = pos->unk32 - 5;
    func_80016D2C(pos, scratch, 0x28 - D_800E9FF0[1].field18, 2);

    scratch->unk14 = 0x808080;
    if (D_8009B1D5 != 0) {
        scratch->unk14 = 0x404040;
    }

    scratch->unk4 = pos->unk30 - 3;
    scratch->unk6 = pos->unk32 + 0xD;
    func_80016D2C(pos, scratch, D_800E9FF0[0].field12, 4);

    scratch->unk4 = pos->unk30 + 0xE;
    scratch->unk6 = pos->unk32 + 5;
    func_80016D2C(pos, scratch, 0x28 - D_800E9FF0[0].field18, 2);
}
