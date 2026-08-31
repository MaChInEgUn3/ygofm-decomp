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
    ".global func_8006151C\n"
    "func_8006151C:\n"
".word 0x8C870000\n\t" /* 8006151C: lw         $a3, 0x0($a0) */
".word 0x8C990010\n\t" /* 80061520: lw         $t9, 0x10($a0) */
".word 0x94F80002\n\t" /* 80061524: lhu        $t8, 0x2($a3) */
".word 0x8CE60004\n\t" /* 80061528: lw         $a2, 0x4($a3) */
".word 0x8C850014\n\t" /* 8006152C: lw         $a1, 0x14($a0) */
".word 0x00063080\n\t" /* 80061530: sll        $a2, $a2, 2 */
".word 0xAC900020\n\t" /* 80061534: sw         $s0, 0x20($a0) */
".word 0xAC910024\n\t" /* 80061538: sw         $s1, 0x24($a0) */
".word 0xAC920028\n\t" /* 8006153C: sw         $s2, 0x28($a0) */
".word 0xAC93002C\n\t" /* 80061540: sw         $s3, 0x2C($a0) */
".word 0xAC960030\n\t" /* 80061544: sw         $s6, 0x30($a0) */
".word 0xAC970034\n\t" /* 80061548: sw         $s7, 0x34($a0) */
".word 0x13000098\n\t" /* 8006154C: beqz       $t8, .L800617B0 */
".word 0x00A63821\n\t" /* 80061550: addu      $a3, $a1, $a2 */
".word 0x3C10800A\n\t" /* 80061554: lui        $s0, %hi(D_8009AFB4) */
".word 0x8E10AFB4\n\t" /* 80061558: lw         $s0, %lo(D_8009AFB4)($s0) */
".word 0x3C11800A\n\t" /* 8006155C: lui        $s1, %hi(D_8009AFD8) */
".word 0x8E31AFD8\n\t" /* 80061560: lw         $s1, %lo(D_8009AFD8)($s1) */
".word 0x3C12800A\n\t" /* 80061564: lui        $s2, %hi(D_8009AFDC) */
".word 0x8E52AFDC\n\t" /* 80061568: lw         $s2, %lo(D_8009AFDC)($s2) */
".word 0x3C16800A\n\t" /* 8006156C: lui        $s6, %hi(D_8009AFE4) */
".word 0x82D6AFE4\n\t" /* 80061570: lb         $s6, %lo(D_8009AFE4)($s6) */
".word 0x3C17800A\n\t" /* 80061574: lui        $s7, %hi(D_8009AFE0) */
".word 0x8EF7AFE0\n\t" /* 80061578: lw         $s7, %lo(D_8009AFE0)($s7) */
".word 0x02006021\n\t" /* 8006157C: addu       $t4, $s0, $zero */
".word 0x00109E02\n\t" /* 80061580: srl        $s3, $s0, 24 */
".word 0x8C850018\n\t" /* 80061584: lw         $a1, 0x18($a0) */
".word 0x8C86001C\n\t" /* 80061588: lw         $a2, 0x1C($a0) */
".word 0x48903000\n\t" /* 8006158C: mtc2       $s0, $6 ( handwritten instruction ) */
".word 0x8C8D0004\n\t" /* 80061590: lw         $t5, 0x4($a0) */
".word 0x8C8E0008\n\t" /* 80061594: lw         $t6, 0x8($a0) */
".word 0x8DAF0004\n\t" /* 80061598: lw         $t7, 0x4($t5) */
".L8006159C:\n\t"
".word 0x8CE8000C\n\t" /* 8006159C: lw         $t0, 0xC($a3) */
".word 0x8CE90010\n\t" /* 800615A0: lw         $t1, 0x10($a3) */
".word 0x8CEA0014\n\t" /* 800615A4: lw         $t2, 0x14($a3) */
".word 0x00086C02\n\t" /* 800615A8: srl        $t5, $t0, 16 */
".word 0x000D68C0\n\t" /* 800615AC: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 800615B0: addu       $t5, $t5, $a1 */
".word 0xC9A00000\n\t" /* 800615B4: lwc2       $0, 0x0($t5) */
".word 0xC9A10004\n\t" /* 800615B8: lwc2       $1, 0x4($t5) */
".word 0x00096C02\n\t" /* 800615BC: srl        $t5, $t1, 16 */
".word 0x000D68C0\n\t" /* 800615C0: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 800615C4: addu       $t5, $t5, $a1 */
".word 0xC9A20000\n\t" /* 800615C8: lwc2       $2, 0x0($t5) */
".word 0xC9A30004\n\t" /* 800615CC: lwc2       $3, 0x4($t5) */
".word 0x000A6C02\n\t" /* 800615D0: srl        $t5, $t2, 16 */
".word 0x000D68C0\n\t" /* 800615D4: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 800615D8: addu       $t5, $t5, $a1 */
".word 0xC9A40000\n\t" /* 800615DC: lwc2       $4, 0x0($t5) */
".word 0xC9A50004\n\t" /* 800615E0: lwc2       $5, 0x4($t5) */
".word 0x00084400\n\t" /* 800615E4: sll        $t0, $t0, 16 */
".word 0x00084342\n\t" /* 800615E8: srl        $t0, $t0, 13 */
".word 0x4A280030\n\t" /* 800615EC: rtpt */
".word 0x00094C00\n\t" /* 800615F0: sll        $t1, $t1, 16 */
".word 0x00094B42\n\t" /* 800615F4: srl        $t1, $t1, 13 */
".word 0x000A5400\n\t" /* 800615F8: sll        $t2, $t2, 16 */
".word 0x24010001\n\t" /* 800615FC: addiu      $at, $zero, 0x1 */
".word 0x12C1000A\n\t" /* 80061600: beq        $s6, $at, .L8006162C */
".word 0x000A5342\n\t" /* 80061604: srl       $t2, $t2, 13 */
".word 0x4842F800\n\t" /* 80061608: cfc2       $v0, $31 ( handwritten instruction ) */
".word 0x00000000\n\t" /* 8006160C: nop */
".word 0x04400064\n\t" /* 80061610: bltz       $v0, .L800617A4 */
".word 0x00000000\n\t" /* 80061614: nop */
".word 0x4B400006\n\t" /* 80061618: nclip */
".word 0x4802C000\n\t" /* 8006161C: mfc2       $v0, $24 ( handwritten instruction ) */
".word 0x00000000\n\t" /* 80061620: nop */
".word 0x1840005F\n\t" /* 80061624: blez       $v0, .L800617A4 */
".word 0x00000000\n\t" /* 80061628: nop */
".L8006162C:\n\t"
".word 0x4B58002D\n\t" /* 8006162C: avsz3 */
".word 0x12C0001E\n\t" /* 80061630: beqz       $s6, .L800616AC */
".word 0x01066821\n\t" /* 80061634: addu      $t5, $t0, $a2 */
".word 0xC9A00000\n\t" /* 80061638: lwc2       $0, 0x0($t5) */
".word 0xC9A10004\n\t" /* 8006163C: lwc2       $1, 0x4($t5) */
".word 0x01266821\n\t" /* 80061640: addu       $t5, $t1, $a2 */
".word 0xC9A20000\n\t" /* 80061644: lwc2       $2, 0x0($t5) */
".word 0xC9A30004\n\t" /* 80061648: lwc2       $3, 0x4($t5) */
".word 0x01466821\n\t" /* 8006164C: addu       $t5, $t2, $a2 */
".word 0xC9A40000\n\t" /* 80061650: lwc2       $4, 0x0($t5) */
".word 0xC9A50004\n\t" /* 80061654: lwc2       $5, 0x4($t5) */
".word 0x00000000\n\t" /* 80061658: nop */
".word 0x00000000\n\t" /* 8006165C: nop */
".word 0x4B18043F\n\t" /* 80061660: ncct */
".word 0x12E00009\n\t" /* 80061664: beqz       $s7, .L8006168C */
".word 0x00084042\n\t" /* 80061668: srl       $t0, $t0, 1 */
".word 0x01174021\n\t" /* 8006166C: addu       $t0, $t0, $s7 */
".word 0x00094842\n\t" /* 80061670: srl        $t1, $t1, 1 */
".word 0x01374821\n\t" /* 80061674: addu       $t1, $t1, $s7 */
".word 0x000A5042\n\t" /* 80061678: srl        $t2, $t2, 1 */
".word 0x01575021\n\t" /* 8006167C: addu       $t2, $t2, $s7 */
".word 0xE9140000\n\t" /* 80061680: swc2       $20, 0x0($t0) */
".word 0xE9350000\n\t" /* 80061684: swc2       $21, 0x0($t1) */
".word 0xE9560000\n\t" /* 80061688: swc2       $22, 0x0($t2) */
".L8006168C:\n\t"
".word 0xEB340004\n\t" /* 8006168C: swc2       $20, 0x4($t9) */
".word 0xEB350010\n\t" /* 80061690: swc2       $21, 0x10($t9) */
".word 0xEB36001C\n\t" /* 80061694: swc2       $22, 0x1C($t9) */
".word 0x24010001\n\t" /* 80061698: addiu      $at, $zero, 0x1 */
".word 0x12C10041\n\t" /* 8006169C: beq        $s6, $at, .L800617A4 */
".word 0x00000000\n\t" /* 800616A0: nop */
".word 0x080185B8\n\t" /* 800616A4: j          .L800616E0 */
".word 0x00000000\n\t" /* 800616A8: nop */
".L800616AC:\n\t"
".word 0x00084042\n\t" /* 800616AC: srl        $t0, $t0, 1 */
".word 0x01171821\n\t" /* 800616B0: addu       $v1, $t0, $s7 */
".word 0x8C680000\n\t" /* 800616B4: lw         $t0, 0x0($v1) */
".word 0x00094842\n\t" /* 800616B8: srl        $t1, $t1, 1 */
".word 0x01371821\n\t" /* 800616BC: addu       $v1, $t1, $s7 */
".word 0x8C690000\n\t" /* 800616C0: lw         $t1, 0x0($v1) */
".word 0x000A5042\n\t" /* 800616C4: srl        $t2, $t2, 1 */
".word 0x01571821\n\t" /* 800616C8: addu       $v1, $t2, $s7 */
".word 0x8C6A0000\n\t" /* 800616CC: lw         $t2, 0x0($v1) */
".word 0xAF280004\n\t" /* 800616D0: sw         $t0, 0x4($t9) */
".word 0xAF290010\n\t" /* 800616D4: sw         $t1, 0x10($t9) */
".word 0xAF2A001C\n\t" /* 800616D8: sw         $t2, 0x1C($t9) */
".word 0xA3330007\n\t" /* 800616DC: sb         $s3, 0x7($t9) */
".L800616E0:\n\t"
".word 0x8CE80000\n\t" /* 800616E0: lw         $t0, 0x0($a3) */
".word 0x8CE90004\n\t" /* 800616E4: lw         $t1, 0x4($a3) */
".word 0x8CEA0008\n\t" /* 800616E8: lw         $t2, 0x8($a3) */
".word 0x48023800\n\t" /* 800616EC: mfc2       $v0, $7 ( handwritten instruction ) */
".word 0x3C010200\n\t" /* 800616F0: lui        $at, (0x2000000 >> 16) */
".word 0x02011824\n\t" /* 800616F4: and        $v1, $s0, $at */
".word 0x01314825\n\t" /* 800616F8: or         $t1, $t1, $s1 */
".word 0x01C21006\n\t" /* 800616FC: srlv       $v0, $v0, $t6 */
".word 0x00021080\n\t" /* 80061700: sll        $v0, $v0, 2 */
".word 0x004F1021\n\t" /* 80061704: addu       $v0, $v0, $t7 */
".word 0x8C4D0000\n\t" /* 80061708: lw         $t5, 0x0($v0) */
".word 0xEB2C0008\n\t" /* 8006170C: swc2       $12, 0x8($t9) */
".word 0xEB2D0014\n\t" /* 80061710: swc2       $13, 0x14($t9) */
".word 0xEB2E0020\n\t" /* 80061714: swc2       $14, 0x20($t9) */
".L80061718:\n\t"
".word 0xAF28000C\n\t" /* 80061718: sw         $t0, 0xC($t9) */
".word 0xAF290018\n\t" /* 8006171C: sw         $t1, 0x18($t9) */
".word 0xAF2A0024\n\t" /* 80061720: sw         $t2, 0x24($t9) */
".word 0x000D6A00\n\t" /* 80061724: sll        $t5, $t5, 8 */
".word 0x35AD0009\n\t" /* 80061728: ori        $t5, $t5, 0x9 */
".word 0x000D0A02\n\t" /* 8006172C: srl        $at, $t5, 8 */
".word 0x000D6E00\n\t" /* 80061730: sll        $t5, $t5, 24 */
".word 0x01A16825\n\t" /* 80061734: or         $t5, $t5, $at */
".word 0xAF2D0000\n\t" /* 80061738: sw         $t5, 0x0($t9) */
".word 0x00196A00\n\t" /* 8006173C: sll        $t5, $t9, 8 */
".word 0x000D6A02\n\t" /* 80061740: srl        $t5, $t5, 8 */
".word 0x10600016\n\t" /* 80061744: beqz       $v1, .L800617A0 */
".word 0xAC4D0000\n\t" /* 80061748: sw        $t5, 0x0($v0) */
".word 0x12400014\n\t" /* 8006174C: beqz       $s2, .L800617A0 */
".word 0x00084400\n\t" /* 80061750: sll       $t0, $t0, 16 */
".word 0x00084402\n\t" /* 80061754: srl        $t0, $t0, 16 */
".word 0x01124025\n\t" /* 80061758: or         $t0, $t0, $s2 */
".word 0x3C01FF9F\n\t" /* 8006175C: lui        $at, (0xFF9FFFFF >> 16) */
".word 0x3421FFFF\n\t" /* 80061760: ori        $at, $at, (0xFF9FFFFF & 0xFFFF) */
".word 0x01214824\n\t" /* 80061764: and        $t1, $t1, $at */
".word 0x3C010040\n\t" /* 80061768: lui        $at, (0x400000 >> 16) */
".word 0x01214825\n\t" /* 8006176C: or         $t1, $t1, $at */
".word 0x8F230008\n\t" /* 80061770: lw         $v1, 0x8($t9) */
".word 0xAF2C002C\n\t" /* 80061774: sw         $t4, 0x2C($t9) */
".word 0xAF230030\n\t" /* 80061778: sw         $v1, 0x30($t9) */
".word 0x8F230014\n\t" /* 8006177C: lw         $v1, 0x14($t9) */
".word 0xAF2C0038\n\t" /* 80061780: sw         $t4, 0x38($t9) */
".word 0xAF23003C\n\t" /* 80061784: sw         $v1, 0x3C($t9) */
".word 0x8F230020\n\t" /* 80061788: lw         $v1, 0x20($t9) */
".word 0xAF2C0044\n\t" /* 8006178C: sw         $t4, 0x44($t9) */
".word 0xAF230048\n\t" /* 80061790: sw         $v1, 0x48($t9) */
".word 0x27390028\n\t" /* 80061794: addiu      $t9, $t9, 0x28 */
".word 0x080185C6\n\t" /* 80061798: j          .L80061718 */
".word 0x24030000\n\t" /* 8006179C: addiu     $v1, $zero, 0x0 */
".L800617A0:\n\t"
".word 0x27390028\n\t" /* 800617A0: addiu      $t9, $t9, 0x28 */
".L800617A4:\n\t"
".word 0x2718FFFF\n\t" /* 800617A4: addiu      $t8, $t8, -0x1 */
".word 0x1700FF7C\n\t" /* 800617A8: bnez       $t8, .L8006159C */
".word 0x24E70018\n\t" /* 800617AC: addiu     $a3, $a3, 0x18 */
".L800617B0:\n\t"
".word 0x8C900020\n\t" /* 800617B0: lw         $s0, 0x20($a0) */
".word 0x8C910024\n\t" /* 800617B4: lw         $s1, 0x24($a0) */
".word 0x8C920028\n\t" /* 800617B8: lw         $s2, 0x28($a0) */
".word 0x8C93002C\n\t" /* 800617BC: lw         $s3, 0x2C($a0) */
".word 0x8C960030\n\t" /* 800617C0: lw         $s6, 0x30($a0) */
".word 0x8C970034\n\t" /* 800617C4: lw         $s7, 0x34($a0) */
".word 0x8C820000\n\t" /* 800617C8: lw         $v0, 0x0($a0) */
".word 0x3C018010\n\t" /* 800617CC: lui        $at, %hi(D_800FE240) */
".word 0xAC39E240\n\t" /* 800617D0: sw         $t9, %lo(D_800FE240)($at) */
".word 0x24420008\n\t" /* 800617D4: addiu      $v0, $v0, 0x8 */
".word 0x03E00008\n\t" /* 800617D8: jr         $ra */
".word 0x00000000\n\t" /* 800617DC: nop */
    ".set reorder\n"
);
