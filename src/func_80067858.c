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
    ".global func_80067858\n"
    "func_80067858:\n"
".word 0x8C870000\n\t" /* 80067858: lw         $a3, 0x0($a0) */
".word 0x8C990010\n\t" /* 8006785C: lw         $t9, 0x10($a0) */
".word 0x94F80002\n\t" /* 80067860: lhu        $t8, 0x2($a3) */
".word 0x8CE60004\n\t" /* 80067864: lw         $a2, 0x4($a3) */
".word 0x8C850014\n\t" /* 80067868: lw         $a1, 0x14($a0) */
".word 0x00063080\n\t" /* 8006786C: sll        $a2, $a2, 2 */
".word 0xAC900028\n\t" /* 80067870: sw         $s0, 0x28($a0) */
".word 0xAC91002C\n\t" /* 80067874: sw         $s1, 0x2C($a0) */
".word 0xAC920030\n\t" /* 80067878: sw         $s2, 0x30($a0) */
".word 0xAC930034\n\t" /* 8006787C: sw         $s3, 0x34($a0) */
".word 0xAC940038\n\t" /* 80067880: sw         $s4, 0x38($a0) */
".word 0xAC95003C\n\t" /* 80067884: sw         $s5, 0x3C($a0) */
".word 0x13000080\n\t" /* 80067888: beqz       $t8, .L80067A8C */
".word 0x00A63821\n\t" /* 8006788C: addu      $a3, $a1, $a2 */
".word 0x3C10800A\n\t" /* 80067890: lui        $s0, %hi(D_8009AFB4) */
".word 0x8E10AFB4\n\t" /* 80067894: lw         $s0, %lo(D_8009AFB4)($s0) */
".word 0x3C11800A\n\t" /* 80067898: lui        $s1, %hi(D_8009AFD8) */
".word 0x8E31AFD8\n\t" /* 8006789C: lw         $s1, %lo(D_8009AFD8)($s1) */
".word 0x3C12800A\n\t" /* 800678A0: lui        $s2, %hi(D_8009AFDC) */
".word 0x8E52AFDC\n\t" /* 800678A4: lw         $s2, %lo(D_8009AFDC)($s2) */
".word 0x02006021\n\t" /* 800678A8: addu       $t4, $s0, $zero */
".word 0x3C0D800A\n\t" /* 800678AC: lui        $t5, %hi(D_8009AFE4) */
".word 0x81ADAFE4\n\t" /* 800678B0: lb         $t5, %lo(D_8009AFE4)($t5) */
".word 0x00109E02\n\t" /* 800678B4: srl        $s3, $s0, 24 */
".word 0x00139E00\n\t" /* 800678B8: sll        $s3, $s3, 24 */
".word 0x24010001\n\t" /* 800678BC: addiu      $at, $zero, 0x1 */
".word 0x11A10072\n\t" /* 800678C0: beq        $t5, $at, .L80067A8C */
".word 0x3C14E200\n\t" /* 800678C4: lui       $s4, (0xE2000000 >> 16) */
".word 0x3C0D800A\n\t" /* 800678C8: lui        $t5, %hi(D_8009AFE0) */
".word 0x8DADAFE0\n\t" /* 800678CC: lw         $t5, %lo(D_8009AFE0)($t5) */
".word 0x8C85001C\n\t" /* 800678D0: lw         $a1, 0x1C($a0) */
".word 0x8C860024\n\t" /* 800678D4: lw         $a2, 0x24($a0) */
".word 0x11A00002\n\t" /* 800678D8: beqz       $t5, .L800678E4 */
".word 0x00000000\n\t" /* 800678DC: nop */
".word 0x24C60004\n\t" /* 800678E0: addiu      $a2, $a2, 0x4 */
".L800678E4:\n\t"
".word 0x8C8D0004\n\t" /* 800678E4: lw         $t5, 0x4($a0) */
".word 0x8C8E0008\n\t" /* 800678E8: lw         $t6, 0x8($a0) */
".word 0x8DAF0004\n\t" /* 800678EC: lw         $t7, 0x4($t5) */
".L800678F0:\n\t"
".word 0x2403FFFF\n\t" /* 800678F0: addiu      $v1, $zero, -0x1 */
".word 0x8CE80010\n\t" /* 800678F4: lw         $t0, 0x10($a3) */
".word 0x8CE90014\n\t" /* 800678F8: lw         $t1, 0x14($a3) */
".word 0x8CEA0018\n\t" /* 800678FC: lw         $t2, 0x18($a3) */
".word 0x00086C02\n\t" /* 80067900: srl        $t5, $t0, 16 */
".word 0x000D68C0\n\t" /* 80067904: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 80067908: addu       $t5, $t5, $a1 */
".word 0x8DA20004\n\t" /* 8006790C: lw         $v0, 0x4($t5) */
".word 0x8DAD0000\n\t" /* 80067910: lw         $t5, 0x0($t5) */
".word 0x1043005A\n\t" /* 80067914: beq        $v0, $v1, .L80067A80 */
".word 0x48828800\n\t" /* 80067918: mtc2      $v0, $17 ( handwritten instruction ) */
".word 0x488D6000\n\t" /* 8006791C: mtc2       $t5, $12 ( handwritten instruction ) */
".word 0xAF2D000C\n\t" /* 80067920: sw         $t5, 0xC($t9) */
".word 0x00096C02\n\t" /* 80067924: srl        $t5, $t1, 16 */
".word 0x000D68C0\n\t" /* 80067928: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 8006792C: addu       $t5, $t5, $a1 */
".word 0x8DA20004\n\t" /* 80067930: lw         $v0, 0x4($t5) */
".word 0x8DAD0000\n\t" /* 80067934: lw         $t5, 0x0($t5) */
".word 0x10430051\n\t" /* 80067938: beq        $v0, $v1, .L80067A80 */
".word 0x48829000\n\t" /* 8006793C: mtc2      $v0, $18 ( handwritten instruction ) */
".word 0x488D6800\n\t" /* 80067940: mtc2       $t5, $13 ( handwritten instruction ) */
".word 0xAF2D0018\n\t" /* 80067944: sw         $t5, 0x18($t9) */
".word 0x000A6C02\n\t" /* 80067948: srl        $t5, $t2, 16 */
".word 0x000D68C0\n\t" /* 8006794C: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 80067950: addu       $t5, $t5, $a1 */
".word 0x8DA20004\n\t" /* 80067954: lw         $v0, 0x4($t5) */
".word 0x8DAD0000\n\t" /* 80067958: lw         $t5, 0x0($t5) */
".word 0x10430048\n\t" /* 8006795C: beq        $v0, $v1, .L80067A80 */
".word 0x48829800\n\t" /* 80067960: mtc2      $v0, $19 ( handwritten instruction ) */
".word 0x488D7000\n\t" /* 80067964: mtc2       $t5, $14 ( handwritten instruction ) */
".word 0xAF2D0024\n\t" /* 80067968: sw         $t5, 0x24($t9) */
".word 0x00084400\n\t" /* 8006796C: sll        $t0, $t0, 16 */
".word 0x00084342\n\t" /* 80067970: srl        $t0, $t0, 13 */
".word 0x4B400006\n\t" /* 80067974: nclip */
".word 0x00094C00\n\t" /* 80067978: sll        $t1, $t1, 16 */
".word 0x00094B42\n\t" /* 8006797C: srl        $t1, $t1, 13 */
".word 0x000A5400\n\t" /* 80067980: sll        $t2, $t2, 16 */
".word 0x000A5342\n\t" /* 80067984: srl        $t2, $t2, 13 */
".word 0x01064021\n\t" /* 80067988: addu       $t0, $t0, $a2 */
".word 0x4802C000\n\t" /* 8006798C: mfc2       $v0, $24 ( handwritten instruction ) */
".word 0x01264821\n\t" /* 80067990: addu       $t1, $t1, $a2 */
".word 0x1840003A\n\t" /* 80067994: blez       $v0, .L80067A80 */
".word 0x01465021\n\t" /* 80067998: addu      $t2, $t2, $a2 */
".word 0x8D080000\n\t" /* 8006799C: lw         $t0, 0x0($t0) */
".word 0x8D290000\n\t" /* 800679A0: lw         $t1, 0x0($t1) */
".word 0x8D4A0000\n\t" /* 800679A4: lw         $t2, 0x0($t2) */
".word 0x01134025\n\t" /* 800679A8: or         $t0, $t0, $s3 */
".word 0xAF280008\n\t" /* 800679AC: sw         $t0, 0x8($t9) */
".word 0xAF290014\n\t" /* 800679B0: sw         $t1, 0x14($t9) */
".word 0xAF2A0020\n\t" /* 800679B4: sw         $t2, 0x20($t9) */
".word 0x4B58002D\n\t" /* 800679B8: avsz3 */
".word 0x8CF50000\n\t" /* 800679BC: lw         $s5, 0x0($a3) */
".word 0x8CE80004\n\t" /* 800679C0: lw         $t0, 0x4($a3) */
".word 0x8CE90008\n\t" /* 800679C4: lw         $t1, 0x8($a3) */
".word 0x8CEA000C\n\t" /* 800679C8: lw         $t2, 0xC($a3) */
".word 0x48023800\n\t" /* 800679CC: mfc2       $v0, $7 ( handwritten instruction ) */
".word 0x3C010200\n\t" /* 800679D0: lui        $at, (0x2000000 >> 16) */
".word 0x02011824\n\t" /* 800679D4: and        $v1, $s0, $at */
".word 0x01314825\n\t" /* 800679D8: or         $t1, $t1, $s1 */
".word 0x01C21006\n\t" /* 800679DC: srlv       $v0, $v0, $t6 */
".word 0x00021080\n\t" /* 800679E0: sll        $v0, $v0, 2 */
".word 0x004F1021\n\t" /* 800679E4: addu       $v0, $v0, $t7 */
".word 0x8C4D0000\n\t" /* 800679E8: lw         $t5, 0x0($v0) */
".L800679EC:\n\t"
".word 0xAF280010\n\t" /* 800679EC: sw         $t0, 0x10($t9) */
".word 0xAF29001C\n\t" /* 800679F0: sw         $t1, 0x1C($t9) */
".word 0xAF2A0028\n\t" /* 800679F4: sw         $t2, 0x28($t9) */
".word 0xAF350004\n\t" /* 800679F8: sw         $s5, 0x4($t9) */
".word 0xAF34002C\n\t" /* 800679FC: sw         $s4, 0x2C($t9) */
".word 0x000D6A00\n\t" /* 80067A00: sll        $t5, $t5, 8 */
".word 0x35AD000B\n\t" /* 80067A04: ori        $t5, $t5, 0xB */
".word 0x000D0A02\n\t" /* 80067A08: srl        $at, $t5, 8 */
".word 0x000D6E00\n\t" /* 80067A0C: sll        $t5, $t5, 24 */
".word 0x01A16825\n\t" /* 80067A10: or         $t5, $t5, $at */
".word 0xAF2D0000\n\t" /* 80067A14: sw         $t5, 0x0($t9) */
".word 0x00196A00\n\t" /* 80067A18: sll        $t5, $t9, 8 */
".word 0x000D6A02\n\t" /* 80067A1C: srl        $t5, $t5, 8 */
".word 0x10600016\n\t" /* 80067A20: beqz       $v1, .L80067A7C */
".word 0xAC4D0000\n\t" /* 80067A24: sw        $t5, 0x0($v0) */
".word 0x12400014\n\t" /* 80067A28: beqz       $s2, .L80067A7C */
".word 0x00084400\n\t" /* 80067A2C: sll       $t0, $t0, 16 */
".word 0x00084402\n\t" /* 80067A30: srl        $t0, $t0, 16 */
".word 0x01124025\n\t" /* 80067A34: or         $t0, $t0, $s2 */
".word 0x3C01FF9F\n\t" /* 80067A38: lui        $at, (0xFF9FFFFF >> 16) */
".word 0x3421FFFF\n\t" /* 80067A3C: ori        $at, $at, (0xFF9FFFFF & 0xFFFF) */
".word 0x01214824\n\t" /* 80067A40: and        $t1, $t1, $at */
".word 0x3C010040\n\t" /* 80067A44: lui        $at, (0x400000 >> 16) */
".word 0x01214825\n\t" /* 80067A48: or         $t1, $t1, $at */
".word 0x8F23000C\n\t" /* 80067A4C: lw         $v1, 0xC($t9) */
".word 0xAF2C0038\n\t" /* 80067A50: sw         $t4, 0x38($t9) */
".word 0xAF23003C\n\t" /* 80067A54: sw         $v1, 0x3C($t9) */
".word 0x8F230018\n\t" /* 80067A58: lw         $v1, 0x18($t9) */
".word 0xAF2C0044\n\t" /* 80067A5C: sw         $t4, 0x44($t9) */
".word 0xAF230048\n\t" /* 80067A60: sw         $v1, 0x48($t9) */
".word 0x8F230024\n\t" /* 80067A64: lw         $v1, 0x24($t9) */
".word 0xAF2C0050\n\t" /* 80067A68: sw         $t4, 0x50($t9) */
".word 0xAF230054\n\t" /* 80067A6C: sw         $v1, 0x54($t9) */
".word 0x27390030\n\t" /* 80067A70: addiu      $t9, $t9, 0x30 */
".word 0x08019E7B\n\t" /* 80067A74: j          .L800679EC */
".word 0x24030000\n\t" /* 80067A78: addiu     $v1, $zero, 0x0 */
".L80067A7C:\n\t"
".word 0x27390030\n\t" /* 80067A7C: addiu      $t9, $t9, 0x30 */
".L80067A80:\n\t"
".word 0x2718FFFF\n\t" /* 80067A80: addiu      $t8, $t8, -0x1 */
".word 0x1700FF9A\n\t" /* 80067A84: bnez       $t8, .L800678F0 */
".word 0x24E7001C\n\t" /* 80067A88: addiu     $a3, $a3, 0x1C */
".L80067A8C:\n\t"
".word 0x8C900028\n\t" /* 80067A8C: lw         $s0, 0x28($a0) */
".word 0x8C91002C\n\t" /* 80067A90: lw         $s1, 0x2C($a0) */
".word 0x8C920030\n\t" /* 80067A94: lw         $s2, 0x30($a0) */
".word 0x8C930034\n\t" /* 80067A98: lw         $s3, 0x34($a0) */
".word 0x8C940038\n\t" /* 80067A9C: lw         $s4, 0x38($a0) */
".word 0x8C95003C\n\t" /* 80067AA0: lw         $s5, 0x3C($a0) */
".word 0x8C820000\n\t" /* 80067AA4: lw         $v0, 0x0($a0) */
".word 0x3C018010\n\t" /* 80067AA8: lui        $at, %hi(D_800FE240) */
".word 0xAC39E240\n\t" /* 80067AAC: sw         $t9, %lo(D_800FE240)($at) */
".word 0x24420008\n\t" /* 80067AB0: addiu      $v0, $v0, 0x8 */
".word 0x03E00008\n\t" /* 80067AB4: jr         $ra */
".word 0x00000000\n\t" /* 80067AB8: nop */
    ".set reorder\n"
);
