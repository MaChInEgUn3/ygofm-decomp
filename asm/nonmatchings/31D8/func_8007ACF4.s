nonmatching func_8007ACF4, 0x224

glabel func_8007ACF4
    /* 6B4F4 8007ACF4 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 6B4F8 8007ACF8 21308000 */  addu       $a2, $a0, $zero
    /* 6B4FC 8007ACFC 1400B1AF */  sw         $s1, 0x14($sp)
    /* 6B500 8007AD00 2188A000 */  addu       $s1, $a1, $zero
    /* 6B504 8007AD04 1800B2AF */  sw         $s2, 0x18($sp)
    /* 6B508 8007AD08 0F80123C */  lui        $s2, %hi(D_800F5EE4)
    /* 6B50C 8007AD0C E45E5226 */  addiu      $s2, $s2, %lo(D_800F5EE4)
    /* 6B510 8007AD10 2400BFAF */  sw         $ra, 0x24($sp)
    /* 6B514 8007AD14 2000B4AF */  sw         $s4, 0x20($sp)
    /* 6B518 8007AD18 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 6B51C 8007AD1C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 6B520 8007AD20 0000438E */  lw         $v1, 0x0($s2)
    /* 6B524 8007AD24 3CFF5326 */  addiu      $s3, $s2, -0xC4
    /* 6B528 8007AD28 40100300 */  sll        $v0, $v1, 1
    /* 6B52C 8007AD2C 21104300 */  addu       $v0, $v0, $v1
    /* 6B530 8007AD30 C0100200 */  sll        $v0, $v0, 3
    /* 6B534 8007AD34 21805300 */  addu       $s0, $v0, $s3
    /* 6B538 8007AD38 0000038E */  lw         $v1, 0x0($s0)
    /* 6B53C 8007AD3C 00000000 */  nop
    /* 6B540 8007AD40 46006010 */  beqz       $v1, .L8007AE5C
    /* 6B544 8007AD44 21A0C000 */   addu      $s4, $a2, $zero
    /* 6B548 8007AD48 0F80023C */  lui        $v0, %hi(D_800F5DF0)
    /* 6B54C 8007AD4C F05D4224 */  addiu      $v0, $v0, %lo(D_800F5DF0)
    /* 6B550 8007AD50 05004424 */  addiu      $a0, $v0, 0x5
    /* 6B554 8007AD54 000043AC */  sw         $v1, 0x0($v0)
    /* 6B558 8007AD58 5BF3010C */  jal        func_8007CD6C
    /* 6B55C 8007AD5C 040046A0 */   sb        $a2, 0x4($v0)
    /* 6B560 8007AD60 FF008332 */  andi       $v1, $s4, 0xFF
    /* 6B564 8007AD64 02000224 */  addiu      $v0, $zero, 0x2
    /* 6B568 8007AD68 05006210 */  beq        $v1, $v0, .L8007AD80
    /* 6B56C 8007AD6C 05000224 */   addiu     $v0, $zero, 0x5
    /* 6B570 8007AD70 20006210 */  beq        $v1, $v0, .L8007ADF4
    /* 6B574 8007AD74 00000000 */   nop
    /* 6B578 8007AD78 97EB0108 */  j          .L8007AE5C
    /* 6B57C 8007AD7C 00000000 */   nop
  .L8007AD80:
    /* 6B580 8007AD80 0000428E */  lw         $v0, 0x0($s2)
    /* 6B584 8007AD84 00000000 */  nop
    /* 6B588 8007AD88 01004524 */  addiu      $a1, $v0, 0x1
    /* 6B58C 8007AD8C 0800A628 */  slti       $a2, $a1, 0x8
    /* 6B590 8007AD90 0200C014 */  bnez       $a2, .L8007AD9C
    /* 6B594 8007AD94 2118A000 */   addu      $v1, $a1, $zero
    /* 6B598 8007AD98 21180000 */  addu       $v1, $zero, $zero
  .L8007AD9C:
    /* 6B59C 8007AD9C 40100300 */  sll        $v0, $v1, 1
    /* 6B5A0 8007ADA0 21104300 */  addu       $v0, $v0, $v1
    /* 6B5A4 8007ADA4 C0100200 */  sll        $v0, $v0, 3
    /* 6B5A8 8007ADA8 21105300 */  addu       $v0, $v0, $s3
    /* 6B5AC 8007ADAC 0000428C */  lw         $v0, 0x0($v0)
    /* 6B5B0 8007ADB0 0000048E */  lw         $a0, 0x0($s0)
    /* 6B5B4 8007ADB4 00000000 */  nop
    /* 6B5B8 8007ADB8 0A004410 */  beq        $v0, $a0, .L8007ADE4
    /* 6B5BC 8007ADBC 00000000 */   nop
    /* 6B5C0 8007ADC0 02000524 */  addiu      $a1, $zero, 0x2
    /* 6B5C4 8007ADC4 C6EB010C */  jal        func_8007AF18
    /* 6B5C8 8007ADC8 21302002 */   addu      $a2, $s1, $zero
    /* 6B5CC 8007ADCC 1000028E */  lw         $v0, 0x10($s0)
    /* 6B5D0 8007ADD0 00000000 */  nop
    /* 6B5D4 8007ADD4 1F004010 */  beqz       $v0, .L8007AE54
    /* 6B5D8 8007ADD8 02000424 */   addiu     $a0, $zero, 0x2
    /* 6B5DC 8007ADDC 93EB0108 */  j          .L8007AE4C
    /* 6B5E0 8007ADE0 00000000 */   nop
  .L8007ADE4:
    /* 6B5E4 8007ADE4 1D00C014 */  bnez       $a2, .L8007AE5C
    /* 6B5E8 8007ADE8 000045AE */   sw        $a1, 0x0($s2)
    /* 6B5EC 8007ADEC 97EB0108 */  j          .L8007AE5C
    /* 6B5F0 8007ADF0 000040AE */   sw        $zero, 0x0($s2)
  .L8007ADF4:
    /* 6B5F4 8007ADF4 1400038E */  lw         $v1, 0x14($s0)
    /* 6B5F8 8007ADF8 00000000 */  nop
    /* 6B5FC 8007ADFC 0300601C */  bgtz       $v1, .L8007AE0C
    /* 6B600 8007AE00 FFFF0224 */   addiu     $v0, $zero, -0x1
    /* 6B604 8007AE04 0A006214 */  bne        $v1, $v0, .L8007AE30
    /* 6B608 8007AE08 05000524 */   addiu     $a1, $zero, 0x5
  .L8007AE0C:
    /* 6B60C 8007AE0C C000628E */  lw         $v0, 0xC0($s3)
    /* 6B610 8007AE10 00000000 */  nop
    /* 6B614 8007AE14 000042AE */  sw         $v0, 0x0($s2)
    /* 6B618 8007AE18 1400038E */  lw         $v1, 0x14($s0)
    /* 6B61C 8007AE1C FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 6B620 8007AE20 0E006210 */  beq        $v1, $v0, .L8007AE5C
    /* 6B624 8007AE24 FFFF6224 */   addiu     $v0, $v1, -0x1
    /* 6B628 8007AE28 97EB0108 */  j          .L8007AE5C
    /* 6B62C 8007AE2C 140002AE */   sw        $v0, 0x14($s0)
  .L8007AE30:
    /* 6B630 8007AE30 0000048E */  lw         $a0, 0x0($s0)
    /* 6B634 8007AE34 C6EB010C */  jal        func_8007AF18
    /* 6B638 8007AE38 21302002 */   addu      $a2, $s1, $zero
    /* 6B63C 8007AE3C 1000028E */  lw         $v0, 0x10($s0)
    /* 6B640 8007AE40 00000000 */  nop
    /* 6B644 8007AE44 03004010 */  beqz       $v0, .L8007AE54
    /* 6B648 8007AE48 05000424 */   addiu     $a0, $zero, 0x5
  .L8007AE4C:
    /* 6B64C 8007AE4C 09F84000 */  jalr       $v0
    /* 6B650 8007AE50 21282002 */   addu      $a1, $s1, $zero
  .L8007AE54:
    /* 6B654 8007AE54 30EA010C */  jal        func_8007A8C0
    /* 6B658 8007AE58 00000000 */   nop
  .L8007AE5C:
    /* 6B65C 8007AE5C 1080023C */  lui        $v0, %hi(D_800F8390)
    /* 6B660 8007AE60 9083428C */  lw         $v0, %lo(D_800F8390)($v0)
    /* 6B664 8007AE64 00000000 */  nop
    /* 6B668 8007AE68 03004010 */  beqz       $v0, .L8007AE78
    /* 6B66C 8007AE6C FF008432 */   andi      $a0, $s4, 0xFF
    /* 6B670 8007AE70 09F84000 */  jalr       $v0
    /* 6B674 8007AE74 21282002 */   addu      $a1, $s1, $zero
  .L8007AE78:
    /* 6B678 8007AE78 BBEF010C */  jal        func_8007BEEC
    /* 6B67C 8007AE7C 21200000 */   addu      $a0, $zero, $zero
    /* 6B680 8007AE80 21804000 */  addu       $s0, $v0, $zero
    /* 6B684 8007AE84 01000224 */  addiu      $v0, $zero, 0x1
    /* 6B688 8007AE88 1B000216 */  bne        $s0, $v0, .L8007AEF8
    /* 6B68C 8007AE8C 00000000 */   nop
    /* 6B690 8007AE90 0F80113C */  lui        $s1, %hi(D_800F5EE8)
    /* 6B694 8007AE94 E85E3126 */  addiu      $s1, $s1, %lo(D_800F5EE8)
    /* 6B698 8007AE98 0000228E */  lw         $v0, 0x0($s1)
    /* 6B69C 8007AE9C 00000000 */  nop
    /* 6B6A0 8007AEA0 15004018 */  blez       $v0, .L8007AEF8
    /* 6B6A4 8007AEA4 00000000 */   nop
    /* 6B6A8 8007AEA8 BBEF010C */  jal        func_8007BEEC
    /* 6B6AC 8007AEAC 21200000 */   addu      $a0, $zero, $zero
    /* 6B6B0 8007AEB0 11005014 */  bne        $v0, $s0, .L8007AEF8
    /* 6B6B4 8007AEB4 00000000 */   nop
    /* 6B6B8 8007AEB8 0F80033C */  lui        $v1, %hi(D_800F5EE4)
    /* 6B6BC 8007AEBC E45E638C */  lw         $v1, %lo(D_800F5EE4)($v1)
    /* 6B6C0 8007AEC0 00000000 */  nop
    /* 6B6C4 8007AEC4 40100300 */  sll        $v0, $v1, 1
    /* 6B6C8 8007AEC8 21104300 */  addu       $v0, $v0, $v1
    /* 6B6CC 8007AECC C0100200 */  sll        $v0, $v0, 3
    /* 6B6D0 8007AED0 38FF2326 */  addiu      $v1, $s1, -0xC8
    /* 6B6D4 8007AED4 21184300 */  addu       $v1, $v0, $v1
    /* 6B6D8 8007AED8 0000628C */  lw         $v0, 0x0($v1)
    /* 6B6DC 8007AEDC 00000000 */  nop
    /* 6B6E0 8007AEE0 05004010 */  beqz       $v0, .L8007AEF8
    /* 6B6E4 8007AEE4 00000000 */   nop
    /* 6B6E8 8007AEE8 04006490 */  lbu        $a0, 0x4($v1)
    /* 6B6EC 8007AEEC 0C00658C */  lw         $a1, 0xC($v1)
    /* 6B6F0 8007AEF0 90EF010C */  jal        func_8007BE40
    /* 6B6F4 8007AEF4 00000000 */   nop
  .L8007AEF8:
    /* 6B6F8 8007AEF8 2400BF8F */  lw         $ra, 0x24($sp)
    /* 6B6FC 8007AEFC 2000B48F */  lw         $s4, 0x20($sp)
    /* 6B700 8007AF00 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 6B704 8007AF04 1800B28F */  lw         $s2, 0x18($sp)
    /* 6B708 8007AF08 1400B18F */  lw         $s1, 0x14($sp)
    /* 6B70C 8007AF0C 1000B08F */  lw         $s0, 0x10($sp)
    /* 6B710 8007AF10 0800E003 */  jr         $ra
    /* 6B714 8007AF14 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_8007ACF4
