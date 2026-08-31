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
    ".global func_80065ED8\n"
    "func_80065ED8:\n"
".word 0x8C870000\n\t" /* 80065ED8: lw         $a3, 0x0($a0) */
".word 0x8C990010\n\t" /* 80065EDC: lw         $t9, 0x10($a0) */
".word 0x94F80002\n\t" /* 80065EE0: lhu        $t8, 0x2($a3) */
".word 0x8CE60004\n\t" /* 80065EE4: lw         $a2, 0x4($a3) */
".word 0x8C850014\n\t" /* 80065EE8: lw         $a1, 0x14($a0) */
".word 0x00063080\n\t" /* 80065EEC: sll        $a2, $a2, 2 */
".word 0xAC900020\n\t" /* 80065EF0: sw         $s0, 0x20($a0) */
".word 0xAC910024\n\t" /* 80065EF4: sw         $s1, 0x24($a0) */
".word 0xAC920028\n\t" /* 80065EF8: sw         $s2, 0x28($a0) */
".word 0xAC93002C\n\t" /* 80065EFC: sw         $s3, 0x2C($a0) */
".word 0xAC960030\n\t" /* 80065F00: sw         $s6, 0x30($a0) */
".word 0xAC970034\n\t" /* 80065F04: sw         $s7, 0x34($a0) */
".word 0x130000A2\n\t" /* 80065F08: beqz       $t8, .L80066194 */
".word 0x00A63821\n\t" /* 80065F0C: addu      $a3, $a1, $a2 */
".word 0x3C10800A\n\t" /* 80065F10: lui        $s0, %hi(D_8009AFB0) */
".word 0x8E10AFB0\n\t" /* 80065F14: lw         $s0, %lo(D_8009AFB0)($s0) */
".word 0x3C11800A\n\t" /* 80065F18: lui        $s1, %hi(D_8009AFD8) */
".word 0x8E31AFD8\n\t" /* 80065F1C: lw         $s1, %lo(D_8009AFD8)($s1) */
".word 0x3C12800A\n\t" /* 80065F20: lui        $s2, %hi(D_8009AFDC) */
".word 0x8E52AFDC\n\t" /* 80065F24: lw         $s2, %lo(D_8009AFDC)($s2) */
".word 0x3C16800A\n\t" /* 80065F28: lui        $s6, %hi(D_8009AFE4) */
".word 0x82D6AFE4\n\t" /* 80065F2C: lb         $s6, %lo(D_8009AFE4)($s6) */
".word 0x3C17800A\n\t" /* 80065F30: lui        $s7, %hi(D_8009AFE0) */
".word 0x8EF7AFE0\n\t" /* 80065F34: lw         $s7, %lo(D_8009AFE0)($s7) */
".word 0x02006021\n\t" /* 80065F38: addu       $t4, $s0, $zero */
".word 0x3C02800A\n\t" /* 80065F3C: lui        $v0, %hi(D_8009AFE5) */
".word 0x8042AFE5\n\t" /* 80065F40: lb         $v0, %lo(D_8009AFE5)($v0) */
".word 0x3C010200\n\t" /* 80065F44: lui        $at, (0x2000000 >> 16) */
".word 0x02018025\n\t" /* 80065F48: or         $s0, $s0, $at */
".word 0x1440000E\n\t" /* 80065F4C: bnez       $v0, .L80065F88 */
".word 0x02006021\n\t" /* 80065F50: addu      $t4, $s0, $zero */
".word 0x8CF10004\n\t" /* 80065F54: lw         $s1, 0x4($a3) */
".word 0x3C010060\n\t" /* 80065F58: lui        $at, (0x600000 >> 16) */
".word 0x02218824\n\t" /* 80065F5C: and        $s1, $s1, $at */
".word 0x16200009\n\t" /* 80065F60: bnez       $s1, .L80065F88 */
".word 0x00000000\n\t" /* 80065F64: nop */
".word 0x12400008\n\t" /* 80065F68: beqz       $s2, .L80065F8C */
".word 0x00000000\n\t" /* 80065F6C: nop */
".word 0x94F20002\n\t" /* 80065F70: lhu        $s2, 0x2($a3) */
".word 0x3C0C800A\n\t" /* 80065F74: lui        $t4, %hi(D_8009AFC0) */
".word 0x8D8CAFC0\n\t" /* 80065F78: lw         $t4, %lo(D_8009AFC0)($t4) */
".word 0x00129400\n\t" /* 80065F7C: sll        $s2, $s2, 16 */
".word 0x080197E3\n\t" /* 80065F80: j          .L80065F8C */
".word 0x3C110020\n\t" /* 80065F84: lui       $s1, (0x200000 >> 16) */
".L80065F88:\n\t"
".word 0x24120000\n\t" /* 80065F88: addiu      $s2, $zero, 0x0 */
".L80065F8C:\n\t"
".word 0x00109E02\n\t" /* 80065F8C: srl        $s3, $s0, 24 */
".word 0x8C850018\n\t" /* 80065F90: lw         $a1, 0x18($a0) */
".word 0x8C86001C\n\t" /* 80065F94: lw         $a2, 0x1C($a0) */
".word 0x48903000\n\t" /* 80065F98: mtc2       $s0, $6 ( handwritten instruction ) */
".word 0x8C8D0004\n\t" /* 80065F9C: lw         $t5, 0x4($a0) */
".word 0x8C8E0008\n\t" /* 80065FA0: lw         $t6, 0x8($a0) */
".word 0x8DAF0004\n\t" /* 80065FA4: lw         $t7, 0x4($t5) */
".L80065FA8:\n\t"
".word 0x8CE80010\n\t" /* 80065FA8: lw         $t0, 0x10($a3) */
".word 0x8CE90014\n\t" /* 80065FAC: lw         $t1, 0x14($a3) */
".word 0x00086C00\n\t" /* 80065FB0: sll        $t5, $t0, 16 */
".word 0x000D6B42\n\t" /* 80065FB4: srl        $t5, $t5, 13 */
".word 0x01A56821\n\t" /* 80065FB8: addu       $t5, $t5, $a1 */
".word 0xC9A00000\n\t" /* 80065FBC: lwc2       $0, 0x0($t5) */
".word 0xC9A10004\n\t" /* 80065FC0: lwc2       $1, 0x4($t5) */
".word 0x00086C02\n\t" /* 80065FC4: srl        $t5, $t0, 16 */
".word 0x000D68C0\n\t" /* 80065FC8: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 80065FCC: addu       $t5, $t5, $a1 */
".word 0xC9A20000\n\t" /* 80065FD0: lwc2       $2, 0x0($t5) */
".word 0xC9A30004\n\t" /* 80065FD4: lwc2       $3, 0x4($t5) */
".word 0x00096C00\n\t" /* 80065FD8: sll        $t5, $t1, 16 */
".word 0x000D6B42\n\t" /* 80065FDC: srl        $t5, $t5, 13 */
".word 0x01A56821\n\t" /* 80065FE0: addu       $t5, $t5, $a1 */
".word 0xC9A40000\n\t" /* 80065FE4: lwc2       $4, 0x0($t5) */
".word 0xC9A50004\n\t" /* 80065FE8: lwc2       $5, 0x4($t5) */
".word 0x00095C02\n\t" /* 80065FEC: srl        $t3, $t1, 16 */
".word 0x000B58C0\n\t" /* 80065FF0: sll        $t3, $t3, 3 */
".word 0x4A280030\n\t" /* 80065FF4: rtpt */
".word 0x24010001\n\t" /* 80065FF8: addiu      $at, $zero, 0x1 */
".word 0x12C10005\n\t" /* 80065FFC: beq        $s6, $at, .L80066014 */
".word 0x01656821\n\t" /* 80066000: addu      $t5, $t3, $a1 */
".word 0x4842F800\n\t" /* 80066004: cfc2       $v0, $31 ( handwritten instruction ) */
".word 0x00000000\n\t" /* 80066008: nop */
".word 0x0440005E\n\t" /* 8006600C: bltz       $v0, .L80066188 */
".word 0x00000000\n\t" /* 80066010: nop */
".L80066014:\n\t"
".word 0xC9A00000\n\t" /* 80066014: lwc2       $0, 0x0($t5) */
".word 0xC9A10004\n\t" /* 80066018: lwc2       $1, 0x4($t5) */
".word 0xEB2C0008\n\t" /* 8006601C: swc2       $12, 0x8($t9) */
".word 0xEB2D0010\n\t" /* 80066020: swc2       $13, 0x10($t9) */
".word 0xEB2E0018\n\t" /* 80066024: swc2       $14, 0x18($t9) */
".word 0x00000000\n\t" /* 80066028: nop */
".word 0x00000000\n\t" /* 8006602C: nop */
".word 0x4A180001\n\t" /* 80066030: rtps */
".word 0x94E8000E\n\t" /* 80066034: lhu        $t0, 0xE($a3) */
".word 0x24010001\n\t" /* 80066038: addiu      $at, $zero, 0x1 */
".word 0x12C10005\n\t" /* 8006603C: beq        $s6, $at, .L80066054 */
".word 0x000840C0\n\t" /* 80066040: sll       $t0, $t0, 3 */
".word 0x4842F800\n\t" /* 80066044: cfc2       $v0, $31 ( handwritten instruction ) */
".word 0x00000000\n\t" /* 80066048: nop */
".word 0x0440004E\n\t" /* 8006604C: bltz       $v0, .L80066188 */
".word 0x00000000\n\t" /* 80066050: nop */
".L80066054:\n\t"
".word 0x4B68002E\n\t" /* 80066054: avsz4 */
".word 0x12C00010\n\t" /* 80066058: beqz       $s6, .L8006609C */
".word 0x01066821\n\t" /* 8006605C: addu      $t5, $t0, $a2 */
".word 0xC9A00000\n\t" /* 80066060: lwc2       $0, 0x0($t5) */
".word 0xC9A10004\n\t" /* 80066064: lwc2       $1, 0x4($t5) */
".word 0x00000000\n\t" /* 80066068: nop */
".word 0x00000000\n\t" /* 8006606C: nop */
".word 0x4B08041B\n\t" /* 80066070: nccs */
".word 0x12E00003\n\t" /* 80066074: beqz       $s7, .L80066084 */
".word 0x00084042\n\t" /* 80066078: srl       $t0, $t0, 1 */
".word 0x01174021\n\t" /* 8006607C: addu       $t0, $t0, $s7 */
".word 0xE9160000\n\t" /* 80066080: swc2       $22, 0x0($t0) */
".L80066084:\n\t"
".word 0xEB360004\n\t" /* 80066084: swc2       $22, 0x4($t9) */
".word 0x24010001\n\t" /* 80066088: addiu      $at, $zero, 0x1 */
".word 0x12C1003E\n\t" /* 8006608C: beq        $s6, $at, .L80066188 */
".word 0x00000000\n\t" /* 80066090: nop */
".word 0x0801982D\n\t" /* 80066094: j          .L800660B4 */
".word 0x00000000\n\t" /* 80066098: nop */
".L8006609C:\n\t"
".word 0x00084042\n\t" /* 8006609C: srl        $t0, $t0, 1 */
".word 0x01171821\n\t" /* 800660A0: addu       $v1, $t0, $s7 */
".word 0x8C680000\n\t" /* 800660A4: lw         $t0, 0x0($v1) */
".word 0x00000000\n\t" /* 800660A8: nop */
".word 0xAF280004\n\t" /* 800660AC: sw         $t0, 0x4($t9) */
".word 0xA3330007\n\t" /* 800660B0: sb         $s3, 0x7($t9) */
".L800660B4:\n\t"
".word 0x8CE80000\n\t" /* 800660B4: lw         $t0, 0x0($a3) */
".word 0x8CE90004\n\t" /* 800660B8: lw         $t1, 0x4($a3) */
".word 0x8CEA0008\n\t" /* 800660BC: lw         $t2, 0x8($a3) */
".word 0x8CEB000C\n\t" /* 800660C0: lw         $t3, 0xC($a3) */
".word 0x48023800\n\t" /* 800660C4: mfc2       $v0, $7 ( handwritten instruction ) */
".word 0x3C010200\n\t" /* 800660C8: lui        $at, (0x2000000 >> 16) */
".word 0x02011824\n\t" /* 800660CC: and        $v1, $s0, $at */
".word 0x3C01FF9F\n\t" /* 800660D0: lui        $at, (0xFF9FFFFF >> 16) */
".word 0x3421FFFF\n\t" /* 800660D4: ori        $at, $at, (0xFF9FFFFF & 0xFFFF) */
".word 0x01214824\n\t" /* 800660D8: and        $t1, $t1, $at */
".word 0x01314825\n\t" /* 800660DC: or         $t1, $t1, $s1 */
".word 0x01C21006\n\t" /* 800660E0: srlv       $v0, $v0, $t6 */
".word 0x00021080\n\t" /* 800660E4: sll        $v0, $v0, 2 */
".word 0x004F1021\n\t" /* 800660E8: addu       $v0, $v0, $t7 */
".word 0x8C4D0000\n\t" /* 800660EC: lw         $t5, 0x0($v0) */
".word 0xEB2E0020\n\t" /* 800660F0: swc2       $14, 0x20($t9) */
".L800660F4:\n\t"
".word 0xAF28000C\n\t" /* 800660F4: sw         $t0, 0xC($t9) */
".word 0xAF290014\n\t" /* 800660F8: sw         $t1, 0x14($t9) */
".word 0xAF2A001C\n\t" /* 800660FC: sw         $t2, 0x1C($t9) */
".word 0xAF2B0024\n\t" /* 80066100: sw         $t3, 0x24($t9) */
".word 0x000D6A00\n\t" /* 80066104: sll        $t5, $t5, 8 */
".word 0x35AD0009\n\t" /* 80066108: ori        $t5, $t5, 0x9 */
".word 0x000D0A02\n\t" /* 8006610C: srl        $at, $t5, 8 */
".word 0x000D6E00\n\t" /* 80066110: sll        $t5, $t5, 24 */
".word 0x01A16825\n\t" /* 80066114: or         $t5, $t5, $at */
".word 0xAF2D0000\n\t" /* 80066118: sw         $t5, 0x0($t9) */
".word 0x00196A00\n\t" /* 8006611C: sll        $t5, $t9, 8 */
".word 0x000D6A02\n\t" /* 80066120: srl        $t5, $t5, 8 */
".word 0x10600017\n\t" /* 80066124: beqz       $v1, .L80066184 */
".word 0xAC4D0000\n\t" /* 80066128: sw        $t5, 0x0($v0) */
".word 0x12400015\n\t" /* 8006612C: beqz       $s2, .L80066184 */
".word 0x00000000\n\t" /* 80066130: nop */
".word 0x3C01FF9F\n\t" /* 80066134: lui        $at, (0xFF9FFFFF >> 16) */
".word 0x3421FFFF\n\t" /* 80066138: ori        $at, $at, (0xFF9FFFFF & 0xFFFF) */
".word 0x01214824\n\t" /* 8006613C: and        $t1, $t1, $at */
".word 0x3C010040\n\t" /* 80066140: lui        $at, (0x400000 >> 16) */
".word 0x01214825\n\t" /* 80066144: or         $t1, $t1, $at */
".word 0x8F230008\n\t" /* 80066148: lw         $v1, 0x8($t9) */
".word 0x00084400\n\t" /* 8006614C: sll        $t0, $t0, 16 */
".word 0xAF230030\n\t" /* 80066150: sw         $v1, 0x30($t9) */
".word 0x8F230010\n\t" /* 80066154: lw         $v1, 0x10($t9) */
".word 0x00084402\n\t" /* 80066158: srl        $t0, $t0, 16 */
".word 0xAF230038\n\t" /* 8006615C: sw         $v1, 0x38($t9) */
".word 0x8F230018\n\t" /* 80066160: lw         $v1, 0x18($t9) */
".word 0x01124025\n\t" /* 80066164: or         $t0, $t0, $s2 */
".word 0xAF230040\n\t" /* 80066168: sw         $v1, 0x40($t9) */
".word 0x8F230020\n\t" /* 8006616C: lw         $v1, 0x20($t9) */
".word 0xAF2C002C\n\t" /* 80066170: sw         $t4, 0x2C($t9) */
".word 0xAF230048\n\t" /* 80066174: sw         $v1, 0x48($t9) */
".word 0x27390028\n\t" /* 80066178: addiu      $t9, $t9, 0x28 */
".word 0x0801983D\n\t" /* 8006617C: j          .L800660F4 */
".word 0x24030000\n\t" /* 80066180: addiu     $v1, $zero, 0x0 */
".L80066184:\n\t"
".word 0x27390028\n\t" /* 80066184: addiu      $t9, $t9, 0x28 */
".L80066188:\n\t"
".word 0x2718FFFF\n\t" /* 80066188: addiu      $t8, $t8, -0x1 */
".word 0x1700FF86\n\t" /* 8006618C: bnez       $t8, .L80065FA8 */
".word 0x24E70018\n\t" /* 80066190: addiu     $a3, $a3, 0x18 */
".L80066194:\n\t"
".word 0x8C900020\n\t" /* 80066194: lw         $s0, 0x20($a0) */
".word 0x8C910024\n\t" /* 80066198: lw         $s1, 0x24($a0) */
".word 0x8C920028\n\t" /* 8006619C: lw         $s2, 0x28($a0) */
".word 0x8C93002C\n\t" /* 800661A0: lw         $s3, 0x2C($a0) */
".word 0x8C960030\n\t" /* 800661A4: lw         $s6, 0x30($a0) */
".word 0x8C970034\n\t" /* 800661A8: lw         $s7, 0x34($a0) */
".word 0x8C820000\n\t" /* 800661AC: lw         $v0, 0x0($a0) */
".word 0x3C018010\n\t" /* 800661B0: lui        $at, %hi(D_800FE240) */
".word 0xAC39E240\n\t" /* 800661B4: sw         $t9, %lo(D_800FE240)($at) */
".word 0x24420008\n\t" /* 800661B8: addiu      $v0, $v0, 0x8 */
".word 0x03E00008\n\t" /* 800661BC: jr         $ra */
".word 0x00000000\n\t" /* 800661C0: nop */
    ".set reorder\n"
);
