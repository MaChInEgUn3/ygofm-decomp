/* Handwritten function */
nonmatching func_8006A540, 0x154

glabel func_8006A540
    /* 5AD40 8006A540 0000878C */  lw         $a3, 0x0($a0)
    /* 5AD44 8006A544 1000998C */  lw         $t9, 0x10($a0)
    /* 5AD48 8006A548 0200F894 */  lhu        $t8, 0x2($a3)
    /* 5AD4C 8006A54C 0400E68C */  lw         $a2, 0x4($a3)
    /* 5AD50 8006A550 1400858C */  lw         $a1, 0x14($a0)
    /* 5AD54 8006A554 80300600 */  sll        $a2, $a2, 2
    /* 5AD58 8006A558 200090AC */  sw         $s0, 0x20($a0)
    /* 5AD5C 8006A55C 240091AC */  sw         $s1, 0x24($a0)
    /* 5AD60 8006A560 280092AC */  sw         $s2, 0x28($a0)
    /* 5AD64 8006A564 0A800D3C */  lui        $t5, %hi(D_8009AFE4)
    /* 5AD68 8006A568 E4AFAD8D */  lw         $t5, %lo(D_8009AFE4)($t5)
    /* 5AD6C 8006A56C 40000013 */  beqz       $t8, .L8006A670
    /* 5AD70 8006A570 00000000 */   nop
    /* 5AD74 8006A574 01000124 */  addiu      $at, $zero, 0x1
    /* 5AD78 8006A578 3D00A111 */  beq        $t5, $at, .L8006A670
    /* 5AD7C 8006A57C 2138A600 */   addu      $a3, $a1, $a2
    /* 5AD80 8006A580 0A80103C */  lui        $s0, %hi(D_8009AFD0)
    /* 5AD84 8006A584 D0AF108E */  lw         $s0, %lo(D_8009AFD0)($s0)
    /* 5AD88 8006A588 0A80113C */  lui        $s1, %hi(D_8009AFD4)
    /* 5AD8C 8006A58C D4AF318E */  lw         $s1, %lo(D_8009AFD4)($s1)
    /* 5AD90 8006A590 5555123C */  lui        $s2, (0x55555555 >> 16)
    /* 5AD94 8006A594 55555236 */  ori        $s2, $s2, (0x55555555 & 0xFFFF)
    /* 5AD98 8006A598 1800858C */  lw         $a1, 0x18($a0)
    /* 5AD9C 8006A59C 1C00868C */  lw         $a2, 0x1C($a0)
    /* 5ADA0 8006A5A0 04008D8C */  lw         $t5, 0x4($a0)
    /* 5ADA4 8006A5A4 08008E8C */  lw         $t6, 0x8($a0)
    /* 5ADA8 8006A5A8 0400AF8D */  lw         $t7, 0x4($t5)
  .L8006A5AC:
    /* 5ADAC 8006A5AC 1000E88C */  lw         $t0, 0x10($a3)
    /* 5ADB0 8006A5B0 1400E98C */  lw         $t1, 0x14($a3)
    /* 5ADB4 8006A5B4 1800EA8C */  lw         $t2, 0x18($a3)
    /* 5ADB8 8006A5B8 026C0800 */  srl        $t5, $t0, 16
    /* 5ADBC 8006A5BC C0680D00 */  sll        $t5, $t5, 3
    /* 5ADC0 8006A5C0 2168A501 */  addu       $t5, $t5, $a1
    /* 5ADC4 8006A5C4 0000A0C9 */  lwc2       $0, 0x0($t5)
    /* 5ADC8 8006A5C8 0400A1C9 */  lwc2       $1, 0x4($t5)
    /* 5ADCC 8006A5CC 026C0900 */  srl        $t5, $t1, 16
    /* 5ADD0 8006A5D0 C0680D00 */  sll        $t5, $t5, 3
    /* 5ADD4 8006A5D4 2168A501 */  addu       $t5, $t5, $a1
    /* 5ADD8 8006A5D8 0000A2C9 */  lwc2       $2, 0x0($t5)
    /* 5ADDC 8006A5DC 0400A3C9 */  lwc2       $3, 0x4($t5)
    /* 5ADE0 8006A5E0 026C0A00 */  srl        $t5, $t2, 16
    /* 5ADE4 8006A5E4 C0680D00 */  sll        $t5, $t5, 3
    /* 5ADE8 8006A5E8 2168A501 */  addu       $t5, $t5, $a1
    /* 5ADEC 8006A5EC 0000A4C9 */  lwc2       $4, 0x0($t5)
    /* 5ADF0 8006A5F0 0400A5C9 */  lwc2       $5, 0x4($t5)
    /* 5ADF4 8006A5F4 040031AF */  sw         $s1, 0x4($t9)
    /* 5ADF8 8006A5F8 1C0032AF */  sw         $s2, 0x1C($t9)
    /* 5ADFC 8006A5FC 3000284A */  rtpt
    /* 5AE00 8006A600 00F84248 */  cfc2       $v0, $31 /* handwritten instruction */
    /* 5AE04 8006A604 00000000 */  nop
    /* 5AE08 8006A608 16004004 */  bltz       $v0, .L8006A664
    /* 5AE0C 8006A60C 00000000 */   nop
    /* 5AE10 8006A610 2D00584B */  avsz3
    /* 5AE14 8006A614 00380248 */  mfc2       $v0, $7 /* handwritten instruction */
    /* 5AE18 8006A618 080030AF */  sw         $s0, 0x8($t9)
    /* 5AE1C 8006A61C 0610C201 */  srlv       $v0, $v0, $t6
    /* 5AE20 8006A620 80100200 */  sll        $v0, $v0, 2
    /* 5AE24 8006A624 21104F00 */  addu       $v0, $v0, $t7
    /* 5AE28 8006A628 00004D8C */  lw         $t5, 0x0($v0)
    /* 5AE2C 8006A62C 0C002CEB */  swc2       $12, 0xC($t9)
    /* 5AE30 8006A630 10002DEB */  swc2       $13, 0x10($t9)
    /* 5AE34 8006A634 14002EEB */  swc2       $14, 0x14($t9)
    /* 5AE38 8006A638 18002CEB */  swc2       $12, 0x18($t9)
    /* 5AE3C 8006A63C 006A0D00 */  sll        $t5, $t5, 8
    /* 5AE40 8006A640 0700AD35 */  ori        $t5, $t5, 0x7
    /* 5AE44 8006A644 020A0D00 */  srl        $at, $t5, 8
    /* 5AE48 8006A648 006E0D00 */  sll        $t5, $t5, 24
    /* 5AE4C 8006A64C 2568A101 */  or         $t5, $t5, $at
    /* 5AE50 8006A650 00002DAF */  sw         $t5, 0x0($t9)
    /* 5AE54 8006A654 006A1900 */  sll        $t5, $t9, 8
    /* 5AE58 8006A658 026A0D00 */  srl        $t5, $t5, 8
    /* 5AE5C 8006A65C 00004DAC */  sw         $t5, 0x0($v0)
    /* 5AE60 8006A660 20003927 */  addiu      $t9, $t9, 0x20
  .L8006A664:
    /* 5AE64 8006A664 FFFF1827 */  addiu      $t8, $t8, -0x1
    /* 5AE68 8006A668 D0FF0017 */  bnez       $t8, .L8006A5AC
    /* 5AE6C 8006A66C 1C00E724 */   addiu     $a3, $a3, 0x1C
  .L8006A670:
    /* 5AE70 8006A670 2000908C */  lw         $s0, 0x20($a0)
    /* 5AE74 8006A674 2400918C */  lw         $s1, 0x24($a0)
    /* 5AE78 8006A678 2800928C */  lw         $s2, 0x28($a0)
    /* 5AE7C 8006A67C 0000828C */  lw         $v0, 0x0($a0)
    /* 5AE80 8006A680 1080013C */  lui        $at, %hi(D_800FE240)
    /* 5AE84 8006A684 40E239AC */  sw         $t9, %lo(D_800FE240)($at)
    /* 5AE88 8006A688 08004224 */  addiu      $v0, $v0, 0x8
    /* 5AE8C 8006A68C 0800E003 */  jr         $ra
    /* 5AE90 8006A690 00000000 */   nop
endlabel func_8006A540
