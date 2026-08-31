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
    ".global func_80062978\n"
    "func_80062978:\n"
".word 0x8C870000\n\t" /* 80062978: lw         $a3, 0x0($a0) */
".word 0x8C990010\n\t" /* 8006297C: lw         $t9, 0x10($a0) */
".word 0x94F80002\n\t" /* 80062980: lhu        $t8, 0x2($a3) */
".word 0x8CE60004\n\t" /* 80062984: lw         $a2, 0x4($a3) */
".word 0x8C850014\n\t" /* 80062988: lw         $a1, 0x14($a0) */
".word 0x00063080\n\t" /* 8006298C: sll        $a2, $a2, 2 */
".word 0xAC900020\n\t" /* 80062990: sw         $s0, 0x20($a0) */
".word 0xAC910024\n\t" /* 80062994: sw         $s1, 0x24($a0) */
".word 0xAC920028\n\t" /* 80062998: sw         $s2, 0x28($a0) */
".word 0xAC93002C\n\t" /* 8006299C: sw         $s3, 0x2C($a0) */
".word 0xAC960030\n\t" /* 800629A0: sw         $s6, 0x30($a0) */
".word 0xAC970034\n\t" /* 800629A4: sw         $s7, 0x34($a0) */
".word 0x13000079\n\t" /* 800629A8: beqz       $t8, .L80062B90 */
".word 0x00A63821\n\t" /* 800629AC: addu      $a3, $a1, $a2 */
".word 0x3C10800A\n\t" /* 800629B0: lui        $s0, %hi(D_8009AFAC) */
".word 0x8E10AFAC\n\t" /* 800629B4: lw         $s0, %lo(D_8009AFAC)($s0) */
".word 0x3C11800A\n\t" /* 800629B8: lui        $s1, %hi(D_8009AFD8) */
".word 0x8E31AFD8\n\t" /* 800629BC: lw         $s1, %lo(D_8009AFD8)($s1) */
".word 0x3C12800A\n\t" /* 800629C0: lui        $s2, %hi(D_8009AFDC) */
".word 0x8E52AFDC\n\t" /* 800629C4: lw         $s2, %lo(D_8009AFDC)($s2) */
".word 0x3C16800A\n\t" /* 800629C8: lui        $s6, %hi(D_8009AFE4) */
".word 0x82D6AFE4\n\t" /* 800629CC: lb         $s6, %lo(D_8009AFE4)($s6) */
".word 0x3C17800A\n\t" /* 800629D0: lui        $s7, %hi(D_8009AFE0) */
".word 0x8EF7AFE0\n\t" /* 800629D4: lw         $s7, %lo(D_8009AFE0)($s7) */
".word 0x02006021\n\t" /* 800629D8: addu       $t4, $s0, $zero */
".word 0x00109E02\n\t" /* 800629DC: srl        $s3, $s0, 24 */
".word 0x8C850018\n\t" /* 800629E0: lw         $a1, 0x18($a0) */
".word 0x8C86001C\n\t" /* 800629E4: lw         $a2, 0x1C($a0) */
".word 0x48903000\n\t" /* 800629E8: mtc2       $s0, $6 ( handwritten instruction ) */
".word 0x8C8D0004\n\t" /* 800629EC: lw         $t5, 0x4($a0) */
".word 0x8C8E0008\n\t" /* 800629F0: lw         $t6, 0x8($a0) */
".word 0x8DAF0004\n\t" /* 800629F4: lw         $t7, 0x4($t5) */
".L800629F8:\n\t"
".word 0x8CE8000C\n\t" /* 800629F8: lw         $t0, 0xC($a3) */
".word 0x8CE90010\n\t" /* 800629FC: lw         $t1, 0x10($a3) */
".word 0x00086C02\n\t" /* 80062A00: srl        $t5, $t0, 16 */
".word 0x000D68C0\n\t" /* 80062A04: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 80062A08: addu       $t5, $t5, $a1 */
".word 0xC9A00000\n\t" /* 80062A0C: lwc2       $0, 0x0($t5) */
".word 0xC9A10004\n\t" /* 80062A10: lwc2       $1, 0x4($t5) */
".word 0x00096C00\n\t" /* 80062A14: sll        $t5, $t1, 16 */
".word 0x000D6B42\n\t" /* 80062A18: srl        $t5, $t5, 13 */
".word 0x01A56821\n\t" /* 80062A1C: addu       $t5, $t5, $a1 */
".word 0xC9A20000\n\t" /* 80062A20: lwc2       $2, 0x0($t5) */
".word 0xC9A30004\n\t" /* 80062A24: lwc2       $3, 0x4($t5) */
".word 0x00096C02\n\t" /* 80062A28: srl        $t5, $t1, 16 */
".word 0x000D68C0\n\t" /* 80062A2C: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 80062A30: addu       $t5, $t5, $a1 */
".word 0xC9A40000\n\t" /* 80062A34: lwc2       $4, 0x0($t5) */
".word 0xC9A50004\n\t" /* 80062A38: lwc2       $5, 0x4($t5) */
".word 0x00084400\n\t" /* 80062A3C: sll        $t0, $t0, 16 */
".word 0x00084342\n\t" /* 80062A40: srl        $t0, $t0, 13 */
".word 0x4A280030\n\t" /* 80062A44: rtpt */
".word 0x24010001\n\t" /* 80062A48: addiu      $at, $zero, 0x1 */
".word 0x12C10005\n\t" /* 80062A4C: beq        $s6, $at, .L80062A64 */
".word 0x00000000\n\t" /* 80062A50: nop */
".word 0x4842F800\n\t" /* 80062A54: cfc2       $v0, $31 ( handwritten instruction ) */
".word 0x00000000\n\t" /* 80062A58: nop */
".word 0x04400049\n\t" /* 80062A5C: bltz       $v0, .L80062B84 */
".word 0x00000000\n\t" /* 80062A60: nop */
".L80062A64:\n\t"
".word 0x4B58002D\n\t" /* 80062A64: avsz3 */
".word 0x12C00010\n\t" /* 80062A68: beqz       $s6, .L80062AAC */
".word 0x01066821\n\t" /* 80062A6C: addu      $t5, $t0, $a2 */
".word 0xC9A00000\n\t" /* 80062A70: lwc2       $0, 0x0($t5) */
".word 0xC9A10004\n\t" /* 80062A74: lwc2       $1, 0x4($t5) */
".word 0x00000000\n\t" /* 80062A78: nop */
".word 0x00000000\n\t" /* 80062A7C: nop */
".word 0x4B08041B\n\t" /* 80062A80: nccs */
".word 0x12E00003\n\t" /* 80062A84: beqz       $s7, .L80062A94 */
".word 0x00084042\n\t" /* 80062A88: srl       $t0, $t0, 1 */
".word 0x01174021\n\t" /* 80062A8C: addu       $t0, $t0, $s7 */
".word 0xE9160000\n\t" /* 80062A90: swc2       $22, 0x0($t0) */
".L80062A94:\n\t"
".word 0xEB360004\n\t" /* 80062A94: swc2       $22, 0x4($t9) */
".word 0x24010001\n\t" /* 80062A98: addiu      $at, $zero, 0x1 */
".word 0x12C10039\n\t" /* 80062A9C: beq        $s6, $at, .L80062B84 */
".word 0x00000000\n\t" /* 80062AA0: nop */
".word 0x08018AB1\n\t" /* 80062AA4: j          .L80062AC4 */
".word 0x00000000\n\t" /* 80062AA8: nop */
".L80062AAC:\n\t"
".word 0x00084042\n\t" /* 80062AAC: srl        $t0, $t0, 1 */
".word 0x01171821\n\t" /* 80062AB0: addu       $v1, $t0, $s7 */
".word 0x8C680000\n\t" /* 80062AB4: lw         $t0, 0x0($v1) */
".word 0x00000000\n\t" /* 80062AB8: nop */
".word 0xAF280004\n\t" /* 80062ABC: sw         $t0, 0x4($t9) */
".word 0xA3330007\n\t" /* 80062AC0: sb         $s3, 0x7($t9) */
".L80062AC4:\n\t"
".word 0x8CE80000\n\t" /* 80062AC4: lw         $t0, 0x0($a3) */
".word 0x8CE90004\n\t" /* 80062AC8: lw         $t1, 0x4($a3) */
".word 0x8CEA0008\n\t" /* 80062ACC: lw         $t2, 0x8($a3) */
".word 0x48023800\n\t" /* 80062AD0: mfc2       $v0, $7 ( handwritten instruction ) */
".word 0x3C010200\n\t" /* 80062AD4: lui        $at, (0x2000000 >> 16) */
".word 0x02011824\n\t" /* 80062AD8: and        $v1, $s0, $at */
".word 0x01314825\n\t" /* 80062ADC: or         $t1, $t1, $s1 */
".word 0x01C21006\n\t" /* 80062AE0: srlv       $v0, $v0, $t6 */
".word 0x00021080\n\t" /* 80062AE4: sll        $v0, $v0, 2 */
".word 0x004F1021\n\t" /* 80062AE8: addu       $v0, $v0, $t7 */
".word 0x8C4D0000\n\t" /* 80062AEC: lw         $t5, 0x0($v0) */
".word 0xEB2C0008\n\t" /* 80062AF0: swc2       $12, 0x8($t9) */
".word 0xEB2D0010\n\t" /* 80062AF4: swc2       $13, 0x10($t9) */
".word 0xEB2E0018\n\t" /* 80062AF8: swc2       $14, 0x18($t9) */
".L80062AFC:\n\t"
".word 0xAF28000C\n\t" /* 80062AFC: sw         $t0, 0xC($t9) */
".word 0xAF290014\n\t" /* 80062B00: sw         $t1, 0x14($t9) */
".word 0xAF2A001C\n\t" /* 80062B04: sw         $t2, 0x1C($t9) */
".word 0x000D6A00\n\t" /* 80062B08: sll        $t5, $t5, 8 */
".word 0x35AD0007\n\t" /* 80062B0C: ori        $t5, $t5, 0x7 */
".word 0x000D0A02\n\t" /* 80062B10: srl        $at, $t5, 8 */
".word 0x000D6E00\n\t" /* 80062B14: sll        $t5, $t5, 24 */
".word 0x01A16825\n\t" /* 80062B18: or         $t5, $t5, $at */
".word 0xAF2D0000\n\t" /* 80062B1C: sw         $t5, 0x0($t9) */
".word 0x00196A00\n\t" /* 80062B20: sll        $t5, $t9, 8 */
".word 0x000D6A02\n\t" /* 80062B24: srl        $t5, $t5, 8 */
".word 0x10600015\n\t" /* 80062B28: beqz       $v1, .L80062B80 */
".word 0xAC4D0000\n\t" /* 80062B2C: sw        $t5, 0x0($v0) */
".word 0x12400013\n\t" /* 80062B30: beqz       $s2, .L80062B80 */
".word 0x00000000\n\t" /* 80062B34: nop */
".word 0x3C01FF9F\n\t" /* 80062B38: lui        $at, (0xFF9FFFFF >> 16) */
".word 0x3421FFFF\n\t" /* 80062B3C: ori        $at, $at, (0xFF9FFFFF & 0xFFFF) */
".word 0x01214824\n\t" /* 80062B40: and        $t1, $t1, $at */
".word 0x3C010040\n\t" /* 80062B44: lui        $at, (0x400000 >> 16) */
".word 0x01214825\n\t" /* 80062B48: or         $t1, $t1, $at */
".word 0x8F230008\n\t" /* 80062B4C: lw         $v1, 0x8($t9) */
".word 0x00084400\n\t" /* 80062B50: sll        $t0, $t0, 16 */
".word 0xAF230028\n\t" /* 80062B54: sw         $v1, 0x28($t9) */
".word 0x8F230010\n\t" /* 80062B58: lw         $v1, 0x10($t9) */
".word 0x00084402\n\t" /* 80062B5C: srl        $t0, $t0, 16 */
".word 0xAF230030\n\t" /* 80062B60: sw         $v1, 0x30($t9) */
".word 0x8F230018\n\t" /* 80062B64: lw         $v1, 0x18($t9) */
".word 0x01124025\n\t" /* 80062B68: or         $t0, $t0, $s2 */
".word 0xAF230038\n\t" /* 80062B6C: sw         $v1, 0x38($t9) */
".word 0xAF2C0024\n\t" /* 80062B70: sw         $t4, 0x24($t9) */
".word 0x27390020\n\t" /* 80062B74: addiu      $t9, $t9, 0x20 */
".word 0x08018ABF\n\t" /* 80062B78: j          .L80062AFC */
".word 0x24030000\n\t" /* 80062B7C: addiu     $v1, $zero, 0x0 */
".L80062B80:\n\t"
".word 0x27390020\n\t" /* 80062B80: addiu      $t9, $t9, 0x20 */
".L80062B84:\n\t"
".word 0x2718FFFF\n\t" /* 80062B84: addiu      $t8, $t8, -0x1 */
".word 0x1700FF9B\n\t" /* 80062B88: bnez       $t8, .L800629F8 */
".word 0x24E70014\n\t" /* 80062B8C: addiu     $a3, $a3, 0x14 */
".L80062B90:\n\t"
".word 0x8C900020\n\t" /* 80062B90: lw         $s0, 0x20($a0) */
".word 0x8C910024\n\t" /* 80062B94: lw         $s1, 0x24($a0) */
".word 0x8C920028\n\t" /* 80062B98: lw         $s2, 0x28($a0) */
".word 0x8C93002C\n\t" /* 80062B9C: lw         $s3, 0x2C($a0) */
".word 0x8C960030\n\t" /* 80062BA0: lw         $s6, 0x30($a0) */
".word 0x8C970034\n\t" /* 80062BA4: lw         $s7, 0x34($a0) */
".word 0x8C820000\n\t" /* 80062BA8: lw         $v0, 0x0($a0) */
".word 0x3C018010\n\t" /* 80062BAC: lui        $at, %hi(D_800FE240) */
".word 0xAC39E240\n\t" /* 80062BB0: sw         $t9, %lo(D_800FE240)($at) */
".word 0x24420008\n\t" /* 80062BB4: addiu      $v0, $v0, 0x8 */
".word 0x03E00008\n\t" /* 80062BB8: jr         $ra */
".word 0x00000000\n\t" /* 80062BBC: nop */
    ".set reorder\n"
);
