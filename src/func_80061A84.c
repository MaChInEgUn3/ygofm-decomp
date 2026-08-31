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
    ".global func_80061A84\n"
    "func_80061A84:\n"
".word 0x8C870000\n\t" /* 80061A84: lw         $a3, 0x0($a0) */
".word 0x8C990010\n\t" /* 80061A88: lw         $t9, 0x10($a0) */
".word 0x94F80002\n\t" /* 80061A8C: lhu        $t8, 0x2($a3) */
".word 0x8CE60004\n\t" /* 80061A90: lw         $a2, 0x4($a3) */
".word 0x8C850014\n\t" /* 80061A94: lw         $a1, 0x14($a0) */
".word 0x00063080\n\t" /* 80061A98: sll        $a2, $a2, 2 */
".word 0xAC900020\n\t" /* 80061A9C: sw         $s0, 0x20($a0) */
".word 0xAC910024\n\t" /* 80061AA0: sw         $s1, 0x24($a0) */
".word 0xAC920028\n\t" /* 80061AA4: sw         $s2, 0x28($a0) */
".word 0xAC93002C\n\t" /* 80061AA8: sw         $s3, 0x2C($a0) */
".word 0xAC960030\n\t" /* 80061AAC: sw         $s6, 0x30($a0) */
".word 0xAC970034\n\t" /* 80061AB0: sw         $s7, 0x34($a0) */
".word 0x130000BD\n\t" /* 80061AB4: beqz       $t8, .L80061DAC */
".word 0x00A63821\n\t" /* 80061AB8: addu      $a3, $a1, $a2 */
".word 0x3C10800A\n\t" /* 80061ABC: lui        $s0, %hi(D_8009AFB8) */
".word 0x8E10AFB8\n\t" /* 80061AC0: lw         $s0, %lo(D_8009AFB8)($s0) */
".word 0x3C11800A\n\t" /* 80061AC4: lui        $s1, %hi(D_8009AFD8) */
".word 0x8E31AFD8\n\t" /* 80061AC8: lw         $s1, %lo(D_8009AFD8)($s1) */
".word 0x3C12800A\n\t" /* 80061ACC: lui        $s2, %hi(D_8009AFDC) */
".word 0x8E52AFDC\n\t" /* 80061AD0: lw         $s2, %lo(D_8009AFDC)($s2) */
".word 0x3C16800A\n\t" /* 80061AD4: lui        $s6, %hi(D_8009AFE4) */
".word 0x82D6AFE4\n\t" /* 80061AD8: lb         $s6, %lo(D_8009AFE4)($s6) */
".word 0x3C17800A\n\t" /* 80061ADC: lui        $s7, %hi(D_8009AFE0) */
".word 0x8EF7AFE0\n\t" /* 80061AE0: lw         $s7, %lo(D_8009AFE0)($s7) */
".word 0x02006021\n\t" /* 80061AE4: addu       $t4, $s0, $zero */
".word 0x00109E02\n\t" /* 80061AE8: srl        $s3, $s0, 24 */
".word 0x8C850018\n\t" /* 80061AEC: lw         $a1, 0x18($a0) */
".word 0x8C86001C\n\t" /* 80061AF0: lw         $a2, 0x1C($a0) */
".word 0x48903000\n\t" /* 80061AF4: mtc2       $s0, $6 ( handwritten instruction ) */
".word 0x8C8D0004\n\t" /* 80061AF8: lw         $t5, 0x4($a0) */
".word 0x8C8E0008\n\t" /* 80061AFC: lw         $t6, 0x8($a0) */
".word 0x8DAF0004\n\t" /* 80061B00: lw         $t7, 0x4($t5) */
".L80061B04:\n\t"
".word 0x8CE8000C\n\t" /* 80061B04: lw         $t0, 0xC($a3) */
".word 0x98E8000A\n\t" /* 80061B08: lwr        $t0, 0xA($a3) */
".word 0x8CE90010\n\t" /* 80061B0C: lw         $t1, 0x10($a3) */
".word 0x8CEA0014\n\t" /* 80061B10: lw         $t2, 0x14($a3) */
".word 0x8CEB0018\n\t" /* 80061B14: lw         $t3, 0x18($a3) */
".word 0x00086C02\n\t" /* 80061B18: srl        $t5, $t0, 16 */
".word 0x000D68C0\n\t" /* 80061B1C: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 80061B20: addu       $t5, $t5, $a1 */
".word 0xC9A00000\n\t" /* 80061B24: lwc2       $0, 0x0($t5) */
".word 0xC9A10004\n\t" /* 80061B28: lwc2       $1, 0x4($t5) */
".word 0x00096C02\n\t" /* 80061B2C: srl        $t5, $t1, 16 */
".word 0x000D68C0\n\t" /* 80061B30: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 80061B34: addu       $t5, $t5, $a1 */
".word 0xC9A20000\n\t" /* 80061B38: lwc2       $2, 0x0($t5) */
".word 0xC9A30004\n\t" /* 80061B3C: lwc2       $3, 0x4($t5) */
".word 0x000A6C02\n\t" /* 80061B40: srl        $t5, $t2, 16 */
".word 0x000D68C0\n\t" /* 80061B44: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 80061B48: addu       $t5, $t5, $a1 */
".word 0xC9A40000\n\t" /* 80061B4C: lwc2       $4, 0x0($t5) */
".word 0xC9A50004\n\t" /* 80061B50: lwc2       $5, 0x4($t5) */
".word 0x000B6C02\n\t" /* 80061B54: srl        $t5, $t3, 16 */
".word 0x000D68C0\n\t" /* 80061B58: sll        $t5, $t5, 3 */
".word 0x4A280030\n\t" /* 80061B5C: rtpt */
".word 0x000B5C00\n\t" /* 80061B60: sll        $t3, $t3, 16 */
".word 0x000B5B42\n\t" /* 80061B64: srl        $t3, $t3, 13 */
".word 0x24010001\n\t" /* 80061B68: addiu      $at, $zero, 0x1 */
".word 0x12C1000A\n\t" /* 80061B6C: beq        $s6, $at, .L80061B98 */
".word 0x01A56821\n\t" /* 80061B70: addu      $t5, $t5, $a1 */
".word 0x4842F800\n\t" /* 80061B74: cfc2       $v0, $31 ( handwritten instruction ) */
".word 0x00000000\n\t" /* 80061B78: nop */
".word 0x04400088\n\t" /* 80061B7C: bltz       $v0, .L80061DA0 */
".word 0x00000000\n\t" /* 80061B80: nop */
".word 0x4B400006\n\t" /* 80061B84: nclip */
".word 0x4802C000\n\t" /* 80061B88: mfc2       $v0, $24 ( handwritten instruction ) */
".word 0x00000000\n\t" /* 80061B8C: nop */
".word 0x18400083\n\t" /* 80061B90: blez       $v0, .L80061DA0 */
".word 0x00000000\n\t" /* 80061B94: nop */
".L80061B98:\n\t"
".word 0xC9A00000\n\t" /* 80061B98: lwc2       $0, 0x0($t5) */
".word 0xC9A10004\n\t" /* 80061B9C: lwc2       $1, 0x4($t5) */
".word 0xEB2C0008\n\t" /* 80061BA0: swc2       $12, 0x8($t9) */
".word 0xEB2D0014\n\t" /* 80061BA4: swc2       $13, 0x14($t9) */
".word 0xEB2E0020\n\t" /* 80061BA8: swc2       $14, 0x20($t9) */
".word 0x00084400\n\t" /* 80061BAC: sll        $t0, $t0, 16 */
".word 0x00084342\n\t" /* 80061BB0: srl        $t0, $t0, 13 */
".word 0x4A180001\n\t" /* 80061BB4: rtps */
".word 0x00094C00\n\t" /* 80061BB8: sll        $t1, $t1, 16 */
".word 0x24010001\n\t" /* 80061BBC: addiu      $at, $zero, 0x1 */
".word 0x12C10005\n\t" /* 80061BC0: beq        $s6, $at, .L80061BD8 */
".word 0x00094B42\n\t" /* 80061BC4: srl       $t1, $t1, 13 */
".word 0x4842F800\n\t" /* 80061BC8: cfc2       $v0, $31 ( handwritten instruction ) */
".word 0x00000000\n\t" /* 80061BCC: nop */
".word 0x04400073\n\t" /* 80061BD0: bltz       $v0, .L80061DA0 */
".word 0x00000000\n\t" /* 80061BD4: nop */
".L80061BD8:\n\t"
".word 0x4B68002E\n\t" /* 80061BD8: avsz4 */
".word 0xEB2E002C\n\t" /* 80061BDC: swc2       $14, 0x2C($t9) */
".word 0x000A5400\n\t" /* 80061BE0: sll        $t2, $t2, 16 */
".word 0x000A5342\n\t" /* 80061BE4: srl        $t2, $t2, 13 */
".word 0x12C00029\n\t" /* 80061BE8: beqz       $s6, .L80061C90 */
".word 0x01666821\n\t" /* 80061BEC: addu      $t5, $t3, $a2 */
".word 0xC9A00000\n\t" /* 80061BF0: lwc2       $0, 0x0($t5) */
".word 0xC9A10004\n\t" /* 80061BF4: lwc2       $1, 0x4($t5) */
".word 0x00000000\n\t" /* 80061BF8: nop */
".word 0x00000000\n\t" /* 80061BFC: nop */
".word 0x4B08041B\n\t" /* 80061C00: nccs */
".word 0x01066821\n\t" /* 80061C04: addu       $t5, $t0, $a2 */
".word 0xC9A00000\n\t" /* 80061C08: lwc2       $0, 0x0($t5) */
".word 0xC9A10004\n\t" /* 80061C0C: lwc2       $1, 0x4($t5) */
".word 0x01266821\n\t" /* 80061C10: addu       $t5, $t1, $a2 */
".word 0xC9A20000\n\t" /* 80061C14: lwc2       $2, 0x0($t5) */
".word 0xC9A30004\n\t" /* 80061C18: lwc2       $3, 0x4($t5) */
".word 0x01466821\n\t" /* 80061C1C: addu       $t5, $t2, $a2 */
".word 0xC9A40000\n\t" /* 80061C20: lwc2       $4, 0x0($t5) */
".word 0xC9A50004\n\t" /* 80061C24: lwc2       $5, 0x4($t5) */
".word 0x12E00003\n\t" /* 80061C28: beqz       $s7, .L80061C38 */
".word 0x000B5842\n\t" /* 80061C2C: srl       $t3, $t3, 1 */
".word 0x01775821\n\t" /* 80061C30: addu       $t3, $t3, $s7 */
".word 0xE9760000\n\t" /* 80061C34: swc2       $22, 0x0($t3) */
".L80061C38:\n\t"
".word 0xEB360028\n\t" /* 80061C38: swc2       $22, 0x28($t9) */
".word 0x00000000\n\t" /* 80061C3C: nop */
".word 0x00000000\n\t" /* 80061C40: nop */
".word 0x4B18043F\n\t" /* 80061C44: ncct */
".word 0x12E00009\n\t" /* 80061C48: beqz       $s7, .L80061C70 */
".word 0x00084042\n\t" /* 80061C4C: srl       $t0, $t0, 1 */
".word 0x01174021\n\t" /* 80061C50: addu       $t0, $t0, $s7 */
".word 0x00094842\n\t" /* 80061C54: srl        $t1, $t1, 1 */
".word 0x01374821\n\t" /* 80061C58: addu       $t1, $t1, $s7 */
".word 0x000A5042\n\t" /* 80061C5C: srl        $t2, $t2, 1 */
".word 0x01575021\n\t" /* 80061C60: addu       $t2, $t2, $s7 */
".word 0xE9140000\n\t" /* 80061C64: swc2       $20, 0x0($t0) */
".word 0xE9350000\n\t" /* 80061C68: swc2       $21, 0x0($t1) */
".word 0xE9560000\n\t" /* 80061C6C: swc2       $22, 0x0($t2) */
".L80061C70:\n\t"
".word 0xEB340004\n\t" /* 80061C70: swc2       $20, 0x4($t9) */
".word 0xEB350010\n\t" /* 80061C74: swc2       $21, 0x10($t9) */
".word 0xEB36001C\n\t" /* 80061C78: swc2       $22, 0x1C($t9) */
".word 0x24010001\n\t" /* 80061C7C: addiu      $at, $zero, 0x1 */
".word 0x12C10047\n\t" /* 80061C80: beq        $s6, $at, .L80061DA0 */
".word 0x00000000\n\t" /* 80061C84: nop */
".word 0x08018735\n\t" /* 80061C88: j          .L80061CD4 */
".word 0x00000000\n\t" /* 80061C8C: nop */
".L80061C90:\n\t"
".word 0x00084042\n\t" /* 80061C90: srl        $t0, $t0, 1 */
".word 0x01171821\n\t" /* 80061C94: addu       $v1, $t0, $s7 */
".word 0x8C680000\n\t" /* 80061C98: lw         $t0, 0x0($v1) */
".word 0x00094842\n\t" /* 80061C9C: srl        $t1, $t1, 1 */
".word 0x01371821\n\t" /* 80061CA0: addu       $v1, $t1, $s7 */
".word 0x8C690000\n\t" /* 80061CA4: lw         $t1, 0x0($v1) */
".word 0x000A5042\n\t" /* 80061CA8: srl        $t2, $t2, 1 */
".word 0x01571821\n\t" /* 80061CAC: addu       $v1, $t2, $s7 */
".word 0x8C6A0000\n\t" /* 80061CB0: lw         $t2, 0x0($v1) */
".word 0x000B5842\n\t" /* 80061CB4: srl        $t3, $t3, 1 */
".word 0x01771821\n\t" /* 80061CB8: addu       $v1, $t3, $s7 */
".word 0x8C6B0000\n\t" /* 80061CBC: lw         $t3, 0x0($v1) */
".word 0xAF280004\n\t" /* 80061CC0: sw         $t0, 0x4($t9) */
".word 0xAF290010\n\t" /* 80061CC4: sw         $t1, 0x10($t9) */
".word 0xAF2A001C\n\t" /* 80061CC8: sw         $t2, 0x1C($t9) */
".word 0xAF2B0028\n\t" /* 80061CCC: sw         $t3, 0x28($t9) */
".word 0xA3330007\n\t" /* 80061CD0: sb         $s3, 0x7($t9) */
".L80061CD4:\n\t"
".word 0x8CE80000\n\t" /* 80061CD4: lw         $t0, 0x0($a3) */
".word 0x8CE90004\n\t" /* 80061CD8: lw         $t1, 0x4($a3) */
".word 0x8CEA0008\n\t" /* 80061CDC: lw         $t2, 0x8($a3) */
".word 0x8CEB000C\n\t" /* 80061CE0: lw         $t3, 0xC($a3) */
".word 0x48023800\n\t" /* 80061CE4: mfc2       $v0, $7 ( handwritten instruction ) */
".word 0x3C010200\n\t" /* 80061CE8: lui        $at, (0x2000000 >> 16) */
".word 0x02011824\n\t" /* 80061CEC: and        $v1, $s0, $at */
".word 0x01314825\n\t" /* 80061CF0: or         $t1, $t1, $s1 */
".word 0x01C21006\n\t" /* 80061CF4: srlv       $v0, $v0, $t6 */
".word 0x00021080\n\t" /* 80061CF8: sll        $v0, $v0, 2 */
".word 0x004F1021\n\t" /* 80061CFC: addu       $v0, $v0, $t7 */
".word 0x8C4D0000\n\t" /* 80061D00: lw         $t5, 0x0($v0) */
".L80061D04:\n\t"
".word 0xAF28000C\n\t" /* 80061D04: sw         $t0, 0xC($t9) */
".word 0xAF290018\n\t" /* 80061D08: sw         $t1, 0x18($t9) */
".word 0xAF2A0024\n\t" /* 80061D0C: sw         $t2, 0x24($t9) */
".word 0xAF2B0030\n\t" /* 80061D10: sw         $t3, 0x30($t9) */
".word 0x000D6A00\n\t" /* 80061D14: sll        $t5, $t5, 8 */
".word 0x35AD000C\n\t" /* 80061D18: ori        $t5, $t5, 0xC */
".word 0x000D0A02\n\t" /* 80061D1C: srl        $at, $t5, 8 */
".word 0x000D6E00\n\t" /* 80061D20: sll        $t5, $t5, 24 */
".word 0x01A16825\n\t" /* 80061D24: or         $t5, $t5, $at */
".word 0xAF2D0000\n\t" /* 80061D28: sw         $t5, 0x0($t9) */
".word 0x00196A00\n\t" /* 80061D2C: sll        $t5, $t9, 8 */
".word 0x000D6A02\n\t" /* 80061D30: srl        $t5, $t5, 8 */
".word 0x10600019\n\t" /* 80061D34: beqz       $v1, .L80061D9C */
".word 0xAC4D0000\n\t" /* 80061D38: sw        $t5, 0x0($v0) */
".word 0x12400017\n\t" /* 80061D3C: beqz       $s2, .L80061D9C */
".word 0x00084400\n\t" /* 80061D40: sll       $t0, $t0, 16 */
".word 0x00084402\n\t" /* 80061D44: srl        $t0, $t0, 16 */
".word 0x01124025\n\t" /* 80061D48: or         $t0, $t0, $s2 */
".word 0x3C01FF9F\n\t" /* 80061D4C: lui        $at, (0xFF9FFFFF >> 16) */
".word 0x3421FFFF\n\t" /* 80061D50: ori        $at, $at, (0xFF9FFFFF & 0xFFFF) */
".word 0x01214824\n\t" /* 80061D54: and        $t1, $t1, $at */
".word 0x3C010040\n\t" /* 80061D58: lui        $at, (0x400000 >> 16) */
".word 0x01214825\n\t" /* 80061D5C: or         $t1, $t1, $at */
".word 0x8F230008\n\t" /* 80061D60: lw         $v1, 0x8($t9) */
".word 0xAF2C0038\n\t" /* 80061D64: sw         $t4, 0x38($t9) */
".word 0xAF23003C\n\t" /* 80061D68: sw         $v1, 0x3C($t9) */
".word 0x8F230014\n\t" /* 80061D6C: lw         $v1, 0x14($t9) */
".word 0xAF2C0044\n\t" /* 80061D70: sw         $t4, 0x44($t9) */
".word 0xAF230048\n\t" /* 80061D74: sw         $v1, 0x48($t9) */
".word 0x8F230020\n\t" /* 80061D78: lw         $v1, 0x20($t9) */
".word 0xAF2C0050\n\t" /* 80061D7C: sw         $t4, 0x50($t9) */
".word 0xAF230054\n\t" /* 80061D80: sw         $v1, 0x54($t9) */
".word 0x8F23002C\n\t" /* 80061D84: lw         $v1, 0x2C($t9) */
".word 0xAF2C005C\n\t" /* 80061D88: sw         $t4, 0x5C($t9) */
".word 0xAF230060\n\t" /* 80061D8C: sw         $v1, 0x60($t9) */
".word 0x27390034\n\t" /* 80061D90: addiu      $t9, $t9, 0x34 */
".word 0x08018741\n\t" /* 80061D94: j          .L80061D04 */
".word 0x24030000\n\t" /* 80061D98: addiu     $v1, $zero, 0x0 */
".L80061D9C:\n\t"
".word 0x27390034\n\t" /* 80061D9C: addiu      $t9, $t9, 0x34 */
".L80061DA0:\n\t"
".word 0x2718FFFF\n\t" /* 80061DA0: addiu      $t8, $t8, -0x1 */
".word 0x1700FF57\n\t" /* 80061DA4: bnez       $t8, .L80061B04 */
".word 0x24E7001C\n\t" /* 80061DA8: addiu     $a3, $a3, 0x1C */
".L80061DAC:\n\t"
".word 0x8C900020\n\t" /* 80061DAC: lw         $s0, 0x20($a0) */
".word 0x8C910024\n\t" /* 80061DB0: lw         $s1, 0x24($a0) */
".word 0x8C920028\n\t" /* 80061DB4: lw         $s2, 0x28($a0) */
".word 0x8C93002C\n\t" /* 80061DB8: lw         $s3, 0x2C($a0) */
".word 0x8C960030\n\t" /* 80061DBC: lw         $s6, 0x30($a0) */
".word 0x8C970034\n\t" /* 80061DC0: lw         $s7, 0x34($a0) */
".word 0x8C820000\n\t" /* 80061DC4: lw         $v0, 0x0($a0) */
".word 0x3C018010\n\t" /* 80061DC8: lui        $at, %hi(D_800FE240) */
".word 0xAC39E240\n\t" /* 80061DCC: sw         $t9, %lo(D_800FE240)($at) */
".word 0x24420008\n\t" /* 80061DD0: addiu      $v0, $v0, 0x8 */
".word 0x03E00008\n\t" /* 80061DD4: jr         $ra */
".word 0x00000000\n\t" /* 80061DD8: nop */
    ".set reorder\n"
);
