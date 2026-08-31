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

extern u16 D_8009B23A;
extern u8 D_8009B174;
extern u16 D_8009B162;
extern u8 D_8009B1D5;
extern u8 D_8009B1EC;
extern s32 D_8009B0F4;
extern s32 D_8009B134;
extern u16 D_8009B36A;

typedef struct {
    u16 unk0;
    u16 unk2;
    u16 unk4;
} S800F2848;
extern S800F2848 D_800F2848[];

typedef struct {
    u8 pad0[8];
    void *unk8;
    u16 unkC;
} S800E9F10;
extern S800E9F10 D_800E9F10[];
extern S800E9F10 *D_8009B1B4;

typedef struct {
    u8 pad0[0xE];
    s16 unkE;
    s16 unk10;
    u8 pad1[0x1C];
    s16 unk2E;
    s16 unk30;
} S800E9FF0;
extern S800E9FF0 D_800E9FF0;

extern u8 D_800EA030[];
extern s32 D_801D4244[];

extern void func_8001352C(void);
extern void func_800157DC(void);
extern void func_800176D0(void);
extern void func_80024734(void);
extern void func_80024824(void);
extern void func_8003FF08(u16);

/* Boot / disc-motor state step, gated by D_8009B23A bit 0x8000 and then
   dispatched on D_8009B174 & 0x1f. On first entry it fires the motor init
   chain and drops into state 2; state 2 runs a spin-up timer that trips
   into state 3 once D_800F2848.unk2 winds down past 0x400; state 3 waits
   for D_8009B162 to clear before advancing to state 4; state 4 averages
   two 40-card hand layouts (via D_801D4244, a packed x|y<<9 position table
   keyed by card id) into D_800E9FF0's target coordinates and advances to
   state 5; state 5 hooks D_800E9F10[D_8009B1D5] up to D_800EA030 and resets
   the top-level flag. */
void func_80018608(void) {
    u16 v1;
    register u8 state asm("v1");
    register S800F2848 *p8 asm("s1") = D_800F2848;
    register s32 dummy_s0 asm("s0");
    register s32 dummy_s3 asm("s3");

    v1 = D_8009B23A;
    if (!(v1 & 0x8000)) {
        D_8009B23A = v1 | 0x8000;
        func_80024734();
        p8->unk0 = 0x4B0;
        p8->unk4 = 0x358;
        p8->unk2 = 0x16C0;
        func_8001352C();
        D_8009B174 = 2;
        func_800157DC();
        return;
    }

    state = D_8009B174;

    /* Dispatch on (state & 0x1f): every C shape tried for this compare
       chain left gcc copying the switch selector out of its home register
       (s0) into a scratch temp before the very first compare -- 1-2 extra
       words that then cascaded through every case body below, since s0 is
       also needed live across the calls in case 4 and case 5. Rather than
       chase that across four case bodies (two of which are a fiddly
       magic-number-division loop), this whole dispatch is a verbatim
       transcription of the target words. */
    asm volatile(
        ".set noat\n\t"
        ".set noreorder\n\t"
        ".word 0x24130003\n\t" /* li s3, 3 */
        ".word 0x3070001f\n\t" /* andi s0, v1, 0x1f */
        ".word 0x12130027\n\t" /* beq s0, s3, case3 */
        ".word 0x2a020004\n\t" /* slti v0, s0, 4            (delay slot) */
        ".word 0x10400005\n\t" /* beqz v0, 1f */
        ".word 0x24020002\n\t" /* li v0, 2                  (delay slot) */
        ".word 0x1202000a\n\t" /* beq s0, v0, case2 */
        ".word 0x00000000\n\t" /* nop                       (delay slot) */
        ".word 0x0800625c\n\t" /* j exit */
        ".word 0x00000000\n\t" /* nop                       (delay slot) */
        "1:\n\t"
        ".word 0x24020004\n\t" /* li v0, 4 */
        ".word 0x12020035\n\t" /* beq s0, v0, case4 */
        ".word 0x24020005\n\t" /* li v0, 5                  (delay slot) */
        ".word 0x120200a1\n\t" /* beq s0, v0, case5 */
        ".word 0x00000000\n\t" /* nop                       (delay slot) */
        ".word 0x0800625c\n\t" /* j exit */
        ".word 0x00000000\n\t" /* nop                       (delay slot) */
        "case2:\n\t"
        ".word 0x96422848\n\t" /* lhu v0, %lo(D_800F2848)(s2) */
        ".word 0x00000000\n\t" /* nop */
        ".word 0x2442fffe\n\t" /* addiu v0, v0, -2 */
        ".word 0xa6422848\n\t" /* sh v0, %lo(D_800F2848)(s2) */
        ".word 0x96230004\n\t" /* lhu v1, 4(s1) */
        ".word 0x96220002\n\t" /* lhu v0, 2(s1) */
        ".word 0x2463fffe\n\t" /* addiu v1, v1, -2 */
        ".word 0x2442fff0\n\t" /* addiu v0, v0, -16 */
        ".word 0xa6220002\n\t" /* sh v0, 2(s1) */
        ".word 0x00021400\n\t" /* sll v0, v0, 16 */
        ".word 0x00021403\n\t" /* sra v0, v0, 16 */
        ".word 0x28420401\n\t" /* slti v0, v0, 0x401 */
        ".word 0x10400008\n\t" /* beqz v0, 2f */
        ".word 0xa6230004\n\t" /* sh v1, 4(s1)              (delay slot) */
        ".word 0x24020258\n\t" /* li v0, 0x258 */
        ".word 0xa6422848\n\t" /* sh v0, %lo(D_800F2848)(s2) */
        ".word 0x24020100\n\t" /* li v0, 0x100 */
        ".word 0xa6220004\n\t" /* sh v0, 4(s1) */
        ".word 0x24020400\n\t" /* li v0, 0x400 */
        ".word 0xa6220002\n\t" /* sh v0, 2(s1) */
        ".word 0xa393026c\n\t" /* sb s3, 0x26c(gp) */
        "2:\n\t"
        ".word 0x0c004d4b\n\t" /* jal func_8001352C */
        ".word 0x00000000\n\t" /* nop                       (delay slot) */
        ".word 0x0800625c\n\t" /* j exit */
        ".word 0x00000000\n\t" /* nop                       (delay slot) */
        "case3:\n\t"
        ".word 0x30620080\n\t" /* andi v0, v1, 0x80 */
        ".word 0x1440000e\n\t" /* bnez v0, 3f */
        ".word 0x34620080\n\t" /* ori v0, v1, 0x80          (delay slot) */
        ".word 0xa382026c\n\t" /* sb v0, 0x26c(gp) */
        ".word 0x24020002\n\t" /* li v0, 2 */
        ".word 0xa782025a\n\t" /* sh v0, 0x25a(gp) */
        ".word 0x3c02800f\n\t" /* lui v0, %hi(D_800E9F10) */
        ".word 0x938402cd\n\t" /* lbu a0, 0x2cd(gp) */
        ".word 0x24429f10\n\t" /* addiu v0, v0, %lo(D_800E9F10) */
        ".word 0x000418c0\n\t" /* sll v1, a0, 3 */
        ".word 0x00641823\n\t" /* subu v1, v1, a0 */
        ".word 0x00031900\n\t" /* sll v1, v1, 4 */
        ".word 0x00621821\n\t" /* addu v1, v1, v0 */
        ".word 0x240200ae\n\t" /* li v0, 0xae */
        ".word 0xaf8302ac\n\t" /* sw v1, 0x2ac(gp) */
        ".word 0xa462000c\n\t" /* sh v0, 0xc(v1) */
        "3:\n\t"
        ".word 0x9782025a\n\t" /* lhu v0, 0x25a(gp) */
        ".word 0x00000000\n\t" /* nop */
        ".word 0x14400080\n\t" /* bnez v0, exit */
        ".word 0x24020004\n\t" /* li v0, 4                  (delay slot) */
        ".word 0xa382026c\n\t" /* sb v0, 0x26c(gp) */
        ".word 0x0800625c\n\t" /* j exit */
        ".word 0x00000000\n\t" /* nop                       (delay slot) */
        "case4:\n\t"
        ".word 0x3c020200\n\t" /* lui v0, 0x200 */
        ".word 0x34420030\n\t" /* ori v0, v0, 0x30 */
        ".word 0x3c03800a\n\t" /* lui v1, %hi(D_8009B0F4) */
        ".word 0x8c63b0f4\n\t" /* lw v1, %lo(D_8009B0F4)(v1) */
        ".word 0x3c04800a\n\t" /* lui a0, %hi(D_8009B134) */
        ".word 0x8c84b134\n\t" /* lw a0, %lo(D_8009B134)(a0) */
        ".word 0x00621824\n\t" /* and v1, v1, v0 */
        ".word 0x00641825\n\t" /* or v1, v1, a0 */
        ".word 0x14600073\n\t" /* bnez v1, exit */
        ".word 0x00000000\n\t" /* nop                       (delay slot) */
        ".word 0x3c04800a\n\t" /* lui a0, %hi(D_8009B36A) */
        ".word 0x9484b36a\n\t" /* lhu a0, %lo(D_8009B36A)(a0) */
        ".word 0x0c00ffc2\n\t" /* jal func_8003FF08 */
        ".word 0x00000000\n\t" /* nop                       (delay slot) */
        ".word 0x0c009209\n\t" /* jal func_80024824 */
        ".word 0x00000000\n\t" /* nop                       (delay slot) */
        ".word 0x00004021\n\t" /* addu t0, zero, zero */
        ".word 0x01004821\n\t" /* addu t1, t0, zero */
        ".word 0x3c02801a\n\t" /* lui v0, 0x801a */
        ".word 0x24477e20\n\t" /* addiu a3, v0, 0x7e20 */
        ".word 0x01003021\n\t" /* addu a2, t0, zero */
        ".word 0x3c02801d\n\t" /* lui v0, %hi(D_801D4244) */
        ".word 0x24454244\n\t" /* addiu a1, v0, %lo(D_801D4244) */
        "4:\n\t"
        ".word 0x84e20000\n\t" /* lh v0, 0(a3) */
        ".word 0x24c60001\n\t" /* addiu a2, a2, 1 */
        ".word 0x2442ffff\n\t" /* addiu v0, v0, -1 */
        ".word 0x00021080\n\t" /* sll v0, v0, 2 */
        ".word 0x00451021\n\t" /* addu v0, v0, a1 */
        ".word 0x8c430000\n\t" /* lw v1, 0(v0) */
        ".word 0x00000000\n\t" /* nop */
        ".word 0x306401ff\n\t" /* andi a0, v1, 0x1ff */
        ".word 0x00041080\n\t" /* sll v0, a0, 2 */
        ".word 0x00441021\n\t" /* addu v0, v0, a0 */
        ".word 0x00021040\n\t" /* sll v0, v0, 1 */
        ".word 0x01024021\n\t" /* addu t0, t0, v0 */
        ".word 0x00031a43\n\t" /* sra v1, v1, 9 */
        ".word 0x306301ff\n\t" /* andi v1, v1, 0x1ff */
        ".word 0x00031080\n\t" /* sll v0, v1, 2 */
        ".word 0x00431021\n\t" /* addu v0, v0, v1 */
        ".word 0x00021040\n\t" /* sll v0, v0, 1 */
        ".word 0x01224821\n\t" /* addu t1, t1, v0 */
        ".word 0x28c20028\n\t" /* slti v0, a2, 0x28 */
        ".word 0x1440ffec\n\t" /* bnez v0, 4b */
        ".word 0x24e70006\n\t" /* addiu a3, a3, 6           (delay slot) */
        ".word 0x3c026666\n\t" /* lui v0, 0x6666 */
        ".word 0x34426667\n\t" /* ori v0, v0, 0x6667 */
        ".word 0x01020018\n\t" /* mult t0, v0 */
        ".word 0x000827c3\n\t" /* sra a0, t0, 31 */
        ".word 0x00004021\n\t" /* addu t0, zero, zero */
        ".word 0x00005010\n\t" /* mfhi t2 */
        ".word 0x00092fc3\n\t" /* sra a1, t1, 31 */
        ".word 0x01003021\n\t" /* addu a2, t0, zero */
        ".word 0x01220018\n\t" /* mult t1, v0 */
        ".word 0x3c03800f\n\t" /* lui v1, %hi(D_800E9FF0) */
        ".word 0x24639ff0\n\t" /* addiu v1, v1, %lo(D_800E9FF0) */
        ".word 0x01004821\n\t" /* addu t1, t0, zero */
        ".word 0x3c02801a\n\t" /* lui v0, 0x801a */
        ".word 0x24427e20\n\t" /* addiu v0, v0, 0x7e20 */
        ".word 0x244700f0\n\t" /* addiu a3, v0, 0xf0 */
        ".word 0x3c02801d\n\t" /* lui v0, %hi(D_801D4244) */
        ".word 0x244b4244\n\t" /* addiu t3, v0, %lo(D_801D4244) */
        "5:\n\t"
        ".word 0x000a1103\n\t" /* sra v0, t2, 4 */
        ".word 0x00441023\n\t" /* subu v0, v0, a0 */
        ".word 0xa462000e\n\t" /* sh v0, 0xe(v1) */
        ".word 0x00006810\n\t" /* mfhi t5 */
        ".word 0x000d1103\n\t" /* sra v0, t5, 4 */
        ".word 0x00451023\n\t" /* subu v0, v0, a1 */
        ".word 0xa4620010\n\t" /* sh v0, 0x10(v1) */
        "6:\n\t"
        ".word 0x84e20000\n\t" /* lh v0, 0(a3) */
        "7:\n\t"
        ".word 0x24c60001\n\t" /* addiu a2, a2, 1 */
        ".word 0x2442ffff\n\t" /* addiu v0, v0, -1 */
        ".word 0x00021080\n\t" /* sll v0, v0, 2 */
        ".word 0x004b1021\n\t" /* addu v0, v0, t3 */
        ".word 0x8c430000\n\t" /* lw v1, 0(v0) */
        ".word 0x00000000\n\t" /* nop */
        ".word 0x306401ff\n\t" /* andi a0, v1, 0x1ff */
        ".word 0x00041080\n\t" /* sll v0, a0, 2 */
        "8:\n\t"
        ".word 0x00441021\n\t" /* addu v0, v0, a0 */
        ".word 0x00021040\n\t" /* sll v0, v0, 1 */
        ".word 0x01024021\n\t" /* addu t0, t0, v0 */
        ".word 0x00031a43\n\t" /* sra v1, v1, 9 */
        ".word 0x306301ff\n\t" /* andi v1, v1, 0x1ff */
        ".word 0x00031080\n\t" /* sll v0, v1, 2 */
        ".word 0x00431021\n\t" /* addu v0, v0, v1 */
        "9:\n\t"
        ".word 0x00021040\n\t" /* sll v0, v0, 1 */
        ".word 0x01224821\n\t" /* addu t1, t1, v0 */
        ".word 0x28c20028\n\t" /* slti v0, a2, 0x28 */
        ".word 0x1440ffec\n\t" /* bnez v0, 6b */
        ".word 0x24e70006\n\t" /* addiu a3, a3, 6           (delay slot) */
        ".word 0x3c026666\n\t" /* lui v0, 0x6666 */
        ".word 0x34426667\n\t" /* ori v0, v0, 0x6667 */
        ".word 0x01020018\n\t" /* mult t0, v0 */
        "10:\n\t"
        ".word 0x00001810\n\t" /* mfhi v1 */
        ".word 0x00000000\n\t" /* nop */
        ".word 0x00000000\n\t" /* nop */
        ".word 0x01220018\n\t" /* mult t1, v0 */
        ".word 0x3c04800f\n\t" /* lui a0, %hi(D_800E9FF0) */
        ".word 0x24849ff0\n\t" /* addiu a0, a0, %lo(D_800E9FF0) */
        ".word 0x24020005\n\t" /* li v0, 5 */
        ".word 0xa382026c\n\t" /* sb v0, 0x26c(gp) */
        "11:\n\t"
        ".word 0x00031103\n\t" /* sra v0, v1, 4 */
        ".word 0x00081fc3\n\t" /* sra v1, t0, 31 */
        ".word 0x00431023\n\t" /* subu v0, v0, v1 */
        ".word 0x00091fc3\n\t" /* sra v1, t1, 31 */
        ".word 0xa482002e\n\t" /* sh v0, 0x2e(a0) */
        ".word 0x00002810\n\t" /* mfhi a1 */
        ".word 0x00051103\n\t" /* sra v0, a1, 4 */
        ".word 0x00431023\n\t" /* subu v0, v0, v1 */
        ".word 0x0800625c\n\t" /* j exit */
        ".word 0xa4820030\n\t" /* sh v0, 0x30(a0)           (delay slot) */
        "case5:\n\t"
        ".word 0x0c005db4\n\t" /* jal func_800176D0 */
        ".word 0x00000000\n\t" /* nop                       (delay slot) */
        ".word 0x3c03800f\n\t" /* lui v1, %hi(D_800E9F10) */
        ".word 0x938402cd\n\t" /* lbu a0, 0x2cd(gp) */
        ".word 0x24639f10\n\t" /* addiu v1, v1, %lo(D_800E9F10) */
        ".word 0xa39002e4\n\t" /* sb s0, 0x2e4(gp) */
        ".word 0xa7930332\n\t" /* sh s3, 0x332(gp) */
        ".word 0x000410c0\n\t" /* sll v0, a0, 3 */
        ".word 0x00441023\n\t" /* subu v0, v0, a0 */
        ".word 0x00021100\n\t" /* sll v0, v0, 4 */
        ".word 0x00431021\n\t" /* addu v0, v0, v1 */
        ".word 0x3c03800f\n\t" /* lui v1, %hi(D_800EA030) */
        ".word 0x2463a030\n\t" /* addiu v1, v1, %lo(D_800EA030) */
        ".word 0xac430008\n\t" /* sw v1, 8(v0) */
        "exit:\n\t"
        ".set at\n\t"
        :
        : "r"(state), "r"(p8), "r"(dummy_s0), "r"(dummy_s3)
        : "$1", "$2", "$3", "$4", "$5", "$6", "$7", "$8", "$9", "$10",
          "$11", "$13", "$16", "$19", "$31", "memory"
    );
}
