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
    ".global func_8006759C\n"
    "func_8006759C:\n"
".word 0x8C870000\n\t" /* 8006759C: lw         $a3, 0x0($a0) */
".word 0x8C990010\n\t" /* 800675A0: lw         $t9, 0x10($a0) */
".word 0x94F80002\n\t" /* 800675A4: lhu        $t8, 0x2($a3) */
".word 0x8CE60004\n\t" /* 800675A8: lw         $a2, 0x4($a3) */
".word 0x8C850014\n\t" /* 800675AC: lw         $a1, 0x14($a0) */
".word 0x00063080\n\t" /* 800675B0: sll        $a2, $a2, 2 */
".word 0xAC900028\n\t" /* 800675B4: sw         $s0, 0x28($a0) */
".word 0xAC91002C\n\t" /* 800675B8: sw         $s1, 0x2C($a0) */
".word 0xAC920030\n\t" /* 800675BC: sw         $s2, 0x30($a0) */
".word 0xAC930034\n\t" /* 800675C0: sw         $s3, 0x34($a0) */
".word 0x1300009A\n\t" /* 800675C4: beqz       $t8, .L80067830 */
".word 0x00A63821\n\t" /* 800675C8: addu      $a3, $a1, $a2 */
".word 0x3C10800A\n\t" /* 800675CC: lui        $s0, %hi(D_8009AFB8) */
".word 0x8E10AFB8\n\t" /* 800675D0: lw         $s0, %lo(D_8009AFB8)($s0) */
".word 0x3C11800A\n\t" /* 800675D4: lui        $s1, %hi(D_8009AFD8) */
".word 0x8E31AFD8\n\t" /* 800675D8: lw         $s1, %lo(D_8009AFD8)($s1) */
".word 0x3C12800A\n\t" /* 800675DC: lui        $s2, %hi(D_8009AFDC) */
".word 0x8E52AFDC\n\t" /* 800675E0: lw         $s2, %lo(D_8009AFDC)($s2) */
".word 0x02006021\n\t" /* 800675E4: addu       $t4, $s0, $zero */
".word 0x3C0D800A\n\t" /* 800675E8: lui        $t5, %hi(D_8009AFE4) */
".word 0x81ADAFE4\n\t" /* 800675EC: lb         $t5, %lo(D_8009AFE4)($t5) */
".word 0x00109E02\n\t" /* 800675F0: srl        $s3, $s0, 24 */
".word 0x00139E00\n\t" /* 800675F4: sll        $s3, $s3, 24 */
".word 0x24010001\n\t" /* 800675F8: addiu      $at, $zero, 0x1 */
".word 0x11A1008C\n\t" /* 800675FC: beq        $t5, $at, .L80067830 */
".word 0x00000000\n\t" /* 80067600: nop */
".word 0x3C0D800A\n\t" /* 80067604: lui        $t5, %hi(D_8009AFE0) */
".word 0x8DADAFE0\n\t" /* 80067608: lw         $t5, %lo(D_8009AFE0)($t5) */
".word 0x8C85001C\n\t" /* 8006760C: lw         $a1, 0x1C($a0) */
".word 0x8C860024\n\t" /* 80067610: lw         $a2, 0x24($a0) */
".word 0x11A00002\n\t" /* 80067614: beqz       $t5, .L80067620 */
".word 0x00000000\n\t" /* 80067618: nop */
".word 0x24C60004\n\t" /* 8006761C: addiu      $a2, $a2, 0x4 */
".L80067620:\n\t"
".word 0x8C8D0004\n\t" /* 80067620: lw         $t5, 0x4($a0) */
".word 0x8C8E0008\n\t" /* 80067624: lw         $t6, 0x8($a0) */
".word 0x8DAF0004\n\t" /* 80067628: lw         $t7, 0x4($t5) */
".L8006762C:\n\t"
".word 0x2403FFFF\n\t" /* 8006762C: addiu      $v1, $zero, -0x1 */
".word 0x8CE8000C\n\t" /* 80067630: lw         $t0, 0xC($a3) */
".word 0x98E8000A\n\t" /* 80067634: lwr        $t0, 0xA($a3) */
".word 0x8CE90010\n\t" /* 80067638: lw         $t1, 0x10($a3) */
".word 0x8CEA0014\n\t" /* 8006763C: lw         $t2, 0x14($a3) */
".word 0x8CEB0018\n\t" /* 80067640: lw         $t3, 0x18($a3) */
".word 0x00086C02\n\t" /* 80067644: srl        $t5, $t0, 16 */
".word 0x000D68C0\n\t" /* 80067648: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 8006764C: addu       $t5, $t5, $a1 */
".word 0x8DA20004\n\t" /* 80067650: lw         $v0, 0x4($t5) */
".word 0x8DAD0000\n\t" /* 80067654: lw         $t5, 0x0($t5) */
".word 0x10430072\n\t" /* 80067658: beq        $v0, $v1, .L80067824 */
".word 0x48828000\n\t" /* 8006765C: mtc2      $v0, $16 ( handwritten instruction ) */
".word 0x488D6000\n\t" /* 80067660: mtc2       $t5, $12 ( handwritten instruction ) */
".word 0xAF2D0008\n\t" /* 80067664: sw         $t5, 0x8($t9) */
".word 0x00096C02\n\t" /* 80067668: srl        $t5, $t1, 16 */
".word 0x000D68C0\n\t" /* 8006766C: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 80067670: addu       $t5, $t5, $a1 */
".word 0x8DA20004\n\t" /* 80067674: lw         $v0, 0x4($t5) */
".word 0x8DAD0000\n\t" /* 80067678: lw         $t5, 0x0($t5) */
".word 0x10430069\n\t" /* 8006767C: beq        $v0, $v1, .L80067824 */
".word 0x48828800\n\t" /* 80067680: mtc2      $v0, $17 ( handwritten instruction ) */
".word 0x488D6800\n\t" /* 80067684: mtc2       $t5, $13 ( handwritten instruction ) */
".word 0xAF2D0014\n\t" /* 80067688: sw         $t5, 0x14($t9) */
".word 0x000A6C02\n\t" /* 8006768C: srl        $t5, $t2, 16 */
".word 0x000D68C0\n\t" /* 80067690: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 80067694: addu       $t5, $t5, $a1 */
".word 0x8DA20004\n\t" /* 80067698: lw         $v0, 0x4($t5) */
".word 0x8DAD0000\n\t" /* 8006769C: lw         $t5, 0x0($t5) */
".word 0x10430060\n\t" /* 800676A0: beq        $v0, $v1, .L80067824 */
".word 0x48829000\n\t" /* 800676A4: mtc2      $v0, $18 ( handwritten instruction ) */
".word 0x488D7000\n\t" /* 800676A8: mtc2       $t5, $14 ( handwritten instruction ) */
".word 0xAF2D0020\n\t" /* 800676AC: sw         $t5, 0x20($t9) */
".word 0x000B6C02\n\t" /* 800676B0: srl        $t5, $t3, 16 */
".word 0x000D68C0\n\t" /* 800676B4: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 800676B8: addu       $t5, $t5, $a1 */
".word 0x8DA20004\n\t" /* 800676BC: lw         $v0, 0x4($t5) */
".word 0x8DAD0000\n\t" /* 800676C0: lw         $t5, 0x0($t5) */
".word 0x10430057\n\t" /* 800676C4: beq        $v0, $v1, .L80067824 */
".word 0x48829800\n\t" /* 800676C8: mtc2      $v0, $19 ( handwritten instruction ) */
".word 0xAF2D002C\n\t" /* 800676CC: sw         $t5, 0x2C($t9) */
".word 0x00084400\n\t" /* 800676D0: sll        $t0, $t0, 16 */
".word 0x00084342\n\t" /* 800676D4: srl        $t0, $t0, 13 */
".word 0x4B400006\n\t" /* 800676D8: nclip */
".word 0x00094C00\n\t" /* 800676DC: sll        $t1, $t1, 16 */
".word 0x4802C000\n\t" /* 800676E0: mfc2       $v0, $24 ( handwritten instruction ) */
".word 0x00094B42\n\t" /* 800676E4: srl        $t1, $t1, 13 */
".word 0x1C400009\n\t" /* 800676E8: bgtz       $v0, .L80067710 */
".word 0x00000000\n\t" /* 800676EC: nop */
".word 0x488D6000\n\t" /* 800676F0: mtc2       $t5, $12 ( handwritten instruction ) */
".word 0x00000000\n\t" /* 800676F4: nop */
".word 0x00000000\n\t" /* 800676F8: nop */
".word 0x4B400006\n\t" /* 800676FC: nclip */
".word 0x4802C000\n\t" /* 80067700: mfc2       $v0, $24 ( handwritten instruction ) */
".word 0x00000000\n\t" /* 80067704: nop */
".word 0x1C400046\n\t" /* 80067708: bgtz       $v0, .L80067824 */
".word 0x00000000\n\t" /* 8006770C: nop */
".L80067710:\n\t"
".word 0x000A5400\n\t" /* 80067710: sll        $t2, $t2, 16 */
".word 0x000A5342\n\t" /* 80067714: srl        $t2, $t2, 13 */
".word 0x000B5C00\n\t" /* 80067718: sll        $t3, $t3, 16 */
".word 0x000B5B42\n\t" /* 8006771C: srl        $t3, $t3, 13 */
".word 0x01064021\n\t" /* 80067720: addu       $t0, $t0, $a2 */
".word 0x01264821\n\t" /* 80067724: addu       $t1, $t1, $a2 */
".word 0x01465021\n\t" /* 80067728: addu       $t2, $t2, $a2 */
".word 0x01665821\n\t" /* 8006772C: addu       $t3, $t3, $a2 */
".word 0x8D080000\n\t" /* 80067730: lw         $t0, 0x0($t0) */
".word 0x8D290000\n\t" /* 80067734: lw         $t1, 0x0($t1) */
".word 0x8D4A0000\n\t" /* 80067738: lw         $t2, 0x0($t2) */
".word 0x8D6B0000\n\t" /* 8006773C: lw         $t3, 0x0($t3) */
".word 0x01134025\n\t" /* 80067740: or         $t0, $t0, $s3 */
".word 0xAF280004\n\t" /* 80067744: sw         $t0, 0x4($t9) */
".word 0xAF290010\n\t" /* 80067748: sw         $t1, 0x10($t9) */
".word 0xAF2A001C\n\t" /* 8006774C: sw         $t2, 0x1C($t9) */
".word 0xAF2B0028\n\t" /* 80067750: sw         $t3, 0x28($t9) */
".word 0x4B68002E\n\t" /* 80067754: avsz4 */
".word 0x8CE80000\n\t" /* 80067758: lw         $t0, 0x0($a3) */
".word 0x8CE90004\n\t" /* 8006775C: lw         $t1, 0x4($a3) */
".word 0x8CEA0008\n\t" /* 80067760: lw         $t2, 0x8($a3) */
".word 0x8CEB000C\n\t" /* 80067764: lw         $t3, 0xC($a3) */
".word 0x48023800\n\t" /* 80067768: mfc2       $v0, $7 ( handwritten instruction ) */
".word 0x3C010200\n\t" /* 8006776C: lui        $at, (0x2000000 >> 16) */
".word 0x02011824\n\t" /* 80067770: and        $v1, $s0, $at */
".word 0x01314825\n\t" /* 80067774: or         $t1, $t1, $s1 */
".word 0x01C21006\n\t" /* 80067778: srlv       $v0, $v0, $t6 */
".word 0x00021080\n\t" /* 8006777C: sll        $v0, $v0, 2 */
".word 0x004F1021\n\t" /* 80067780: addu       $v0, $v0, $t7 */
".word 0x8C4D0000\n\t" /* 80067784: lw         $t5, 0x0($v0) */
".L80067788:\n\t"
".word 0xAF28000C\n\t" /* 80067788: sw         $t0, 0xC($t9) */
".word 0xAF290018\n\t" /* 8006778C: sw         $t1, 0x18($t9) */
".word 0xAF2A0024\n\t" /* 80067790: sw         $t2, 0x24($t9) */
".word 0xAF2B0030\n\t" /* 80067794: sw         $t3, 0x30($t9) */
".word 0x000D6A00\n\t" /* 80067798: sll        $t5, $t5, 8 */
".word 0x35AD000C\n\t" /* 8006779C: ori        $t5, $t5, 0xC */
".word 0x000D0A02\n\t" /* 800677A0: srl        $at, $t5, 8 */
".word 0x000D6E00\n\t" /* 800677A4: sll        $t5, $t5, 24 */
".word 0x01A16825\n\t" /* 800677A8: or         $t5, $t5, $at */
".word 0xAF2D0000\n\t" /* 800677AC: sw         $t5, 0x0($t9) */
".word 0x00196A00\n\t" /* 800677B0: sll        $t5, $t9, 8 */
".word 0x000D6A02\n\t" /* 800677B4: srl        $t5, $t5, 8 */
".word 0x10600019\n\t" /* 800677B8: beqz       $v1, .L80067820 */
".word 0xAC4D0000\n\t" /* 800677BC: sw        $t5, 0x0($v0) */
".word 0x12400017\n\t" /* 800677C0: beqz       $s2, .L80067820 */
".word 0x00084400\n\t" /* 800677C4: sll       $t0, $t0, 16 */
".word 0x00084402\n\t" /* 800677C8: srl        $t0, $t0, 16 */
".word 0x01124025\n\t" /* 800677CC: or         $t0, $t0, $s2 */
".word 0x3C01FF9F\n\t" /* 800677D0: lui        $at, (0xFF9FFFFF >> 16) */
".word 0x3421FFFF\n\t" /* 800677D4: ori        $at, $at, (0xFF9FFFFF & 0xFFFF) */
".word 0x01214824\n\t" /* 800677D8: and        $t1, $t1, $at */
".word 0x3C010040\n\t" /* 800677DC: lui        $at, (0x400000 >> 16) */
".word 0x01214825\n\t" /* 800677E0: or         $t1, $t1, $at */
".word 0x8F230008\n\t" /* 800677E4: lw         $v1, 0x8($t9) */
".word 0xAF2C0038\n\t" /* 800677E8: sw         $t4, 0x38($t9) */
".word 0xAF23003C\n\t" /* 800677EC: sw         $v1, 0x3C($t9) */
".word 0x8F230014\n\t" /* 800677F0: lw         $v1, 0x14($t9) */
".word 0xAF2C0044\n\t" /* 800677F4: sw         $t4, 0x44($t9) */
".word 0xAF230048\n\t" /* 800677F8: sw         $v1, 0x48($t9) */
".word 0x8F230020\n\t" /* 800677FC: lw         $v1, 0x20($t9) */
".word 0xAF2C0050\n\t" /* 80067800: sw         $t4, 0x50($t9) */
".word 0xAF230054\n\t" /* 80067804: sw         $v1, 0x54($t9) */
".word 0x8F23002C\n\t" /* 80067808: lw         $v1, 0x2C($t9) */
".word 0xAF2C005C\n\t" /* 8006780C: sw         $t4, 0x5C($t9) */
".word 0xAF230060\n\t" /* 80067810: sw         $v1, 0x60($t9) */
".word 0x27390034\n\t" /* 80067814: addiu      $t9, $t9, 0x34 */
".word 0x08019DE2\n\t" /* 80067818: j          .L80067788 */
".word 0x24030000\n\t" /* 8006781C: addiu     $v1, $zero, 0x0 */
".L80067820:\n\t"
".word 0x27390034\n\t" /* 80067820: addiu      $t9, $t9, 0x34 */
".L80067824:\n\t"
".word 0x2718FFFF\n\t" /* 80067824: addiu      $t8, $t8, -0x1 */
".word 0x1700FF80\n\t" /* 80067828: bnez       $t8, .L8006762C */
".word 0x24E7001C\n\t" /* 8006782C: addiu     $a3, $a3, 0x1C */
".L80067830:\n\t"
".word 0x8C900028\n\t" /* 80067830: lw         $s0, 0x28($a0) */
".word 0x8C91002C\n\t" /* 80067834: lw         $s1, 0x2C($a0) */
".word 0x8C920030\n\t" /* 80067838: lw         $s2, 0x30($a0) */
".word 0x8C930034\n\t" /* 8006783C: lw         $s3, 0x34($a0) */
".word 0x8C820000\n\t" /* 80067840: lw         $v0, 0x0($a0) */
".word 0x3C018010\n\t" /* 80067844: lui        $at, %hi(D_800FE240) */
".word 0xAC39E240\n\t" /* 80067848: sw         $t9, %lo(D_800FE240)($at) */
".word 0x24420008\n\t" /* 8006784C: addiu      $v0, $v0, 0x8 */
".word 0x03E00008\n\t" /* 80067850: jr         $ra */
".word 0x00000000\n\t" /* 80067854: nop */
    ".set reorder\n"
);
