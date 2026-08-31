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
    ".global func_80066B54\n"
    "func_80066B54:\n"
".word 0x8C870000\n\t" /* 80066B54: lw         $a3, 0x0($a0) */
".word 0x8C990010\n\t" /* 80066B58: lw         $t9, 0x10($a0) */
".word 0x94F80002\n\t" /* 80066B5C: lhu        $t8, 0x2($a3) */
".word 0x8CE60004\n\t" /* 80066B60: lw         $a2, 0x4($a3) */
".word 0x8C850014\n\t" /* 80066B64: lw         $a1, 0x14($a0) */
".word 0x00063080\n\t" /* 80066B68: sll        $a2, $a2, 2 */
".word 0xAC900020\n\t" /* 80066B6C: sw         $s0, 0x20($a0) */
".word 0xAC910024\n\t" /* 80066B70: sw         $s1, 0x24($a0) */
".word 0xAC920028\n\t" /* 80066B74: sw         $s2, 0x28($a0) */
".word 0xAC93002C\n\t" /* 80066B78: sw         $s3, 0x2C($a0) */
".word 0xAC940030\n\t" /* 80066B7C: sw         $s4, 0x30($a0) */
".word 0xAC950034\n\t" /* 80066B80: sw         $s5, 0x34($a0) */
".word 0xAC960038\n\t" /* 80066B84: sw         $s6, 0x38($a0) */
".word 0xAC97003C\n\t" /* 80066B88: sw         $s7, 0x3C($a0) */
".word 0x130000A6\n\t" /* 80066B8C: beqz       $t8, .L80066E28 */
".word 0x00A63821\n\t" /* 80066B90: addu      $a3, $a1, $a2 */
".word 0x3C10800A\n\t" /* 80066B94: lui        $s0, %hi(D_8009AFB0) */
".word 0x8E10AFB0\n\t" /* 80066B98: lw         $s0, %lo(D_8009AFB0)($s0) */
".word 0x3C11800A\n\t" /* 80066B9C: lui        $s1, %hi(D_8009AFD8) */
".word 0x8E31AFD8\n\t" /* 80066BA0: lw         $s1, %lo(D_8009AFD8)($s1) */
".word 0x3C12800A\n\t" /* 80066BA4: lui        $s2, %hi(D_8009AFDC) */
".word 0x8E52AFDC\n\t" /* 80066BA8: lw         $s2, %lo(D_8009AFDC)($s2) */
".word 0x3C16800A\n\t" /* 80066BAC: lui        $s6, %hi(D_8009AFE4) */
".word 0x82D6AFE4\n\t" /* 80066BB0: lb         $s6, %lo(D_8009AFE4)($s6) */
".word 0x3C17800A\n\t" /* 80066BB4: lui        $s7, %hi(D_8009AFE0) */
".word 0x8EF7AFE0\n\t" /* 80066BB8: lw         $s7, %lo(D_8009AFE0)($s7) */
".word 0x02006021\n\t" /* 80066BBC: addu       $t4, $s0, $zero */
".word 0x3C02800A\n\t" /* 80066BC0: lui        $v0, %hi(D_8009AFE5) */
".word 0x8042AFE5\n\t" /* 80066BC4: lb         $v0, %lo(D_8009AFE5)($v0) */
".word 0x3C010200\n\t" /* 80066BC8: lui        $at, (0x2000000 >> 16) */
".word 0x02018025\n\t" /* 80066BCC: or         $s0, $s0, $at */
".word 0x1440000E\n\t" /* 80066BD0: bnez       $v0, .L80066C0C */
".word 0x02006021\n\t" /* 80066BD4: addu      $t4, $s0, $zero */
".word 0x8CF10008\n\t" /* 80066BD8: lw         $s1, 0x8($a3) */
".word 0x3C010060\n\t" /* 80066BDC: lui        $at, (0x600000 >> 16) */
".word 0x02218824\n\t" /* 80066BE0: and        $s1, $s1, $at */
".word 0x16200009\n\t" /* 80066BE4: bnez       $s1, .L80066C0C */
".word 0x00000000\n\t" /* 80066BE8: nop */
".word 0x12400008\n\t" /* 80066BEC: beqz       $s2, .L80066C10 */
".word 0x00000000\n\t" /* 80066BF0: nop */
".word 0x94F20006\n\t" /* 80066BF4: lhu        $s2, 0x6($a3) */
".word 0x3C0C800A\n\t" /* 80066BF8: lui        $t4, %hi(D_8009AFC0) */
".word 0x8D8CAFC0\n\t" /* 80066BFC: lw         $t4, %lo(D_8009AFC0)($t4) */
".word 0x00129400\n\t" /* 80066C00: sll        $s2, $s2, 16 */
".word 0x08019B04\n\t" /* 80066C04: j          .L80066C10 */
".word 0x3C110020\n\t" /* 80066C08: lui       $s1, (0x200000 >> 16) */
".L80066C0C:\n\t"
".word 0x24120000\n\t" /* 80066C0C: addiu      $s2, $zero, 0x0 */
".L80066C10:\n\t"
".word 0x00109E02\n\t" /* 80066C10: srl        $s3, $s0, 24 */
".word 0x3C14E200\n\t" /* 80066C14: lui        $s4, (0xE2000000 >> 16) */
".word 0x8C850018\n\t" /* 80066C18: lw         $a1, 0x18($a0) */
".word 0x8C86001C\n\t" /* 80066C1C: lw         $a2, 0x1C($a0) */
".word 0x48903000\n\t" /* 80066C20: mtc2       $s0, $6 ( handwritten instruction ) */
".word 0x8C8D0004\n\t" /* 80066C24: lw         $t5, 0x4($a0) */
".word 0x8C8E0008\n\t" /* 80066C28: lw         $t6, 0x8($a0) */
".word 0x8DAF0004\n\t" /* 80066C2C: lw         $t7, 0x4($t5) */
".L80066C30:\n\t"
".word 0x8CE80014\n\t" /* 80066C30: lw         $t0, 0x14($a3) */
".word 0x8CE90018\n\t" /* 80066C34: lw         $t1, 0x18($a3) */
".word 0x00086C00\n\t" /* 80066C38: sll        $t5, $t0, 16 */
".word 0x000D6B42\n\t" /* 80066C3C: srl        $t5, $t5, 13 */
".word 0x01A56821\n\t" /* 80066C40: addu       $t5, $t5, $a1 */
".word 0xC9A00000\n\t" /* 80066C44: lwc2       $0, 0x0($t5) */
".word 0xC9A10004\n\t" /* 80066C48: lwc2       $1, 0x4($t5) */
".word 0x00086C02\n\t" /* 80066C4C: srl        $t5, $t0, 16 */
".word 0x000D68C0\n\t" /* 80066C50: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 80066C54: addu       $t5, $t5, $a1 */
".word 0xC9A20000\n\t" /* 80066C58: lwc2       $2, 0x0($t5) */
".word 0xC9A30004\n\t" /* 80066C5C: lwc2       $3, 0x4($t5) */
".word 0x00096C00\n\t" /* 80066C60: sll        $t5, $t1, 16 */
".word 0x000D6B42\n\t" /* 80066C64: srl        $t5, $t5, 13 */
".word 0x01A56821\n\t" /* 80066C68: addu       $t5, $t5, $a1 */
".word 0xC9A40000\n\t" /* 80066C6C: lwc2       $4, 0x0($t5) */
".word 0xC9A50004\n\t" /* 80066C70: lwc2       $5, 0x4($t5) */
".word 0x00095C02\n\t" /* 80066C74: srl        $t3, $t1, 16 */
".word 0x000B58C0\n\t" /* 80066C78: sll        $t3, $t3, 3 */
".word 0x4A280030\n\t" /* 80066C7C: rtpt */
".word 0x24010001\n\t" /* 80066C80: addiu      $at, $zero, 0x1 */
".word 0x12C10005\n\t" /* 80066C84: beq        $s6, $at, .L80066C9C */
".word 0x01656821\n\t" /* 80066C88: addu      $t5, $t3, $a1 */
".word 0x4842F800\n\t" /* 80066C8C: cfc2       $v0, $31 ( handwritten instruction ) */
".word 0x00000000\n\t" /* 80066C90: nop */
".word 0x04400061\n\t" /* 80066C94: bltz       $v0, .L80066E1C */
".word 0x00000000\n\t" /* 80066C98: nop */
".L80066C9C:\n\t"
".word 0xC9A00000\n\t" /* 80066C9C: lwc2       $0, 0x0($t5) */
".word 0xC9A10004\n\t" /* 80066CA0: lwc2       $1, 0x4($t5) */
".word 0xEB2C000C\n\t" /* 80066CA4: swc2       $12, 0xC($t9) */
".word 0xEB2D0014\n\t" /* 80066CA8: swc2       $13, 0x14($t9) */
".word 0xEB2E001C\n\t" /* 80066CAC: swc2       $14, 0x1C($t9) */
".word 0x00000000\n\t" /* 80066CB0: nop */
".word 0x00000000\n\t" /* 80066CB4: nop */
".word 0x4A180001\n\t" /* 80066CB8: rtps */
".word 0x94E80012\n\t" /* 80066CBC: lhu        $t0, 0x12($a3) */
".word 0x24010001\n\t" /* 80066CC0: addiu      $at, $zero, 0x1 */
".word 0x12C10005\n\t" /* 80066CC4: beq        $s6, $at, .L80066CDC */
".word 0x000840C0\n\t" /* 80066CC8: sll       $t0, $t0, 3 */
".word 0x4842F800\n\t" /* 80066CCC: cfc2       $v0, $31 ( handwritten instruction ) */
".word 0x00000000\n\t" /* 80066CD0: nop */
".word 0x04400051\n\t" /* 80066CD4: bltz       $v0, .L80066E1C */
".word 0x00000000\n\t" /* 80066CD8: nop */
".L80066CDC:\n\t"
".word 0x4B68002E\n\t" /* 80066CDC: avsz4 */
".word 0x8CF50000\n\t" /* 80066CE0: lw         $s5, 0x0($a3) */
".word 0x12C00010\n\t" /* 80066CE4: beqz       $s6, .L80066D28 */
".word 0x01066821\n\t" /* 80066CE8: addu      $t5, $t0, $a2 */
".word 0xC9A00000\n\t" /* 80066CEC: lwc2       $0, 0x0($t5) */
".word 0xC9A10004\n\t" /* 80066CF0: lwc2       $1, 0x4($t5) */
".word 0x00000000\n\t" /* 80066CF4: nop */
".word 0x00000000\n\t" /* 80066CF8: nop */
".word 0x4B08041B\n\t" /* 80066CFC: nccs */
".word 0x12E00003\n\t" /* 80066D00: beqz       $s7, .L80066D10 */
".word 0x00084042\n\t" /* 80066D04: srl       $t0, $t0, 1 */
".word 0x01174021\n\t" /* 80066D08: addu       $t0, $t0, $s7 */
".word 0xE9160000\n\t" /* 80066D0C: swc2       $22, 0x0($t0) */
".L80066D10:\n\t"
".word 0xEB360008\n\t" /* 80066D10: swc2       $22, 0x8($t9) */
".word 0x24010001\n\t" /* 80066D14: addiu      $at, $zero, 0x1 */
".word 0x12C10040\n\t" /* 80066D18: beq        $s6, $at, .L80066E1C */
".word 0x00000000\n\t" /* 80066D1C: nop */
".word 0x08019B50\n\t" /* 80066D20: j          .L80066D40 */
".word 0x00000000\n\t" /* 80066D24: nop */
".L80066D28:\n\t"
".word 0x00084042\n\t" /* 80066D28: srl        $t0, $t0, 1 */
".word 0x01171821\n\t" /* 80066D2C: addu       $v1, $t0, $s7 */
".word 0x8C680000\n\t" /* 80066D30: lw         $t0, 0x0($v1) */
".word 0x00000000\n\t" /* 80066D34: nop */
".word 0xAF280008\n\t" /* 80066D38: sw         $t0, 0x8($t9) */
".word 0xA333000B\n\t" /* 80066D3C: sb         $s3, 0xB($t9) */
".L80066D40:\n\t"
".word 0x8CE80004\n\t" /* 80066D40: lw         $t0, 0x4($a3) */
".word 0x8CE90008\n\t" /* 80066D44: lw         $t1, 0x8($a3) */
".word 0x8CEA000C\n\t" /* 80066D48: lw         $t2, 0xC($a3) */
".word 0x8CEB0010\n\t" /* 80066D4C: lw         $t3, 0x10($a3) */
".word 0x48023800\n\t" /* 80066D50: mfc2       $v0, $7 ( handwritten instruction ) */
".word 0x3C010200\n\t" /* 80066D54: lui        $at, (0x2000000 >> 16) */
".word 0x02011824\n\t" /* 80066D58: and        $v1, $s0, $at */
".word 0x3C01FF9F\n\t" /* 80066D5C: lui        $at, (0xFF9FFFFF >> 16) */
".word 0x3421FFFF\n\t" /* 80066D60: ori        $at, $at, (0xFF9FFFFF & 0xFFFF) */
".word 0x01214824\n\t" /* 80066D64: and        $t1, $t1, $at */
".word 0x01314825\n\t" /* 80066D68: or         $t1, $t1, $s1 */
".word 0x01C21006\n\t" /* 80066D6C: srlv       $v0, $v0, $t6 */
".word 0x00021080\n\t" /* 80066D70: sll        $v0, $v0, 2 */
".word 0x004F1021\n\t" /* 80066D74: addu       $v0, $v0, $t7 */
".word 0x8C4D0000\n\t" /* 80066D78: lw         $t5, 0x0($v0) */
".word 0xEB2E0024\n\t" /* 80066D7C: swc2       $14, 0x24($t9) */
".L80066D80:\n\t"
".word 0xAF280010\n\t" /* 80066D80: sw         $t0, 0x10($t9) */
".word 0xAF290018\n\t" /* 80066D84: sw         $t1, 0x18($t9) */
".word 0xAF2A0020\n\t" /* 80066D88: sw         $t2, 0x20($t9) */
".word 0xAF2B0028\n\t" /* 80066D8C: sw         $t3, 0x28($t9) */
".word 0xAF350004\n\t" /* 80066D90: sw         $s5, 0x4($t9) */
".word 0xAF34002C\n\t" /* 80066D94: sw         $s4, 0x2C($t9) */
".word 0x000D6A00\n\t" /* 80066D98: sll        $t5, $t5, 8 */
".word 0x35AD000B\n\t" /* 80066D9C: ori        $t5, $t5, 0xB */
".word 0x000D0A02\n\t" /* 80066DA0: srl        $at, $t5, 8 */
".word 0x000D6E00\n\t" /* 80066DA4: sll        $t5, $t5, 24 */
".word 0x01A16825\n\t" /* 80066DA8: or         $t5, $t5, $at */
".word 0xAF2D0000\n\t" /* 80066DAC: sw         $t5, 0x0($t9) */
".word 0x00196A00\n\t" /* 80066DB0: sll        $t5, $t9, 8 */
".word 0x000D6A02\n\t" /* 80066DB4: srl        $t5, $t5, 8 */
".word 0x10600017\n\t" /* 80066DB8: beqz       $v1, .L80066E18 */
".word 0xAC4D0000\n\t" /* 80066DBC: sw        $t5, 0x0($v0) */
".word 0x12400015\n\t" /* 80066DC0: beqz       $s2, .L80066E18 */
".word 0x00000000\n\t" /* 80066DC4: nop */
".word 0x3C01FF9F\n\t" /* 80066DC8: lui        $at, (0xFF9FFFFF >> 16) */
".word 0x3421FFFF\n\t" /* 80066DCC: ori        $at, $at, (0xFF9FFFFF & 0xFFFF) */
".word 0x01214824\n\t" /* 80066DD0: and        $t1, $t1, $at */
".word 0x3C010040\n\t" /* 80066DD4: lui        $at, (0x400000 >> 16) */
".word 0x01214825\n\t" /* 80066DD8: or         $t1, $t1, $at */
".word 0x8F23000C\n\t" /* 80066DDC: lw         $v1, 0xC($t9) */
".word 0x00084400\n\t" /* 80066DE0: sll        $t0, $t0, 16 */
".word 0xAF23003C\n\t" /* 80066DE4: sw         $v1, 0x3C($t9) */
".word 0x8F230014\n\t" /* 80066DE8: lw         $v1, 0x14($t9) */
".word 0x00084402\n\t" /* 80066DEC: srl        $t0, $t0, 16 */
".word 0xAF230044\n\t" /* 80066DF0: sw         $v1, 0x44($t9) */
".word 0x8F23001C\n\t" /* 80066DF4: lw         $v1, 0x1C($t9) */
".word 0x01124025\n\t" /* 80066DF8: or         $t0, $t0, $s2 */
".word 0xAF23004C\n\t" /* 80066DFC: sw         $v1, 0x4C($t9) */
".word 0x8F230024\n\t" /* 80066E00: lw         $v1, 0x24($t9) */
".word 0xAF2C0038\n\t" /* 80066E04: sw         $t4, 0x38($t9) */
".word 0xAF230054\n\t" /* 80066E08: sw         $v1, 0x54($t9) */
".word 0x27390030\n\t" /* 80066E0C: addiu      $t9, $t9, 0x30 */
".word 0x08019B60\n\t" /* 80066E10: j          .L80066D80 */
".word 0x24030000\n\t" /* 80066E14: addiu     $v1, $zero, 0x0 */
".L80066E18:\n\t"
".word 0x27390030\n\t" /* 80066E18: addiu      $t9, $t9, 0x30 */
".L80066E1C:\n\t"
".word 0x2718FFFF\n\t" /* 80066E1C: addiu      $t8, $t8, -0x1 */
".word 0x1700FF83\n\t" /* 80066E20: bnez       $t8, .L80066C30 */
".word 0x24E7001C\n\t" /* 80066E24: addiu     $a3, $a3, 0x1C */
".L80066E28:\n\t"
".word 0x8C900020\n\t" /* 80066E28: lw         $s0, 0x20($a0) */
".word 0x8C910024\n\t" /* 80066E2C: lw         $s1, 0x24($a0) */
".word 0x8C920028\n\t" /* 80066E30: lw         $s2, 0x28($a0) */
".word 0x8C93002C\n\t" /* 80066E34: lw         $s3, 0x2C($a0) */
".word 0x8C940030\n\t" /* 80066E38: lw         $s4, 0x30($a0) */
".word 0x8C950034\n\t" /* 80066E3C: lw         $s5, 0x34($a0) */
".word 0x8C960038\n\t" /* 80066E40: lw         $s6, 0x38($a0) */
".word 0x8C97003C\n\t" /* 80066E44: lw         $s7, 0x3C($a0) */
".word 0x8C820000\n\t" /* 80066E48: lw         $v0, 0x0($a0) */
".word 0x3C018010\n\t" /* 80066E4C: lui        $at, %hi(D_800FE240) */
".word 0xAC39E240\n\t" /* 80066E50: sw         $t9, %lo(D_800FE240)($at) */
".word 0x24420008\n\t" /* 80066E54: addiu      $v0, $v0, 0x8 */
".word 0x03E00008\n\t" /* 80066E58: jr         $ra */
".word 0x00000000\n\t" /* 80066E5C: nop */
    ".set reorder\n"
);
