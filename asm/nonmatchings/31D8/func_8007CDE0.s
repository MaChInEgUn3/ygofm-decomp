nonmatching func_8007CDE0, 0x130

glabel func_8007CDE0
    /* 6D5E0 8007CDE0 C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* 6D5E4 8007CDE4 2800B2AF */  sw         $s2, 0x28($sp)
    /* 6D5E8 8007CDE8 21908000 */  addu       $s2, $a0, $zero
    /* 6D5EC 8007CDEC 3000B4AF */  sw         $s4, 0x30($sp)
    /* 6D5F0 8007CDF0 21A0A000 */  addu       $s4, $a1, $zero
    /* 6D5F4 8007CDF4 2C00B3AF */  sw         $s3, 0x2C($sp)
    /* 6D5F8 8007CDF8 2198C000 */  addu       $s3, $a2, $zero
    /* 6D5FC 8007CDFC 2400B1AF */  sw         $s1, 0x24($sp)
    /* 6D600 8007CE00 2000B0AF */  sw         $s0, 0x20($sp)
    /* 6D604 8007CE04 0980103C */  lui        $s0, %hi(D_800939F8)
    /* 6D608 8007CE08 F8391026 */  addiu      $s0, $s0, %lo(D_800939F8)
    /* 6D60C 8007CE0C 3400BFAF */  sw         $ra, 0x34($sp)
    /* 6D610 8007CE10 0000038E */  lw         $v1, 0x0($s0)
    /* 6D614 8007CE14 01000224 */  addiu      $v0, $zero, 0x1
    /* 6D618 8007CE18 05006210 */  beq        $v1, $v0, .L8007CE30
    /* 6D61C 8007CE1C 2188E000 */   addu      $s1, $a3, $zero
    /* 6D620 8007CE20 A2F8010C */  jal        func_8007E288
    /* 6D624 8007CE24 00000000 */   nop
    /* 6D628 8007CE28 03004010 */  beqz       $v0, .L8007CE38
    /* 6D62C 8007CE2C 00020224 */   addiu     $v0, $zero, 0x200
  .L8007CE30:
    /* 6D630 8007CE30 BCF30108 */  j          .L8007CEF0
    /* 6D634 8007CE34 21100000 */   addu      $v0, $zero, $zero
  .L8007CE38:
    /* 6D638 8007CE38 E0FF02AE */  sw         $v0, -0x20($s0)
    /* 6D63C 8007CE3C E4FF13AE */  sw         $s3, -0x1C($s0)
    /* 6D640 8007CE40 0A004016 */  bnez       $s2, .L8007CE6C
    /* 6D644 8007CE44 E8FF14AE */   sw        $s4, -0x18($s0)
    /* 6D648 8007CE48 E4F9010C */  jal        func_8007E790
    /* 6D64C 8007CE4C 21200000 */   addu      $a0, $zero, $zero
    /* 6D650 8007CE50 03004388 */  lwl        $v1, 0x3($v0)
    /* 6D654 8007CE54 00004398 */  lwr        $v1, 0x0($v0)
    /* 6D658 8007CE58 00000000 */  nop
    /* 6D65C 8007CE5C 1B00A3AB */  swl        $v1, 0x1B($sp)
    /* 6D660 8007CE60 1800A3BB */  swr        $v1, 0x18($sp)
    /* 6D664 8007CE64 A1F30108 */  j          .L8007CE84
    /* 6D668 8007CE68 20003136 */   ori       $s1, $s1, 0x20
  .L8007CE6C:
    /* 6D66C 8007CE6C 0300428A */  lwl        $v0, 0x3($s2)
    /* 6D670 8007CE70 0000429A */  lwr        $v0, 0x0($s2)
    /* 6D674 8007CE74 00000000 */  nop
    /* 6D678 8007CE78 1B00A2AB */  swl        $v0, 0x1B($sp)
    /* 6D67C 8007CE7C 1800A2BB */  swr        $v0, 0x18($sp)
    /* 6D680 8007CE80 20003136 */  ori        $s1, $s1, 0x20
  .L8007CE84:
    /* 6D684 8007CE84 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 6D688 8007CE88 1000A2AF */  sw         $v0, 0x10($sp)
    /* 6D68C 8007CE8C FF002432 */  andi       $a0, $s1, 0xFF
    /* 6D690 8007CE90 1800A527 */  addiu      $a1, $sp, 0x18
    /* 6D694 8007CE94 0880073C */  lui        $a3, %hi(func_8007CF10)
    /* 6D698 8007CE98 10CFE724 */  addiu      $a3, $a3, %lo(func_8007CF10)
    /* 6D69C 8007CE9C 1AED010C */  jal        func_8007B468
    /* 6D6A0 8007CEA0 06000624 */   addiu     $a2, $zero, 0x6
    /* 6D6A4 8007CEA4 21884000 */  addu       $s1, $v0, $zero
    /* 6D6A8 8007CEA8 11002012 */  beqz       $s1, .L8007CEF0
    /* 6D6AC 8007CEAC 21100000 */   addu      $v0, $zero, $zero
    /* 6D6B0 8007CEB0 5CD0010C */  jal        func_80074170
    /* 6D6B4 8007CEB4 FFFF0424 */   addiu     $a0, $zero, -0x1
    /* 6D6B8 8007CEB8 0980103C */  lui        $s0, %hi(D_800939F0)
    /* 6D6BC 8007CEBC F0391026 */  addiu      $s0, $s0, %lo(D_800939F0)
    /* 6D6C0 8007CEC0 F4FF038E */  lw         $v1, -0xC($s0)
    /* 6D6C4 8007CEC4 00000000 */  nop
    /* 6D6C8 8007CEC8 01006330 */  andi       $v1, $v1, 0x1
    /* 6D6CC 8007CECC 05006010 */  beqz       $v1, .L8007CEE4
    /* 6D6D0 8007CED0 000002AE */   sw        $v0, 0x0($s0)
    /* 6D6D4 8007CED4 0880043C */  lui        $a0, %hi(func_8007D0BC)
    /* 6D6D8 8007CED8 28FA010C */  jal        func_8007E8A0
    /* 6D6DC 8007CEDC BCD08424 */   addiu     $a0, $a0, %lo(func_8007D0BC)
    /* 6D6E0 8007CEE0 FCFF02AE */  sw         $v0, -0x4($s0)
  .L8007CEE4:
    /* 6D6E4 8007CEE4 01000224 */  addiu      $v0, $zero, 0x1
    /* 6D6E8 8007CEE8 080002AE */  sw         $v0, 0x8($s0)
    /* 6D6EC 8007CEEC 21102002 */  addu       $v0, $s1, $zero
  .L8007CEF0:
    /* 6D6F0 8007CEF0 3400BF8F */  lw         $ra, 0x34($sp)
    /* 6D6F4 8007CEF4 3000B48F */  lw         $s4, 0x30($sp)
    /* 6D6F8 8007CEF8 2C00B38F */  lw         $s3, 0x2C($sp)
    /* 6D6FC 8007CEFC 2800B28F */  lw         $s2, 0x28($sp)
    /* 6D700 8007CF00 2400B18F */  lw         $s1, 0x24($sp)
    /* 6D704 8007CF04 2000B08F */  lw         $s0, 0x20($sp)
    /* 6D708 8007CF08 0800E003 */  jr         $ra
    /* 6D70C 8007CF0C 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel func_8007CDE0
