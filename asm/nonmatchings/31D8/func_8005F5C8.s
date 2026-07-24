nonmatching func_8005F5C8, 0x14C

glabel func_8005F5C8
    /* 4FDC8 8005F5C8 C0FFBD27 */  addiu      $sp, $sp, -0x40
    /* 4FDCC 8005F5CC 2C00B3AF */  sw         $s3, 0x2C($sp)
    /* 4FDD0 8005F5D0 21988000 */  addu       $s3, $a0, $zero
    /* 4FDD4 8005F5D4 3000B4AF */  sw         $s4, 0x30($sp)
    /* 4FDD8 8005F5D8 21A0C000 */  addu       $s4, $a2, $zero
    /* 4FDDC 8005F5DC 3400B5AF */  sw         $s5, 0x34($sp)
    /* 4FDE0 8005F5E0 21A8E000 */  addu       $s5, $a3, $zero
    /* 4FDE4 8005F5E4 C0280500 */  sll        $a1, $a1, 3
    /* 4FDE8 8005F5E8 0980023C */  lui        $v0, %hi(D_80091570)
    /* 4FDEC 8005F5EC 70154224 */  addiu      $v0, $v0, %lo(D_80091570)
    /* 4FDF0 8005F5F0 2400B1AF */  sw         $s1, 0x24($sp)
    /* 4FDF4 8005F5F4 2188A200 */  addu       $s1, $a1, $v0
    /* 4FDF8 8005F5F8 73018393 */  lbu        $v1, %gp_rel(D_8009B07B)($gp)
    /* 4FDFC 8005F5FC 01000224 */  addiu      $v0, $zero, 0x1
    /* 4FE00 8005F600 3800BFAF */  sw         $ra, 0x38($sp)
    /* 4FE04 8005F604 2800B2AF */  sw         $s2, 0x28($sp)
    /* 4FE08 8005F608 05006214 */  bne        $v1, $v0, .L8005F620
    /* 4FE0C 8005F60C 2000B0AF */   sw        $s0, 0x20($sp)
    /* 4FE10 8005F610 74018293 */  lbu        $v0, %gp_rel(D_8009B07C)($gp)
    /* 4FE14 8005F614 00000000 */  nop
    /* 4FE18 8005F618 35004310 */  beq        $v0, $v1, .L8005F6F0
    /* 4FE1C 8005F61C 00000000 */   nop
  .L8005F620:
    /* 4FE20 8005F620 00002296 */  lhu        $v0, 0x0($s1)
    /* 4FE24 8005F624 00000000 */  nop
    /* 4FE28 8005F628 00940200 */  sll        $s2, $v0, 16
    /* 4FE2C 8005F62C 0200622A */  slti       $v0, $s3, 0x2
    /* 4FE30 8005F630 28004010 */  beqz       $v0, .L8005F6D4
    /* 4FE34 8005F634 03841200 */   sra       $s0, $s2, 16
    /* 4FE38 8005F638 21206002 */  addu       $a0, $s3, $zero
    /* 4FE3C 8005F63C 0064010C */  jal        func_80059000
    /* 4FE40 8005F640 1800A527 */   addiu     $a1, $sp, 0x18
    /* 4FE44 8005F644 1E00A287 */  lh         $v0, 0x1E($sp)
    /* 4FE48 8005F648 00000000 */  nop
    /* 4FE4C 8005F64C 32004228 */  slti       $v0, $v0, 0x32
    /* 4FE50 8005F650 02004010 */  beqz       $v0, .L8005F65C
    /* 4FE54 8005F654 32000224 */   addiu     $v0, $zero, 0x32
    /* 4FE58 8005F658 1E00A2A7 */  sh         $v0, 0x1E($sp)
  .L8005F65C:
    /* 4FE5C 8005F65C 1E00A297 */  lhu        $v0, 0x1E($sp)
    /* 4FE60 8005F660 00000000 */  nop
    /* 4FE64 8005F664 D4FE4224 */  addiu      $v0, $v0, -0x12C
    /* 4FE68 8005F668 1E00A2A7 */  sh         $v0, 0x1E($sp)
    /* 4FE6C 8005F66C 00140200 */  sll        $v0, $v0, 16
    /* 4FE70 8005F670 031C0200 */  sra        $v1, $v0, 16
    /* 4FE74 8005F674 17006010 */  beqz       $v1, .L8005F6D4
    /* 4FE78 8005F678 21100002 */   addu      $v0, $s0, $zero
    /* 4FE7C 8005F67C 04006018 */  blez       $v1, .L8005F690
    /* 4FE80 8005F680 EE020424 */   addiu     $a0, $zero, 0x2EE
    /* 4FE84 8005F684 C2171200 */  srl        $v0, $s2, 31
    /* 4FE88 8005F688 21100202 */  addu       $v0, $s0, $v0
    /* 4FE8C 8005F68C 43100200 */  sra        $v0, $v0, 1
  .L8005F690:
    /* 4FE90 8005F690 18006200 */  mult       $v1, $v0
    /* 4FE94 8005F694 12100000 */  mflo       $v0
    /* 4FE98 8005F698 00000000 */  nop
    /* 4FE9C 8005F69C 00000000 */  nop
    /* 4FEA0 8005F6A0 1A004400 */  div        $zero, $v0, $a0
    /* 4FEA4 8005F6A4 02008014 */  bnez       $a0, .L8005F6B0
    /* 4FEA8 8005F6A8 00000000 */   nop
    /* 4FEAC 8005F6AC 0D000700 */  break      7
  .L8005F6B0:
    /* 4FEB0 8005F6B0 FFFF0124 */  addiu      $at, $zero, -0x1
    /* 4FEB4 8005F6B4 04008114 */  bne        $a0, $at, .L8005F6C8
    /* 4FEB8 8005F6B8 0080013C */   lui       $at, (0x80000000 >> 16)
    /* 4FEBC 8005F6BC 02004114 */  bne        $v0, $at, .L8005F6C8
    /* 4FEC0 8005F6C0 00000000 */   nop
    /* 4FEC4 8005F6C4 0D000600 */  break      6
  .L8005F6C8:
    /* 4FEC8 8005F6C8 12100000 */  mflo       $v0
    /* 4FECC 8005F6CC 00000000 */  nop
    /* 4FED0 8005F6D0 21800202 */  addu       $s0, $s0, $v0
  .L8005F6D4:
    /* 4FED4 8005F6D4 21206002 */  addu       $a0, $s3, $zero
    /* 4FED8 8005F6D8 02002686 */  lh         $a2, 0x2($s1)
    /* 4FEDC 8005F6DC 04002786 */  lh         $a3, 0x4($s1)
    /* 4FEE0 8005F6E0 21280002 */  addu       $a1, $s0, $zero
    /* 4FEE4 8005F6E4 1000B4AF */  sw         $s4, 0x10($sp)
    /* 4FEE8 8005F6E8 6576010C */  jal        func_8005D994
    /* 4FEEC 8005F6EC 1400B5AF */   sw        $s5, 0x14($sp)
  .L8005F6F0:
    /* 4FEF0 8005F6F0 3800BF8F */  lw         $ra, 0x38($sp)
    /* 4FEF4 8005F6F4 3400B58F */  lw         $s5, 0x34($sp)
    /* 4FEF8 8005F6F8 3000B48F */  lw         $s4, 0x30($sp)
    /* 4FEFC 8005F6FC 2C00B38F */  lw         $s3, 0x2C($sp)
    /* 4FF00 8005F700 2800B28F */  lw         $s2, 0x28($sp)
    /* 4FF04 8005F704 2400B18F */  lw         $s1, 0x24($sp)
    /* 4FF08 8005F708 2000B08F */  lw         $s0, 0x20($sp)
    /* 4FF0C 8005F70C 0800E003 */  jr         $ra
    /* 4FF10 8005F710 4000BD27 */   addiu     $sp, $sp, 0x40
endlabel func_8005F5C8
