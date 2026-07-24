nonmatching func_8008CE04, 0xFC

glabel func_8008CE04
    /* 7D604 8008CE04 B8FFBD27 */  addiu      $sp, $sp, -0x48
    /* 7D608 8008CE08 3000B0AF */  sw         $s0, 0x30($sp)
    /* 7D60C 8008CE0C 21808000 */  addu       $s0, $a0, $zero
    /* 7D610 8008CE10 3400B1AF */  sw         $s1, 0x34($sp)
    /* 7D614 8008CE14 2188A000 */  addu       $s1, $a1, $zero
    /* 7D618 8008CE18 3800B2AF */  sw         $s2, 0x38($sp)
    /* 7D61C 8008CE1C 1080123C */  lui        $s2, %hi(D_800FE348)
    /* 7D620 8008CE20 48E35226 */  addiu      $s2, $s2, %lo(D_800FE348)
    /* 7D624 8008CE24 4000BFAF */  sw         $ra, 0x40($sp)
    /* 7D628 8008CE28 3C00B3AF */  sw         $s3, 0x3C($sp)
    /* 7D62C 8008CE2C 0000428E */  lw         $v0, 0x0($s2)
    /* 7D630 8008CE30 00000000 */  nop
    /* 7D634 8008CE34 0C004010 */  beqz       $v0, .L8008CE68
    /* 7D638 8008CE38 2198C000 */   addu      $s3, $a2, $zero
    /* 7D63C 8008CE3C 0180043C */  lui        $a0, %hi(D_8001261C)
    /* 7D640 8008CE40 1C3A020C */  jal        func_8008E870
    /* 7D644 8008CE44 1C268424 */   addiu     $a0, $a0, %lo(D_8001261C)
    /* 7D648 8008CE48 B9330208 */  j          .L8008CEE4
    /* 7D64C 8008CE4C FFFF0224 */   addiu     $v0, $zero, -0x1
  .L8008CE50:
    /* 7D650 8008CE50 B9330208 */  j          .L8008CEE4
    /* 7D654 8008CE54 07000224 */   addiu     $v0, $zero, 0x7
  .L8008CE58:
    /* 7D658 8008CE58 B9330208 */  j          .L8008CEE4
    /* 7D65C 8008CE5C 04000224 */   addiu     $v0, $zero, 0x4
  .L8008CE60:
    /* 7D660 8008CE60 B9330208 */  j          .L8008CEE4
    /* 7D664 8008CE64 06000224 */   addiu     $v0, $zero, 0x6
  .L8008CE68:
    /* 7D668 8008CE68 21200002 */  addu       $a0, $s0, $zero
    /* 7D66C 8008CE6C 1D34020C */  jal        func_8008D074
    /* 7D670 8008CE70 1000A527 */   addiu     $a1, $sp, 0x10
    /* 7D674 8008CE74 1000A427 */  addiu      $a0, $sp, 0x10
    /* 7D678 8008CE78 7439020C */  jal        func_8008E5D0
    /* 7D67C 8008CE7C 21282002 */   addu      $a1, $s1, $zero
    /* 7D680 8008CE80 01000224 */  addiu      $v0, $zero, 0x1
    /* 7D684 8008CE84 0C00438E */  lw         $v1, 0xC($s2)
    /* 7D688 8008CE88 04100202 */  sllv       $v0, $v0, $s0
    /* 7D68C 8008CE8C 25186200 */  or         $v1, $v1, $v0
    /* 7D690 8008CE90 0C0043AE */  sw         $v1, 0xC($s2)
    /* 7D694 8008CE94 21200002 */  addu       $a0, $s0, $zero
    /* 7D698 8008CE98 21282002 */  addu       $a1, $s1, $zero
    /* 7D69C 8008CE9C 1837020C */  jal        func_8008DC60
    /* 7D6A0 8008CEA0 21306002 */   addu      $a2, $s3, $zero
    /* 7D6A4 8008CEA4 21204000 */  addu       $a0, $v0, $zero
    /* 7D6A8 8008CEA8 0D008010 */  beqz       $a0, .L8008CEE0
    /* 7D6AC 8008CEAC FFFF0224 */   addiu     $v0, $zero, -0x1
    /* 7D6B0 8008CEB0 E7FF8210 */  beq        $a0, $v0, .L8008CE50
    /* 7D6B4 8008CEB4 FEFF0224 */   addiu     $v0, $zero, -0x2
    /* 7D6B8 8008CEB8 E7FF8210 */  beq        $a0, $v0, .L8008CE58
    /* 7D6BC 8008CEBC FDFF0224 */   addiu     $v0, $zero, -0x3
    /* 7D6C0 8008CEC0 E7FF8210 */  beq        $a0, $v0, .L8008CE60
    /* 7D6C4 8008CEC4 04000224 */   addiu     $v0, $zero, 0x4
    /* 7D6C8 8008CEC8 06008210 */  beq        $a0, $v0, .L8008CEE4
    /* 7D6CC 8008CECC 02000224 */   addiu     $v0, $zero, 0x2
    /* 7D6D0 8008CED0 DD33020C */  jal        func_8008CF74
    /* 7D6D4 8008CED4 00000000 */   nop
    /* 7D6D8 8008CED8 B9330208 */  j          .L8008CEE4
    /* 7D6DC 8008CEDC 00000000 */   nop
  .L8008CEE0:
    /* 7D6E0 8008CEE0 21100000 */  addu       $v0, $zero, $zero
  .L8008CEE4:
    /* 7D6E4 8008CEE4 4000BF8F */  lw         $ra, 0x40($sp)
    /* 7D6E8 8008CEE8 3C00B38F */  lw         $s3, 0x3C($sp)
    /* 7D6EC 8008CEEC 3800B28F */  lw         $s2, 0x38($sp)
    /* 7D6F0 8008CEF0 3400B18F */  lw         $s1, 0x34($sp)
    /* 7D6F4 8008CEF4 3000B08F */  lw         $s0, 0x30($sp)
    /* 7D6F8 8008CEF8 0800E003 */  jr         $ra
    /* 7D6FC 8008CEFC 4800BD27 */   addiu     $sp, $sp, 0x48
endlabel func_8008CE04
