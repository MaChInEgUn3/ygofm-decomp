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
    ".global func_8006397C\n"
    "func_8006397C:\n"
".word 0x8C870000\n\t" /* 8006397C: lw         $a3, 0x0($a0) */
".word 0x8C990010\n\t" /* 80063980: lw         $t9, 0x10($a0) */
".word 0x94F80002\n\t" /* 80063984: lhu        $t8, 0x2($a3) */
".word 0x8CE60004\n\t" /* 80063988: lw         $a2, 0x4($a3) */
".word 0x8C850014\n\t" /* 8006398C: lw         $a1, 0x14($a0) */
".word 0x00063080\n\t" /* 80063990: sll        $a2, $a2, 2 */
".word 0xAC900020\n\t" /* 80063994: sw         $s0, 0x20($a0) */
".word 0xAC910024\n\t" /* 80063998: sw         $s1, 0x24($a0) */
".word 0xAC920028\n\t" /* 8006399C: sw         $s2, 0x28($a0) */
".word 0xAC93002C\n\t" /* 800639A0: sw         $s3, 0x2C($a0) */
".word 0xAC940030\n\t" /* 800639A4: sw         $s4, 0x30($a0) */
".word 0xAC950034\n\t" /* 800639A8: sw         $s5, 0x34($a0) */
".word 0xAC960038\n\t" /* 800639AC: sw         $s6, 0x38($a0) */
".word 0xAC97003C\n\t" /* 800639B0: sw         $s7, 0x3C($a0) */
".word 0x1300008F\n\t" /* 800639B4: beqz       $t8, .L80063BF4 */
".word 0x00A63821\n\t" /* 800639B8: addu      $a3, $a1, $a2 */
".word 0x3C10800A\n\t" /* 800639BC: lui        $s0, %hi(D_8009AFB0) */
".word 0x8E10AFB0\n\t" /* 800639C0: lw         $s0, %lo(D_8009AFB0)($s0) */
".word 0x3C11800A\n\t" /* 800639C4: lui        $s1, %hi(D_8009AFD8) */
".word 0x8E31AFD8\n\t" /* 800639C8: lw         $s1, %lo(D_8009AFD8)($s1) */
".word 0x3C12800A\n\t" /* 800639CC: lui        $s2, %hi(D_8009AFDC) */
".word 0x8E52AFDC\n\t" /* 800639D0: lw         $s2, %lo(D_8009AFDC)($s2) */
".word 0x3C16800A\n\t" /* 800639D4: lui        $s6, %hi(D_8009AFE4) */
".word 0x82D6AFE4\n\t" /* 800639D8: lb         $s6, %lo(D_8009AFE4)($s6) */
".word 0x3C17800A\n\t" /* 800639DC: lui        $s7, %hi(D_8009AFE0) */
".word 0x8EF7AFE0\n\t" /* 800639E0: lw         $s7, %lo(D_8009AFE0)($s7) */
".word 0x02006021\n\t" /* 800639E4: addu       $t4, $s0, $zero */
".word 0x00109E02\n\t" /* 800639E8: srl        $s3, $s0, 24 */
".word 0x3C14E200\n\t" /* 800639EC: lui        $s4, (0xE2000000 >> 16) */
".word 0x8C850018\n\t" /* 800639F0: lw         $a1, 0x18($a0) */
".word 0x8C86001C\n\t" /* 800639F4: lw         $a2, 0x1C($a0) */
".word 0x48903000\n\t" /* 800639F8: mtc2       $s0, $6 ( handwritten instruction ) */
".word 0x8C8D0004\n\t" /* 800639FC: lw         $t5, 0x4($a0) */
".word 0x8C8E0008\n\t" /* 80063A00: lw         $t6, 0x8($a0) */
".word 0x8DAF0004\n\t" /* 80063A04: lw         $t7, 0x4($t5) */
".L80063A08:\n\t"
".word 0x8CE80014\n\t" /* 80063A08: lw         $t0, 0x14($a3) */
".word 0x8CE90018\n\t" /* 80063A0C: lw         $t1, 0x18($a3) */
".word 0x00086C00\n\t" /* 80063A10: sll        $t5, $t0, 16 */
".word 0x000D6B42\n\t" /* 80063A14: srl        $t5, $t5, 13 */
".word 0x01A56821\n\t" /* 80063A18: addu       $t5, $t5, $a1 */
".word 0xC9A00000\n\t" /* 80063A1C: lwc2       $0, 0x0($t5) */
".word 0xC9A10004\n\t" /* 80063A20: lwc2       $1, 0x4($t5) */
".word 0x00086C02\n\t" /* 80063A24: srl        $t5, $t0, 16 */
".word 0x000D68C0\n\t" /* 80063A28: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 80063A2C: addu       $t5, $t5, $a1 */
".word 0xC9A20000\n\t" /* 80063A30: lwc2       $2, 0x0($t5) */
".word 0xC9A30004\n\t" /* 80063A34: lwc2       $3, 0x4($t5) */
".word 0x00096C00\n\t" /* 80063A38: sll        $t5, $t1, 16 */
".word 0x000D6B42\n\t" /* 80063A3C: srl        $t5, $t5, 13 */
".word 0x01A56821\n\t" /* 80063A40: addu       $t5, $t5, $a1 */
".word 0xC9A40000\n\t" /* 80063A44: lwc2       $4, 0x0($t5) */
".word 0xC9A50004\n\t" /* 80063A48: lwc2       $5, 0x4($t5) */
".word 0x00095C02\n\t" /* 80063A4C: srl        $t3, $t1, 16 */
".word 0x000B58C0\n\t" /* 80063A50: sll        $t3, $t3, 3 */
".word 0x4A280030\n\t" /* 80063A54: rtpt */
".word 0x24010001\n\t" /* 80063A58: addiu      $at, $zero, 0x1 */
".word 0x12C10005\n\t" /* 80063A5C: beq        $s6, $at, .L80063A74 */
".word 0x01656821\n\t" /* 80063A60: addu      $t5, $t3, $a1 */
".word 0x4842F800\n\t" /* 80063A64: cfc2       $v0, $31 ( handwritten instruction ) */
".word 0x00000000\n\t" /* 80063A68: nop */
".word 0x0440005E\n\t" /* 80063A6C: bltz       $v0, .L80063BE8 */
".word 0x00000000\n\t" /* 80063A70: nop */
".L80063A74:\n\t"
".word 0xC9A00000\n\t" /* 80063A74: lwc2       $0, 0x0($t5) */
".word 0xC9A10004\n\t" /* 80063A78: lwc2       $1, 0x4($t5) */
".word 0xEB2C000C\n\t" /* 80063A7C: swc2       $12, 0xC($t9) */
".word 0xEB2D0014\n\t" /* 80063A80: swc2       $13, 0x14($t9) */
".word 0xEB2E001C\n\t" /* 80063A84: swc2       $14, 0x1C($t9) */
".word 0x00000000\n\t" /* 80063A88: nop */
".word 0x00000000\n\t" /* 80063A8C: nop */
".word 0x4A180001\n\t" /* 80063A90: rtps */
".word 0x94E80012\n\t" /* 80063A94: lhu        $t0, 0x12($a3) */
".word 0x24010001\n\t" /* 80063A98: addiu      $at, $zero, 0x1 */
".word 0x12C10005\n\t" /* 80063A9C: beq        $s6, $at, .L80063AB4 */
".word 0x000840C0\n\t" /* 80063AA0: sll       $t0, $t0, 3 */
".word 0x4842F800\n\t" /* 80063AA4: cfc2       $v0, $31 ( handwritten instruction ) */
".word 0x00000000\n\t" /* 80063AA8: nop */
".word 0x0440004E\n\t" /* 80063AAC: bltz       $v0, .L80063BE8 */
".word 0x00000000\n\t" /* 80063AB0: nop */
".L80063AB4:\n\t"
".word 0x4B68002E\n\t" /* 80063AB4: avsz4 */
".word 0x8CF50000\n\t" /* 80063AB8: lw         $s5, 0x0($a3) */
".word 0x12C00010\n\t" /* 80063ABC: beqz       $s6, .L80063B00 */
".word 0x01066821\n\t" /* 80063AC0: addu      $t5, $t0, $a2 */
".word 0xC9A00000\n\t" /* 80063AC4: lwc2       $0, 0x0($t5) */
".word 0xC9A10004\n\t" /* 80063AC8: lwc2       $1, 0x4($t5) */
".word 0x00000000\n\t" /* 80063ACC: nop */
".word 0x00000000\n\t" /* 80063AD0: nop */
".word 0x4B08041B\n\t" /* 80063AD4: nccs */
".word 0x12E00003\n\t" /* 80063AD8: beqz       $s7, .L80063AE8 */
".word 0x00084042\n\t" /* 80063ADC: srl       $t0, $t0, 1 */
".word 0x01174021\n\t" /* 80063AE0: addu       $t0, $t0, $s7 */
".word 0xE9160000\n\t" /* 80063AE4: swc2       $22, 0x0($t0) */
".L80063AE8:\n\t"
".word 0xEB360008\n\t" /* 80063AE8: swc2       $22, 0x8($t9) */
".word 0x24010001\n\t" /* 80063AEC: addiu      $at, $zero, 0x1 */
".word 0x12C1003D\n\t" /* 80063AF0: beq        $s6, $at, .L80063BE8 */
".word 0x00000000\n\t" /* 80063AF4: nop */
".word 0x08018EC6\n\t" /* 80063AF8: j          .L80063B18 */
".word 0x00000000\n\t" /* 80063AFC: nop */
".L80063B00:\n\t"
".word 0x00084042\n\t" /* 80063B00: srl        $t0, $t0, 1 */
".word 0x01171821\n\t" /* 80063B04: addu       $v1, $t0, $s7 */
".word 0x8C680000\n\t" /* 80063B08: lw         $t0, 0x0($v1) */
".word 0x00000000\n\t" /* 80063B0C: nop */
".word 0xAF280008\n\t" /* 80063B10: sw         $t0, 0x8($t9) */
".word 0xA333000B\n\t" /* 80063B14: sb         $s3, 0xB($t9) */
".L80063B18:\n\t"
".word 0x8CE80004\n\t" /* 80063B18: lw         $t0, 0x4($a3) */
".word 0x8CE90008\n\t" /* 80063B1C: lw         $t1, 0x8($a3) */
".word 0x8CEA000C\n\t" /* 80063B20: lw         $t2, 0xC($a3) */
".word 0x8CEB0010\n\t" /* 80063B24: lw         $t3, 0x10($a3) */
".word 0x48023800\n\t" /* 80063B28: mfc2       $v0, $7 ( handwritten instruction ) */
".word 0x3C010200\n\t" /* 80063B2C: lui        $at, (0x2000000 >> 16) */
".word 0x02011824\n\t" /* 80063B30: and        $v1, $s0, $at */
".word 0x01314825\n\t" /* 80063B34: or         $t1, $t1, $s1 */
".word 0x01C21006\n\t" /* 80063B38: srlv       $v0, $v0, $t6 */
".word 0x00021080\n\t" /* 80063B3C: sll        $v0, $v0, 2 */
".word 0x004F1021\n\t" /* 80063B40: addu       $v0, $v0, $t7 */
".word 0x8C4D0000\n\t" /* 80063B44: lw         $t5, 0x0($v0) */
".word 0xEB2E0024\n\t" /* 80063B48: swc2       $14, 0x24($t9) */
".L80063B4C:\n\t"
".word 0xAF280010\n\t" /* 80063B4C: sw         $t0, 0x10($t9) */
".word 0xAF290018\n\t" /* 80063B50: sw         $t1, 0x18($t9) */
".word 0xAF2A0020\n\t" /* 80063B54: sw         $t2, 0x20($t9) */
".word 0xAF2B0028\n\t" /* 80063B58: sw         $t3, 0x28($t9) */
".word 0xAF350004\n\t" /* 80063B5C: sw         $s5, 0x4($t9) */
".word 0xAF34002C\n\t" /* 80063B60: sw         $s4, 0x2C($t9) */
".word 0x000D6A00\n\t" /* 80063B64: sll        $t5, $t5, 8 */
".word 0x35AD000B\n\t" /* 80063B68: ori        $t5, $t5, 0xB */
".word 0x000D0A02\n\t" /* 80063B6C: srl        $at, $t5, 8 */
".word 0x000D6E00\n\t" /* 80063B70: sll        $t5, $t5, 24 */
".word 0x01A16825\n\t" /* 80063B74: or         $t5, $t5, $at */
".word 0xAF2D0000\n\t" /* 80063B78: sw         $t5, 0x0($t9) */
".word 0x00196A00\n\t" /* 80063B7C: sll        $t5, $t9, 8 */
".word 0x000D6A02\n\t" /* 80063B80: srl        $t5, $t5, 8 */
".word 0x10600017\n\t" /* 80063B84: beqz       $v1, .L80063BE4 */
".word 0xAC4D0000\n\t" /* 80063B88: sw        $t5, 0x0($v0) */
".word 0x12400015\n\t" /* 80063B8C: beqz       $s2, .L80063BE4 */
".word 0x00000000\n\t" /* 80063B90: nop */
".word 0x3C01FF9F\n\t" /* 80063B94: lui        $at, (0xFF9FFFFF >> 16) */
".word 0x3421FFFF\n\t" /* 80063B98: ori        $at, $at, (0xFF9FFFFF & 0xFFFF) */
".word 0x01214824\n\t" /* 80063B9C: and        $t1, $t1, $at */
".word 0x3C010040\n\t" /* 80063BA0: lui        $at, (0x400000 >> 16) */
".word 0x01214825\n\t" /* 80063BA4: or         $t1, $t1, $at */
".word 0x8F23000C\n\t" /* 80063BA8: lw         $v1, 0xC($t9) */
".word 0x00084400\n\t" /* 80063BAC: sll        $t0, $t0, 16 */
".word 0xAF23003C\n\t" /* 80063BB0: sw         $v1, 0x3C($t9) */
".word 0x8F230014\n\t" /* 80063BB4: lw         $v1, 0x14($t9) */
".word 0x00084402\n\t" /* 80063BB8: srl        $t0, $t0, 16 */
".word 0xAF230044\n\t" /* 80063BBC: sw         $v1, 0x44($t9) */
".word 0x8F23001C\n\t" /* 80063BC0: lw         $v1, 0x1C($t9) */
".word 0x01124025\n\t" /* 80063BC4: or         $t0, $t0, $s2 */
".word 0xAF23004C\n\t" /* 80063BC8: sw         $v1, 0x4C($t9) */
".word 0x8F230024\n\t" /* 80063BCC: lw         $v1, 0x24($t9) */
".word 0xAF2C0038\n\t" /* 80063BD0: sw         $t4, 0x38($t9) */
".word 0xAF230054\n\t" /* 80063BD4: sw         $v1, 0x54($t9) */
".word 0x27390030\n\t" /* 80063BD8: addiu      $t9, $t9, 0x30 */
".word 0x08018ED3\n\t" /* 80063BDC: j          .L80063B4C */
".word 0x24030000\n\t" /* 80063BE0: addiu     $v1, $zero, 0x0 */
".L80063BE4:\n\t"
".word 0x27390030\n\t" /* 80063BE4: addiu      $t9, $t9, 0x30 */
".L80063BE8:\n\t"
".word 0x2718FFFF\n\t" /* 80063BE8: addiu      $t8, $t8, -0x1 */
".word 0x1700FF86\n\t" /* 80063BEC: bnez       $t8, .L80063A08 */
".word 0x24E7001C\n\t" /* 80063BF0: addiu     $a3, $a3, 0x1C */
".L80063BF4:\n\t"
".word 0x8C900020\n\t" /* 80063BF4: lw         $s0, 0x20($a0) */
".word 0x8C910024\n\t" /* 80063BF8: lw         $s1, 0x24($a0) */
".word 0x8C920028\n\t" /* 80063BFC: lw         $s2, 0x28($a0) */
".word 0x8C93002C\n\t" /* 80063C00: lw         $s3, 0x2C($a0) */
".word 0x8C940030\n\t" /* 80063C04: lw         $s4, 0x30($a0) */
".word 0x8C950034\n\t" /* 80063C08: lw         $s5, 0x34($a0) */
".word 0x8C960038\n\t" /* 80063C0C: lw         $s6, 0x38($a0) */
".word 0x8C97003C\n\t" /* 80063C10: lw         $s7, 0x3C($a0) */
".word 0x8C820000\n\t" /* 80063C14: lw         $v0, 0x0($a0) */
".word 0x3C018010\n\t" /* 80063C18: lui        $at, %hi(D_800FE240) */
".word 0xAC39E240\n\t" /* 80063C1C: sw         $t9, %lo(D_800FE240)($at) */
".word 0x24420008\n\t" /* 80063C20: addiu      $v0, $v0, 0x8 */
".word 0x03E00008\n\t" /* 80063C24: jr         $ra */
".word 0x00000000\n\t" /* 80063C28: nop */
    ".set reorder\n"
);
