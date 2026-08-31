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
    ".global func_80066564\n"
    "func_80066564:\n"
".word 0x8C870000\n\t" /* 80066564: lw         $a3, 0x0($a0) */
".word 0x8C990010\n\t" /* 80066568: lw         $t9, 0x10($a0) */
".word 0x94F80002\n\t" /* 8006656C: lhu        $t8, 0x2($a3) */
".word 0x8CE60004\n\t" /* 80066570: lw         $a2, 0x4($a3) */
".word 0x8C850014\n\t" /* 80066574: lw         $a1, 0x14($a0) */
".word 0x00063080\n\t" /* 80066578: sll        $a2, $a2, 2 */
".word 0xAC900020\n\t" /* 8006657C: sw         $s0, 0x20($a0) */
".word 0xAC910024\n\t" /* 80066580: sw         $s1, 0x24($a0) */
".word 0xAC920028\n\t" /* 80066584: sw         $s2, 0x28($a0) */
".word 0xAC93002C\n\t" /* 80066588: sw         $s3, 0x2C($a0) */
".word 0xAC940030\n\t" /* 8006658C: sw         $s4, 0x30($a0) */
".word 0xAC950034\n\t" /* 80066590: sw         $s5, 0x34($a0) */
".word 0xAC960038\n\t" /* 80066594: sw         $s6, 0x38($a0) */
".word 0xAC97003C\n\t" /* 80066598: sw         $s7, 0x3C($a0) */
".word 0x13000094\n\t" /* 8006659C: beqz       $t8, .L800667F0 */
".word 0x00A63821\n\t" /* 800665A0: addu      $a3, $a1, $a2 */
".word 0x3C10800A\n\t" /* 800665A4: lui        $s0, %hi(D_8009AFAC) */
".word 0x8E10AFAC\n\t" /* 800665A8: lw         $s0, %lo(D_8009AFAC)($s0) */
".word 0x3C11800A\n\t" /* 800665AC: lui        $s1, %hi(D_8009AFD8) */
".word 0x8E31AFD8\n\t" /* 800665B0: lw         $s1, %lo(D_8009AFD8)($s1) */
".word 0x3C12800A\n\t" /* 800665B4: lui        $s2, %hi(D_8009AFDC) */
".word 0x8E52AFDC\n\t" /* 800665B8: lw         $s2, %lo(D_8009AFDC)($s2) */
".word 0x3C16800A\n\t" /* 800665BC: lui        $s6, %hi(D_8009AFE4) */
".word 0x82D6AFE4\n\t" /* 800665C0: lb         $s6, %lo(D_8009AFE4)($s6) */
".word 0x3C17800A\n\t" /* 800665C4: lui        $s7, %hi(D_8009AFE0) */
".word 0x8EF7AFE0\n\t" /* 800665C8: lw         $s7, %lo(D_8009AFE0)($s7) */
".word 0x02006021\n\t" /* 800665CC: addu       $t4, $s0, $zero */
".word 0x3C02800A\n\t" /* 800665D0: lui        $v0, %hi(D_8009AFE5) */
".word 0x8042AFE5\n\t" /* 800665D4: lb         $v0, %lo(D_8009AFE5)($v0) */
".word 0x3C010200\n\t" /* 800665D8: lui        $at, (0x2000000 >> 16) */
".word 0x02018025\n\t" /* 800665DC: or         $s0, $s0, $at */
".word 0x1440000E\n\t" /* 800665E0: bnez       $v0, .L8006661C */
".word 0x02006021\n\t" /* 800665E4: addu      $t4, $s0, $zero */
".word 0x8CF10008\n\t" /* 800665E8: lw         $s1, 0x8($a3) */
".word 0x3C010060\n\t" /* 800665EC: lui        $at, (0x600000 >> 16) */
".word 0x02218824\n\t" /* 800665F0: and        $s1, $s1, $at */
".word 0x16200009\n\t" /* 800665F4: bnez       $s1, .L8006661C */
".word 0x00000000\n\t" /* 800665F8: nop */
".word 0x12400008\n\t" /* 800665FC: beqz       $s2, .L80066620 */
".word 0x00000000\n\t" /* 80066600: nop */
".word 0x94F20006\n\t" /* 80066604: lhu        $s2, 0x6($a3) */
".word 0x3C0C800A\n\t" /* 80066608: lui        $t4, %hi(D_8009AFBC) */
".word 0x8D8CAFBC\n\t" /* 8006660C: lw         $t4, %lo(D_8009AFBC)($t4) */
".word 0x00129400\n\t" /* 80066610: sll        $s2, $s2, 16 */
".word 0x08019988\n\t" /* 80066614: j          .L80066620 */
".word 0x3C110020\n\t" /* 80066618: lui       $s1, (0x200000 >> 16) */
".L8006661C:\n\t"
".word 0x24120000\n\t" /* 8006661C: addiu      $s2, $zero, 0x0 */
".L80066620:\n\t"
".word 0x00109E02\n\t" /* 80066620: srl        $s3, $s0, 24 */
".word 0x3C14E200\n\t" /* 80066624: lui        $s4, (0xE2000000 >> 16) */
".word 0x8C850018\n\t" /* 80066628: lw         $a1, 0x18($a0) */
".word 0x8C86001C\n\t" /* 8006662C: lw         $a2, 0x1C($a0) */
".word 0x48903000\n\t" /* 80066630: mtc2       $s0, $6 ( handwritten instruction ) */
".word 0x8C8D0004\n\t" /* 80066634: lw         $t5, 0x4($a0) */
".word 0x8C8E0008\n\t" /* 80066638: lw         $t6, 0x8($a0) */
".word 0x8DAF0004\n\t" /* 8006663C: lw         $t7, 0x4($t5) */
".L80066640:\n\t"
".word 0x8CE80010\n\t" /* 80066640: lw         $t0, 0x10($a3) */
".word 0x8CE90014\n\t" /* 80066644: lw         $t1, 0x14($a3) */
".word 0x00086C02\n\t" /* 80066648: srl        $t5, $t0, 16 */
".word 0x000D68C0\n\t" /* 8006664C: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 80066650: addu       $t5, $t5, $a1 */
".word 0xC9A00000\n\t" /* 80066654: lwc2       $0, 0x0($t5) */
".word 0xC9A10004\n\t" /* 80066658: lwc2       $1, 0x4($t5) */
".word 0x00096C00\n\t" /* 8006665C: sll        $t5, $t1, 16 */
".word 0x000D6B42\n\t" /* 80066660: srl        $t5, $t5, 13 */
".word 0x01A56821\n\t" /* 80066664: addu       $t5, $t5, $a1 */
".word 0xC9A20000\n\t" /* 80066668: lwc2       $2, 0x0($t5) */
".word 0xC9A30004\n\t" /* 8006666C: lwc2       $3, 0x4($t5) */
".word 0x00096C02\n\t" /* 80066670: srl        $t5, $t1, 16 */
".word 0x000D68C0\n\t" /* 80066674: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 80066678: addu       $t5, $t5, $a1 */
".word 0xC9A40000\n\t" /* 8006667C: lwc2       $4, 0x0($t5) */
".word 0xC9A50004\n\t" /* 80066680: lwc2       $5, 0x4($t5) */
".word 0x00084400\n\t" /* 80066684: sll        $t0, $t0, 16 */
".word 0x00084342\n\t" /* 80066688: srl        $t0, $t0, 13 */
".word 0x4A280030\n\t" /* 8006668C: rtpt */
".word 0x24010001\n\t" /* 80066690: addiu      $at, $zero, 0x1 */
".word 0x12C10005\n\t" /* 80066694: beq        $s6, $at, .L800666AC */
".word 0x00000000\n\t" /* 80066698: nop */
".word 0x4842F800\n\t" /* 8006669C: cfc2       $v0, $31 ( handwritten instruction ) */
".word 0x00000000\n\t" /* 800666A0: nop */
".word 0x0440004F\n\t" /* 800666A4: bltz       $v0, .L800667E4 */
".word 0x00000000\n\t" /* 800666A8: nop */
".L800666AC:\n\t"
".word 0x4B58002D\n\t" /* 800666AC: avsz3 */
".word 0x8CF50000\n\t" /* 800666B0: lw         $s5, 0x0($a3) */
".word 0x12C00010\n\t" /* 800666B4: beqz       $s6, .L800666F8 */
".word 0x01066821\n\t" /* 800666B8: addu      $t5, $t0, $a2 */
".word 0xC9A00000\n\t" /* 800666BC: lwc2       $0, 0x0($t5) */
".word 0xC9A10004\n\t" /* 800666C0: lwc2       $1, 0x4($t5) */
".word 0x00000000\n\t" /* 800666C4: nop */
".word 0x00000000\n\t" /* 800666C8: nop */
".word 0x4B08041B\n\t" /* 800666CC: nccs */
".word 0x12E00003\n\t" /* 800666D0: beqz       $s7, .L800666E0 */
".word 0x00084042\n\t" /* 800666D4: srl       $t0, $t0, 1 */
".word 0x01174021\n\t" /* 800666D8: addu       $t0, $t0, $s7 */
".word 0xE9160000\n\t" /* 800666DC: swc2       $22, 0x0($t0) */
".L800666E0:\n\t"
".word 0xEB360008\n\t" /* 800666E0: swc2       $22, 0x8($t9) */
".word 0x24010001\n\t" /* 800666E4: addiu      $at, $zero, 0x1 */
".word 0x12C1003E\n\t" /* 800666E8: beq        $s6, $at, .L800667E4 */
".word 0x00000000\n\t" /* 800666EC: nop */
".word 0x080199C4\n\t" /* 800666F0: j          .L80066710 */
".word 0x00000000\n\t" /* 800666F4: nop */
".L800666F8:\n\t"
".word 0x00084042\n\t" /* 800666F8: srl        $t0, $t0, 1 */
".word 0x01171821\n\t" /* 800666FC: addu       $v1, $t0, $s7 */
".word 0x8C680000\n\t" /* 80066700: lw         $t0, 0x0($v1) */
".word 0x00000000\n\t" /* 80066704: nop */
".word 0xAF280008\n\t" /* 80066708: sw         $t0, 0x8($t9) */
".word 0xA333000B\n\t" /* 8006670C: sb         $s3, 0xB($t9) */
".L80066710:\n\t"
".word 0x8CE80004\n\t" /* 80066710: lw         $t0, 0x4($a3) */
".word 0x8CE90008\n\t" /* 80066714: lw         $t1, 0x8($a3) */
".word 0x8CEA000C\n\t" /* 80066718: lw         $t2, 0xC($a3) */
".word 0x48023800\n\t" /* 8006671C: mfc2       $v0, $7 ( handwritten instruction ) */
".word 0x3C010200\n\t" /* 80066720: lui        $at, (0x2000000 >> 16) */
".word 0x02011824\n\t" /* 80066724: and        $v1, $s0, $at */
".word 0x3C01FF9F\n\t" /* 80066728: lui        $at, (0xFF9FFFFF >> 16) */
".word 0x3421FFFF\n\t" /* 8006672C: ori        $at, $at, (0xFF9FFFFF & 0xFFFF) */
".word 0x01214824\n\t" /* 80066730: and        $t1, $t1, $at */
".word 0x01314825\n\t" /* 80066734: or         $t1, $t1, $s1 */
".word 0x01C21006\n\t" /* 80066738: srlv       $v0, $v0, $t6 */
".word 0x00021080\n\t" /* 8006673C: sll        $v0, $v0, 2 */
".word 0x004F1021\n\t" /* 80066740: addu       $v0, $v0, $t7 */
".word 0x8C4D0000\n\t" /* 80066744: lw         $t5, 0x0($v0) */
".word 0xEB2C000C\n\t" /* 80066748: swc2       $12, 0xC($t9) */
".word 0xEB2D0014\n\t" /* 8006674C: swc2       $13, 0x14($t9) */
".word 0xEB2E001C\n\t" /* 80066750: swc2       $14, 0x1C($t9) */
".L80066754:\n\t"
".word 0xAF280010\n\t" /* 80066754: sw         $t0, 0x10($t9) */
".word 0xAF290018\n\t" /* 80066758: sw         $t1, 0x18($t9) */
".word 0xAF2A0020\n\t" /* 8006675C: sw         $t2, 0x20($t9) */
".word 0xAF350004\n\t" /* 80066760: sw         $s5, 0x4($t9) */
".word 0xAF340024\n\t" /* 80066764: sw         $s4, 0x24($t9) */
".word 0x000D6A00\n\t" /* 80066768: sll        $t5, $t5, 8 */
".word 0x35AD0009\n\t" /* 8006676C: ori        $t5, $t5, 0x9 */
".word 0x000D0A02\n\t" /* 80066770: srl        $at, $t5, 8 */
".word 0x000D6E00\n\t" /* 80066774: sll        $t5, $t5, 24 */
".word 0x01A16825\n\t" /* 80066778: or         $t5, $t5, $at */
".word 0xAF2D0000\n\t" /* 8006677C: sw         $t5, 0x0($t9) */
".word 0x00196A00\n\t" /* 80066780: sll        $t5, $t9, 8 */
".word 0x000D6A02\n\t" /* 80066784: srl        $t5, $t5, 8 */
".word 0x10600015\n\t" /* 80066788: beqz       $v1, .L800667E0 */
".word 0xAC4D0000\n\t" /* 8006678C: sw        $t5, 0x0($v0) */
".word 0x12400013\n\t" /* 80066790: beqz       $s2, .L800667E0 */
".word 0x00000000\n\t" /* 80066794: nop */
".word 0x3C01FF9F\n\t" /* 80066798: lui        $at, (0xFF9FFFFF >> 16) */
".word 0x3421FFFF\n\t" /* 8006679C: ori        $at, $at, (0xFF9FFFFF & 0xFFFF) */
".word 0x01214824\n\t" /* 800667A0: and        $t1, $t1, $at */
".word 0x3C010040\n\t" /* 800667A4: lui        $at, (0x400000 >> 16) */
".word 0x01214825\n\t" /* 800667A8: or         $t1, $t1, $at */
".word 0x8F23000C\n\t" /* 800667AC: lw         $v1, 0xC($t9) */
".word 0x00084400\n\t" /* 800667B0: sll        $t0, $t0, 16 */
".word 0xAF230034\n\t" /* 800667B4: sw         $v1, 0x34($t9) */
".word 0x8F230014\n\t" /* 800667B8: lw         $v1, 0x14($t9) */
".word 0x00084402\n\t" /* 800667BC: srl        $t0, $t0, 16 */
".word 0xAF23003C\n\t" /* 800667C0: sw         $v1, 0x3C($t9) */
".word 0x8F23001C\n\t" /* 800667C4: lw         $v1, 0x1C($t9) */
".word 0x01124025\n\t" /* 800667C8: or         $t0, $t0, $s2 */
".word 0xAF230044\n\t" /* 800667CC: sw         $v1, 0x44($t9) */
".word 0xAF2C0030\n\t" /* 800667D0: sw         $t4, 0x30($t9) */
".word 0x27390028\n\t" /* 800667D4: addiu      $t9, $t9, 0x28 */
".word 0x080199D5\n\t" /* 800667D8: j          .L80066754 */
".word 0x24030000\n\t" /* 800667DC: addiu     $v1, $zero, 0x0 */
".L800667E0:\n\t"
".word 0x27390028\n\t" /* 800667E0: addiu      $t9, $t9, 0x28 */
".L800667E4:\n\t"
".word 0x2718FFFF\n\t" /* 800667E4: addiu      $t8, $t8, -0x1 */
".word 0x1700FF95\n\t" /* 800667E8: bnez       $t8, .L80066640 */
".word 0x24E70018\n\t" /* 800667EC: addiu     $a3, $a3, 0x18 */
".L800667F0:\n\t"
".word 0x8C900020\n\t" /* 800667F0: lw         $s0, 0x20($a0) */
".word 0x8C910024\n\t" /* 800667F4: lw         $s1, 0x24($a0) */
".word 0x8C920028\n\t" /* 800667F8: lw         $s2, 0x28($a0) */
".word 0x8C93002C\n\t" /* 800667FC: lw         $s3, 0x2C($a0) */
".word 0x8C940030\n\t" /* 80066800: lw         $s4, 0x30($a0) */
".word 0x8C950034\n\t" /* 80066804: lw         $s5, 0x34($a0) */
".word 0x8C960038\n\t" /* 80066808: lw         $s6, 0x38($a0) */
".word 0x8C97003C\n\t" /* 8006680C: lw         $s7, 0x3C($a0) */
".word 0x8C820000\n\t" /* 80066810: lw         $v0, 0x0($a0) */
".word 0x3C018010\n\t" /* 80066814: lui        $at, %hi(D_800FE240) */
".word 0xAC39E240\n\t" /* 80066818: sw         $t9, %lo(D_800FE240)($at) */
".word 0x24420008\n\t" /* 8006681C: addiu      $v0, $v0, 0x8 */
".word 0x03E00008\n\t" /* 80066820: jr         $ra */
".word 0x00000000\n\t" /* 80066824: nop */
    ".set reorder\n"
);
