nonmatching func_8003AD6C, 0x2E8

glabel func_8003AD6C
    /* 2B56C 8003AD6C D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 2B570 8003AD70 2800B4AF */  sw         $s4, 0x28($sp)
    /* 2B574 8003AD74 21A08000 */  addu       $s4, $a0, $zero
    /* 2B578 8003AD78 2C00BFAF */  sw         $ra, 0x2C($sp)
    /* 2B57C 8003AD7C 2400B3AF */  sw         $s3, 0x24($sp)
    /* 2B580 8003AD80 2000B2AF */  sw         $s2, 0x20($sp)
    /* 2B584 8003AD84 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 2B588 8003AD88 C7E7000C */  jal        func_80039F1C
    /* 2B58C 8003AD8C 1800B0AF */   sw        $s0, 0x18($sp)
    /* 2B590 8003AD90 2F004014 */  bnez       $v0, .L8003AE50
    /* 2B594 8003AD94 00000000 */   nop
    /* 2B598 8003AD98 32008292 */  lbu        $v0, 0x32($s4)
    /* 2B59C 8003AD9C 0000838E */  lw         $v1, 0x0($s4)
    /* 2B5A0 8003ADA0 10004234 */  ori        $v0, $v0, 0x10
    /* 2B5A4 8003ADA4 320082A2 */  sb         $v0, 0x32($s4)
    /* 2B5A8 8003ADA8 67007390 */  lbu        $s3, 0x67($v1)
    /* 2B5AC 8003ADAC 16007180 */  lb         $s1, 0x16($v1)
    /* 2B5B0 8003ADB0 E4E7000C */  jal        func_80039F90
    /* 2B5B4 8003ADB4 21208002 */   addu      $a0, $s4, $zero
    /* 2B5B8 8003ADB8 21208002 */  addu       $a0, $s4, $zero
    /* 2B5BC 8003ADBC 31008692 */  lbu        $a2, 0x31($s4)
    /* 2B5C0 8003ADC0 7BE8000C */  jal        func_8003A1EC
    /* 2B5C4 8003ADC4 21288002 */   addu      $a1, $s4, $zero
    /* 2B5C8 8003ADC8 21208002 */  addu       $a0, $s4, $zero
    /* 2B5CC 8003ADCC 0050053C */  lui        $a1, (0x50000000 >> 16)
    /* 2B5D0 8003ADD0 10E9000C */  jal        func_8003A440
    /* 2B5D4 8003ADD4 21302002 */   addu      $a2, $s1, $zero
    /* 2B5D8 8003ADD8 21208002 */  addu       $a0, $s4, $zero
    /* 2B5DC 8003ADDC 0C009026 */  addiu      $s0, $s4, 0xC
    /* 2B5E0 8003ADE0 31008692 */  lbu        $a2, 0x31($s4)
    /* 2B5E4 8003ADE4 7BE8000C */  jal        func_8003A1EC
    /* 2B5E8 8003ADE8 21280002 */   addu      $a1, $s0, $zero
    /* 2B5EC 8003ADEC 21200002 */  addu       $a0, $s0, $zero
    /* 2B5F0 8003ADF0 0060053C */  lui        $a1, (0x60000000 >> 16)
    /* 2B5F4 8003ADF4 FFFF3226 */  addiu      $s2, $s1, -0x1
    /* 2B5F8 8003ADF8 10E9000C */  jal        func_8003A440
    /* 2B5FC 8003ADFC 21304002 */   addu      $a2, $s2, $zero
    /* 2B600 8003AE00 21208002 */  addu       $a0, $s4, $zero
    /* 2B604 8003AE04 18009026 */  addiu      $s0, $s4, 0x18
    /* 2B608 8003AE08 21280002 */  addu       $a1, $s0, $zero
    /* 2B60C 8003AE0C 7BE8000C */  jal        func_8003A1EC
    /* 2B610 8003AE10 21306002 */   addu      $a2, $s3, $zero
    /* 2B614 8003AE14 21200002 */  addu       $a0, $s0, $zero
    /* 2B618 8003AE18 0050053C */  lui        $a1, (0x50000000 >> 16)
    /* 2B61C 8003AE1C 10E9000C */  jal        func_8003A440
    /* 2B620 8003AE20 21302002 */   addu      $a2, $s1, $zero
    /* 2B624 8003AE24 21208002 */  addu       $a0, $s4, $zero
    /* 2B628 8003AE28 24009026 */  addiu      $s0, $s4, 0x24
    /* 2B62C 8003AE2C 21280002 */  addu       $a1, $s0, $zero
    /* 2B630 8003AE30 7BE8000C */  jal        func_8003A1EC
    /* 2B634 8003AE34 21306002 */   addu      $a2, $s3, $zero
    /* 2B638 8003AE38 21200002 */  addu       $a0, $s0, $zero
    /* 2B63C 8003AE3C 0060053C */  lui        $a1, (0x60000000 >> 16)
    /* 2B640 8003AE40 10E9000C */  jal        func_8003A440
    /* 2B644 8003AE44 21304002 */   addu      $a2, $s2, $zero
    /* 2B648 8003AE48 80000224 */  addiu      $v0, $zero, 0x80
    /* 2B64C 8003AE4C 400082A6 */  sh         $v0, 0x40($s4)
  .L8003AE50:
    /* 2B650 8003AE50 0A80033C */  lui        $v1, %hi(D_8009B0D8)
    /* 2B654 8003AE54 D8B0638C */  lw         $v1, %lo(D_8009B0D8)($v1)
    /* 2B658 8003AE58 40008296 */  lhu        $v0, 0x40($s4)
    /* 2B65C 8003AE5C C0180300 */  sll        $v1, $v1, 3
    /* 2B660 8003AE60 23104300 */  subu       $v0, $v0, $v1
    /* 2B664 8003AE64 400082A6 */  sh         $v0, 0x40($s4)
    /* 2B668 8003AE68 00140200 */  sll        $v0, $v0, 16
    /* 2B66C 8003AE6C 03140200 */  sra        $v0, $v0, 16
    /* 2B670 8003AE70 1600401C */  bgtz       $v0, .L8003AECC
    /* 2B674 8003AE74 21204000 */   addu      $a0, $v0, $zero
    /* 2B678 8003AE78 0000828E */  lw         $v0, 0x0($s4)
    /* 2B67C 8003AE7C 21208002 */  addu       $a0, $s4, $zero
    /* 2B680 8003AE80 330080A2 */  sb         $zero, 0x33($s4)
    /* 2B684 8003AE84 16004680 */  lb         $a2, 0x16($v0)
    /* 2B688 8003AE88 10E9000C */  jal        func_8003A440
    /* 2B68C 8003AE8C 21280000 */   addu      $a1, $zero, $zero
    /* 2B690 8003AE90 34008586 */  lh         $a1, 0x34($s4)
    /* 2B694 8003AE94 36008686 */  lh         $a2, 0x36($s4)
    /* 2B698 8003AE98 48EA000C */  jal        func_8003A920
    /* 2B69C 8003AE9C 21208002 */   addu      $a0, $s4, $zero
    /* 2B6A0 8003AEA0 E4E7000C */  jal        func_80039F90
    /* 2B6A4 8003AEA4 0C008426 */   addiu     $a0, $s4, 0xC
    /* 2B6A8 8003AEA8 E4E7000C */  jal        func_80039F90
    /* 2B6AC 8003AEAC 18008426 */   addiu     $a0, $s4, 0x18
    /* 2B6B0 8003AEB0 E4E7000C */  jal        func_80039F90
    /* 2B6B4 8003AEB4 24008426 */   addiu     $a0, $s4, 0x24
    /* 2B6B8 8003AEB8 32008292 */  lbu        $v0, 0x32($s4)
    /* 2B6BC 8003AEBC 00000000 */  nop
    /* 2B6C0 8003AEC0 EF004230 */  andi       $v0, $v0, 0xEF
    /* 2B6C4 8003AEC4 0DEC0008 */  j          .L8003B034
    /* 2B6C8 8003AEC8 320082A2 */   sb        $v0, 0x32($s4)
  .L8003AECC:
    /* 2B6CC 8003AECC 00120400 */  sll        $v0, $a0, 8
    /* 2B6D0 8003AED0 001C0400 */  sll        $v1, $a0, 16
    /* 2B6D4 8003AED4 25104300 */  or         $v0, $v0, $v1
    /* 2B6D8 8003AED8 25208200 */  or         $a0, $a0, $v0
    /* 2B6DC 8003AEDC 02000624 */  addiu      $a2, $zero, 0x2
    /* 2B6E0 8003AEE0 08008326 */  addiu      $v1, $s4, 0x8
  .L8003AEE4:
    /* 2B6E4 8003AEE4 1800628C */  lw         $v0, 0x18($v1)
    /* 2B6E8 8003AEE8 00000000 */  nop
    /* 2B6EC 8003AEEC 02004010 */  beqz       $v0, .L8003AEF8
    /* 2B6F0 8003AEF0 00000000 */   nop
    /* 2B6F4 8003AEF4 0C0044AC */  sw         $a0, 0xC($v0)
  .L8003AEF8:
    /* 2B6F8 8003AEF8 2400628C */  lw         $v0, 0x24($v1)
    /* 2B6FC 8003AEFC 00000000 */  nop
    /* 2B700 8003AF00 02004010 */  beqz       $v0, .L8003AF0C
    /* 2B704 8003AF04 00000000 */   nop
    /* 2B708 8003AF08 0C0044AC */  sw         $a0, 0xC($v0)
  .L8003AF0C:
    /* 2B70C 8003AF0C FFFFC624 */  addiu      $a2, $a2, -0x1
    /* 2B710 8003AF10 F4FFC104 */  bgez       $a2, .L8003AEE4
    /* 2B714 8003AF14 FCFF6324 */   addiu     $v1, $v1, -0x4
    /* 2B718 8003AF18 02000624 */  addiu      $a2, $zero, 0x2
    /* 2B71C 8003AF1C 08008526 */  addiu      $a1, $s4, 0x8
    /* 2B720 8003AF20 40008386 */  lh         $v1, 0x40($s4)
    /* 2B724 8003AF24 80000224 */  addiu      $v0, $zero, 0x80
    /* 2B728 8003AF28 23204300 */  subu       $a0, $v0, $v1
    /* 2B72C 8003AF2C 00120400 */  sll        $v0, $a0, 8
    /* 2B730 8003AF30 001C0400 */  sll        $v1, $a0, 16
    /* 2B734 8003AF34 25104300 */  or         $v0, $v0, $v1
    /* 2B738 8003AF38 25208200 */  or         $a0, $a0, $v0
  .L8003AF3C:
    /* 2B73C 8003AF3C 0000A28C */  lw         $v0, 0x0($a1)
    /* 2B740 8003AF40 00000000 */  nop
    /* 2B744 8003AF44 02004010 */  beqz       $v0, .L8003AF50
    /* 2B748 8003AF48 00000000 */   nop
    /* 2B74C 8003AF4C 0C0044AC */  sw         $a0, 0xC($v0)
  .L8003AF50:
    /* 2B750 8003AF50 0C00A28C */  lw         $v0, 0xC($a1)
    /* 2B754 8003AF54 00000000 */  nop
    /* 2B758 8003AF58 02004010 */  beqz       $v0, .L8003AF64
    /* 2B75C 8003AF5C 00000000 */   nop
    /* 2B760 8003AF60 0C0044AC */  sw         $a0, 0xC($v0)
  .L8003AF64:
    /* 2B764 8003AF64 FFFFC624 */  addiu      $a2, $a2, -0x1
    /* 2B768 8003AF68 F4FFC104 */  bgez       $a2, .L8003AF3C
    /* 2B76C 8003AF6C FCFFA524 */   addiu     $a1, $a1, -0x4
    /* 2B770 8003AF70 40008286 */  lh         $v0, 0x40($s4)
    /* 2B774 8003AF74 00000000 */  nop
    /* 2B778 8003AF78 03004104 */  bgez       $v0, .L8003AF88
    /* 2B77C 8003AF7C C3200200 */   sra       $a0, $v0, 3
    /* 2B780 8003AF80 07004224 */  addiu      $v0, $v0, 0x7
    /* 2B784 8003AF84 C3200200 */  sra        $a0, $v0, 3
  .L8003AF88:
    /* 2B788 8003AF88 1000A4AF */  sw         $a0, 0x10($sp)
    /* 2B78C 8003AF8C 40008386 */  lh         $v1, 0x40($s4)
    /* 2B790 8003AF90 80000224 */  addiu      $v0, $zero, 0x80
    /* 2B794 8003AF94 23104300 */  subu       $v0, $v0, $v1
    /* 2B798 8003AF98 03004104 */  bgez       $v0, .L8003AFA8
    /* 2B79C 8003AF9C C3180200 */   sra       $v1, $v0, 3
    /* 2B7A0 8003AFA0 07004224 */  addiu      $v0, $v0, 0x7
    /* 2B7A4 8003AFA4 C3180200 */  sra        $v1, $v0, 3
  .L8003AFA8:
    /* 2B7A8 8003AFA8 23100300 */  negu       $v0, $v1
    /* 2B7AC 8003AFAC 1400A2AF */  sw         $v0, 0x14($sp)
    /* 2B7B0 8003AFB0 3C008292 */  lbu        $v0, 0x3C($s4)
    /* 2B7B4 8003AFB4 00000000 */  nop
    /* 2B7B8 8003AFB8 03004014 */  bnez       $v0, .L8003AFC8
    /* 2B7BC 8003AFBC 23100400 */   negu      $v0, $a0
    /* 2B7C0 8003AFC0 1000A2AF */  sw         $v0, 0x10($sp)
    /* 2B7C4 8003AFC4 1400A3AF */  sw         $v1, 0x14($sp)
  .L8003AFC8:
    /* 2B7C8 8003AFC8 21208002 */  addu       $a0, $s4, $zero
    /* 2B7CC 8003AFCC 34008386 */  lh         $v1, 0x34($s4)
    /* 2B7D0 8003AFD0 1000A28F */  lw         $v0, 0x10($sp)
    /* 2B7D4 8003AFD4 36009186 */  lh         $s1, 0x36($s4)
    /* 2B7D8 8003AFD8 21186200 */  addu       $v1, $v1, $v0
    /* 2B7DC 8003AFDC 00840300 */  sll        $s0, $v1, 16
    /* 2B7E0 8003AFE0 03841000 */  sra        $s0, $s0, 16
    /* 2B7E4 8003AFE4 21280002 */  addu       $a1, $s0, $zero
    /* 2B7E8 8003AFE8 48EA000C */  jal        func_8003A920
    /* 2B7EC 8003AFEC 21302002 */   addu      $a2, $s1, $zero
    /* 2B7F0 8003AFF0 0C008426 */  addiu      $a0, $s4, 0xC
    /* 2B7F4 8003AFF4 21280002 */  addu       $a1, $s0, $zero
    /* 2B7F8 8003AFF8 48EA000C */  jal        func_8003A920
    /* 2B7FC 8003AFFC 21302002 */   addu      $a2, $s1, $zero
    /* 2B800 8003B000 18008426 */  addiu      $a0, $s4, 0x18
    /* 2B804 8003B004 34008386 */  lh         $v1, 0x34($s4)
    /* 2B808 8003B008 1400A28F */  lw         $v0, 0x14($sp)
    /* 2B80C 8003B00C 21302002 */  addu       $a2, $s1, $zero
    /* 2B810 8003B010 23186200 */  subu       $v1, $v1, $v0
    /* 2B814 8003B014 00840300 */  sll        $s0, $v1, 16
    /* 2B818 8003B018 03841000 */  sra        $s0, $s0, 16
    /* 2B81C 8003B01C 48EA000C */  jal        func_8003A920
    /* 2B820 8003B020 21280002 */   addu      $a1, $s0, $zero
    /* 2B824 8003B024 24008426 */  addiu      $a0, $s4, 0x24
    /* 2B828 8003B028 21280002 */  addu       $a1, $s0, $zero
    /* 2B82C 8003B02C 48EA000C */  jal        func_8003A920
    /* 2B830 8003B030 21302002 */   addu      $a2, $s1, $zero
  .L8003B034:
    /* 2B834 8003B034 2C00BF8F */  lw         $ra, 0x2C($sp)
    /* 2B838 8003B038 2800B48F */  lw         $s4, 0x28($sp)
    /* 2B83C 8003B03C 2400B38F */  lw         $s3, 0x24($sp)
    /* 2B840 8003B040 2000B28F */  lw         $s2, 0x20($sp)
    /* 2B844 8003B044 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 2B848 8003B048 1800B08F */  lw         $s0, 0x18($sp)
    /* 2B84C 8003B04C 0800E003 */  jr         $ra
    /* 2B850 8003B050 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel func_8003AD6C
