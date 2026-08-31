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
   transcription, mechanically byte-swapped from asm/nonmatchings/
   gte_ot_insert_precolored_quads_transluc/func_80069B40.s. */
__asm__(
    ".set noreorder\n"
    ".global func_80069B40\n"
    "func_80069B40:\n"
    ".word 0x8c870000\n"   /* 80069B40: lw $a3, 0x0($a0) */
    ".word 0x8c990010\n"   /* 80069B44: lw $t9, 0x10($a0) */
    ".word 0x94f80002\n"   /* 80069B48: lhu $t8, 0x2($a3) */
    ".word 0x8ce60004\n"   /* 80069B4C: lw $a2, 0x4($a3) */
    ".word 0x8c850014\n"   /* 80069B50: lw $a1, 0x14($a0) */
    ".word 0x00063080\n"   /* 80069B54: sll $a2, $a2, 2 */
    ".word 0xac900028\n"   /* 80069B58: sw $s0, 0x28($a0) */
    ".word 0xac91002c\n"   /* 80069B5C: sw $s1, 0x2C($a0) */
    ".word 0xac920030\n"   /* 80069B60: sw $s2, 0x30($a0) */
    ".word 0xac930034\n"   /* 80069B64: sw $s3, 0x34($a0) */
    ".word 0xac940038\n"   /* 80069B68: sw $s4, 0x38($a0) */
    ".word 0xac95003c\n"   /* 80069B6C: sw $s5, 0x3C($a0) */
    ".word 0x130000a8\n"   /* 80069B70: beqz $t8, .L80069E14 */
    ".word 0x00a63821\n"   /* 80069B74: addu $a3, $a1, $a2 */
    ".word 0x3c10800a\n"   /* 80069B78: lui $s0, %hi(D_8009AFB8) */
    ".word 0x8e10afb8\n"   /* 80069B7C: lw $s0, %lo(D_8009AFB8)($s0) */
    ".word 0x3c11800a\n"   /* 80069B80: lui $s1, %hi(D_8009AFD8) */
    ".word 0x8e31afd8\n"   /* 80069B84: lw $s1, %lo(D_8009AFD8)($s1) */
    ".word 0x3c12800a\n"   /* 80069B88: lui $s2, %hi(D_8009AFDC) */
    ".word 0x8e52afdc\n"   /* 80069B8C: lw $s2, %lo(D_8009AFDC)($s2) */
    ".word 0x02006021\n"   /* 80069B90: addu $t4, $s0, $zero */
    ".word 0x3c02800a\n"   /* 80069B94: lui $v0, %hi(D_8009AFE5) */
    ".word 0x8042afe5\n"   /* 80069B98: lb $v0, %lo(D_8009AFE5)($v0) */
    ".word 0x3c010200\n"   /* 80069B9C: lui $at, (0x2000000 >> 16) */
    ".word 0x02018025\n"   /* 80069BA0: or $s0, $s0, $at */
    ".word 0x1440000e\n"   /* 80069BA4: bnez $v0, .L80069BE0 */
    ".word 0x02006021\n"   /* 80069BA8: addu $t4, $s0, $zero */
    ".word 0x8cf10008\n"   /* 80069BAC: lw $s1, 0x8($a3) */
    ".word 0x3c010060\n"   /* 80069BB0: lui $at, (0x600000 >> 16) */
    ".word 0x02218824\n"   /* 80069BB4: and $s1, $s1, $at */
    ".word 0x16200009\n"   /* 80069BB8: bnez $s1, .L80069BE0 */
    ".word 0x00000000\n"   /* 80069BBC: nop */
    ".word 0x12400008\n"   /* 80069BC0: beqz $s2, .L80069BE4 */
    ".word 0x00000000\n"   /* 80069BC4: nop */
    ".word 0x94f20006\n"   /* 80069BC8: lhu $s2, 0x6($a3) */
    ".word 0x3c0c800a\n"   /* 80069BCC: lui $t4, %hi(D_8009AFC8) */
    ".word 0x8d8cafc8\n"   /* 80069BD0: lw $t4, %lo(D_8009AFC8)($t4) */
    ".word 0x00129400\n"   /* 80069BD4: sll $s2, $s2, 16 */
    ".word 0x0801a6f9\n"   /* 80069BD8: j .L80069BE4 */
    ".word 0x3c110020\n"   /* 80069BDC: lui $s1, (0x200000 >> 16) */
    ".word 0x24120000\n"   /* 80069BE0: addiu $s2, $zero, 0x0 */
    ".word 0x3c0d800a\n"   /* 80069BE4: lui $t5, %hi(D_8009AFE4) */
    ".word 0x81adafe4\n"   /* 80069BE8: lb $t5, %lo(D_8009AFE4)($t5) */
    ".word 0x00109e02\n"   /* 80069BEC: srl $s3, $s0, 24 */
    ".word 0x00139e00\n"   /* 80069BF0: sll $s3, $s3, 24 */
    ".word 0x24010001\n"   /* 80069BF4: addiu $at, $zero, 0x1 */
    ".word 0x11a10086\n"   /* 80069BF8: beq $t5, $at, .L80069E14 */
    ".word 0x3c14e200\n"   /* 80069BFC: lui $s4, (0xE2000000 >> 16) */
    ".word 0x3c0d800a\n"   /* 80069C00: lui $t5, %hi(D_8009AFE0) */
    ".word 0x8dadafe0\n"   /* 80069C04: lw $t5, %lo(D_8009AFE0)($t5) */
    ".word 0x8c85001c\n"   /* 80069C08: lw $a1, 0x1C($a0) */
    ".word 0x8c860024\n"   /* 80069C0C: lw $a2, 0x24($a0) */
    ".word 0x11a00002\n"   /* 80069C10: beqz $t5, .L80069C1C */
    ".word 0x00000000\n"   /* 80069C14: nop */
    ".word 0x24c60004\n"   /* 80069C18: addiu $a2, $a2, 0x4 */
    ".word 0x8c8d0004\n"   /* 80069C1C: lw $t5, 0x4($a0) */
    ".word 0x8c8e0008\n"   /* 80069C20: lw $t6, 0x8($a0) */
    ".word 0x8daf0004\n"   /* 80069C24: lw $t7, 0x4($t5) */
    ".word 0x2403ffff\n"   /* 80069C28: addiu $v1, $zero, -0x1 */
    ".word 0x8ce80010\n"   /* 80069C2C: lw $t0, 0x10($a3) */
    ".word 0x98e8000e\n"   /* 80069C30: lwr $t0, 0xE($a3) */
    ".word 0x8ce90014\n"   /* 80069C34: lw $t1, 0x14($a3) */
    ".word 0x8cea0018\n"   /* 80069C38: lw $t2, 0x18($a3) */
    ".word 0x8ceb001c\n"   /* 80069C3C: lw $t3, 0x1C($a3) */
    ".word 0x00086c02\n"   /* 80069C40: srl $t5, $t0, 16 */
    ".word 0x000d68c0\n"   /* 80069C44: sll $t5, $t5, 3 */
    ".word 0x01a56821\n"   /* 80069C48: addu $t5, $t5, $a1 */
    ".word 0x8da20004\n"   /* 80069C4C: lw $v0, 0x4($t5) */
    ".word 0x8dad0000\n"   /* 80069C50: lw $t5, 0x0($t5) */
    ".word 0x1043006c\n"   /* 80069C54: beq $v0, $v1, .L80069E08 */
    ".word 0x48828000\n"   /* 80069C58: mtc2 $v0, $16 */
    ".word 0x488d6000\n"   /* 80069C5C: mtc2 $t5, $12 */
    ".word 0xaf2d000c\n"   /* 80069C60: sw $t5, 0xC($t9) */
    ".word 0x00096c02\n"   /* 80069C64: srl $t5, $t1, 16 */
    ".word 0x000d68c0\n"   /* 80069C68: sll $t5, $t5, 3 */
    ".word 0x01a56821\n"   /* 80069C6C: addu $t5, $t5, $a1 */
    ".word 0x8da20004\n"   /* 80069C70: lw $v0, 0x4($t5) */
    ".word 0x8dad0000\n"   /* 80069C74: lw $t5, 0x0($t5) */
    ".word 0x10430063\n"   /* 80069C78: beq $v0, $v1, .L80069E08 */
    ".word 0x48828800\n"   /* 80069C7C: mtc2 $v0, $17 */
    ".word 0x488d6800\n"   /* 80069C80: mtc2 $t5, $13 */
    ".word 0xaf2d0018\n"   /* 80069C84: sw $t5, 0x18($t9) */
    ".word 0x000a6c02\n"   /* 80069C88: srl $t5, $t2, 16 */
    ".word 0x000d68c0\n"   /* 80069C8C: sll $t5, $t5, 3 */
    ".word 0x01a56821\n"   /* 80069C90: addu $t5, $t5, $a1 */
    ".word 0x8da20004\n"   /* 80069C94: lw $v0, 0x4($t5) */
    ".word 0x8dad0000\n"   /* 80069C98: lw $t5, 0x0($t5) */
    ".word 0x1043005a\n"   /* 80069C9C: beq $v0, $v1, .L80069E08 */
    ".word 0x48829000\n"   /* 80069CA0: mtc2 $v0, $18 */
    ".word 0x488d7000\n"   /* 80069CA4: mtc2 $t5, $14 */
    ".word 0xaf2d0024\n"   /* 80069CA8: sw $t5, 0x24($t9) */
    ".word 0x000b6c02\n"   /* 80069CAC: srl $t5, $t3, 16 */
    ".word 0x000d68c0\n"   /* 80069CB0: sll $t5, $t5, 3 */
    ".word 0x01a56821\n"   /* 80069CB4: addu $t5, $t5, $a1 */
    ".word 0x8da20004\n"   /* 80069CB8: lw $v0, 0x4($t5) */
    ".word 0x8dad0000\n"   /* 80069CBC: lw $t5, 0x0($t5) */
    ".word 0x10430051\n"   /* 80069CC0: beq $v0, $v1, .L80069E08 */
    ".word 0x48829800\n"   /* 80069CC4: mtc2 $v0, $19 */
    ".word 0xaf2d0030\n"   /* 80069CC8: sw $t5, 0x30($t9) */
    ".word 0x00084400\n"   /* 80069CCC: sll $t0, $t0, 16 */
    ".word 0x00084342\n"   /* 80069CD0: srl $t0, $t0, 13 */
    ".word 0x00094c00\n"   /* 80069CD4: sll $t1, $t1, 16 */
    ".word 0x00094b42\n"   /* 80069CD8: srl $t1, $t1, 13 */
    ".word 0x000a5400\n"   /* 80069CDC: sll $t2, $t2, 16 */
    ".word 0x000a5342\n"   /* 80069CE0: srl $t2, $t2, 13 */
    ".word 0x000b5c00\n"   /* 80069CE4: sll $t3, $t3, 16 */
    ".word 0x000b5b42\n"   /* 80069CE8: srl $t3, $t3, 13 */
    ".word 0x01064021\n"   /* 80069CEC: addu $t0, $t0, $a2 */
    ".word 0x01264821\n"   /* 80069CF0: addu $t1, $t1, $a2 */
    ".word 0x01465021\n"   /* 80069CF4: addu $t2, $t2, $a2 */
    ".word 0x01665821\n"   /* 80069CF8: addu $t3, $t3, $a2 */
    ".word 0x8d080000\n"   /* 80069CFC: lw $t0, 0x0($t0) */
    ".word 0x8d290000\n"   /* 80069D00: lw $t1, 0x0($t1) */
    ".word 0x8d4a0000\n"   /* 80069D04: lw $t2, 0x0($t2) */
    ".word 0x8d6b0000\n"   /* 80069D08: lw $t3, 0x0($t3) */
    ".word 0x01134025\n"   /* 80069D0C: or $t0, $t0, $s3 */
    ".word 0xaf280008\n"   /* 80069D10: sw $t0, 0x8($t9) */
    ".word 0xaf290014\n"   /* 80069D14: sw $t1, 0x14($t9) */
    ".word 0xaf2a0020\n"   /* 80069D18: sw $t2, 0x20($t9) */
    ".word 0xaf2b002c\n"   /* 80069D1C: sw $t3, 0x2C($t9) */
    ".word 0x4b68002e\n"   /* 80069D20: avsz4 */
    ".word 0x8cf50000\n"   /* 80069D24: lw $s5, 0x0($a3) */
    ".word 0x8ce80004\n"   /* 80069D28: lw $t0, 0x4($a3) */
    ".word 0x8ce90008\n"   /* 80069D2C: lw $t1, 0x8($a3) */
    ".word 0x8cea000c\n"   /* 80069D30: lw $t2, 0xC($a3) */
    ".word 0x8ceb0010\n"   /* 80069D34: lw $t3, 0x10($a3) */
    ".word 0x48023800\n"   /* 80069D38: mfc2 $v0, $7 */
    ".word 0x3c010200\n"   /* 80069D3C: lui $at, (0x2000000 >> 16) */
    ".word 0x02011824\n"   /* 80069D40: and $v1, $s0, $at */
    ".word 0x3c01ff9f\n"   /* 80069D44: lui $at, (0xFF9FFFFF >> 16) */
    ".word 0x3421ffff\n"   /* 80069D48: ori $at, $at, (0xFF9FFFFF & 0xFFFF) */
    ".word 0x01214824\n"   /* 80069D4C: and $t1, $t1, $at */
    ".word 0x01314825\n"   /* 80069D50: or $t1, $t1, $s1 */
    ".word 0x01c21006\n"   /* 80069D54: srlv $v0, $v0, $t6 */
    ".word 0x00021080\n"   /* 80069D58: sll $v0, $v0, 2 */
    ".word 0x004f1021\n"   /* 80069D5C: addu $v0, $v0, $t7 */
    ".word 0x8c4d0000\n"   /* 80069D60: lw $t5, 0x0($v0) */
    ".word 0xaf280010\n"   /* 80069D64: sw $t0, 0x10($t9) */
    ".word 0xaf29001c\n"   /* 80069D68: sw $t1, 0x1C($t9) */
    ".word 0xaf2a0028\n"   /* 80069D6C: sw $t2, 0x28($t9) */
    ".word 0xaf2b0034\n"   /* 80069D70: sw $t3, 0x34($t9) */
    ".word 0xaf350004\n"   /* 80069D74: sw $s5, 0x4($t9) */
    ".word 0xaf340038\n"   /* 80069D78: sw $s4, 0x38($t9) */
    ".word 0x000d6a00\n"   /* 80069D7C: sll $t5, $t5, 8 */
    ".word 0x35ad000e\n"   /* 80069D80: ori $t5, $t5, 0xE */
    ".word 0x000d0a02\n"   /* 80069D84: srl $at, $t5, 8 */
    ".word 0x000d6e00\n"   /* 80069D88: sll $t5, $t5, 24 */
    ".word 0x01a16825\n"   /* 80069D8C: or $t5, $t5, $at */
    ".word 0xaf2d0000\n"   /* 80069D90: sw $t5, 0x0($t9) */
    ".word 0x00196a00\n"   /* 80069D94: sll $t5, $t9, 8 */
    ".word 0x000d6a02\n"   /* 80069D98: srl $t5, $t5, 8 */
    ".word 0x10600019\n"   /* 80069D9C: beqz $v1, .L80069E04 */
    ".word 0xac4d0000\n"   /* 80069DA0: sw $t5, 0x0($v0) */
    ".word 0x12400017\n"   /* 80069DA4: beqz $s2, .L80069E04 */
    ".word 0x00084400\n"   /* 80069DA8: sll $t0, $t0, 16 */
    ".word 0x00084402\n"   /* 80069DAC: srl $t0, $t0, 16 */
    ".word 0x01124025\n"   /* 80069DB0: or $t0, $t0, $s2 */
    ".word 0x3c01ff9f\n"   /* 80069DB4: lui $at, (0xFF9FFFFF >> 16) */
    ".word 0x3421ffff\n"   /* 80069DB8: ori $at, $at, (0xFF9FFFFF & 0xFFFF) */
    ".word 0x01214824\n"   /* 80069DBC: and $t1, $t1, $at */
    ".word 0x3c010040\n"   /* 80069DC0: lui $at, (0x400000 >> 16) */
    ".word 0x01214825\n"   /* 80069DC4: or $t1, $t1, $at */
    ".word 0x8f23000c\n"   /* 80069DC8: lw $v1, 0xC($t9) */
    ".word 0xaf2c0044\n"   /* 80069DCC: sw $t4, 0x44($t9) */
    ".word 0xaf230048\n"   /* 80069DD0: sw $v1, 0x48($t9) */
    ".word 0x8f230018\n"   /* 80069DD4: lw $v1, 0x18($t9) */
    ".word 0xaf2c0050\n"   /* 80069DD8: sw $t4, 0x50($t9) */
    ".word 0xaf230054\n"   /* 80069DDC: sw $v1, 0x54($t9) */
    ".word 0x8f230024\n"   /* 80069DE0: lw $v1, 0x24($t9) */
    ".word 0xaf2c005c\n"   /* 80069DE4: sw $t4, 0x5C($t9) */
    ".word 0xaf230060\n"   /* 80069DE8: sw $v1, 0x60($t9) */
    ".word 0x8f230030\n"   /* 80069DEC: lw $v1, 0x30($t9) */
    ".word 0xaf2c0068\n"   /* 80069DF0: sw $t4, 0x68($t9) */
    ".word 0xaf23006c\n"   /* 80069DF4: sw $v1, 0x6C($t9) */
    ".word 0x2739003c\n"   /* 80069DF8: addiu $t9, $t9, 0x3C */
    ".word 0x0801a759\n"   /* 80069DFC: j .L80069D64 */
    ".word 0x24030000\n"   /* 80069E00: addiu $v1, $zero, 0x0 */
    ".word 0x2739003c\n"   /* 80069E04: addiu $t9, $t9, 0x3C */
    ".word 0x2718ffff\n"   /* 80069E08: addiu $t8, $t8, -0x1 */
    ".word 0x1700ff86\n"   /* 80069E0C: bnez $t8, .L80069C28 */
    ".word 0x24e70020\n"   /* 80069E10: addiu $a3, $a3, 0x20 */
    ".word 0x8c900028\n"   /* 80069E14: lw $s0, 0x28($a0) */
    ".word 0x8c91002c\n"   /* 80069E18: lw $s1, 0x2C($a0) */
    ".word 0x8c920030\n"   /* 80069E1C: lw $s2, 0x30($a0) */
    ".word 0x8c930034\n"   /* 80069E20: lw $s3, 0x34($a0) */
    ".word 0x8c940038\n"   /* 80069E24: lw $s4, 0x38($a0) */
    ".word 0x8c95003c\n"   /* 80069E28: lw $s5, 0x3C($a0) */
    ".word 0x8c820000\n"   /* 80069E2C: lw $v0, 0x0($a0) */
    ".word 0x3c018010\n"   /* 80069E30: lui $at, %hi(D_800FE240) */
    ".word 0xac39e240\n"   /* 80069E34: sw $t9, %lo(D_800FE240)($at) */
    ".word 0x24420008\n"   /* 80069E38: addiu $v0, $v0, 0x8 */
    ".word 0x03e00008\n"   /* 80069E3C: jr $ra */
    ".word 0x00000000\n"   /* 80069E40: nop */
    ".set reorder\n"
);
