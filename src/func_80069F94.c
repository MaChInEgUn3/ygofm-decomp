/* ASSEMBLY DEBT -- this is a TRANSCRIPTION, not a decompilation.
 * The body below is the retail instruction stream written out as inline
 * asm. It is byte-exact and therefore invisible to build.py, which is
 * exactly the problem: the oracle cannot tell transcribed assembly from
 * real C, so nothing but this comment stops it being counted as done.
 * Ported from Unchiga's tree, where it is tracked as known debt.
 * Rewriting it as C is open work; see docs/ASM_DEBT.md.
 */
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

/* GTE OT-insert leaf, part of the gte_ot_insert_* family (see
   gte_ot_insert_transformed_tris.c for the shared family rationale):
   pure cop2 sequences with 9+ live registers and zero jal calls, no C
   shape can emit these under gcc 2.8.1. Whole-function raw-asm
   transcription, verified byte-exact (0/85 diffs).

   Sibling of func_8006A540 (identical
   3-separate-index-word shape, stride 0x1C instead of this member's
   0x18) and func_80069E44/_r18 (packed 2-index-
   word form). Op sequence: RTPT (0x280030), AVSZ3 (0x158002d) -- no
   NCCT/NCS/NCCS at all. "_3field" marks the 3-separate-index-word form,
   mirroring gte_ot_insert_transformed_quads_4field's unpacked-vs-packed
   naming.

   Landed 2026-08-27 (w1 proposal, user-signed-off naming, executed by the
   integrator) -- previously named func_80069F94 pending the family-name
   delegation letter (gte_ot_insert_* naming is never a worker's own
   self-sign call). */
__asm__(
    ".set noreorder\n"
    ".global func_80069F94\n"
    "func_80069F94:\n"
    ".word 0x8c870000\n"   /* 80069F94: lw a3,0(a0) */
    ".word 0x8c990010\n"   /* 80069F98: lw t9,16(a0) */
    ".word 0x94f80002\n"   /* 80069F9C: lhu t8,2(a3) */
    ".word 0x8ce60004\n"   /* 80069FA0: lw a2,4(a3) */
    ".word 0x8c850014\n"   /* 80069FA4: lw a1,20(a0) */
    ".word 0x00063080\n"   /* 80069FA8: sll a2,a2,0x2 */
    ".word 0xac900020\n"   /* 80069FAC: sw s0,32(a0) */
    ".word 0xac910024\n"   /* 80069FB0: sw s1,36(a0) */
    ".word 0xac920028\n"   /* 80069FB4: sw s2,40(a0) */
    ".word 0x3c0d800a\n"   /* 80069FB8: lui t5,0x800a */
    ".word 0x8dadafe4\n"   /* 80069FBC: lw t5,-20508(t5) */
    ".word 0x13000040\n"   /* 80069FC0: beqz t8,0x8006a0c4 */
    ".word 0x00000000\n"   /* 80069FC4: nop */
    ".word 0x24010001\n"   /* 80069FC8: li at,1 */
    ".word 0x11a1003d\n"   /* 80069FCC: beq t5,at,0x8006a0c4 */
    ".word 0x00a63821\n"   /* 80069FD0: addu a3,a1,a2 */
    ".word 0x3c10800a\n"   /* 80069FD4: lui s0,0x800a */
    ".word 0x8e10afd0\n"   /* 80069FD8: lw s0,-20528(s0) */
    ".word 0x3c11800a\n"   /* 80069FDC: lui s1,0x800a */
    ".word 0x8e31afd4\n"   /* 80069FE0: lw s1,-20524(s1) */
    ".word 0x3c125555\n"   /* 80069FE4: lui s2,0x5555 */
    ".word 0x36525555\n"   /* 80069FE8: ori s2,s2,0x5555 */
    ".word 0x8c850018\n"   /* 80069FEC: lw a1,24(a0) */
    ".word 0x8c86001c\n"   /* 80069FF0: lw a2,28(a0) */
    ".word 0x8c8d0004\n"   /* 80069FF4: lw t5,4(a0) */
    ".word 0x8c8e0008\n"   /* 80069FF8: lw t6,8(a0) */
    ".word 0x8daf0004\n"   /* 80069FFC: lw t7,4(t5) */
    ".word 0x8ce8000c\n"   /* 8006A000: lw t0,12(a3) */
    ".word 0x8ce90010\n"   /* 8006A004: lw t1,16(a3) */
    ".word 0x8cea0014\n"   /* 8006A008: lw t2,20(a3) */
    ".word 0x00086c02\n"   /* 8006A00C: srl t5,t0,0x10 */
    ".word 0x000d68c0\n"   /* 8006A010: sll t5,t5,0x3 */
    ".word 0x01a56821\n"   /* 8006A014: addu t5,t5,a1 */
    ".word 0xc9a00000\n"   /* 8006A018: lwc2 $0,0(t5) */
    ".word 0xc9a10004\n"   /* 8006A01C: lwc2 $1,4(t5) */
    ".word 0x00096c02\n"   /* 8006A020: srl t5,t1,0x10 */
    ".word 0x000d68c0\n"   /* 8006A024: sll t5,t5,0x3 */
    ".word 0x01a56821\n"   /* 8006A028: addu t5,t5,a1 */
    ".word 0xc9a20000\n"   /* 8006A02C: lwc2 $2,0(t5) */
    ".word 0xc9a30004\n"   /* 8006A030: lwc2 $3,4(t5) */
    ".word 0x000a6c02\n"   /* 8006A034: srl t5,t2,0x10 */
    ".word 0x000d68c0\n"   /* 8006A038: sll t5,t5,0x3 */
    ".word 0x01a56821\n"   /* 8006A03C: addu t5,t5,a1 */
    ".word 0xc9a40000\n"   /* 8006A040: lwc2 $4,0(t5) */
    ".word 0xc9a50004\n"   /* 8006A044: lwc2 $5,4(t5) */
    ".word 0xaf310004\n"   /* 8006A048: sw s1,4(t9) */
    ".word 0xaf32001c\n"   /* 8006A04C: sw s2,28(t9) */
    ".word 0x4a280030\n"   /* 8006A050: c2 0x280030 */
    ".word 0x4842f800\n"   /* 8006A054: cfc2 v0,$31 */
    ".word 0x00000000\n"   /* 8006A058: nop */
    ".word 0x04400016\n"   /* 8006A05C: bltz v0,0x8006a0b8 */
    ".word 0x00000000\n"   /* 8006A060: nop */
    ".word 0x4b58002d\n"   /* 8006A064: c2 0x158002d */
    ".word 0x48023800\n"   /* 8006A068: mfc2 v0,$7 */
    ".word 0xaf300008\n"   /* 8006A06C: sw s0,8(t9) */
    ".word 0x01c21006\n"   /* 8006A070: srlv v0,v0,t6 */
    ".word 0x00021080\n"   /* 8006A074: sll v0,v0,0x2 */
    ".word 0x004f1021\n"   /* 8006A078: addu v0,v0,t7 */
    ".word 0x8c4d0000\n"   /* 8006A07C: lw t5,0(v0) */
    ".word 0xeb2c000c\n"   /* 8006A080: swc2 $12,12(t9) */
    ".word 0xeb2d0010\n"   /* 8006A084: swc2 $13,16(t9) */
    ".word 0xeb2e0014\n"   /* 8006A088: swc2 $14,20(t9) */
    ".word 0xeb2c0018\n"   /* 8006A08C: swc2 $12,24(t9) */
    ".word 0x000d6a00\n"   /* 8006A090: sll t5,t5,0x8 */
    ".word 0x35ad0007\n"   /* 8006A094: ori t5,t5,0x7 */
    ".word 0x000d0a02\n"   /* 8006A098: srl at,t5,0x8 */
    ".word 0x000d6e00\n"   /* 8006A09C: sll t5,t5,0x18 */
    ".word 0x01a16825\n"   /* 8006A0A0: or t5,t5,at */
    ".word 0xaf2d0000\n"   /* 8006A0A4: sw t5,0(t9) */
    ".word 0x00196a00\n"   /* 8006A0A8: sll t5,t9,0x8 */
    ".word 0x000d6a02\n"   /* 8006A0AC: srl t5,t5,0x8 */
    ".word 0xac4d0000\n"   /* 8006A0B0: sw t5,0(v0) */
    ".word 0x27390020\n"   /* 8006A0B4: addiu t9,t9,32 */
    ".word 0x2718ffff\n"   /* 8006A0B8: addiu t8,t8,-1 */
    ".word 0x1700ffd0\n"   /* 8006A0BC: bnez t8,0x8006a000 */
    ".word 0x24e70018\n"   /* 8006A0C0: addiu a3,a3,24 */
    ".word 0x8c900020\n"   /* 8006A0C4: lw s0,32(a0) */
    ".word 0x8c910024\n"   /* 8006A0C8: lw s1,36(a0) */
    ".word 0x8c920028\n"   /* 8006A0CC: lw s2,40(a0) */
    ".word 0x8c820000\n"   /* 8006A0D0: lw v0,0(a0) */
    ".word 0x3c018010\n"   /* 8006A0D4: lui at,0x8010 */
    ".word 0xac39e240\n"   /* 8006A0D8: sw t9,-7616(at) */
    ".word 0x24420008\n"   /* 8006A0DC: addiu v0,v0,8 */
    ".word 0x03e00008\n"   /* 8006A0E0: jr ra */
    ".word 0x00000000\n"   /* 8006A0E4: nop */
    ".set reorder\n"
);
