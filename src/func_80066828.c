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
    ".global func_80066828\n"
    "func_80066828:\n"
".word 0x8C870000\n\t" /* 80066828: lw         $a3, 0x0($a0) */
".word 0x8C990010\n\t" /* 8006682C: lw         $t9, 0x10($a0) */
".word 0x94F80002\n\t" /* 80066830: lhu        $t8, 0x2($a3) */
".word 0x8CE60004\n\t" /* 80066834: lw         $a2, 0x4($a3) */
".word 0x8C850014\n\t" /* 80066838: lw         $a1, 0x14($a0) */
".word 0x00063080\n\t" /* 8006683C: sll        $a2, $a2, 2 */
".word 0xAC900020\n\t" /* 80066840: sw         $s0, 0x20($a0) */
".word 0xAC910024\n\t" /* 80066844: sw         $s1, 0x24($a0) */
".word 0xAC920028\n\t" /* 80066848: sw         $s2, 0x28($a0) */
".word 0xAC93002C\n\t" /* 8006684C: sw         $s3, 0x2C($a0) */
".word 0xAC940030\n\t" /* 80066850: sw         $s4, 0x30($a0) */
".word 0xAC950034\n\t" /* 80066854: sw         $s5, 0x34($a0) */
".word 0xAC960038\n\t" /* 80066858: sw         $s6, 0x38($a0) */
".word 0xAC97003C\n\t" /* 8006685C: sw         $s7, 0x3C($a0) */
".word 0x130000AE\n\t" /* 80066860: beqz       $t8, .L80066B1C */
".word 0x00A63821\n\t" /* 80066864: addu      $a3, $a1, $a2 */
".word 0x3C10800A\n\t" /* 80066868: lui        $s0, %hi(D_8009AFB4) */
".word 0x8E10AFB4\n\t" /* 8006686C: lw         $s0, %lo(D_8009AFB4)($s0) */
".word 0x3C11800A\n\t" /* 80066870: lui        $s1, %hi(D_8009AFD8) */
".word 0x8E31AFD8\n\t" /* 80066874: lw         $s1, %lo(D_8009AFD8)($s1) */
".word 0x3C12800A\n\t" /* 80066878: lui        $s2, %hi(D_8009AFDC) */
".word 0x8E52AFDC\n\t" /* 8006687C: lw         $s2, %lo(D_8009AFDC)($s2) */
".word 0x3C16800A\n\t" /* 80066880: lui        $s6, %hi(D_8009AFE4) */
".word 0x82D6AFE4\n\t" /* 80066884: lb         $s6, %lo(D_8009AFE4)($s6) */
".word 0x3C17800A\n\t" /* 80066888: lui        $s7, %hi(D_8009AFE0) */
".word 0x8EF7AFE0\n\t" /* 8006688C: lw         $s7, %lo(D_8009AFE0)($s7) */
".word 0x02006021\n\t" /* 80066890: addu       $t4, $s0, $zero */
".word 0x3C02800A\n\t" /* 80066894: lui        $v0, %hi(D_8009AFE5) */
".word 0x8042AFE5\n\t" /* 80066898: lb         $v0, %lo(D_8009AFE5)($v0) */
".word 0x3C010200\n\t" /* 8006689C: lui        $at, (0x2000000 >> 16) */
".word 0x02018025\n\t" /* 800668A0: or         $s0, $s0, $at */
".word 0x1440000E\n\t" /* 800668A4: bnez       $v0, .L800668E0 */
".word 0x02006021\n\t" /* 800668A8: addu      $t4, $s0, $zero */
".word 0x8CF10008\n\t" /* 800668AC: lw         $s1, 0x8($a3) */
".word 0x3C010060\n\t" /* 800668B0: lui        $at, (0x600000 >> 16) */
".word 0x02218824\n\t" /* 800668B4: and        $s1, $s1, $at */
".word 0x16200009\n\t" /* 800668B8: bnez       $s1, .L800668E0 */
".word 0x00000000\n\t" /* 800668BC: nop */
".word 0x12400008\n\t" /* 800668C0: beqz       $s2, .L800668E4 */
".word 0x00000000\n\t" /* 800668C4: nop */
".word 0x94F20006\n\t" /* 800668C8: lhu        $s2, 0x6($a3) */
".word 0x3C0C800A\n\t" /* 800668CC: lui        $t4, %hi(D_8009AFC4) */
".word 0x8D8CAFC4\n\t" /* 800668D0: lw         $t4, %lo(D_8009AFC4)($t4) */
".word 0x00129400\n\t" /* 800668D4: sll        $s2, $s2, 16 */
".word 0x08019A39\n\t" /* 800668D8: j          .L800668E4 */
".word 0x3C110020\n\t" /* 800668DC: lui       $s1, (0x200000 >> 16) */
".L800668E0:\n\t"
".word 0x24120000\n\t" /* 800668E0: addiu      $s2, $zero, 0x0 */
".L800668E4:\n\t"
".word 0x00109E02\n\t" /* 800668E4: srl        $s3, $s0, 24 */
".word 0x3C14E200\n\t" /* 800668E8: lui        $s4, (0xE2000000 >> 16) */
".word 0x8C850018\n\t" /* 800668EC: lw         $a1, 0x18($a0) */
".word 0x8C86001C\n\t" /* 800668F0: lw         $a2, 0x1C($a0) */
".word 0x48903000\n\t" /* 800668F4: mtc2       $s0, $6 ( handwritten instruction ) */
".word 0x8C8D0004\n\t" /* 800668F8: lw         $t5, 0x4($a0) */
".word 0x8C8E0008\n\t" /* 800668FC: lw         $t6, 0x8($a0) */
".word 0x8DAF0004\n\t" /* 80066900: lw         $t7, 0x4($t5) */
".L80066904:\n\t"
".word 0x8CE80010\n\t" /* 80066904: lw         $t0, 0x10($a3) */
".word 0x8CE90014\n\t" /* 80066908: lw         $t1, 0x14($a3) */
".word 0x8CEA0018\n\t" /* 8006690C: lw         $t2, 0x18($a3) */
".word 0x00086C02\n\t" /* 80066910: srl        $t5, $t0, 16 */
".word 0x000D68C0\n\t" /* 80066914: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 80066918: addu       $t5, $t5, $a1 */
".word 0xC9A00000\n\t" /* 8006691C: lwc2       $0, 0x0($t5) */
".word 0xC9A10004\n\t" /* 80066920: lwc2       $1, 0x4($t5) */
".word 0x00096C02\n\t" /* 80066924: srl        $t5, $t1, 16 */
".word 0x000D68C0\n\t" /* 80066928: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 8006692C: addu       $t5, $t5, $a1 */
".word 0xC9A20000\n\t" /* 80066930: lwc2       $2, 0x0($t5) */
".word 0xC9A30004\n\t" /* 80066934: lwc2       $3, 0x4($t5) */
".word 0x000A6C02\n\t" /* 80066938: srl        $t5, $t2, 16 */
".word 0x000D68C0\n\t" /* 8006693C: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 80066940: addu       $t5, $t5, $a1 */
".word 0xC9A40000\n\t" /* 80066944: lwc2       $4, 0x0($t5) */
".word 0xC9A50004\n\t" /* 80066948: lwc2       $5, 0x4($t5) */
".word 0x00084400\n\t" /* 8006694C: sll        $t0, $t0, 16 */
".word 0x00084342\n\t" /* 80066950: srl        $t0, $t0, 13 */
".word 0x4A280030\n\t" /* 80066954: rtpt */
".word 0x00094C00\n\t" /* 80066958: sll        $t1, $t1, 16 */
".word 0x00094B42\n\t" /* 8006695C: srl        $t1, $t1, 13 */
".word 0x000A5400\n\t" /* 80066960: sll        $t2, $t2, 16 */
".word 0x24010001\n\t" /* 80066964: addiu      $at, $zero, 0x1 */
".word 0x12C10005\n\t" /* 80066968: beq        $s6, $at, .L80066980 */
".word 0x000A5342\n\t" /* 8006696C: srl       $t2, $t2, 13 */
".word 0x4842F800\n\t" /* 80066970: cfc2       $v0, $31 ( handwritten instruction ) */
".word 0x00000000\n\t" /* 80066974: nop */
".word 0x04400065\n\t" /* 80066978: bltz       $v0, .L80066B10 */
".word 0x00000000\n\t" /* 8006697C: nop */
".L80066980:\n\t"
".word 0x4B58002D\n\t" /* 80066980: avsz3 */
".word 0x8CF50000\n\t" /* 80066984: lw         $s5, 0x0($a3) */
".word 0x12C0001E\n\t" /* 80066988: beqz       $s6, .L80066A04 */
".word 0x01066821\n\t" /* 8006698C: addu      $t5, $t0, $a2 */
".word 0xC9A00000\n\t" /* 80066990: lwc2       $0, 0x0($t5) */
".word 0xC9A10004\n\t" /* 80066994: lwc2       $1, 0x4($t5) */
".word 0x01266821\n\t" /* 80066998: addu       $t5, $t1, $a2 */
".word 0xC9A20000\n\t" /* 8006699C: lwc2       $2, 0x0($t5) */
".word 0xC9A30004\n\t" /* 800669A0: lwc2       $3, 0x4($t5) */
".word 0x01466821\n\t" /* 800669A4: addu       $t5, $t2, $a2 */
".word 0xC9A40000\n\t" /* 800669A8: lwc2       $4, 0x0($t5) */
".word 0xC9A50004\n\t" /* 800669AC: lwc2       $5, 0x4($t5) */
".word 0x00000000\n\t" /* 800669B0: nop */
".word 0x00000000\n\t" /* 800669B4: nop */
".word 0x4B18043F\n\t" /* 800669B8: ncct */
".word 0x12E00009\n\t" /* 800669BC: beqz       $s7, .L800669E4 */
".word 0x00084042\n\t" /* 800669C0: srl       $t0, $t0, 1 */
".word 0x01174021\n\t" /* 800669C4: addu       $t0, $t0, $s7 */
".word 0x00094842\n\t" /* 800669C8: srl        $t1, $t1, 1 */
".word 0x01374821\n\t" /* 800669CC: addu       $t1, $t1, $s7 */
".word 0x000A5042\n\t" /* 800669D0: srl        $t2, $t2, 1 */
".word 0x01575021\n\t" /* 800669D4: addu       $t2, $t2, $s7 */
".word 0xE9140000\n\t" /* 800669D8: swc2       $20, 0x0($t0) */
".word 0xE9350000\n\t" /* 800669DC: swc2       $21, 0x0($t1) */
".word 0xE9560000\n\t" /* 800669E0: swc2       $22, 0x0($t2) */
".L800669E4:\n\t"
".word 0xEB340008\n\t" /* 800669E4: swc2       $20, 0x8($t9) */
".word 0xEB350014\n\t" /* 800669E8: swc2       $21, 0x14($t9) */
".word 0xEB360020\n\t" /* 800669EC: swc2       $22, 0x20($t9) */
".word 0x24010001\n\t" /* 800669F0: addiu      $at, $zero, 0x1 */
".word 0x12C10046\n\t" /* 800669F4: beq        $s6, $at, .L80066B10 */
".word 0x00000000\n\t" /* 800669F8: nop */
".word 0x08019A8E\n\t" /* 800669FC: j          .L80066A38 */
".word 0x00000000\n\t" /* 80066A00: nop */
".L80066A04:\n\t"
".word 0x00084042\n\t" /* 80066A04: srl        $t0, $t0, 1 */
".word 0x01171821\n\t" /* 80066A08: addu       $v1, $t0, $s7 */
".word 0x8C680000\n\t" /* 80066A0C: lw         $t0, 0x0($v1) */
".word 0x00094842\n\t" /* 80066A10: srl        $t1, $t1, 1 */
".word 0x01371821\n\t" /* 80066A14: addu       $v1, $t1, $s7 */
".word 0x8C690000\n\t" /* 80066A18: lw         $t1, 0x0($v1) */
".word 0x000A5042\n\t" /* 80066A1C: srl        $t2, $t2, 1 */
".word 0x01571821\n\t" /* 80066A20: addu       $v1, $t2, $s7 */
".word 0x8C6A0000\n\t" /* 80066A24: lw         $t2, 0x0($v1) */
".word 0xAF280008\n\t" /* 80066A28: sw         $t0, 0x8($t9) */
".word 0xAF290014\n\t" /* 80066A2C: sw         $t1, 0x14($t9) */
".word 0xAF2A0020\n\t" /* 80066A30: sw         $t2, 0x20($t9) */
".word 0xA333000B\n\t" /* 80066A34: sb         $s3, 0xB($t9) */
".L80066A38:\n\t"
".word 0x8CE80004\n\t" /* 80066A38: lw         $t0, 0x4($a3) */
".word 0x8CE90008\n\t" /* 80066A3C: lw         $t1, 0x8($a3) */
".word 0x8CEA000C\n\t" /* 80066A40: lw         $t2, 0xC($a3) */
".word 0x48023800\n\t" /* 80066A44: mfc2       $v0, $7 ( handwritten instruction ) */
".word 0x3C010200\n\t" /* 80066A48: lui        $at, (0x2000000 >> 16) */
".word 0x02011824\n\t" /* 80066A4C: and        $v1, $s0, $at */
".word 0x3C01FF9F\n\t" /* 80066A50: lui        $at, (0xFF9FFFFF >> 16) */
".word 0x3421FFFF\n\t" /* 80066A54: ori        $at, $at, (0xFF9FFFFF & 0xFFFF) */
".word 0x01214824\n\t" /* 80066A58: and        $t1, $t1, $at */
".word 0x01314825\n\t" /* 80066A5C: or         $t1, $t1, $s1 */
".word 0x01C21006\n\t" /* 80066A60: srlv       $v0, $v0, $t6 */
".word 0x00021080\n\t" /* 80066A64: sll        $v0, $v0, 2 */
".word 0x004F1021\n\t" /* 80066A68: addu       $v0, $v0, $t7 */
".word 0x8C4D0000\n\t" /* 80066A6C: lw         $t5, 0x0($v0) */
".word 0xEB2C000C\n\t" /* 80066A70: swc2       $12, 0xC($t9) */
".word 0xEB2D0018\n\t" /* 80066A74: swc2       $13, 0x18($t9) */
".word 0xEB2E0024\n\t" /* 80066A78: swc2       $14, 0x24($t9) */
".L80066A7C:\n\t"
".word 0xAF280010\n\t" /* 80066A7C: sw         $t0, 0x10($t9) */
".word 0xAF29001C\n\t" /* 80066A80: sw         $t1, 0x1C($t9) */
".word 0xAF2A0028\n\t" /* 80066A84: sw         $t2, 0x28($t9) */
".word 0xAF350004\n\t" /* 80066A88: sw         $s5, 0x4($t9) */
".word 0xAF34002C\n\t" /* 80066A8C: sw         $s4, 0x2C($t9) */
".word 0x000D6A00\n\t" /* 80066A90: sll        $t5, $t5, 8 */
".word 0x35AD000B\n\t" /* 80066A94: ori        $t5, $t5, 0xB */
".word 0x000D0A02\n\t" /* 80066A98: srl        $at, $t5, 8 */
".word 0x000D6E00\n\t" /* 80066A9C: sll        $t5, $t5, 24 */
".word 0x01A16825\n\t" /* 80066AA0: or         $t5, $t5, $at */
".word 0xAF2D0000\n\t" /* 80066AA4: sw         $t5, 0x0($t9) */
".word 0x00196A00\n\t" /* 80066AA8: sll        $t5, $t9, 8 */
".word 0x000D6A02\n\t" /* 80066AAC: srl        $t5, $t5, 8 */
".word 0x10600016\n\t" /* 80066AB0: beqz       $v1, .L80066B0C */
".word 0xAC4D0000\n\t" /* 80066AB4: sw        $t5, 0x0($v0) */
".word 0x12400014\n\t" /* 80066AB8: beqz       $s2, .L80066B0C */
".word 0x00084400\n\t" /* 80066ABC: sll       $t0, $t0, 16 */
".word 0x00084402\n\t" /* 80066AC0: srl        $t0, $t0, 16 */
".word 0x01124025\n\t" /* 80066AC4: or         $t0, $t0, $s2 */
".word 0x3C01FF9F\n\t" /* 80066AC8: lui        $at, (0xFF9FFFFF >> 16) */
".word 0x3421FFFF\n\t" /* 80066ACC: ori        $at, $at, (0xFF9FFFFF & 0xFFFF) */
".word 0x01214824\n\t" /* 80066AD0: and        $t1, $t1, $at */
".word 0x3C010040\n\t" /* 80066AD4: lui        $at, (0x400000 >> 16) */
".word 0x01214825\n\t" /* 80066AD8: or         $t1, $t1, $at */
".word 0x8F23000C\n\t" /* 80066ADC: lw         $v1, 0xC($t9) */
".word 0xAF2C0038\n\t" /* 80066AE0: sw         $t4, 0x38($t9) */
".word 0xAF23003C\n\t" /* 80066AE4: sw         $v1, 0x3C($t9) */
".word 0x8F230018\n\t" /* 80066AE8: lw         $v1, 0x18($t9) */
".word 0xAF2C0044\n\t" /* 80066AEC: sw         $t4, 0x44($t9) */
".word 0xAF230048\n\t" /* 80066AF0: sw         $v1, 0x48($t9) */
".word 0x8F230024\n\t" /* 80066AF4: lw         $v1, 0x24($t9) */
".word 0xAF2C0050\n\t" /* 80066AF8: sw         $t4, 0x50($t9) */
".word 0xAF230054\n\t" /* 80066AFC: sw         $v1, 0x54($t9) */
".word 0x27390030\n\t" /* 80066B00: addiu      $t9, $t9, 0x30 */
".word 0x08019A9F\n\t" /* 80066B04: j          .L80066A7C */
".word 0x24030000\n\t" /* 80066B08: addiu     $v1, $zero, 0x0 */
".L80066B0C:\n\t"
".word 0x27390030\n\t" /* 80066B0C: addiu      $t9, $t9, 0x30 */
".L80066B10:\n\t"
".word 0x2718FFFF\n\t" /* 80066B10: addiu      $t8, $t8, -0x1 */
".word 0x1700FF7B\n\t" /* 80066B14: bnez       $t8, .L80066904 */
".word 0x24E7001C\n\t" /* 80066B18: addiu     $a3, $a3, 0x1C */
".L80066B1C:\n\t"
".word 0x8C900020\n\t" /* 80066B1C: lw         $s0, 0x20($a0) */
".word 0x8C910024\n\t" /* 80066B20: lw         $s1, 0x24($a0) */
".word 0x8C920028\n\t" /* 80066B24: lw         $s2, 0x28($a0) */
".word 0x8C93002C\n\t" /* 80066B28: lw         $s3, 0x2C($a0) */
".word 0x8C940030\n\t" /* 80066B2C: lw         $s4, 0x30($a0) */
".word 0x8C950034\n\t" /* 80066B30: lw         $s5, 0x34($a0) */
".word 0x8C960038\n\t" /* 80066B34: lw         $s6, 0x38($a0) */
".word 0x8C97003C\n\t" /* 80066B38: lw         $s7, 0x3C($a0) */
".word 0x8C820000\n\t" /* 80066B3C: lw         $v0, 0x0($a0) */
".word 0x3C018010\n\t" /* 80066B40: lui        $at, %hi(D_800FE240) */
".word 0xAC39E240\n\t" /* 80066B44: sw         $t9, %lo(D_800FE240)($at) */
".word 0x24420008\n\t" /* 80066B48: addiu      $v0, $v0, 0x8 */
".word 0x03E00008\n\t" /* 80066B4C: jr         $ra */
".word 0x00000000\n\t" /* 80066B50: nop */
    ".set reorder\n"
);
