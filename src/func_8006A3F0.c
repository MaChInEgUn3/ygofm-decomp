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
   transcription, verified byte-exact (0/84 diffs).

   Sibling of func_80069E44 (packed 2-index-word
   form, identical shape but stride 0x14 instead of this member's 0x18)
   and func_80069F94/_3field_r1C (3-separate-
   index-word form). Op sequence: RTPT (0x280030), AVSZ3 (0x158002d) --
   no NCCT/NCS/NCCS at all. "_r18" is a factual stride note (this member's
   record stride is 0x18 vs its packed pair-mate's 0x14), not a claimed
   semantic difference.

   Landed 2026-08-27 (w1 proposal, user-signed-off naming, executed by the
   integrator) -- previously named func_8006A3F0 pending the family-name
   delegation letter (gte_ot_insert_* naming is never a worker's own
   self-sign call). */
__asm__(
    ".set noreorder\n"
    ".global func_8006A3F0\n"
    "func_8006A3F0:\n"
    ".word 0x8c870000\n"   /* 8006A3F0: lw a3,0(a0) */
    ".word 0x8c990010\n"   /* 8006A3F4: lw t9,16(a0) */
    ".word 0x94f80002\n"   /* 8006A3F8: lhu t8,2(a3) */
    ".word 0x8ce60004\n"   /* 8006A3FC: lw a2,4(a3) */
    ".word 0x8c850014\n"   /* 8006A400: lw a1,20(a0) */
    ".word 0x00063080\n"   /* 8006A404: sll a2,a2,0x2 */
    ".word 0xac900020\n"   /* 8006A408: sw s0,32(a0) */
    ".word 0xac910024\n"   /* 8006A40C: sw s1,36(a0) */
    ".word 0xac920028\n"   /* 8006A410: sw s2,40(a0) */
    ".word 0x3c0d800a\n"   /* 8006A414: lui t5,0x800a */
    ".word 0x8dadafe4\n"   /* 8006A418: lw t5,-20508(t5) */
    ".word 0x1300003f\n"   /* 8006A41C: beqz t8,0x8006a51c */
    ".word 0x00000000\n"   /* 8006A420: nop */
    ".word 0x24010001\n"   /* 8006A424: li at,1 */
    ".word 0x11a1003c\n"   /* 8006A428: beq t5,at,0x8006a51c */
    ".word 0x00a63821\n"   /* 8006A42C: addu a3,a1,a2 */
    ".word 0x3c10800a\n"   /* 8006A430: lui s0,0x800a */
    ".word 0x8e10afd0\n"   /* 8006A434: lw s0,-20528(s0) */
    ".word 0x3c11800a\n"   /* 8006A438: lui s1,0x800a */
    ".word 0x8e31afd4\n"   /* 8006A43C: lw s1,-20524(s1) */
    ".word 0x3c125555\n"   /* 8006A440: lui s2,0x5555 */
    ".word 0x36525555\n"   /* 8006A444: ori s2,s2,0x5555 */
    ".word 0x8c850018\n"   /* 8006A448: lw a1,24(a0) */
    ".word 0x8c86001c\n"   /* 8006A44C: lw a2,28(a0) */
    ".word 0x8c8d0004\n"   /* 8006A450: lw t5,4(a0) */
    ".word 0x8c8e0008\n"   /* 8006A454: lw t6,8(a0) */
    ".word 0x8daf0004\n"   /* 8006A458: lw t7,4(t5) */
    ".word 0x8ce80010\n"   /* 8006A45C: lw t0,16(a3) */
    ".word 0x8ce90014\n"   /* 8006A460: lw t1,20(a3) */
    ".word 0x00086c02\n"   /* 8006A464: srl t5,t0,0x10 */
    ".word 0x000d68c0\n"   /* 8006A468: sll t5,t5,0x3 */
    ".word 0x01a56821\n"   /* 8006A46C: addu t5,t5,a1 */
    ".word 0xc9a00000\n"   /* 8006A470: lwc2 $0,0(t5) */
    ".word 0xc9a10004\n"   /* 8006A474: lwc2 $1,4(t5) */
    ".word 0x00096c00\n"   /* 8006A478: sll t5,t1,0x10 */
    ".word 0x000d6b42\n"   /* 8006A47C: srl t5,t5,0xd */
    ".word 0x01a56821\n"   /* 8006A480: addu t5,t5,a1 */
    ".word 0xc9a20000\n"   /* 8006A484: lwc2 $2,0(t5) */
    ".word 0xc9a30004\n"   /* 8006A488: lwc2 $3,4(t5) */
    ".word 0x00096c02\n"   /* 8006A48C: srl t5,t1,0x10 */
    ".word 0x000d68c0\n"   /* 8006A490: sll t5,t5,0x3 */
    ".word 0x01a56821\n"   /* 8006A494: addu t5,t5,a1 */
    ".word 0xc9a40000\n"   /* 8006A498: lwc2 $4,0(t5) */
    ".word 0xc9a50004\n"   /* 8006A49C: lwc2 $5,4(t5) */
    ".word 0xaf310004\n"   /* 8006A4A0: sw s1,4(t9) */
    ".word 0xaf32001c\n"   /* 8006A4A4: sw s2,28(t9) */
    ".word 0x4a280030\n"   /* 8006A4A8: c2 0x280030 */
    ".word 0x4842f800\n"   /* 8006A4AC: cfc2 v0,$31 */
    ".word 0x00000000\n"   /* 8006A4B0: nop */
    ".word 0x04400016\n"   /* 8006A4B4: bltz v0,0x8006a510 */
    ".word 0x00000000\n"   /* 8006A4B8: nop */
    ".word 0x4b58002d\n"   /* 8006A4BC: c2 0x158002d */
    ".word 0x48023800\n"   /* 8006A4C0: mfc2 v0,$7 */
    ".word 0xaf300008\n"   /* 8006A4C4: sw s0,8(t9) */
    ".word 0x01c21006\n"   /* 8006A4C8: srlv v0,v0,t6 */
    ".word 0x00021080\n"   /* 8006A4CC: sll v0,v0,0x2 */
    ".word 0x004f1021\n"   /* 8006A4D0: addu v0,v0,t7 */
    ".word 0x8c4d0000\n"   /* 8006A4D4: lw t5,0(v0) */
    ".word 0xeb2c000c\n"   /* 8006A4D8: swc2 $12,12(t9) */
    ".word 0xeb2d0010\n"   /* 8006A4DC: swc2 $13,16(t9) */
    ".word 0xeb2e0014\n"   /* 8006A4E0: swc2 $14,20(t9) */
    ".word 0xeb2c0018\n"   /* 8006A4E4: swc2 $12,24(t9) */
    ".word 0x000d6a00\n"   /* 8006A4E8: sll t5,t5,0x8 */
    ".word 0x35ad0007\n"   /* 8006A4EC: ori t5,t5,0x7 */
    ".word 0x000d0a02\n"   /* 8006A4F0: srl at,t5,0x8 */
    ".word 0x000d6e00\n"   /* 8006A4F4: sll t5,t5,0x18 */
    ".word 0x01a16825\n"   /* 8006A4F8: or t5,t5,at */
    ".word 0xaf2d0000\n"   /* 8006A4FC: sw t5,0(t9) */
    ".word 0x00196a00\n"   /* 8006A500: sll t5,t9,0x8 */
    ".word 0x000d6a02\n"   /* 8006A504: srl t5,t5,0x8 */
    ".word 0xac4d0000\n"   /* 8006A508: sw t5,0(v0) */
    ".word 0x27390020\n"   /* 8006A50C: addiu t9,t9,32 */
    ".word 0x2718ffff\n"   /* 8006A510: addiu t8,t8,-1 */
    ".word 0x1700ffd1\n"   /* 8006A514: bnez t8,0x8006a45c */
    ".word 0x24e70018\n"   /* 8006A518: addiu a3,a3,24 */
    ".word 0x8c900020\n"   /* 8006A51C: lw s0,32(a0) */
    ".word 0x8c910024\n"   /* 8006A520: lw s1,36(a0) */
    ".word 0x8c920028\n"   /* 8006A524: lw s2,40(a0) */
    ".word 0x8c820000\n"   /* 8006A528: lw v0,0(a0) */
    ".word 0x3c018010\n"   /* 8006A52C: lui at,0x8010 */
    ".word 0xac39e240\n"   /* 8006A530: sw t9,-7616(at) */
    ".word 0x24420008\n"   /* 8006A534: addiu v0,v0,8 */
    ".word 0x03e00008\n"   /* 8006A538: jr ra */
    ".word 0x00000000\n"   /* 8006A53C: nop */
    ".set reorder\n"
);
