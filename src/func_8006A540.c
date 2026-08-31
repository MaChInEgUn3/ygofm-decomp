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

   Sibling of func_80069F94 (identical
   3-separate-index-word shape, stride 0x18 instead of this member's
   0x1C) and func_80069E44/_r18 (packed 2-index-
   word form). Op sequence: RTPT (0x280030), AVSZ3 (0x158002d) -- the
   second op was originally mislabeled NCLIP in an early draft of this
   comment; corrected 2026-08-27 (w1) to match
   gte_ot_insert_transformed_tris.c's own disassembly labeling. No
   NCCT/NCS/NCCS at all, leaner than even the unsuffixed
   gte_ot_insert_transformed_tris.c (which calls nccs) -- transforms 3
   vertices then constructs the OT tag word directly (a literal 0x7 via
   shift/or), the same pattern the plain transformed_tris base uses, not
   a distinguishing "notag" feature.

   "flat" marks this leaf's no-lighting-at-all shape; "_3field" marks the
   3-separate-index-word form, mirroring
   gte_ot_insert_transformed_quads_4field's unpacked-vs-packed naming;
   "_r1C" is a factual stride note (this member's record stride is 0x1C
   vs its 3field pair-mate's 0x18), not a claimed semantic difference.

   Landed 2026-08-27 (w1 proposal, user-signed-off naming, executed by the
   integrator) -- previously named func_8006A540 pending the family-name
   delegation letter (gte_ot_insert_* naming is never a worker's own
   self-sign call; caught by the Overseer/user 2026-08-27 after an
   initial incorrect self-sign+queue attempt). */
__asm__(
    ".set noreorder\n"
    ".global func_8006A540\n"
    "func_8006A540:\n"
    ".word 0x8c870000\n"   /* 8006A540: lw a3,0(a0) */
    ".word 0x8c990010\n"   /* 8006A544: lw t9,16(a0) */
    ".word 0x94f80002\n"   /* 8006A548: lhu t8,2(a3) */
    ".word 0x8ce60004\n"   /* 8006A54C: lw a2,4(a3) */
    ".word 0x8c850014\n"   /* 8006A550: lw a1,20(a0) */
    ".word 0x00063080\n"   /* 8006A554: sll a2,a2,0x2 */
    ".word 0xac900020\n"   /* 8006A558: sw s0,32(a0) */
    ".word 0xac910024\n"   /* 8006A55C: sw s1,36(a0) */
    ".word 0xac920028\n"   /* 8006A560: sw s2,40(a0) */
    ".word 0x3c0d800a\n"   /* 8006A564: lui t5,0x800a */
    ".word 0x8dadafe4\n"   /* 8006A568: lw t5,-20508(t5) */
    ".word 0x13000040\n"   /* 8006A56C: beqz t8,0x8006a670 */
    ".word 0x00000000\n"   /* 8006A570: nop */
    ".word 0x24010001\n"   /* 8006A574: li at,1 */
    ".word 0x11a1003d\n"   /* 8006A578: beq t5,at,0x8006a670 */
    ".word 0x00a63821\n"   /* 8006A57C: addu a3,a1,a2 */
    ".word 0x3c10800a\n"   /* 8006A580: lui s0,0x800a */
    ".word 0x8e10afd0\n"   /* 8006A584: lw s0,-20528(s0) */
    ".word 0x3c11800a\n"   /* 8006A588: lui s1,0x800a */
    ".word 0x8e31afd4\n"   /* 8006A58C: lw s1,-20524(s1) */
    ".word 0x3c125555\n"   /* 8006A590: lui s2,0x5555 */
    ".word 0x36525555\n"   /* 8006A594: ori s2,s2,0x5555 */
    ".word 0x8c850018\n"   /* 8006A598: lw a1,24(a0) */
    ".word 0x8c86001c\n"   /* 8006A59C: lw a2,28(a0) */
    ".word 0x8c8d0004\n"   /* 8006A5A0: lw t5,4(a0) */
    ".word 0x8c8e0008\n"   /* 8006A5A4: lw t6,8(a0) */
    ".word 0x8daf0004\n"   /* 8006A5A8: lw t7,4(t5) */
    ".word 0x8ce80010\n"   /* 8006A5AC: lw t0,16(a3) */
    ".word 0x8ce90014\n"   /* 8006A5B0: lw t1,20(a3) */
    ".word 0x8cea0018\n"   /* 8006A5B4: lw t2,24(a3) */
    ".word 0x00086c02\n"   /* 8006A5B8: srl t5,t0,0x10 */
    ".word 0x000d68c0\n"   /* 8006A5BC: sll t5,t5,0x3 */
    ".word 0x01a56821\n"   /* 8006A5C0: addu t5,t5,a1 */
    ".word 0xc9a00000\n"   /* 8006A5C4: lwc2 $0,0(t5) */
    ".word 0xc9a10004\n"   /* 8006A5C8: lwc2 $1,4(t5) */
    ".word 0x00096c02\n"   /* 8006A5CC: srl t5,t1,0x10 */
    ".word 0x000d68c0\n"   /* 8006A5D0: sll t5,t5,0x3 */
    ".word 0x01a56821\n"   /* 8006A5D4: addu t5,t5,a1 */
    ".word 0xc9a20000\n"   /* 8006A5D8: lwc2 $2,0(t5) */
    ".word 0xc9a30004\n"   /* 8006A5DC: lwc2 $3,4(t5) */
    ".word 0x000a6c02\n"   /* 8006A5E0: srl t5,t2,0x10 */
    ".word 0x000d68c0\n"   /* 8006A5E4: sll t5,t5,0x3 */
    ".word 0x01a56821\n"   /* 8006A5E8: addu t5,t5,a1 */
    ".word 0xc9a40000\n"   /* 8006A5EC: lwc2 $4,0(t5) */
    ".word 0xc9a50004\n"   /* 8006A5F0: lwc2 $5,4(t5) */
    ".word 0xaf310004\n"   /* 8006A5F4: sw s1,4(t9) */
    ".word 0xaf32001c\n"   /* 8006A5F8: sw s2,28(t9) */
    ".word 0x4a280030\n"   /* 8006A5FC: c2 0x280030 */
    ".word 0x4842f800\n"   /* 8006A600: cfc2 v0,$31 */
    ".word 0x00000000\n"   /* 8006A604: nop */
    ".word 0x04400016\n"   /* 8006A608: bltz v0,0x8006a664 */
    ".word 0x00000000\n"   /* 8006A60C: nop */
    ".word 0x4b58002d\n"   /* 8006A610: c2 0x158002d */
    ".word 0x48023800\n"   /* 8006A614: mfc2 v0,$7 */
    ".word 0xaf300008\n"   /* 8006A618: sw s0,8(t9) */
    ".word 0x01c21006\n"   /* 8006A61C: srlv v0,v0,t6 */
    ".word 0x00021080\n"   /* 8006A620: sll v0,v0,0x2 */
    ".word 0x004f1021\n"   /* 8006A624: addu v0,v0,t7 */
    ".word 0x8c4d0000\n"   /* 8006A628: lw t5,0(v0) */
    ".word 0xeb2c000c\n"   /* 8006A62C: swc2 $12,12(t9) */
    ".word 0xeb2d0010\n"   /* 8006A630: swc2 $13,16(t9) */
    ".word 0xeb2e0014\n"   /* 8006A634: swc2 $14,20(t9) */
    ".word 0xeb2c0018\n"   /* 8006A638: swc2 $12,24(t9) */
    ".word 0x000d6a00\n"   /* 8006A63C: sll t5,t5,0x8 */
    ".word 0x35ad0007\n"   /* 8006A640: ori t5,t5,0x7 */
    ".word 0x000d0a02\n"   /* 8006A644: srl at,t5,0x8 */
    ".word 0x000d6e00\n"   /* 8006A648: sll t5,t5,0x18 */
    ".word 0x01a16825\n"   /* 8006A64C: or t5,t5,at */
    ".word 0xaf2d0000\n"   /* 8006A650: sw t5,0(t9) */
    ".word 0x00196a00\n"   /* 8006A654: sll t5,t9,0x8 */
    ".word 0x000d6a02\n"   /* 8006A658: srl t5,t5,0x8 */
    ".word 0xac4d0000\n"   /* 8006A65C: sw t5,0(v0) */
    ".word 0x27390020\n"   /* 8006A660: addiu t9,t9,32 */
    ".word 0x2718ffff\n"   /* 8006A664: addiu t8,t8,-1 */
    ".word 0x1700ffd0\n"   /* 8006A668: bnez t8,0x8006a5ac */
    ".word 0x24e7001c\n"   /* 8006A66C: addiu a3,a3,28 */
    ".word 0x8c900020\n"   /* 8006A670: lw s0,32(a0) */
    ".word 0x8c910024\n"   /* 8006A674: lw s1,36(a0) */
    ".word 0x8c920028\n"   /* 8006A678: lw s2,40(a0) */
    ".word 0x8c820000\n"   /* 8006A67C: lw v0,0(a0) */
    ".word 0x3c018010\n"   /* 8006A680: lui at,0x8010 */
    ".word 0xac39e240\n"   /* 8006A684: sw t9,-7616(at) */
    ".word 0x24420008\n"   /* 8006A688: addiu v0,v0,8 */
    ".word 0x03e00008\n"   /* 8006A68C: jr ra */
    ".word 0x00000000\n"   /* 8006A690: nop */
    ".set reorder\n"
);
