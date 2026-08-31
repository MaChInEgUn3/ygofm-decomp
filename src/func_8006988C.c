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

/* Whole-function raw-asm transcription (GTE OT-insert family, see
   project_gte_register_spill_and_pin_techniques.md). */
__asm__(
    ".set noreorder\n"
    ".global func_8006988C\n"
    "func_8006988C:\n"
".word 0x8C870000\n\t" /* 8006988C: lw         $a3, 0x0($a0) */
".word 0x8C990010\n\t" /* 80069890: lw         $t9, 0x10($a0) */
".word 0x94F80002\n\t" /* 80069894: lhu        $t8, 0x2($a3) */
".word 0x8CE60004\n\t" /* 80069898: lw         $a2, 0x4($a3) */
".word 0x8C850014\n\t" /* 8006989C: lw         $a1, 0x14($a0) */
".word 0x00063080\n\t" /* 800698A0: sll        $a2, $a2, 2 */
".word 0xAC900028\n\t" /* 800698A4: sw         $s0, 0x28($a0) */
".word 0xAC91002C\n\t" /* 800698A8: sw         $s1, 0x2C($a0) */
".word 0xAC920030\n\t" /* 800698AC: sw         $s2, 0x30($a0) */
".word 0xAC930034\n\t" /* 800698B0: sw         $s3, 0x34($a0) */
".word 0xAC940038\n\t" /* 800698B4: sw         $s4, 0x38($a0) */
".word 0xAC95003C\n\t" /* 800698B8: sw         $s5, 0x3C($a0) */
".word 0x13000094\n\t" /* 800698BC: beqz       $t8, .L80069B10 */
".word 0x00A63821\n\t" /* 800698C0: addu      $a3, $a1, $a2 */
".word 0x3C10800A\n\t" /* 800698C4: lui        $s0, %hi(D_8009AFB4) */
".word 0x8E10AFB4\n\t" /* 800698C8: lw         $s0, %lo(D_8009AFB4)($s0) */
".word 0x3C11800A\n\t" /* 800698CC: lui        $s1, %hi(D_8009AFD8) */
".word 0x8E31AFD8\n\t" /* 800698D0: lw         $s1, %lo(D_8009AFD8)($s1) */
".word 0x3C12800A\n\t" /* 800698D4: lui        $s2, %hi(D_8009AFDC) */
".word 0x8E52AFDC\n\t" /* 800698D8: lw         $s2, %lo(D_8009AFDC)($s2) */
".word 0x02006021\n\t" /* 800698DC: addu       $t4, $s0, $zero */
".word 0x3C02800A\n\t" /* 800698E0: lui        $v0, %hi(D_8009AFE5) */
".word 0x8042AFE5\n\t" /* 800698E4: lb         $v0, %lo(D_8009AFE5)($v0) */
".word 0x3C010200\n\t" /* 800698E8: lui        $at, (0x2000000 >> 16) */
".word 0x02018025\n\t" /* 800698EC: or         $s0, $s0, $at */
".word 0x1440000E\n\t" /* 800698F0: bnez       $v0, .L8006992C */
".word 0x02006021\n\t" /* 800698F4: addu      $t4, $s0, $zero */
".word 0x8CF10008\n\t" /* 800698F8: lw         $s1, 0x8($a3) */
".word 0x3C010060\n\t" /* 800698FC: lui        $at, (0x600000 >> 16) */
".word 0x02218824\n\t" /* 80069900: and        $s1, $s1, $at */
".word 0x16200009\n\t" /* 80069904: bnez       $s1, .L8006992C */
".word 0x00000000\n\t" /* 80069908: nop */
".word 0x12400008\n\t" /* 8006990C: beqz       $s2, .L80069930 */
".word 0x00000000\n\t" /* 80069910: nop */
".word 0x94F20006\n\t" /* 80069914: lhu        $s2, 0x6($a3) */
".word 0x3C0C800A\n\t" /* 80069918: lui        $t4, %hi(D_8009AFC4) */
".word 0x8D8CAFC4\n\t" /* 8006991C: lw         $t4, %lo(D_8009AFC4)($t4) */
".word 0x00129400\n\t" /* 80069920: sll        $s2, $s2, 16 */
".word 0x0801A64C\n\t" /* 80069924: j          .L80069930 */
".word 0x3C110020\n\t" /* 80069928: lui       $s1, (0x200000 >> 16) */
".L8006992C:\n\t"
".word 0x24120000\n\t" /* 8006992C: addiu      $s2, $zero, 0x0 */
".L80069930:\n\t"
".word 0x3C0D800A\n\t" /* 80069930: lui        $t5, %hi(D_8009AFE4) */
".word 0x81ADAFE4\n\t" /* 80069934: lb         $t5, %lo(D_8009AFE4)($t5) */
".word 0x00109E02\n\t" /* 80069938: srl        $s3, $s0, 24 */
".word 0x00139E00\n\t" /* 8006993C: sll        $s3, $s3, 24 */
".word 0x24010001\n\t" /* 80069940: addiu      $at, $zero, 0x1 */
".word 0x11A10072\n\t" /* 80069944: beq        $t5, $at, .L80069B10 */
".word 0x3C14E200\n\t" /* 80069948: lui       $s4, (0xE2000000 >> 16) */
".word 0x3C0D800A\n\t" /* 8006994C: lui        $t5, %hi(D_8009AFE0) */
".word 0x8DADAFE0\n\t" /* 80069950: lw         $t5, %lo(D_8009AFE0)($t5) */
".word 0x8C85001C\n\t" /* 80069954: lw         $a1, 0x1C($a0) */
".word 0x8C860024\n\t" /* 80069958: lw         $a2, 0x24($a0) */
".word 0x11A00002\n\t" /* 8006995C: beqz       $t5, .L80069968 */
".word 0x00000000\n\t" /* 80069960: nop */
".word 0x24C60004\n\t" /* 80069964: addiu      $a2, $a2, 0x4 */
".L80069968:\n\t"
".word 0x8C8D0004\n\t" /* 80069968: lw         $t5, 0x4($a0) */
".word 0x8C8E0008\n\t" /* 8006996C: lw         $t6, 0x8($a0) */
".word 0x8DAF0004\n\t" /* 80069970: lw         $t7, 0x4($t5) */
".L80069974:\n\t"
".word 0x2403FFFF\n\t" /* 80069974: addiu      $v1, $zero, -0x1 */
".word 0x8CE80010\n\t" /* 80069978: lw         $t0, 0x10($a3) */
".word 0x8CE90014\n\t" /* 8006997C: lw         $t1, 0x14($a3) */
".word 0x8CEA0018\n\t" /* 80069980: lw         $t2, 0x18($a3) */
".word 0x00086C02\n\t" /* 80069984: srl        $t5, $t0, 16 */
".word 0x000D68C0\n\t" /* 80069988: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 8006998C: addu       $t5, $t5, $a1 */
".word 0x8DA20004\n\t" /* 80069990: lw         $v0, 0x4($t5) */
".word 0x8DAD0000\n\t" /* 80069994: lw         $t5, 0x0($t5) */
".word 0x1043005A\n\t" /* 80069998: beq        $v0, $v1, .L80069B04 */
".word 0x48828800\n\t" /* 8006999C: mtc2      $v0, $17 ( handwritten instruction ) */
".word 0x488D6000\n\t" /* 800699A0: mtc2       $t5, $12 ( handwritten instruction ) */
".word 0xAF2D000C\n\t" /* 800699A4: sw         $t5, 0xC($t9) */
".word 0x00096C02\n\t" /* 800699A8: srl        $t5, $t1, 16 */
".word 0x000D68C0\n\t" /* 800699AC: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 800699B0: addu       $t5, $t5, $a1 */
".word 0x8DA20004\n\t" /* 800699B4: lw         $v0, 0x4($t5) */
".word 0x8DAD0000\n\t" /* 800699B8: lw         $t5, 0x0($t5) */
".word 0x10430051\n\t" /* 800699BC: beq        $v0, $v1, .L80069B04 */
".word 0x48829000\n\t" /* 800699C0: mtc2      $v0, $18 ( handwritten instruction ) */
".word 0x488D6800\n\t" /* 800699C4: mtc2       $t5, $13 ( handwritten instruction ) */
".word 0xAF2D0018\n\t" /* 800699C8: sw         $t5, 0x18($t9) */
".word 0x000A6C02\n\t" /* 800699CC: srl        $t5, $t2, 16 */
".word 0x000D68C0\n\t" /* 800699D0: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 800699D4: addu       $t5, $t5, $a1 */
".word 0x8DA20004\n\t" /* 800699D8: lw         $v0, 0x4($t5) */
".word 0x8DAD0000\n\t" /* 800699DC: lw         $t5, 0x0($t5) */
".word 0x10430048\n\t" /* 800699E0: beq        $v0, $v1, .L80069B04 */
".word 0x48829800\n\t" /* 800699E4: mtc2      $v0, $19 ( handwritten instruction ) */
".word 0x488D7000\n\t" /* 800699E8: mtc2       $t5, $14 ( handwritten instruction ) */
".word 0xAF2D0024\n\t" /* 800699EC: sw         $t5, 0x24($t9) */
".word 0x00084400\n\t" /* 800699F0: sll        $t0, $t0, 16 */
".word 0x00084342\n\t" /* 800699F4: srl        $t0, $t0, 13 */
".word 0x00094C00\n\t" /* 800699F8: sll        $t1, $t1, 16 */
".word 0x00094B42\n\t" /* 800699FC: srl        $t1, $t1, 13 */
".word 0x000A5400\n\t" /* 80069A00: sll        $t2, $t2, 16 */
".word 0x000A5342\n\t" /* 80069A04: srl        $t2, $t2, 13 */
".word 0x01064021\n\t" /* 80069A08: addu       $t0, $t0, $a2 */
".word 0x01264821\n\t" /* 80069A0C: addu       $t1, $t1, $a2 */
".word 0x01465021\n\t" /* 80069A10: addu       $t2, $t2, $a2 */
".word 0x8D080000\n\t" /* 80069A14: lw         $t0, 0x0($t0) */
".word 0x8D290000\n\t" /* 80069A18: lw         $t1, 0x0($t1) */
".word 0x8D4A0000\n\t" /* 80069A1C: lw         $t2, 0x0($t2) */
".word 0x4B58002D\n\t" /* 80069A20: avsz3 */
".word 0x01134025\n\t" /* 80069A24: or         $t0, $t0, $s3 */
".word 0xAF280008\n\t" /* 80069A28: sw         $t0, 0x8($t9) */
".word 0xAF290014\n\t" /* 80069A2C: sw         $t1, 0x14($t9) */
".word 0xAF2A0020\n\t" /* 80069A30: sw         $t2, 0x20($t9) */
".word 0x8CF50000\n\t" /* 80069A34: lw         $s5, 0x0($a3) */
".word 0x8CE80004\n\t" /* 80069A38: lw         $t0, 0x4($a3) */
".word 0x8CE90008\n\t" /* 80069A3C: lw         $t1, 0x8($a3) */
".word 0x8CEA000C\n\t" /* 80069A40: lw         $t2, 0xC($a3) */
".word 0x48023800\n\t" /* 80069A44: mfc2       $v0, $7 ( handwritten instruction ) */
".word 0x3C010200\n\t" /* 80069A48: lui        $at, (0x2000000 >> 16) */
".word 0x02011824\n\t" /* 80069A4C: and        $v1, $s0, $at */
".word 0x3C01FF9F\n\t" /* 80069A50: lui        $at, (0xFF9FFFFF >> 16) */
".word 0x3421FFFF\n\t" /* 80069A54: ori        $at, $at, (0xFF9FFFFF & 0xFFFF) */
".word 0x01214824\n\t" /* 80069A58: and        $t1, $t1, $at */
".word 0x01314825\n\t" /* 80069A5C: or         $t1, $t1, $s1 */
".word 0x01C21006\n\t" /* 80069A60: srlv       $v0, $v0, $t6 */
".word 0x00021080\n\t" /* 80069A64: sll        $v0, $v0, 2 */
".word 0x004F1021\n\t" /* 80069A68: addu       $v0, $v0, $t7 */
".word 0x8C4D0000\n\t" /* 80069A6C: lw         $t5, 0x0($v0) */
".L80069A70:\n\t"
".word 0xAF280010\n\t" /* 80069A70: sw         $t0, 0x10($t9) */
".word 0xAF29001C\n\t" /* 80069A74: sw         $t1, 0x1C($t9) */
".word 0xAF2A0028\n\t" /* 80069A78: sw         $t2, 0x28($t9) */
".word 0xAF350004\n\t" /* 80069A7C: sw         $s5, 0x4($t9) */
".word 0xAF34002C\n\t" /* 80069A80: sw         $s4, 0x2C($t9) */
".word 0x000D6A00\n\t" /* 80069A84: sll        $t5, $t5, 8 */
".word 0x35AD000B\n\t" /* 80069A88: ori        $t5, $t5, 0xB */
".word 0x000D0A02\n\t" /* 80069A8C: srl        $at, $t5, 8 */
".word 0x000D6E00\n\t" /* 80069A90: sll        $t5, $t5, 24 */
".word 0x01A16825\n\t" /* 80069A94: or         $t5, $t5, $at */
".word 0xAF2D0000\n\t" /* 80069A98: sw         $t5, 0x0($t9) */
".word 0x00196A00\n\t" /* 80069A9C: sll        $t5, $t9, 8 */
".word 0x000D6A02\n\t" /* 80069AA0: srl        $t5, $t5, 8 */
".word 0x10600016\n\t" /* 80069AA4: beqz       $v1, .L80069B00 */
".word 0xAC4D0000\n\t" /* 80069AA8: sw        $t5, 0x0($v0) */
".word 0x12400014\n\t" /* 80069AAC: beqz       $s2, .L80069B00 */
".word 0x00084400\n\t" /* 80069AB0: sll       $t0, $t0, 16 */
".word 0x00084402\n\t" /* 80069AB4: srl        $t0, $t0, 16 */
".word 0x01124025\n\t" /* 80069AB8: or         $t0, $t0, $s2 */
".word 0x3C01FF9F\n\t" /* 80069ABC: lui        $at, (0xFF9FFFFF >> 16) */
".word 0x3421FFFF\n\t" /* 80069AC0: ori        $at, $at, (0xFF9FFFFF & 0xFFFF) */
".word 0x01214824\n\t" /* 80069AC4: and        $t1, $t1, $at */
".word 0x3C010040\n\t" /* 80069AC8: lui        $at, (0x400000 >> 16) */
".word 0x01214825\n\t" /* 80069ACC: or         $t1, $t1, $at */
".word 0x8F23000C\n\t" /* 80069AD0: lw         $v1, 0xC($t9) */
".word 0xAF2C0038\n\t" /* 80069AD4: sw         $t4, 0x38($t9) */
".word 0xAF23003C\n\t" /* 80069AD8: sw         $v1, 0x3C($t9) */
".word 0x8F230018\n\t" /* 80069ADC: lw         $v1, 0x18($t9) */
".word 0xAF2C0044\n\t" /* 80069AE0: sw         $t4, 0x44($t9) */
".word 0xAF230048\n\t" /* 80069AE4: sw         $v1, 0x48($t9) */
".word 0x8F230024\n\t" /* 80069AE8: lw         $v1, 0x24($t9) */
".word 0xAF2C0050\n\t" /* 80069AEC: sw         $t4, 0x50($t9) */
".word 0xAF230054\n\t" /* 80069AF0: sw         $v1, 0x54($t9) */
".word 0x27390030\n\t" /* 80069AF4: addiu      $t9, $t9, 0x30 */
".word 0x0801A69C\n\t" /* 80069AF8: j          .L80069A70 */
".word 0x24030000\n\t" /* 80069AFC: addiu     $v1, $zero, 0x0 */
".L80069B00:\n\t"
".word 0x27390030\n\t" /* 80069B00: addiu      $t9, $t9, 0x30 */
".L80069B04:\n\t"
".word 0x2718FFFF\n\t" /* 80069B04: addiu      $t8, $t8, -0x1 */
".word 0x1700FF9A\n\t" /* 80069B08: bnez       $t8, .L80069974 */
".word 0x24E7001C\n\t" /* 80069B0C: addiu     $a3, $a3, 0x1C */
".L80069B10:\n\t"
".word 0x8C900028\n\t" /* 80069B10: lw         $s0, 0x28($a0) */
".word 0x8C91002C\n\t" /* 80069B14: lw         $s1, 0x2C($a0) */
".word 0x8C920030\n\t" /* 80069B18: lw         $s2, 0x30($a0) */
".word 0x8C930034\n\t" /* 80069B1C: lw         $s3, 0x34($a0) */
".word 0x8C940038\n\t" /* 80069B20: lw         $s4, 0x38($a0) */
".word 0x8C95003C\n\t" /* 80069B24: lw         $s5, 0x3C($a0) */
".word 0x8C820000\n\t" /* 80069B28: lw         $v0, 0x0($a0) */
".word 0x3C018010\n\t" /* 80069B2C: lui        $at, %hi(D_800FE240) */
".word 0xAC39E240\n\t" /* 80069B30: sw         $t9, %lo(D_800FE240)($at) */
".word 0x24420008\n\t" /* 80069B34: addiu      $v0, $v0, 0x8 */
".word 0x03E00008\n\t" /* 80069B38: jr         $ra */
".word 0x00000000\n\t" /* 80069B3C: nop */
    ".set reorder\n"
);
