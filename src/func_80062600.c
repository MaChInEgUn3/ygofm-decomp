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
    ".global func_80062600\n"
    "func_80062600:\n"
".word 0x8C870000\n\t" /* 80062600: lw         $a3, 0x0($a0) */
".word 0x8C990010\n\t" /* 80062604: lw         $t9, 0x10($a0) */
".word 0x94F80002\n\t" /* 80062608: lhu        $t8, 0x2($a3) */
".word 0x8CE60004\n\t" /* 8006260C: lw         $a2, 0x4($a3) */
".word 0x8C850014\n\t" /* 80062610: lw         $a1, 0x14($a0) */
".word 0x00063080\n\t" /* 80062614: sll        $a2, $a2, 2 */
".word 0xAC900020\n\t" /* 80062618: sw         $s0, 0x20($a0) */
".word 0xAC910024\n\t" /* 8006261C: sw         $s1, 0x24($a0) */
".word 0xAC920028\n\t" /* 80062620: sw         $s2, 0x28($a0) */
".word 0xAC93002C\n\t" /* 80062624: sw         $s3, 0x2C($a0) */
".word 0xAC940030\n\t" /* 80062628: sw         $s4, 0x30($a0) */
".word 0xAC950034\n\t" /* 8006262C: sw         $s5, 0x34($a0) */
".word 0xAC960038\n\t" /* 80062630: sw         $s6, 0x38($a0) */
".word 0xAC97003C\n\t" /* 80062634: sw         $s7, 0x3C($a0) */
".word 0x130000C1\n\t" /* 80062638: beqz       $t8, .L80062940 */
".word 0x00A63821\n\t" /* 8006263C: addu      $a3, $a1, $a2 */
".word 0x3C10800A\n\t" /* 80062640: lui        $s0, %hi(D_8009AFB8) */
".word 0x8E10AFB8\n\t" /* 80062644: lw         $s0, %lo(D_8009AFB8)($s0) */
".word 0x3C11800A\n\t" /* 80062648: lui        $s1, %hi(D_8009AFD8) */
".word 0x8E31AFD8\n\t" /* 8006264C: lw         $s1, %lo(D_8009AFD8)($s1) */
".word 0x3C12800A\n\t" /* 80062650: lui        $s2, %hi(D_8009AFDC) */
".word 0x8E52AFDC\n\t" /* 80062654: lw         $s2, %lo(D_8009AFDC)($s2) */
".word 0x3C16800A\n\t" /* 80062658: lui        $s6, %hi(D_8009AFE4) */
".word 0x82D6AFE4\n\t" /* 8006265C: lb         $s6, %lo(D_8009AFE4)($s6) */
".word 0x3C17800A\n\t" /* 80062660: lui        $s7, %hi(D_8009AFE0) */
".word 0x8EF7AFE0\n\t" /* 80062664: lw         $s7, %lo(D_8009AFE0)($s7) */
".word 0x02006021\n\t" /* 80062668: addu       $t4, $s0, $zero */
".word 0x00109E02\n\t" /* 8006266C: srl        $s3, $s0, 24 */
".word 0x3C14E200\n\t" /* 80062670: lui        $s4, (0xE2000000 >> 16) */
".word 0x8C850018\n\t" /* 80062674: lw         $a1, 0x18($a0) */
".word 0x8C86001C\n\t" /* 80062678: lw         $a2, 0x1C($a0) */
".word 0x48903000\n\t" /* 8006267C: mtc2       $s0, $6 ( handwritten instruction ) */
".word 0x8C8D0004\n\t" /* 80062680: lw         $t5, 0x4($a0) */
".word 0x8C8E0008\n\t" /* 80062684: lw         $t6, 0x8($a0) */
".word 0x8DAF0004\n\t" /* 80062688: lw         $t7, 0x4($t5) */
".L8006268C:\n\t"
".word 0x8CE80010\n\t" /* 8006268C: lw         $t0, 0x10($a3) */
".word 0x98E8000E\n\t" /* 80062690: lwr        $t0, 0xE($a3) */
".word 0x8CE90014\n\t" /* 80062694: lw         $t1, 0x14($a3) */
".word 0x8CEA0018\n\t" /* 80062698: lw         $t2, 0x18($a3) */
".word 0x8CEB001C\n\t" /* 8006269C: lw         $t3, 0x1C($a3) */
".word 0x00086C02\n\t" /* 800626A0: srl        $t5, $t0, 16 */
".word 0x000D68C0\n\t" /* 800626A4: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 800626A8: addu       $t5, $t5, $a1 */
".word 0xC9A00000\n\t" /* 800626AC: lwc2       $0, 0x0($t5) */
".word 0xC9A10004\n\t" /* 800626B0: lwc2       $1, 0x4($t5) */
".word 0x00096C02\n\t" /* 800626B4: srl        $t5, $t1, 16 */
".word 0x000D68C0\n\t" /* 800626B8: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 800626BC: addu       $t5, $t5, $a1 */
".word 0xC9A20000\n\t" /* 800626C0: lwc2       $2, 0x0($t5) */
".word 0xC9A30004\n\t" /* 800626C4: lwc2       $3, 0x4($t5) */
".word 0x000A6C02\n\t" /* 800626C8: srl        $t5, $t2, 16 */
".word 0x000D68C0\n\t" /* 800626CC: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 800626D0: addu       $t5, $t5, $a1 */
".word 0xC9A40000\n\t" /* 800626D4: lwc2       $4, 0x0($t5) */
".word 0xC9A50004\n\t" /* 800626D8: lwc2       $5, 0x4($t5) */
".word 0x000B6C02\n\t" /* 800626DC: srl        $t5, $t3, 16 */
".word 0x000D68C0\n\t" /* 800626E0: sll        $t5, $t5, 3 */
".word 0x4A280030\n\t" /* 800626E4: rtpt */
".word 0x000B5C00\n\t" /* 800626E8: sll        $t3, $t3, 16 */
".word 0x000B5B42\n\t" /* 800626EC: srl        $t3, $t3, 13 */
".word 0x24010001\n\t" /* 800626F0: addiu      $at, $zero, 0x1 */
".word 0x12C1000A\n\t" /* 800626F4: beq        $s6, $at, .L80062720 */
".word 0x01A56821\n\t" /* 800626F8: addu      $t5, $t5, $a1 */
".word 0x4842F800\n\t" /* 800626FC: cfc2       $v0, $31 ( handwritten instruction ) */
".word 0x00000000\n\t" /* 80062700: nop */
".word 0x0440008B\n\t" /* 80062704: bltz       $v0, .L80062934 */
".word 0x00000000\n\t" /* 80062708: nop */
".word 0x4B400006\n\t" /* 8006270C: nclip */
".word 0x4802C000\n\t" /* 80062710: mfc2       $v0, $24 ( handwritten instruction ) */
".word 0x00000000\n\t" /* 80062714: nop */
".word 0x18400086\n\t" /* 80062718: blez       $v0, .L80062934 */
".word 0x00000000\n\t" /* 8006271C: nop */
".L80062720:\n\t"
".word 0xC9A00000\n\t" /* 80062720: lwc2       $0, 0x0($t5) */
".word 0xC9A10004\n\t" /* 80062724: lwc2       $1, 0x4($t5) */
".word 0xEB2C000C\n\t" /* 80062728: swc2       $12, 0xC($t9) */
".word 0xEB2D0018\n\t" /* 8006272C: swc2       $13, 0x18($t9) */
".word 0xEB2E0024\n\t" /* 80062730: swc2       $14, 0x24($t9) */
".word 0x00084400\n\t" /* 80062734: sll        $t0, $t0, 16 */
".word 0x00084342\n\t" /* 80062738: srl        $t0, $t0, 13 */
".word 0x4A180001\n\t" /* 8006273C: rtps */
".word 0x00094C00\n\t" /* 80062740: sll        $t1, $t1, 16 */
".word 0x24010001\n\t" /* 80062744: addiu      $at, $zero, 0x1 */
".word 0x12C10005\n\t" /* 80062748: beq        $s6, $at, .L80062760 */
".word 0x00094B42\n\t" /* 8006274C: srl       $t1, $t1, 13 */
".word 0x4842F800\n\t" /* 80062750: cfc2       $v0, $31 ( handwritten instruction ) */
".word 0x00000000\n\t" /* 80062754: nop */
".word 0x04400076\n\t" /* 80062758: bltz       $v0, .L80062934 */
".word 0x00000000\n\t" /* 8006275C: nop */
".L80062760:\n\t"
".word 0x4B68002E\n\t" /* 80062760: avsz4 */
".word 0xEB2E0030\n\t" /* 80062764: swc2       $14, 0x30($t9) */
".word 0x000A5400\n\t" /* 80062768: sll        $t2, $t2, 16 */
".word 0x000A5342\n\t" /* 8006276C: srl        $t2, $t2, 13 */
".word 0x8CF50000\n\t" /* 80062770: lw         $s5, 0x0($a3) */
".word 0x12C00029\n\t" /* 80062774: beqz       $s6, .L8006281C */
".word 0x01666821\n\t" /* 80062778: addu      $t5, $t3, $a2 */
".word 0xC9A00000\n\t" /* 8006277C: lwc2       $0, 0x0($t5) */
".word 0xC9A10004\n\t" /* 80062780: lwc2       $1, 0x4($t5) */
".word 0x00000000\n\t" /* 80062784: nop */
".word 0x00000000\n\t" /* 80062788: nop */
".word 0x4B08041B\n\t" /* 8006278C: nccs */
".word 0x01066821\n\t" /* 80062790: addu       $t5, $t0, $a2 */
".word 0xC9A00000\n\t" /* 80062794: lwc2       $0, 0x0($t5) */
".word 0xC9A10004\n\t" /* 80062798: lwc2       $1, 0x4($t5) */
".word 0x01266821\n\t" /* 8006279C: addu       $t5, $t1, $a2 */
".word 0xC9A20000\n\t" /* 800627A0: lwc2       $2, 0x0($t5) */
".word 0xC9A30004\n\t" /* 800627A4: lwc2       $3, 0x4($t5) */
".word 0x01466821\n\t" /* 800627A8: addu       $t5, $t2, $a2 */
".word 0xC9A40000\n\t" /* 800627AC: lwc2       $4, 0x0($t5) */
".word 0xC9A50004\n\t" /* 800627B0: lwc2       $5, 0x4($t5) */
".word 0x12E00003\n\t" /* 800627B4: beqz       $s7, .L800627C4 */
".word 0x000B5842\n\t" /* 800627B8: srl       $t3, $t3, 1 */
".word 0x01775821\n\t" /* 800627BC: addu       $t3, $t3, $s7 */
".word 0xE9760000\n\t" /* 800627C0: swc2       $22, 0x0($t3) */
".L800627C4:\n\t"
".word 0xEB36002C\n\t" /* 800627C4: swc2       $22, 0x2C($t9) */
".word 0x00000000\n\t" /* 800627C8: nop */
".word 0x00000000\n\t" /* 800627CC: nop */
".word 0x4B18043F\n\t" /* 800627D0: ncct */
".word 0x12E00009\n\t" /* 800627D4: beqz       $s7, .L800627FC */
".word 0x00084042\n\t" /* 800627D8: srl       $t0, $t0, 1 */
".word 0x01174021\n\t" /* 800627DC: addu       $t0, $t0, $s7 */
".word 0x00094842\n\t" /* 800627E0: srl        $t1, $t1, 1 */
".word 0x01374821\n\t" /* 800627E4: addu       $t1, $t1, $s7 */
".word 0x000A5042\n\t" /* 800627E8: srl        $t2, $t2, 1 */
".word 0x01575021\n\t" /* 800627EC: addu       $t2, $t2, $s7 */
".word 0xE9140000\n\t" /* 800627F0: swc2       $20, 0x0($t0) */
".word 0xE9350000\n\t" /* 800627F4: swc2       $21, 0x0($t1) */
".word 0xE9560000\n\t" /* 800627F8: swc2       $22, 0x0($t2) */
".L800627FC:\n\t"
".word 0xEB340008\n\t" /* 800627FC: swc2       $20, 0x8($t9) */
".word 0xEB350014\n\t" /* 80062800: swc2       $21, 0x14($t9) */
".word 0xEB360020\n\t" /* 80062804: swc2       $22, 0x20($t9) */
".word 0x24010001\n\t" /* 80062808: addiu      $at, $zero, 0x1 */
".word 0x12C10049\n\t" /* 8006280C: beq        $s6, $at, .L80062934 */
".word 0x00000000\n\t" /* 80062810: nop */
".word 0x08018A18\n\t" /* 80062814: j          .L80062860 */
".word 0x00000000\n\t" /* 80062818: nop */
".L8006281C:\n\t"
".word 0x00084042\n\t" /* 8006281C: srl        $t0, $t0, 1 */
".word 0x01171821\n\t" /* 80062820: addu       $v1, $t0, $s7 */
".word 0x8C680000\n\t" /* 80062824: lw         $t0, 0x0($v1) */
".word 0x00094842\n\t" /* 80062828: srl        $t1, $t1, 1 */
".word 0x01371821\n\t" /* 8006282C: addu       $v1, $t1, $s7 */
".word 0x8C690000\n\t" /* 80062830: lw         $t1, 0x0($v1) */
".word 0x000A5042\n\t" /* 80062834: srl        $t2, $t2, 1 */
".word 0x01571821\n\t" /* 80062838: addu       $v1, $t2, $s7 */
".word 0x8C6A0000\n\t" /* 8006283C: lw         $t2, 0x0($v1) */
".word 0x000B5842\n\t" /* 80062840: srl        $t3, $t3, 1 */
".word 0x01771821\n\t" /* 80062844: addu       $v1, $t3, $s7 */
".word 0x8C6B0000\n\t" /* 80062848: lw         $t3, 0x0($v1) */
".word 0xAF280008\n\t" /* 8006284C: sw         $t0, 0x8($t9) */
".word 0xAF290014\n\t" /* 80062850: sw         $t1, 0x14($t9) */
".word 0xAF2A0020\n\t" /* 80062854: sw         $t2, 0x20($t9) */
".word 0xAF2B002C\n\t" /* 80062858: sw         $t3, 0x2C($t9) */
".word 0xA333000B\n\t" /* 8006285C: sb         $s3, 0xB($t9) */
".L80062860:\n\t"
".word 0x8CE80004\n\t" /* 80062860: lw         $t0, 0x4($a3) */
".word 0x8CE90008\n\t" /* 80062864: lw         $t1, 0x8($a3) */
".word 0x8CEA000C\n\t" /* 80062868: lw         $t2, 0xC($a3) */
".word 0x8CEB0010\n\t" /* 8006286C: lw         $t3, 0x10($a3) */
".word 0x48023800\n\t" /* 80062870: mfc2       $v0, $7 ( handwritten instruction ) */
".word 0x3C010200\n\t" /* 80062874: lui        $at, (0x2000000 >> 16) */
".word 0x02011824\n\t" /* 80062878: and        $v1, $s0, $at */
".word 0x01314825\n\t" /* 8006287C: or         $t1, $t1, $s1 */
".word 0x01C21006\n\t" /* 80062880: srlv       $v0, $v0, $t6 */
".word 0x00021080\n\t" /* 80062884: sll        $v0, $v0, 2 */
".word 0x004F1021\n\t" /* 80062888: addu       $v0, $v0, $t7 */
".word 0x8C4D0000\n\t" /* 8006288C: lw         $t5, 0x0($v0) */
".L80062890:\n\t"
".word 0xAF280010\n\t" /* 80062890: sw         $t0, 0x10($t9) */
".word 0xAF29001C\n\t" /* 80062894: sw         $t1, 0x1C($t9) */
".word 0xAF2A0028\n\t" /* 80062898: sw         $t2, 0x28($t9) */
".word 0xAF2B0034\n\t" /* 8006289C: sw         $t3, 0x34($t9) */
".word 0xAF350004\n\t" /* 800628A0: sw         $s5, 0x4($t9) */
".word 0xAF340038\n\t" /* 800628A4: sw         $s4, 0x38($t9) */
".word 0x000D6A00\n\t" /* 800628A8: sll        $t5, $t5, 8 */
".word 0x35AD000E\n\t" /* 800628AC: ori        $t5, $t5, 0xE */
".word 0x000D0A02\n\t" /* 800628B0: srl        $at, $t5, 8 */
".word 0x000D6E00\n\t" /* 800628B4: sll        $t5, $t5, 24 */
".word 0x01A16825\n\t" /* 800628B8: or         $t5, $t5, $at */
".word 0xAF2D0000\n\t" /* 800628BC: sw         $t5, 0x0($t9) */
".word 0x00196A00\n\t" /* 800628C0: sll        $t5, $t9, 8 */
".word 0x000D6A02\n\t" /* 800628C4: srl        $t5, $t5, 8 */
".word 0x10600019\n\t" /* 800628C8: beqz       $v1, .L80062930 */
".word 0xAC4D0000\n\t" /* 800628CC: sw        $t5, 0x0($v0) */
".word 0x12400017\n\t" /* 800628D0: beqz       $s2, .L80062930 */
".word 0x00084400\n\t" /* 800628D4: sll       $t0, $t0, 16 */
".word 0x00084402\n\t" /* 800628D8: srl        $t0, $t0, 16 */
".word 0x01124025\n\t" /* 800628DC: or         $t0, $t0, $s2 */
".word 0x3C01FF9F\n\t" /* 800628E0: lui        $at, (0xFF9FFFFF >> 16) */
".word 0x3421FFFF\n\t" /* 800628E4: ori        $at, $at, (0xFF9FFFFF & 0xFFFF) */
".word 0x01214824\n\t" /* 800628E8: and        $t1, $t1, $at */
".word 0x3C010040\n\t" /* 800628EC: lui        $at, (0x400000 >> 16) */
".word 0x01214825\n\t" /* 800628F0: or         $t1, $t1, $at */
".word 0x8F23000C\n\t" /* 800628F4: lw         $v1, 0xC($t9) */
".word 0xAF2C0044\n\t" /* 800628F8: sw         $t4, 0x44($t9) */
".word 0xAF230048\n\t" /* 800628FC: sw         $v1, 0x48($t9) */
".word 0x8F230018\n\t" /* 80062900: lw         $v1, 0x18($t9) */
".word 0xAF2C0050\n\t" /* 80062904: sw         $t4, 0x50($t9) */
".word 0xAF230054\n\t" /* 80062908: sw         $v1, 0x54($t9) */
".word 0x8F230024\n\t" /* 8006290C: lw         $v1, 0x24($t9) */
".word 0xAF2C005C\n\t" /* 80062910: sw         $t4, 0x5C($t9) */
".word 0xAF230060\n\t" /* 80062914: sw         $v1, 0x60($t9) */
".word 0x8F230030\n\t" /* 80062918: lw         $v1, 0x30($t9) */
".word 0xAF2C0068\n\t" /* 8006291C: sw         $t4, 0x68($t9) */
".word 0xAF23006C\n\t" /* 80062920: sw         $v1, 0x6C($t9) */
".word 0x2739003C\n\t" /* 80062924: addiu      $t9, $t9, 0x3C */
".word 0x08018A24\n\t" /* 80062928: j          .L80062890 */
".word 0x24030000\n\t" /* 8006292C: addiu     $v1, $zero, 0x0 */
".L80062930:\n\t"
".word 0x2739003C\n\t" /* 80062930: addiu      $t9, $t9, 0x3C */
".L80062934:\n\t"
".word 0x2718FFFF\n\t" /* 80062934: addiu      $t8, $t8, -0x1 */
".word 0x1700FF54\n\t" /* 80062938: bnez       $t8, .L8006268C */
".word 0x24E70020\n\t" /* 8006293C: addiu     $a3, $a3, 0x20 */
".L80062940:\n\t"
".word 0x8C900020\n\t" /* 80062940: lw         $s0, 0x20($a0) */
".word 0x8C910024\n\t" /* 80062944: lw         $s1, 0x24($a0) */
".word 0x8C920028\n\t" /* 80062948: lw         $s2, 0x28($a0) */
".word 0x8C93002C\n\t" /* 8006294C: lw         $s3, 0x2C($a0) */
".word 0x8C940030\n\t" /* 80062950: lw         $s4, 0x30($a0) */
".word 0x8C950034\n\t" /* 80062954: lw         $s5, 0x34($a0) */
".word 0x8C960038\n\t" /* 80062958: lw         $s6, 0x38($a0) */
".word 0x8C97003C\n\t" /* 8006295C: lw         $s7, 0x3C($a0) */
".word 0x8C820000\n\t" /* 80062960: lw         $v0, 0x0($a0) */
".word 0x3C018010\n\t" /* 80062964: lui        $at, %hi(D_800FE240) */
".word 0xAC39E240\n\t" /* 80062968: sw         $t9, %lo(D_800FE240)($at) */
".word 0x24420008\n\t" /* 8006296C: addiu      $v0, $v0, 0x8 */
".word 0x03E00008\n\t" /* 80062970: jr         $ra */
".word 0x00000000\n\t" /* 80062974: nop */
    ".set reorder\n"
);
