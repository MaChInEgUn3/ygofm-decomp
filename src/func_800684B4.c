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
    ".global func_800684B4\n"
    "func_800684B4:\n"
".word 0x8C870000\n\t" /* 800684B4: lw         $a3, 0x0($a0) */
".word 0x8C990010\n\t" /* 800684B8: lw         $t9, 0x10($a0) */
".word 0x94F80002\n\t" /* 800684BC: lhu        $t8, 0x2($a3) */
".word 0x8CE60004\n\t" /* 800684C0: lw         $a2, 0x4($a3) */
".word 0x8C850014\n\t" /* 800684C4: lw         $a1, 0x14($a0) */
".word 0x00063080\n\t" /* 800684C8: sll        $a2, $a2, 2 */
".word 0xAC900028\n\t" /* 800684CC: sw         $s0, 0x28($a0) */
".word 0xAC91002C\n\t" /* 800684D0: sw         $s1, 0x2C($a0) */
".word 0xAC920030\n\t" /* 800684D4: sw         $s2, 0x30($a0) */
".word 0xAC930034\n\t" /* 800684D8: sw         $s3, 0x34($a0) */
".word 0xAC940038\n\t" /* 800684DC: sw         $s4, 0x38($a0) */
".word 0xAC95003C\n\t" /* 800684E0: sw         $s5, 0x3C($a0) */
".word 0x13000091\n\t" /* 800684E4: beqz       $t8, .L8006872C */
".word 0x00A63821\n\t" /* 800684E8: addu      $a3, $a1, $a2 */
".word 0x3C10800A\n\t" /* 800684EC: lui        $s0, %hi(D_8009AFB8) */
".word 0x8E10AFB8\n\t" /* 800684F0: lw         $s0, %lo(D_8009AFB8)($s0) */
".word 0x3C11800A\n\t" /* 800684F4: lui        $s1, %hi(D_8009AFD8) */
".word 0x8E31AFD8\n\t" /* 800684F8: lw         $s1, %lo(D_8009AFD8)($s1) */
".word 0x3C12800A\n\t" /* 800684FC: lui        $s2, %hi(D_8009AFDC) */
".word 0x8E52AFDC\n\t" /* 80068500: lw         $s2, %lo(D_8009AFDC)($s2) */
".word 0x02006021\n\t" /* 80068504: addu       $t4, $s0, $zero */
".word 0x3C0D800A\n\t" /* 80068508: lui        $t5, %hi(D_8009AFE4) */
".word 0x81ADAFE4\n\t" /* 8006850C: lb         $t5, %lo(D_8009AFE4)($t5) */
".word 0x00109E02\n\t" /* 80068510: srl        $s3, $s0, 24 */
".word 0x00139E00\n\t" /* 80068514: sll        $s3, $s3, 24 */
".word 0x24010001\n\t" /* 80068518: addiu      $at, $zero, 0x1 */
".word 0x11A10083\n\t" /* 8006851C: beq        $t5, $at, .L8006872C */
".word 0x3C14E200\n\t" /* 80068520: lui       $s4, (0xE2000000 >> 16) */
".word 0x3C0D800A\n\t" /* 80068524: lui        $t5, %hi(D_8009AFE0) */
".word 0x8DADAFE0\n\t" /* 80068528: lw         $t5, %lo(D_8009AFE0)($t5) */
".word 0x8C85001C\n\t" /* 8006852C: lw         $a1, 0x1C($a0) */
".word 0x8C860024\n\t" /* 80068530: lw         $a2, 0x24($a0) */
".word 0x11A00002\n\t" /* 80068534: beqz       $t5, .L80068540 */
".word 0x00000000\n\t" /* 80068538: nop */
".word 0x24C60004\n\t" /* 8006853C: addiu      $a2, $a2, 0x4 */
".L80068540:\n\t"
".word 0x8C8D0004\n\t" /* 80068540: lw         $t5, 0x4($a0) */
".word 0x8C8E0008\n\t" /* 80068544: lw         $t6, 0x8($a0) */
".word 0x8DAF0004\n\t" /* 80068548: lw         $t7, 0x4($t5) */
".L8006854C:\n\t"
".word 0x2403FFFF\n\t" /* 8006854C: addiu      $v1, $zero, -0x1 */
".word 0x8CE80010\n\t" /* 80068550: lw         $t0, 0x10($a3) */
".word 0x98E8000E\n\t" /* 80068554: lwr        $t0, 0xE($a3) */
".word 0x8CE90014\n\t" /* 80068558: lw         $t1, 0x14($a3) */
".word 0x8CEA0018\n\t" /* 8006855C: lw         $t2, 0x18($a3) */
".word 0x8CEB001C\n\t" /* 80068560: lw         $t3, 0x1C($a3) */
".word 0x00086C02\n\t" /* 80068564: srl        $t5, $t0, 16 */
".word 0x000D68C0\n\t" /* 80068568: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 8006856C: addu       $t5, $t5, $a1 */
".word 0x8DA20004\n\t" /* 80068570: lw         $v0, 0x4($t5) */
".word 0x8DAD0000\n\t" /* 80068574: lw         $t5, 0x0($t5) */
".word 0x10430069\n\t" /* 80068578: beq        $v0, $v1, .L80068720 */
".word 0x48828000\n\t" /* 8006857C: mtc2      $v0, $16 ( handwritten instruction ) */
".word 0x488D6000\n\t" /* 80068580: mtc2       $t5, $12 ( handwritten instruction ) */
".word 0xAF2D000C\n\t" /* 80068584: sw         $t5, 0xC($t9) */
".word 0x00096C02\n\t" /* 80068588: srl        $t5, $t1, 16 */
".word 0x000D68C0\n\t" /* 8006858C: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 80068590: addu       $t5, $t5, $a1 */
".word 0x8DA20004\n\t" /* 80068594: lw         $v0, 0x4($t5) */
".word 0x8DAD0000\n\t" /* 80068598: lw         $t5, 0x0($t5) */
".word 0x10430060\n\t" /* 8006859C: beq        $v0, $v1, .L80068720 */
".word 0x48828800\n\t" /* 800685A0: mtc2      $v0, $17 ( handwritten instruction ) */
".word 0x488D6800\n\t" /* 800685A4: mtc2       $t5, $13 ( handwritten instruction ) */
".word 0xAF2D0018\n\t" /* 800685A8: sw         $t5, 0x18($t9) */
".word 0x000A6C02\n\t" /* 800685AC: srl        $t5, $t2, 16 */
".word 0x000D68C0\n\t" /* 800685B0: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 800685B4: addu       $t5, $t5, $a1 */
".word 0x8DA20004\n\t" /* 800685B8: lw         $v0, 0x4($t5) */
".word 0x8DAD0000\n\t" /* 800685BC: lw         $t5, 0x0($t5) */
".word 0x10430057\n\t" /* 800685C0: beq        $v0, $v1, .L80068720 */
".word 0x48829000\n\t" /* 800685C4: mtc2      $v0, $18 ( handwritten instruction ) */
".word 0x488D7000\n\t" /* 800685C8: mtc2       $t5, $14 ( handwritten instruction ) */
".word 0xAF2D0024\n\t" /* 800685CC: sw         $t5, 0x24($t9) */
".word 0x000B6C02\n\t" /* 800685D0: srl        $t5, $t3, 16 */
".word 0x000D68C0\n\t" /* 800685D4: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 800685D8: addu       $t5, $t5, $a1 */
".word 0x8DA20004\n\t" /* 800685DC: lw         $v0, 0x4($t5) */
".word 0x8DAD0000\n\t" /* 800685E0: lw         $t5, 0x0($t5) */
".word 0x1043004E\n\t" /* 800685E4: beq        $v0, $v1, .L80068720 */
".word 0x48829800\n\t" /* 800685E8: mtc2      $v0, $19 ( handwritten instruction ) */
".word 0xAF2D0030\n\t" /* 800685EC: sw         $t5, 0x30($t9) */
".word 0x00084400\n\t" /* 800685F0: sll        $t0, $t0, 16 */
".word 0x00084342\n\t" /* 800685F4: srl        $t0, $t0, 13 */
".word 0x00094C00\n\t" /* 800685F8: sll        $t1, $t1, 16 */
".word 0x00094B42\n\t" /* 800685FC: srl        $t1, $t1, 13 */
".word 0x000A5400\n\t" /* 80068600: sll        $t2, $t2, 16 */
".word 0x000A5342\n\t" /* 80068604: srl        $t2, $t2, 13 */
".word 0x000B5C00\n\t" /* 80068608: sll        $t3, $t3, 16 */
".word 0x000B5B42\n\t" /* 8006860C: srl        $t3, $t3, 13 */
".word 0x01064021\n\t" /* 80068610: addu       $t0, $t0, $a2 */
".word 0x01264821\n\t" /* 80068614: addu       $t1, $t1, $a2 */
".word 0x01465021\n\t" /* 80068618: addu       $t2, $t2, $a2 */
".word 0x01665821\n\t" /* 8006861C: addu       $t3, $t3, $a2 */
".word 0x8D080000\n\t" /* 80068620: lw         $t0, 0x0($t0) */
".word 0x8D290000\n\t" /* 80068624: lw         $t1, 0x0($t1) */
".word 0x8D4A0000\n\t" /* 80068628: lw         $t2, 0x0($t2) */
".word 0x8D6B0000\n\t" /* 8006862C: lw         $t3, 0x0($t3) */
".word 0x01134025\n\t" /* 80068630: or         $t0, $t0, $s3 */
".word 0xAF280008\n\t" /* 80068634: sw         $t0, 0x8($t9) */
".word 0xAF290014\n\t" /* 80068638: sw         $t1, 0x14($t9) */
".word 0xAF2A0020\n\t" /* 8006863C: sw         $t2, 0x20($t9) */
".word 0xAF2B002C\n\t" /* 80068640: sw         $t3, 0x2C($t9) */
".word 0x4B68002E\n\t" /* 80068644: avsz4 */
".word 0x8CF50000\n\t" /* 80068648: lw         $s5, 0x0($a3) */
".word 0x8CE80004\n\t" /* 8006864C: lw         $t0, 0x4($a3) */
".word 0x8CE90008\n\t" /* 80068650: lw         $t1, 0x8($a3) */
".word 0x8CEA000C\n\t" /* 80068654: lw         $t2, 0xC($a3) */
".word 0x8CEB0010\n\t" /* 80068658: lw         $t3, 0x10($a3) */
".word 0x48023800\n\t" /* 8006865C: mfc2       $v0, $7 ( handwritten instruction ) */
".word 0x3C010200\n\t" /* 80068660: lui        $at, (0x2000000 >> 16) */
".word 0x02011824\n\t" /* 80068664: and        $v1, $s0, $at */
".word 0x01314825\n\t" /* 80068668: or         $t1, $t1, $s1 */
".word 0x01C21006\n\t" /* 8006866C: srlv       $v0, $v0, $t6 */
".word 0x00021080\n\t" /* 80068670: sll        $v0, $v0, 2 */
".word 0x004F1021\n\t" /* 80068674: addu       $v0, $v0, $t7 */
".word 0x8C4D0000\n\t" /* 80068678: lw         $t5, 0x0($v0) */
".L8006867C:\n\t"
".word 0xAF280010\n\t" /* 8006867C: sw         $t0, 0x10($t9) */
".word 0xAF29001C\n\t" /* 80068680: sw         $t1, 0x1C($t9) */
".word 0xAF2A0028\n\t" /* 80068684: sw         $t2, 0x28($t9) */
".word 0xAF2B0034\n\t" /* 80068688: sw         $t3, 0x34($t9) */
".word 0xAF350004\n\t" /* 8006868C: sw         $s5, 0x4($t9) */
".word 0xAF340038\n\t" /* 80068690: sw         $s4, 0x38($t9) */
".word 0x000D6A00\n\t" /* 80068694: sll        $t5, $t5, 8 */
".word 0x35AD000E\n\t" /* 80068698: ori        $t5, $t5, 0xE */
".word 0x000D0A02\n\t" /* 8006869C: srl        $at, $t5, 8 */
".word 0x000D6E00\n\t" /* 800686A0: sll        $t5, $t5, 24 */
".word 0x01A16825\n\t" /* 800686A4: or         $t5, $t5, $at */
".word 0xAF2D0000\n\t" /* 800686A8: sw         $t5, 0x0($t9) */
".word 0x00196A00\n\t" /* 800686AC: sll        $t5, $t9, 8 */
".word 0x000D6A02\n\t" /* 800686B0: srl        $t5, $t5, 8 */
".word 0x10600019\n\t" /* 800686B4: beqz       $v1, .L8006871C */
".word 0xAC4D0000\n\t" /* 800686B8: sw        $t5, 0x0($v0) */
".word 0x12400017\n\t" /* 800686BC: beqz       $s2, .L8006871C */
".word 0x00084400\n\t" /* 800686C0: sll       $t0, $t0, 16 */
".word 0x00084402\n\t" /* 800686C4: srl        $t0, $t0, 16 */
".word 0x01124025\n\t" /* 800686C8: or         $t0, $t0, $s2 */
".word 0x3C01FF9F\n\t" /* 800686CC: lui        $at, (0xFF9FFFFF >> 16) */
".word 0x3421FFFF\n\t" /* 800686D0: ori        $at, $at, (0xFF9FFFFF & 0xFFFF) */
".word 0x01214824\n\t" /* 800686D4: and        $t1, $t1, $at */
".word 0x3C010040\n\t" /* 800686D8: lui        $at, (0x400000 >> 16) */
".word 0x01214825\n\t" /* 800686DC: or         $t1, $t1, $at */
".word 0x8F23000C\n\t" /* 800686E0: lw         $v1, 0xC($t9) */
".word 0xAF2C0044\n\t" /* 800686E4: sw         $t4, 0x44($t9) */
".word 0xAF230048\n\t" /* 800686E8: sw         $v1, 0x48($t9) */
".word 0x8F230018\n\t" /* 800686EC: lw         $v1, 0x18($t9) */
".word 0xAF2C0050\n\t" /* 800686F0: sw         $t4, 0x50($t9) */
".word 0xAF230054\n\t" /* 800686F4: sw         $v1, 0x54($t9) */
".word 0x8F230024\n\t" /* 800686F8: lw         $v1, 0x24($t9) */
".word 0xAF2C005C\n\t" /* 800686FC: sw         $t4, 0x5C($t9) */
".word 0xAF230060\n\t" /* 80068700: sw         $v1, 0x60($t9) */
".word 0x8F230030\n\t" /* 80068704: lw         $v1, 0x30($t9) */
".word 0xAF2C0068\n\t" /* 80068708: sw         $t4, 0x68($t9) */
".word 0xAF23006C\n\t" /* 8006870C: sw         $v1, 0x6C($t9) */
".word 0x2739003C\n\t" /* 80068710: addiu      $t9, $t9, 0x3C */
".word 0x0801A19F\n\t" /* 80068714: j          .L8006867C */
".word 0x24030000\n\t" /* 80068718: addiu     $v1, $zero, 0x0 */
".L8006871C:\n\t"
".word 0x2739003C\n\t" /* 8006871C: addiu      $t9, $t9, 0x3C */
".L80068720:\n\t"
".word 0x2718FFFF\n\t" /* 80068720: addiu      $t8, $t8, -0x1 */
".word 0x1700FF89\n\t" /* 80068724: bnez       $t8, .L8006854C */
".word 0x24E70020\n\t" /* 80068728: addiu     $a3, $a3, 0x20 */
".L8006872C:\n\t"
".word 0x8C900028\n\t" /* 8006872C: lw         $s0, 0x28($a0) */
".word 0x8C91002C\n\t" /* 80068730: lw         $s1, 0x2C($a0) */
".word 0x8C920030\n\t" /* 80068734: lw         $s2, 0x30($a0) */
".word 0x8C930034\n\t" /* 80068738: lw         $s3, 0x34($a0) */
".word 0x8C940038\n\t" /* 8006873C: lw         $s4, 0x38($a0) */
".word 0x8C95003C\n\t" /* 80068740: lw         $s5, 0x3C($a0) */
".word 0x8C820000\n\t" /* 80068744: lw         $v0, 0x0($a0) */
".word 0x3C018010\n\t" /* 80068748: lui        $at, %hi(D_800FE240) */
".word 0xAC39E240\n\t" /* 8006874C: sw         $t9, %lo(D_800FE240)($at) */
".word 0x24420008\n\t" /* 80068750: addiu      $v0, $v0, 0x8 */
".word 0x03E00008\n\t" /* 80068754: jr         $ra */
".word 0x00000000\n\t" /* 80068758: nop */
    ".set reorder\n"
);
