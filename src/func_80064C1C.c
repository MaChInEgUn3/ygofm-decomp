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
    ".global func_80064C1C\n"
    "func_80064C1C:\n"
".word 0x8C870000\n\t" /* 80064C1C: lw         $a3, 0x0($a0) */
".word 0x8C990010\n\t" /* 80064C20: lw         $t9, 0x10($a0) */
".word 0x94F80002\n\t" /* 80064C24: lhu        $t8, 0x2($a3) */
".word 0x8CE60004\n\t" /* 80064C28: lw         $a2, 0x4($a3) */
".word 0x8C850014\n\t" /* 80064C2C: lw         $a1, 0x14($a0) */
".word 0x00063080\n\t" /* 80064C30: sll        $a2, $a2, 2 */
".word 0xAC900020\n\t" /* 80064C34: sw         $s0, 0x20($a0) */
".word 0xAC910024\n\t" /* 80064C38: sw         $s1, 0x24($a0) */
".word 0xAC920028\n\t" /* 80064C3C: sw         $s2, 0x28($a0) */
".word 0xAC93002C\n\t" /* 80064C40: sw         $s3, 0x2C($a0) */
".word 0xAC940030\n\t" /* 80064C44: sw         $s4, 0x30($a0) */
".word 0xAC950034\n\t" /* 80064C48: sw         $s5, 0x34($a0) */
".word 0xAC960038\n\t" /* 80064C4C: sw         $s6, 0x38($a0) */
".word 0xAC97003C\n\t" /* 80064C50: sw         $s7, 0x3C($a0) */
".word 0x13000099\n\t" /* 80064C54: beqz       $t8, .L80064EBC */
".word 0x00A63821\n\t" /* 80064C58: addu      $a3, $a1, $a2 */
".word 0x3C10800A\n\t" /* 80064C5C: lui        $s0, %hi(D_8009AFAC) */
".word 0x8E10AFAC\n\t" /* 80064C60: lw         $s0, %lo(D_8009AFAC)($s0) */
".word 0x3C11800A\n\t" /* 80064C64: lui        $s1, %hi(D_8009AFD8) */
".word 0x8E31AFD8\n\t" /* 80064C68: lw         $s1, %lo(D_8009AFD8)($s1) */
".word 0x3C12800A\n\t" /* 80064C6C: lui        $s2, %hi(D_8009AFDC) */
".word 0x8E52AFDC\n\t" /* 80064C70: lw         $s2, %lo(D_8009AFDC)($s2) */
".word 0x3C16800A\n\t" /* 80064C74: lui        $s6, %hi(D_8009AFE4) */
".word 0x82D6AFE4\n\t" /* 80064C78: lb         $s6, %lo(D_8009AFE4)($s6) */
".word 0x3C17800A\n\t" /* 80064C7C: lui        $s7, %hi(D_8009AFE0) */
".word 0x8EF7AFE0\n\t" /* 80064C80: lw         $s7, %lo(D_8009AFE0)($s7) */
".word 0x02006021\n\t" /* 80064C84: addu       $t4, $s0, $zero */
".word 0x3C02800A\n\t" /* 80064C88: lui        $v0, %hi(D_8009AFE5) */
".word 0x8042AFE5\n\t" /* 80064C8C: lb         $v0, %lo(D_8009AFE5)($v0) */
".word 0x3C010200\n\t" /* 80064C90: lui        $at, (0x2000000 >> 16) */
".word 0x02018025\n\t" /* 80064C94: or         $s0, $s0, $at */
".word 0x1440000E\n\t" /* 80064C98: bnez       $v0, .L80064CD4 */
".word 0x02006021\n\t" /* 80064C9C: addu      $t4, $s0, $zero */
".word 0x8CF10008\n\t" /* 80064CA0: lw         $s1, 0x8($a3) */
".word 0x3C010060\n\t" /* 80064CA4: lui        $at, (0x600000 >> 16) */
".word 0x02218824\n\t" /* 80064CA8: and        $s1, $s1, $at */
".word 0x16200009\n\t" /* 80064CAC: bnez       $s1, .L80064CD4 */
".word 0x00000000\n\t" /* 80064CB0: nop */
".word 0x12400008\n\t" /* 80064CB4: beqz       $s2, .L80064CD8 */
".word 0x00000000\n\t" /* 80064CB8: nop */
".word 0x94F20006\n\t" /* 80064CBC: lhu        $s2, 0x6($a3) */
".word 0x3C0C800A\n\t" /* 80064CC0: lui        $t4, %hi(D_8009AFBC) */
".word 0x8D8CAFBC\n\t" /* 80064CC4: lw         $t4, %lo(D_8009AFBC)($t4) */
".word 0x00129400\n\t" /* 80064CC8: sll        $s2, $s2, 16 */
".word 0x08019336\n\t" /* 80064CCC: j          .L80064CD8 */
".word 0x3C110020\n\t" /* 80064CD0: lui       $s1, (0x200000 >> 16) */
".L80064CD4:\n\t"
".word 0x24120000\n\t" /* 80064CD4: addiu      $s2, $zero, 0x0 */
".L80064CD8:\n\t"
".word 0x00109E02\n\t" /* 80064CD8: srl        $s3, $s0, 24 */
".word 0x3C14E200\n\t" /* 80064CDC: lui        $s4, (0xE2000000 >> 16) */
".word 0x8C850018\n\t" /* 80064CE0: lw         $a1, 0x18($a0) */
".word 0x8C86001C\n\t" /* 80064CE4: lw         $a2, 0x1C($a0) */
".word 0x48903000\n\t" /* 80064CE8: mtc2       $s0, $6 ( handwritten instruction ) */
".word 0x8C8D0004\n\t" /* 80064CEC: lw         $t5, 0x4($a0) */
".word 0x8C8E0008\n\t" /* 80064CF0: lw         $t6, 0x8($a0) */
".word 0x8DAF0004\n\t" /* 80064CF4: lw         $t7, 0x4($t5) */
".L80064CF8:\n\t"
".word 0x8CE80010\n\t" /* 80064CF8: lw         $t0, 0x10($a3) */
".word 0x8CE90014\n\t" /* 80064CFC: lw         $t1, 0x14($a3) */
".word 0x00086C02\n\t" /* 80064D00: srl        $t5, $t0, 16 */
".word 0x000D68C0\n\t" /* 80064D04: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 80064D08: addu       $t5, $t5, $a1 */
".word 0xC9A00000\n\t" /* 80064D0C: lwc2       $0, 0x0($t5) */
".word 0xC9A10004\n\t" /* 80064D10: lwc2       $1, 0x4($t5) */
".word 0x00096C00\n\t" /* 80064D14: sll        $t5, $t1, 16 */
".word 0x000D6B42\n\t" /* 80064D18: srl        $t5, $t5, 13 */
".word 0x01A56821\n\t" /* 80064D1C: addu       $t5, $t5, $a1 */
".word 0xC9A20000\n\t" /* 80064D20: lwc2       $2, 0x0($t5) */
".word 0xC9A30004\n\t" /* 80064D24: lwc2       $3, 0x4($t5) */
".word 0x00096C02\n\t" /* 80064D28: srl        $t5, $t1, 16 */
".word 0x000D68C0\n\t" /* 80064D2C: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 80064D30: addu       $t5, $t5, $a1 */
".word 0xC9A40000\n\t" /* 80064D34: lwc2       $4, 0x0($t5) */
".word 0xC9A50004\n\t" /* 80064D38: lwc2       $5, 0x4($t5) */
".word 0x00084400\n\t" /* 80064D3C: sll        $t0, $t0, 16 */
".word 0x00084342\n\t" /* 80064D40: srl        $t0, $t0, 13 */
".word 0x4A280030\n\t" /* 80064D44: rtpt */
".word 0x24010001\n\t" /* 80064D48: addiu      $at, $zero, 0x1 */
".word 0x12C1000A\n\t" /* 80064D4C: beq        $s6, $at, .L80064D78 */
".word 0x00000000\n\t" /* 80064D50: nop */
".word 0x4842F800\n\t" /* 80064D54: cfc2       $v0, $31 ( handwritten instruction ) */
".word 0x00000000\n\t" /* 80064D58: nop */
".word 0x04400054\n\t" /* 80064D5C: bltz       $v0, .L80064EB0 */
".word 0x00000000\n\t" /* 80064D60: nop */
".word 0x4B400006\n\t" /* 80064D64: nclip */
".word 0x4802C000\n\t" /* 80064D68: mfc2       $v0, $24 ( handwritten instruction ) */
".word 0x00000000\n\t" /* 80064D6C: nop */
".word 0x1840004F\n\t" /* 80064D70: blez       $v0, .L80064EB0 */
".word 0x00000000\n\t" /* 80064D74: nop */
".L80064D78:\n\t"
".word 0x4B58002D\n\t" /* 80064D78: avsz3 */
".word 0x8CF50000\n\t" /* 80064D7C: lw         $s5, 0x0($a3) */
".word 0x12C00010\n\t" /* 80064D80: beqz       $s6, .L80064DC4 */
".word 0x01066821\n\t" /* 80064D84: addu      $t5, $t0, $a2 */
".word 0xC9A00000\n\t" /* 80064D88: lwc2       $0, 0x0($t5) */
".word 0xC9A10004\n\t" /* 80064D8C: lwc2       $1, 0x4($t5) */
".word 0x00000000\n\t" /* 80064D90: nop */
".word 0x00000000\n\t" /* 80064D94: nop */
".word 0x4B08041B\n\t" /* 80064D98: nccs */
".word 0x12E00003\n\t" /* 80064D9C: beqz       $s7, .L80064DAC */
".word 0x00084042\n\t" /* 80064DA0: srl       $t0, $t0, 1 */
".word 0x01174021\n\t" /* 80064DA4: addu       $t0, $t0, $s7 */
".word 0xE9160000\n\t" /* 80064DA8: swc2       $22, 0x0($t0) */
".L80064DAC:\n\t"
".word 0xEB360008\n\t" /* 80064DAC: swc2       $22, 0x8($t9) */
".word 0x24010001\n\t" /* 80064DB0: addiu      $at, $zero, 0x1 */
".word 0x12C1003E\n\t" /* 80064DB4: beq        $s6, $at, .L80064EB0 */
".word 0x00000000\n\t" /* 80064DB8: nop */
".word 0x08019377\n\t" /* 80064DBC: j          .L80064DDC */
".word 0x00000000\n\t" /* 80064DC0: nop */
".L80064DC4:\n\t"
".word 0x00084042\n\t" /* 80064DC4: srl        $t0, $t0, 1 */
".word 0x01171821\n\t" /* 80064DC8: addu       $v1, $t0, $s7 */
".word 0x8C680000\n\t" /* 80064DCC: lw         $t0, 0x0($v1) */
".word 0x00000000\n\t" /* 80064DD0: nop */
".word 0xAF280008\n\t" /* 80064DD4: sw         $t0, 0x8($t9) */
".word 0xA333000B\n\t" /* 80064DD8: sb         $s3, 0xB($t9) */
".L80064DDC:\n\t"
".word 0x8CE80004\n\t" /* 80064DDC: lw         $t0, 0x4($a3) */
".word 0x8CE90008\n\t" /* 80064DE0: lw         $t1, 0x8($a3) */
".word 0x8CEA000C\n\t" /* 80064DE4: lw         $t2, 0xC($a3) */
".word 0x48023800\n\t" /* 80064DE8: mfc2       $v0, $7 ( handwritten instruction ) */
".word 0x3C010200\n\t" /* 80064DEC: lui        $at, (0x2000000 >> 16) */
".word 0x02011824\n\t" /* 80064DF0: and        $v1, $s0, $at */
".word 0x3C01FF9F\n\t" /* 80064DF4: lui        $at, (0xFF9FFFFF >> 16) */
".word 0x3421FFFF\n\t" /* 80064DF8: ori        $at, $at, (0xFF9FFFFF & 0xFFFF) */
".word 0x01214824\n\t" /* 80064DFC: and        $t1, $t1, $at */
".word 0x01314825\n\t" /* 80064E00: or         $t1, $t1, $s1 */
".word 0x01C21006\n\t" /* 80064E04: srlv       $v0, $v0, $t6 */
".word 0x00021080\n\t" /* 80064E08: sll        $v0, $v0, 2 */
".word 0x004F1021\n\t" /* 80064E0C: addu       $v0, $v0, $t7 */
".word 0x8C4D0000\n\t" /* 80064E10: lw         $t5, 0x0($v0) */
".word 0xEB2C000C\n\t" /* 80064E14: swc2       $12, 0xC($t9) */
".word 0xEB2D0014\n\t" /* 80064E18: swc2       $13, 0x14($t9) */
".word 0xEB2E001C\n\t" /* 80064E1C: swc2       $14, 0x1C($t9) */
".L80064E20:\n\t"
".word 0xAF280010\n\t" /* 80064E20: sw         $t0, 0x10($t9) */
".word 0xAF290018\n\t" /* 80064E24: sw         $t1, 0x18($t9) */
".word 0xAF2A0020\n\t" /* 80064E28: sw         $t2, 0x20($t9) */
".word 0xAF350004\n\t" /* 80064E2C: sw         $s5, 0x4($t9) */
".word 0xAF340024\n\t" /* 80064E30: sw         $s4, 0x24($t9) */
".word 0x000D6A00\n\t" /* 80064E34: sll        $t5, $t5, 8 */
".word 0x35AD0009\n\t" /* 80064E38: ori        $t5, $t5, 0x9 */
".word 0x000D0A02\n\t" /* 80064E3C: srl        $at, $t5, 8 */
".word 0x000D6E00\n\t" /* 80064E40: sll        $t5, $t5, 24 */
".word 0x01A16825\n\t" /* 80064E44: or         $t5, $t5, $at */
".word 0xAF2D0000\n\t" /* 80064E48: sw         $t5, 0x0($t9) */
".word 0x00196A00\n\t" /* 80064E4C: sll        $t5, $t9, 8 */
".word 0x000D6A02\n\t" /* 80064E50: srl        $t5, $t5, 8 */
".word 0x10600015\n\t" /* 80064E54: beqz       $v1, .L80064EAC */
".word 0xAC4D0000\n\t" /* 80064E58: sw        $t5, 0x0($v0) */
".word 0x12400013\n\t" /* 80064E5C: beqz       $s2, .L80064EAC */
".word 0x00000000\n\t" /* 80064E60: nop */
".word 0x3C01FF9F\n\t" /* 80064E64: lui        $at, (0xFF9FFFFF >> 16) */
".word 0x3421FFFF\n\t" /* 80064E68: ori        $at, $at, (0xFF9FFFFF & 0xFFFF) */
".word 0x01214824\n\t" /* 80064E6C: and        $t1, $t1, $at */
".word 0x3C010040\n\t" /* 80064E70: lui        $at, (0x400000 >> 16) */
".word 0x01214825\n\t" /* 80064E74: or         $t1, $t1, $at */
".word 0x8F23000C\n\t" /* 80064E78: lw         $v1, 0xC($t9) */
".word 0x00084400\n\t" /* 80064E7C: sll        $t0, $t0, 16 */
".word 0xAF230034\n\t" /* 80064E80: sw         $v1, 0x34($t9) */
".word 0x8F230014\n\t" /* 80064E84: lw         $v1, 0x14($t9) */
".word 0x00084402\n\t" /* 80064E88: srl        $t0, $t0, 16 */
".word 0xAF23003C\n\t" /* 80064E8C: sw         $v1, 0x3C($t9) */
".word 0x8F23001C\n\t" /* 80064E90: lw         $v1, 0x1C($t9) */
".word 0x01124025\n\t" /* 80064E94: or         $t0, $t0, $s2 */
".word 0xAF230044\n\t" /* 80064E98: sw         $v1, 0x44($t9) */
".word 0xAF2C0030\n\t" /* 80064E9C: sw         $t4, 0x30($t9) */
".word 0x27390028\n\t" /* 80064EA0: addiu      $t9, $t9, 0x28 */
".word 0x08019388\n\t" /* 80064EA4: j          .L80064E20 */
".word 0x24030000\n\t" /* 80064EA8: addiu     $v1, $zero, 0x0 */
".L80064EAC:\n\t"
".word 0x27390028\n\t" /* 80064EAC: addiu      $t9, $t9, 0x28 */
".L80064EB0:\n\t"
".word 0x2718FFFF\n\t" /* 80064EB0: addiu      $t8, $t8, -0x1 */
".word 0x1700FF90\n\t" /* 80064EB4: bnez       $t8, .L80064CF8 */
".word 0x24E70018\n\t" /* 80064EB8: addiu     $a3, $a3, 0x18 */
".L80064EBC:\n\t"
".word 0x8C900020\n\t" /* 80064EBC: lw         $s0, 0x20($a0) */
".word 0x8C910024\n\t" /* 80064EC0: lw         $s1, 0x24($a0) */
".word 0x8C920028\n\t" /* 80064EC4: lw         $s2, 0x28($a0) */
".word 0x8C93002C\n\t" /* 80064EC8: lw         $s3, 0x2C($a0) */
".word 0x8C940030\n\t" /* 80064ECC: lw         $s4, 0x30($a0) */
".word 0x8C950034\n\t" /* 80064ED0: lw         $s5, 0x34($a0) */
".word 0x8C960038\n\t" /* 80064ED4: lw         $s6, 0x38($a0) */
".word 0x8C97003C\n\t" /* 80064ED8: lw         $s7, 0x3C($a0) */
".word 0x8C820000\n\t" /* 80064EDC: lw         $v0, 0x0($a0) */
".word 0x3C018010\n\t" /* 80064EE0: lui        $at, %hi(D_800FE240) */
".word 0xAC39E240\n\t" /* 80064EE4: sw         $t9, %lo(D_800FE240)($at) */
".word 0x24420008\n\t" /* 80064EE8: addiu      $v0, $v0, 0x8 */
".word 0x03E00008\n\t" /* 80064EEC: jr         $ra */
".word 0x00000000\n\t" /* 80064EF0: nop */
    ".set reorder\n"
);
