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
    ".global func_80066E60\n"
    "func_80066E60:\n"
".word 0x8C870000\n\t" /* 80066E60: lw         $a3, 0x0($a0) */
".word 0x8C990010\n\t" /* 80066E64: lw         $t9, 0x10($a0) */
".word 0x94F80002\n\t" /* 80066E68: lhu        $t8, 0x2($a3) */
".word 0x8CE60004\n\t" /* 80066E6C: lw         $a2, 0x4($a3) */
".word 0x8C850014\n\t" /* 80066E70: lw         $a1, 0x14($a0) */
".word 0x00063080\n\t" /* 80066E74: sll        $a2, $a2, 2 */
".word 0xAC900020\n\t" /* 80066E78: sw         $s0, 0x20($a0) */
".word 0xAC910024\n\t" /* 80066E7C: sw         $s1, 0x24($a0) */
".word 0xAC920028\n\t" /* 80066E80: sw         $s2, 0x28($a0) */
".word 0xAC93002C\n\t" /* 80066E84: sw         $s3, 0x2C($a0) */
".word 0xAC940030\n\t" /* 80066E88: sw         $s4, 0x30($a0) */
".word 0xAC950034\n\t" /* 80066E8C: sw         $s5, 0x34($a0) */
".word 0xAC960038\n\t" /* 80066E90: sw         $s6, 0x38($a0) */
".word 0xAC97003C\n\t" /* 80066E94: sw         $s7, 0x3C($a0) */
".word 0x130000D3\n\t" /* 80066E98: beqz       $t8, .L800671E8 */
".word 0x00A63821\n\t" /* 80066E9C: addu      $a3, $a1, $a2 */
".word 0x3C10800A\n\t" /* 80066EA0: lui        $s0, %hi(D_8009AFB8) */
".word 0x8E10AFB8\n\t" /* 80066EA4: lw         $s0, %lo(D_8009AFB8)($s0) */
".word 0x3C11800A\n\t" /* 80066EA8: lui        $s1, %hi(D_8009AFD8) */
".word 0x8E31AFD8\n\t" /* 80066EAC: lw         $s1, %lo(D_8009AFD8)($s1) */
".word 0x3C12800A\n\t" /* 80066EB0: lui        $s2, %hi(D_8009AFDC) */
".word 0x8E52AFDC\n\t" /* 80066EB4: lw         $s2, %lo(D_8009AFDC)($s2) */
".word 0x3C16800A\n\t" /* 80066EB8: lui        $s6, %hi(D_8009AFE4) */
".word 0x82D6AFE4\n\t" /* 80066EBC: lb         $s6, %lo(D_8009AFE4)($s6) */
".word 0x3C17800A\n\t" /* 80066EC0: lui        $s7, %hi(D_8009AFE0) */
".word 0x8EF7AFE0\n\t" /* 80066EC4: lw         $s7, %lo(D_8009AFE0)($s7) */
".word 0x02006021\n\t" /* 80066EC8: addu       $t4, $s0, $zero */
".word 0x3C02800A\n\t" /* 80066ECC: lui        $v0, %hi(D_8009AFE5) */
".word 0x8042AFE5\n\t" /* 80066ED0: lb         $v0, %lo(D_8009AFE5)($v0) */
".word 0x3C010200\n\t" /* 80066ED4: lui        $at, (0x2000000 >> 16) */
".word 0x02018025\n\t" /* 80066ED8: or         $s0, $s0, $at */
".word 0x1440000E\n\t" /* 80066EDC: bnez       $v0, .L80066F18 */
".word 0x02006021\n\t" /* 80066EE0: addu      $t4, $s0, $zero */
".word 0x8CF10008\n\t" /* 80066EE4: lw         $s1, 0x8($a3) */
".word 0x3C010060\n\t" /* 80066EE8: lui        $at, (0x600000 >> 16) */
".word 0x02218824\n\t" /* 80066EEC: and        $s1, $s1, $at */
".word 0x16200009\n\t" /* 80066EF0: bnez       $s1, .L80066F18 */
".word 0x00000000\n\t" /* 80066EF4: nop */
".word 0x12400008\n\t" /* 80066EF8: beqz       $s2, .L80066F1C */
".word 0x00000000\n\t" /* 80066EFC: nop */
".word 0x94F20006\n\t" /* 80066F00: lhu        $s2, 0x6($a3) */
".word 0x3C0C800A\n\t" /* 80066F04: lui        $t4, %hi(D_8009AFC8) */
".word 0x8D8CAFC8\n\t" /* 80066F08: lw         $t4, %lo(D_8009AFC8)($t4) */
".word 0x00129400\n\t" /* 80066F0C: sll        $s2, $s2, 16 */
".word 0x08019BC7\n\t" /* 80066F10: j          .L80066F1C */
".word 0x3C110020\n\t" /* 80066F14: lui       $s1, (0x200000 >> 16) */
".L80066F18:\n\t"
".word 0x24120000\n\t" /* 80066F18: addiu      $s2, $zero, 0x0 */
".L80066F1C:\n\t"
".word 0x00109E02\n\t" /* 80066F1C: srl        $s3, $s0, 24 */
".word 0x3C14E200\n\t" /* 80066F20: lui        $s4, (0xE2000000 >> 16) */
".word 0x8C850018\n\t" /* 80066F24: lw         $a1, 0x18($a0) */
".word 0x8C86001C\n\t" /* 80066F28: lw         $a2, 0x1C($a0) */
".word 0x48903000\n\t" /* 80066F2C: mtc2       $s0, $6 ( handwritten instruction ) */
".word 0x8C8D0004\n\t" /* 80066F30: lw         $t5, 0x4($a0) */
".word 0x8C8E0008\n\t" /* 80066F34: lw         $t6, 0x8($a0) */
".word 0x8DAF0004\n\t" /* 80066F38: lw         $t7, 0x4($t5) */
".L80066F3C:\n\t"
".word 0x8CE80010\n\t" /* 80066F3C: lw         $t0, 0x10($a3) */
".word 0x98E8000E\n\t" /* 80066F40: lwr        $t0, 0xE($a3) */
".word 0x8CE90014\n\t" /* 80066F44: lw         $t1, 0x14($a3) */
".word 0x8CEA0018\n\t" /* 80066F48: lw         $t2, 0x18($a3) */
".word 0x8CEB001C\n\t" /* 80066F4C: lw         $t3, 0x1C($a3) */
".word 0x00086C02\n\t" /* 80066F50: srl        $t5, $t0, 16 */
".word 0x000D68C0\n\t" /* 80066F54: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 80066F58: addu       $t5, $t5, $a1 */
".word 0xC9A00000\n\t" /* 80066F5C: lwc2       $0, 0x0($t5) */
".word 0xC9A10004\n\t" /* 80066F60: lwc2       $1, 0x4($t5) */
".word 0x00096C02\n\t" /* 80066F64: srl        $t5, $t1, 16 */
".word 0x000D68C0\n\t" /* 80066F68: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 80066F6C: addu       $t5, $t5, $a1 */
".word 0xC9A20000\n\t" /* 80066F70: lwc2       $2, 0x0($t5) */
".word 0xC9A30004\n\t" /* 80066F74: lwc2       $3, 0x4($t5) */
".word 0x000A6C02\n\t" /* 80066F78: srl        $t5, $t2, 16 */
".word 0x000D68C0\n\t" /* 80066F7C: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 80066F80: addu       $t5, $t5, $a1 */
".word 0xC9A40000\n\t" /* 80066F84: lwc2       $4, 0x0($t5) */
".word 0xC9A50004\n\t" /* 80066F88: lwc2       $5, 0x4($t5) */
".word 0x000B6C02\n\t" /* 80066F8C: srl        $t5, $t3, 16 */
".word 0x000D68C0\n\t" /* 80066F90: sll        $t5, $t5, 3 */
".word 0x4A280030\n\t" /* 80066F94: rtpt */
".word 0x000B5C00\n\t" /* 80066F98: sll        $t3, $t3, 16 */
".word 0x000B5B42\n\t" /* 80066F9C: srl        $t3, $t3, 13 */
".word 0x24010001\n\t" /* 80066FA0: addiu      $at, $zero, 0x1 */
".word 0x12C10005\n\t" /* 80066FA4: beq        $s6, $at, .L80066FBC */
".word 0x01A56821\n\t" /* 80066FA8: addu      $t5, $t5, $a1 */
".word 0x4842F800\n\t" /* 80066FAC: cfc2       $v0, $31 ( handwritten instruction ) */
".word 0x00000000\n\t" /* 80066FB0: nop */
".word 0x04400089\n\t" /* 80066FB4: bltz       $v0, .L800671DC */
".word 0x00000000\n\t" /* 80066FB8: nop */
".L80066FBC:\n\t"
".word 0xC9A00000\n\t" /* 80066FBC: lwc2       $0, 0x0($t5) */
".word 0xC9A10004\n\t" /* 80066FC0: lwc2       $1, 0x4($t5) */
".word 0xEB2C000C\n\t" /* 80066FC4: swc2       $12, 0xC($t9) */
".word 0xEB2D0018\n\t" /* 80066FC8: swc2       $13, 0x18($t9) */
".word 0xEB2E0024\n\t" /* 80066FCC: swc2       $14, 0x24($t9) */
".word 0x00084400\n\t" /* 80066FD0: sll        $t0, $t0, 16 */
".word 0x00084342\n\t" /* 80066FD4: srl        $t0, $t0, 13 */
".word 0x4A180001\n\t" /* 80066FD8: rtps */
".word 0x00094C00\n\t" /* 80066FDC: sll        $t1, $t1, 16 */
".word 0x24010001\n\t" /* 80066FE0: addiu      $at, $zero, 0x1 */
".word 0x12C10005\n\t" /* 80066FE4: beq        $s6, $at, .L80066FFC */
".word 0x00094B42\n\t" /* 80066FE8: srl       $t1, $t1, 13 */
".word 0x4842F800\n\t" /* 80066FEC: cfc2       $v0, $31 ( handwritten instruction ) */
".word 0x00000000\n\t" /* 80066FF0: nop */
".word 0x04400079\n\t" /* 80066FF4: bltz       $v0, .L800671DC */
".word 0x00000000\n\t" /* 80066FF8: nop */
".L80066FFC:\n\t"
".word 0x4B68002E\n\t" /* 80066FFC: avsz4 */
".word 0xEB2E0030\n\t" /* 80067000: swc2       $14, 0x30($t9) */
".word 0x000A5400\n\t" /* 80067004: sll        $t2, $t2, 16 */
".word 0x000A5342\n\t" /* 80067008: srl        $t2, $t2, 13 */
".word 0x8CF50000\n\t" /* 8006700C: lw         $s5, 0x0($a3) */
".word 0x12C00029\n\t" /* 80067010: beqz       $s6, .L800670B8 */
".word 0x01666821\n\t" /* 80067014: addu      $t5, $t3, $a2 */
".word 0xC9A00000\n\t" /* 80067018: lwc2       $0, 0x0($t5) */
".word 0xC9A10004\n\t" /* 8006701C: lwc2       $1, 0x4($t5) */
".word 0x00000000\n\t" /* 80067020: nop */
".word 0x00000000\n\t" /* 80067024: nop */
".word 0x4B08041B\n\t" /* 80067028: nccs */
".word 0x01066821\n\t" /* 8006702C: addu       $t5, $t0, $a2 */
".word 0xC9A00000\n\t" /* 80067030: lwc2       $0, 0x0($t5) */
".word 0xC9A10004\n\t" /* 80067034: lwc2       $1, 0x4($t5) */
".word 0x01266821\n\t" /* 80067038: addu       $t5, $t1, $a2 */
".word 0xC9A20000\n\t" /* 8006703C: lwc2       $2, 0x0($t5) */
".word 0xC9A30004\n\t" /* 80067040: lwc2       $3, 0x4($t5) */
".word 0x01466821\n\t" /* 80067044: addu       $t5, $t2, $a2 */
".word 0xC9A40000\n\t" /* 80067048: lwc2       $4, 0x0($t5) */
".word 0xC9A50004\n\t" /* 8006704C: lwc2       $5, 0x4($t5) */
".word 0x12E00003\n\t" /* 80067050: beqz       $s7, .L80067060 */
".word 0x000B5842\n\t" /* 80067054: srl       $t3, $t3, 1 */
".word 0x01775821\n\t" /* 80067058: addu       $t3, $t3, $s7 */
".word 0xE9760000\n\t" /* 8006705C: swc2       $22, 0x0($t3) */
".L80067060:\n\t"
".word 0xEB36002C\n\t" /* 80067060: swc2       $22, 0x2C($t9) */
".word 0x00000000\n\t" /* 80067064: nop */
".word 0x00000000\n\t" /* 80067068: nop */
".word 0x4B18043F\n\t" /* 8006706C: ncct */
".word 0x12E00009\n\t" /* 80067070: beqz       $s7, .L80067098 */
".word 0x00084042\n\t" /* 80067074: srl       $t0, $t0, 1 */
".word 0x01174021\n\t" /* 80067078: addu       $t0, $t0, $s7 */
".word 0x00094842\n\t" /* 8006707C: srl        $t1, $t1, 1 */
".word 0x01374821\n\t" /* 80067080: addu       $t1, $t1, $s7 */
".word 0x000A5042\n\t" /* 80067084: srl        $t2, $t2, 1 */
".word 0x01575021\n\t" /* 80067088: addu       $t2, $t2, $s7 */
".word 0xE9140000\n\t" /* 8006708C: swc2       $20, 0x0($t0) */
".word 0xE9350000\n\t" /* 80067090: swc2       $21, 0x0($t1) */
".word 0xE9560000\n\t" /* 80067094: swc2       $22, 0x0($t2) */
".L80067098:\n\t"
".word 0xEB340008\n\t" /* 80067098: swc2       $20, 0x8($t9) */
".word 0xEB350014\n\t" /* 8006709C: swc2       $21, 0x14($t9) */
".word 0xEB360020\n\t" /* 800670A0: swc2       $22, 0x20($t9) */
".word 0x24010001\n\t" /* 800670A4: addiu      $at, $zero, 0x1 */
".word 0x12C1004C\n\t" /* 800670A8: beq        $s6, $at, .L800671DC */
".word 0x00000000\n\t" /* 800670AC: nop */
".word 0x08019C3F\n\t" /* 800670B0: j          .L800670FC */
".word 0x00000000\n\t" /* 800670B4: nop */
".L800670B8:\n\t"
".word 0x00084042\n\t" /* 800670B8: srl        $t0, $t0, 1 */
".word 0x01171821\n\t" /* 800670BC: addu       $v1, $t0, $s7 */
".word 0x8C680000\n\t" /* 800670C0: lw         $t0, 0x0($v1) */
".word 0x00094842\n\t" /* 800670C4: srl        $t1, $t1, 1 */
".word 0x01371821\n\t" /* 800670C8: addu       $v1, $t1, $s7 */
".word 0x8C690000\n\t" /* 800670CC: lw         $t1, 0x0($v1) */
".word 0x000A5042\n\t" /* 800670D0: srl        $t2, $t2, 1 */
".word 0x01571821\n\t" /* 800670D4: addu       $v1, $t2, $s7 */
".word 0x8C6A0000\n\t" /* 800670D8: lw         $t2, 0x0($v1) */
".word 0x000B5842\n\t" /* 800670DC: srl        $t3, $t3, 1 */
".word 0x01771821\n\t" /* 800670E0: addu       $v1, $t3, $s7 */
".word 0x8C6B0000\n\t" /* 800670E4: lw         $t3, 0x0($v1) */
".word 0xAF280008\n\t" /* 800670E8: sw         $t0, 0x8($t9) */
".word 0xAF290014\n\t" /* 800670EC: sw         $t1, 0x14($t9) */
".word 0xAF2A0020\n\t" /* 800670F0: sw         $t2, 0x20($t9) */
".word 0xAF2B002C\n\t" /* 800670F4: sw         $t3, 0x2C($t9) */
".word 0xA333000B\n\t" /* 800670F8: sb         $s3, 0xB($t9) */
".L800670FC:\n\t"
".word 0x8CE80004\n\t" /* 800670FC: lw         $t0, 0x4($a3) */
".word 0x8CE90008\n\t" /* 80067100: lw         $t1, 0x8($a3) */
".word 0x8CEA000C\n\t" /* 80067104: lw         $t2, 0xC($a3) */
".word 0x8CEB0010\n\t" /* 80067108: lw         $t3, 0x10($a3) */
".word 0x48023800\n\t" /* 8006710C: mfc2       $v0, $7 ( handwritten instruction ) */
".word 0x3C010200\n\t" /* 80067110: lui        $at, (0x2000000 >> 16) */
".word 0x02011824\n\t" /* 80067114: and        $v1, $s0, $at */
".word 0x3C01FF9F\n\t" /* 80067118: lui        $at, (0xFF9FFFFF >> 16) */
".word 0x3421FFFF\n\t" /* 8006711C: ori        $at, $at, (0xFF9FFFFF & 0xFFFF) */
".word 0x01214824\n\t" /* 80067120: and        $t1, $t1, $at */
".word 0x01314825\n\t" /* 80067124: or         $t1, $t1, $s1 */
".word 0x01C21006\n\t" /* 80067128: srlv       $v0, $v0, $t6 */
".word 0x00021080\n\t" /* 8006712C: sll        $v0, $v0, 2 */
".word 0x004F1021\n\t" /* 80067130: addu       $v0, $v0, $t7 */
".word 0x8C4D0000\n\t" /* 80067134: lw         $t5, 0x0($v0) */
".L80067138:\n\t"
".word 0xAF280010\n\t" /* 80067138: sw         $t0, 0x10($t9) */
".word 0xAF29001C\n\t" /* 8006713C: sw         $t1, 0x1C($t9) */
".word 0xAF2A0028\n\t" /* 80067140: sw         $t2, 0x28($t9) */
".word 0xAF2B0034\n\t" /* 80067144: sw         $t3, 0x34($t9) */
".word 0xAF350004\n\t" /* 80067148: sw         $s5, 0x4($t9) */
".word 0xAF340038\n\t" /* 8006714C: sw         $s4, 0x38($t9) */
".word 0x000D6A00\n\t" /* 80067150: sll        $t5, $t5, 8 */
".word 0x35AD000E\n\t" /* 80067154: ori        $t5, $t5, 0xE */
".word 0x000D0A02\n\t" /* 80067158: srl        $at, $t5, 8 */
".word 0x000D6E00\n\t" /* 8006715C: sll        $t5, $t5, 24 */
".word 0x01A16825\n\t" /* 80067160: or         $t5, $t5, $at */
".word 0xAF2D0000\n\t" /* 80067164: sw         $t5, 0x0($t9) */
".word 0x00196A00\n\t" /* 80067168: sll        $t5, $t9, 8 */
".word 0x000D6A02\n\t" /* 8006716C: srl        $t5, $t5, 8 */
".word 0x10600019\n\t" /* 80067170: beqz       $v1, .L800671D8 */
".word 0xAC4D0000\n\t" /* 80067174: sw        $t5, 0x0($v0) */
".word 0x12400017\n\t" /* 80067178: beqz       $s2, .L800671D8 */
".word 0x00084400\n\t" /* 8006717C: sll       $t0, $t0, 16 */
".word 0x00084402\n\t" /* 80067180: srl        $t0, $t0, 16 */
".word 0x01124025\n\t" /* 80067184: or         $t0, $t0, $s2 */
".word 0x3C01FF9F\n\t" /* 80067188: lui        $at, (0xFF9FFFFF >> 16) */
".word 0x3421FFFF\n\t" /* 8006718C: ori        $at, $at, (0xFF9FFFFF & 0xFFFF) */
".word 0x01214824\n\t" /* 80067190: and        $t1, $t1, $at */
".word 0x3C010040\n\t" /* 80067194: lui        $at, (0x400000 >> 16) */
".word 0x01214825\n\t" /* 80067198: or         $t1, $t1, $at */
".word 0x8F23000C\n\t" /* 8006719C: lw         $v1, 0xC($t9) */
".word 0xAF2C0044\n\t" /* 800671A0: sw         $t4, 0x44($t9) */
".word 0xAF230048\n\t" /* 800671A4: sw         $v1, 0x48($t9) */
".word 0x8F230018\n\t" /* 800671A8: lw         $v1, 0x18($t9) */
".word 0xAF2C0050\n\t" /* 800671AC: sw         $t4, 0x50($t9) */
".word 0xAF230054\n\t" /* 800671B0: sw         $v1, 0x54($t9) */
".word 0x8F230024\n\t" /* 800671B4: lw         $v1, 0x24($t9) */
".word 0xAF2C005C\n\t" /* 800671B8: sw         $t4, 0x5C($t9) */
".word 0xAF230060\n\t" /* 800671BC: sw         $v1, 0x60($t9) */
".word 0x8F230030\n\t" /* 800671C0: lw         $v1, 0x30($t9) */
".word 0xAF2C0068\n\t" /* 800671C4: sw         $t4, 0x68($t9) */
".word 0xAF23006C\n\t" /* 800671C8: sw         $v1, 0x6C($t9) */
".word 0x2739003C\n\t" /* 800671CC: addiu      $t9, $t9, 0x3C */
".word 0x08019C4E\n\t" /* 800671D0: j          .L80067138 */
".word 0x24030000\n\t" /* 800671D4: addiu     $v1, $zero, 0x0 */
".L800671D8:\n\t"
".word 0x2739003C\n\t" /* 800671D8: addiu      $t9, $t9, 0x3C */
".L800671DC:\n\t"
".word 0x2718FFFF\n\t" /* 800671DC: addiu      $t8, $t8, -0x1 */
".word 0x1700FF56\n\t" /* 800671E0: bnez       $t8, .L80066F3C */
".word 0x24E70020\n\t" /* 800671E4: addiu     $a3, $a3, 0x20 */
".L800671E8:\n\t"
".word 0x8C900020\n\t" /* 800671E8: lw         $s0, 0x20($a0) */
".word 0x8C910024\n\t" /* 800671EC: lw         $s1, 0x24($a0) */
".word 0x8C920028\n\t" /* 800671F0: lw         $s2, 0x28($a0) */
".word 0x8C93002C\n\t" /* 800671F4: lw         $s3, 0x2C($a0) */
".word 0x8C940030\n\t" /* 800671F8: lw         $s4, 0x30($a0) */
".word 0x8C950034\n\t" /* 800671FC: lw         $s5, 0x34($a0) */
".word 0x8C960038\n\t" /* 80067200: lw         $s6, 0x38($a0) */
".word 0x8C97003C\n\t" /* 80067204: lw         $s7, 0x3C($a0) */
".word 0x8C820000\n\t" /* 80067208: lw         $v0, 0x0($a0) */
".word 0x3C018010\n\t" /* 8006720C: lui        $at, %hi(D_800FE240) */
".word 0xAC39E240\n\t" /* 80067210: sw         $t9, %lo(D_800FE240)($at) */
".word 0x24420008\n\t" /* 80067214: addiu      $v0, $v0, 0x8 */
".word 0x03E00008\n\t" /* 80067218: jr         $ra */
".word 0x00000000\n\t" /* 8006721C: nop */
    ".set reorder\n"
);
