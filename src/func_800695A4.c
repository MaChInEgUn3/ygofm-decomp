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
    ".global func_800695A4\n"
    "func_800695A4:\n"
".word 0x8C870000\n\t" /* 800695A4: lw         $a3, 0x0($a0) */
".word 0x8C990010\n\t" /* 800695A8: lw         $t9, 0x10($a0) */
".word 0x94F80002\n\t" /* 800695AC: lhu        $t8, 0x2($a3) */
".word 0x8CE60004\n\t" /* 800695B0: lw         $a2, 0x4($a3) */
".word 0x8C850014\n\t" /* 800695B4: lw         $a1, 0x14($a0) */
".word 0x00063080\n\t" /* 800695B8: sll        $a2, $a2, 2 */
".word 0xAC900028\n\t" /* 800695BC: sw         $s0, 0x28($a0) */
".word 0xAC91002C\n\t" /* 800695C0: sw         $s1, 0x2C($a0) */
".word 0xAC920030\n\t" /* 800695C4: sw         $s2, 0x30($a0) */
".word 0xAC930034\n\t" /* 800695C8: sw         $s3, 0x34($a0) */
".word 0x130000A5\n\t" /* 800695CC: beqz       $t8, .L80069864 */
".word 0x00A63821\n\t" /* 800695D0: addu      $a3, $a1, $a2 */
".word 0x3C10800A\n\t" /* 800695D4: lui        $s0, %hi(D_8009AFB8) */
".word 0x8E10AFB8\n\t" /* 800695D8: lw         $s0, %lo(D_8009AFB8)($s0) */
".word 0x3C11800A\n\t" /* 800695DC: lui        $s1, %hi(D_8009AFD8) */
".word 0x8E31AFD8\n\t" /* 800695E0: lw         $s1, %lo(D_8009AFD8)($s1) */
".word 0x3C12800A\n\t" /* 800695E4: lui        $s2, %hi(D_8009AFDC) */
".word 0x8E52AFDC\n\t" /* 800695E8: lw         $s2, %lo(D_8009AFDC)($s2) */
".word 0x02006021\n\t" /* 800695EC: addu       $t4, $s0, $zero */
".word 0x3C02800A\n\t" /* 800695F0: lui        $v0, %hi(D_8009AFE5) */
".word 0x8042AFE5\n\t" /* 800695F4: lb         $v0, %lo(D_8009AFE5)($v0) */
".word 0x3C010200\n\t" /* 800695F8: lui        $at, (0x2000000 >> 16) */
".word 0x02018025\n\t" /* 800695FC: or         $s0, $s0, $at */
".word 0x1440000E\n\t" /* 80069600: bnez       $v0, .L8006963C */
".word 0x02006021\n\t" /* 80069604: addu      $t4, $s0, $zero */
".word 0x8CF10004\n\t" /* 80069608: lw         $s1, 0x4($a3) */
".word 0x3C010060\n\t" /* 8006960C: lui        $at, (0x600000 >> 16) */
".word 0x02218824\n\t" /* 80069610: and        $s1, $s1, $at */
".word 0x16200009\n\t" /* 80069614: bnez       $s1, .L8006963C */
".word 0x00000000\n\t" /* 80069618: nop */
".word 0x12400008\n\t" /* 8006961C: beqz       $s2, .L80069640 */
".word 0x00000000\n\t" /* 80069620: nop */
".word 0x94F20002\n\t" /* 80069624: lhu        $s2, 0x2($a3) */
".word 0x3C0C800A\n\t" /* 80069628: lui        $t4, %hi(D_8009AFC8) */
".word 0x8D8CAFC8\n\t" /* 8006962C: lw         $t4, %lo(D_8009AFC8)($t4) */
".word 0x00129400\n\t" /* 80069630: sll        $s2, $s2, 16 */
".word 0x0801A590\n\t" /* 80069634: j          .L80069640 */
".word 0x3C110020\n\t" /* 80069638: lui       $s1, (0x200000 >> 16) */
".L8006963C:\n\t"
".word 0x24120000\n\t" /* 8006963C: addiu      $s2, $zero, 0x0 */
".L80069640:\n\t"
".word 0x3C0D800A\n\t" /* 80069640: lui        $t5, %hi(D_8009AFE4) */
".word 0x81ADAFE4\n\t" /* 80069644: lb         $t5, %lo(D_8009AFE4)($t5) */
".word 0x00109E02\n\t" /* 80069648: srl        $s3, $s0, 24 */
".word 0x00139E00\n\t" /* 8006964C: sll        $s3, $s3, 24 */
".word 0x24010001\n\t" /* 80069650: addiu      $at, $zero, 0x1 */
".word 0x11A10083\n\t" /* 80069654: beq        $t5, $at, .L80069864 */
".word 0x00000000\n\t" /* 80069658: nop */
".word 0x3C0D800A\n\t" /* 8006965C: lui        $t5, %hi(D_8009AFE0) */
".word 0x8DADAFE0\n\t" /* 80069660: lw         $t5, %lo(D_8009AFE0)($t5) */
".word 0x8C85001C\n\t" /* 80069664: lw         $a1, 0x1C($a0) */
".word 0x8C860024\n\t" /* 80069668: lw         $a2, 0x24($a0) */
".word 0x11A00002\n\t" /* 8006966C: beqz       $t5, .L80069678 */
".word 0x00000000\n\t" /* 80069670: nop */
".word 0x24C60004\n\t" /* 80069674: addiu      $a2, $a2, 0x4 */
".L80069678:\n\t"
".word 0x8C8D0004\n\t" /* 80069678: lw         $t5, 0x4($a0) */
".word 0x8C8E0008\n\t" /* 8006967C: lw         $t6, 0x8($a0) */
".word 0x8DAF0004\n\t" /* 80069680: lw         $t7, 0x4($t5) */
".L80069684:\n\t"
".word 0x2403FFFF\n\t" /* 80069684: addiu      $v1, $zero, -0x1 */
".word 0x8CE8000C\n\t" /* 80069688: lw         $t0, 0xC($a3) */
".word 0x98E8000A\n\t" /* 8006968C: lwr        $t0, 0xA($a3) */
".word 0x8CE90010\n\t" /* 80069690: lw         $t1, 0x10($a3) */
".word 0x8CEA0014\n\t" /* 80069694: lw         $t2, 0x14($a3) */
".word 0x8CEB0018\n\t" /* 80069698: lw         $t3, 0x18($a3) */
".word 0x00086C02\n\t" /* 8006969C: srl        $t5, $t0, 16 */
".word 0x000D68C0\n\t" /* 800696A0: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 800696A4: addu       $t5, $t5, $a1 */
".word 0x8DA20004\n\t" /* 800696A8: lw         $v0, 0x4($t5) */
".word 0x8DAD0000\n\t" /* 800696AC: lw         $t5, 0x0($t5) */
".word 0x10430069\n\t" /* 800696B0: beq        $v0, $v1, .L80069858 */
".word 0x48828000\n\t" /* 800696B4: mtc2      $v0, $16 ( handwritten instruction ) */
".word 0x488D6000\n\t" /* 800696B8: mtc2       $t5, $12 ( handwritten instruction ) */
".word 0xAF2D0008\n\t" /* 800696BC: sw         $t5, 0x8($t9) */
".word 0x00096C02\n\t" /* 800696C0: srl        $t5, $t1, 16 */
".word 0x000D68C0\n\t" /* 800696C4: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 800696C8: addu       $t5, $t5, $a1 */
".word 0x8DA20004\n\t" /* 800696CC: lw         $v0, 0x4($t5) */
".word 0x8DAD0000\n\t" /* 800696D0: lw         $t5, 0x0($t5) */
".word 0x10430060\n\t" /* 800696D4: beq        $v0, $v1, .L80069858 */
".word 0x48828800\n\t" /* 800696D8: mtc2      $v0, $17 ( handwritten instruction ) */
".word 0x488D6800\n\t" /* 800696DC: mtc2       $t5, $13 ( handwritten instruction ) */
".word 0xAF2D0014\n\t" /* 800696E0: sw         $t5, 0x14($t9) */
".word 0x000A6C02\n\t" /* 800696E4: srl        $t5, $t2, 16 */
".word 0x000D68C0\n\t" /* 800696E8: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 800696EC: addu       $t5, $t5, $a1 */
".word 0x8DA20004\n\t" /* 800696F0: lw         $v0, 0x4($t5) */
".word 0x8DAD0000\n\t" /* 800696F4: lw         $t5, 0x0($t5) */
".word 0x10430057\n\t" /* 800696F8: beq        $v0, $v1, .L80069858 */
".word 0x48829000\n\t" /* 800696FC: mtc2      $v0, $18 ( handwritten instruction ) */
".word 0x488D7000\n\t" /* 80069700: mtc2       $t5, $14 ( handwritten instruction ) */
".word 0xAF2D0020\n\t" /* 80069704: sw         $t5, 0x20($t9) */
".word 0x000B6C02\n\t" /* 80069708: srl        $t5, $t3, 16 */
".word 0x000D68C0\n\t" /* 8006970C: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 80069710: addu       $t5, $t5, $a1 */
".word 0x8DA20004\n\t" /* 80069714: lw         $v0, 0x4($t5) */
".word 0x8DAD0000\n\t" /* 80069718: lw         $t5, 0x0($t5) */
".word 0x1043004E\n\t" /* 8006971C: beq        $v0, $v1, .L80069858 */
".word 0x48829800\n\t" /* 80069720: mtc2      $v0, $19 ( handwritten instruction ) */
".word 0xAF2D002C\n\t" /* 80069724: sw         $t5, 0x2C($t9) */
".word 0x00084400\n\t" /* 80069728: sll        $t0, $t0, 16 */
".word 0x00084342\n\t" /* 8006972C: srl        $t0, $t0, 13 */
".word 0x00094C00\n\t" /* 80069730: sll        $t1, $t1, 16 */
".word 0x00094B42\n\t" /* 80069734: srl        $t1, $t1, 13 */
".word 0x000A5400\n\t" /* 80069738: sll        $t2, $t2, 16 */
".word 0x000A5342\n\t" /* 8006973C: srl        $t2, $t2, 13 */
".word 0x000B5C00\n\t" /* 80069740: sll        $t3, $t3, 16 */
".word 0x000B5B42\n\t" /* 80069744: srl        $t3, $t3, 13 */
".word 0x01064021\n\t" /* 80069748: addu       $t0, $t0, $a2 */
".word 0x01264821\n\t" /* 8006974C: addu       $t1, $t1, $a2 */
".word 0x01465021\n\t" /* 80069750: addu       $t2, $t2, $a2 */
".word 0x01665821\n\t" /* 80069754: addu       $t3, $t3, $a2 */
".word 0x8D080000\n\t" /* 80069758: lw         $t0, 0x0($t0) */
".word 0x8D290000\n\t" /* 8006975C: lw         $t1, 0x0($t1) */
".word 0x8D4A0000\n\t" /* 80069760: lw         $t2, 0x0($t2) */
".word 0x8D6B0000\n\t" /* 80069764: lw         $t3, 0x0($t3) */
".word 0x4B68002E\n\t" /* 80069768: avsz4 */
".word 0x01134025\n\t" /* 8006976C: or         $t0, $t0, $s3 */
".word 0xAF280004\n\t" /* 80069770: sw         $t0, 0x4($t9) */
".word 0xAF290010\n\t" /* 80069774: sw         $t1, 0x10($t9) */
".word 0xAF2A001C\n\t" /* 80069778: sw         $t2, 0x1C($t9) */
".word 0xAF2B0028\n\t" /* 8006977C: sw         $t3, 0x28($t9) */
".word 0x8CE80000\n\t" /* 80069780: lw         $t0, 0x0($a3) */
".word 0x8CE90004\n\t" /* 80069784: lw         $t1, 0x4($a3) */
".word 0x8CEA0008\n\t" /* 80069788: lw         $t2, 0x8($a3) */
".word 0x8CEB000C\n\t" /* 8006978C: lw         $t3, 0xC($a3) */
".word 0x48023800\n\t" /* 80069790: mfc2       $v0, $7 ( handwritten instruction ) */
".word 0x3C010200\n\t" /* 80069794: lui        $at, (0x2000000 >> 16) */
".word 0x02011824\n\t" /* 80069798: and        $v1, $s0, $at */
".word 0x3C01FF9F\n\t" /* 8006979C: lui        $at, (0xFF9FFFFF >> 16) */
".word 0x3421FFFF\n\t" /* 800697A0: ori        $at, $at, (0xFF9FFFFF & 0xFFFF) */
".word 0x01214824\n\t" /* 800697A4: and        $t1, $t1, $at */
".word 0x01314825\n\t" /* 800697A8: or         $t1, $t1, $s1 */
".word 0x01C21006\n\t" /* 800697AC: srlv       $v0, $v0, $t6 */
".word 0x00021080\n\t" /* 800697B0: sll        $v0, $v0, 2 */
".word 0x004F1021\n\t" /* 800697B4: addu       $v0, $v0, $t7 */
".word 0x8C4D0000\n\t" /* 800697B8: lw         $t5, 0x0($v0) */
".L800697BC:\n\t"
".word 0xAF28000C\n\t" /* 800697BC: sw         $t0, 0xC($t9) */
".word 0xAF290018\n\t" /* 800697C0: sw         $t1, 0x18($t9) */
".word 0xAF2A0024\n\t" /* 800697C4: sw         $t2, 0x24($t9) */
".word 0xAF2B0030\n\t" /* 800697C8: sw         $t3, 0x30($t9) */
".word 0x000D6A00\n\t" /* 800697CC: sll        $t5, $t5, 8 */
".word 0x35AD000C\n\t" /* 800697D0: ori        $t5, $t5, 0xC */
".word 0x000D0A02\n\t" /* 800697D4: srl        $at, $t5, 8 */
".word 0x000D6E00\n\t" /* 800697D8: sll        $t5, $t5, 24 */
".word 0x01A16825\n\t" /* 800697DC: or         $t5, $t5, $at */
".word 0xAF2D0000\n\t" /* 800697E0: sw         $t5, 0x0($t9) */
".word 0x00196A00\n\t" /* 800697E4: sll        $t5, $t9, 8 */
".word 0x000D6A02\n\t" /* 800697E8: srl        $t5, $t5, 8 */
".word 0x10600019\n\t" /* 800697EC: beqz       $v1, .L80069854 */
".word 0xAC4D0000\n\t" /* 800697F0: sw        $t5, 0x0($v0) */
".word 0x12400017\n\t" /* 800697F4: beqz       $s2, .L80069854 */
".word 0x00084400\n\t" /* 800697F8: sll       $t0, $t0, 16 */
".word 0x00084402\n\t" /* 800697FC: srl        $t0, $t0, 16 */
".word 0x01124025\n\t" /* 80069800: or         $t0, $t0, $s2 */
".word 0x3C01FF9F\n\t" /* 80069804: lui        $at, (0xFF9FFFFF >> 16) */
".word 0x3421FFFF\n\t" /* 80069808: ori        $at, $at, (0xFF9FFFFF & 0xFFFF) */
".word 0x01214824\n\t" /* 8006980C: and        $t1, $t1, $at */
".word 0x3C010040\n\t" /* 80069810: lui        $at, (0x400000 >> 16) */
".word 0x01214825\n\t" /* 80069814: or         $t1, $t1, $at */
".word 0x8F230008\n\t" /* 80069818: lw         $v1, 0x8($t9) */
".word 0xAF2C0038\n\t" /* 8006981C: sw         $t4, 0x38($t9) */
".word 0xAF23003C\n\t" /* 80069820: sw         $v1, 0x3C($t9) */
".word 0x8F230014\n\t" /* 80069824: lw         $v1, 0x14($t9) */
".word 0xAF2C0044\n\t" /* 80069828: sw         $t4, 0x44($t9) */
".word 0xAF230048\n\t" /* 8006982C: sw         $v1, 0x48($t9) */
".word 0x8F230020\n\t" /* 80069830: lw         $v1, 0x20($t9) */
".word 0xAF2C0050\n\t" /* 80069834: sw         $t4, 0x50($t9) */
".word 0xAF230054\n\t" /* 80069838: sw         $v1, 0x54($t9) */
".word 0x8F23002C\n\t" /* 8006983C: lw         $v1, 0x2C($t9) */
".word 0xAF2C005C\n\t" /* 80069840: sw         $t4, 0x5C($t9) */
".word 0xAF230060\n\t" /* 80069844: sw         $v1, 0x60($t9) */
".word 0x27390034\n\t" /* 80069848: addiu      $t9, $t9, 0x34 */
".word 0x0801A5EF\n\t" /* 8006984C: j          .L800697BC */
".word 0x24030000\n\t" /* 80069850: addiu     $v1, $zero, 0x0 */
".L80069854:\n\t"
".word 0x27390034\n\t" /* 80069854: addiu      $t9, $t9, 0x34 */
".L80069858:\n\t"
".word 0x2718FFFF\n\t" /* 80069858: addiu      $t8, $t8, -0x1 */
".word 0x1700FF89\n\t" /* 8006985C: bnez       $t8, .L80069684 */
".word 0x24E7001C\n\t" /* 80069860: addiu     $a3, $a3, 0x1C */
".L80069864:\n\t"
".word 0x8C900028\n\t" /* 80069864: lw         $s0, 0x28($a0) */
".word 0x8C91002C\n\t" /* 80069868: lw         $s1, 0x2C($a0) */
".word 0x8C920030\n\t" /* 8006986C: lw         $s2, 0x30($a0) */
".word 0x8C930034\n\t" /* 80069870: lw         $s3, 0x34($a0) */
".word 0x8C820000\n\t" /* 80069874: lw         $v0, 0x0($a0) */
".word 0x3C018010\n\t" /* 80069878: lui        $at, %hi(D_800FE240) */
".word 0xAC39E240\n\t" /* 8006987C: sw         $t9, %lo(D_800FE240)($at) */
".word 0x24420008\n\t" /* 80069880: addiu      $v0, $v0, 0x8 */
".word 0x03E00008\n\t" /* 80069884: jr         $ra */
".word 0x00000000\n\t" /* 80069888: nop */
    ".set reorder\n"
);
