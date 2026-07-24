/* Handwritten function */
nonmatching func_8006A694, 0x180

glabel func_8006A694
    /* 5AE94 8006A694 0000878C */  lw         $a3, 0x0($a0)
    /* 5AE98 8006A698 1000998C */  lw         $t9, 0x10($a0)
    /* 5AE9C 8006A69C 0200F894 */  lhu        $t8, 0x2($a3)
    /* 5AEA0 8006A6A0 0400E68C */  lw         $a2, 0x4($a3)
    /* 5AEA4 8006A6A4 1400858C */  lw         $a1, 0x14($a0)
    /* 5AEA8 8006A6A8 80300600 */  sll        $a2, $a2, 2
    /* 5AEAC 8006A6AC 200090AC */  sw         $s0, 0x20($a0)
    /* 5AEB0 8006A6B0 240091AC */  sw         $s1, 0x24($a0)
    /* 5AEB4 8006A6B4 280092AC */  sw         $s2, 0x28($a0)
    /* 5AEB8 8006A6B8 0A800D3C */  lui        $t5, %hi(D_8009AFE4)
    /* 5AEBC 8006A6BC E4AFAD8D */  lw         $t5, %lo(D_8009AFE4)($t5)
    /* 5AEC0 8006A6C0 4B000013 */  beqz       $t8, .L8006A7F0
    /* 5AEC4 8006A6C4 00000000 */   nop
    /* 5AEC8 8006A6C8 01000124 */  addiu      $at, $zero, 0x1
    /* 5AECC 8006A6CC 4800A111 */  beq        $t5, $at, .L8006A7F0
    /* 5AED0 8006A6D0 2138A600 */   addu      $a3, $a1, $a2
    /* 5AED4 8006A6D4 0A80103C */  lui        $s0, %hi(D_8009AFCC)
    /* 5AED8 8006A6D8 CCAF108E */  lw         $s0, %lo(D_8009AFCC)($s0)
    /* 5AEDC 8006A6DC 0A80113C */  lui        $s1, %hi(D_8009AFD4)
    /* 5AEE0 8006A6E0 D4AF318E */  lw         $s1, %lo(D_8009AFD4)($s1)
    /* 5AEE4 8006A6E4 5555123C */  lui        $s2, (0x55555555 >> 16)
    /* 5AEE8 8006A6E8 55555236 */  ori        $s2, $s2, (0x55555555 & 0xFFFF)
    /* 5AEEC 8006A6EC 1800858C */  lw         $a1, 0x18($a0)
    /* 5AEF0 8006A6F0 1C00868C */  lw         $a2, 0x1C($a0)
    /* 5AEF4 8006A6F4 04008D8C */  lw         $t5, 0x4($a0)
    /* 5AEF8 8006A6F8 08008E8C */  lw         $t6, 0x8($a0)
    /* 5AEFC 8006A6FC 0400AF8D */  lw         $t7, 0x4($t5)
  .L8006A700:
    /* 5AF00 8006A700 1400E88C */  lw         $t0, 0x14($a3)
    /* 5AF04 8006A704 1800E98C */  lw         $t1, 0x18($a3)
    /* 5AF08 8006A708 006C0800 */  sll        $t5, $t0, 16
    /* 5AF0C 8006A70C 426B0D00 */  srl        $t5, $t5, 13
    /* 5AF10 8006A710 2168A501 */  addu       $t5, $t5, $a1
    /* 5AF14 8006A714 0000A0C9 */  lwc2       $0, 0x0($t5)
    /* 5AF18 8006A718 0400A1C9 */  lwc2       $1, 0x4($t5)
    /* 5AF1C 8006A71C 026C0800 */  srl        $t5, $t0, 16
    /* 5AF20 8006A720 C0680D00 */  sll        $t5, $t5, 3
    /* 5AF24 8006A724 2168A501 */  addu       $t5, $t5, $a1
    /* 5AF28 8006A728 0000A2C9 */  lwc2       $2, 0x0($t5)
    /* 5AF2C 8006A72C 0400A3C9 */  lwc2       $3, 0x4($t5)
    /* 5AF30 8006A730 006C0900 */  sll        $t5, $t1, 16
    /* 5AF34 8006A734 426B0D00 */  srl        $t5, $t5, 13
    /* 5AF38 8006A738 2168A501 */  addu       $t5, $t5, $a1
    /* 5AF3C 8006A73C 0000A4C9 */  lwc2       $4, 0x0($t5)
    /* 5AF40 8006A740 0400A5C9 */  lwc2       $5, 0x4($t5)
    /* 5AF44 8006A744 025C0900 */  srl        $t3, $t1, 16
    /* 5AF48 8006A748 C0580B00 */  sll        $t3, $t3, 3
    /* 5AF4C 8006A74C 3000284A */  rtpt
    /* 5AF50 8006A750 00F84248 */  cfc2       $v0, $31 /* handwritten instruction */
    /* 5AF54 8006A754 21686501 */  addu       $t5, $t3, $a1
    /* 5AF58 8006A758 22004004 */  bltz       $v0, .L8006A7E4
    /* 5AF5C 8006A75C 040031AF */   sw        $s1, 0x4($t9)
    /* 5AF60 8006A760 0000A0C9 */  lwc2       $0, 0x0($t5)
    /* 5AF64 8006A764 0400A1C9 */  lwc2       $1, 0x4($t5)
    /* 5AF68 8006A768 0C002CEB */  swc2       $12, 0xC($t9)
    /* 5AF6C 8006A76C 10002DEB */  swc2       $13, 0x10($t9)
    /* 5AF70 8006A770 24002EEB */  swc2       $14, 0x24($t9)
    /* 5AF74 8006A774 28002CEB */  swc2       $12, 0x28($t9)
    /* 5AF78 8006A778 180032AF */  sw         $s2, 0x18($t9)
    /* 5AF7C 8006A77C 2C0032AF */  sw         $s2, 0x2C($t9)
    /* 5AF80 8006A780 0100184A */  rtps
    /* 5AF84 8006A784 00F84248 */  cfc2       $v0, $31 /* handwritten instruction */
    /* 5AF88 8006A788 00000000 */  nop
    /* 5AF8C 8006A78C 15004004 */  bltz       $v0, .L8006A7E4
    /* 5AF90 8006A790 00000000 */   nop
    /* 5AF94 8006A794 2E00684B */  avsz4
    /* 5AF98 8006A798 00380248 */  mfc2       $v0, $7 /* handwritten instruction */
    /* 5AF9C 8006A79C 080030AF */  sw         $s0, 0x8($t9)
    /* 5AFA0 8006A7A0 1C0030AF */  sw         $s0, 0x1C($t9)
    /* 5AFA4 8006A7A4 0610C201 */  srlv       $v0, $v0, $t6
    /* 5AFA8 8006A7A8 80100200 */  sll        $v0, $v0, 2
    /* 5AFAC 8006A7AC 21104F00 */  addu       $v0, $v0, $t7
    /* 5AFB0 8006A7B0 00004D8C */  lw         $t5, 0x0($v0)
    /* 5AFB4 8006A7B4 14002EEB */  swc2       $14, 0x14($t9)
    /* 5AFB8 8006A7B8 20002EEB */  swc2       $14, 0x20($t9)
    /* 5AFBC 8006A7BC 006A0D00 */  sll        $t5, $t5, 8
    /* 5AFC0 8006A7C0 0B00AD35 */  ori        $t5, $t5, 0xB
    /* 5AFC4 8006A7C4 020A0D00 */  srl        $at, $t5, 8
    /* 5AFC8 8006A7C8 006E0D00 */  sll        $t5, $t5, 24
    /* 5AFCC 8006A7CC 2568A101 */  or         $t5, $t5, $at
    /* 5AFD0 8006A7D0 00002DAF */  sw         $t5, 0x0($t9)
    /* 5AFD4 8006A7D4 006A1900 */  sll        $t5, $t9, 8
    /* 5AFD8 8006A7D8 026A0D00 */  srl        $t5, $t5, 8
    /* 5AFDC 8006A7DC 00004DAC */  sw         $t5, 0x0($v0)
    /* 5AFE0 8006A7E0 30003927 */  addiu      $t9, $t9, 0x30
  .L8006A7E4:
    /* 5AFE4 8006A7E4 FFFF1827 */  addiu      $t8, $t8, -0x1
    /* 5AFE8 8006A7E8 C5FF0017 */  bnez       $t8, .L8006A700
    /* 5AFEC 8006A7EC 1C00E724 */   addiu     $a3, $a3, 0x1C
  .L8006A7F0:
    /* 5AFF0 8006A7F0 2000908C */  lw         $s0, 0x20($a0)
    /* 5AFF4 8006A7F4 2400918C */  lw         $s1, 0x24($a0)
    /* 5AFF8 8006A7F8 2800928C */  lw         $s2, 0x28($a0)
    /* 5AFFC 8006A7FC 0000828C */  lw         $v0, 0x0($a0)
    /* 5B000 8006A800 1080013C */  lui        $at, %hi(D_800FE240)
    /* 5B004 8006A804 40E239AC */  sw         $t9, %lo(D_800FE240)($at)
    /* 5B008 8006A808 08004224 */  addiu      $v0, $v0, 0x8
    /* 5B00C 8006A80C 0800E003 */  jr         $ra
    /* 5B010 8006A810 00000000 */   nop
endlabel func_8006A694
