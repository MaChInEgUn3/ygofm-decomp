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
    ".global func_80064EF4\n"
    "func_80064EF4:\n"
".word 0x8C870000\n\t" /* 80064EF4: lw         $a3, 0x0($a0) */
".word 0x8C990010\n\t" /* 80064EF8: lw         $t9, 0x10($a0) */
".word 0x94F80002\n\t" /* 80064EFC: lhu        $t8, 0x2($a3) */
".word 0x8CE60004\n\t" /* 80064F00: lw         $a2, 0x4($a3) */
".word 0x8C850014\n\t" /* 80064F04: lw         $a1, 0x14($a0) */
".word 0x00063080\n\t" /* 80064F08: sll        $a2, $a2, 2 */
".word 0xAC900020\n\t" /* 80064F0C: sw         $s0, 0x20($a0) */
".word 0xAC910024\n\t" /* 80064F10: sw         $s1, 0x24($a0) */
".word 0xAC920028\n\t" /* 80064F14: sw         $s2, 0x28($a0) */
".word 0xAC93002C\n\t" /* 80064F18: sw         $s3, 0x2C($a0) */
".word 0xAC940030\n\t" /* 80064F1C: sw         $s4, 0x30($a0) */
".word 0xAC950034\n\t" /* 80064F20: sw         $s5, 0x34($a0) */
".word 0xAC960038\n\t" /* 80064F24: sw         $s6, 0x38($a0) */
".word 0xAC97003C\n\t" /* 80064F28: sw         $s7, 0x3C($a0) */
".word 0x130000B3\n\t" /* 80064F2C: beqz       $t8, .L800651FC */
".word 0x00A63821\n\t" /* 80064F30: addu      $a3, $a1, $a2 */
".word 0x3C10800A\n\t" /* 80064F34: lui        $s0, %hi(D_8009AFB4) */
".word 0x8E10AFB4\n\t" /* 80064F38: lw         $s0, %lo(D_8009AFB4)($s0) */
".word 0x3C11800A\n\t" /* 80064F3C: lui        $s1, %hi(D_8009AFD8) */
".word 0x8E31AFD8\n\t" /* 80064F40: lw         $s1, %lo(D_8009AFD8)($s1) */
".word 0x3C12800A\n\t" /* 80064F44: lui        $s2, %hi(D_8009AFDC) */
".word 0x8E52AFDC\n\t" /* 80064F48: lw         $s2, %lo(D_8009AFDC)($s2) */
".word 0x3C16800A\n\t" /* 80064F4C: lui        $s6, %hi(D_8009AFE4) */
".word 0x82D6AFE4\n\t" /* 80064F50: lb         $s6, %lo(D_8009AFE4)($s6) */
".word 0x3C17800A\n\t" /* 80064F54: lui        $s7, %hi(D_8009AFE0) */
".word 0x8EF7AFE0\n\t" /* 80064F58: lw         $s7, %lo(D_8009AFE0)($s7) */
".word 0x02006021\n\t" /* 80064F5C: addu       $t4, $s0, $zero */
".word 0x3C02800A\n\t" /* 80064F60: lui        $v0, %hi(D_8009AFE5) */
".word 0x8042AFE5\n\t" /* 80064F64: lb         $v0, %lo(D_8009AFE5)($v0) */
".word 0x3C010200\n\t" /* 80064F68: lui        $at, (0x2000000 >> 16) */
".word 0x02018025\n\t" /* 80064F6C: or         $s0, $s0, $at */
".word 0x1440000E\n\t" /* 80064F70: bnez       $v0, .L80064FAC */
".word 0x02006021\n\t" /* 80064F74: addu      $t4, $s0, $zero */
".word 0x8CF10008\n\t" /* 80064F78: lw         $s1, 0x8($a3) */
".word 0x3C010060\n\t" /* 80064F7C: lui        $at, (0x600000 >> 16) */
".word 0x02218824\n\t" /* 80064F80: and        $s1, $s1, $at */
".word 0x16200009\n\t" /* 80064F84: bnez       $s1, .L80064FAC */
".word 0x00000000\n\t" /* 80064F88: nop */
".word 0x12400008\n\t" /* 80064F8C: beqz       $s2, .L80064FB0 */
".word 0x00000000\n\t" /* 80064F90: nop */
".word 0x94F20006\n\t" /* 80064F94: lhu        $s2, 0x6($a3) */
".word 0x3C0C800A\n\t" /* 80064F98: lui        $t4, %hi(D_8009AFC4) */
".word 0x8D8CAFC4\n\t" /* 80064F9C: lw         $t4, %lo(D_8009AFC4)($t4) */
".word 0x00129400\n\t" /* 80064FA0: sll        $s2, $s2, 16 */
".word 0x080193EC\n\t" /* 80064FA4: j          .L80064FB0 */
".word 0x3C110020\n\t" /* 80064FA8: lui       $s1, (0x200000 >> 16) */
".L80064FAC:\n\t"
".word 0x24120000\n\t" /* 80064FAC: addiu      $s2, $zero, 0x0 */
".L80064FB0:\n\t"
".word 0x00109E02\n\t" /* 80064FB0: srl        $s3, $s0, 24 */
".word 0x3C14E200\n\t" /* 80064FB4: lui        $s4, (0xE2000000 >> 16) */
".word 0x8C850018\n\t" /* 80064FB8: lw         $a1, 0x18($a0) */
".word 0x8C86001C\n\t" /* 80064FBC: lw         $a2, 0x1C($a0) */
".word 0x48903000\n\t" /* 80064FC0: mtc2       $s0, $6 ( handwritten instruction ) */
".word 0x8C8D0004\n\t" /* 80064FC4: lw         $t5, 0x4($a0) */
".word 0x8C8E0008\n\t" /* 80064FC8: lw         $t6, 0x8($a0) */
".word 0x8DAF0004\n\t" /* 80064FCC: lw         $t7, 0x4($t5) */
".L80064FD0:\n\t"
".word 0x8CE80010\n\t" /* 80064FD0: lw         $t0, 0x10($a3) */
".word 0x8CE90014\n\t" /* 80064FD4: lw         $t1, 0x14($a3) */
".word 0x8CEA0018\n\t" /* 80064FD8: lw         $t2, 0x18($a3) */
".word 0x00086C02\n\t" /* 80064FDC: srl        $t5, $t0, 16 */
".word 0x000D68C0\n\t" /* 80064FE0: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 80064FE4: addu       $t5, $t5, $a1 */
".word 0xC9A00000\n\t" /* 80064FE8: lwc2       $0, 0x0($t5) */
".word 0xC9A10004\n\t" /* 80064FEC: lwc2       $1, 0x4($t5) */
".word 0x00096C02\n\t" /* 80064FF0: srl        $t5, $t1, 16 */
".word 0x000D68C0\n\t" /* 80064FF4: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 80064FF8: addu       $t5, $t5, $a1 */
".word 0xC9A20000\n\t" /* 80064FFC: lwc2       $2, 0x0($t5) */
".word 0xC9A30004\n\t" /* 80065000: lwc2       $3, 0x4($t5) */
".word 0x000A6C02\n\t" /* 80065004: srl        $t5, $t2, 16 */
".word 0x000D68C0\n\t" /* 80065008: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 8006500C: addu       $t5, $t5, $a1 */
".word 0xC9A40000\n\t" /* 80065010: lwc2       $4, 0x0($t5) */
".word 0xC9A50004\n\t" /* 80065014: lwc2       $5, 0x4($t5) */
".word 0x00084400\n\t" /* 80065018: sll        $t0, $t0, 16 */
".word 0x00084342\n\t" /* 8006501C: srl        $t0, $t0, 13 */
".word 0x4A280030\n\t" /* 80065020: rtpt */
".word 0x00094C00\n\t" /* 80065024: sll        $t1, $t1, 16 */
".word 0x00094B42\n\t" /* 80065028: srl        $t1, $t1, 13 */
".word 0x000A5400\n\t" /* 8006502C: sll        $t2, $t2, 16 */
".word 0x24010001\n\t" /* 80065030: addiu      $at, $zero, 0x1 */
".word 0x12C1000A\n\t" /* 80065034: beq        $s6, $at, .L80065060 */
".word 0x000A5342\n\t" /* 80065038: srl       $t2, $t2, 13 */
".word 0x4842F800\n\t" /* 8006503C: cfc2       $v0, $31 ( handwritten instruction ) */
".word 0x00000000\n\t" /* 80065040: nop */
".word 0x0440006A\n\t" /* 80065044: bltz       $v0, .L800651F0 */
".word 0x00000000\n\t" /* 80065048: nop */
".word 0x4B400006\n\t" /* 8006504C: nclip */
".word 0x4802C000\n\t" /* 80065050: mfc2       $v0, $24 ( handwritten instruction ) */
".word 0x00000000\n\t" /* 80065054: nop */
".word 0x18400065\n\t" /* 80065058: blez       $v0, .L800651F0 */
".word 0x00000000\n\t" /* 8006505C: nop */
".L80065060:\n\t"
".word 0x4B58002D\n\t" /* 80065060: avsz3 */
".word 0x8CF50000\n\t" /* 80065064: lw         $s5, 0x0($a3) */
".word 0x12C0001E\n\t" /* 80065068: beqz       $s6, .L800650E4 */
".word 0x01066821\n\t" /* 8006506C: addu      $t5, $t0, $a2 */
".word 0xC9A00000\n\t" /* 80065070: lwc2       $0, 0x0($t5) */
".word 0xC9A10004\n\t" /* 80065074: lwc2       $1, 0x4($t5) */
".word 0x01266821\n\t" /* 80065078: addu       $t5, $t1, $a2 */
".word 0xC9A20000\n\t" /* 8006507C: lwc2       $2, 0x0($t5) */
".word 0xC9A30004\n\t" /* 80065080: lwc2       $3, 0x4($t5) */
".word 0x01466821\n\t" /* 80065084: addu       $t5, $t2, $a2 */
".word 0xC9A40000\n\t" /* 80065088: lwc2       $4, 0x0($t5) */
".word 0xC9A50004\n\t" /* 8006508C: lwc2       $5, 0x4($t5) */
".word 0x00000000\n\t" /* 80065090: nop */
".word 0x00000000\n\t" /* 80065094: nop */
".word 0x4B18043F\n\t" /* 80065098: ncct */
".word 0x12E00009\n\t" /* 8006509C: beqz       $s7, .L800650C4 */
".word 0x00084042\n\t" /* 800650A0: srl       $t0, $t0, 1 */
".word 0x01174021\n\t" /* 800650A4: addu       $t0, $t0, $s7 */
".word 0x00094842\n\t" /* 800650A8: srl        $t1, $t1, 1 */
".word 0x01374821\n\t" /* 800650AC: addu       $t1, $t1, $s7 */
".word 0x000A5042\n\t" /* 800650B0: srl        $t2, $t2, 1 */
".word 0x01575021\n\t" /* 800650B4: addu       $t2, $t2, $s7 */
".word 0xE9140000\n\t" /* 800650B8: swc2       $20, 0x0($t0) */
".word 0xE9350000\n\t" /* 800650BC: swc2       $21, 0x0($t1) */
".word 0xE9560000\n\t" /* 800650C0: swc2       $22, 0x0($t2) */
".L800650C4:\n\t"
".word 0xEB340008\n\t" /* 800650C4: swc2       $20, 0x8($t9) */
".word 0xEB350014\n\t" /* 800650C8: swc2       $21, 0x14($t9) */
".word 0xEB360020\n\t" /* 800650CC: swc2       $22, 0x20($t9) */
".word 0x24010001\n\t" /* 800650D0: addiu      $at, $zero, 0x1 */
".word 0x12C10046\n\t" /* 800650D4: beq        $s6, $at, .L800651F0 */
".word 0x00000000\n\t" /* 800650D8: nop */
".word 0x08019446\n\t" /* 800650DC: j          .L80065118 */
".word 0x00000000\n\t" /* 800650E0: nop */
".L800650E4:\n\t"
".word 0x00084042\n\t" /* 800650E4: srl        $t0, $t0, 1 */
".word 0x01171821\n\t" /* 800650E8: addu       $v1, $t0, $s7 */
".word 0x8C680000\n\t" /* 800650EC: lw         $t0, 0x0($v1) */
".word 0x00094842\n\t" /* 800650F0: srl        $t1, $t1, 1 */
".word 0x01371821\n\t" /* 800650F4: addu       $v1, $t1, $s7 */
".word 0x8C690000\n\t" /* 800650F8: lw         $t1, 0x0($v1) */
".word 0x000A5042\n\t" /* 800650FC: srl        $t2, $t2, 1 */
".word 0x01571821\n\t" /* 80065100: addu       $v1, $t2, $s7 */
".word 0x8C6A0000\n\t" /* 80065104: lw         $t2, 0x0($v1) */
".word 0xAF280008\n\t" /* 80065108: sw         $t0, 0x8($t9) */
".word 0xAF290014\n\t" /* 8006510C: sw         $t1, 0x14($t9) */
".word 0xAF2A0020\n\t" /* 80065110: sw         $t2, 0x20($t9) */
".word 0xA333000B\n\t" /* 80065114: sb         $s3, 0xB($t9) */
".L80065118:\n\t"
".word 0x8CE80004\n\t" /* 80065118: lw         $t0, 0x4($a3) */
".word 0x8CE90008\n\t" /* 8006511C: lw         $t1, 0x8($a3) */
".word 0x8CEA000C\n\t" /* 80065120: lw         $t2, 0xC($a3) */
".word 0x48023800\n\t" /* 80065124: mfc2       $v0, $7 ( handwritten instruction ) */
".word 0x3C010200\n\t" /* 80065128: lui        $at, (0x2000000 >> 16) */
".word 0x02011824\n\t" /* 8006512C: and        $v1, $s0, $at */
".word 0x3C01FF9F\n\t" /* 80065130: lui        $at, (0xFF9FFFFF >> 16) */
".word 0x3421FFFF\n\t" /* 80065134: ori        $at, $at, (0xFF9FFFFF & 0xFFFF) */
".word 0x01214824\n\t" /* 80065138: and        $t1, $t1, $at */
".word 0x01314825\n\t" /* 8006513C: or         $t1, $t1, $s1 */
".word 0x01C21006\n\t" /* 80065140: srlv       $v0, $v0, $t6 */
".word 0x00021080\n\t" /* 80065144: sll        $v0, $v0, 2 */
".word 0x004F1021\n\t" /* 80065148: addu       $v0, $v0, $t7 */
".word 0x8C4D0000\n\t" /* 8006514C: lw         $t5, 0x0($v0) */
".word 0xEB2C000C\n\t" /* 80065150: swc2       $12, 0xC($t9) */
".word 0xEB2D0018\n\t" /* 80065154: swc2       $13, 0x18($t9) */
".word 0xEB2E0024\n\t" /* 80065158: swc2       $14, 0x24($t9) */
".L8006515C:\n\t"
".word 0xAF280010\n\t" /* 8006515C: sw         $t0, 0x10($t9) */
".word 0xAF29001C\n\t" /* 80065160: sw         $t1, 0x1C($t9) */
".word 0xAF2A0028\n\t" /* 80065164: sw         $t2, 0x28($t9) */
".word 0xAF350004\n\t" /* 80065168: sw         $s5, 0x4($t9) */
".word 0xAF34002C\n\t" /* 8006516C: sw         $s4, 0x2C($t9) */
".word 0x000D6A00\n\t" /* 80065170: sll        $t5, $t5, 8 */
".word 0x35AD000B\n\t" /* 80065174: ori        $t5, $t5, 0xB */
".word 0x000D0A02\n\t" /* 80065178: srl        $at, $t5, 8 */
".word 0x000D6E00\n\t" /* 8006517C: sll        $t5, $t5, 24 */
".word 0x01A16825\n\t" /* 80065180: or         $t5, $t5, $at */
".word 0xAF2D0000\n\t" /* 80065184: sw         $t5, 0x0($t9) */
".word 0x00196A00\n\t" /* 80065188: sll        $t5, $t9, 8 */
".word 0x000D6A02\n\t" /* 8006518C: srl        $t5, $t5, 8 */
".word 0x10600016\n\t" /* 80065190: beqz       $v1, .L800651EC */
".word 0xAC4D0000\n\t" /* 80065194: sw        $t5, 0x0($v0) */
".word 0x12400014\n\t" /* 80065198: beqz       $s2, .L800651EC */
".word 0x00084400\n\t" /* 8006519C: sll       $t0, $t0, 16 */
".word 0x00084402\n\t" /* 800651A0: srl        $t0, $t0, 16 */
".word 0x01124025\n\t" /* 800651A4: or         $t0, $t0, $s2 */
".word 0x3C01FF9F\n\t" /* 800651A8: lui        $at, (0xFF9FFFFF >> 16) */
".word 0x3421FFFF\n\t" /* 800651AC: ori        $at, $at, (0xFF9FFFFF & 0xFFFF) */
".word 0x01214824\n\t" /* 800651B0: and        $t1, $t1, $at */
".word 0x3C010040\n\t" /* 800651B4: lui        $at, (0x400000 >> 16) */
".word 0x01214825\n\t" /* 800651B8: or         $t1, $t1, $at */
".word 0x8F23000C\n\t" /* 800651BC: lw         $v1, 0xC($t9) */
".word 0xAF2C0038\n\t" /* 800651C0: sw         $t4, 0x38($t9) */
".word 0xAF23003C\n\t" /* 800651C4: sw         $v1, 0x3C($t9) */
".word 0x8F230018\n\t" /* 800651C8: lw         $v1, 0x18($t9) */
".word 0xAF2C0044\n\t" /* 800651CC: sw         $t4, 0x44($t9) */
".word 0xAF230048\n\t" /* 800651D0: sw         $v1, 0x48($t9) */
".word 0x8F230024\n\t" /* 800651D4: lw         $v1, 0x24($t9) */
".word 0xAF2C0050\n\t" /* 800651D8: sw         $t4, 0x50($t9) */
".word 0xAF230054\n\t" /* 800651DC: sw         $v1, 0x54($t9) */
".word 0x27390030\n\t" /* 800651E0: addiu      $t9, $t9, 0x30 */
".word 0x08019457\n\t" /* 800651E4: j          .L8006515C */
".word 0x24030000\n\t" /* 800651E8: addiu     $v1, $zero, 0x0 */
".L800651EC:\n\t"
".word 0x27390030\n\t" /* 800651EC: addiu      $t9, $t9, 0x30 */
".L800651F0:\n\t"
".word 0x2718FFFF\n\t" /* 800651F0: addiu      $t8, $t8, -0x1 */
".word 0x1700FF76\n\t" /* 800651F4: bnez       $t8, .L80064FD0 */
".word 0x24E7001C\n\t" /* 800651F8: addiu     $a3, $a3, 0x1C */
".L800651FC:\n\t"
".word 0x8C900020\n\t" /* 800651FC: lw         $s0, 0x20($a0) */
".word 0x8C910024\n\t" /* 80065200: lw         $s1, 0x24($a0) */
".word 0x8C920028\n\t" /* 80065204: lw         $s2, 0x28($a0) */
".word 0x8C93002C\n\t" /* 80065208: lw         $s3, 0x2C($a0) */
".word 0x8C940030\n\t" /* 8006520C: lw         $s4, 0x30($a0) */
".word 0x8C950034\n\t" /* 80065210: lw         $s5, 0x34($a0) */
".word 0x8C960038\n\t" /* 80065214: lw         $s6, 0x38($a0) */
".word 0x8C97003C\n\t" /* 80065218: lw         $s7, 0x3C($a0) */
".word 0x8C820000\n\t" /* 8006521C: lw         $v0, 0x0($a0) */
".word 0x3C018010\n\t" /* 80065220: lui        $at, %hi(D_800FE240) */
".word 0xAC39E240\n\t" /* 80065224: sw         $t9, %lo(D_800FE240)($at) */
".word 0x24420008\n\t" /* 80065228: addiu      $v0, $v0, 0x8 */
".word 0x03E00008\n\t" /* 8006522C: jr         $ra */
".word 0x00000000\n\t" /* 80065230: nop */
    ".set reorder\n"
);
