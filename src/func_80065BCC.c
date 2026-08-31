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
    ".global func_80065BCC\n"
    "func_80065BCC:\n"
".word 0x8C870000\n\t" /* 80065BCC: lw         $a3, 0x0($a0) */
".word 0x8C990010\n\t" /* 80065BD0: lw         $t9, 0x10($a0) */
".word 0x94F80002\n\t" /* 80065BD4: lhu        $t8, 0x2($a3) */
".word 0x8CE60004\n\t" /* 80065BD8: lw         $a2, 0x4($a3) */
".word 0x8C850014\n\t" /* 80065BDC: lw         $a1, 0x14($a0) */
".word 0x00063080\n\t" /* 80065BE0: sll        $a2, $a2, 2 */
".word 0xAC900020\n\t" /* 80065BE4: sw         $s0, 0x20($a0) */
".word 0xAC910024\n\t" /* 80065BE8: sw         $s1, 0x24($a0) */
".word 0xAC920028\n\t" /* 80065BEC: sw         $s2, 0x28($a0) */
".word 0xAC93002C\n\t" /* 80065BF0: sw         $s3, 0x2C($a0) */
".word 0xAC960030\n\t" /* 80065BF4: sw         $s6, 0x30($a0) */
".word 0xAC970034\n\t" /* 80065BF8: sw         $s7, 0x34($a0) */
".word 0x130000AA\n\t" /* 80065BFC: beqz       $t8, .L80065EA8 */
".word 0x00A63821\n\t" /* 80065C00: addu      $a3, $a1, $a2 */
".word 0x3C10800A\n\t" /* 80065C04: lui        $s0, %hi(D_8009AFB4) */
".word 0x8E10AFB4\n\t" /* 80065C08: lw         $s0, %lo(D_8009AFB4)($s0) */
".word 0x3C11800A\n\t" /* 80065C0C: lui        $s1, %hi(D_8009AFD8) */
".word 0x8E31AFD8\n\t" /* 80065C10: lw         $s1, %lo(D_8009AFD8)($s1) */
".word 0x3C12800A\n\t" /* 80065C14: lui        $s2, %hi(D_8009AFDC) */
".word 0x8E52AFDC\n\t" /* 80065C18: lw         $s2, %lo(D_8009AFDC)($s2) */
".word 0x3C16800A\n\t" /* 80065C1C: lui        $s6, %hi(D_8009AFE4) */
".word 0x82D6AFE4\n\t" /* 80065C20: lb         $s6, %lo(D_8009AFE4)($s6) */
".word 0x3C17800A\n\t" /* 80065C24: lui        $s7, %hi(D_8009AFE0) */
".word 0x8EF7AFE0\n\t" /* 80065C28: lw         $s7, %lo(D_8009AFE0)($s7) */
".word 0x02006021\n\t" /* 80065C2C: addu       $t4, $s0, $zero */
".word 0x3C02800A\n\t" /* 80065C30: lui        $v0, %hi(D_8009AFE5) */
".word 0x8042AFE5\n\t" /* 80065C34: lb         $v0, %lo(D_8009AFE5)($v0) */
".word 0x3C010200\n\t" /* 80065C38: lui        $at, (0x2000000 >> 16) */
".word 0x02018025\n\t" /* 80065C3C: or         $s0, $s0, $at */
".word 0x1440000E\n\t" /* 80065C40: bnez       $v0, .L80065C7C */
".word 0x02006021\n\t" /* 80065C44: addu      $t4, $s0, $zero */
".word 0x8CF10004\n\t" /* 80065C48: lw         $s1, 0x4($a3) */
".word 0x3C010060\n\t" /* 80065C4C: lui        $at, (0x600000 >> 16) */
".word 0x02218824\n\t" /* 80065C50: and        $s1, $s1, $at */
".word 0x16200009\n\t" /* 80065C54: bnez       $s1, .L80065C7C */
".word 0x00000000\n\t" /* 80065C58: nop */
".word 0x12400008\n\t" /* 80065C5C: beqz       $s2, .L80065C80 */
".word 0x00000000\n\t" /* 80065C60: nop */
".word 0x94F20002\n\t" /* 80065C64: lhu        $s2, 0x2($a3) */
".word 0x3C0C800A\n\t" /* 80065C68: lui        $t4, %hi(D_8009AFC4) */
".word 0x8D8CAFC4\n\t" /* 80065C6C: lw         $t4, %lo(D_8009AFC4)($t4) */
".word 0x00129400\n\t" /* 80065C70: sll        $s2, $s2, 16 */
".word 0x08019720\n\t" /* 80065C74: j          .L80065C80 */
".word 0x3C110020\n\t" /* 80065C78: lui       $s1, (0x200000 >> 16) */
".L80065C7C:\n\t"
".word 0x24120000\n\t" /* 80065C7C: addiu      $s2, $zero, 0x0 */
".L80065C80:\n\t"
".word 0x00109E02\n\t" /* 80065C80: srl        $s3, $s0, 24 */
".word 0x8C850018\n\t" /* 80065C84: lw         $a1, 0x18($a0) */
".word 0x8C86001C\n\t" /* 80065C88: lw         $a2, 0x1C($a0) */
".word 0x48903000\n\t" /* 80065C8C: mtc2       $s0, $6 ( handwritten instruction ) */
".word 0x8C8D0004\n\t" /* 80065C90: lw         $t5, 0x4($a0) */
".word 0x8C8E0008\n\t" /* 80065C94: lw         $t6, 0x8($a0) */
".word 0x8DAF0004\n\t" /* 80065C98: lw         $t7, 0x4($t5) */
".L80065C9C:\n\t"
".word 0x8CE8000C\n\t" /* 80065C9C: lw         $t0, 0xC($a3) */
".word 0x8CE90010\n\t" /* 80065CA0: lw         $t1, 0x10($a3) */
".word 0x8CEA0014\n\t" /* 80065CA4: lw         $t2, 0x14($a3) */
".word 0x00086C02\n\t" /* 80065CA8: srl        $t5, $t0, 16 */
".word 0x000D68C0\n\t" /* 80065CAC: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 80065CB0: addu       $t5, $t5, $a1 */
".word 0xC9A00000\n\t" /* 80065CB4: lwc2       $0, 0x0($t5) */
".word 0xC9A10004\n\t" /* 80065CB8: lwc2       $1, 0x4($t5) */
".word 0x00096C02\n\t" /* 80065CBC: srl        $t5, $t1, 16 */
".word 0x000D68C0\n\t" /* 80065CC0: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 80065CC4: addu       $t5, $t5, $a1 */
".word 0xC9A20000\n\t" /* 80065CC8: lwc2       $2, 0x0($t5) */
".word 0xC9A30004\n\t" /* 80065CCC: lwc2       $3, 0x4($t5) */
".word 0x000A6C02\n\t" /* 80065CD0: srl        $t5, $t2, 16 */
".word 0x000D68C0\n\t" /* 80065CD4: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 80065CD8: addu       $t5, $t5, $a1 */
".word 0xC9A40000\n\t" /* 80065CDC: lwc2       $4, 0x0($t5) */
".word 0xC9A50004\n\t" /* 80065CE0: lwc2       $5, 0x4($t5) */
".word 0x00084400\n\t" /* 80065CE4: sll        $t0, $t0, 16 */
".word 0x00084342\n\t" /* 80065CE8: srl        $t0, $t0, 13 */
".word 0x4A280030\n\t" /* 80065CEC: rtpt */
".word 0x00094C00\n\t" /* 80065CF0: sll        $t1, $t1, 16 */
".word 0x00094B42\n\t" /* 80065CF4: srl        $t1, $t1, 13 */
".word 0x000A5400\n\t" /* 80065CF8: sll        $t2, $t2, 16 */
".word 0x24010001\n\t" /* 80065CFC: addiu      $at, $zero, 0x1 */
".word 0x12C10005\n\t" /* 80065D00: beq        $s6, $at, .L80065D18 */
".word 0x000A5342\n\t" /* 80065D04: srl       $t2, $t2, 13 */
".word 0x4842F800\n\t" /* 80065D08: cfc2       $v0, $31 ( handwritten instruction ) */
".word 0x00000000\n\t" /* 80065D0C: nop */
".word 0x04400062\n\t" /* 80065D10: bltz       $v0, .L80065E9C */
".word 0x00000000\n\t" /* 80065D14: nop */
".L80065D18:\n\t"
".word 0x4B58002D\n\t" /* 80065D18: avsz3 */
".word 0x12C0001E\n\t" /* 80065D1C: beqz       $s6, .L80065D98 */
".word 0x01066821\n\t" /* 80065D20: addu      $t5, $t0, $a2 */
".word 0xC9A00000\n\t" /* 80065D24: lwc2       $0, 0x0($t5) */
".word 0xC9A10004\n\t" /* 80065D28: lwc2       $1, 0x4($t5) */
".word 0x01266821\n\t" /* 80065D2C: addu       $t5, $t1, $a2 */
".word 0xC9A20000\n\t" /* 80065D30: lwc2       $2, 0x0($t5) */
".word 0xC9A30004\n\t" /* 80065D34: lwc2       $3, 0x4($t5) */
".word 0x01466821\n\t" /* 80065D38: addu       $t5, $t2, $a2 */
".word 0xC9A40000\n\t" /* 80065D3C: lwc2       $4, 0x0($t5) */
".word 0xC9A50004\n\t" /* 80065D40: lwc2       $5, 0x4($t5) */
".word 0x00000000\n\t" /* 80065D44: nop */
".word 0x00000000\n\t" /* 80065D48: nop */
".word 0x4B18043F\n\t" /* 80065D4C: ncct */
".word 0x12E00009\n\t" /* 80065D50: beqz       $s7, .L80065D78 */
".word 0x00084042\n\t" /* 80065D54: srl       $t0, $t0, 1 */
".word 0x01174021\n\t" /* 80065D58: addu       $t0, $t0, $s7 */
".word 0x00094842\n\t" /* 80065D5C: srl        $t1, $t1, 1 */
".word 0x01374821\n\t" /* 80065D60: addu       $t1, $t1, $s7 */
".word 0x000A5042\n\t" /* 80065D64: srl        $t2, $t2, 1 */
".word 0x01575021\n\t" /* 80065D68: addu       $t2, $t2, $s7 */
".word 0xE9140000\n\t" /* 80065D6C: swc2       $20, 0x0($t0) */
".word 0xE9350000\n\t" /* 80065D70: swc2       $21, 0x0($t1) */
".word 0xE9560000\n\t" /* 80065D74: swc2       $22, 0x0($t2) */
".L80065D78:\n\t"
".word 0xEB340004\n\t" /* 80065D78: swc2       $20, 0x4($t9) */
".word 0xEB350010\n\t" /* 80065D7C: swc2       $21, 0x10($t9) */
".word 0xEB36001C\n\t" /* 80065D80: swc2       $22, 0x1C($t9) */
".word 0x24010001\n\t" /* 80065D84: addiu      $at, $zero, 0x1 */
".word 0x12C10044\n\t" /* 80065D88: beq        $s6, $at, .L80065E9C */
".word 0x00000000\n\t" /* 80065D8C: nop */
".word 0x08019773\n\t" /* 80065D90: j          .L80065DCC */
".word 0x00000000\n\t" /* 80065D94: nop */
".L80065D98:\n\t"
".word 0x00084042\n\t" /* 80065D98: srl        $t0, $t0, 1 */
".word 0x01171821\n\t" /* 80065D9C: addu       $v1, $t0, $s7 */
".word 0x8C680000\n\t" /* 80065DA0: lw         $t0, 0x0($v1) */
".word 0x00094842\n\t" /* 80065DA4: srl        $t1, $t1, 1 */
".word 0x01371821\n\t" /* 80065DA8: addu       $v1, $t1, $s7 */
".word 0x8C690000\n\t" /* 80065DAC: lw         $t1, 0x0($v1) */
".word 0x000A5042\n\t" /* 80065DB0: srl        $t2, $t2, 1 */
".word 0x01571821\n\t" /* 80065DB4: addu       $v1, $t2, $s7 */
".word 0x8C6A0000\n\t" /* 80065DB8: lw         $t2, 0x0($v1) */
".word 0xAF280004\n\t" /* 80065DBC: sw         $t0, 0x4($t9) */
".word 0xAF290010\n\t" /* 80065DC0: sw         $t1, 0x10($t9) */
".word 0xAF2A001C\n\t" /* 80065DC4: sw         $t2, 0x1C($t9) */
".word 0xA3330007\n\t" /* 80065DC8: sb         $s3, 0x7($t9) */
".L80065DCC:\n\t"
".word 0x8CE80000\n\t" /* 80065DCC: lw         $t0, 0x0($a3) */
".word 0x8CE90004\n\t" /* 80065DD0: lw         $t1, 0x4($a3) */
".word 0x8CEA0008\n\t" /* 80065DD4: lw         $t2, 0x8($a3) */
".word 0x48023800\n\t" /* 80065DD8: mfc2       $v0, $7 ( handwritten instruction ) */
".word 0x3C010200\n\t" /* 80065DDC: lui        $at, (0x2000000 >> 16) */
".word 0x02011824\n\t" /* 80065DE0: and        $v1, $s0, $at */
".word 0x3C01FF9F\n\t" /* 80065DE4: lui        $at, (0xFF9FFFFF >> 16) */
".word 0x3421FFFF\n\t" /* 80065DE8: ori        $at, $at, (0xFF9FFFFF & 0xFFFF) */
".word 0x01214824\n\t" /* 80065DEC: and        $t1, $t1, $at */
".word 0x01314825\n\t" /* 80065DF0: or         $t1, $t1, $s1 */
".word 0x01C21006\n\t" /* 80065DF4: srlv       $v0, $v0, $t6 */
".word 0x00021080\n\t" /* 80065DF8: sll        $v0, $v0, 2 */
".word 0x004F1021\n\t" /* 80065DFC: addu       $v0, $v0, $t7 */
".word 0x8C4D0000\n\t" /* 80065E00: lw         $t5, 0x0($v0) */
".word 0xEB2C0008\n\t" /* 80065E04: swc2       $12, 0x8($t9) */
".word 0xEB2D0014\n\t" /* 80065E08: swc2       $13, 0x14($t9) */
".word 0xEB2E0020\n\t" /* 80065E0C: swc2       $14, 0x20($t9) */
".L80065E10:\n\t"
".word 0xAF28000C\n\t" /* 80065E10: sw         $t0, 0xC($t9) */
".word 0xAF290018\n\t" /* 80065E14: sw         $t1, 0x18($t9) */
".word 0xAF2A0024\n\t" /* 80065E18: sw         $t2, 0x24($t9) */
".word 0x000D6A00\n\t" /* 80065E1C: sll        $t5, $t5, 8 */
".word 0x35AD0009\n\t" /* 80065E20: ori        $t5, $t5, 0x9 */
".word 0x000D0A02\n\t" /* 80065E24: srl        $at, $t5, 8 */
".word 0x000D6E00\n\t" /* 80065E28: sll        $t5, $t5, 24 */
".word 0x01A16825\n\t" /* 80065E2C: or         $t5, $t5, $at */
".word 0xAF2D0000\n\t" /* 80065E30: sw         $t5, 0x0($t9) */
".word 0x00196A00\n\t" /* 80065E34: sll        $t5, $t9, 8 */
".word 0x000D6A02\n\t" /* 80065E38: srl        $t5, $t5, 8 */
".word 0x10600016\n\t" /* 80065E3C: beqz       $v1, .L80065E98 */
".word 0xAC4D0000\n\t" /* 80065E40: sw        $t5, 0x0($v0) */
".word 0x12400014\n\t" /* 80065E44: beqz       $s2, .L80065E98 */
".word 0x00084400\n\t" /* 80065E48: sll       $t0, $t0, 16 */
".word 0x00084402\n\t" /* 80065E4C: srl        $t0, $t0, 16 */
".word 0x01124025\n\t" /* 80065E50: or         $t0, $t0, $s2 */
".word 0x3C01FF9F\n\t" /* 80065E54: lui        $at, (0xFF9FFFFF >> 16) */
".word 0x3421FFFF\n\t" /* 80065E58: ori        $at, $at, (0xFF9FFFFF & 0xFFFF) */
".word 0x01214824\n\t" /* 80065E5C: and        $t1, $t1, $at */
".word 0x3C010040\n\t" /* 80065E60: lui        $at, (0x400000 >> 16) */
".word 0x01214825\n\t" /* 80065E64: or         $t1, $t1, $at */
".word 0x8F230008\n\t" /* 80065E68: lw         $v1, 0x8($t9) */
".word 0xAF2C002C\n\t" /* 80065E6C: sw         $t4, 0x2C($t9) */
".word 0xAF230030\n\t" /* 80065E70: sw         $v1, 0x30($t9) */
".word 0x8F230014\n\t" /* 80065E74: lw         $v1, 0x14($t9) */
".word 0xAF2C0038\n\t" /* 80065E78: sw         $t4, 0x38($t9) */
".word 0xAF23003C\n\t" /* 80065E7C: sw         $v1, 0x3C($t9) */
".word 0x8F230020\n\t" /* 80065E80: lw         $v1, 0x20($t9) */
".word 0xAF2C0044\n\t" /* 80065E84: sw         $t4, 0x44($t9) */
".word 0xAF230048\n\t" /* 80065E88: sw         $v1, 0x48($t9) */
".word 0x27390028\n\t" /* 80065E8C: addiu      $t9, $t9, 0x28 */
".word 0x08019784\n\t" /* 80065E90: j          .L80065E10 */
".word 0x24030000\n\t" /* 80065E94: addiu     $v1, $zero, 0x0 */
".L80065E98:\n\t"
".word 0x27390028\n\t" /* 80065E98: addiu      $t9, $t9, 0x28 */
".L80065E9C:\n\t"
".word 0x2718FFFF\n\t" /* 80065E9C: addiu      $t8, $t8, -0x1 */
".word 0x1700FF7E\n\t" /* 80065EA0: bnez       $t8, .L80065C9C */
".word 0x24E70018\n\t" /* 80065EA4: addiu     $a3, $a3, 0x18 */
".L80065EA8:\n\t"
".word 0x8C900020\n\t" /* 80065EA8: lw         $s0, 0x20($a0) */
".word 0x8C910024\n\t" /* 80065EAC: lw         $s1, 0x24($a0) */
".word 0x8C920028\n\t" /* 80065EB0: lw         $s2, 0x28($a0) */
".word 0x8C93002C\n\t" /* 80065EB4: lw         $s3, 0x2C($a0) */
".word 0x8C960030\n\t" /* 80065EB8: lw         $s6, 0x30($a0) */
".word 0x8C970034\n\t" /* 80065EBC: lw         $s7, 0x34($a0) */
".word 0x8C820000\n\t" /* 80065EC0: lw         $v0, 0x0($a0) */
".word 0x3C018010\n\t" /* 80065EC4: lui        $at, %hi(D_800FE240) */
".word 0xAC39E240\n\t" /* 80065EC8: sw         $t9, %lo(D_800FE240)($at) */
".word 0x24420008\n\t" /* 80065ECC: addiu      $v0, $v0, 0x8 */
".word 0x03E00008\n\t" /* 80065ED0: jr         $ra */
".word 0x00000000\n\t" /* 80065ED4: nop */
    ".set reorder\n"
);
