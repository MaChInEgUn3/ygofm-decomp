nonmatching func_8008AD50, 0x3D0

glabel func_8008AD50
    /* 7B550 8008AD50 40FFBD27 */  addiu      $sp, $sp, -0xC0
    /* 7B554 8008AD54 B000B4AF */  sw         $s4, 0xB0($sp)
    /* 7B558 8008AD58 21A08000 */  addu       $s4, $a0, $zero
    /* 7B55C 8008AD5C B400B5AF */  sw         $s5, 0xB4($sp)
    /* 7B560 8008AD60 1080153C */  lui        $s5, %hi(D_800FE148)
    /* 7B564 8008AD64 48E1B526 */  addiu      $s5, $s5, %lo(D_800FE148)
    /* 7B568 8008AD68 B800BFAF */  sw         $ra, 0xB8($sp)
    /* 7B56C 8008AD6C AC00B3AF */  sw         $s3, 0xAC($sp)
    /* 7B570 8008AD70 A800B2AF */  sw         $s2, 0xA8($sp)
    /* 7B574 8008AD74 A400B1AF */  sw         $s1, 0xA4($sp)
    /* 7B578 8008AD78 A000B0AF */  sw         $s0, 0xA0($sp)
    /* 7B57C 8008AD7C 1080053C */  lui        $a1, %hi(D_800FE188)
    /* 7B580 8008AD80 88E1A524 */  addiu      $a1, $a1, %lo(D_800FE188)
    /* 7B584 8008AD84 0000A28C */  lw         $v0, 0x0($a1)
    /* 7B588 8008AD88 0400A38C */  lw         $v1, 0x4($a1)
    /* 7B58C 8008AD8C 0800A48C */  lw         $a0, 0x8($a1)
    /* 7B590 8008AD90 0000A2AE */  sw         $v0, 0x0($s5)
    /* 7B594 8008AD94 0400A3AE */  sw         $v1, 0x4($s5)
    /* 7B598 8008AD98 0800A4AE */  sw         $a0, 0x8($s5)
    /* 7B59C 8008AD9C 0C00A28C */  lw         $v0, 0xC($a1)
    /* 7B5A0 8008ADA0 1000A38C */  lw         $v1, 0x10($a1)
    /* 7B5A4 8008ADA4 1400A48C */  lw         $a0, 0x14($a1)
    /* 7B5A8 8008ADA8 0C00A2AE */  sw         $v0, 0xC($s5)
    /* 7B5AC 8008ADAC 1000A3AE */  sw         $v1, 0x10($s5)
    /* 7B5B0 8008ADB0 1400A4AE */  sw         $a0, 0x14($s5)
    /* 7B5B4 8008ADB4 1800A28C */  lw         $v0, 0x18($a1)
    /* 7B5B8 8008ADB8 1C00A38C */  lw         $v1, 0x1C($a1)
    /* 7B5BC 8008ADBC 1800A2AE */  sw         $v0, 0x18($s5)
    /* 7B5C0 8008ADC0 1C00A3AE */  sw         $v1, 0x1C($s5)
    /* 7B5C4 8008ADC4 1800858E */  lw         $a1, 0x18($s4)
    /* 7B5C8 8008ADC8 2120A002 */  addu       $a0, $s5, $zero
    /* 7B5CC 8008ADCC B417020C */  jal        func_80085ED0
    /* 7B5D0 8008ADD0 23280500 */   negu      $a1, $a1
    /* 7B5D4 8008ADD4 21208002 */  addu       $a0, $s4, $zero
    /* 7B5D8 8008ADD8 482C020C */  jal        func_8008B120
    /* 7B5DC 8008ADDC 1000A527 */   addiu     $a1, $sp, 0x10
    /* 7B5E0 8008ADE0 1C00A28F */  lw         $v0, 0x1C($sp)
    /* 7B5E4 8008ADE4 1000A38F */  lw         $v1, 0x10($sp)
    /* 7B5E8 8008ADE8 00000000 */  nop
    /* 7B5EC 8008ADEC 23104300 */  subu       $v0, $v0, $v1
    /* 7B5F0 8008ADF0 18004200 */  mult       $v0, $v0
    /* 7B5F4 8008ADF4 2000A28F */  lw         $v0, 0x20($sp)
    /* 7B5F8 8008ADF8 1400A38F */  lw         $v1, 0x14($sp)
    /* 7B5FC 8008ADFC 12280000 */  mflo       $a1
    /* 7B600 8008AE00 23104300 */  subu       $v0, $v0, $v1
    /* 7B604 8008AE04 00000000 */  nop
    /* 7B608 8008AE08 18004200 */  mult       $v0, $v0
    /* 7B60C 8008AE0C 1800A38F */  lw         $v1, 0x18($sp)
    /* 7B610 8008AE10 2400A28F */  lw         $v0, 0x24($sp)
    /* 7B614 8008AE14 12200000 */  mflo       $a0
    /* 7B618 8008AE18 23104300 */  subu       $v0, $v0, $v1
    /* 7B61C 8008AE1C 00000000 */  nop
    /* 7B620 8008AE20 18004200 */  mult       $v0, $v0
    /* 7B624 8008AE24 2120A400 */  addu       $a0, $a1, $a0
    /* 7B628 8008AE28 12180000 */  mflo       $v1
    /* 7B62C 8008AE2C 941B020C */  jal        func_80086E50
    /* 7B630 8008AE30 21208300 */   addu      $a0, $a0, $v1
    /* 7B634 8008AE34 21904000 */  addu       $s2, $v0, $zero
    /* 7B638 8008AE38 B0004012 */  beqz       $s2, .L8008B0FC
    /* 7B63C 8008AE3C 01000224 */   addiu     $v0, $zero, 0x1
    /* 7B640 8008AE40 1400A38F */  lw         $v1, 0x14($sp)
    /* 7B644 8008AE44 2000A28F */  lw         $v0, 0x20($sp)
    /* 7B648 8008AE48 00000000 */  nop
    /* 7B64C 8008AE4C 23886200 */  subu       $s1, $v1, $v0
    /* 7B650 8008AE50 00831100 */  sll        $s0, $s1, 12
    /* 7B654 8008AE54 1A001202 */  div        $zero, $s0, $s2
    /* 7B658 8008AE58 02004016 */  bnez       $s2, .L8008AE64
    /* 7B65C 8008AE5C 00000000 */   nop
    /* 7B660 8008AE60 0D000700 */  break      7
  .L8008AE64:
    /* 7B664 8008AE64 FFFF0124 */  addiu      $at, $zero, -0x1
    /* 7B668 8008AE68 04004116 */  bne        $s2, $at, .L8008AE7C
    /* 7B66C 8008AE6C 0080013C */   lui       $at, (0x80000000 >> 16)
    /* 7B670 8008AE70 02000116 */  bne        $s0, $at, .L8008AE7C
    /* 7B674 8008AE74 00000000 */   nop
    /* 7B678 8008AE78 0D000600 */  break      6
  .L8008AE7C:
    /* 7B67C 8008AE7C 12800000 */  mflo       $s0
    /* 7B680 8008AE80 1C00A28F */  lw         $v0, 0x1C($sp)
    /* 7B684 8008AE84 1000A38F */  lw         $v1, 0x10($sp)
    /* 7B688 8008AE88 00000000 */  nop
    /* 7B68C 8008AE8C 23104300 */  subu       $v0, $v0, $v1
    /* 7B690 8008AE90 18004200 */  mult       $v0, $v0
    /* 7B694 8008AE94 2400A28F */  lw         $v0, 0x24($sp)
    /* 7B698 8008AE98 1800A38F */  lw         $v1, 0x18($sp)
    /* 7B69C 8008AE9C 12200000 */  mflo       $a0
    /* 7B6A0 8008AEA0 23104300 */  subu       $v0, $v0, $v1
    /* 7B6A4 8008AEA4 00000000 */  nop
    /* 7B6A8 8008AEA8 18004200 */  mult       $v0, $v0
    /* 7B6AC 8008AEAC 12180000 */  mflo       $v1
    /* 7B6B0 8008AEB0 21208300 */  addu       $a0, $a0, $v1
    /* 7B6B4 8008AEB4 941B020C */  jal        func_80086E50
    /* 7B6B8 8008AEB8 23801000 */   negu      $s0, $s0
    /* 7B6BC 8008AEBC 21884000 */  addu       $s1, $v0, $zero
    /* 7B6C0 8008AEC0 00331100 */  sll        $a2, $s1, 12
    /* 7B6C4 8008AEC4 1A00D200 */  div        $zero, $a2, $s2
    /* 7B6C8 8008AEC8 02004016 */  bnez       $s2, .L8008AED4
    /* 7B6CC 8008AECC 00000000 */   nop
    /* 7B6D0 8008AED0 0D000700 */  break      7
  .L8008AED4:
    /* 7B6D4 8008AED4 FFFF0124 */  addiu      $at, $zero, -0x1
    /* 7B6D8 8008AED8 04004116 */  bne        $s2, $at, .L8008AEEC
    /* 7B6DC 8008AEDC 0080013C */   lui       $at, (0x80000000 >> 16)
    /* 7B6E0 8008AEE0 0200C114 */  bne        $a2, $at, .L8008AEEC
    /* 7B6E4 8008AEE4 00000000 */   nop
    /* 7B6E8 8008AEE8 0D000600 */  break      6
  .L8008AEEC:
    /* 7B6EC 8008AEEC 12300000 */  mflo       $a2
    /* 7B6F0 8008AEF0 3000B327 */  addiu      $s3, $sp, 0x30
    /* 7B6F4 8008AEF4 21206002 */  addu       $a0, $s3, $zero
    /* 7B6F8 8008AEF8 00841000 */  sll        $s0, $s0, 16
    /* 7B6FC 8008AEFC 032C1000 */  sra        $a1, $s0, 16
    /* 7B700 8008AF00 78000724 */  addiu      $a3, $zero, 0x78
    /* 7B704 8008AF04 00340600 */  sll        $a2, $a2, 16
    /* 7B708 8008AF08 7C18020C */  jal        func_800861F0
    /* 7B70C 8008AF0C 03340600 */   sra       $a2, $a2, 16
    /* 7B710 8008AF10 2120A002 */  addu       $a0, $s5, $zero
    /* 7B714 8008AF14 DC1C020C */  jal        func_80087370
    /* 7B718 8008AF18 21286002 */   addu      $a1, $s3, $zero
    /* 7B71C 8008AF1C 2C002012 */  beqz       $s1, .L8008AFD0
    /* 7B720 8008AF20 21902002 */   addu      $s2, $s1, $zero
    /* 7B724 8008AF24 1C00A38F */  lw         $v1, 0x1C($sp)
    /* 7B728 8008AF28 1000A28F */  lw         $v0, 0x10($sp)
    /* 7B72C 8008AF2C 00000000 */  nop
    /* 7B730 8008AF30 23886200 */  subu       $s1, $v1, $v0
    /* 7B734 8008AF34 002B1100 */  sll        $a1, $s1, 12
    /* 7B738 8008AF38 1A00B200 */  div        $zero, $a1, $s2
    /* 7B73C 8008AF3C 02004016 */  bnez       $s2, .L8008AF48
    /* 7B740 8008AF40 00000000 */   nop
    /* 7B744 8008AF44 0D000700 */  break      7
  .L8008AF48:
    /* 7B748 8008AF48 FFFF0124 */  addiu      $at, $zero, -0x1
    /* 7B74C 8008AF4C 04004116 */  bne        $s2, $at, .L8008AF60
    /* 7B750 8008AF50 0080013C */   lui       $at, (0x80000000 >> 16)
    /* 7B754 8008AF54 0200A114 */  bne        $a1, $at, .L8008AF60
    /* 7B758 8008AF58 00000000 */   nop
    /* 7B75C 8008AF5C 0D000600 */  break      6
  .L8008AF60:
    /* 7B760 8008AF60 12280000 */  mflo       $a1
    /* 7B764 8008AF64 2400A38F */  lw         $v1, 0x24($sp)
    /* 7B768 8008AF68 1800A28F */  lw         $v0, 0x18($sp)
    /* 7B76C 8008AF6C 00000000 */  nop
    /* 7B770 8008AF70 23886200 */  subu       $s1, $v1, $v0
    /* 7B774 8008AF74 00331100 */  sll        $a2, $s1, 12
    /* 7B778 8008AF78 1A00D200 */  div        $zero, $a2, $s2
    /* 7B77C 8008AF7C 02004016 */  bnez       $s2, .L8008AF88
    /* 7B780 8008AF80 00000000 */   nop
    /* 7B784 8008AF84 0D000700 */  break      7
  .L8008AF88:
    /* 7B788 8008AF88 FFFF0124 */  addiu      $at, $zero, -0x1
    /* 7B78C 8008AF8C 04004116 */  bne        $s2, $at, .L8008AFA0
    /* 7B790 8008AF90 0080013C */   lui       $at, (0x80000000 >> 16)
    /* 7B794 8008AF94 0200C114 */  bne        $a2, $at, .L8008AFA0
    /* 7B798 8008AF98 00000000 */   nop
    /* 7B79C 8008AF9C 0D000600 */  break      6
  .L8008AFA0:
    /* 7B7A0 8008AFA0 12300000 */  mflo       $a2
    /* 7B7A4 8008AFA4 21206002 */  addu       $a0, $s3, $zero
    /* 7B7A8 8008AFA8 79000724 */  addiu      $a3, $zero, 0x79
    /* 7B7AC 8008AFAC 23280500 */  negu       $a1, $a1
    /* 7B7B0 8008AFB0 002C0500 */  sll        $a1, $a1, 16
    /* 7B7B4 8008AFB4 032C0500 */  sra        $a1, $a1, 16
    /* 7B7B8 8008AFB8 00340600 */  sll        $a2, $a2, 16
    /* 7B7BC 8008AFBC 7C18020C */  jal        func_800861F0
    /* 7B7C0 8008AFC0 03340600 */   sra       $a2, $a2, 16
    /* 7B7C4 8008AFC4 2120A002 */  addu       $a0, $s5, $zero
    /* 7B7C8 8008AFC8 DC1C020C */  jal        func_80087370
    /* 7B7CC 8008AFCC 21286002 */   addu      $a1, $s3, $zero
  .L8008AFD0:
    /* 7B7D0 8008AFD0 2120A002 */  addu       $a0, $s5, $zero
    /* 7B7D4 8008AFD4 0000828E */  lw         $v0, 0x0($s4)
    /* 7B7D8 8008AFD8 9000B127 */  addiu      $s1, $sp, 0x90
    /* 7B7DC 8008AFDC 23100200 */  negu       $v0, $v0
    /* 7B7E0 8008AFE0 9000A2AF */  sw         $v0, 0x90($sp)
    /* 7B7E4 8008AFE4 0400828E */  lw         $v0, 0x4($s4)
    /* 7B7E8 8008AFE8 21282002 */  addu       $a1, $s1, $zero
    /* 7B7EC 8008AFEC 23100200 */  negu       $v0, $v0
    /* 7B7F0 8008AFF0 9400A2AF */  sw         $v0, 0x94($sp)
    /* 7B7F4 8008AFF4 0800828E */  lw         $v0, 0x8($s4)
    /* 7B7F8 8008AFF8 1400A626 */  addiu      $a2, $s5, 0x14
    /* 7B7FC 8008AFFC 23100200 */  negu       $v0, $v0
    /* 7B800 8008B000 1C1C020C */  jal        func_80087070
    /* 7B804 8008B004 9800A2AF */   sw        $v0, 0x98($sp)
    /* 7B808 8008B008 1C00848E */  lw         $a0, 0x1C($s4)
    /* 7B80C 8008B00C 00000000 */  nop
    /* 7B810 8008B010 27008010 */  beqz       $a0, .L8008B0B0
    /* 7B814 8008B014 00000000 */   nop
    /* 7B818 8008B018 2829020C */  jal        func_8008A4A0
    /* 7B81C 8008B01C 21286002 */   addu      $a1, $s3, $zero
    /* 7B820 8008B020 21206002 */  addu       $a0, $s3, $zero
    /* 7B824 8008B024 5000B027 */  addiu      $s0, $sp, 0x50
    /* 7B828 8008B028 BC2C020C */  jal        func_8008B2F0
    /* 7B82C 8008B02C 21280002 */   addu      $a1, $s0, $zero
    /* 7B830 8008B030 21200002 */  addu       $a0, $s0, $zero
    /* 7B834 8008B034 4400A527 */  addiu      $a1, $sp, 0x44
    /* 7B838 8008B038 1C1C020C */  jal        func_80087070
    /* 7B83C 8008B03C 21302002 */   addu      $a2, $s1, $zero
    /* 7B840 8008B040 2120A002 */  addu       $a0, $s5, $zero
    /* 7B844 8008B044 21280002 */  addu       $a1, $s0, $zero
    /* 7B848 8008B048 9000A28F */  lw         $v0, 0x90($sp)
    /* 7B84C 8008B04C 9800A38F */  lw         $v1, 0x98($sp)
    /* 7B850 8008B050 23100200 */  negu       $v0, $v0
    /* 7B854 8008B054 6400A2AF */  sw         $v0, 0x64($sp)
    /* 7B858 8008B058 9400A28F */  lw         $v0, 0x94($sp)
    /* 7B85C 8008B05C 23180300 */  negu       $v1, $v1
    /* 7B860 8008B060 6C00A3AF */  sw         $v1, 0x6C($sp)
    /* 7B864 8008B064 23100200 */  negu       $v0, $v0
    /* 7B868 8008B068 6819020C */  jal        func_800865A0
    /* 7B86C 8008B06C 6800A2AF */   sw        $v0, 0x68($sp)
    /* 7B870 8008B070 5000A28F */  lw         $v0, 0x50($sp)
    /* 7B874 8008B074 5400A38F */  lw         $v1, 0x54($sp)
    /* 7B878 8008B078 5800A48F */  lw         $a0, 0x58($sp)
    /* 7B87C 8008B07C 5C00A58F */  lw         $a1, 0x5C($sp)
    /* 7B880 8008B080 0000A2AE */  sw         $v0, 0x0($s5)
    /* 7B884 8008B084 0400A3AE */  sw         $v1, 0x4($s5)
    /* 7B888 8008B088 0800A4AE */  sw         $a0, 0x8($s5)
    /* 7B88C 8008B08C 0C00A5AE */  sw         $a1, 0xC($s5)
    /* 7B890 8008B090 6000A28F */  lw         $v0, 0x60($sp)
    /* 7B894 8008B094 6400A38F */  lw         $v1, 0x64($sp)
    /* 7B898 8008B098 6800A48F */  lw         $a0, 0x68($sp)
    /* 7B89C 8008B09C 6C00A58F */  lw         $a1, 0x6C($sp)
    /* 7B8A0 8008B0A0 1000A2AE */  sw         $v0, 0x10($s5)
    /* 7B8A4 8008B0A4 1400A3AE */  sw         $v1, 0x14($s5)
    /* 7B8A8 8008B0A8 1800A4AE */  sw         $a0, 0x18($s5)
    /* 7B8AC 8008B0AC 1C00A5AE */  sw         $a1, 0x1C($s5)
  .L8008B0B0:
    /* 7B8B0 8008B0B0 1080053C */  lui        $a1, %hi(D_800FE128)
    /* 7B8B4 8008B0B4 28E1A524 */  addiu      $a1, $a1, %lo(D_800FE128)
    /* 7B8B8 8008B0B8 0000A28E */  lw         $v0, 0x0($s5)
    /* 7B8BC 8008B0BC 0400A38E */  lw         $v1, 0x4($s5)
    /* 7B8C0 8008B0C0 0800A48E */  lw         $a0, 0x8($s5)
    /* 7B8C4 8008B0C4 0000A2AC */  sw         $v0, 0x0($a1)
    /* 7B8C8 8008B0C8 0400A3AC */  sw         $v1, 0x4($a1)
    /* 7B8CC 8008B0CC 0800A4AC */  sw         $a0, 0x8($a1)
    /* 7B8D0 8008B0D0 0C00A28E */  lw         $v0, 0xC($s5)
    /* 7B8D4 8008B0D4 1000A38E */  lw         $v1, 0x10($s5)
    /* 7B8D8 8008B0D8 1400A48E */  lw         $a0, 0x14($s5)
    /* 7B8DC 8008B0DC 0C00A2AC */  sw         $v0, 0xC($a1)
    /* 7B8E0 8008B0E0 1000A3AC */  sw         $v1, 0x10($a1)
    /* 7B8E4 8008B0E4 1400A4AC */  sw         $a0, 0x14($a1)
    /* 7B8E8 8008B0E8 1800A28E */  lw         $v0, 0x18($s5)
    /* 7B8EC 8008B0EC 1C00A38E */  lw         $v1, 0x1C($s5)
    /* 7B8F0 8008B0F0 1800A2AC */  sw         $v0, 0x18($a1)
    /* 7B8F4 8008B0F4 1C00A3AC */  sw         $v1, 0x1C($a1)
    /* 7B8F8 8008B0F8 21100000 */  addu       $v0, $zero, $zero
  .L8008B0FC:
    /* 7B8FC 8008B0FC B800BF8F */  lw         $ra, 0xB8($sp)
    /* 7B900 8008B100 B400B58F */  lw         $s5, 0xB4($sp)
    /* 7B904 8008B104 B000B48F */  lw         $s4, 0xB0($sp)
    /* 7B908 8008B108 AC00B38F */  lw         $s3, 0xAC($sp)
    /* 7B90C 8008B10C A800B28F */  lw         $s2, 0xA8($sp)
    /* 7B910 8008B110 A400B18F */  lw         $s1, 0xA4($sp)
    /* 7B914 8008B114 A000B08F */  lw         $s0, 0xA0($sp)
    /* 7B918 8008B118 0800E003 */  jr         $ra
    /* 7B91C 8008B11C C000BD27 */   addiu     $sp, $sp, 0xC0
endlabel func_8008AD50
