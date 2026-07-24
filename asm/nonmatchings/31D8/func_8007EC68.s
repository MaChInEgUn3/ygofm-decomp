nonmatching func_8007EC68, 0x31C

glabel func_8007EC68
    /* 6F468 8007EC68 B0FFBD27 */  addiu      $sp, $sp, -0x50
    /* 6F46C 8007EC6C 80000624 */  addiu      $a2, $zero, 0x80
    /* 6F470 8007EC70 1C00A6AF */  sw         $a2, 0x1C($sp)
    /* 6F474 8007EC74 2000A6AF */  sw         $a2, 0x20($sp)
    /* 6F478 8007EC78 4C00BFAF */  sw         $ra, 0x4C($sp)
    /* 6F47C 8007EC7C 4800BEAF */  sw         $fp, 0x48($sp)
    /* 6F480 8007EC80 4400B7AF */  sw         $s7, 0x44($sp)
    /* 6F484 8007EC84 4000B6AF */  sw         $s6, 0x40($sp)
    /* 6F488 8007EC88 3C00B5AF */  sw         $s5, 0x3C($sp)
    /* 6F48C 8007EC8C 3800B4AF */  sw         $s4, 0x38($sp)
    /* 6F490 8007EC90 3400B3AF */  sw         $s3, 0x34($sp)
    /* 6F494 8007EC94 3000B2AF */  sw         $s2, 0x30($sp)
    /* 6F498 8007EC98 2C00B1AF */  sw         $s1, 0x2C($sp)
    /* 6F49C 8007EC9C 2800B0AF */  sw         $s0, 0x28($sp)
    /* 6F4A0 8007ECA0 1400A0AF */  sw         $zero, 0x14($sp)
    /* 6F4A4 8007ECA4 07008004 */  bltz       $a0, .L8007ECC4
    /* 6F4A8 8007ECA8 2400A6AF */   sw        $a2, 0x24($sp)
    /* 6F4AC 8007ECAC 0980023C */  lui        $v0, %hi(D_80093C08)
    /* 6F4B0 8007ECB0 083C428C */  lw         $v0, %lo(D_80093C08)($v0)
    /* 6F4B4 8007ECB4 00000000 */  nop
    /* 6F4B8 8007ECB8 2A108200 */  slt        $v0, $a0, $v0
    /* 6F4BC 8007ECBC 0F004014 */  bnez       $v0, .L8007ECFC
    /* 6F4C0 8007ECC0 40100400 */   sll       $v0, $a0, 1
  .L8007ECC4:
    /* 6F4C4 8007ECC4 0980043C */  lui        $a0, %hi(D_80093C0C)
    /* 6F4C8 8007ECC8 0C3C848C */  lw         $a0, %lo(D_80093C0C)($a0)
    /* 6F4CC 8007ECCC 00000000 */  nop
    /* 6F4D0 8007ECD0 40100400 */  sll        $v0, $a0, 1
    /* 6F4D4 8007ECD4 21104400 */  addu       $v0, $v0, $a0
    /* 6F4D8 8007ECD8 00110200 */  sll        $v0, $v0, 4
    /* 6F4DC 8007ECDC 0980013C */  lui        $at, %hi(D_80093AAC)
    /* 6F4E0 8007ECE0 21082200 */  addu       $at, $at, $v0
    /* 6F4E4 8007ECE4 AC3A228C */  lw         $v0, %lo(D_80093AAC)($at)
    /* 6F4E8 8007ECE8 00000000 */  nop
    /* 6F4EC 8007ECEC 03004014 */  bnez       $v0, .L8007ECFC
    /* 6F4F0 8007ECF0 40100400 */   sll       $v0, $a0, 1
    /* 6F4F4 8007ECF4 D5FB0108 */  j          .L8007EF54
    /* 6F4F8 8007ECF8 21100000 */   addu      $v0, $zero, $zero
  .L8007ECFC:
    /* 6F4FC 8007ECFC 21104400 */  addu       $v0, $v0, $a0
    /* 6F500 8007ED00 00110200 */  sll        $v0, $v0, 4
    /* 6F504 8007ED04 0980033C */  lui        $v1, %hi(D_80093A88)
    /* 6F508 8007ED08 883A6324 */  addiu      $v1, $v1, %lo(D_80093A88)
    /* 6F50C 8007ED0C 21984300 */  addu       $s3, $v0, $v1
    /* 6F510 8007ED10 10006626 */  addiu      $a2, $s3, 0x10
    /* 6F514 8007ED14 1000A6AF */  sw         $a2, 0x10($sp)
    /* 6F518 8007ED18 1000A48F */  lw         $a0, 0x10($sp)
    /* 6F51C 8007ED1C 2400708E */  lw         $s0, 0x24($s3)
    /* 6F520 8007ED20 1C007E8E */  lw         $fp, 0x1C($s3)
    /* 6F524 8007ED24 08007186 */  lh         $s1, 0x8($s3)
    /* 6F528 8007ED28 0A007586 */  lh         $s5, 0xA($s3)
    /* 6F52C 8007ED2C 0C006286 */  lh         $v0, 0xC($s3)
    /* 6F530 8007ED30 0E006386 */  lh         $v1, 0xE($s3)
    /* 6F534 8007ED34 00000000 */  nop
    /* 6F538 8007ED38 2118A302 */  addu       $v1, $s5, $v1
    /* 6F53C 8007ED3C 1800A3AF */  sw         $v1, 0x18($sp)
    /* 6F540 8007ED40 2000728E */  lw         $s2, 0x20($s3)
    /* 6F544 8007ED44 2C00768E */  lw         $s6, 0x2C($s3)
    /* 6F548 8007ED48 080A020C */  jal        func_80082820
    /* 6F54C 8007ED4C 21B82202 */   addu      $s7, $s1, $v0
    /* 6F550 8007ED50 B9FB0108 */  j          .L8007EEE4
    /* 6F554 8007ED54 00000000 */   nop
  .L8007ED58:
    /* 6F558 8007ED58 6600C013 */  beqz       $fp, .L8007EEF4
    /* 6F55C 8007ED5C 00160300 */   sll       $v0, $v1, 24
    /* 6F560 8007ED60 031E0200 */  sra        $v1, $v0, 24
    /* 6F564 8007ED64 20000224 */  addiu      $v0, $zero, 0x20
    /* 6F568 8007ED68 47006210 */  beq        $v1, $v0, .L8007EE88
    /* 6F56C 8007ED6C 21A00000 */   addu      $s4, $zero, $zero
    /* 6F570 8007ED70 21006228 */  slti       $v0, $v1, 0x21
    /* 6F574 8007ED74 07004010 */  beqz       $v0, .L8007ED94
    /* 6F578 8007ED78 09000224 */   addiu     $v0, $zero, 0x9
    /* 6F57C 8007ED7C 1D006210 */  beq        $v1, $v0, .L8007EDF4
    /* 6F580 8007ED80 0A000224 */   addiu     $v0, $zero, 0xA
    /* 6F584 8007ED84 46006210 */  beq        $v1, $v0, .L8007EEA0
    /* 6F588 8007ED88 00000000 */   nop
    /* 6F58C 8007ED8C 7FFB0108 */  j          .L8007EDFC
    /* 6F590 8007ED90 00000000 */   nop
  .L8007ED94:
    /* 6F594 8007ED94 7E000224 */  addiu      $v0, $zero, 0x7E
    /* 6F598 8007ED98 18006214 */  bne        $v1, $v0, .L8007EDFC
    /* 6F59C 8007ED9C 63000224 */   addiu     $v0, $zero, 0x63
    /* 6F5A0 8007EDA0 01001026 */  addiu      $s0, $s0, 0x1
    /* 6F5A4 8007EDA4 00000382 */  lb         $v1, 0x0($s0)
    /* 6F5A8 8007EDA8 00000000 */  nop
    /* 6F5AC 8007EDAC 3D006214 */  bne        $v1, $v0, .L8007EEA4
    /* 6F5B0 8007EDB0 00000000 */   nop
    /* 6F5B4 8007EDB4 01001026 */  addiu      $s0, $s0, 0x1
    /* 6F5B8 8007EDB8 00000282 */  lb         $v0, 0x0($s0)
    /* 6F5BC 8007EDBC 01001026 */  addiu      $s0, $s0, 0x1
    /* 6F5C0 8007EDC0 00000382 */  lb         $v1, 0x0($s0)
    /* 6F5C4 8007EDC4 01001026 */  addiu      $s0, $s0, 0x1
    /* 6F5C8 8007EDC8 D0FF4224 */  addiu      $v0, $v0, -0x30
    /* 6F5CC 8007EDCC 00110200 */  sll        $v0, $v0, 4
    /* 6F5D0 8007EDD0 D0FF6324 */  addiu      $v1, $v1, -0x30
    /* 6F5D4 8007EDD4 1C00A2AF */  sw         $v0, 0x1C($sp)
    /* 6F5D8 8007EDD8 00000282 */  lb         $v0, 0x0($s0)
    /* 6F5DC 8007EDDC 00190300 */  sll        $v1, $v1, 4
    /* 6F5E0 8007EDE0 2000A3AF */  sw         $v1, 0x20($sp)
    /* 6F5E4 8007EDE4 D0FF4224 */  addiu      $v0, $v0, -0x30
    /* 6F5E8 8007EDE8 00110200 */  sll        $v0, $v0, 4
    /* 6F5EC 8007EDEC A9FB0108 */  j          .L8007EEA4
    /* 6F5F0 8007EDF0 2400A2AF */   sw        $v0, 0x24($sp)
  .L8007EDF4:
    /* 6F5F4 8007EDF4 A3FB0108 */  j          .L8007EE8C
    /* 6F5F8 8007EDF8 20003126 */   addiu     $s1, $s1, 0x20
  .L8007EDFC:
    /* 6F5FC 8007EDFC 00000392 */  lbu        $v1, 0x0($s0)
    /* 6F600 8007EE00 00000000 */  nop
    /* 6F604 8007EE04 9FFF6224 */  addiu      $v0, $v1, -0x61
    /* 6F608 8007EE08 1A00422C */  sltiu      $v0, $v0, 0x1A
    /* 6F60C 8007EE0C 04004010 */  beqz       $v0, .L8007EE20
    /* 6F610 8007EE10 00160300 */   sll       $v0, $v1, 24
    /* 6F614 8007EE14 03160200 */  sra        $v0, $v0, 24
    /* 6F618 8007EE18 8AFB0108 */  j          .L8007EE28
    /* 6F61C 8007EE1C C0FF4324 */   addiu     $v1, $v0, -0x40
  .L8007EE20:
    /* 6F620 8007EE20 03160200 */  sra        $v0, $v0, 24
    /* 6F624 8007EE24 E0FF4324 */  addiu      $v1, $v0, -0x20
  .L8007EE28:
    /* 6F628 8007EE28 02006104 */  bgez       $v1, .L8007EE34
    /* 6F62C 8007EE2C 21106000 */   addu      $v0, $v1, $zero
    /* 6F630 8007EE30 0F006224 */  addiu      $v0, $v1, 0xF
  .L8007EE34:
    /* 6F634 8007EE34 03210200 */  sra        $a0, $v0, 4
    /* 6F638 8007EE38 00110400 */  sll        $v0, $a0, 4
    /* 6F63C 8007EE3C 23106200 */  subu       $v0, $v1, $v0
    /* 6F640 8007EE40 C0100200 */  sll        $v0, $v0, 3
    /* 6F644 8007EE44 0C0042A2 */  sb         $v0, 0xC($s2)
    /* 6F648 8007EE48 C0100400 */  sll        $v0, $a0, 3
    /* 6F64C 8007EE4C 0D0042A2 */  sb         $v0, 0xD($s2)
    /* 6F650 8007EE50 080051A6 */  sh         $s1, 0x8($s2)
    /* 6F654 8007EE54 0A0055A6 */  sh         $s5, 0xA($s2)
    /* 6F658 8007EE58 1C00A693 */  lbu        $a2, 0x1C($sp)
    /* 6F65C 8007EE5C 21284002 */  addu       $a1, $s2, $zero
    /* 6F660 8007EE60 040046A2 */  sb         $a2, 0x4($s2)
    /* 6F664 8007EE64 2000A693 */  lbu        $a2, 0x20($sp)
    /* 6F668 8007EE68 00000000 */  nop
    /* 6F66C 8007EE6C 050046A2 */  sb         $a2, 0x5($s2)
    /* 6F670 8007EE70 2400A693 */  lbu        $a2, 0x24($sp)
    /* 6F674 8007EE74 00000000 */  nop
    /* 6F678 8007EE78 060046A2 */  sb         $a2, 0x6($s2)
    /* 6F67C 8007EE7C 1000A48F */  lw         $a0, 0x10($sp)
    /* 6F680 8007EE80 F809020C */  jal        func_800827E0
    /* 6F684 8007EE84 10005226 */   addiu     $s2, $s2, 0x10
  .L8007EE88:
    /* 6F688 8007EE88 08003126 */  addiu      $s1, $s1, 0x8
  .L8007EE8C:
    /* 6F68C 8007EE8C 2A103702 */  slt        $v0, $s1, $s7
    /* 6F690 8007EE90 04004014 */  bnez       $v0, .L8007EEA4
    /* 6F694 8007EE94 00000000 */   nop
    /* 6F698 8007EE98 0200C016 */  bnez       $s6, .L8007EEA4
    /* 6F69C 8007EE9C 00000000 */   nop
  .L8007EEA0:
    /* 6F6A0 8007EEA0 01001424 */  addiu      $s4, $zero, 0x1
  .L8007EEA4:
    /* 6F6A4 8007EEA4 0D008012 */  beqz       $s4, .L8007EEDC
    /* 6F6A8 8007EEA8 00000000 */   nop
    /* 6F6AC 8007EEAC 1400A68F */  lw         $a2, 0x14($sp)
    /* 6F6B0 8007EEB0 00000000 */  nop
    /* 6F6B4 8007EEB4 2A10D100 */  slt        $v0, $a2, $s1
    /* 6F6B8 8007EEB8 02004010 */  beqz       $v0, .L8007EEC4
    /* 6F6BC 8007EEBC 00000000 */   nop
    /* 6F6C0 8007EEC0 1400B1AF */  sw         $s1, 0x14($sp)
  .L8007EEC4:
    /* 6F6C4 8007EEC4 0800B526 */  addiu      $s5, $s5, 0x8
    /* 6F6C8 8007EEC8 1800A68F */  lw         $a2, 0x18($sp)
    /* 6F6CC 8007EECC 08007186 */  lh         $s1, 0x8($s3)
    /* 6F6D0 8007EED0 2A10A602 */  slt        $v0, $s5, $a2
    /* 6F6D4 8007EED4 07004010 */  beqz       $v0, .L8007EEF4
    /* 6F6D8 8007EED8 00000000 */   nop
  .L8007EEDC:
    /* 6F6DC 8007EEDC 01001026 */  addiu      $s0, $s0, 0x1
    /* 6F6E0 8007EEE0 FFFFDE27 */  addiu      $fp, $fp, -0x1
  .L8007EEE4:
    /* 6F6E4 8007EEE4 00000282 */  lb         $v0, 0x0($s0)
    /* 6F6E8 8007EEE8 00000392 */  lbu        $v1, 0x0($s0)
    /* 6F6EC 8007EEEC 9AFF4014 */  bnez       $v0, .L8007ED58
    /* 6F6F0 8007EEF0 00000000 */   nop
  .L8007EEF4:
    /* 6F6F4 8007EEF4 07006292 */  lbu        $v0, 0x7($s3)
    /* 6F6F8 8007EEF8 00000000 */  nop
    /* 6F6FC 8007EEFC 0E004010 */  beqz       $v0, .L8007EF38
    /* 6F700 8007EF00 00000000 */   nop
    /* 6F704 8007EF04 1000A48F */  lw         $a0, 0x10($sp)
    /* 6F708 8007EF08 F809020C */  jal        func_800827E0
    /* 6F70C 8007EF0C 21286002 */   addu      $a1, $s3, $zero
    /* 6F710 8007EF10 0900C012 */  beqz       $s6, .L8007EF38
    /* 6F714 8007EF14 00000000 */   nop
    /* 6F718 8007EF18 08006296 */  lhu        $v0, 0x8($s3)
    /* 6F71C 8007EF1C 1400A68F */  lw         $a2, 0x14($sp)
    /* 6F720 8007EF20 0A006396 */  lhu        $v1, 0xA($s3)
    /* 6F724 8007EF24 2310C200 */  subu       $v0, $a2, $v0
    /* 6F728 8007EF28 F8FF6324 */  addiu      $v1, $v1, -0x8
    /* 6F72C 8007EF2C 2318A302 */  subu       $v1, $s5, $v1
    /* 6F730 8007EF30 0C0062A6 */  sh         $v0, 0xC($s3)
    /* 6F734 8007EF34 0E0063A6 */  sh         $v1, 0xE($s3)
  .L8007EF38:
    /* 6F738 8007EF38 1000A48F */  lw         $a0, 0x10($sp)
    /* 6F73C 8007EF3C 30FF010C */  jal        func_8007FCC0
    /* 6F740 8007EF40 00000000 */   nop
    /* 6F744 8007EF44 2400638E */  lw         $v1, 0x24($s3)
    /* 6F748 8007EF48 1000A28F */  lw         $v0, 0x10($sp)
    /* 6F74C 8007EF4C 280060AE */  sw         $zero, 0x28($s3)
    /* 6F750 8007EF50 000060A0 */  sb         $zero, 0x0($v1)
  .L8007EF54:
    /* 6F754 8007EF54 4C00BF8F */  lw         $ra, 0x4C($sp)
    /* 6F758 8007EF58 4800BE8F */  lw         $fp, 0x48($sp)
    /* 6F75C 8007EF5C 4400B78F */  lw         $s7, 0x44($sp)
    /* 6F760 8007EF60 4000B68F */  lw         $s6, 0x40($sp)
    /* 6F764 8007EF64 3C00B58F */  lw         $s5, 0x3C($sp)
    /* 6F768 8007EF68 3800B48F */  lw         $s4, 0x38($sp)
    /* 6F76C 8007EF6C 3400B38F */  lw         $s3, 0x34($sp)
    /* 6F770 8007EF70 3000B28F */  lw         $s2, 0x30($sp)
    /* 6F774 8007EF74 2C00B18F */  lw         $s1, 0x2C($sp)
    /* 6F778 8007EF78 2800B08F */  lw         $s0, 0x28($sp)
    /* 6F77C 8007EF7C 0800E003 */  jr         $ra
    /* 6F780 8007EF80 5000BD27 */   addiu     $sp, $sp, 0x50
endlabel func_8007EC68
