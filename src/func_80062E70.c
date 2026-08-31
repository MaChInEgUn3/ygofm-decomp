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
   transcription, verified byte-exact (0/164 diffs); signed off in
   config/asm_allowed.txt. */
__asm__(
    ".set noreorder\n"
    ".global func_80062E70\n"
    "func_80062E70:\n"
    ".word 0x8c870000\n"   /* 80062E70: lw $a3, 0x0($a0) */
    ".word 0x8c990010\n"   /* 80062E74: lw $t9, 0x10($a0) */
    ".word 0x94f80002\n"   /* 80062E78: lhu $t8, 0x2($a3) */
    ".word 0x8ce60004\n"   /* 80062E7C: lw $a2, 0x4($a3) */
    ".word 0x8c850014\n"   /* 80062E80: lw $a1, 0x14($a0) */
    ".word 0x00063080\n"   /* 80062E84: sll $a2, $a2, 2 */
    ".word 0xac900020\n"   /* 80062E88: sw $s0, 0x20($a0) */
    ".word 0xac910024\n"   /* 80062E8C: sw $s1, 0x24($a0) */
    ".word 0xac920028\n"   /* 80062E90: sw $s2, 0x28($a0) */
    ".word 0xac93002c\n"   /* 80062E94: sw $s3, 0x2C($a0) */
    ".word 0xac960030\n"   /* 80062E98: sw $s6, 0x30($a0) */
    ".word 0xac970034\n"   /* 80062E9C: sw $s7, 0x34($a0) */
    ".word 0x1300008b\n"   /* 80062EA0: beqz $t8, .L800630D0 */
    ".word 0x00a63821\n"   /* 80062EA4: addu $a3, $a1, $a2 */
    ".word 0x3c10800a\n"   /* 80062EA8: lui $s0, %hi(D_8009AFB0) */
    ".word 0x8e10afb0\n"   /* 80062EAC: lw $s0, %lo(D_8009AFB0)($s0) */
    ".word 0x3c11800a\n"   /* 80062EB0: lui $s1, %hi(D_8009AFD8) */
    ".word 0x8e31afd8\n"   /* 80062EB4: lw $s1, %lo(D_8009AFD8)($s1) */
    ".word 0x3c12800a\n"   /* 80062EB8: lui $s2, %hi(D_8009AFDC) */
    ".word 0x8e52afdc\n"   /* 80062EBC: lw $s2, %lo(D_8009AFDC)($s2) */
    ".word 0x3c16800a\n"   /* 80062EC0: lui $s6, %hi(D_8009AFE4) */
    ".word 0x82d6afe4\n"   /* 80062EC4: lb $s6, %lo(D_8009AFE4)($s6) */
    ".word 0x3c17800a\n"   /* 80062EC8: lui $s7, %hi(D_8009AFE0) */
    ".word 0x8ef7afe0\n"   /* 80062ECC: lw $s7, %lo(D_8009AFE0)($s7) */
    ".word 0x02006021\n"   /* 80062ED0: addu $t4, $s0, $zero */
    ".word 0x00109e02\n"   /* 80062ED4: srl $s3, $s0, 24 */
    ".word 0x8c850018\n"   /* 80062ED8: lw $a1, 0x18($a0) */
    ".word 0x8c86001c\n"   /* 80062EDC: lw $a2, 0x1C($a0) */
    ".word 0x48903000\n"   /* 80062EE0: mtc2 $s0, $6 */
    ".word 0x8c8d0004\n"   /* 80062EE4: lw $t5, 0x4($a0) */
    ".word 0x8c8e0008\n"   /* 80062EE8: lw $t6, 0x8($a0) */
    ".word 0x8daf0004\n"   /* 80062EEC: lw $t7, 0x4($t5) */
    ".word 0x8ce80010\n"   /* 80062EF0: lw $t0, 0x10($a3) */
    ".word 0x8ce90014\n"   /* 80062EF4: lw $t1, 0x14($a3) */
    ".word 0x00086c00\n"   /* 80062EF8: sll $t5, $t0, 16 */
    ".word 0x000d6b42\n"   /* 80062EFC: srl $t5, $t5, 13 */
    ".word 0x01a56821\n"   /* 80062F00: addu $t5, $t5, $a1 */
    ".word 0xc9a00000\n"   /* 80062F04: lwc2 $0, 0x0($t5) */
    ".word 0xc9a10004\n"   /* 80062F08: lwc2 $1, 0x4($t5) */
    ".word 0x00086c02\n"   /* 80062F0C: srl $t5, $t0, 16 */
    ".word 0x000d68c0\n"   /* 80062F10: sll $t5, $t5, 3 */
    ".word 0x01a56821\n"   /* 80062F14: addu $t5, $t5, $a1 */
    ".word 0xc9a20000\n"   /* 80062F18: lwc2 $2, 0x0($t5) */
    ".word 0xc9a30004\n"   /* 80062F1C: lwc2 $3, 0x4($t5) */
    ".word 0x00096c00\n"   /* 80062F20: sll $t5, $t1, 16 */
    ".word 0x000d6b42\n"   /* 80062F24: srl $t5, $t5, 13 */
    ".word 0x01a56821\n"   /* 80062F28: addu $t5, $t5, $a1 */
    ".word 0xc9a40000\n"   /* 80062F2C: lwc2 $4, 0x0($t5) */
    ".word 0xc9a50004\n"   /* 80062F30: lwc2 $5, 0x4($t5) */
    ".word 0x00095c02\n"   /* 80062F34: srl $t3, $t1, 16 */
    ".word 0x000b58c0\n"   /* 80062F38: sll $t3, $t3, 3 */
    ".word 0x4a280030\n"   /* 80062F3C: rtpt */
    ".word 0x24010001\n"   /* 80062F40: addiu $at, $zero, 0x1 */
    ".word 0x12c10005\n"   /* 80062F44: beq $s6, $at, .L80062F5C */
    ".word 0x01656821\n"   /* 80062F48: addu $t5, $t3, $a1 */
    ".word 0x4842f800\n"   /* 80062F4C: cfc2 $v0, $31 */
    ".word 0x00000000\n"   /* 80062F50: nop */
    ".word 0x0440005b\n"   /* 80062F54: bltz $v0, .L800630C4 */
    ".word 0x00000000\n"   /* 80062F58: nop */
    ".word 0xc9a00000\n"   /* 80062F5C: lwc2 $0, 0x0($t5) */
    ".word 0xc9a10004\n"   /* 80062F60: lwc2 $1, 0x4($t5) */
    ".word 0xeb2c0008\n"   /* 80062F64: swc2 $12, 0x8($t9) */
    ".word 0xeb2d0010\n"   /* 80062F68: swc2 $13, 0x10($t9) */
    ".word 0xeb2e0018\n"   /* 80062F6C: swc2 $14, 0x18($t9) */
    ".word 0x00000000\n"   /* 80062F70: nop */
    ".word 0x00000000\n"   /* 80062F74: nop */
    ".word 0x4a180001\n"   /* 80062F78: rtps */
    ".word 0x94e8000e\n"   /* 80062F7C: lhu $t0, 0xE($a3) */
    ".word 0x24010001\n"   /* 80062F80: addiu $at, $zero, 0x1 */
    ".word 0x12c10005\n"   /* 80062F84: beq $s6, $at, .L80062F9C */
    ".word 0x000840c0\n"   /* 80062F88: sll $t0, $t0, 3 */
    ".word 0x4842f800\n"   /* 80062F8C: cfc2 $v0, $31 */
    ".word 0x00000000\n"   /* 80062F90: nop */
    ".word 0x0440004b\n"   /* 80062F94: bltz $v0, .L800630C4 */
    ".word 0x00000000\n"   /* 80062F98: nop */
    ".word 0x4b68002e\n"   /* 80062F9C: avsz4 */
    ".word 0x12c00010\n"   /* 80062FA0: beqz $s6, .L80062FE4 */
    ".word 0x01066821\n"   /* 80062FA4: addu $t5, $t0, $a2 */
    ".word 0xc9a00000\n"   /* 80062FA8: lwc2 $0, 0x0($t5) */
    ".word 0xc9a10004\n"   /* 80062FAC: lwc2 $1, 0x4($t5) */
    ".word 0x00000000\n"   /* 80062FB0: nop */
    ".word 0x00000000\n"   /* 80062FB4: nop */
    ".word 0x4b08041b\n"   /* 80062FB8: nccs */
    ".word 0x12e00003\n"   /* 80062FBC: beqz $s7, .L80062FCC */
    ".word 0x00084042\n"   /* 80062FC0: srl $t0, $t0, 1 */
    ".word 0x01174021\n"   /* 80062FC4: addu $t0, $t0, $s7 */
    ".word 0xe9160000\n"   /* 80062FC8: swc2 $22, 0x0($t0) */
    ".word 0xeb360004\n"   /* 80062FCC: swc2 $22, 0x4($t9) */
    ".word 0x24010001\n"   /* 80062FD0: addiu $at, $zero, 0x1 */
    ".word 0x12c1003b\n"   /* 80062FD4: beq $s6, $at, .L800630C4 */
    ".word 0x00000000\n"   /* 80062FD8: nop */
    ".word 0x08018bff\n"   /* 80062FDC: j .L80062FFC */
    ".word 0x00000000\n"   /* 80062FE0: nop */
    ".word 0x00084042\n"   /* 80062FE4: srl $t0, $t0, 1 */
    ".word 0x01171821\n"   /* 80062FE8: addu $v1, $t0, $s7 */
    ".word 0x8c680000\n"   /* 80062FEC: lw $t0, 0x0($v1) */
    ".word 0x00000000\n"   /* 80062FF0: nop */
    ".word 0xaf280004\n"   /* 80062FF4: sw $t0, 0x4($t9) */
    ".word 0xa3330007\n"   /* 80062FF8: sb $s3, 0x7($t9) */
    ".word 0x8ce80000\n"   /* 80062FFC: lw $t0, 0x0($a3) */
    ".word 0x8ce90004\n"   /* 80063000: lw $t1, 0x4($a3) */
    ".word 0x8cea0008\n"   /* 80063004: lw $t2, 0x8($a3) */
    ".word 0x8ceb000c\n"   /* 80063008: lw $t3, 0xC($a3) */
    ".word 0x48023800\n"   /* 8006300C: mfc2 $v0, $7 */
    ".word 0x3c010200\n"   /* 80063010: lui $at, (0x2000000 >> 16) */
    ".word 0x02011824\n"   /* 80063014: and $v1, $s0, $at */
    ".word 0x01314825\n"   /* 80063018: or $t1, $t1, $s1 */
    ".word 0x01c21006\n"   /* 8006301C: srlv $v0, $v0, $t6 */
    ".word 0x00021080\n"   /* 80063020: sll $v0, $v0, 2 */
    ".word 0x004f1021\n"   /* 80063024: addu $v0, $v0, $t7 */
    ".word 0x8c4d0000\n"   /* 80063028: lw $t5, 0x0($v0) */
    ".word 0xeb2e0020\n"   /* 8006302C: swc2 $14, 0x20($t9) */
    ".word 0xaf28000c\n"   /* 80063030: sw $t0, 0xC($t9) */
    ".word 0xaf290014\n"   /* 80063034: sw $t1, 0x14($t9) */
    ".word 0xaf2a001c\n"   /* 80063038: sw $t2, 0x1C($t9) */
    ".word 0xaf2b0024\n"   /* 8006303C: sw $t3, 0x24($t9) */
    ".word 0x000d6a00\n"   /* 80063040: sll $t5, $t5, 8 */
    ".word 0x35ad0009\n"   /* 80063044: ori $t5, $t5, 0x9 */
    ".word 0x000d0a02\n"   /* 80063048: srl $at, $t5, 8 */
    ".word 0x000d6e00\n"   /* 8006304C: sll $t5, $t5, 24 */
    ".word 0x01a16825\n"   /* 80063050: or $t5, $t5, $at */
    ".word 0xaf2d0000\n"   /* 80063054: sw $t5, 0x0($t9) */
    ".word 0x00196a00\n"   /* 80063058: sll $t5, $t9, 8 */
    ".word 0x000d6a02\n"   /* 8006305C: srl $t5, $t5, 8 */
    ".word 0x10600017\n"   /* 80063060: beqz $v1, .L800630C0 */
    ".word 0xac4d0000\n"   /* 80063064: sw $t5, 0x0($v0) */
    ".word 0x12400015\n"   /* 80063068: beqz $s2, .L800630C0 */
    ".word 0x00000000\n"   /* 8006306C: nop */
    ".word 0x3c01ff9f\n"   /* 80063070: lui $at, (0xFF9FFFFF >> 16) */
    ".word 0x3421ffff\n"   /* 80063074: ori $at, $at, (0xFF9FFFFF & 0xFFFF) */
    ".word 0x01214824\n"   /* 80063078: and $t1, $t1, $at */
    ".word 0x3c010040\n"   /* 8006307C: lui $at, (0x400000 >> 16) */
    ".word 0x01214825\n"   /* 80063080: or $t1, $t1, $at */
    ".word 0x8f230008\n"   /* 80063084: lw $v1, 0x8($t9) */
    ".word 0x00084400\n"   /* 80063088: sll $t0, $t0, 16 */
    ".word 0xaf230030\n"   /* 8006308C: sw $v1, 0x30($t9) */
    ".word 0x8f230010\n"   /* 80063090: lw $v1, 0x10($t9) */
    ".word 0x00084402\n"   /* 80063094: srl $t0, $t0, 16 */
    ".word 0xaf230038\n"   /* 80063098: sw $v1, 0x38($t9) */
    ".word 0x8f230018\n"   /* 8006309C: lw $v1, 0x18($t9) */
    ".word 0x01124025\n"   /* 800630A0: or $t0, $t0, $s2 */
    ".word 0xaf230040\n"   /* 800630A4: sw $v1, 0x40($t9) */
    ".word 0x8f230020\n"   /* 800630A8: lw $v1, 0x20($t9) */
    ".word 0xaf2c002c\n"   /* 800630AC: sw $t4, 0x2C($t9) */
    ".word 0xaf230048\n"   /* 800630B0: sw $v1, 0x48($t9) */
    ".word 0x27390028\n"   /* 800630B4: addiu $t9, $t9, 0x28 */
    ".word 0x08018c0c\n"   /* 800630B8: j .L80063030 */
    ".word 0x24030000\n"   /* 800630BC: addiu $v1, $zero, 0x0 */
    ".word 0x27390028\n"   /* 800630C0: addiu $t9, $t9, 0x28 */
    ".word 0x2718ffff\n"   /* 800630C4: addiu $t8, $t8, -0x1 */
    ".word 0x1700ff89\n"   /* 800630C8: bnez $t8, .L80062EF0 */
    ".word 0x24e70018\n"   /* 800630CC: addiu $a3, $a3, 0x18 */
    ".word 0x8c900020\n"   /* 800630D0: lw $s0, 0x20($a0) */
    ".word 0x8c910024\n"   /* 800630D4: lw $s1, 0x24($a0) */
    ".word 0x8c920028\n"   /* 800630D8: lw $s2, 0x28($a0) */
    ".word 0x8c93002c\n"   /* 800630DC: lw $s3, 0x2C($a0) */
    ".word 0x8c960030\n"   /* 800630E0: lw $s6, 0x30($a0) */
    ".word 0x8c970034\n"   /* 800630E4: lw $s7, 0x34($a0) */
    ".word 0x8c820000\n"   /* 800630E8: lw $v0, 0x0($a0) */
    ".word 0x3c018010\n"   /* 800630EC: lui $at, %hi(D_800FE240) */
    ".word 0xac39e240\n"   /* 800630F0: sw $t9, %lo(D_800FE240)($at) */
    ".word 0x24420008\n"   /* 800630F4: addiu $v0, $v0, 0x8 */
    ".word 0x03e00008\n"   /* 800630F8: jr $ra */
    ".word 0x00000000\n"   /* 800630FC: nop */
    ".set reorder\n"
);
