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
    ".global func_80068A00\n"
    "func_80068A00:\n"
".word 0x8C870000\n\t" /* 80068A00: lw         $a3, 0x0($a0) */
".word 0x8C990010\n\t" /* 80068A04: lw         $t9, 0x10($a0) */
".word 0x94F80002\n\t" /* 80068A08: lhu        $t8, 0x2($a3) */
".word 0x8CE60004\n\t" /* 80068A0C: lw         $a2, 0x4($a3) */
".word 0x8C850014\n\t" /* 80068A10: lw         $a1, 0x14($a0) */
".word 0x00063080\n\t" /* 80068A14: sll        $a2, $a2, 2 */
".word 0xAC900028\n\t" /* 80068A18: sw         $s0, 0x28($a0) */
".word 0xAC91002C\n\t" /* 80068A1C: sw         $s1, 0x2C($a0) */
".word 0xAC920030\n\t" /* 80068A20: sw         $s2, 0x30($a0) */
".word 0xAC930034\n\t" /* 80068A24: sw         $s3, 0x34($a0) */
".word 0x130000B1\n\t" /* 80068A28: beqz       $t8, .L80068CF0 */
".word 0x00A63821\n\t" /* 80068A2C: addu      $a3, $a1, $a2 */
".word 0x3C10800A\n\t" /* 80068A30: lui        $s0, %hi(D_8009AFB8) */
".word 0x8E10AFB8\n\t" /* 80068A34: lw         $s0, %lo(D_8009AFB8)($s0) */
".word 0x3C11800A\n\t" /* 80068A38: lui        $s1, %hi(D_8009AFD8) */
".word 0x8E31AFD8\n\t" /* 80068A3C: lw         $s1, %lo(D_8009AFD8)($s1) */
".word 0x3C12800A\n\t" /* 80068A40: lui        $s2, %hi(D_8009AFDC) */
".word 0x8E52AFDC\n\t" /* 80068A44: lw         $s2, %lo(D_8009AFDC)($s2) */
".word 0x02006021\n\t" /* 80068A48: addu       $t4, $s0, $zero */
".word 0x3C02800A\n\t" /* 80068A4C: lui        $v0, %hi(D_8009AFE5) */
".word 0x8042AFE5\n\t" /* 80068A50: lb         $v0, %lo(D_8009AFE5)($v0) */
".word 0x3C010200\n\t" /* 80068A54: lui        $at, (0x2000000 >> 16) */
".word 0x02018025\n\t" /* 80068A58: or         $s0, $s0, $at */
".word 0x1440000E\n\t" /* 80068A5C: bnez       $v0, .L80068A98 */
".word 0x02006021\n\t" /* 80068A60: addu      $t4, $s0, $zero */
".word 0x8CF10004\n\t" /* 80068A64: lw         $s1, 0x4($a3) */
".word 0x3C010060\n\t" /* 80068A68: lui        $at, (0x600000 >> 16) */
".word 0x02218824\n\t" /* 80068A6C: and        $s1, $s1, $at */
".word 0x16200009\n\t" /* 80068A70: bnez       $s1, .L80068A98 */
".word 0x00000000\n\t" /* 80068A74: nop */
".word 0x12400008\n\t" /* 80068A78: beqz       $s2, .L80068A9C */
".word 0x00000000\n\t" /* 80068A7C: nop */
".word 0x94F20002\n\t" /* 80068A80: lhu        $s2, 0x2($a3) */
".word 0x3C0C800A\n\t" /* 80068A84: lui        $t4, %hi(D_8009AFC8) */
".word 0x8D8CAFC8\n\t" /* 80068A88: lw         $t4, %lo(D_8009AFC8)($t4) */
".word 0x00129400\n\t" /* 80068A8C: sll        $s2, $s2, 16 */
".word 0x0801A2A7\n\t" /* 80068A90: j          .L80068A9C */
".word 0x3C110020\n\t" /* 80068A94: lui       $s1, (0x200000 >> 16) */
".L80068A98:\n\t"
".word 0x24120000\n\t" /* 80068A98: addiu      $s2, $zero, 0x0 */
".L80068A9C:\n\t"
".word 0x3C0D800A\n\t" /* 80068A9C: lui        $t5, %hi(D_8009AFE4) */
".word 0x81ADAFE4\n\t" /* 80068AA0: lb         $t5, %lo(D_8009AFE4)($t5) */
".word 0x00109E02\n\t" /* 80068AA4: srl        $s3, $s0, 24 */
".word 0x00139E00\n\t" /* 80068AA8: sll        $s3, $s3, 24 */
".word 0x24010001\n\t" /* 80068AAC: addiu      $at, $zero, 0x1 */
".word 0x11A1008F\n\t" /* 80068AB0: beq        $t5, $at, .L80068CF0 */
".word 0x00000000\n\t" /* 80068AB4: nop */
".word 0x3C0D800A\n\t" /* 80068AB8: lui        $t5, %hi(D_8009AFE0) */
".word 0x8DADAFE0\n\t" /* 80068ABC: lw         $t5, %lo(D_8009AFE0)($t5) */
".word 0x8C85001C\n\t" /* 80068AC0: lw         $a1, 0x1C($a0) */
".word 0x8C860024\n\t" /* 80068AC4: lw         $a2, 0x24($a0) */
".word 0x11A00002\n\t" /* 80068AC8: beqz       $t5, .L80068AD4 */
".word 0x00000000\n\t" /* 80068ACC: nop */
".word 0x24C60004\n\t" /* 80068AD0: addiu      $a2, $a2, 0x4 */
".L80068AD4:\n\t"
".word 0x8C8D0004\n\t" /* 80068AD4: lw         $t5, 0x4($a0) */
".word 0x8C8E0008\n\t" /* 80068AD8: lw         $t6, 0x8($a0) */
".word 0x8DAF0004\n\t" /* 80068ADC: lw         $t7, 0x4($t5) */
".L80068AE0:\n\t"
".word 0x2403FFFF\n\t" /* 80068AE0: addiu      $v1, $zero, -0x1 */
".word 0x8CE8000C\n\t" /* 80068AE4: lw         $t0, 0xC($a3) */
".word 0x98E8000A\n\t" /* 80068AE8: lwr        $t0, 0xA($a3) */
".word 0x8CE90010\n\t" /* 80068AEC: lw         $t1, 0x10($a3) */
".word 0x8CEA0014\n\t" /* 80068AF0: lw         $t2, 0x14($a3) */
".word 0x8CEB0018\n\t" /* 80068AF4: lw         $t3, 0x18($a3) */
".word 0x00086C02\n\t" /* 80068AF8: srl        $t5, $t0, 16 */
".word 0x000D68C0\n\t" /* 80068AFC: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 80068B00: addu       $t5, $t5, $a1 */
".word 0x8DA20004\n\t" /* 80068B04: lw         $v0, 0x4($t5) */
".word 0x8DAD0000\n\t" /* 80068B08: lw         $t5, 0x0($t5) */
".word 0x10430075\n\t" /* 80068B0C: beq        $v0, $v1, .L80068CE4 */
".word 0x48828000\n\t" /* 80068B10: mtc2      $v0, $16 ( handwritten instruction ) */
".word 0x488D6000\n\t" /* 80068B14: mtc2       $t5, $12 ( handwritten instruction ) */
".word 0xAF2D0008\n\t" /* 80068B18: sw         $t5, 0x8($t9) */
".word 0x00096C02\n\t" /* 80068B1C: srl        $t5, $t1, 16 */
".word 0x000D68C0\n\t" /* 80068B20: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 80068B24: addu       $t5, $t5, $a1 */
".word 0x8DA20004\n\t" /* 80068B28: lw         $v0, 0x4($t5) */
".word 0x8DAD0000\n\t" /* 80068B2C: lw         $t5, 0x0($t5) */
".word 0x1043006C\n\t" /* 80068B30: beq        $v0, $v1, .L80068CE4 */
".word 0x48828800\n\t" /* 80068B34: mtc2      $v0, $17 ( handwritten instruction ) */
".word 0x488D6800\n\t" /* 80068B38: mtc2       $t5, $13 ( handwritten instruction ) */
".word 0xAF2D0014\n\t" /* 80068B3C: sw         $t5, 0x14($t9) */
".word 0x000A6C02\n\t" /* 80068B40: srl        $t5, $t2, 16 */
".word 0x000D68C0\n\t" /* 80068B44: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 80068B48: addu       $t5, $t5, $a1 */
".word 0x8DA20004\n\t" /* 80068B4C: lw         $v0, 0x4($t5) */
".word 0x8DAD0000\n\t" /* 80068B50: lw         $t5, 0x0($t5) */
".word 0x10430063\n\t" /* 80068B54: beq        $v0, $v1, .L80068CE4 */
".word 0x48829000\n\t" /* 80068B58: mtc2      $v0, $18 ( handwritten instruction ) */
".word 0x488D7000\n\t" /* 80068B5C: mtc2       $t5, $14 ( handwritten instruction ) */
".word 0xAF2D0020\n\t" /* 80068B60: sw         $t5, 0x20($t9) */
".word 0x000B6C02\n\t" /* 80068B64: srl        $t5, $t3, 16 */
".word 0x000D68C0\n\t" /* 80068B68: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 80068B6C: addu       $t5, $t5, $a1 */
".word 0x8DA20004\n\t" /* 80068B70: lw         $v0, 0x4($t5) */
".word 0x8DAD0000\n\t" /* 80068B74: lw         $t5, 0x0($t5) */
".word 0x1043005A\n\t" /* 80068B78: beq        $v0, $v1, .L80068CE4 */
".word 0x48829800\n\t" /* 80068B7C: mtc2      $v0, $19 ( handwritten instruction ) */
".word 0xAF2D002C\n\t" /* 80068B80: sw         $t5, 0x2C($t9) */
".word 0x00084400\n\t" /* 80068B84: sll        $t0, $t0, 16 */
".word 0x00084342\n\t" /* 80068B88: srl        $t0, $t0, 13 */
".word 0x4B400006\n\t" /* 80068B8C: nclip */
".word 0x00094C00\n\t" /* 80068B90: sll        $t1, $t1, 16 */
".word 0x4802C000\n\t" /* 80068B94: mfc2       $v0, $24 ( handwritten instruction ) */
".word 0x00094B42\n\t" /* 80068B98: srl        $t1, $t1, 13 */
".word 0x1C400009\n\t" /* 80068B9C: bgtz       $v0, .L80068BC4 */
".word 0x00000000\n\t" /* 80068BA0: nop */
".word 0x488D6000\n\t" /* 80068BA4: mtc2       $t5, $12 ( handwritten instruction ) */
".word 0x00000000\n\t" /* 80068BA8: nop */
".word 0x00000000\n\t" /* 80068BAC: nop */
".word 0x4B400006\n\t" /* 80068BB0: nclip */
".word 0x4802C000\n\t" /* 80068BB4: mfc2       $v0, $24 ( handwritten instruction ) */
".word 0x00000000\n\t" /* 80068BB8: nop */
".word 0x1C400049\n\t" /* 80068BBC: bgtz       $v0, .L80068CE4 */
".word 0x00000000\n\t" /* 80068BC0: nop */
".L80068BC4:\n\t"
".word 0x000A5400\n\t" /* 80068BC4: sll        $t2, $t2, 16 */
".word 0x000A5342\n\t" /* 80068BC8: srl        $t2, $t2, 13 */
".word 0x000B5C00\n\t" /* 80068BCC: sll        $t3, $t3, 16 */
".word 0x000B5B42\n\t" /* 80068BD0: srl        $t3, $t3, 13 */
".word 0x01064021\n\t" /* 80068BD4: addu       $t0, $t0, $a2 */
".word 0x01264821\n\t" /* 80068BD8: addu       $t1, $t1, $a2 */
".word 0x01465021\n\t" /* 80068BDC: addu       $t2, $t2, $a2 */
".word 0x01665821\n\t" /* 80068BE0: addu       $t3, $t3, $a2 */
".word 0x8D080000\n\t" /* 80068BE4: lw         $t0, 0x0($t0) */
".word 0x8D290000\n\t" /* 80068BE8: lw         $t1, 0x0($t1) */
".word 0x8D4A0000\n\t" /* 80068BEC: lw         $t2, 0x0($t2) */
".word 0x8D6B0000\n\t" /* 80068BF0: lw         $t3, 0x0($t3) */
".word 0x01134025\n\t" /* 80068BF4: or         $t0, $t0, $s3 */
".word 0xAF280004\n\t" /* 80068BF8: sw         $t0, 0x4($t9) */
".word 0xAF290010\n\t" /* 80068BFC: sw         $t1, 0x10($t9) */
".word 0xAF2A001C\n\t" /* 80068C00: sw         $t2, 0x1C($t9) */
".word 0xAF2B0028\n\t" /* 80068C04: sw         $t3, 0x28($t9) */
".word 0x4B68002E\n\t" /* 80068C08: avsz4 */
".word 0x8CE80000\n\t" /* 80068C0C: lw         $t0, 0x0($a3) */
".word 0x8CE90004\n\t" /* 80068C10: lw         $t1, 0x4($a3) */
".word 0x8CEA0008\n\t" /* 80068C14: lw         $t2, 0x8($a3) */
".word 0x8CEB000C\n\t" /* 80068C18: lw         $t3, 0xC($a3) */
".word 0x48023800\n\t" /* 80068C1C: mfc2       $v0, $7 ( handwritten instruction ) */
".word 0x3C010200\n\t" /* 80068C20: lui        $at, (0x2000000 >> 16) */
".word 0x02011824\n\t" /* 80068C24: and        $v1, $s0, $at */
".word 0x3C01FF9F\n\t" /* 80068C28: lui        $at, (0xFF9FFFFF >> 16) */
".word 0x3421FFFF\n\t" /* 80068C2C: ori        $at, $at, (0xFF9FFFFF & 0xFFFF) */
".word 0x01214824\n\t" /* 80068C30: and        $t1, $t1, $at */
".word 0x01314825\n\t" /* 80068C34: or         $t1, $t1, $s1 */
".word 0x01C21006\n\t" /* 80068C38: srlv       $v0, $v0, $t6 */
".word 0x00021080\n\t" /* 80068C3C: sll        $v0, $v0, 2 */
".word 0x004F1021\n\t" /* 80068C40: addu       $v0, $v0, $t7 */
".word 0x8C4D0000\n\t" /* 80068C44: lw         $t5, 0x0($v0) */
".L80068C48:\n\t"
".word 0xAF28000C\n\t" /* 80068C48: sw         $t0, 0xC($t9) */
".word 0xAF290018\n\t" /* 80068C4C: sw         $t1, 0x18($t9) */
".word 0xAF2A0024\n\t" /* 80068C50: sw         $t2, 0x24($t9) */
".word 0xAF2B0030\n\t" /* 80068C54: sw         $t3, 0x30($t9) */
".word 0x000D6A00\n\t" /* 80068C58: sll        $t5, $t5, 8 */
".word 0x35AD000C\n\t" /* 80068C5C: ori        $t5, $t5, 0xC */
".word 0x000D0A02\n\t" /* 80068C60: srl        $at, $t5, 8 */
".word 0x000D6E00\n\t" /* 80068C64: sll        $t5, $t5, 24 */
".word 0x01A16825\n\t" /* 80068C68: or         $t5, $t5, $at */
".word 0xAF2D0000\n\t" /* 80068C6C: sw         $t5, 0x0($t9) */
".word 0x00196A00\n\t" /* 80068C70: sll        $t5, $t9, 8 */
".word 0x000D6A02\n\t" /* 80068C74: srl        $t5, $t5, 8 */
".word 0x10600019\n\t" /* 80068C78: beqz       $v1, .L80068CE0 */
".word 0xAC4D0000\n\t" /* 80068C7C: sw        $t5, 0x0($v0) */
".word 0x12400017\n\t" /* 80068C80: beqz       $s2, .L80068CE0 */
".word 0x00084400\n\t" /* 80068C84: sll       $t0, $t0, 16 */
".word 0x00084402\n\t" /* 80068C88: srl        $t0, $t0, 16 */
".word 0x01124025\n\t" /* 80068C8C: or         $t0, $t0, $s2 */
".word 0x3C01FF9F\n\t" /* 80068C90: lui        $at, (0xFF9FFFFF >> 16) */
".word 0x3421FFFF\n\t" /* 80068C94: ori        $at, $at, (0xFF9FFFFF & 0xFFFF) */
".word 0x01214824\n\t" /* 80068C98: and        $t1, $t1, $at */
".word 0x3C010040\n\t" /* 80068C9C: lui        $at, (0x400000 >> 16) */
".word 0x01214825\n\t" /* 80068CA0: or         $t1, $t1, $at */
".word 0x8F230008\n\t" /* 80068CA4: lw         $v1, 0x8($t9) */
".word 0xAF2C0038\n\t" /* 80068CA8: sw         $t4, 0x38($t9) */
".word 0xAF23003C\n\t" /* 80068CAC: sw         $v1, 0x3C($t9) */
".word 0x8F230014\n\t" /* 80068CB0: lw         $v1, 0x14($t9) */
".word 0xAF2C0044\n\t" /* 80068CB4: sw         $t4, 0x44($t9) */
".word 0xAF230048\n\t" /* 80068CB8: sw         $v1, 0x48($t9) */
".word 0x8F230020\n\t" /* 80068CBC: lw         $v1, 0x20($t9) */
".word 0xAF2C0050\n\t" /* 80068CC0: sw         $t4, 0x50($t9) */
".word 0xAF230054\n\t" /* 80068CC4: sw         $v1, 0x54($t9) */
".word 0x8F23002C\n\t" /* 80068CC8: lw         $v1, 0x2C($t9) */
".word 0xAF2C005C\n\t" /* 80068CCC: sw         $t4, 0x5C($t9) */
".word 0xAF230060\n\t" /* 80068CD0: sw         $v1, 0x60($t9) */
".word 0x27390034\n\t" /* 80068CD4: addiu      $t9, $t9, 0x34 */
".word 0x0801A312\n\t" /* 80068CD8: j          .L80068C48 */
".word 0x24030000\n\t" /* 80068CDC: addiu     $v1, $zero, 0x0 */
".L80068CE0:\n\t"
".word 0x27390034\n\t" /* 80068CE0: addiu      $t9, $t9, 0x34 */
".L80068CE4:\n\t"
".word 0x2718FFFF\n\t" /* 80068CE4: addiu      $t8, $t8, -0x1 */
".word 0x1700FF7D\n\t" /* 80068CE8: bnez       $t8, .L80068AE0 */
".word 0x24E7001C\n\t" /* 80068CEC: addiu     $a3, $a3, 0x1C */
".L80068CF0:\n\t"
".word 0x8C900028\n\t" /* 80068CF0: lw         $s0, 0x28($a0) */
".word 0x8C91002C\n\t" /* 80068CF4: lw         $s1, 0x2C($a0) */
".word 0x8C920030\n\t" /* 80068CF8: lw         $s2, 0x30($a0) */
".word 0x8C930034\n\t" /* 80068CFC: lw         $s3, 0x34($a0) */
".word 0x8C820000\n\t" /* 80068D00: lw         $v0, 0x0($a0) */
".word 0x3C018010\n\t" /* 80068D04: lui        $at, %hi(D_800FE240) */
".word 0xAC39E240\n\t" /* 80068D08: sw         $t9, %lo(D_800FE240)($at) */
".word 0x24420008\n\t" /* 80068D0C: addiu      $v0, $v0, 0x8 */
".word 0x03E00008\n\t" /* 80068D10: jr         $ra */
".word 0x00000000\n\t" /* 80068D14: nop */
    ".set reorder\n"
);
