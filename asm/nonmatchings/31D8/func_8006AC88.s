/* Handwritten function */
nonmatching func_8006AC88, 0x160

glabel func_8006AC88
    /* 5B488 8006AC88 0000878C */  lw         $a3, 0x0($a0)
    /* 5B48C 8006AC8C 1000998C */  lw         $t9, 0x10($a0)
    /* 5B490 8006AC90 0200F894 */  lhu        $t8, 0x2($a3)
    /* 5B494 8006AC94 0400E68C */  lw         $a2, 0x4($a3)
    /* 5B498 8006AC98 1400858C */  lw         $a1, 0x14($a0)
    /* 5B49C 8006AC9C 80300600 */  sll        $a2, $a2, 2
    /* 5B4A0 8006ACA0 280090AC */  sw         $s0, 0x28($a0)
    /* 5B4A4 8006ACA4 2C0091AC */  sw         $s1, 0x2C($a0)
    /* 5B4A8 8006ACA8 300092AC */  sw         $s2, 0x30($a0)
    /* 5B4AC 8006ACAC 0A800D3C */  lui        $t5, %hi(D_8009AFE4)
    /* 5B4B0 8006ACB0 E4AFAD8D */  lw         $t5, %lo(D_8009AFE4)($t5)
    /* 5B4B4 8006ACB4 43000013 */  beqz       $t8, .L8006ADC4
    /* 5B4B8 8006ACB8 00000000 */   nop
    /* 5B4BC 8006ACBC 01000124 */  addiu      $at, $zero, 0x1
    /* 5B4C0 8006ACC0 4000A111 */  beq        $t5, $at, .L8006ADC4
    /* 5B4C4 8006ACC4 2138A600 */   addu      $a3, $a1, $a2
    /* 5B4C8 8006ACC8 0A80103C */  lui        $s0, %hi(D_8009AFD0)
    /* 5B4CC 8006ACCC D0AF108E */  lw         $s0, %lo(D_8009AFD0)($s0)
    /* 5B4D0 8006ACD0 0A80113C */  lui        $s1, %hi(D_8009AFD4)
    /* 5B4D4 8006ACD4 D4AF318E */  lw         $s1, %lo(D_8009AFD4)($s1)
    /* 5B4D8 8006ACD8 5555123C */  lui        $s2, (0x55555555 >> 16)
    /* 5B4DC 8006ACDC 55555236 */  ori        $s2, $s2, (0x55555555 & 0xFFFF)
    /* 5B4E0 8006ACE0 1C00858C */  lw         $a1, 0x1C($a0)
    /* 5B4E4 8006ACE4 2400868C */  lw         $a2, 0x24($a0)
    /* 5B4E8 8006ACE8 04008D8C */  lw         $t5, 0x4($a0)
    /* 5B4EC 8006ACEC 08008E8C */  lw         $t6, 0x8($a0)
    /* 5B4F0 8006ACF0 0400AF8D */  lw         $t7, 0x4($t5)
  .L8006ACF4:
    /* 5B4F4 8006ACF4 FFFF0324 */  addiu      $v1, $zero, -0x1
    /* 5B4F8 8006ACF8 1000E88C */  lw         $t0, 0x10($a3)
    /* 5B4FC 8006ACFC 1400E98C */  lw         $t1, 0x14($a3)
    /* 5B500 8006AD00 1800EA8C */  lw         $t2, 0x18($a3)
    /* 5B504 8006AD04 026C0800 */  srl        $t5, $t0, 16
    /* 5B508 8006AD08 C0680D00 */  sll        $t5, $t5, 3
    /* 5B50C 8006AD0C 2168A501 */  addu       $t5, $t5, $a1
    /* 5B510 8006AD10 0400A28D */  lw         $v0, 0x4($t5)
    /* 5B514 8006AD14 0000AD8D */  lw         $t5, 0x0($t5)
    /* 5B518 8006AD18 27004310 */  beq        $v0, $v1, .L8006ADB8
    /* 5B51C 8006AD1C 0C002DAF */   sw        $t5, 0xC($t9)
    /* 5B520 8006AD20 00888248 */  mtc2       $v0, $17 /* handwritten instruction */
    /* 5B524 8006AD24 18002DAF */  sw         $t5, 0x18($t9)
    /* 5B528 8006AD28 026C0900 */  srl        $t5, $t1, 16
    /* 5B52C 8006AD2C C0680D00 */  sll        $t5, $t5, 3
    /* 5B530 8006AD30 2168A501 */  addu       $t5, $t5, $a1
    /* 5B534 8006AD34 0400A28D */  lw         $v0, 0x4($t5)
    /* 5B538 8006AD38 0000AD8D */  lw         $t5, 0x0($t5)
    /* 5B53C 8006AD3C 1E004310 */  beq        $v0, $v1, .L8006ADB8
    /* 5B540 8006AD40 10002DAF */   sw        $t5, 0x10($t9)
    /* 5B544 8006AD44 00908248 */  mtc2       $v0, $18 /* handwritten instruction */
    /* 5B548 8006AD48 026C0A00 */  srl        $t5, $t2, 16
    /* 5B54C 8006AD4C C0680D00 */  sll        $t5, $t5, 3
    /* 5B550 8006AD50 2168A501 */  addu       $t5, $t5, $a1
    /* 5B554 8006AD54 0400A28D */  lw         $v0, 0x4($t5)
    /* 5B558 8006AD58 0000AD8D */  lw         $t5, 0x0($t5)
    /* 5B55C 8006AD5C 16004310 */  beq        $v0, $v1, .L8006ADB8
    /* 5B560 8006AD60 14002DAF */   sw        $t5, 0x14($t9)
    /* 5B564 8006AD64 00988248 */  mtc2       $v0, $19 /* handwritten instruction */
    /* 5B568 8006AD68 040031AF */  sw         $s1, 0x4($t9)
    /* 5B56C 8006AD6C 1C0032AF */  sw         $s2, 0x1C($t9)
    /* 5B570 8006AD70 2D00584B */  avsz3
    /* 5B574 8006AD74 00380248 */  mfc2       $v0, $7 /* handwritten instruction */
    /* 5B578 8006AD78 080030AF */  sw         $s0, 0x8($t9)
    /* 5B57C 8006AD7C 0610C201 */  srlv       $v0, $v0, $t6
    /* 5B580 8006AD80 80100200 */  sll        $v0, $v0, 2
    /* 5B584 8006AD84 21104F00 */  addu       $v0, $v0, $t7
    /* 5B588 8006AD88 00004D8C */  lw         $t5, 0x0($v0)
    /* 5B58C 8006AD8C 00000000 */  nop
    /* 5B590 8006AD90 006A0D00 */  sll        $t5, $t5, 8
    /* 5B594 8006AD94 0700AD35 */  ori        $t5, $t5, 0x7
    /* 5B598 8006AD98 020A0D00 */  srl        $at, $t5, 8
    /* 5B59C 8006AD9C 006E0D00 */  sll        $t5, $t5, 24
    /* 5B5A0 8006ADA0 2568A101 */  or         $t5, $t5, $at
    /* 5B5A4 8006ADA4 00002DAF */  sw         $t5, 0x0($t9)
    /* 5B5A8 8006ADA8 006A1900 */  sll        $t5, $t9, 8
    /* 5B5AC 8006ADAC 026A0D00 */  srl        $t5, $t5, 8
    /* 5B5B0 8006ADB0 00004DAC */  sw         $t5, 0x0($v0)
    /* 5B5B4 8006ADB4 20003927 */  addiu      $t9, $t9, 0x20
  .L8006ADB8:
    /* 5B5B8 8006ADB8 FFFF1827 */  addiu      $t8, $t8, -0x1
    /* 5B5BC 8006ADBC CDFF0017 */  bnez       $t8, .L8006ACF4
    /* 5B5C0 8006ADC0 1C00E724 */   addiu     $a3, $a3, 0x1C
  .L8006ADC4:
    /* 5B5C4 8006ADC4 2800908C */  lw         $s0, 0x28($a0)
    /* 5B5C8 8006ADC8 2C00918C */  lw         $s1, 0x2C($a0)
    /* 5B5CC 8006ADCC 3000928C */  lw         $s2, 0x30($a0)
    /* 5B5D0 8006ADD0 0000828C */  lw         $v0, 0x0($a0)
    /* 5B5D4 8006ADD4 1080013C */  lui        $at, %hi(D_800FE240)
    /* 5B5D8 8006ADD8 40E239AC */  sw         $t9, %lo(D_800FE240)($at)
    /* 5B5DC 8006ADDC 08004224 */  addiu      $v0, $v0, 0x8
    /* 5B5E0 8006ADE0 0800E003 */  jr         $ra
    /* 5B5E4 8006ADE4 00000000 */   nop
endlabel func_8006AC88
