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
    ".global func_80064868\n"
    "func_80064868:\n"
".word 0x8C870000\n\t" /* 80064868: lw         $a3, 0x0($a0) */
".word 0x8C990010\n\t" /* 8006486C: lw         $t9, 0x10($a0) */
".word 0x94F80002\n\t" /* 80064870: lhu        $t8, 0x2($a3) */
".word 0x8CE60004\n\t" /* 80064874: lw         $a2, 0x4($a3) */
".word 0x8C850014\n\t" /* 80064878: lw         $a1, 0x14($a0) */
".word 0x00063080\n\t" /* 8006487C: sll        $a2, $a2, 2 */
".word 0xAC900020\n\t" /* 80064880: sw         $s0, 0x20($a0) */
".word 0xAC910024\n\t" /* 80064884: sw         $s1, 0x24($a0) */
".word 0xAC920028\n\t" /* 80064888: sw         $s2, 0x28($a0) */
".word 0xAC93002C\n\t" /* 8006488C: sw         $s3, 0x2C($a0) */
".word 0xAC960030\n\t" /* 80064890: sw         $s6, 0x30($a0) */
".word 0xAC970034\n\t" /* 80064894: sw         $s7, 0x34($a0) */
".word 0x130000D4\n\t" /* 80064898: beqz       $t8, .L80064BEC */
".word 0x00A63821\n\t" /* 8006489C: addu      $a3, $a1, $a2 */
".word 0x3C10800A\n\t" /* 800648A0: lui        $s0, %hi(D_8009AFB8) */
".word 0x8E10AFB8\n\t" /* 800648A4: lw         $s0, %lo(D_8009AFB8)($s0) */
".word 0x3C11800A\n\t" /* 800648A8: lui        $s1, %hi(D_8009AFD8) */
".word 0x8E31AFD8\n\t" /* 800648AC: lw         $s1, %lo(D_8009AFD8)($s1) */
".word 0x3C12800A\n\t" /* 800648B0: lui        $s2, %hi(D_8009AFDC) */
".word 0x8E52AFDC\n\t" /* 800648B4: lw         $s2, %lo(D_8009AFDC)($s2) */
".word 0x3C16800A\n\t" /* 800648B8: lui        $s6, %hi(D_8009AFE4) */
".word 0x82D6AFE4\n\t" /* 800648BC: lb         $s6, %lo(D_8009AFE4)($s6) */
".word 0x3C17800A\n\t" /* 800648C0: lui        $s7, %hi(D_8009AFE0) */
".word 0x8EF7AFE0\n\t" /* 800648C4: lw         $s7, %lo(D_8009AFE0)($s7) */
".word 0x02006021\n\t" /* 800648C8: addu       $t4, $s0, $zero */
".word 0x3C02800A\n\t" /* 800648CC: lui        $v0, %hi(D_8009AFE5) */
".word 0x8042AFE5\n\t" /* 800648D0: lb         $v0, %lo(D_8009AFE5)($v0) */
".word 0x3C010200\n\t" /* 800648D4: lui        $at, (0x2000000 >> 16) */
".word 0x02018025\n\t" /* 800648D8: or         $s0, $s0, $at */
".word 0x1440000E\n\t" /* 800648DC: bnez       $v0, .L80064918 */
".word 0x02006021\n\t" /* 800648E0: addu      $t4, $s0, $zero */
".word 0x8CF10004\n\t" /* 800648E4: lw         $s1, 0x4($a3) */
".word 0x3C010060\n\t" /* 800648E8: lui        $at, (0x600000 >> 16) */
".word 0x02218824\n\t" /* 800648EC: and        $s1, $s1, $at */
".word 0x16200009\n\t" /* 800648F0: bnez       $s1, .L80064918 */
".word 0x00000000\n\t" /* 800648F4: nop */
".word 0x12400008\n\t" /* 800648F8: beqz       $s2, .L8006491C */
".word 0x00000000\n\t" /* 800648FC: nop */
".word 0x94F20002\n\t" /* 80064900: lhu        $s2, 0x2($a3) */
".word 0x3C0C800A\n\t" /* 80064904: lui        $t4, %hi(D_8009AFC8) */
".word 0x8D8CAFC8\n\t" /* 80064908: lw         $t4, %lo(D_8009AFC8)($t4) */
".word 0x00129400\n\t" /* 8006490C: sll        $s2, $s2, 16 */
".word 0x08019247\n\t" /* 80064910: j          .L8006491C */
".word 0x3C110020\n\t" /* 80064914: lui       $s1, (0x200000 >> 16) */
".L80064918:\n\t"
".word 0x24120000\n\t" /* 80064918: addiu      $s2, $zero, 0x0 */
".L8006491C:\n\t"
".word 0x00109E02\n\t" /* 8006491C: srl        $s3, $s0, 24 */
".word 0x8C850018\n\t" /* 80064920: lw         $a1, 0x18($a0) */
".word 0x8C86001C\n\t" /* 80064924: lw         $a2, 0x1C($a0) */
".word 0x48903000\n\t" /* 80064928: mtc2       $s0, $6 ( handwritten instruction ) */
".word 0x8C8D0004\n\t" /* 8006492C: lw         $t5, 0x4($a0) */
".word 0x8C8E0008\n\t" /* 80064930: lw         $t6, 0x8($a0) */
".word 0x8DAF0004\n\t" /* 80064934: lw         $t7, 0x4($t5) */
".L80064938:\n\t"
".word 0x8CE8000C\n\t" /* 80064938: lw         $t0, 0xC($a3) */
".word 0x98E8000A\n\t" /* 8006493C: lwr        $t0, 0xA($a3) */
".word 0x8CE90010\n\t" /* 80064940: lw         $t1, 0x10($a3) */
".word 0x8CEA0014\n\t" /* 80064944: lw         $t2, 0x14($a3) */
".word 0x8CEB0018\n\t" /* 80064948: lw         $t3, 0x18($a3) */
".word 0x00086C02\n\t" /* 8006494C: srl        $t5, $t0, 16 */
".word 0x000D68C0\n\t" /* 80064950: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 80064954: addu       $t5, $t5, $a1 */
".word 0xC9A00000\n\t" /* 80064958: lwc2       $0, 0x0($t5) */
".word 0xC9A10004\n\t" /* 8006495C: lwc2       $1, 0x4($t5) */
".word 0x00096C02\n\t" /* 80064960: srl        $t5, $t1, 16 */
".word 0x000D68C0\n\t" /* 80064964: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 80064968: addu       $t5, $t5, $a1 */
".word 0xC9A20000\n\t" /* 8006496C: lwc2       $2, 0x0($t5) */
".word 0xC9A30004\n\t" /* 80064970: lwc2       $3, 0x4($t5) */
".word 0x000A6C02\n\t" /* 80064974: srl        $t5, $t2, 16 */
".word 0x000D68C0\n\t" /* 80064978: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 8006497C: addu       $t5, $t5, $a1 */
".word 0xC9A40000\n\t" /* 80064980: lwc2       $4, 0x0($t5) */
".word 0xC9A50004\n\t" /* 80064984: lwc2       $5, 0x4($t5) */
".word 0x000B6C02\n\t" /* 80064988: srl        $t5, $t3, 16 */
".word 0x000D68C0\n\t" /* 8006498C: sll        $t5, $t5, 3 */
".word 0x4A280030\n\t" /* 80064990: rtpt */
".word 0x000B5C00\n\t" /* 80064994: sll        $t3, $t3, 16 */
".word 0x000B5B42\n\t" /* 80064998: srl        $t3, $t3, 13 */
".word 0x24010001\n\t" /* 8006499C: addiu      $at, $zero, 0x1 */
".word 0x12C1000A\n\t" /* 800649A0: beq        $s6, $at, .L800649CC */
".word 0x01A56821\n\t" /* 800649A4: addu      $t5, $t5, $a1 */
".word 0x4842F800\n\t" /* 800649A8: cfc2       $v0, $31 ( handwritten instruction ) */
".word 0x00000000\n\t" /* 800649AC: nop */
".word 0x0440008B\n\t" /* 800649B0: bltz       $v0, .L80064BE0 */
".word 0x00000000\n\t" /* 800649B4: nop */
".word 0x4B400006\n\t" /* 800649B8: nclip */
".word 0x4802C000\n\t" /* 800649BC: mfc2       $v0, $24 ( handwritten instruction ) */
".word 0x00000000\n\t" /* 800649C0: nop */
".word 0x18400086\n\t" /* 800649C4: blez       $v0, .L80064BE0 */
".word 0x00000000\n\t" /* 800649C8: nop */
".L800649CC:\n\t"
".word 0xC9A00000\n\t" /* 800649CC: lwc2       $0, 0x0($t5) */
".word 0xC9A10004\n\t" /* 800649D0: lwc2       $1, 0x4($t5) */
".word 0xEB2C0008\n\t" /* 800649D4: swc2       $12, 0x8($t9) */
".word 0xEB2D0014\n\t" /* 800649D8: swc2       $13, 0x14($t9) */
".word 0xEB2E0020\n\t" /* 800649DC: swc2       $14, 0x20($t9) */
".word 0x00084400\n\t" /* 800649E0: sll        $t0, $t0, 16 */
".word 0x00084342\n\t" /* 800649E4: srl        $t0, $t0, 13 */
".word 0x4A180001\n\t" /* 800649E8: rtps */
".word 0x00094C00\n\t" /* 800649EC: sll        $t1, $t1, 16 */
".word 0x24010001\n\t" /* 800649F0: addiu      $at, $zero, 0x1 */
".word 0x12C10005\n\t" /* 800649F4: beq        $s6, $at, .L80064A0C */
".word 0x00094B42\n\t" /* 800649F8: srl       $t1, $t1, 13 */
".word 0x4842F800\n\t" /* 800649FC: cfc2       $v0, $31 ( handwritten instruction ) */
".word 0x00000000\n\t" /* 80064A00: nop */
".word 0x04400076\n\t" /* 80064A04: bltz       $v0, .L80064BE0 */
".word 0x00000000\n\t" /* 80064A08: nop */
".L80064A0C:\n\t"
".word 0x4B68002E\n\t" /* 80064A0C: avsz4 */
".word 0xEB2E002C\n\t" /* 80064A10: swc2       $14, 0x2C($t9) */
".word 0x000A5400\n\t" /* 80064A14: sll        $t2, $t2, 16 */
".word 0x000A5342\n\t" /* 80064A18: srl        $t2, $t2, 13 */
".word 0x12C00029\n\t" /* 80064A1C: beqz       $s6, .L80064AC4 */
".word 0x01666821\n\t" /* 80064A20: addu      $t5, $t3, $a2 */
".word 0xC9A00000\n\t" /* 80064A24: lwc2       $0, 0x0($t5) */
".word 0xC9A10004\n\t" /* 80064A28: lwc2       $1, 0x4($t5) */
".word 0x00000000\n\t" /* 80064A2C: nop */
".word 0x00000000\n\t" /* 80064A30: nop */
".word 0x4B08041B\n\t" /* 80064A34: nccs */
".word 0x01066821\n\t" /* 80064A38: addu       $t5, $t0, $a2 */
".word 0xC9A00000\n\t" /* 80064A3C: lwc2       $0, 0x0($t5) */
".word 0xC9A10004\n\t" /* 80064A40: lwc2       $1, 0x4($t5) */
".word 0x01266821\n\t" /* 80064A44: addu       $t5, $t1, $a2 */
".word 0xC9A20000\n\t" /* 80064A48: lwc2       $2, 0x0($t5) */
".word 0xC9A30004\n\t" /* 80064A4C: lwc2       $3, 0x4($t5) */
".word 0x01466821\n\t" /* 80064A50: addu       $t5, $t2, $a2 */
".word 0xC9A40000\n\t" /* 80064A54: lwc2       $4, 0x0($t5) */
".word 0xC9A50004\n\t" /* 80064A58: lwc2       $5, 0x4($t5) */
".word 0x12E00003\n\t" /* 80064A5C: beqz       $s7, .L80064A6C */
".word 0x000B5842\n\t" /* 80064A60: srl       $t3, $t3, 1 */
".word 0x01775821\n\t" /* 80064A64: addu       $t3, $t3, $s7 */
".word 0xE9760000\n\t" /* 80064A68: swc2       $22, 0x0($t3) */
".L80064A6C:\n\t"
".word 0xEB360028\n\t" /* 80064A6C: swc2       $22, 0x28($t9) */
".word 0x00000000\n\t" /* 80064A70: nop */
".word 0x00000000\n\t" /* 80064A74: nop */
".word 0x4B18043F\n\t" /* 80064A78: ncct */
".word 0x12E00009\n\t" /* 80064A7C: beqz       $s7, .L80064AA4 */
".word 0x00084042\n\t" /* 80064A80: srl       $t0, $t0, 1 */
".word 0x01174021\n\t" /* 80064A84: addu       $t0, $t0, $s7 */
".word 0x00094842\n\t" /* 80064A88: srl        $t1, $t1, 1 */
".word 0x01374821\n\t" /* 80064A8C: addu       $t1, $t1, $s7 */
".word 0x000A5042\n\t" /* 80064A90: srl        $t2, $t2, 1 */
".word 0x01575021\n\t" /* 80064A94: addu       $t2, $t2, $s7 */
".word 0xE9140000\n\t" /* 80064A98: swc2       $20, 0x0($t0) */
".word 0xE9350000\n\t" /* 80064A9C: swc2       $21, 0x0($t1) */
".word 0xE9560000\n\t" /* 80064AA0: swc2       $22, 0x0($t2) */
".L80064AA4:\n\t"
".word 0xEB340004\n\t" /* 80064AA4: swc2       $20, 0x4($t9) */
".word 0xEB350010\n\t" /* 80064AA8: swc2       $21, 0x10($t9) */
".word 0xEB36001C\n\t" /* 80064AAC: swc2       $22, 0x1C($t9) */
".word 0x24010001\n\t" /* 80064AB0: addiu      $at, $zero, 0x1 */
".word 0x12C1004A\n\t" /* 80064AB4: beq        $s6, $at, .L80064BE0 */
".word 0x00000000\n\t" /* 80064AB8: nop */
".word 0x080192C2\n\t" /* 80064ABC: j          .L80064B08 */
".word 0x00000000\n\t" /* 80064AC0: nop */
".L80064AC4:\n\t"
".word 0x00084042\n\t" /* 80064AC4: srl        $t0, $t0, 1 */
".word 0x01171821\n\t" /* 80064AC8: addu       $v1, $t0, $s7 */
".word 0x8C680000\n\t" /* 80064ACC: lw         $t0, 0x0($v1) */
".word 0x00094842\n\t" /* 80064AD0: srl        $t1, $t1, 1 */
".word 0x01371821\n\t" /* 80064AD4: addu       $v1, $t1, $s7 */
".word 0x8C690000\n\t" /* 80064AD8: lw         $t1, 0x0($v1) */
".word 0x000A5042\n\t" /* 80064ADC: srl        $t2, $t2, 1 */
".word 0x01571821\n\t" /* 80064AE0: addu       $v1, $t2, $s7 */
".word 0x8C6A0000\n\t" /* 80064AE4: lw         $t2, 0x0($v1) */
".word 0x000B5842\n\t" /* 80064AE8: srl        $t3, $t3, 1 */
".word 0x01771821\n\t" /* 80064AEC: addu       $v1, $t3, $s7 */
".word 0x8C6B0000\n\t" /* 80064AF0: lw         $t3, 0x0($v1) */
".word 0xAF280004\n\t" /* 80064AF4: sw         $t0, 0x4($t9) */
".word 0xAF290010\n\t" /* 80064AF8: sw         $t1, 0x10($t9) */
".word 0xAF2A001C\n\t" /* 80064AFC: sw         $t2, 0x1C($t9) */
".word 0xAF2B0028\n\t" /* 80064B00: sw         $t3, 0x28($t9) */
".word 0xA3330007\n\t" /* 80064B04: sb         $s3, 0x7($t9) */
".L80064B08:\n\t"
".word 0x8CE80000\n\t" /* 80064B08: lw         $t0, 0x0($a3) */
".word 0x8CE90004\n\t" /* 80064B0C: lw         $t1, 0x4($a3) */
".word 0x8CEA0008\n\t" /* 80064B10: lw         $t2, 0x8($a3) */
".word 0x8CEB000C\n\t" /* 80064B14: lw         $t3, 0xC($a3) */
".word 0x48023800\n\t" /* 80064B18: mfc2       $v0, $7 ( handwritten instruction ) */
".word 0x3C010200\n\t" /* 80064B1C: lui        $at, (0x2000000 >> 16) */
".word 0x02011824\n\t" /* 80064B20: and        $v1, $s0, $at */
".word 0x3C01FF9F\n\t" /* 80064B24: lui        $at, (0xFF9FFFFF >> 16) */
".word 0x3421FFFF\n\t" /* 80064B28: ori        $at, $at, (0xFF9FFFFF & 0xFFFF) */
".word 0x01214824\n\t" /* 80064B2C: and        $t1, $t1, $at */
".word 0x01314825\n\t" /* 80064B30: or         $t1, $t1, $s1 */
".word 0x01C21006\n\t" /* 80064B34: srlv       $v0, $v0, $t6 */
".word 0x00021080\n\t" /* 80064B38: sll        $v0, $v0, 2 */
".word 0x004F1021\n\t" /* 80064B3C: addu       $v0, $v0, $t7 */
".word 0x8C4D0000\n\t" /* 80064B40: lw         $t5, 0x0($v0) */
".L80064B44:\n\t"
".word 0xAF28000C\n\t" /* 80064B44: sw         $t0, 0xC($t9) */
".word 0xAF290018\n\t" /* 80064B48: sw         $t1, 0x18($t9) */
".word 0xAF2A0024\n\t" /* 80064B4C: sw         $t2, 0x24($t9) */
".word 0xAF2B0030\n\t" /* 80064B50: sw         $t3, 0x30($t9) */
".word 0x000D6A00\n\t" /* 80064B54: sll        $t5, $t5, 8 */
".word 0x35AD000C\n\t" /* 80064B58: ori        $t5, $t5, 0xC */
".word 0x000D0A02\n\t" /* 80064B5C: srl        $at, $t5, 8 */
".word 0x000D6E00\n\t" /* 80064B60: sll        $t5, $t5, 24 */
".word 0x01A16825\n\t" /* 80064B64: or         $t5, $t5, $at */
".word 0xAF2D0000\n\t" /* 80064B68: sw         $t5, 0x0($t9) */
".word 0x00196A00\n\t" /* 80064B6C: sll        $t5, $t9, 8 */
".word 0x000D6A02\n\t" /* 80064B70: srl        $t5, $t5, 8 */
".word 0x10600019\n\t" /* 80064B74: beqz       $v1, .L80064BDC */
".word 0xAC4D0000\n\t" /* 80064B78: sw        $t5, 0x0($v0) */
".word 0x12400017\n\t" /* 80064B7C: beqz       $s2, .L80064BDC */
".word 0x00084400\n\t" /* 80064B80: sll       $t0, $t0, 16 */
".word 0x00084402\n\t" /* 80064B84: srl        $t0, $t0, 16 */
".word 0x01124025\n\t" /* 80064B88: or         $t0, $t0, $s2 */
".word 0x3C01FF9F\n\t" /* 80064B8C: lui        $at, (0xFF9FFFFF >> 16) */
".word 0x3421FFFF\n\t" /* 80064B90: ori        $at, $at, (0xFF9FFFFF & 0xFFFF) */
".word 0x01214824\n\t" /* 80064B94: and        $t1, $t1, $at */
".word 0x3C010040\n\t" /* 80064B98: lui        $at, (0x400000 >> 16) */
".word 0x01214825\n\t" /* 80064B9C: or         $t1, $t1, $at */
".word 0x8F230008\n\t" /* 80064BA0: lw         $v1, 0x8($t9) */
".word 0xAF2C0038\n\t" /* 80064BA4: sw         $t4, 0x38($t9) */
".word 0xAF23003C\n\t" /* 80064BA8: sw         $v1, 0x3C($t9) */
".word 0x8F230014\n\t" /* 80064BAC: lw         $v1, 0x14($t9) */
".word 0xAF2C0044\n\t" /* 80064BB0: sw         $t4, 0x44($t9) */
".word 0xAF230048\n\t" /* 80064BB4: sw         $v1, 0x48($t9) */
".word 0x8F230020\n\t" /* 80064BB8: lw         $v1, 0x20($t9) */
".word 0xAF2C0050\n\t" /* 80064BBC: sw         $t4, 0x50($t9) */
".word 0xAF230054\n\t" /* 80064BC0: sw         $v1, 0x54($t9) */
".word 0x8F23002C\n\t" /* 80064BC4: lw         $v1, 0x2C($t9) */
".word 0xAF2C005C\n\t" /* 80064BC8: sw         $t4, 0x5C($t9) */
".word 0xAF230060\n\t" /* 80064BCC: sw         $v1, 0x60($t9) */
".word 0x27390034\n\t" /* 80064BD0: addiu      $t9, $t9, 0x34 */
".word 0x080192D1\n\t" /* 80064BD4: j          .L80064B44 */
".word 0x24030000\n\t" /* 80064BD8: addiu     $v1, $zero, 0x0 */
".L80064BDC:\n\t"
".word 0x27390034\n\t" /* 80064BDC: addiu      $t9, $t9, 0x34 */
".L80064BE0:\n\t"
".word 0x2718FFFF\n\t" /* 80064BE0: addiu      $t8, $t8, -0x1 */
".word 0x1700FF54\n\t" /* 80064BE4: bnez       $t8, .L80064938 */
".word 0x24E7001C\n\t" /* 80064BE8: addiu     $a3, $a3, 0x1C */
".L80064BEC:\n\t"
".word 0x8C900020\n\t" /* 80064BEC: lw         $s0, 0x20($a0) */
".word 0x8C910024\n\t" /* 80064BF0: lw         $s1, 0x24($a0) */
".word 0x8C920028\n\t" /* 80064BF4: lw         $s2, 0x28($a0) */
".word 0x8C93002C\n\t" /* 80064BF8: lw         $s3, 0x2C($a0) */
".word 0x8C960030\n\t" /* 80064BFC: lw         $s6, 0x30($a0) */
".word 0x8C970034\n\t" /* 80064C00: lw         $s7, 0x34($a0) */
".word 0x8C820000\n\t" /* 80064C04: lw         $v0, 0x0($a0) */
".word 0x3C018010\n\t" /* 80064C08: lui        $at, %hi(D_800FE240) */
".word 0xAC39E240\n\t" /* 80064C0C: sw         $t9, %lo(D_800FE240)($at) */
".word 0x24420008\n\t" /* 80064C10: addiu      $v0, $v0, 0x8 */
".word 0x03E00008\n\t" /* 80064C14: jr         $ra */
".word 0x00000000\n\t" /* 80064C18: nop */
    ".set reorder\n"
);
