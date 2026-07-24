nonmatching func_8005A53C, 0xDC

glabel func_8005A53C
    /* 4AD3C 8005A53C D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 4AD40 8005A540 2400B5AF */  sw         $s5, 0x24($sp)
    /* 4AD44 8005A544 21A88000 */  addu       $s5, $a0, $zero
    /* 4AD48 8005A548 1000B0AF */  sw         $s0, 0x10($sp)
    /* 4AD4C 8005A54C 2180A000 */  addu       $s0, $a1, $zero
    /* 4AD50 8005A550 1400B1AF */  sw         $s1, 0x14($sp)
    /* 4AD54 8005A554 FFFFF124 */  addiu      $s1, $a3, -0x1
    /* 4AD58 8005A558 2800BFAF */  sw         $ra, 0x28($sp)
    /* 4AD5C 8005A55C 2000B4AF */  sw         $s4, 0x20($sp)
    /* 4AD60 8005A560 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 4AD64 8005A564 2300E010 */  beqz       $a3, .L8005A5F4
    /* 4AD68 8005A568 1800B2AF */   sw        $s2, 0x18($sp)
    /* 4AD6C 8005A56C FFFF143C */  lui        $s4, (0xFFFF0000 >> 16)
    /* 4AD70 8005A570 FFFF1324 */  addiu      $s3, $zero, -0x1
  .L8005A574:
    /* 4AD74 8005A574 0000048E */  lw         $a0, 0x0($s0)
    /* 4AD78 8005A578 7480010C */  jal        func_800601D0
    /* 4AD7C 8005A57C 00000000 */   nop
    /* 4AD80 8005A580 21204000 */  addu       $a0, $v0, $zero
    /* 4AD84 8005A584 0400038E */  lw         $v1, 0x4($s0)
    /* 4AD88 8005A588 032E0400 */  sra        $a1, $a0, 24
    /* 4AD8C 8005A58C FFFF6230 */  andi       $v0, $v1, 0xFFFF
    /* 4AD90 8005A590 01005224 */  addiu      $s2, $v0, 0x1
    /* 4AD94 8005A594 0200A22C */  sltiu      $v0, $a1, 0x2
    /* 4AD98 8005A598 06004010 */  beqz       $v0, .L8005A5B4
    /* 4AD9C 8005A59C 24187400 */   and       $v1, $v1, $s4
    /* 4ADA0 8005A5A0 FFFF8230 */  andi       $v0, $a0, 0xFFFF
    /* 4ADA4 8005A5A4 04004010 */  beqz       $v0, .L8005A5B8
    /* 4ADA8 8005A5A8 01000224 */   addiu     $v0, $zero, 0x1
    /* 4ADAC 8005A5AC 07006014 */  bnez       $v1, .L8005A5CC
    /* 4ADB0 8005A5B0 00000000 */   nop
  .L8005A5B4:
    /* 4ADB4 8005A5B4 01000224 */  addiu      $v0, $zero, 0x1
  .L8005A5B8:
    /* 4ADB8 8005A5B8 0B00A214 */  bne        $a1, $v0, .L8005A5E8
    /* 4ADBC 8005A5BC 80101200 */   sll       $v0, $s2, 2
    /* 4ADC0 8005A5C0 FFFF8230 */  andi       $v0, $a0, 0xFFFF
    /* 4ADC4 8005A5C4 08004014 */  bnez       $v0, .L8005A5E8
    /* 4ADC8 8005A5C8 80101200 */   sll       $v0, $s2, 2
  .L8005A5CC:
    /* 4ADCC 8005A5CC 0000048E */  lw         $a0, 0x0($s0)
    /* 4ADD0 8005A5D0 09F8A002 */  jalr       $s5
    /* 4ADD4 8005A5D4 00000000 */   nop
    /* 4ADD8 8005A5D8 02005310 */  beq        $v0, $s3, .L8005A5E4
    /* 4ADDC 8005A5DC 00000000 */   nop
    /* 4ADE0 8005A5E0 000002AE */  sw         $v0, 0x0($s0)
  .L8005A5E4:
    /* 4ADE4 8005A5E4 80101200 */  sll        $v0, $s2, 2
  .L8005A5E8:
    /* 4ADE8 8005A5E8 FFFF3126 */  addiu      $s1, $s1, -0x1
    /* 4ADEC 8005A5EC E1FF3316 */  bne        $s1, $s3, .L8005A574
    /* 4ADF0 8005A5F0 21800202 */   addu      $s0, $s0, $v0
  .L8005A5F4:
    /* 4ADF4 8005A5F4 2800BF8F */  lw         $ra, 0x28($sp)
    /* 4ADF8 8005A5F8 2400B58F */  lw         $s5, 0x24($sp)
    /* 4ADFC 8005A5FC 2000B48F */  lw         $s4, 0x20($sp)
    /* 4AE00 8005A600 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 4AE04 8005A604 1800B28F */  lw         $s2, 0x18($sp)
    /* 4AE08 8005A608 1400B18F */  lw         $s1, 0x14($sp)
    /* 4AE0C 8005A60C 1000B08F */  lw         $s0, 0x10($sp)
    /* 4AE10 8005A610 0800E003 */  jr         $ra
    /* 4AE14 8005A614 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel func_8005A53C
