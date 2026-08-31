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
    ".global func_80065928\n"
    "func_80065928:\n"
".word 0x8C870000\n\t" /* 80065928: lw         $a3, 0x0($a0) */
".word 0x8C990010\n\t" /* 8006592C: lw         $t9, 0x10($a0) */
".word 0x94F80002\n\t" /* 80065930: lhu        $t8, 0x2($a3) */
".word 0x8CE60004\n\t" /* 80065934: lw         $a2, 0x4($a3) */
".word 0x8C850014\n\t" /* 80065938: lw         $a1, 0x14($a0) */
".word 0x00063080\n\t" /* 8006593C: sll        $a2, $a2, 2 */
".word 0xAC900020\n\t" /* 80065940: sw         $s0, 0x20($a0) */
".word 0xAC910024\n\t" /* 80065944: sw         $s1, 0x24($a0) */
".word 0xAC920028\n\t" /* 80065948: sw         $s2, 0x28($a0) */
".word 0xAC93002C\n\t" /* 8006594C: sw         $s3, 0x2C($a0) */
".word 0xAC960030\n\t" /* 80065950: sw         $s6, 0x30($a0) */
".word 0xAC970034\n\t" /* 80065954: sw         $s7, 0x34($a0) */
".word 0x13000090\n\t" /* 80065958: beqz       $t8, .L80065B9C */
".word 0x00A63821\n\t" /* 8006595C: addu      $a3, $a1, $a2 */
".word 0x3C10800A\n\t" /* 80065960: lui        $s0, %hi(D_8009AFAC) */
".word 0x8E10AFAC\n\t" /* 80065964: lw         $s0, %lo(D_8009AFAC)($s0) */
".word 0x3C11800A\n\t" /* 80065968: lui        $s1, %hi(D_8009AFD8) */
".word 0x8E31AFD8\n\t" /* 8006596C: lw         $s1, %lo(D_8009AFD8)($s1) */
".word 0x3C12800A\n\t" /* 80065970: lui        $s2, %hi(D_8009AFDC) */
".word 0x8E52AFDC\n\t" /* 80065974: lw         $s2, %lo(D_8009AFDC)($s2) */
".word 0x3C16800A\n\t" /* 80065978: lui        $s6, %hi(D_8009AFE4) */
".word 0x82D6AFE4\n\t" /* 8006597C: lb         $s6, %lo(D_8009AFE4)($s6) */
".word 0x3C17800A\n\t" /* 80065980: lui        $s7, %hi(D_8009AFE0) */
".word 0x8EF7AFE0\n\t" /* 80065984: lw         $s7, %lo(D_8009AFE0)($s7) */
".word 0x02006021\n\t" /* 80065988: addu       $t4, $s0, $zero */
".word 0x3C02800A\n\t" /* 8006598C: lui        $v0, %hi(D_8009AFE5) */
".word 0x8042AFE5\n\t" /* 80065990: lb         $v0, %lo(D_8009AFE5)($v0) */
".word 0x3C010200\n\t" /* 80065994: lui        $at, (0x2000000 >> 16) */
".word 0x02018025\n\t" /* 80065998: or         $s0, $s0, $at */
".word 0x1440000E\n\t" /* 8006599C: bnez       $v0, .L800659D8 */
".word 0x02006021\n\t" /* 800659A0: addu      $t4, $s0, $zero */
".word 0x8CF10004\n\t" /* 800659A4: lw         $s1, 0x4($a3) */
".word 0x3C010060\n\t" /* 800659A8: lui        $at, (0x600000 >> 16) */
".word 0x02218824\n\t" /* 800659AC: and        $s1, $s1, $at */
".word 0x16200009\n\t" /* 800659B0: bnez       $s1, .L800659D8 */
".word 0x00000000\n\t" /* 800659B4: nop */
".word 0x12400008\n\t" /* 800659B8: beqz       $s2, .L800659DC */
".word 0x00000000\n\t" /* 800659BC: nop */
".word 0x94F20002\n\t" /* 800659C0: lhu        $s2, 0x2($a3) */
".word 0x3C0C800A\n\t" /* 800659C4: lui        $t4, %hi(D_8009AFBC) */
".word 0x8D8CAFBC\n\t" /* 800659C8: lw         $t4, %lo(D_8009AFBC)($t4) */
".word 0x00129400\n\t" /* 800659CC: sll        $s2, $s2, 16 */
".word 0x08019677\n\t" /* 800659D0: j          .L800659DC */
".word 0x3C110020\n\t" /* 800659D4: lui       $s1, (0x200000 >> 16) */
".L800659D8:\n\t"
".word 0x24120000\n\t" /* 800659D8: addiu      $s2, $zero, 0x0 */
".L800659DC:\n\t"
".word 0x00109E02\n\t" /* 800659DC: srl        $s3, $s0, 24 */
".word 0x8C850018\n\t" /* 800659E0: lw         $a1, 0x18($a0) */
".word 0x8C86001C\n\t" /* 800659E4: lw         $a2, 0x1C($a0) */
".word 0x48903000\n\t" /* 800659E8: mtc2       $s0, $6 ( handwritten instruction ) */
".word 0x8C8D0004\n\t" /* 800659EC: lw         $t5, 0x4($a0) */
".word 0x8C8E0008\n\t" /* 800659F0: lw         $t6, 0x8($a0) */
".word 0x8DAF0004\n\t" /* 800659F4: lw         $t7, 0x4($t5) */
".L800659F8:\n\t"
".word 0x8CE8000C\n\t" /* 800659F8: lw         $t0, 0xC($a3) */
".word 0x8CE90010\n\t" /* 800659FC: lw         $t1, 0x10($a3) */
".word 0x00086C02\n\t" /* 80065A00: srl        $t5, $t0, 16 */
".word 0x000D68C0\n\t" /* 80065A04: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 80065A08: addu       $t5, $t5, $a1 */
".word 0xC9A00000\n\t" /* 80065A0C: lwc2       $0, 0x0($t5) */
".word 0xC9A10004\n\t" /* 80065A10: lwc2       $1, 0x4($t5) */
".word 0x00096C00\n\t" /* 80065A14: sll        $t5, $t1, 16 */
".word 0x000D6B42\n\t" /* 80065A18: srl        $t5, $t5, 13 */
".word 0x01A56821\n\t" /* 80065A1C: addu       $t5, $t5, $a1 */
".word 0xC9A20000\n\t" /* 80065A20: lwc2       $2, 0x0($t5) */
".word 0xC9A30004\n\t" /* 80065A24: lwc2       $3, 0x4($t5) */
".word 0x00096C02\n\t" /* 80065A28: srl        $t5, $t1, 16 */
".word 0x000D68C0\n\t" /* 80065A2C: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 80065A30: addu       $t5, $t5, $a1 */
".word 0xC9A40000\n\t" /* 80065A34: lwc2       $4, 0x0($t5) */
".word 0xC9A50004\n\t" /* 80065A38: lwc2       $5, 0x4($t5) */
".word 0x00084400\n\t" /* 80065A3C: sll        $t0, $t0, 16 */
".word 0x00084342\n\t" /* 80065A40: srl        $t0, $t0, 13 */
".word 0x4A280030\n\t" /* 80065A44: rtpt */
".word 0x24010001\n\t" /* 80065A48: addiu      $at, $zero, 0x1 */
".word 0x12C10005\n\t" /* 80065A4C: beq        $s6, $at, .L80065A64 */
".word 0x00000000\n\t" /* 80065A50: nop */
".word 0x4842F800\n\t" /* 80065A54: cfc2       $v0, $31 ( handwritten instruction ) */
".word 0x00000000\n\t" /* 80065A58: nop */
".word 0x0440004C\n\t" /* 80065A5C: bltz       $v0, .L80065B90 */
".word 0x00000000\n\t" /* 80065A60: nop */
".L80065A64:\n\t"
".word 0x4B58002D\n\t" /* 80065A64: avsz3 */
".word 0x12C00010\n\t" /* 80065A68: beqz       $s6, .L80065AAC */
".word 0x01066821\n\t" /* 80065A6C: addu      $t5, $t0, $a2 */
".word 0xC9A00000\n\t" /* 80065A70: lwc2       $0, 0x0($t5) */
".word 0xC9A10004\n\t" /* 80065A74: lwc2       $1, 0x4($t5) */
".word 0x00000000\n\t" /* 80065A78: nop */
".word 0x00000000\n\t" /* 80065A7C: nop */
".word 0x4B08041B\n\t" /* 80065A80: nccs */
".word 0x12E00003\n\t" /* 80065A84: beqz       $s7, .L80065A94 */
".word 0x00084042\n\t" /* 80065A88: srl       $t0, $t0, 1 */
".word 0x01174021\n\t" /* 80065A8C: addu       $t0, $t0, $s7 */
".word 0xE9160000\n\t" /* 80065A90: swc2       $22, 0x0($t0) */
".L80065A94:\n\t"
".word 0xEB360004\n\t" /* 80065A94: swc2       $22, 0x4($t9) */
".word 0x24010001\n\t" /* 80065A98: addiu      $at, $zero, 0x1 */
".word 0x12C1003C\n\t" /* 80065A9C: beq        $s6, $at, .L80065B90 */
".word 0x00000000\n\t" /* 80065AA0: nop */
".word 0x080196B1\n\t" /* 80065AA4: j          .L80065AC4 */
".word 0x00000000\n\t" /* 80065AA8: nop */
".L80065AAC:\n\t"
".word 0x00084042\n\t" /* 80065AAC: srl        $t0, $t0, 1 */
".word 0x01171821\n\t" /* 80065AB0: addu       $v1, $t0, $s7 */
".word 0x8C680000\n\t" /* 80065AB4: lw         $t0, 0x0($v1) */
".word 0x00000000\n\t" /* 80065AB8: nop */
".word 0xAF280004\n\t" /* 80065ABC: sw         $t0, 0x4($t9) */
".word 0xA3330007\n\t" /* 80065AC0: sb         $s3, 0x7($t9) */
".L80065AC4:\n\t"
".word 0x8CE80000\n\t" /* 80065AC4: lw         $t0, 0x0($a3) */
".word 0x8CE90004\n\t" /* 80065AC8: lw         $t1, 0x4($a3) */
".word 0x8CEA0008\n\t" /* 80065ACC: lw         $t2, 0x8($a3) */
".word 0x48023800\n\t" /* 80065AD0: mfc2       $v0, $7 ( handwritten instruction ) */
".word 0x3C010200\n\t" /* 80065AD4: lui        $at, (0x2000000 >> 16) */
".word 0x02011824\n\t" /* 80065AD8: and        $v1, $s0, $at */
".word 0x3C01FF9F\n\t" /* 80065ADC: lui        $at, (0xFF9FFFFF >> 16) */
".word 0x3421FFFF\n\t" /* 80065AE0: ori        $at, $at, (0xFF9FFFFF & 0xFFFF) */
".word 0x01214824\n\t" /* 80065AE4: and        $t1, $t1, $at */
".word 0x01314825\n\t" /* 80065AE8: or         $t1, $t1, $s1 */
".word 0x01C21006\n\t" /* 80065AEC: srlv       $v0, $v0, $t6 */
".word 0x00021080\n\t" /* 80065AF0: sll        $v0, $v0, 2 */
".word 0x004F1021\n\t" /* 80065AF4: addu       $v0, $v0, $t7 */
".word 0x8C4D0000\n\t" /* 80065AF8: lw         $t5, 0x0($v0) */
".word 0xEB2C0008\n\t" /* 80065AFC: swc2       $12, 0x8($t9) */
".word 0xEB2D0010\n\t" /* 80065B00: swc2       $13, 0x10($t9) */
".word 0xEB2E0018\n\t" /* 80065B04: swc2       $14, 0x18($t9) */
".L80065B08:\n\t"
".word 0xAF28000C\n\t" /* 80065B08: sw         $t0, 0xC($t9) */
".word 0xAF290014\n\t" /* 80065B0C: sw         $t1, 0x14($t9) */
".word 0xAF2A001C\n\t" /* 80065B10: sw         $t2, 0x1C($t9) */
".word 0x000D6A00\n\t" /* 80065B14: sll        $t5, $t5, 8 */
".word 0x35AD0007\n\t" /* 80065B18: ori        $t5, $t5, 0x7 */
".word 0x000D0A02\n\t" /* 80065B1C: srl        $at, $t5, 8 */
".word 0x000D6E00\n\t" /* 80065B20: sll        $t5, $t5, 24 */
".word 0x01A16825\n\t" /* 80065B24: or         $t5, $t5, $at */
".word 0xAF2D0000\n\t" /* 80065B28: sw         $t5, 0x0($t9) */
".word 0x00196A00\n\t" /* 80065B2C: sll        $t5, $t9, 8 */
".word 0x000D6A02\n\t" /* 80065B30: srl        $t5, $t5, 8 */
".word 0x10600015\n\t" /* 80065B34: beqz       $v1, .L80065B8C */
".word 0xAC4D0000\n\t" /* 80065B38: sw        $t5, 0x0($v0) */
".word 0x12400013\n\t" /* 80065B3C: beqz       $s2, .L80065B8C */
".word 0x00000000\n\t" /* 80065B40: nop */
".word 0x3C01FF9F\n\t" /* 80065B44: lui        $at, (0xFF9FFFFF >> 16) */
".word 0x3421FFFF\n\t" /* 80065B48: ori        $at, $at, (0xFF9FFFFF & 0xFFFF) */
".word 0x01214824\n\t" /* 80065B4C: and        $t1, $t1, $at */
".word 0x3C010040\n\t" /* 80065B50: lui        $at, (0x400000 >> 16) */
".word 0x01214825\n\t" /* 80065B54: or         $t1, $t1, $at */
".word 0x8F230008\n\t" /* 80065B58: lw         $v1, 0x8($t9) */
".word 0x00084400\n\t" /* 80065B5C: sll        $t0, $t0, 16 */
".word 0xAF230028\n\t" /* 80065B60: sw         $v1, 0x28($t9) */
".word 0x8F230010\n\t" /* 80065B64: lw         $v1, 0x10($t9) */
".word 0x00084402\n\t" /* 80065B68: srl        $t0, $t0, 16 */
".word 0xAF230030\n\t" /* 80065B6C: sw         $v1, 0x30($t9) */
".word 0x8F230018\n\t" /* 80065B70: lw         $v1, 0x18($t9) */
".word 0x01124025\n\t" /* 80065B74: or         $t0, $t0, $s2 */
".word 0xAF230038\n\t" /* 80065B78: sw         $v1, 0x38($t9) */
".word 0xAF2C0024\n\t" /* 80065B7C: sw         $t4, 0x24($t9) */
".word 0x27390020\n\t" /* 80065B80: addiu      $t9, $t9, 0x20 */
".word 0x080196C2\n\t" /* 80065B84: j          .L80065B08 */
".word 0x24030000\n\t" /* 80065B88: addiu     $v1, $zero, 0x0 */
".L80065B8C:\n\t"
".word 0x27390020\n\t" /* 80065B8C: addiu      $t9, $t9, 0x20 */
".L80065B90:\n\t"
".word 0x2718FFFF\n\t" /* 80065B90: addiu      $t8, $t8, -0x1 */
".word 0x1700FF98\n\t" /* 80065B94: bnez       $t8, .L800659F8 */
".word 0x24E70014\n\t" /* 80065B98: addiu     $a3, $a3, 0x14 */
".L80065B9C:\n\t"
".word 0x8C900020\n\t" /* 80065B9C: lw         $s0, 0x20($a0) */
".word 0x8C910024\n\t" /* 80065BA0: lw         $s1, 0x24($a0) */
".word 0x8C920028\n\t" /* 80065BA4: lw         $s2, 0x28($a0) */
".word 0x8C93002C\n\t" /* 80065BA8: lw         $s3, 0x2C($a0) */
".word 0x8C960030\n\t" /* 80065BAC: lw         $s6, 0x30($a0) */
".word 0x8C970034\n\t" /* 80065BB0: lw         $s7, 0x34($a0) */
".word 0x8C820000\n\t" /* 80065BB4: lw         $v0, 0x0($a0) */
".word 0x3C018010\n\t" /* 80065BB8: lui        $at, %hi(D_800FE240) */
".word 0xAC39E240\n\t" /* 80065BBC: sw         $t9, %lo(D_800FE240)($at) */
".word 0x24420008\n\t" /* 80065BC0: addiu      $v0, $v0, 0x8 */
".word 0x03E00008\n\t" /* 80065BC4: jr         $ra */
".word 0x00000000\n\t" /* 80065BC8: nop */
    ".set reorder\n"
);
