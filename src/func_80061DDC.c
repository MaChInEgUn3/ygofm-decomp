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
   transcription, verified byte-exact (0/159 diffs); signed off in
   config/asm_allowed.txt. */
__asm__(
    ".set noreorder\n"
    ".global func_80061DDC\n"
    "func_80061DDC:\n"
    ".word 0x8c870000\n"   /* 80061DDC: lw $a3, 0x0($a0) */
    ".word 0x8c990010\n"   /* 80061DE0: lw $t9, 0x10($a0) */
    ".word 0x94f80002\n"   /* 80061DE4: lhu $t8, 0x2($a3) */
    ".word 0x8ce60004\n"   /* 80061DE8: lw $a2, 0x4($a3) */
    ".word 0x8c850014\n"   /* 80061DEC: lw $a1, 0x14($a0) */
    ".word 0x00063080\n"   /* 80061DF0: sll $a2, $a2, 2 */
    ".word 0xac900020\n"   /* 80061DF4: sw $s0, 0x20($a0) */
    ".word 0xac910024\n"   /* 80061DF8: sw $s1, 0x24($a0) */
    ".word 0xac920028\n"   /* 80061DFC: sw $s2, 0x28($a0) */
    ".word 0xac93002c\n"   /* 80061E00: sw $s3, 0x2C($a0) */
    ".word 0xac940030\n"   /* 80061E04: sw $s4, 0x30($a0) */
    ".word 0xac950034\n"   /* 80061E08: sw $s5, 0x34($a0) */
    ".word 0xac960038\n"   /* 80061E0C: sw $s6, 0x38($a0) */
    ".word 0xac97003c\n"   /* 80061E10: sw $s7, 0x3C($a0) */
    ".word 0x13000082\n"   /* 80061E14: beqz $t8, .L80062020 */
    ".word 0x00a63821\n"   /* 80061E18: addu $a3, $a1, $a2 */
    ".word 0x3c10800a\n"   /* 80061E1C: lui $s0, %hi(D_8009AFAC) */
    ".word 0x8e10afac\n"   /* 80061E20: lw $s0, %lo(D_8009AFAC)($s0) */
    ".word 0x3c11800a\n"   /* 80061E24: lui $s1, %hi(D_8009AFD8) */
    ".word 0x8e31afd8\n"   /* 80061E28: lw $s1, %lo(D_8009AFD8)($s1) */
    ".word 0x3c12800a\n"   /* 80061E2C: lui $s2, %hi(D_8009AFDC) */
    ".word 0x8e52afdc\n"   /* 80061E30: lw $s2, %lo(D_8009AFDC)($s2) */
    ".word 0x3c16800a\n"   /* 80061E34: lui $s6, %hi(D_8009AFE4) */
    ".word 0x82d6afe4\n"   /* 80061E38: lb $s6, %lo(D_8009AFE4)($s6) */
    ".word 0x3c17800a\n"   /* 80061E3C: lui $s7, %hi(D_8009AFE0) */
    ".word 0x8ef7afe0\n"   /* 80061E40: lw $s7, %lo(D_8009AFE0)($s7) */
    ".word 0x02006021\n"   /* 80061E44: addu $t4, $s0, $zero */
    ".word 0x00109e02\n"   /* 80061E48: srl $s3, $s0, 24 */
    ".word 0x3c14e200\n"   /* 80061E4C: lui $s4, (0xE2000000 >> 16) */
    ".word 0x8c850018\n"   /* 80061E50: lw $a1, 0x18($a0) */
    ".word 0x8c86001c\n"   /* 80061E54: lw $a2, 0x1C($a0) */
    ".word 0x48903000\n"   /* 80061E58: mtc2 $s0, $6 */
    ".word 0x8c8d0004\n"   /* 80061E5C: lw $t5, 0x4($a0) */
    ".word 0x8c8e0008\n"   /* 80061E60: lw $t6, 0x8($a0) */
    ".word 0x8daf0004\n"   /* 80061E64: lw $t7, 0x4($t5) */
    ".word 0x8ce80010\n"   /* 80061E68: lw $t0, 0x10($a3) */
    ".word 0x8ce90014\n"   /* 80061E6C: lw $t1, 0x14($a3) */
    ".word 0x00086c02\n"   /* 80061E70: srl $t5, $t0, 16 */
    ".word 0x000d68c0\n"   /* 80061E74: sll $t5, $t5, 3 */
    ".word 0x01a56821\n"   /* 80061E78: addu $t5, $t5, $a1 */
    ".word 0xc9a00000\n"   /* 80061E7C: lwc2 $0, 0x0($t5) */
    ".word 0xc9a10004\n"   /* 80061E80: lwc2 $1, 0x4($t5) */
    ".word 0x00096c00\n"   /* 80061E84: sll $t5, $t1, 16 */
    ".word 0x000d6b42\n"   /* 80061E88: srl $t5, $t5, 13 */
    ".word 0x01a56821\n"   /* 80061E8C: addu $t5, $t5, $a1 */
    ".word 0xc9a20000\n"   /* 80061E90: lwc2 $2, 0x0($t5) */
    ".word 0xc9a30004\n"   /* 80061E94: lwc2 $3, 0x4($t5) */
    ".word 0x00096c02\n"   /* 80061E98: srl $t5, $t1, 16 */
    ".word 0x000d68c0\n"   /* 80061E9C: sll $t5, $t5, 3 */
    ".word 0x01a56821\n"   /* 80061EA0: addu $t5, $t5, $a1 */
    ".word 0xc9a40000\n"   /* 80061EA4: lwc2 $4, 0x0($t5) */
    ".word 0xc9a50004\n"   /* 80061EA8: lwc2 $5, 0x4($t5) */
    ".word 0x00084400\n"   /* 80061EAC: sll $t0, $t0, 16 */
    ".word 0x00084342\n"   /* 80061EB0: srl $t0, $t0, 13 */
    ".word 0x4a280030\n"   /* 80061EB4: rtpt */
    ".word 0x24010001\n"   /* 80061EB8: addiu $at, $zero, 0x1 */
    ".word 0x12c1000a\n"   /* 80061EBC: beq $s6, $at, .L80061EE8 */
    ".word 0x00000000\n"   /* 80061EC0: nop */
    ".word 0x4842f800\n"   /* 80061EC4: cfc2 $v0, $31 */
    ".word 0x00000000\n"   /* 80061EC8: nop */
    ".word 0x04400051\n"   /* 80061ECC: bltz $v0, .L80062014 */
    ".word 0x00000000\n"   /* 80061ED0: nop */
    ".word 0x4b400006\n"   /* 80061ED4: nclip */
    ".word 0x4802c000\n"   /* 80061ED8: mfc2 $v0, $24 */
    ".word 0x00000000\n"   /* 80061EDC: nop */
    ".word 0x1840004c\n"   /* 80061EE0: blez $v0, .L80062014 */
    ".word 0x00000000\n"   /* 80061EE4: nop */
    ".word 0x4b58002d\n"   /* 80061EE8: avsz3 */
    ".word 0x8cf50000\n"   /* 80061EEC: lw $s5, 0x0($a3) */
    ".word 0x12c00010\n"   /* 80061EF0: beqz $s6, .L80061F34 */
    ".word 0x01066821\n"   /* 80061EF4: addu $t5, $t0, $a2 */
    ".word 0xc9a00000\n"   /* 80061EF8: lwc2 $0, 0x0($t5) */
    ".word 0xc9a10004\n"   /* 80061EFC: lwc2 $1, 0x4($t5) */
    ".word 0x00000000\n"   /* 80061F00: nop */
    ".word 0x00000000\n"   /* 80061F04: nop */
    ".word 0x4b08041b\n"   /* 80061F08: nccs */
    ".word 0x12e00003\n"   /* 80061F0C: beqz $s7, .L80061F1C */
    ".word 0x00084042\n"   /* 80061F10: srl $t0, $t0, 1 */
    ".word 0x01174021\n"   /* 80061F14: addu $t0, $t0, $s7 */
    ".word 0xe9160000\n"   /* 80061F18: swc2 $22, 0x0($t0) */
    ".word 0xeb360008\n"   /* 80061F1C: swc2 $22, 0x8($t9) */
    ".word 0x24010001\n"   /* 80061F20: addiu $at, $zero, 0x1 */
    ".word 0x12c1003b\n"   /* 80061F24: beq $s6, $at, .L80062014 */
    ".word 0x00000000\n"   /* 80061F28: nop */
    ".word 0x080187d3\n"   /* 80061F2C: j .L80061F4C */
    ".word 0x00000000\n"   /* 80061F30: nop */
    ".word 0x00084042\n"   /* 80061F34: srl $t0, $t0, 1 */
    ".word 0x01171821\n"   /* 80061F38: addu $v1, $t0, $s7 */
    ".word 0x8c680000\n"   /* 80061F3C: lw $t0, 0x0($v1) */
    ".word 0x00000000\n"   /* 80061F40: nop */
    ".word 0xaf280008\n"   /* 80061F44: sw $t0, 0x8($t9) */
    ".word 0xa333000b\n"   /* 80061F48: sb $s3, 0xB($t9) */
    ".word 0x8ce80004\n"   /* 80061F4C: lw $t0, 0x4($a3) */
    ".word 0x8ce90008\n"   /* 80061F50: lw $t1, 0x8($a3) */
    ".word 0x8cea000c\n"   /* 80061F54: lw $t2, 0xC($a3) */
    ".word 0x48023800\n"   /* 80061F58: mfc2 $v0, $7 */
    ".word 0x3c010200\n"   /* 80061F5C: lui $at, (0x2000000 >> 16) */
    ".word 0x02011824\n"   /* 80061F60: and $v1, $s0, $at */
    ".word 0x01314825\n"   /* 80061F64: or $t1, $t1, $s1 */
    ".word 0x01c21006\n"   /* 80061F68: srlv $v0, $v0, $t6 */
    ".word 0x00021080\n"   /* 80061F6C: sll $v0, $v0, 2 */
    ".word 0x004f1021\n"   /* 80061F70: addu $v0, $v0, $t7 */
    ".word 0x8c4d0000\n"   /* 80061F74: lw $t5, 0x0($v0) */
    ".word 0xeb2c000c\n"   /* 80061F78: swc2 $12, 0xC($t9) */
    ".word 0xeb2d0014\n"   /* 80061F7C: swc2 $13, 0x14($t9) */
    ".word 0xeb2e001c\n"   /* 80061F80: swc2 $14, 0x1C($t9) */
    ".word 0xaf280010\n"   /* 80061F84: sw $t0, 0x10($t9) */
    ".word 0xaf290018\n"   /* 80061F88: sw $t1, 0x18($t9) */
    ".word 0xaf2a0020\n"   /* 80061F8C: sw $t2, 0x20($t9) */
    ".word 0xaf350004\n"   /* 80061F90: sw $s5, 0x4($t9) */
    ".word 0xaf340024\n"   /* 80061F94: sw $s4, 0x24($t9) */
    ".word 0x000d6a00\n"   /* 80061F98: sll $t5, $t5, 8 */
    ".word 0x35ad0009\n"   /* 80061F9C: ori $t5, $t5, 0x9 */
    ".word 0x000d0a02\n"   /* 80061FA0: srl $at, $t5, 8 */
    ".word 0x000d6e00\n"   /* 80061FA4: sll $t5, $t5, 24 */
    ".word 0x01a16825\n"   /* 80061FA8: or $t5, $t5, $at */
    ".word 0xaf2d0000\n"   /* 80061FAC: sw $t5, 0x0($t9) */
    ".word 0x00196a00\n"   /* 80061FB0: sll $t5, $t9, 8 */
    ".word 0x000d6a02\n"   /* 80061FB4: srl $t5, $t5, 8 */
    ".word 0x10600015\n"   /* 80061FB8: beqz $v1, .L80062010 */
    ".word 0xac4d0000\n"   /* 80061FBC: sw $t5, 0x0($v0) */
    ".word 0x12400013\n"   /* 80061FC0: beqz $s2, .L80062010 */
    ".word 0x00000000\n"   /* 80061FC4: nop */
    ".word 0x3c01ff9f\n"   /* 80061FC8: lui $at, (0xFF9FFFFF >> 16) */
    ".word 0x3421ffff\n"   /* 80061FCC: ori $at, $at, (0xFF9FFFFF & 0xFFFF) */
    ".word 0x01214824\n"   /* 80061FD0: and $t1, $t1, $at */
    ".word 0x3c010040\n"   /* 80061FD4: lui $at, (0x400000 >> 16) */
    ".word 0x01214825\n"   /* 80061FD8: or $t1, $t1, $at */
    ".word 0x8f23000c\n"   /* 80061FDC: lw $v1, 0xC($t9) */
    ".word 0x00084400\n"   /* 80061FE0: sll $t0, $t0, 16 */
    ".word 0xaf230034\n"   /* 80061FE4: sw $v1, 0x34($t9) */
    ".word 0x8f230014\n"   /* 80061FE8: lw $v1, 0x14($t9) */
    ".word 0x00084402\n"   /* 80061FEC: srl $t0, $t0, 16 */
    ".word 0xaf23003c\n"   /* 80061FF0: sw $v1, 0x3C($t9) */
    ".word 0x8f23001c\n"   /* 80061FF4: lw $v1, 0x1C($t9) */
    ".word 0x01124025\n"   /* 80061FF8: or $t0, $t0, $s2 */
    ".word 0xaf230044\n"   /* 80061FFC: sw $v1, 0x44($t9) */
    ".word 0xaf2c0030\n"   /* 80062000: sw $t4, 0x30($t9) */
    ".word 0x27390028\n"   /* 80062004: addiu $t9, $t9, 0x28 */
    ".word 0x080187e1\n"   /* 80062008: j .L80061F84 */
    ".word 0x24030000\n"   /* 8006200C: addiu $v1, $zero, 0x0 */
    ".word 0x27390028\n"   /* 80062010: addiu $t9, $t9, 0x28 */
    ".word 0x2718ffff\n"   /* 80062014: addiu $t8, $t8, -0x1 */
    ".word 0x1700ff93\n"   /* 80062018: bnez $t8, .L80061E68 */
    ".word 0x24e70018\n"   /* 8006201C: addiu $a3, $a3, 0x18 */
    ".word 0x8c900020\n"   /* 80062020: lw $s0, 0x20($a0) */
    ".word 0x8c910024\n"   /* 80062024: lw $s1, 0x24($a0) */
    ".word 0x8c920028\n"   /* 80062028: lw $s2, 0x28($a0) */
    ".word 0x8c93002c\n"   /* 8006202C: lw $s3, 0x2C($a0) */
    ".word 0x8c940030\n"   /* 80062030: lw $s4, 0x30($a0) */
    ".word 0x8c950034\n"   /* 80062034: lw $s5, 0x34($a0) */
    ".word 0x8c960038\n"   /* 80062038: lw $s6, 0x38($a0) */
    ".word 0x8c97003c\n"   /* 8006203C: lw $s7, 0x3C($a0) */
    ".word 0x8c820000\n"   /* 80062040: lw $v0, 0x0($a0) */
    ".word 0x3c018010\n"   /* 80062044: lui $at, %hi(D_800FE240) */
    ".word 0xac39e240\n"   /* 80062048: sw $t9, %lo(D_800FE240)($at) */
    ".word 0x24420008\n"   /* 8006204C: addiu $v0, $v0, 0x8 */
    ".word 0x03e00008\n"   /* 80062050: jr $ra */
    ".word 0x00000000\n"   /* 80062054: nop */
    ".set reorder\n"
);
