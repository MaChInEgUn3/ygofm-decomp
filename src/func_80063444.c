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
    ".global func_80063444\n"
    "func_80063444:\n"
".word 0x8C870000\n\t" /* 80063444: lw         $a3, 0x0($a0) */
".word 0x8C990010\n\t" /* 80063448: lw         $t9, 0x10($a0) */
".word 0x94F80002\n\t" /* 8006344C: lhu        $t8, 0x2($a3) */
".word 0x8CE60004\n\t" /* 80063450: lw         $a2, 0x4($a3) */
".word 0x8C850014\n\t" /* 80063454: lw         $a1, 0x14($a0) */
".word 0x00063080\n\t" /* 80063458: sll        $a2, $a2, 2 */
".word 0xAC900020\n\t" /* 8006345C: sw         $s0, 0x20($a0) */
".word 0xAC910024\n\t" /* 80063460: sw         $s1, 0x24($a0) */
".word 0xAC920028\n\t" /* 80063464: sw         $s2, 0x28($a0) */
".word 0xAC93002C\n\t" /* 80063468: sw         $s3, 0x2C($a0) */
".word 0xAC940030\n\t" /* 8006346C: sw         $s4, 0x30($a0) */
".word 0xAC950034\n\t" /* 80063470: sw         $s5, 0x34($a0) */
".word 0xAC960038\n\t" /* 80063474: sw         $s6, 0x38($a0) */
".word 0xAC97003C\n\t" /* 80063478: sw         $s7, 0x3C($a0) */
".word 0x1300007D\n\t" /* 8006347C: beqz       $t8, .L80063674 */
".word 0x00A63821\n\t" /* 80063480: addu      $a3, $a1, $a2 */
".word 0x3C10800A\n\t" /* 80063484: lui        $s0, %hi(D_8009AFAC) */
".word 0x8E10AFAC\n\t" /* 80063488: lw         $s0, %lo(D_8009AFAC)($s0) */
".word 0x3C11800A\n\t" /* 8006348C: lui        $s1, %hi(D_8009AFD8) */
".word 0x8E31AFD8\n\t" /* 80063490: lw         $s1, %lo(D_8009AFD8)($s1) */
".word 0x3C12800A\n\t" /* 80063494: lui        $s2, %hi(D_8009AFDC) */
".word 0x8E52AFDC\n\t" /* 80063498: lw         $s2, %lo(D_8009AFDC)($s2) */
".word 0x3C16800A\n\t" /* 8006349C: lui        $s6, %hi(D_8009AFE4) */
".word 0x82D6AFE4\n\t" /* 800634A0: lb         $s6, %lo(D_8009AFE4)($s6) */
".word 0x3C17800A\n\t" /* 800634A4: lui        $s7, %hi(D_8009AFE0) */
".word 0x8EF7AFE0\n\t" /* 800634A8: lw         $s7, %lo(D_8009AFE0)($s7) */
".word 0x02006021\n\t" /* 800634AC: addu       $t4, $s0, $zero */
".word 0x00109E02\n\t" /* 800634B0: srl        $s3, $s0, 24 */
".word 0x3C14E200\n\t" /* 800634B4: lui        $s4, (0xE2000000 >> 16) */
".word 0x8C850018\n\t" /* 800634B8: lw         $a1, 0x18($a0) */
".word 0x8C86001C\n\t" /* 800634BC: lw         $a2, 0x1C($a0) */
".word 0x48903000\n\t" /* 800634C0: mtc2       $s0, $6 ( handwritten instruction ) */
".word 0x8C8D0004\n\t" /* 800634C4: lw         $t5, 0x4($a0) */
".word 0x8C8E0008\n\t" /* 800634C8: lw         $t6, 0x8($a0) */
".word 0x8DAF0004\n\t" /* 800634CC: lw         $t7, 0x4($t5) */
".L800634D0:\n\t"
".word 0x8CE80010\n\t" /* 800634D0: lw         $t0, 0x10($a3) */
".word 0x8CE90014\n\t" /* 800634D4: lw         $t1, 0x14($a3) */
".word 0x00086C02\n\t" /* 800634D8: srl        $t5, $t0, 16 */
".word 0x000D68C0\n\t" /* 800634DC: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 800634E0: addu       $t5, $t5, $a1 */
".word 0xC9A00000\n\t" /* 800634E4: lwc2       $0, 0x0($t5) */
".word 0xC9A10004\n\t" /* 800634E8: lwc2       $1, 0x4($t5) */
".word 0x00096C00\n\t" /* 800634EC: sll        $t5, $t1, 16 */
".word 0x000D6B42\n\t" /* 800634F0: srl        $t5, $t5, 13 */
".word 0x01A56821\n\t" /* 800634F4: addu       $t5, $t5, $a1 */
".word 0xC9A20000\n\t" /* 800634F8: lwc2       $2, 0x0($t5) */
".word 0xC9A30004\n\t" /* 800634FC: lwc2       $3, 0x4($t5) */
".word 0x00096C02\n\t" /* 80063500: srl        $t5, $t1, 16 */
".word 0x000D68C0\n\t" /* 80063504: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 80063508: addu       $t5, $t5, $a1 */
".word 0xC9A40000\n\t" /* 8006350C: lwc2       $4, 0x0($t5) */
".word 0xC9A50004\n\t" /* 80063510: lwc2       $5, 0x4($t5) */
".word 0x00084400\n\t" /* 80063514: sll        $t0, $t0, 16 */
".word 0x00084342\n\t" /* 80063518: srl        $t0, $t0, 13 */
".word 0x4A280030\n\t" /* 8006351C: rtpt */
".word 0x24010001\n\t" /* 80063520: addiu      $at, $zero, 0x1 */
".word 0x12C10005\n\t" /* 80063524: beq        $s6, $at, .L8006353C */
".word 0x00000000\n\t" /* 80063528: nop */
".word 0x4842F800\n\t" /* 8006352C: cfc2       $v0, $31 ( handwritten instruction ) */
".word 0x00000000\n\t" /* 80063530: nop */
".word 0x0440004C\n\t" /* 80063534: bltz       $v0, .L80063668 */
".word 0x00000000\n\t" /* 80063538: nop */
".L8006353C:\n\t"
".word 0x4B58002D\n\t" /* 8006353C: avsz3 */
".word 0x8CF50000\n\t" /* 80063540: lw         $s5, 0x0($a3) */
".word 0x12C00010\n\t" /* 80063544: beqz       $s6, .L80063588 */
".word 0x01066821\n\t" /* 80063548: addu      $t5, $t0, $a2 */
".word 0xC9A00000\n\t" /* 8006354C: lwc2       $0, 0x0($t5) */
".word 0xC9A10004\n\t" /* 80063550: lwc2       $1, 0x4($t5) */
".word 0x00000000\n\t" /* 80063554: nop */
".word 0x00000000\n\t" /* 80063558: nop */
".word 0x4B08041B\n\t" /* 8006355C: nccs */
".word 0x12E00003\n\t" /* 80063560: beqz       $s7, .L80063570 */
".word 0x00084042\n\t" /* 80063564: srl       $t0, $t0, 1 */
".word 0x01174021\n\t" /* 80063568: addu       $t0, $t0, $s7 */
".word 0xE9160000\n\t" /* 8006356C: swc2       $22, 0x0($t0) */
".L80063570:\n\t"
".word 0xEB360008\n\t" /* 80063570: swc2       $22, 0x8($t9) */
".word 0x24010001\n\t" /* 80063574: addiu      $at, $zero, 0x1 */
".word 0x12C1003B\n\t" /* 80063578: beq        $s6, $at, .L80063668 */
".word 0x00000000\n\t" /* 8006357C: nop */
".word 0x08018D68\n\t" /* 80063580: j          .L800635A0 */
".word 0x00000000\n\t" /* 80063584: nop */
".L80063588:\n\t"
".word 0x00084042\n\t" /* 80063588: srl        $t0, $t0, 1 */
".word 0x01171821\n\t" /* 8006358C: addu       $v1, $t0, $s7 */
".word 0x8C680000\n\t" /* 80063590: lw         $t0, 0x0($v1) */
".word 0x00000000\n\t" /* 80063594: nop */
".word 0xAF280008\n\t" /* 80063598: sw         $t0, 0x8($t9) */
".word 0xA333000B\n\t" /* 8006359C: sb         $s3, 0xB($t9) */
".L800635A0:\n\t"
".word 0x8CE80004\n\t" /* 800635A0: lw         $t0, 0x4($a3) */
".word 0x8CE90008\n\t" /* 800635A4: lw         $t1, 0x8($a3) */
".word 0x8CEA000C\n\t" /* 800635A8: lw         $t2, 0xC($a3) */
".word 0x48023800\n\t" /* 800635AC: mfc2       $v0, $7 ( handwritten instruction ) */
".word 0x3C010200\n\t" /* 800635B0: lui        $at, (0x2000000 >> 16) */
".word 0x02011824\n\t" /* 800635B4: and        $v1, $s0, $at */
".word 0x01314825\n\t" /* 800635B8: or         $t1, $t1, $s1 */
".word 0x01C21006\n\t" /* 800635BC: srlv       $v0, $v0, $t6 */
".word 0x00021080\n\t" /* 800635C0: sll        $v0, $v0, 2 */
".word 0x004F1021\n\t" /* 800635C4: addu       $v0, $v0, $t7 */
".word 0x8C4D0000\n\t" /* 800635C8: lw         $t5, 0x0($v0) */
".word 0xEB2C000C\n\t" /* 800635CC: swc2       $12, 0xC($t9) */
".word 0xEB2D0014\n\t" /* 800635D0: swc2       $13, 0x14($t9) */
".word 0xEB2E001C\n\t" /* 800635D4: swc2       $14, 0x1C($t9) */
".L800635D8:\n\t"
".word 0xAF280010\n\t" /* 800635D8: sw         $t0, 0x10($t9) */
".word 0xAF290018\n\t" /* 800635DC: sw         $t1, 0x18($t9) */
".word 0xAF2A0020\n\t" /* 800635E0: sw         $t2, 0x20($t9) */
".word 0xAF350004\n\t" /* 800635E4: sw         $s5, 0x4($t9) */
".word 0xAF340024\n\t" /* 800635E8: sw         $s4, 0x24($t9) */
".word 0x000D6A00\n\t" /* 800635EC: sll        $t5, $t5, 8 */
".word 0x35AD0009\n\t" /* 800635F0: ori        $t5, $t5, 0x9 */
".word 0x000D0A02\n\t" /* 800635F4: srl        $at, $t5, 8 */
".word 0x000D6E00\n\t" /* 800635F8: sll        $t5, $t5, 24 */
".word 0x01A16825\n\t" /* 800635FC: or         $t5, $t5, $at */
".word 0xAF2D0000\n\t" /* 80063600: sw         $t5, 0x0($t9) */
".word 0x00196A00\n\t" /* 80063604: sll        $t5, $t9, 8 */
".word 0x000D6A02\n\t" /* 80063608: srl        $t5, $t5, 8 */
".word 0x10600015\n\t" /* 8006360C: beqz       $v1, .L80063664 */
".word 0xAC4D0000\n\t" /* 80063610: sw        $t5, 0x0($v0) */
".word 0x12400013\n\t" /* 80063614: beqz       $s2, .L80063664 */
".word 0x00000000\n\t" /* 80063618: nop */
".word 0x3C01FF9F\n\t" /* 8006361C: lui        $at, (0xFF9FFFFF >> 16) */
".word 0x3421FFFF\n\t" /* 80063620: ori        $at, $at, (0xFF9FFFFF & 0xFFFF) */
".word 0x01214824\n\t" /* 80063624: and        $t1, $t1, $at */
".word 0x3C010040\n\t" /* 80063628: lui        $at, (0x400000 >> 16) */
".word 0x01214825\n\t" /* 8006362C: or         $t1, $t1, $at */
".word 0x8F23000C\n\t" /* 80063630: lw         $v1, 0xC($t9) */
".word 0x00084400\n\t" /* 80063634: sll        $t0, $t0, 16 */
".word 0xAF230034\n\t" /* 80063638: sw         $v1, 0x34($t9) */
".word 0x8F230014\n\t" /* 8006363C: lw         $v1, 0x14($t9) */
".word 0x00084402\n\t" /* 80063640: srl        $t0, $t0, 16 */
".word 0xAF23003C\n\t" /* 80063644: sw         $v1, 0x3C($t9) */
".word 0x8F23001C\n\t" /* 80063648: lw         $v1, 0x1C($t9) */
".word 0x01124025\n\t" /* 8006364C: or         $t0, $t0, $s2 */
".word 0xAF230044\n\t" /* 80063650: sw         $v1, 0x44($t9) */
".word 0xAF2C0030\n\t" /* 80063654: sw         $t4, 0x30($t9) */
".word 0x27390028\n\t" /* 80063658: addiu      $t9, $t9, 0x28 */
".word 0x08018D76\n\t" /* 8006365C: j          .L800635D8 */
".word 0x24030000\n\t" /* 80063660: addiu     $v1, $zero, 0x0 */
".L80063664:\n\t"
".word 0x27390028\n\t" /* 80063664: addiu      $t9, $t9, 0x28 */
".L80063668:\n\t"
".word 0x2718FFFF\n\t" /* 80063668: addiu      $t8, $t8, -0x1 */
".word 0x1700FF98\n\t" /* 8006366C: bnez       $t8, .L800634D0 */
".word 0x24E70018\n\t" /* 80063670: addiu     $a3, $a3, 0x18 */
".L80063674:\n\t"
".word 0x8C900020\n\t" /* 80063674: lw         $s0, 0x20($a0) */
".word 0x8C910024\n\t" /* 80063678: lw         $s1, 0x24($a0) */
".word 0x8C920028\n\t" /* 8006367C: lw         $s2, 0x28($a0) */
".word 0x8C93002C\n\t" /* 80063680: lw         $s3, 0x2C($a0) */
".word 0x8C940030\n\t" /* 80063684: lw         $s4, 0x30($a0) */
".word 0x8C950034\n\t" /* 80063688: lw         $s5, 0x34($a0) */
".word 0x8C960038\n\t" /* 8006368C: lw         $s6, 0x38($a0) */
".word 0x8C97003C\n\t" /* 80063690: lw         $s7, 0x3C($a0) */
".word 0x8C820000\n\t" /* 80063694: lw         $v0, 0x0($a0) */
".word 0x3C018010\n\t" /* 80063698: lui        $at, %hi(D_800FE240) */
".word 0xAC39E240\n\t" /* 8006369C: sw         $t9, %lo(D_800FE240)($at) */
".word 0x24420008\n\t" /* 800636A0: addiu      $v0, $v0, 0x8 */
".word 0x03E00008\n\t" /* 800636A4: jr         $ra */
".word 0x00000000\n\t" /* 800636A8: nop */
    ".set reorder\n"
);
