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

   Sibling of func_8006A3F0 (packed 2-index-word
   form, same shape but stride 0x18 instead of this member's 0x14) and
   func_80069F94/_3field_r1C (3-separate-
   index-word form). Op sequence: RTPT (0x280030), AVSZ3 (0x158002d) --
   no NCCT/NCS/NCCS at all. "flat" marks this leaf's no-lighting-at-all
   shape; the packed sibling here loads 2 index words then derives the
   third vertex's address via a second bitfield extraction of the same
   word (one instruction shorter than the 3field members' 3-separate-word
   form).

   Landed 2026-08-27 (w1 proposal, user-signed-off naming, executed by the
   integrator) -- previously named func_80069E44 pending the family-name
   delegation letter (gte_ot_insert_* naming is never a worker's own
   self-sign call). */
__asm__(
    ".set noreorder\n"
    ".global func_80069E44\n"
    "func_80069E44:\n"
    ".word 0x8c870000\n"   /* 80069E44: lw a3,0(a0) */
    ".word 0x8c990010\n"   /* 80069E48: lw t9,16(a0) */
    ".word 0x94f80002\n"   /* 80069E4C: lhu t8,2(a3) */
    ".word 0x8ce60004\n"   /* 80069E50: lw a2,4(a3) */
    ".word 0x8c850014\n"   /* 80069E54: lw a1,20(a0) */
    ".word 0x00063080\n"   /* 80069E58: sll a2,a2,0x2 */
    ".word 0xac900020\n"   /* 80069E5C: sw s0,32(a0) */
    ".word 0xac910024\n"   /* 80069E60: sw s1,36(a0) */
    ".word 0xac920028\n"   /* 80069E64: sw s2,40(a0) */
    ".word 0x3c0d800a\n"   /* 80069E68: lui t5,0x800a */
    ".word 0x8dadafe4\n"   /* 80069E6C: lw t5,-20508(t5) */
    ".word 0x1300003f\n"   /* 80069E70: beqz t8,0x80069f70 */
    ".word 0x00000000\n"   /* 80069E74: nop */
    ".word 0x24010001\n"   /* 80069E78: li at,1 */
    ".word 0x11a1003c\n"   /* 80069E7C: beq t5,at,0x80069f70 */
    ".word 0x00a63821\n"   /* 80069E80: addu a3,a1,a2 */
    ".word 0x3c10800a\n"   /* 80069E84: lui s0,0x800a */
    ".word 0x8e10afd0\n"   /* 80069E88: lw s0,-20528(s0) */
    ".word 0x3c11800a\n"   /* 80069E8C: lui s1,0x800a */
    ".word 0x8e31afd4\n"   /* 80069E90: lw s1,-20524(s1) */
    ".word 0x3c125555\n"   /* 80069E94: lui s2,0x5555 */
    ".word 0x36525555\n"   /* 80069E98: ori s2,s2,0x5555 */
    ".word 0x8c850018\n"   /* 80069E9C: lw a1,24(a0) */
    ".word 0x8c86001c\n"   /* 80069EA0: lw a2,28(a0) */
    ".word 0x8c8d0004\n"   /* 80069EA4: lw t5,4(a0) */
    ".word 0x8c8e0008\n"   /* 80069EA8: lw t6,8(a0) */
    ".word 0x8daf0004\n"   /* 80069EAC: lw t7,4(t5) */
    ".word 0x8ce8000c\n"   /* 80069EB0: lw t0,12(a3) */
    ".word 0x8ce90010\n"   /* 80069EB4: lw t1,16(a3) */
    ".word 0x00086c02\n"   /* 80069EB8: srl t5,t0,0x10 */
    ".word 0x000d68c0\n"   /* 80069EBC: sll t5,t5,0x3 */
    ".word 0x01a56821\n"   /* 80069EC0: addu t5,t5,a1 */
    ".word 0xc9a00000\n"   /* 80069EC4: lwc2 $0,0(t5) */
    ".word 0xc9a10004\n"   /* 80069EC8: lwc2 $1,4(t5) */
    ".word 0x00096c00\n"   /* 80069ECC: sll t5,t1,0x10 */
    ".word 0x000d6b42\n"   /* 80069ED0: srl t5,t5,0xd */
    ".word 0x01a56821\n"   /* 80069ED4: addu t5,t5,a1 */
    ".word 0xc9a20000\n"   /* 80069ED8: lwc2 $2,0(t5) */
    ".word 0xc9a30004\n"   /* 80069EDC: lwc2 $3,4(t5) */
    ".word 0x00096c02\n"   /* 80069EE0: srl t5,t1,0x10 */
    ".word 0x000d68c0\n"   /* 80069EE4: sll t5,t5,0x3 */
    ".word 0x01a56821\n"   /* 80069EE8: addu t5,t5,a1 */
    ".word 0xc9a40000\n"   /* 80069EEC: lwc2 $4,0(t5) */
    ".word 0xc9a50004\n"   /* 80069EF0: lwc2 $5,4(t5) */
    ".word 0xaf310004\n"   /* 80069EF4: sw s1,4(t9) */
    ".word 0xaf32001c\n"   /* 80069EF8: sw s2,28(t9) */
    ".word 0x4a280030\n"   /* 80069EFC: c2 0x280030 */
    ".word 0x4842f800\n"   /* 80069F00: cfc2 v0,$31 */
    ".word 0x00000000\n"   /* 80069F04: nop */
    ".word 0x04400016\n"   /* 80069F08: bltz v0,0x80069f64 */
    ".word 0x00000000\n"   /* 80069F0C: nop */
    ".word 0x4b58002d\n"   /* 80069F10: c2 0x158002d */
    ".word 0x48023800\n"   /* 80069F14: mfc2 v0,$7 */
    ".word 0xaf300008\n"   /* 80069F18: sw s0,8(t9) */
    ".word 0x01c21006\n"   /* 80069F1C: srlv v0,v0,t6 */
    ".word 0x00021080\n"   /* 80069F20: sll v0,v0,0x2 */
    ".word 0x004f1021\n"   /* 80069F24: addu v0,v0,t7 */
    ".word 0x8c4d0000\n"   /* 80069F28: lw t5,0(v0) */
    ".word 0xeb2c000c\n"   /* 80069F2C: swc2 $12,12(t9) */
    ".word 0xeb2d0010\n"   /* 80069F30: swc2 $13,16(t9) */
    ".word 0xeb2e0014\n"   /* 80069F34: swc2 $14,20(t9) */
    ".word 0xeb2c0018\n"   /* 80069F38: swc2 $12,24(t9) */
    ".word 0x000d6a00\n"   /* 80069F3C: sll t5,t5,0x8 */
    ".word 0x35ad0007\n"   /* 80069F40: ori t5,t5,0x7 */
    ".word 0x000d0a02\n"   /* 80069F44: srl at,t5,0x8 */
    ".word 0x000d6e00\n"   /* 80069F48: sll t5,t5,0x18 */
    ".word 0x01a16825\n"   /* 80069F4C: or t5,t5,at */
    ".word 0xaf2d0000\n"   /* 80069F50: sw t5,0(t9) */
    ".word 0x00196a00\n"   /* 80069F54: sll t5,t9,0x8 */
    ".word 0x000d6a02\n"   /* 80069F58: srl t5,t5,0x8 */
    ".word 0xac4d0000\n"   /* 80069F5C: sw t5,0(v0) */
    ".word 0x27390020\n"   /* 80069F60: addiu t9,t9,32 */
    ".word 0x2718ffff\n"   /* 80069F64: addiu t8,t8,-1 */
    ".word 0x1700ffd1\n"   /* 80069F68: bnez t8,0x80069eb0 */
    ".word 0x24e70014\n"   /* 80069F6C: addiu a3,a3,20 */
    ".word 0x8c900020\n"   /* 80069F70: lw s0,32(a0) */
    ".word 0x8c910024\n"   /* 80069F74: lw s1,36(a0) */
    ".word 0x8c920028\n"   /* 80069F78: lw s2,40(a0) */
    ".word 0x8c820000\n"   /* 80069F7C: lw v0,0(a0) */
    ".word 0x3c018010\n"   /* 80069F80: lui at,0x8010 */
    ".word 0xac39e240\n"   /* 80069F84: sw t9,-7616(at) */
    ".word 0x24420008\n"   /* 80069F88: addiu v0,v0,8 */
    ".word 0x03e00008\n"   /* 80069F8C: jr ra */
    ".word 0x00000000\n"   /* 80069F90: nop */
    ".set reorder\n"
);
