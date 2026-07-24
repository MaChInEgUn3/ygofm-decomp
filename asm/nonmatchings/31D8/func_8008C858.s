nonmatching func_8008C858, 0x118

glabel func_8008C858
    /* 7D058 8008C858 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 7D05C 8008C85C 2000B4AF */  sw         $s4, 0x20($sp)
    /* 7D060 8008C860 21A08000 */  addu       $s4, $a0, $zero
    /* 7D064 8008C864 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 7D068 8008C868 2198A000 */  addu       $s3, $a1, $zero
    /* 7D06C 8008C86C 2400B5AF */  sw         $s5, 0x24($sp)
    /* 7D070 8008C870 21A8C000 */  addu       $s5, $a2, $zero
    /* 7D074 8008C874 1800B2AF */  sw         $s2, 0x18($sp)
    /* 7D078 8008C878 2190E000 */  addu       $s2, $a3, $zero
    /* 7D07C 8008C87C 1400B1AF */  sw         $s1, 0x14($sp)
    /* 7D080 8008C880 1080113C */  lui        $s1, %hi(D_800FE348)
    /* 7D084 8008C884 48E33126 */  addiu      $s1, $s1, %lo(D_800FE348)
    /* 7D088 8008C888 2C00BFAF */  sw         $ra, 0x2C($sp)
    /* 7D08C 8008C88C 2800B6AF */  sw         $s6, 0x28($sp)
    /* 7D090 8008C890 1000B0AF */  sw         $s0, 0x10($sp)
    /* 7D094 8008C894 0000228E */  lw         $v0, 0x0($s1)
    /* 7D098 8008C898 4000B68F */  lw         $s6, 0x40($sp)
    /* 7D09C 8008C89C 04004018 */  blez       $v0, .L8008C8B0
    /* 7D0A0 8008C8A0 00000000 */   nop
    /* 7D0A4 8008C8A4 0180043C */  lui        $a0, %hi(D_8001261C)
    /* 7D0A8 8008C8A8 4F320208 */  j          .L8008C93C
    /* 7D0AC 8008C8AC 1C268424 */   addiu     $a0, $a0, %lo(D_8001261C)
  .L8008C8B0:
    /* 7D0B0 8008C8B0 1400228E */  lw         $v0, 0x14($s1)
    /* 7D0B4 8008C8B4 00000000 */  nop
    /* 7D0B8 8008C8B8 04004004 */  bltz       $v0, .L8008C8CC
    /* 7D0BC 8008C8BC 7F00C232 */   andi      $v0, $s6, 0x7F
    /* 7D0C0 8008C8C0 0180043C */  lui        $a0, %hi(D_80012574)
    /* 7D0C4 8008C8C4 4F320208 */  j          .L8008C93C
    /* 7D0C8 8008C8C8 74258424 */   addiu     $a0, $a0, %lo(D_80012574)
  .L8008C8CC:
    /* 7D0CC 8008C8CC 04004010 */  beqz       $v0, .L8008C8E0
    /* 7D0D0 8008C8D0 7F004232 */   andi      $v0, $s2, 0x7F
    /* 7D0D4 8008C8D4 0180043C */  lui        $a0, %hi(D_800125C0)
    /* 7D0D8 8008C8D8 4F320208 */  j          .L8008C93C
    /* 7D0DC 8008C8DC C0258424 */   addiu     $a0, $a0, %lo(D_800125C0)
  .L8008C8E0:
    /* 7D0E0 8008C8E0 14004014 */  bnez       $v0, .L8008C934
    /* 7D0E4 8008C8E4 21208002 */   addu      $a0, $s4, $zero
    /* 7D0E8 8008C8E8 24003026 */  addiu      $s0, $s1, 0x24
    /* 7D0EC 8008C8EC 1D34020C */  jal        func_8008D074
    /* 7D0F0 8008C8F0 21280002 */   addu      $a1, $s0, $zero
    /* 7D0F4 8008C8F4 21200002 */  addu       $a0, $s0, $zero
    /* 7D0F8 8008C8F8 7439020C */  jal        func_8008E5D0
    /* 7D0FC 8008C8FC 21286002 */   addu      $a1, $s3, $zero
    /* 7D100 8008C900 0980043C */  lui        $a0, %hi(func_8008C970)
    /* 7D104 8008C904 70C98424 */  addiu      $a0, $a0, %lo(func_8008C970)
    /* 7D108 8008C908 04000224 */  addiu      $v0, $zero, 0x4
    /* 7D10C 8008C90C 000022AE */  sw         $v0, 0x0($s1)
    /* 7D110 8008C910 040020AE */  sw         $zero, 0x4($s1)
    /* 7D114 8008C914 080020AE */  sw         $zero, 0x8($s1)
    /* 7D118 8008C918 180032AE */  sw         $s2, 0x18($s1)
    /* 7D11C 8008C91C 200035AE */  sw         $s5, 0x20($s1)
    /* 7D120 8008C920 1C0036AE */  sw         $s6, 0x1C($s1)
    /* 7D124 8008C924 3834020C */  jal        func_8008D0E0
    /* 7D128 8008C928 100034AE */   sw        $s4, 0x10($s1)
    /* 7D12C 8008C92C 52320208 */  j          .L8008C948
    /* 7D130 8008C930 01000224 */   addiu     $v0, $zero, 0x1
  .L8008C934:
    /* 7D134 8008C934 0180043C */  lui        $a0, %hi(D_800125EC)
    /* 7D138 8008C938 EC258424 */  addiu      $a0, $a0, %lo(D_800125EC)
  .L8008C93C:
    /* 7D13C 8008C93C 1C3A020C */  jal        func_8008E870
    /* 7D140 8008C940 00000000 */   nop
    /* 7D144 8008C944 21100000 */  addu       $v0, $zero, $zero
  .L8008C948:
    /* 7D148 8008C948 2C00BF8F */  lw         $ra, 0x2C($sp)
    /* 7D14C 8008C94C 2800B68F */  lw         $s6, 0x28($sp)
    /* 7D150 8008C950 2400B58F */  lw         $s5, 0x24($sp)
    /* 7D154 8008C954 2000B48F */  lw         $s4, 0x20($sp)
    /* 7D158 8008C958 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 7D15C 8008C95C 1800B28F */  lw         $s2, 0x18($sp)
    /* 7D160 8008C960 1400B18F */  lw         $s1, 0x14($sp)
    /* 7D164 8008C964 1000B08F */  lw         $s0, 0x10($sp)
    /* 7D168 8008C968 0800E003 */  jr         $ra
    /* 7D16C 8008C96C 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel func_8008C858
