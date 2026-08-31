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
    ".global func_80067D94\n"
    "func_80067D94:\n"
".word 0x8C870000\n\t" /* 80067D94: lw         $a3, 0x0($a0) */
".word 0x8C990010\n\t" /* 80067D98: lw         $t9, 0x10($a0) */
".word 0x94F80002\n\t" /* 80067D9C: lhu        $t8, 0x2($a3) */
".word 0x8CE60004\n\t" /* 80067DA0: lw         $a2, 0x4($a3) */
".word 0x8C850014\n\t" /* 80067DA4: lw         $a1, 0x14($a0) */
".word 0x00063080\n\t" /* 80067DA8: sll        $a2, $a2, 2 */
".word 0xAC900028\n\t" /* 80067DAC: sw         $s0, 0x28($a0) */
".word 0xAC91002C\n\t" /* 80067DB0: sw         $s1, 0x2C($a0) */
".word 0xAC920030\n\t" /* 80067DB4: sw         $s2, 0x30($a0) */
".word 0xAC930034\n\t" /* 80067DB8: sw         $s3, 0x34($a0) */
".word 0x1300007A\n\t" /* 80067DBC: beqz       $t8, .L80067FA8 */
".word 0x00A63821\n\t" /* 80067DC0: addu      $a3, $a1, $a2 */
".word 0x3C10800A\n\t" /* 80067DC4: lui        $s0, %hi(D_8009AFB4) */
".word 0x8E10AFB4\n\t" /* 80067DC8: lw         $s0, %lo(D_8009AFB4)($s0) */
".word 0x3C11800A\n\t" /* 80067DCC: lui        $s1, %hi(D_8009AFD8) */
".word 0x8E31AFD8\n\t" /* 80067DD0: lw         $s1, %lo(D_8009AFD8)($s1) */
".word 0x3C12800A\n\t" /* 80067DD4: lui        $s2, %hi(D_8009AFDC) */
".word 0x8E52AFDC\n\t" /* 80067DD8: lw         $s2, %lo(D_8009AFDC)($s2) */
".word 0x02006021\n\t" /* 80067DDC: addu       $t4, $s0, $zero */
".word 0x3C0D800A\n\t" /* 80067DE0: lui        $t5, %hi(D_8009AFE4) */
".word 0x81ADAFE4\n\t" /* 80067DE4: lb         $t5, %lo(D_8009AFE4)($t5) */
".word 0x00109E02\n\t" /* 80067DE8: srl        $s3, $s0, 24 */
".word 0x00139E00\n\t" /* 80067DEC: sll        $s3, $s3, 24 */
".word 0x24010001\n\t" /* 80067DF0: addiu      $at, $zero, 0x1 */
".word 0x11A1006C\n\t" /* 80067DF4: beq        $t5, $at, .L80067FA8 */
".word 0x00000000\n\t" /* 80067DF8: nop */
".word 0x3C0D800A\n\t" /* 80067DFC: lui        $t5, %hi(D_8009AFE0) */
".word 0x8DADAFE0\n\t" /* 80067E00: lw         $t5, %lo(D_8009AFE0)($t5) */
".word 0x8C85001C\n\t" /* 80067E04: lw         $a1, 0x1C($a0) */
".word 0x8C860024\n\t" /* 80067E08: lw         $a2, 0x24($a0) */
".word 0x11A00002\n\t" /* 80067E0C: beqz       $t5, .L80067E18 */
".word 0x00000000\n\t" /* 80067E10: nop */
".word 0x24C60004\n\t" /* 80067E14: addiu      $a2, $a2, 0x4 */
".L80067E18:\n\t"
".word 0x8C8D0004\n\t" /* 80067E18: lw         $t5, 0x4($a0) */
".word 0x8C8E0008\n\t" /* 80067E1C: lw         $t6, 0x8($a0) */
".word 0x8DAF0004\n\t" /* 80067E20: lw         $t7, 0x4($t5) */
".L80067E24:\n\t"
".word 0x2403FFFF\n\t" /* 80067E24: addiu      $v1, $zero, -0x1 */
".word 0x8CE8000C\n\t" /* 80067E28: lw         $t0, 0xC($a3) */
".word 0x8CE90010\n\t" /* 80067E2C: lw         $t1, 0x10($a3) */
".word 0x8CEA0014\n\t" /* 80067E30: lw         $t2, 0x14($a3) */
".word 0x00086C02\n\t" /* 80067E34: srl        $t5, $t0, 16 */
".word 0x000D68C0\n\t" /* 80067E38: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 80067E3C: addu       $t5, $t5, $a1 */
".word 0x8DA20004\n\t" /* 80067E40: lw         $v0, 0x4($t5) */
".word 0x8DAD0000\n\t" /* 80067E44: lw         $t5, 0x0($t5) */
".word 0x10430054\n\t" /* 80067E48: beq        $v0, $v1, .L80067F9C */
".word 0x48828800\n\t" /* 80067E4C: mtc2      $v0, $17 ( handwritten instruction ) */
".word 0x488D6000\n\t" /* 80067E50: mtc2       $t5, $12 ( handwritten instruction ) */
".word 0xAF2D0008\n\t" /* 80067E54: sw         $t5, 0x8($t9) */
".word 0x00096C02\n\t" /* 80067E58: srl        $t5, $t1, 16 */
".word 0x000D68C0\n\t" /* 80067E5C: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 80067E60: addu       $t5, $t5, $a1 */
".word 0x8DA20004\n\t" /* 80067E64: lw         $v0, 0x4($t5) */
".word 0x8DAD0000\n\t" /* 80067E68: lw         $t5, 0x0($t5) */
".word 0x1043004B\n\t" /* 80067E6C: beq        $v0, $v1, .L80067F9C */
".word 0x48829000\n\t" /* 80067E70: mtc2      $v0, $18 ( handwritten instruction ) */
".word 0x488D6800\n\t" /* 80067E74: mtc2       $t5, $13 ( handwritten instruction ) */
".word 0xAF2D0014\n\t" /* 80067E78: sw         $t5, 0x14($t9) */
".word 0x000A6C02\n\t" /* 80067E7C: srl        $t5, $t2, 16 */
".word 0x000D68C0\n\t" /* 80067E80: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 80067E84: addu       $t5, $t5, $a1 */
".word 0x8DA20004\n\t" /* 80067E88: lw         $v0, 0x4($t5) */
".word 0x8DAD0000\n\t" /* 80067E8C: lw         $t5, 0x0($t5) */
".word 0x10430042\n\t" /* 80067E90: beq        $v0, $v1, .L80067F9C */
".word 0x48829800\n\t" /* 80067E94: mtc2      $v0, $19 ( handwritten instruction ) */
".word 0x488D7000\n\t" /* 80067E98: mtc2       $t5, $14 ( handwritten instruction ) */
".word 0xAF2D0020\n\t" /* 80067E9C: sw         $t5, 0x20($t9) */
".word 0x00084400\n\t" /* 80067EA0: sll        $t0, $t0, 16 */
".word 0x00084342\n\t" /* 80067EA4: srl        $t0, $t0, 13 */
".word 0x00094C00\n\t" /* 80067EA8: sll        $t1, $t1, 16 */
".word 0x00094B42\n\t" /* 80067EAC: srl        $t1, $t1, 13 */
".word 0x000A5400\n\t" /* 80067EB0: sll        $t2, $t2, 16 */
".word 0x000A5342\n\t" /* 80067EB4: srl        $t2, $t2, 13 */
".word 0x01064021\n\t" /* 80067EB8: addu       $t0, $t0, $a2 */
".word 0x01264821\n\t" /* 80067EBC: addu       $t1, $t1, $a2 */
".word 0x01465021\n\t" /* 80067EC0: addu       $t2, $t2, $a2 */
".word 0x8D080000\n\t" /* 80067EC4: lw         $t0, 0x0($t0) */
".word 0x8D290000\n\t" /* 80067EC8: lw         $t1, 0x0($t1) */
".word 0x8D4A0000\n\t" /* 80067ECC: lw         $t2, 0x0($t2) */
".word 0x4B58002D\n\t" /* 80067ED0: avsz3 */
".word 0x01134025\n\t" /* 80067ED4: or         $t0, $t0, $s3 */
".word 0xAF280004\n\t" /* 80067ED8: sw         $t0, 0x4($t9) */
".word 0xAF290010\n\t" /* 80067EDC: sw         $t1, 0x10($t9) */
".word 0xAF2A001C\n\t" /* 80067EE0: sw         $t2, 0x1C($t9) */
".word 0x8CE80000\n\t" /* 80067EE4: lw         $t0, 0x0($a3) */
".word 0x8CE90004\n\t" /* 80067EE8: lw         $t1, 0x4($a3) */
".word 0x8CEA0008\n\t" /* 80067EEC: lw         $t2, 0x8($a3) */
".word 0x48023800\n\t" /* 80067EF0: mfc2       $v0, $7 ( handwritten instruction ) */
".word 0x3C010200\n\t" /* 80067EF4: lui        $at, (0x2000000 >> 16) */
".word 0x02011824\n\t" /* 80067EF8: and        $v1, $s0, $at */
".word 0x01314825\n\t" /* 80067EFC: or         $t1, $t1, $s1 */
".word 0x01C21006\n\t" /* 80067F00: srlv       $v0, $v0, $t6 */
".word 0x00021080\n\t" /* 80067F04: sll        $v0, $v0, 2 */
".word 0x004F1021\n\t" /* 80067F08: addu       $v0, $v0, $t7 */
".word 0x8C4D0000\n\t" /* 80067F0C: lw         $t5, 0x0($v0) */
".L80067F10:\n\t"
".word 0xAF28000C\n\t" /* 80067F10: sw         $t0, 0xC($t9) */
".word 0xAF290018\n\t" /* 80067F14: sw         $t1, 0x18($t9) */
".word 0xAF2A0024\n\t" /* 80067F18: sw         $t2, 0x24($t9) */
".word 0x000D6A00\n\t" /* 80067F1C: sll        $t5, $t5, 8 */
".word 0x35AD0009\n\t" /* 80067F20: ori        $t5, $t5, 0x9 */
".word 0x000D0A02\n\t" /* 80067F24: srl        $at, $t5, 8 */
".word 0x000D6E00\n\t" /* 80067F28: sll        $t5, $t5, 24 */
".word 0x01A16825\n\t" /* 80067F2C: or         $t5, $t5, $at */
".word 0xAF2D0000\n\t" /* 80067F30: sw         $t5, 0x0($t9) */
".word 0x00196A00\n\t" /* 80067F34: sll        $t5, $t9, 8 */
".word 0x000D6A02\n\t" /* 80067F38: srl        $t5, $t5, 8 */
".word 0x10600016\n\t" /* 80067F3C: beqz       $v1, .L80067F98 */
".word 0xAC4D0000\n\t" /* 80067F40: sw        $t5, 0x0($v0) */
".word 0x12400014\n\t" /* 80067F44: beqz       $s2, .L80067F98 */
".word 0x00084400\n\t" /* 80067F48: sll       $t0, $t0, 16 */
".word 0x00084402\n\t" /* 80067F4C: srl        $t0, $t0, 16 */
".word 0x01124025\n\t" /* 80067F50: or         $t0, $t0, $s2 */
".word 0x3C01FF9F\n\t" /* 80067F54: lui        $at, (0xFF9FFFFF >> 16) */
".word 0x3421FFFF\n\t" /* 80067F58: ori        $at, $at, (0xFF9FFFFF & 0xFFFF) */
".word 0x01214824\n\t" /* 80067F5C: and        $t1, $t1, $at */
".word 0x3C010040\n\t" /* 80067F60: lui        $at, (0x400000 >> 16) */
".word 0x01214825\n\t" /* 80067F64: or         $t1, $t1, $at */
".word 0x8F230008\n\t" /* 80067F68: lw         $v1, 0x8($t9) */
".word 0xAF2C002C\n\t" /* 80067F6C: sw         $t4, 0x2C($t9) */
".word 0xAF230030\n\t" /* 80067F70: sw         $v1, 0x30($t9) */
".word 0x8F230014\n\t" /* 80067F74: lw         $v1, 0x14($t9) */
".word 0xAF2C0038\n\t" /* 80067F78: sw         $t4, 0x38($t9) */
".word 0xAF23003C\n\t" /* 80067F7C: sw         $v1, 0x3C($t9) */
".word 0x8F230020\n\t" /* 80067F80: lw         $v1, 0x20($t9) */
".word 0xAF2C0044\n\t" /* 80067F84: sw         $t4, 0x44($t9) */
".word 0xAF230048\n\t" /* 80067F88: sw         $v1, 0x48($t9) */
".word 0x27390028\n\t" /* 80067F8C: addiu      $t9, $t9, 0x28 */
".word 0x08019FC4\n\t" /* 80067F90: j          .L80067F10 */
".word 0x24030000\n\t" /* 80067F94: addiu     $v1, $zero, 0x0 */
".L80067F98:\n\t"
".word 0x27390028\n\t" /* 80067F98: addiu      $t9, $t9, 0x28 */
".L80067F9C:\n\t"
".word 0x2718FFFF\n\t" /* 80067F9C: addiu      $t8, $t8, -0x1 */
".word 0x1700FFA0\n\t" /* 80067FA0: bnez       $t8, .L80067E24 */
".word 0x24E70018\n\t" /* 80067FA4: addiu     $a3, $a3, 0x18 */
".L80067FA8:\n\t"
".word 0x8C900028\n\t" /* 80067FA8: lw         $s0, 0x28($a0) */
".word 0x8C91002C\n\t" /* 80067FAC: lw         $s1, 0x2C($a0) */
".word 0x8C920030\n\t" /* 80067FB0: lw         $s2, 0x30($a0) */
".word 0x8C930034\n\t" /* 80067FB4: lw         $s3, 0x34($a0) */
".word 0x8C820000\n\t" /* 80067FB8: lw         $v0, 0x0($a0) */
".word 0x3C018010\n\t" /* 80067FBC: lui        $at, %hi(D_800FE240) */
".word 0xAC39E240\n\t" /* 80067FC0: sw         $t9, %lo(D_800FE240)($at) */
".word 0x24420008\n\t" /* 80067FC4: addiu      $v0, $v0, 0x8 */
".word 0x03E00008\n\t" /* 80067FC8: jr         $ra */
".word 0x00000000\n\t" /* 80067FCC: nop */
    ".set reorder\n"
);
