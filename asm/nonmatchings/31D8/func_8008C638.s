nonmatching func_8008C638, 0x118

glabel func_8008C638
    /* 7CE38 8008C638 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 7CE3C 8008C63C 2000B4AF */  sw         $s4, 0x20($sp)
    /* 7CE40 8008C640 21A08000 */  addu       $s4, $a0, $zero
    /* 7CE44 8008C644 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 7CE48 8008C648 2198A000 */  addu       $s3, $a1, $zero
    /* 7CE4C 8008C64C 2400B5AF */  sw         $s5, 0x24($sp)
    /* 7CE50 8008C650 21A8C000 */  addu       $s5, $a2, $zero
    /* 7CE54 8008C654 1800B2AF */  sw         $s2, 0x18($sp)
    /* 7CE58 8008C658 2190E000 */  addu       $s2, $a3, $zero
    /* 7CE5C 8008C65C 1400B1AF */  sw         $s1, 0x14($sp)
    /* 7CE60 8008C660 1080113C */  lui        $s1, %hi(D_800FE348)
    /* 7CE64 8008C664 48E33126 */  addiu      $s1, $s1, %lo(D_800FE348)
    /* 7CE68 8008C668 2C00BFAF */  sw         $ra, 0x2C($sp)
    /* 7CE6C 8008C66C 2800B6AF */  sw         $s6, 0x28($sp)
    /* 7CE70 8008C670 1000B0AF */  sw         $s0, 0x10($sp)
    /* 7CE74 8008C674 0000228E */  lw         $v0, 0x0($s1)
    /* 7CE78 8008C678 4000B68F */  lw         $s6, 0x40($sp)
    /* 7CE7C 8008C67C 04004018 */  blez       $v0, .L8008C690
    /* 7CE80 8008C680 00000000 */   nop
    /* 7CE84 8008C684 0180043C */  lui        $a0, %hi(D_8001261C)
    /* 7CE88 8008C688 C7310208 */  j          .L8008C71C
    /* 7CE8C 8008C68C 1C268424 */   addiu     $a0, $a0, %lo(D_8001261C)
  .L8008C690:
    /* 7CE90 8008C690 1400228E */  lw         $v0, 0x14($s1)
    /* 7CE94 8008C694 00000000 */  nop
    /* 7CE98 8008C698 04004004 */  bltz       $v0, .L8008C6AC
    /* 7CE9C 8008C69C 7F00C232 */   andi      $v0, $s6, 0x7F
    /* 7CEA0 8008C6A0 0180043C */  lui        $a0, %hi(D_80012574)
    /* 7CEA4 8008C6A4 C7310208 */  j          .L8008C71C
    /* 7CEA8 8008C6A8 74258424 */   addiu     $a0, $a0, %lo(D_80012574)
  .L8008C6AC:
    /* 7CEAC 8008C6AC 04004010 */  beqz       $v0, .L8008C6C0
    /* 7CEB0 8008C6B0 7F004232 */   andi      $v0, $s2, 0x7F
    /* 7CEB4 8008C6B4 0180043C */  lui        $a0, %hi(D_800125C0)
    /* 7CEB8 8008C6B8 C7310208 */  j          .L8008C71C
    /* 7CEBC 8008C6BC C0258424 */   addiu     $a0, $a0, %lo(D_800125C0)
  .L8008C6C0:
    /* 7CEC0 8008C6C0 14004014 */  bnez       $v0, .L8008C714
    /* 7CEC4 8008C6C4 21208002 */   addu      $a0, $s4, $zero
    /* 7CEC8 8008C6C8 24003026 */  addiu      $s0, $s1, 0x24
    /* 7CECC 8008C6CC 1D34020C */  jal        func_8008D074
    /* 7CED0 8008C6D0 21280002 */   addu      $a1, $s0, $zero
    /* 7CED4 8008C6D4 21200002 */  addu       $a0, $s0, $zero
    /* 7CED8 8008C6D8 7439020C */  jal        func_8008E5D0
    /* 7CEDC 8008C6DC 21286002 */   addu      $a1, $s3, $zero
    /* 7CEE0 8008C6E0 0980043C */  lui        $a0, %hi(func_8008C750)
    /* 7CEE4 8008C6E4 50C78424 */  addiu      $a0, $a0, %lo(func_8008C750)
    /* 7CEE8 8008C6E8 03000224 */  addiu      $v0, $zero, 0x3
    /* 7CEEC 8008C6EC 000022AE */  sw         $v0, 0x0($s1)
    /* 7CEF0 8008C6F0 040020AE */  sw         $zero, 0x4($s1)
    /* 7CEF4 8008C6F4 080020AE */  sw         $zero, 0x8($s1)
    /* 7CEF8 8008C6F8 180032AE */  sw         $s2, 0x18($s1)
    /* 7CEFC 8008C6FC 200035AE */  sw         $s5, 0x20($s1)
    /* 7CF00 8008C700 1C0036AE */  sw         $s6, 0x1C($s1)
    /* 7CF04 8008C704 3834020C */  jal        func_8008D0E0
    /* 7CF08 8008C708 100034AE */   sw        $s4, 0x10($s1)
    /* 7CF0C 8008C70C CA310208 */  j          .L8008C728
    /* 7CF10 8008C710 01000224 */   addiu     $v0, $zero, 0x1
  .L8008C714:
    /* 7CF14 8008C714 0180043C */  lui        $a0, %hi(D_800125EC)
    /* 7CF18 8008C718 EC258424 */  addiu      $a0, $a0, %lo(D_800125EC)
  .L8008C71C:
    /* 7CF1C 8008C71C 1C3A020C */  jal        func_8008E870
    /* 7CF20 8008C720 00000000 */   nop
    /* 7CF24 8008C724 21100000 */  addu       $v0, $zero, $zero
  .L8008C728:
    /* 7CF28 8008C728 2C00BF8F */  lw         $ra, 0x2C($sp)
    /* 7CF2C 8008C72C 2800B68F */  lw         $s6, 0x28($sp)
    /* 7CF30 8008C730 2400B58F */  lw         $s5, 0x24($sp)
    /* 7CF34 8008C734 2000B48F */  lw         $s4, 0x20($sp)
    /* 7CF38 8008C738 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 7CF3C 8008C73C 1800B28F */  lw         $s2, 0x18($sp)
    /* 7CF40 8008C740 1400B18F */  lw         $s1, 0x14($sp)
    /* 7CF44 8008C744 1000B08F */  lw         $s0, 0x10($sp)
    /* 7CF48 8008C748 0800E003 */  jr         $ra
    /* 7CF4C 8008C74C 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel func_8008C638
