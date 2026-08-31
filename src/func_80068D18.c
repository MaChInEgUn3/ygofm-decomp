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
    ".global func_80068D18\n"
    "func_80068D18:\n"
".word 0x8C870000\n\t" /* 80068D18: lw         $a3, 0x0($a0) */
".word 0x8C990010\n\t" /* 80068D1C: lw         $t9, 0x10($a0) */
".word 0x94F80002\n\t" /* 80068D20: lhu        $t8, 0x2($a3) */
".word 0x8CE60004\n\t" /* 80068D24: lw         $a2, 0x4($a3) */
".word 0x8C850014\n\t" /* 80068D28: lw         $a1, 0x14($a0) */
".word 0x00063080\n\t" /* 80068D2C: sll        $a2, $a2, 2 */
".word 0xAC900028\n\t" /* 80068D30: sw         $s0, 0x28($a0) */
".word 0xAC91002C\n\t" /* 80068D34: sw         $s1, 0x2C($a0) */
".word 0xAC920030\n\t" /* 80068D38: sw         $s2, 0x30($a0) */
".word 0xAC930034\n\t" /* 80068D3C: sw         $s3, 0x34($a0) */
".word 0xAC940038\n\t" /* 80068D40: sw         $s4, 0x38($a0) */
".word 0xAC95003C\n\t" /* 80068D44: sw         $s5, 0x3C($a0) */
".word 0x13000097\n\t" /* 80068D48: beqz       $t8, .L80068FA8 */
".word 0x00A63821\n\t" /* 80068D4C: addu      $a3, $a1, $a2 */
".word 0x3C10800A\n\t" /* 80068D50: lui        $s0, %hi(D_8009AFB4) */
".word 0x8E10AFB4\n\t" /* 80068D54: lw         $s0, %lo(D_8009AFB4)($s0) */
".word 0x3C11800A\n\t" /* 80068D58: lui        $s1, %hi(D_8009AFD8) */
".word 0x8E31AFD8\n\t" /* 80068D5C: lw         $s1, %lo(D_8009AFD8)($s1) */
".word 0x3C12800A\n\t" /* 80068D60: lui        $s2, %hi(D_8009AFDC) */
".word 0x8E52AFDC\n\t" /* 80068D64: lw         $s2, %lo(D_8009AFDC)($s2) */
".word 0x02006021\n\t" /* 80068D68: addu       $t4, $s0, $zero */
".word 0x3C02800A\n\t" /* 80068D6C: lui        $v0, %hi(D_8009AFE5) */
".word 0x8042AFE5\n\t" /* 80068D70: lb         $v0, %lo(D_8009AFE5)($v0) */
".word 0x3C010200\n\t" /* 80068D74: lui        $at, (0x2000000 >> 16) */
".word 0x02018025\n\t" /* 80068D78: or         $s0, $s0, $at */
".word 0x1440000E\n\t" /* 80068D7C: bnez       $v0, .L80068DB8 */
".word 0x02006021\n\t" /* 80068D80: addu      $t4, $s0, $zero */
".word 0x8CF10008\n\t" /* 80068D84: lw         $s1, 0x8($a3) */
".word 0x3C010060\n\t" /* 80068D88: lui        $at, (0x600000 >> 16) */
".word 0x02218824\n\t" /* 80068D8C: and        $s1, $s1, $at */
".word 0x16200009\n\t" /* 80068D90: bnez       $s1, .L80068DB8 */
".word 0x00000000\n\t" /* 80068D94: nop */
".word 0x12400008\n\t" /* 80068D98: beqz       $s2, .L80068DBC */
".word 0x00000000\n\t" /* 80068D9C: nop */
".word 0x94F20006\n\t" /* 80068DA0: lhu        $s2, 0x6($a3) */
".word 0x3C0C800A\n\t" /* 80068DA4: lui        $t4, %hi(D_8009AFC4) */
".word 0x8D8CAFC4\n\t" /* 80068DA8: lw         $t4, %lo(D_8009AFC4)($t4) */
".word 0x00129400\n\t" /* 80068DAC: sll        $s2, $s2, 16 */
".word 0x0801A36F\n\t" /* 80068DB0: j          .L80068DBC */
".word 0x3C110020\n\t" /* 80068DB4: lui       $s1, (0x200000 >> 16) */
".L80068DB8:\n\t"
".word 0x24120000\n\t" /* 80068DB8: addiu      $s2, $zero, 0x0 */
".L80068DBC:\n\t"
".word 0x3C0D800A\n\t" /* 80068DBC: lui        $t5, %hi(D_8009AFE4) */
".word 0x81ADAFE4\n\t" /* 80068DC0: lb         $t5, %lo(D_8009AFE4)($t5) */
".word 0x00109E02\n\t" /* 80068DC4: srl        $s3, $s0, 24 */
".word 0x00139E00\n\t" /* 80068DC8: sll        $s3, $s3, 24 */
".word 0x24010001\n\t" /* 80068DCC: addiu      $at, $zero, 0x1 */
".word 0x11A10075\n\t" /* 80068DD0: beq        $t5, $at, .L80068FA8 */
".word 0x3C14E200\n\t" /* 80068DD4: lui       $s4, (0xE2000000 >> 16) */
".word 0x3C0D800A\n\t" /* 80068DD8: lui        $t5, %hi(D_8009AFE0) */
".word 0x8DADAFE0\n\t" /* 80068DDC: lw         $t5, %lo(D_8009AFE0)($t5) */
".word 0x8C85001C\n\t" /* 80068DE0: lw         $a1, 0x1C($a0) */
".word 0x8C860024\n\t" /* 80068DE4: lw         $a2, 0x24($a0) */
".word 0x11A00002\n\t" /* 80068DE8: beqz       $t5, .L80068DF4 */
".word 0x00000000\n\t" /* 80068DEC: nop */
".word 0x24C60004\n\t" /* 80068DF0: addiu      $a2, $a2, 0x4 */
".L80068DF4:\n\t"
".word 0x8C8D0004\n\t" /* 80068DF4: lw         $t5, 0x4($a0) */
".word 0x8C8E0008\n\t" /* 80068DF8: lw         $t6, 0x8($a0) */
".word 0x8DAF0004\n\t" /* 80068DFC: lw         $t7, 0x4($t5) */
".L80068E00:\n\t"
".word 0x2403FFFF\n\t" /* 80068E00: addiu      $v1, $zero, -0x1 */
".word 0x8CE80010\n\t" /* 80068E04: lw         $t0, 0x10($a3) */
".word 0x8CE90014\n\t" /* 80068E08: lw         $t1, 0x14($a3) */
".word 0x8CEA0018\n\t" /* 80068E0C: lw         $t2, 0x18($a3) */
".word 0x00086C02\n\t" /* 80068E10: srl        $t5, $t0, 16 */
".word 0x000D68C0\n\t" /* 80068E14: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 80068E18: addu       $t5, $t5, $a1 */
".word 0x8DA20004\n\t" /* 80068E1C: lw         $v0, 0x4($t5) */
".word 0x8DAD0000\n\t" /* 80068E20: lw         $t5, 0x0($t5) */
".word 0x1043005D\n\t" /* 80068E24: beq        $v0, $v1, .L80068F9C */
".word 0x48828800\n\t" /* 80068E28: mtc2      $v0, $17 ( handwritten instruction ) */
".word 0x488D6000\n\t" /* 80068E2C: mtc2       $t5, $12 ( handwritten instruction ) */
".word 0xAF2D000C\n\t" /* 80068E30: sw         $t5, 0xC($t9) */
".word 0x00096C02\n\t" /* 80068E34: srl        $t5, $t1, 16 */
".word 0x000D68C0\n\t" /* 80068E38: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 80068E3C: addu       $t5, $t5, $a1 */
".word 0x8DA20004\n\t" /* 80068E40: lw         $v0, 0x4($t5) */
".word 0x8DAD0000\n\t" /* 80068E44: lw         $t5, 0x0($t5) */
".word 0x10430054\n\t" /* 80068E48: beq        $v0, $v1, .L80068F9C */
".word 0x48829000\n\t" /* 80068E4C: mtc2      $v0, $18 ( handwritten instruction ) */
".word 0x488D6800\n\t" /* 80068E50: mtc2       $t5, $13 ( handwritten instruction ) */
".word 0xAF2D0018\n\t" /* 80068E54: sw         $t5, 0x18($t9) */
".word 0x000A6C02\n\t" /* 80068E58: srl        $t5, $t2, 16 */
".word 0x000D68C0\n\t" /* 80068E5C: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 80068E60: addu       $t5, $t5, $a1 */
".word 0x8DA20004\n\t" /* 80068E64: lw         $v0, 0x4($t5) */
".word 0x8DAD0000\n\t" /* 80068E68: lw         $t5, 0x0($t5) */
".word 0x1043004B\n\t" /* 80068E6C: beq        $v0, $v1, .L80068F9C */
".word 0x48829800\n\t" /* 80068E70: mtc2      $v0, $19 ( handwritten instruction ) */
".word 0x488D7000\n\t" /* 80068E74: mtc2       $t5, $14 ( handwritten instruction ) */
".word 0xAF2D0024\n\t" /* 80068E78: sw         $t5, 0x24($t9) */
".word 0x00084400\n\t" /* 80068E7C: sll        $t0, $t0, 16 */
".word 0x00084342\n\t" /* 80068E80: srl        $t0, $t0, 13 */
".word 0x4B400006\n\t" /* 80068E84: nclip */
".word 0x00094C00\n\t" /* 80068E88: sll        $t1, $t1, 16 */
".word 0x00094B42\n\t" /* 80068E8C: srl        $t1, $t1, 13 */
".word 0x000A5400\n\t" /* 80068E90: sll        $t2, $t2, 16 */
".word 0x000A5342\n\t" /* 80068E94: srl        $t2, $t2, 13 */
".word 0x01064021\n\t" /* 80068E98: addu       $t0, $t0, $a2 */
".word 0x4802C000\n\t" /* 80068E9C: mfc2       $v0, $24 ( handwritten instruction ) */
".word 0x01264821\n\t" /* 80068EA0: addu       $t1, $t1, $a2 */
".word 0x1840003D\n\t" /* 80068EA4: blez       $v0, .L80068F9C */
".word 0x01465021\n\t" /* 80068EA8: addu      $t2, $t2, $a2 */
".word 0x8D080000\n\t" /* 80068EAC: lw         $t0, 0x0($t0) */
".word 0x8D290000\n\t" /* 80068EB0: lw         $t1, 0x0($t1) */
".word 0x8D4A0000\n\t" /* 80068EB4: lw         $t2, 0x0($t2) */
".word 0x01134025\n\t" /* 80068EB8: or         $t0, $t0, $s3 */
".word 0xAF280008\n\t" /* 80068EBC: sw         $t0, 0x8($t9) */
".word 0xAF290014\n\t" /* 80068EC0: sw         $t1, 0x14($t9) */
".word 0xAF2A0020\n\t" /* 80068EC4: sw         $t2, 0x20($t9) */
".word 0x4B58002D\n\t" /* 80068EC8: avsz3 */
".word 0x8CF50000\n\t" /* 80068ECC: lw         $s5, 0x0($a3) */
".word 0x8CE80004\n\t" /* 80068ED0: lw         $t0, 0x4($a3) */
".word 0x8CE90008\n\t" /* 80068ED4: lw         $t1, 0x8($a3) */
".word 0x8CEA000C\n\t" /* 80068ED8: lw         $t2, 0xC($a3) */
".word 0x48023800\n\t" /* 80068EDC: mfc2       $v0, $7 ( handwritten instruction ) */
".word 0x3C010200\n\t" /* 80068EE0: lui        $at, (0x2000000 >> 16) */
".word 0x02011824\n\t" /* 80068EE4: and        $v1, $s0, $at */
".word 0x3C01FF9F\n\t" /* 80068EE8: lui        $at, (0xFF9FFFFF >> 16) */
".word 0x3421FFFF\n\t" /* 80068EEC: ori        $at, $at, (0xFF9FFFFF & 0xFFFF) */
".word 0x01214824\n\t" /* 80068EF0: and        $t1, $t1, $at */
".word 0x01314825\n\t" /* 80068EF4: or         $t1, $t1, $s1 */
".word 0x01C21006\n\t" /* 80068EF8: srlv       $v0, $v0, $t6 */
".word 0x00021080\n\t" /* 80068EFC: sll        $v0, $v0, 2 */
".word 0x004F1021\n\t" /* 80068F00: addu       $v0, $v0, $t7 */
".word 0x8C4D0000\n\t" /* 80068F04: lw         $t5, 0x0($v0) */
".L80068F08:\n\t"
".word 0xAF280010\n\t" /* 80068F08: sw         $t0, 0x10($t9) */
".word 0xAF29001C\n\t" /* 80068F0C: sw         $t1, 0x1C($t9) */
".word 0xAF2A0028\n\t" /* 80068F10: sw         $t2, 0x28($t9) */
".word 0xAF350004\n\t" /* 80068F14: sw         $s5, 0x4($t9) */
".word 0xAF34002C\n\t" /* 80068F18: sw         $s4, 0x2C($t9) */
".word 0x000D6A00\n\t" /* 80068F1C: sll        $t5, $t5, 8 */
".word 0x35AD000B\n\t" /* 80068F20: ori        $t5, $t5, 0xB */
".word 0x000D0A02\n\t" /* 80068F24: srl        $at, $t5, 8 */
".word 0x000D6E00\n\t" /* 80068F28: sll        $t5, $t5, 24 */
".word 0x01A16825\n\t" /* 80068F2C: or         $t5, $t5, $at */
".word 0xAF2D0000\n\t" /* 80068F30: sw         $t5, 0x0($t9) */
".word 0x00196A00\n\t" /* 80068F34: sll        $t5, $t9, 8 */
".word 0x000D6A02\n\t" /* 80068F38: srl        $t5, $t5, 8 */
".word 0x10600016\n\t" /* 80068F3C: beqz       $v1, .L80068F98 */
".word 0xAC4D0000\n\t" /* 80068F40: sw        $t5, 0x0($v0) */
".word 0x12400014\n\t" /* 80068F44: beqz       $s2, .L80068F98 */
".word 0x00084400\n\t" /* 80068F48: sll       $t0, $t0, 16 */
".word 0x00084402\n\t" /* 80068F4C: srl        $t0, $t0, 16 */
".word 0x01124025\n\t" /* 80068F50: or         $t0, $t0, $s2 */
".word 0x3C01FF9F\n\t" /* 80068F54: lui        $at, (0xFF9FFFFF >> 16) */
".word 0x3421FFFF\n\t" /* 80068F58: ori        $at, $at, (0xFF9FFFFF & 0xFFFF) */
".word 0x01214824\n\t" /* 80068F5C: and        $t1, $t1, $at */
".word 0x3C010040\n\t" /* 80068F60: lui        $at, (0x400000 >> 16) */
".word 0x01214825\n\t" /* 80068F64: or         $t1, $t1, $at */
".word 0x8F23000C\n\t" /* 80068F68: lw         $v1, 0xC($t9) */
".word 0xAF2C0038\n\t" /* 80068F6C: sw         $t4, 0x38($t9) */
".word 0xAF23003C\n\t" /* 80068F70: sw         $v1, 0x3C($t9) */
".word 0x8F230018\n\t" /* 80068F74: lw         $v1, 0x18($t9) */
".word 0xAF2C0044\n\t" /* 80068F78: sw         $t4, 0x44($t9) */
".word 0xAF230048\n\t" /* 80068F7C: sw         $v1, 0x48($t9) */
".word 0x8F230024\n\t" /* 80068F80: lw         $v1, 0x24($t9) */
".word 0xAF2C0050\n\t" /* 80068F84: sw         $t4, 0x50($t9) */
".word 0xAF230054\n\t" /* 80068F88: sw         $v1, 0x54($t9) */
".word 0x27390030\n\t" /* 80068F8C: addiu      $t9, $t9, 0x30 */
".word 0x0801A3C2\n\t" /* 80068F90: j          .L80068F08 */
".word 0x24030000\n\t" /* 80068F94: addiu     $v1, $zero, 0x0 */
".L80068F98:\n\t"
".word 0x27390030\n\t" /* 80068F98: addiu      $t9, $t9, 0x30 */
".L80068F9C:\n\t"
".word 0x2718FFFF\n\t" /* 80068F9C: addiu      $t8, $t8, -0x1 */
".word 0x1700FF97\n\t" /* 80068FA0: bnez       $t8, .L80068E00 */
".word 0x24E7001C\n\t" /* 80068FA4: addiu     $a3, $a3, 0x1C */
".L80068FA8:\n\t"
".word 0x8C900028\n\t" /* 80068FA8: lw         $s0, 0x28($a0) */
".word 0x8C91002C\n\t" /* 80068FAC: lw         $s1, 0x2C($a0) */
".word 0x8C920030\n\t" /* 80068FB0: lw         $s2, 0x30($a0) */
".word 0x8C930034\n\t" /* 80068FB4: lw         $s3, 0x34($a0) */
".word 0x8C940038\n\t" /* 80068FB8: lw         $s4, 0x38($a0) */
".word 0x8C95003C\n\t" /* 80068FBC: lw         $s5, 0x3C($a0) */
".word 0x8C820000\n\t" /* 80068FC0: lw         $v0, 0x0($a0) */
".word 0x3C018010\n\t" /* 80068FC4: lui        $at, %hi(D_800FE240) */
".word 0xAC39E240\n\t" /* 80068FC8: sw         $t9, %lo(D_800FE240)($at) */
".word 0x24420008\n\t" /* 80068FCC: addiu      $v0, $v0, 0x8 */
".word 0x03E00008\n\t" /* 80068FD0: jr         $ra */
".word 0x00000000\n\t" /* 80068FD4: nop */
    ".set reorder\n"
);
