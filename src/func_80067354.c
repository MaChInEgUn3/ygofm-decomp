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
    ".global func_80067354\n"
    "func_80067354:\n"
".word 0x8C870000\n\t" /* 80067354: lw         $a3, 0x0($a0) */
".word 0x8C990010\n\t" /* 80067358: lw         $t9, 0x10($a0) */
".word 0x94F80002\n\t" /* 8006735C: lhu        $t8, 0x2($a3) */
".word 0x8CE60004\n\t" /* 80067360: lw         $a2, 0x4($a3) */
".word 0x8C850014\n\t" /* 80067364: lw         $a1, 0x14($a0) */
".word 0x00063080\n\t" /* 80067368: sll        $a2, $a2, 2 */
".word 0xAC900028\n\t" /* 8006736C: sw         $s0, 0x28($a0) */
".word 0xAC91002C\n\t" /* 80067370: sw         $s1, 0x2C($a0) */
".word 0xAC920030\n\t" /* 80067374: sw         $s2, 0x30($a0) */
".word 0xAC930034\n\t" /* 80067378: sw         $s3, 0x34($a0) */
".word 0x1300007D\n\t" /* 8006737C: beqz       $t8, .L80067574 */
".word 0x00A63821\n\t" /* 80067380: addu      $a3, $a1, $a2 */
".word 0x3C10800A\n\t" /* 80067384: lui        $s0, %hi(D_8009AFB4) */
".word 0x8E10AFB4\n\t" /* 80067388: lw         $s0, %lo(D_8009AFB4)($s0) */
".word 0x3C11800A\n\t" /* 8006738C: lui        $s1, %hi(D_8009AFD8) */
".word 0x8E31AFD8\n\t" /* 80067390: lw         $s1, %lo(D_8009AFD8)($s1) */
".word 0x3C12800A\n\t" /* 80067394: lui        $s2, %hi(D_8009AFDC) */
".word 0x8E52AFDC\n\t" /* 80067398: lw         $s2, %lo(D_8009AFDC)($s2) */
".word 0x02006021\n\t" /* 8006739C: addu       $t4, $s0, $zero */
".word 0x3C0D800A\n\t" /* 800673A0: lui        $t5, %hi(D_8009AFE4) */
".word 0x81ADAFE4\n\t" /* 800673A4: lb         $t5, %lo(D_8009AFE4)($t5) */
".word 0x00109E02\n\t" /* 800673A8: srl        $s3, $s0, 24 */
".word 0x00139E00\n\t" /* 800673AC: sll        $s3, $s3, 24 */
".word 0x24010001\n\t" /* 800673B0: addiu      $at, $zero, 0x1 */
".word 0x11A1006F\n\t" /* 800673B4: beq        $t5, $at, .L80067574 */
".word 0x00000000\n\t" /* 800673B8: nop */
".word 0x3C0D800A\n\t" /* 800673BC: lui        $t5, %hi(D_8009AFE0) */
".word 0x8DADAFE0\n\t" /* 800673C0: lw         $t5, %lo(D_8009AFE0)($t5) */
".word 0x8C85001C\n\t" /* 800673C4: lw         $a1, 0x1C($a0) */
".word 0x8C860024\n\t" /* 800673C8: lw         $a2, 0x24($a0) */
".word 0x11A00002\n\t" /* 800673CC: beqz       $t5, .L800673D8 */
".word 0x00000000\n\t" /* 800673D0: nop */
".word 0x24C60004\n\t" /* 800673D4: addiu      $a2, $a2, 0x4 */
".L800673D8:\n\t"
".word 0x8C8D0004\n\t" /* 800673D8: lw         $t5, 0x4($a0) */
".word 0x8C8E0008\n\t" /* 800673DC: lw         $t6, 0x8($a0) */
".word 0x8DAF0004\n\t" /* 800673E0: lw         $t7, 0x4($t5) */
".L800673E4:\n\t"
".word 0x2403FFFF\n\t" /* 800673E4: addiu      $v1, $zero, -0x1 */
".word 0x8CE8000C\n\t" /* 800673E8: lw         $t0, 0xC($a3) */
".word 0x8CE90010\n\t" /* 800673EC: lw         $t1, 0x10($a3) */
".word 0x8CEA0014\n\t" /* 800673F0: lw         $t2, 0x14($a3) */
".word 0x00086C02\n\t" /* 800673F4: srl        $t5, $t0, 16 */
".word 0x000D68C0\n\t" /* 800673F8: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 800673FC: addu       $t5, $t5, $a1 */
".word 0x8DA20004\n\t" /* 80067400: lw         $v0, 0x4($t5) */
".word 0x8DAD0000\n\t" /* 80067404: lw         $t5, 0x0($t5) */
".word 0x10430057\n\t" /* 80067408: beq        $v0, $v1, .L80067568 */
".word 0x48828800\n\t" /* 8006740C: mtc2      $v0, $17 ( handwritten instruction ) */
".word 0x488D6000\n\t" /* 80067410: mtc2       $t5, $12 ( handwritten instruction ) */
".word 0xAF2D0008\n\t" /* 80067414: sw         $t5, 0x8($t9) */
".word 0x00096C02\n\t" /* 80067418: srl        $t5, $t1, 16 */
".word 0x000D68C0\n\t" /* 8006741C: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 80067420: addu       $t5, $t5, $a1 */
".word 0x8DA20004\n\t" /* 80067424: lw         $v0, 0x4($t5) */
".word 0x8DAD0000\n\t" /* 80067428: lw         $t5, 0x0($t5) */
".word 0x1043004E\n\t" /* 8006742C: beq        $v0, $v1, .L80067568 */
".word 0x48829000\n\t" /* 80067430: mtc2      $v0, $18 ( handwritten instruction ) */
".word 0x488D6800\n\t" /* 80067434: mtc2       $t5, $13 ( handwritten instruction ) */
".word 0xAF2D0014\n\t" /* 80067438: sw         $t5, 0x14($t9) */
".word 0x000A6C02\n\t" /* 8006743C: srl        $t5, $t2, 16 */
".word 0x000D68C0\n\t" /* 80067440: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 80067444: addu       $t5, $t5, $a1 */
".word 0x8DA20004\n\t" /* 80067448: lw         $v0, 0x4($t5) */
".word 0x8DAD0000\n\t" /* 8006744C: lw         $t5, 0x0($t5) */
".word 0x10430045\n\t" /* 80067450: beq        $v0, $v1, .L80067568 */
".word 0x48829800\n\t" /* 80067454: mtc2      $v0, $19 ( handwritten instruction ) */
".word 0x488D7000\n\t" /* 80067458: mtc2       $t5, $14 ( handwritten instruction ) */
".word 0xAF2D0020\n\t" /* 8006745C: sw         $t5, 0x20($t9) */
".word 0x00084400\n\t" /* 80067460: sll        $t0, $t0, 16 */
".word 0x00084342\n\t" /* 80067464: srl        $t0, $t0, 13 */
".word 0x4B400006\n\t" /* 80067468: nclip */
".word 0x00094C00\n\t" /* 8006746C: sll        $t1, $t1, 16 */
".word 0x00094B42\n\t" /* 80067470: srl        $t1, $t1, 13 */
".word 0x000A5400\n\t" /* 80067474: sll        $t2, $t2, 16 */
".word 0x000A5342\n\t" /* 80067478: srl        $t2, $t2, 13 */
".word 0x01064021\n\t" /* 8006747C: addu       $t0, $t0, $a2 */
".word 0x4802C000\n\t" /* 80067480: mfc2       $v0, $24 ( handwritten instruction ) */
".word 0x01264821\n\t" /* 80067484: addu       $t1, $t1, $a2 */
".word 0x18400037\n\t" /* 80067488: blez       $v0, .L80067568 */
".word 0x01465021\n\t" /* 8006748C: addu      $t2, $t2, $a2 */
".word 0x8D080000\n\t" /* 80067490: lw         $t0, 0x0($t0) */
".word 0x8D290000\n\t" /* 80067494: lw         $t1, 0x0($t1) */
".word 0x8D4A0000\n\t" /* 80067498: lw         $t2, 0x0($t2) */
".word 0x01134025\n\t" /* 8006749C: or         $t0, $t0, $s3 */
".word 0xAF280004\n\t" /* 800674A0: sw         $t0, 0x4($t9) */
".word 0xAF290010\n\t" /* 800674A4: sw         $t1, 0x10($t9) */
".word 0xAF2A001C\n\t" /* 800674A8: sw         $t2, 0x1C($t9) */
".word 0x4B58002D\n\t" /* 800674AC: avsz3 */
".word 0x8CE80000\n\t" /* 800674B0: lw         $t0, 0x0($a3) */
".word 0x8CE90004\n\t" /* 800674B4: lw         $t1, 0x4($a3) */
".word 0x8CEA0008\n\t" /* 800674B8: lw         $t2, 0x8($a3) */
".word 0x48023800\n\t" /* 800674BC: mfc2       $v0, $7 ( handwritten instruction ) */
".word 0x3C010200\n\t" /* 800674C0: lui        $at, (0x2000000 >> 16) */
".word 0x02011824\n\t" /* 800674C4: and        $v1, $s0, $at */
".word 0x01314825\n\t" /* 800674C8: or         $t1, $t1, $s1 */
".word 0x01C21006\n\t" /* 800674CC: srlv       $v0, $v0, $t6 */
".word 0x00021080\n\t" /* 800674D0: sll        $v0, $v0, 2 */
".word 0x004F1021\n\t" /* 800674D4: addu       $v0, $v0, $t7 */
".word 0x8C4D0000\n\t" /* 800674D8: lw         $t5, 0x0($v0) */
".L800674DC:\n\t"
".word 0xAF28000C\n\t" /* 800674DC: sw         $t0, 0xC($t9) */
".word 0xAF290018\n\t" /* 800674E0: sw         $t1, 0x18($t9) */
".word 0xAF2A0024\n\t" /* 800674E4: sw         $t2, 0x24($t9) */
".word 0x000D6A00\n\t" /* 800674E8: sll        $t5, $t5, 8 */
".word 0x35AD0009\n\t" /* 800674EC: ori        $t5, $t5, 0x9 */
".word 0x000D0A02\n\t" /* 800674F0: srl        $at, $t5, 8 */
".word 0x000D6E00\n\t" /* 800674F4: sll        $t5, $t5, 24 */
".word 0x01A16825\n\t" /* 800674F8: or         $t5, $t5, $at */
".word 0xAF2D0000\n\t" /* 800674FC: sw         $t5, 0x0($t9) */
".word 0x00196A00\n\t" /* 80067500: sll        $t5, $t9, 8 */
".word 0x000D6A02\n\t" /* 80067504: srl        $t5, $t5, 8 */
".word 0x10600016\n\t" /* 80067508: beqz       $v1, .L80067564 */
".word 0xAC4D0000\n\t" /* 8006750C: sw        $t5, 0x0($v0) */
".word 0x12400014\n\t" /* 80067510: beqz       $s2, .L80067564 */
".word 0x00084400\n\t" /* 80067514: sll       $t0, $t0, 16 */
".word 0x00084402\n\t" /* 80067518: srl        $t0, $t0, 16 */
".word 0x01124025\n\t" /* 8006751C: or         $t0, $t0, $s2 */
".word 0x3C01FF9F\n\t" /* 80067520: lui        $at, (0xFF9FFFFF >> 16) */
".word 0x3421FFFF\n\t" /* 80067524: ori        $at, $at, (0xFF9FFFFF & 0xFFFF) */
".word 0x01214824\n\t" /* 80067528: and        $t1, $t1, $at */
".word 0x3C010040\n\t" /* 8006752C: lui        $at, (0x400000 >> 16) */
".word 0x01214825\n\t" /* 80067530: or         $t1, $t1, $at */
".word 0x8F230008\n\t" /* 80067534: lw         $v1, 0x8($t9) */
".word 0xAF2C002C\n\t" /* 80067538: sw         $t4, 0x2C($t9) */
".word 0xAF230030\n\t" /* 8006753C: sw         $v1, 0x30($t9) */
".word 0x8F230014\n\t" /* 80067540: lw         $v1, 0x14($t9) */
".word 0xAF2C0038\n\t" /* 80067544: sw         $t4, 0x38($t9) */
".word 0xAF23003C\n\t" /* 80067548: sw         $v1, 0x3C($t9) */
".word 0x8F230020\n\t" /* 8006754C: lw         $v1, 0x20($t9) */
".word 0xAF2C0044\n\t" /* 80067550: sw         $t4, 0x44($t9) */
".word 0xAF230048\n\t" /* 80067554: sw         $v1, 0x48($t9) */
".word 0x27390028\n\t" /* 80067558: addiu      $t9, $t9, 0x28 */
".word 0x08019D37\n\t" /* 8006755C: j          .L800674DC */
".word 0x24030000\n\t" /* 80067560: addiu     $v1, $zero, 0x0 */
".L80067564:\n\t"
".word 0x27390028\n\t" /* 80067564: addiu      $t9, $t9, 0x28 */
".L80067568:\n\t"
".word 0x2718FFFF\n\t" /* 80067568: addiu      $t8, $t8, -0x1 */
".word 0x1700FF9D\n\t" /* 8006756C: bnez       $t8, .L800673E4 */
".word 0x24E70018\n\t" /* 80067570: addiu     $a3, $a3, 0x18 */
".L80067574:\n\t"
".word 0x8C900028\n\t" /* 80067574: lw         $s0, 0x28($a0) */
".word 0x8C91002C\n\t" /* 80067578: lw         $s1, 0x2C($a0) */
".word 0x8C920030\n\t" /* 8006757C: lw         $s2, 0x30($a0) */
".word 0x8C930034\n\t" /* 80067580: lw         $s3, 0x34($a0) */
".word 0x8C820000\n\t" /* 80067584: lw         $v0, 0x0($a0) */
".word 0x3C018010\n\t" /* 80067588: lui        $at, %hi(D_800FE240) */
".word 0xAC39E240\n\t" /* 8006758C: sw         $t9, %lo(D_800FE240)($at) */
".word 0x24420008\n\t" /* 80067590: addiu      $v0, $v0, 0x8 */
".word 0x03E00008\n\t" /* 80067594: jr         $ra */
".word 0x00000000\n\t" /* 80067598: nop */
    ".set reorder\n"
);
