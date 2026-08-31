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
    ".global func_80067ABC\n"
    "func_80067ABC:\n"
".word 0x8C870000\n\t" /* 80067ABC: lw         $a3, 0x0($a0) */
".word 0x8C990010\n\t" /* 80067AC0: lw         $t9, 0x10($a0) */
".word 0x94F80002\n\t" /* 80067AC4: lhu        $t8, 0x2($a3) */
".word 0x8CE60004\n\t" /* 80067AC8: lw         $a2, 0x4($a3) */
".word 0x8C850014\n\t" /* 80067ACC: lw         $a1, 0x14($a0) */
".word 0x00063080\n\t" /* 80067AD0: sll        $a2, $a2, 2 */
".word 0xAC900028\n\t" /* 80067AD4: sw         $s0, 0x28($a0) */
".word 0xAC91002C\n\t" /* 80067AD8: sw         $s1, 0x2C($a0) */
".word 0xAC920030\n\t" /* 80067ADC: sw         $s2, 0x30($a0) */
".word 0xAC930034\n\t" /* 80067AE0: sw         $s3, 0x34($a0) */
".word 0xAC940038\n\t" /* 80067AE4: sw         $s4, 0x38($a0) */
".word 0xAC95003C\n\t" /* 80067AE8: sw         $s5, 0x3C($a0) */
".word 0x1300009D\n\t" /* 80067AEC: beqz       $t8, .L80067D64 */
".word 0x00A63821\n\t" /* 80067AF0: addu      $a3, $a1, $a2 */
".word 0x3C10800A\n\t" /* 80067AF4: lui        $s0, %hi(D_8009AFB8) */
".word 0x8E10AFB8\n\t" /* 80067AF8: lw         $s0, %lo(D_8009AFB8)($s0) */
".word 0x3C11800A\n\t" /* 80067AFC: lui        $s1, %hi(D_8009AFD8) */
".word 0x8E31AFD8\n\t" /* 80067B00: lw         $s1, %lo(D_8009AFD8)($s1) */
".word 0x3C12800A\n\t" /* 80067B04: lui        $s2, %hi(D_8009AFDC) */
".word 0x8E52AFDC\n\t" /* 80067B08: lw         $s2, %lo(D_8009AFDC)($s2) */
".word 0x02006021\n\t" /* 80067B0C: addu       $t4, $s0, $zero */
".word 0x3C0D800A\n\t" /* 80067B10: lui        $t5, %hi(D_8009AFE4) */
".word 0x81ADAFE4\n\t" /* 80067B14: lb         $t5, %lo(D_8009AFE4)($t5) */
".word 0x00109E02\n\t" /* 80067B18: srl        $s3, $s0, 24 */
".word 0x00139E00\n\t" /* 80067B1C: sll        $s3, $s3, 24 */
".word 0x24010001\n\t" /* 80067B20: addiu      $at, $zero, 0x1 */
".word 0x11A1008F\n\t" /* 80067B24: beq        $t5, $at, .L80067D64 */
".word 0x3C14E200\n\t" /* 80067B28: lui       $s4, (0xE2000000 >> 16) */
".word 0x3C0D800A\n\t" /* 80067B2C: lui        $t5, %hi(D_8009AFE0) */
".word 0x8DADAFE0\n\t" /* 80067B30: lw         $t5, %lo(D_8009AFE0)($t5) */
".word 0x8C85001C\n\t" /* 80067B34: lw         $a1, 0x1C($a0) */
".word 0x8C860024\n\t" /* 80067B38: lw         $a2, 0x24($a0) */
".word 0x11A00002\n\t" /* 80067B3C: beqz       $t5, .L80067B48 */
".word 0x00000000\n\t" /* 80067B40: nop */
".word 0x24C60004\n\t" /* 80067B44: addiu      $a2, $a2, 0x4 */
".L80067B48:\n\t"
".word 0x8C8D0004\n\t" /* 80067B48: lw         $t5, 0x4($a0) */
".word 0x8C8E0008\n\t" /* 80067B4C: lw         $t6, 0x8($a0) */
".word 0x8DAF0004\n\t" /* 80067B50: lw         $t7, 0x4($t5) */
".L80067B54:\n\t"
".word 0x2403FFFF\n\t" /* 80067B54: addiu      $v1, $zero, -0x1 */
".word 0x8CE80010\n\t" /* 80067B58: lw         $t0, 0x10($a3) */
".word 0x98E8000E\n\t" /* 80067B5C: lwr        $t0, 0xE($a3) */
".word 0x8CE90014\n\t" /* 80067B60: lw         $t1, 0x14($a3) */
".word 0x8CEA0018\n\t" /* 80067B64: lw         $t2, 0x18($a3) */
".word 0x8CEB001C\n\t" /* 80067B68: lw         $t3, 0x1C($a3) */
".word 0x00086C02\n\t" /* 80067B6C: srl        $t5, $t0, 16 */
".word 0x000D68C0\n\t" /* 80067B70: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 80067B74: addu       $t5, $t5, $a1 */
".word 0x8DA20004\n\t" /* 80067B78: lw         $v0, 0x4($t5) */
".word 0x8DAD0000\n\t" /* 80067B7C: lw         $t5, 0x0($t5) */
".word 0x10430075\n\t" /* 80067B80: beq        $v0, $v1, .L80067D58 */
".word 0x48828000\n\t" /* 80067B84: mtc2      $v0, $16 ( handwritten instruction ) */
".word 0x488D6000\n\t" /* 80067B88: mtc2       $t5, $12 ( handwritten instruction ) */
".word 0xAF2D000C\n\t" /* 80067B8C: sw         $t5, 0xC($t9) */
".word 0x00096C02\n\t" /* 80067B90: srl        $t5, $t1, 16 */
".word 0x000D68C0\n\t" /* 80067B94: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 80067B98: addu       $t5, $t5, $a1 */
".word 0x8DA20004\n\t" /* 80067B9C: lw         $v0, 0x4($t5) */
".word 0x8DAD0000\n\t" /* 80067BA0: lw         $t5, 0x0($t5) */
".word 0x1043006C\n\t" /* 80067BA4: beq        $v0, $v1, .L80067D58 */
".word 0x48828800\n\t" /* 80067BA8: mtc2      $v0, $17 ( handwritten instruction ) */
".word 0x488D6800\n\t" /* 80067BAC: mtc2       $t5, $13 ( handwritten instruction ) */
".word 0xAF2D0018\n\t" /* 80067BB0: sw         $t5, 0x18($t9) */
".word 0x000A6C02\n\t" /* 80067BB4: srl        $t5, $t2, 16 */
".word 0x000D68C0\n\t" /* 80067BB8: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 80067BBC: addu       $t5, $t5, $a1 */
".word 0x8DA20004\n\t" /* 80067BC0: lw         $v0, 0x4($t5) */
".word 0x8DAD0000\n\t" /* 80067BC4: lw         $t5, 0x0($t5) */
".word 0x10430063\n\t" /* 80067BC8: beq        $v0, $v1, .L80067D58 */
".word 0x48829000\n\t" /* 80067BCC: mtc2      $v0, $18 ( handwritten instruction ) */
".word 0x488D7000\n\t" /* 80067BD0: mtc2       $t5, $14 ( handwritten instruction ) */
".word 0xAF2D0024\n\t" /* 80067BD4: sw         $t5, 0x24($t9) */
".word 0x000B6C02\n\t" /* 80067BD8: srl        $t5, $t3, 16 */
".word 0x000D68C0\n\t" /* 80067BDC: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 80067BE0: addu       $t5, $t5, $a1 */
".word 0x8DA20004\n\t" /* 80067BE4: lw         $v0, 0x4($t5) */
".word 0x8DAD0000\n\t" /* 80067BE8: lw         $t5, 0x0($t5) */
".word 0x1043005A\n\t" /* 80067BEC: beq        $v0, $v1, .L80067D58 */
".word 0x48829800\n\t" /* 80067BF0: mtc2      $v0, $19 ( handwritten instruction ) */
".word 0xAF2D0030\n\t" /* 80067BF4: sw         $t5, 0x30($t9) */
".word 0x00084400\n\t" /* 80067BF8: sll        $t0, $t0, 16 */
".word 0x00084342\n\t" /* 80067BFC: srl        $t0, $t0, 13 */
".word 0x4B400006\n\t" /* 80067C00: nclip */
".word 0x00094C00\n\t" /* 80067C04: sll        $t1, $t1, 16 */
".word 0x4802C000\n\t" /* 80067C08: mfc2       $v0, $24 ( handwritten instruction ) */
".word 0x00094B42\n\t" /* 80067C0C: srl        $t1, $t1, 13 */
".word 0x1C400009\n\t" /* 80067C10: bgtz       $v0, .L80067C38 */
".word 0x00000000\n\t" /* 80067C14: nop */
".word 0x488D6000\n\t" /* 80067C18: mtc2       $t5, $12 ( handwritten instruction ) */
".word 0x00000000\n\t" /* 80067C1C: nop */
".word 0x00000000\n\t" /* 80067C20: nop */
".word 0x4B400006\n\t" /* 80067C24: nclip */
".word 0x4802C000\n\t" /* 80067C28: mfc2       $v0, $24 ( handwritten instruction ) */
".word 0x00000000\n\t" /* 80067C2C: nop */
".word 0x1C400049\n\t" /* 80067C30: bgtz       $v0, .L80067D58 */
".word 0x00000000\n\t" /* 80067C34: nop */
".L80067C38:\n\t"
".word 0x000A5400\n\t" /* 80067C38: sll        $t2, $t2, 16 */
".word 0x000A5342\n\t" /* 80067C3C: srl        $t2, $t2, 13 */
".word 0x000B5C00\n\t" /* 80067C40: sll        $t3, $t3, 16 */
".word 0x000B5B42\n\t" /* 80067C44: srl        $t3, $t3, 13 */
".word 0x01064021\n\t" /* 80067C48: addu       $t0, $t0, $a2 */
".word 0x01264821\n\t" /* 80067C4C: addu       $t1, $t1, $a2 */
".word 0x01465021\n\t" /* 80067C50: addu       $t2, $t2, $a2 */
".word 0x01665821\n\t" /* 80067C54: addu       $t3, $t3, $a2 */
".word 0x8D080000\n\t" /* 80067C58: lw         $t0, 0x0($t0) */
".word 0x8D290000\n\t" /* 80067C5C: lw         $t1, 0x0($t1) */
".word 0x8D4A0000\n\t" /* 80067C60: lw         $t2, 0x0($t2) */
".word 0x8D6B0000\n\t" /* 80067C64: lw         $t3, 0x0($t3) */
".word 0x01134025\n\t" /* 80067C68: or         $t0, $t0, $s3 */
".word 0xAF280008\n\t" /* 80067C6C: sw         $t0, 0x8($t9) */
".word 0xAF290014\n\t" /* 80067C70: sw         $t1, 0x14($t9) */
".word 0xAF2A0020\n\t" /* 80067C74: sw         $t2, 0x20($t9) */
".word 0xAF2B002C\n\t" /* 80067C78: sw         $t3, 0x2C($t9) */
".word 0x4B68002E\n\t" /* 80067C7C: avsz4 */
".word 0x8CF50000\n\t" /* 80067C80: lw         $s5, 0x0($a3) */
".word 0x8CE80004\n\t" /* 80067C84: lw         $t0, 0x4($a3) */
".word 0x8CE90008\n\t" /* 80067C88: lw         $t1, 0x8($a3) */
".word 0x8CEA000C\n\t" /* 80067C8C: lw         $t2, 0xC($a3) */
".word 0x8CEB0010\n\t" /* 80067C90: lw         $t3, 0x10($a3) */
".word 0x48023800\n\t" /* 80067C94: mfc2       $v0, $7 ( handwritten instruction ) */
".word 0x3C010200\n\t" /* 80067C98: lui        $at, (0x2000000 >> 16) */
".word 0x02011824\n\t" /* 80067C9C: and        $v1, $s0, $at */
".word 0x01314825\n\t" /* 80067CA0: or         $t1, $t1, $s1 */
".word 0x01C21006\n\t" /* 80067CA4: srlv       $v0, $v0, $t6 */
".word 0x00021080\n\t" /* 80067CA8: sll        $v0, $v0, 2 */
".word 0x004F1021\n\t" /* 80067CAC: addu       $v0, $v0, $t7 */
".word 0x8C4D0000\n\t" /* 80067CB0: lw         $t5, 0x0($v0) */
".L80067CB4:\n\t"
".word 0xAF280010\n\t" /* 80067CB4: sw         $t0, 0x10($t9) */
".word 0xAF29001C\n\t" /* 80067CB8: sw         $t1, 0x1C($t9) */
".word 0xAF2A0028\n\t" /* 80067CBC: sw         $t2, 0x28($t9) */
".word 0xAF2B0034\n\t" /* 80067CC0: sw         $t3, 0x34($t9) */
".word 0xAF350004\n\t" /* 80067CC4: sw         $s5, 0x4($t9) */
".word 0xAF340038\n\t" /* 80067CC8: sw         $s4, 0x38($t9) */
".word 0x000D6A00\n\t" /* 80067CCC: sll        $t5, $t5, 8 */
".word 0x35AD000E\n\t" /* 80067CD0: ori        $t5, $t5, 0xE */
".word 0x000D0A02\n\t" /* 80067CD4: srl        $at, $t5, 8 */
".word 0x000D6E00\n\t" /* 80067CD8: sll        $t5, $t5, 24 */
".word 0x01A16825\n\t" /* 80067CDC: or         $t5, $t5, $at */
".word 0xAF2D0000\n\t" /* 80067CE0: sw         $t5, 0x0($t9) */
".word 0x00196A00\n\t" /* 80067CE4: sll        $t5, $t9, 8 */
".word 0x000D6A02\n\t" /* 80067CE8: srl        $t5, $t5, 8 */
".word 0x10600019\n\t" /* 80067CEC: beqz       $v1, .L80067D54 */
".word 0xAC4D0000\n\t" /* 80067CF0: sw        $t5, 0x0($v0) */
".word 0x12400017\n\t" /* 80067CF4: beqz       $s2, .L80067D54 */
".word 0x00084400\n\t" /* 80067CF8: sll       $t0, $t0, 16 */
".word 0x00084402\n\t" /* 80067CFC: srl        $t0, $t0, 16 */
".word 0x01124025\n\t" /* 80067D00: or         $t0, $t0, $s2 */
".word 0x3C01FF9F\n\t" /* 80067D04: lui        $at, (0xFF9FFFFF >> 16) */
".word 0x3421FFFF\n\t" /* 80067D08: ori        $at, $at, (0xFF9FFFFF & 0xFFFF) */
".word 0x01214824\n\t" /* 80067D0C: and        $t1, $t1, $at */
".word 0x3C010040\n\t" /* 80067D10: lui        $at, (0x400000 >> 16) */
".word 0x01214825\n\t" /* 80067D14: or         $t1, $t1, $at */
".word 0x8F23000C\n\t" /* 80067D18: lw         $v1, 0xC($t9) */
".word 0xAF2C0044\n\t" /* 80067D1C: sw         $t4, 0x44($t9) */
".word 0xAF230048\n\t" /* 80067D20: sw         $v1, 0x48($t9) */
".word 0x8F230018\n\t" /* 80067D24: lw         $v1, 0x18($t9) */
".word 0xAF2C0050\n\t" /* 80067D28: sw         $t4, 0x50($t9) */
".word 0xAF230054\n\t" /* 80067D2C: sw         $v1, 0x54($t9) */
".word 0x8F230024\n\t" /* 80067D30: lw         $v1, 0x24($t9) */
".word 0xAF2C005C\n\t" /* 80067D34: sw         $t4, 0x5C($t9) */
".word 0xAF230060\n\t" /* 80067D38: sw         $v1, 0x60($t9) */
".word 0x8F230030\n\t" /* 80067D3C: lw         $v1, 0x30($t9) */
".word 0xAF2C0068\n\t" /* 80067D40: sw         $t4, 0x68($t9) */
".word 0xAF23006C\n\t" /* 80067D44: sw         $v1, 0x6C($t9) */
".word 0x2739003C\n\t" /* 80067D48: addiu      $t9, $t9, 0x3C */
".word 0x08019F2D\n\t" /* 80067D4C: j          .L80067CB4 */
".word 0x24030000\n\t" /* 80067D50: addiu     $v1, $zero, 0x0 */
".L80067D54:\n\t"
".word 0x2739003C\n\t" /* 80067D54: addiu      $t9, $t9, 0x3C */
".L80067D58:\n\t"
".word 0x2718FFFF\n\t" /* 80067D58: addiu      $t8, $t8, -0x1 */
".word 0x1700FF7D\n\t" /* 80067D5C: bnez       $t8, .L80067B54 */
".word 0x24E70020\n\t" /* 80067D60: addiu     $a3, $a3, 0x20 */
".L80067D64:\n\t"
".word 0x8C900028\n\t" /* 80067D64: lw         $s0, 0x28($a0) */
".word 0x8C91002C\n\t" /* 80067D68: lw         $s1, 0x2C($a0) */
".word 0x8C920030\n\t" /* 80067D6C: lw         $s2, 0x30($a0) */
".word 0x8C930034\n\t" /* 80067D70: lw         $s3, 0x34($a0) */
".word 0x8C940038\n\t" /* 80067D74: lw         $s4, 0x38($a0) */
".word 0x8C95003C\n\t" /* 80067D78: lw         $s5, 0x3C($a0) */
".word 0x8C820000\n\t" /* 80067D7C: lw         $v0, 0x0($a0) */
".word 0x3C018010\n\t" /* 80067D80: lui        $at, %hi(D_800FE240) */
".word 0xAC39E240\n\t" /* 80067D84: sw         $t9, %lo(D_800FE240)($at) */
".word 0x24420008\n\t" /* 80067D88: addiu      $v0, $v0, 0x8 */
".word 0x03E00008\n\t" /* 80067D8C: jr         $ra */
".word 0x00000000\n\t" /* 80067D90: nop */
    ".set reorder\n"
);
