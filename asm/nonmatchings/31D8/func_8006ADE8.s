/* Handwritten function */
nonmatching func_8006ADE8, 0x18C

glabel func_8006ADE8
    /* 5B5E8 8006ADE8 0000878C */  lw         $a3, 0x0($a0)
    /* 5B5EC 8006ADEC 1000998C */  lw         $t9, 0x10($a0)
    /* 5B5F0 8006ADF0 0200F894 */  lhu        $t8, 0x2($a3)
    /* 5B5F4 8006ADF4 0400E68C */  lw         $a2, 0x4($a3)
    /* 5B5F8 8006ADF8 1400858C */  lw         $a1, 0x14($a0)
    /* 5B5FC 8006ADFC 80300600 */  sll        $a2, $a2, 2
    /* 5B600 8006AE00 280090AC */  sw         $s0, 0x28($a0)
    /* 5B604 8006AE04 2C0091AC */  sw         $s1, 0x2C($a0)
    /* 5B608 8006AE08 300092AC */  sw         $s2, 0x30($a0)
    /* 5B60C 8006AE0C 0A800D3C */  lui        $t5, %hi(D_8009AFE4)
    /* 5B610 8006AE10 E4AFAD8D */  lw         $t5, %lo(D_8009AFE4)($t5)
    /* 5B614 8006AE14 4E000013 */  beqz       $t8, .L8006AF50
    /* 5B618 8006AE18 00000000 */   nop
    /* 5B61C 8006AE1C 01000124 */  addiu      $at, $zero, 0x1
    /* 5B620 8006AE20 4B00A111 */  beq        $t5, $at, .L8006AF50
    /* 5B624 8006AE24 2138A600 */   addu      $a3, $a1, $a2
    /* 5B628 8006AE28 0A80103C */  lui        $s0, %hi(D_8009AFCC)
    /* 5B62C 8006AE2C CCAF108E */  lw         $s0, %lo(D_8009AFCC)($s0)
    /* 5B630 8006AE30 0A80113C */  lui        $s1, %hi(D_8009AFD4)
    /* 5B634 8006AE34 D4AF318E */  lw         $s1, %lo(D_8009AFD4)($s1)
    /* 5B638 8006AE38 5555123C */  lui        $s2, (0x55555555 >> 16)
    /* 5B63C 8006AE3C 55555236 */  ori        $s2, $s2, (0x55555555 & 0xFFFF)
    /* 5B640 8006AE40 1C00858C */  lw         $a1, 0x1C($a0)
    /* 5B644 8006AE44 2400868C */  lw         $a2, 0x24($a0)
    /* 5B648 8006AE48 04008D8C */  lw         $t5, 0x4($a0)
    /* 5B64C 8006AE4C 08008E8C */  lw         $t6, 0x8($a0)
    /* 5B650 8006AE50 0400AF8D */  lw         $t7, 0x4($t5)
  .L8006AE54:
    /* 5B654 8006AE54 FFFF0324 */  addiu      $v1, $zero, -0x1
    /* 5B658 8006AE58 1000E88C */  lw         $t0, 0x10($a3)
    /* 5B65C 8006AE5C 1400E98C */  lw         $t1, 0x14($a3)
    /* 5B660 8006AE60 1800EA8C */  lw         $t2, 0x18($a3)
    /* 5B664 8006AE64 1C00EB8C */  lw         $t3, 0x1C($a3)
    /* 5B668 8006AE68 026C0800 */  srl        $t5, $t0, 16
    /* 5B66C 8006AE6C C0680D00 */  sll        $t5, $t5, 3
    /* 5B670 8006AE70 2168A501 */  addu       $t5, $t5, $a1
    /* 5B674 8006AE74 0400A28D */  lw         $v0, 0x4($t5)
    /* 5B678 8006AE78 0000AD8D */  lw         $t5, 0x0($t5)
    /* 5B67C 8006AE7C 31004310 */  beq        $v0, $v1, .L8006AF44
    /* 5B680 8006AE80 0C002DAF */   sw        $t5, 0xC($t9)
    /* 5B684 8006AE84 00808248 */  mtc2       $v0, $16 /* handwritten instruction */
    /* 5B688 8006AE88 28002DAF */  sw         $t5, 0x28($t9)
    /* 5B68C 8006AE8C 026C0900 */  srl        $t5, $t1, 16
    /* 5B690 8006AE90 C0680D00 */  sll        $t5, $t5, 3
    /* 5B694 8006AE94 2168A501 */  addu       $t5, $t5, $a1
    /* 5B698 8006AE98 0400A28D */  lw         $v0, 0x4($t5)
    /* 5B69C 8006AE9C 0000AD8D */  lw         $t5, 0x0($t5)
    /* 5B6A0 8006AEA0 28004310 */  beq        $v0, $v1, .L8006AF44
    /* 5B6A4 8006AEA4 10002DAF */   sw        $t5, 0x10($t9)
    /* 5B6A8 8006AEA8 00888248 */  mtc2       $v0, $17 /* handwritten instruction */
    /* 5B6AC 8006AEAC 026C0A00 */  srl        $t5, $t2, 16
    /* 5B6B0 8006AEB0 C0680D00 */  sll        $t5, $t5, 3
    /* 5B6B4 8006AEB4 2168A501 */  addu       $t5, $t5, $a1
    /* 5B6B8 8006AEB8 0400A28D */  lw         $v0, 0x4($t5)
    /* 5B6BC 8006AEBC 0000AD8D */  lw         $t5, 0x0($t5)
    /* 5B6C0 8006AEC0 20004310 */  beq        $v0, $v1, .L8006AF44
    /* 5B6C4 8006AEC4 24002DAF */   sw        $t5, 0x24($t9)
    /* 5B6C8 8006AEC8 00908248 */  mtc2       $v0, $18 /* handwritten instruction */
    /* 5B6CC 8006AECC 026C0B00 */  srl        $t5, $t3, 16
    /* 5B6D0 8006AED0 C0680D00 */  sll        $t5, $t5, 3
    /* 5B6D4 8006AED4 2168A501 */  addu       $t5, $t5, $a1
    /* 5B6D8 8006AED8 0400A28D */  lw         $v0, 0x4($t5)
    /* 5B6DC 8006AEDC 0000AD8D */  lw         $t5, 0x0($t5)
    /* 5B6E0 8006AEE0 18004310 */  beq        $v0, $v1, .L8006AF44
    /* 5B6E4 8006AEE4 14002DAF */   sw        $t5, 0x14($t9)
    /* 5B6E8 8006AEE8 00988248 */  mtc2       $v0, $19 /* handwritten instruction */
    /* 5B6EC 8006AEEC 20002DAF */  sw         $t5, 0x20($t9)
    /* 5B6F0 8006AEF0 180032AF */  sw         $s2, 0x18($t9)
    /* 5B6F4 8006AEF4 2C0032AF */  sw         $s2, 0x2C($t9)
    /* 5B6F8 8006AEF8 2E00684B */  avsz4
    /* 5B6FC 8006AEFC 00380248 */  mfc2       $v0, $7 /* handwritten instruction */
    /* 5B700 8006AF00 080030AF */  sw         $s0, 0x8($t9)
    /* 5B704 8006AF04 1C0030AF */  sw         $s0, 0x1C($t9)
    /* 5B708 8006AF08 0610C201 */  srlv       $v0, $v0, $t6
    /* 5B70C 8006AF0C 80100200 */  sll        $v0, $v0, 2
    /* 5B710 8006AF10 21104F00 */  addu       $v0, $v0, $t7
    /* 5B714 8006AF14 00004D8C */  lw         $t5, 0x0($v0)
    /* 5B718 8006AF18 040031AF */  sw         $s1, 0x4($t9)
    /* 5B71C 8006AF1C 006A0D00 */  sll        $t5, $t5, 8
    /* 5B720 8006AF20 0B00AD35 */  ori        $t5, $t5, 0xB
    /* 5B724 8006AF24 020A0D00 */  srl        $at, $t5, 8
    /* 5B728 8006AF28 006E0D00 */  sll        $t5, $t5, 24
    /* 5B72C 8006AF2C 2568A101 */  or         $t5, $t5, $at
    /* 5B730 8006AF30 00002DAF */  sw         $t5, 0x0($t9)
    /* 5B734 8006AF34 006A1900 */  sll        $t5, $t9, 8
    /* 5B738 8006AF38 026A0D00 */  srl        $t5, $t5, 8
    /* 5B73C 8006AF3C 00004DAC */  sw         $t5, 0x0($v0)
    /* 5B740 8006AF40 30003927 */  addiu      $t9, $t9, 0x30
  .L8006AF44:
    /* 5B744 8006AF44 FFFF1827 */  addiu      $t8, $t8, -0x1
    /* 5B748 8006AF48 C2FF0017 */  bnez       $t8, .L8006AE54
    /* 5B74C 8006AF4C 2000E724 */   addiu     $a3, $a3, 0x20
  .L8006AF50:
    /* 5B750 8006AF50 2800908C */  lw         $s0, 0x28($a0)
    /* 5B754 8006AF54 2C00918C */  lw         $s1, 0x2C($a0)
    /* 5B758 8006AF58 3000928C */  lw         $s2, 0x30($a0)
    /* 5B75C 8006AF5C 0000828C */  lw         $v0, 0x0($a0)
    /* 5B760 8006AF60 1080013C */  lui        $at, %hi(D_800FE240)
    /* 5B764 8006AF64 40E239AC */  sw         $t9, %lo(D_800FE240)($at)
    /* 5B768 8006AF68 08004224 */  addiu      $v0, $v0, 0x8
    /* 5B76C 8006AF6C 0800E003 */  jr         $ra
    /* 5B770 8006AF70 00000000 */   nop
endlabel func_8006ADE8
