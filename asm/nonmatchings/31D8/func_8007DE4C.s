nonmatching func_8007DE4C, 0x2DC

glabel func_8007DE4C
    /* 6E64C 8007DE4C C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* 6E650 8007DE50 2800B2AF */  sw         $s2, 0x28($sp)
    /* 6E654 8007DE54 2190A000 */  addu       $s2, $a1, $zero
    /* 6E658 8007DE58 2000B0AF */  sw         $s0, 0x20($sp)
    /* 6E65C 8007DE5C 2400B1AF */  sw         $s1, 0x24($sp)
    /* 6E660 8007DE60 0980113C */  lui        $s1, %hi(D_80093A18)
    /* 6E664 8007DE64 183A3126 */  addiu      $s1, $s1, %lo(D_80093A18)
    /* 6E668 8007DE68 3000BFAF */  sw         $ra, 0x30($sp)
    /* 6E66C 8007DE6C 2C00B3AF */  sw         $s3, 0x2C($sp)
    /* 6E670 8007DE70 0000238E */  lw         $v1, 0x0($s1)
    /* 6E674 8007DE74 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 6E678 8007DE78 06006214 */  bne        $v1, $v0, .L8007DE94
    /* 6E67C 8007DE7C 21808000 */   addu      $s0, $a0, $zero
    /* 6E680 8007DE80 C9EF010C */  jal        func_8007BF24
    /* 6E684 8007DE84 00000000 */   nop
    /* 6E688 8007DE88 C4F9010C */  jal        func_8007E710
    /* 6E68C 8007DE8C 21204000 */   addu      $a0, $v0, $zero
    /* 6E690 8007DE90 000022AE */  sw         $v0, 0x0($s1)
  .L8007DE94:
    /* 6E694 8007DE94 FF001032 */  andi       $s0, $s0, 0xFF
    /* 6E698 8007DE98 01001324 */  addiu      $s3, $zero, 0x1
    /* 6E69C 8007DE9C 39001316 */  bne        $s0, $s3, .L8007DF84
    /* 6E6A0 8007DEA0 04000224 */   addiu     $v0, $zero, 0x4
    /* 6E6A4 8007DEA4 C5EF010C */  jal        func_8007BF14
    /* 6E6A8 8007DEA8 00000000 */   nop
    /* 6E6AC 8007DEAC 20004230 */  andi       $v0, $v0, 0x20
    /* 6E6B0 8007DEB0 1D004010 */  beqz       $v0, .L8007DF28
    /* 6E6B4 8007DEB4 00000000 */   nop
    /* 6E6B8 8007DEB8 28FA010C */  jal        func_8007E8A0
    /* 6E6BC 8007DEBC 21200000 */   addu      $a0, $zero, $zero
    /* 6E6C0 8007DEC0 1000A427 */  addiu      $a0, $sp, 0x10
    /* 6E6C4 8007DEC4 03000524 */  addiu      $a1, $zero, 0x3
    /* 6E6C8 8007DEC8 F4F8010C */  jal        func_8007E3D0
    /* 6E6CC 8007DECC 21804000 */   addu      $s0, $v0, $zero
    /* 6E6D0 8007DED0 28FA010C */  jal        func_8007E8A0
    /* 6E6D4 8007DED4 21200002 */   addu      $a0, $s0, $zero
    /* 6E6D8 8007DED8 C4F9010C */  jal        func_8007E710
    /* 6E6DC 8007DEDC 1000A427 */   addiu     $a0, $sp, 0x10
    /* 6E6E0 8007DEE0 0000238E */  lw         $v1, 0x0($s1)
    /* 6E6E4 8007DEE4 21804000 */  addu       $s0, $v0, $zero
    /* 6E6E8 8007DEE8 57000316 */  bne        $s0, $v1, .L8007E048
    /* 6E6EC 8007DEEC 00000000 */   nop
    /* 6E6F0 8007DEF0 0800238E */  lw         $v1, 0x8($s1)
    /* 6E6F4 8007DEF4 00000000 */  nop
    /* 6E6F8 8007DEF8 1B006010 */  beqz       $v1, .L8007DF68
    /* 6E6FC 8007DEFC 00000000 */   nop
    /* 6E700 8007DF00 0400228E */  lw         $v0, 0x4($s1)
    /* 6E704 8007DF04 00000000 */  nop
    /* 6E708 8007DF08 2A105000 */  slt        $v0, $v0, $s0
    /* 6E70C 8007DF0C 16004010 */  beqz       $v0, .L8007DF68
    /* 6E710 8007DF10 01000424 */   addiu     $a0, $zero, 0x1
    /* 6E714 8007DF14 21284002 */  addu       $a1, $s2, $zero
    /* 6E718 8007DF18 09F86000 */  jalr       $v1
    /* 6E71C 8007DF1C 1000A627 */   addiu     $a2, $sp, 0x10
    /* 6E720 8007DF20 DAF70108 */  j          .L8007DF68
    /* 6E724 8007DF24 040030AE */   sw        $s0, 0x4($s1)
  .L8007DF28:
    /* 6E728 8007DF28 0800278E */  lw         $a3, 0x8($s1)
    /* 6E72C 8007DF2C 00000000 */  nop
    /* 6E730 8007DF30 0D00E010 */  beqz       $a3, .L8007DF68
    /* 6E734 8007DF34 00000000 */   nop
    /* 6E738 8007DF38 0000238E */  lw         $v1, 0x0($s1)
    /* 6E73C 8007DF3C 0400228E */  lw         $v0, 0x4($s1)
    /* 6E740 8007DF40 00000000 */  nop
    /* 6E744 8007DF44 2A104300 */  slt        $v0, $v0, $v1
    /* 6E748 8007DF48 07004010 */  beqz       $v0, .L8007DF68
    /* 6E74C 8007DF4C 01000424 */   addiu     $a0, $zero, 0x1
    /* 6E750 8007DF50 21284002 */  addu       $a1, $s2, $zero
    /* 6E754 8007DF54 09F8E000 */  jalr       $a3
    /* 6E758 8007DF58 1000A627 */   addiu     $a2, $sp, 0x10
    /* 6E75C 8007DF5C 0000228E */  lw         $v0, 0x0($s1)
    /* 6E760 8007DF60 00000000 */  nop
    /* 6E764 8007DF64 040022AE */  sw         $v0, 0x4($s1)
  .L8007DF68:
    /* 6E768 8007DF68 0980033C */  lui        $v1, %hi(D_80093A18)
    /* 6E76C 8007DF6C 183A6324 */  addiu      $v1, $v1, %lo(D_80093A18)
    /* 6E770 8007DF70 0000628C */  lw         $v0, 0x0($v1)
    /* 6E774 8007DF74 00000000 */  nop
    /* 6E778 8007DF78 01004224 */  addiu      $v0, $v0, 0x1
    /* 6E77C 8007DF7C 13F80108 */  j          .L8007E04C
    /* 6E780 8007DF80 000062AC */   sw        $v0, 0x0($v1)
  .L8007DF84:
    /* 6E784 8007DF84 0A000216 */  bne        $s0, $v0, .L8007DFB0
    /* 6E788 8007DF88 00000000 */   nop
    /* 6E78C 8007DF8C 0800228E */  lw         $v0, 0x8($s1)
    /* 6E790 8007DF90 00000000 */  nop
    /* 6E794 8007DF94 2D004010 */  beqz       $v0, .L8007E04C
    /* 6E798 8007DF98 04000424 */   addiu     $a0, $zero, 0x4
    /* 6E79C 8007DF9C 21284002 */  addu       $a1, $s2, $zero
    /* 6E7A0 8007DFA0 09F84000 */  jalr       $v0
    /* 6E7A4 8007DFA4 1000A627 */   addiu     $a2, $sp, 0x10
    /* 6E7A8 8007DFA8 13F80108 */  j          .L8007E04C
    /* 6E7AC 8007DFAC 00000000 */   nop
  .L8007DFB0:
    /* 6E7B0 8007DFB0 00004292 */  lbu        $v0, 0x0($s2)
    /* 6E7B4 8007DFB4 00000000 */  nop
    /* 6E7B8 8007DFB8 10004230 */  andi       $v0, $v0, 0x10
    /* 6E7BC 8007DFBC 19004010 */  beqz       $v0, .L8007E024
    /* 6E7C0 8007DFC0 00000000 */   nop
    /* 6E7C4 8007DFC4 1C00228E */  lw         $v0, 0x1C($s1)
    /* 6E7C8 8007DFC8 00000000 */  nop
    /* 6E7CC 8007DFCC 05005314 */  bne        $v0, $s3, .L8007DFE4
    /* 6E7D0 8007DFD0 00000000 */   nop
    /* 6E7D4 8007DFD4 18FA010C */  jal        func_8007E860
    /* 6E7D8 8007DFD8 21200000 */   addu      $a0, $zero, $zero
    /* 6E7DC 8007DFDC 43F80108 */  j          .L8007E10C
    /* 6E7E0 8007DFE0 00000000 */   nop
  .L8007DFE4:
    /* 6E7E4 8007DFE4 1400248E */  lw         $a0, 0x14($s1)
    /* 6E7E8 8007DFE8 18FA010C */  jal        func_8007E860
    /* 6E7EC 8007DFEC 00000000 */   nop
    /* 6E7F0 8007DFF0 1800248E */  lw         $a0, 0x18($s1)
    /* 6E7F4 8007DFF4 20FA010C */  jal        func_8007E880
    /* 6E7F8 8007DFF8 00000000 */   nop
    /* 6E7FC 8007DFFC 0800228E */  lw         $v0, 0x8($s1)
    /* 6E800 8007E000 00000000 */  nop
    /* 6E804 8007E004 41004010 */  beqz       $v0, .L8007E10C
    /* 6E808 8007E008 200020AE */   sw        $zero, 0x20($s1)
    /* 6E80C 8007E00C 21200002 */  addu       $a0, $s0, $zero
    /* 6E810 8007E010 21284002 */  addu       $a1, $s2, $zero
    /* 6E814 8007E014 09F84000 */  jalr       $v0
    /* 6E818 8007E018 1000A627 */   addiu     $a2, $sp, 0x10
    /* 6E81C 8007E01C 43F80108 */  j          .L8007E10C
    /* 6E820 8007E020 00000000 */   nop
  .L8007E024:
    /* 6E824 8007E024 B0EE010C */  jal        func_8007BAC0
    /* 6E828 8007E028 00000000 */   nop
    /* 6E82C 8007E02C 07004014 */  bnez       $v0, .L8007E04C
    /* 6E830 8007E030 00000000 */   nop
    /* 6E834 8007E034 00004292 */  lbu        $v0, 0x0($s2)
    /* 6E838 8007E038 00000000 */  nop
    /* 6E83C 8007E03C A0004230 */  andi       $v0, $v0, 0xA0
    /* 6E840 8007E040 02004014 */  bnez       $v0, .L8007E04C
    /* 6E844 8007E044 00000000 */   nop
  .L8007E048:
    /* 6E848 8007E048 0C0033AE */  sw         $s3, 0xC($s1)
  .L8007E04C:
    /* 6E84C 8007E04C 0980103C */  lui        $s0, %hi(D_80093A24)
    /* 6E850 8007E050 243A1026 */  addiu      $s0, $s0, %lo(D_80093A24)
    /* 6E854 8007E054 0000048E */  lw         $a0, 0x0($s0)
    /* 6E858 8007E058 01000224 */  addiu      $v0, $zero, 0x1
    /* 6E85C 8007E05C 2B008214 */  bne        $a0, $v0, .L8007E10C
    /* 6E860 8007E060 00000000 */   nop
    /* 6E864 8007E064 0400038E */  lw         $v1, 0x4($s0)
    /* 6E868 8007E068 00000000 */  nop
    /* 6E86C 8007E06C 0300601C */  bgtz       $v1, .L8007E07C
    /* 6E870 8007E070 FFFF0224 */   addiu     $v0, $zero, -0x1
    /* 6E874 8007E074 09006214 */  bne        $v1, $v0, .L8007E09C
    /* 6E878 8007E078 00000000 */   nop
  .L8007E07C:
    /* 6E87C 8007E07C 78F8010C */  jal        func_8007E1E0
    /* 6E880 8007E080 00000000 */   nop
    /* 6E884 8007E084 0400028E */  lw         $v0, 0x4($s0)
    /* 6E888 8007E088 00000000 */  nop
    /* 6E88C 8007E08C 1D004018 */  blez       $v0, .L8007E104
    /* 6E890 8007E090 FFFF4224 */   addiu     $v0, $v0, -0x1
    /* 6E894 8007E094 41F80108 */  j          .L8007E104
    /* 6E898 8007E098 040002AE */   sw        $v0, 0x4($s0)
  .L8007E09C:
    /* 6E89C 8007E09C 0980023C */  lui        $v0, %hi(D_80093A38)
    /* 6E8A0 8007E0A0 383A428C */  lw         $v0, %lo(D_80093A38)($v0)
    /* 6E8A4 8007E0A4 00000000 */  nop
    /* 6E8A8 8007E0A8 0E004414 */  bne        $v0, $a0, .L8007E0E4
    /* 6E8AC 8007E0AC 00000000 */   nop
    /* 6E8B0 8007E0B0 0980043C */  lui        $a0, %hi(D_80093A2C)
    /* 6E8B4 8007E0B4 2C3A848C */  lw         $a0, %lo(D_80093A2C)($a0)
    /* 6E8B8 8007E0B8 18FA010C */  jal        func_8007E860
    /* 6E8BC 8007E0BC 00000000 */   nop
    /* 6E8C0 8007E0C0 0980043C */  lui        $a0, %hi(D_80093A30)
    /* 6E8C4 8007E0C4 303A848C */  lw         $a0, %lo(D_80093A30)($a0)
    /* 6E8C8 8007E0C8 20FA010C */  jal        func_8007E880
    /* 6E8CC 8007E0CC 00000000 */   nop
    /* 6E8D0 8007E0D0 09000424 */  addiu      $a0, $zero, 0x9
    /* 6E8D4 8007E0D4 21280000 */  addu       $a1, $zero, $zero
    /* 6E8D8 8007E0D8 21300000 */  addu       $a2, $zero, $zero
    /* 6E8DC 8007E0DC 7DEC010C */  jal        func_8007B1F4
    /* 6E8E0 8007E0E0 FFFF0724 */   addiu     $a3, $zero, -0x1
  .L8007E0E4:
    /* 6E8E4 8007E0E4 FCFF028E */  lw         $v0, -0x4($s0)
    /* 6E8E8 8007E0E8 0980013C */  lui        $at, %hi(D_80093A38)
    /* 6E8EC 8007E0EC 383A20AC */  sw         $zero, %lo(D_80093A38)($at)
    /* 6E8F0 8007E0F0 04004010 */  beqz       $v0, .L8007E104
    /* 6E8F4 8007E0F4 05000424 */   addiu     $a0, $zero, 0x5
    /* 6E8F8 8007E0F8 21284002 */  addu       $a1, $s2, $zero
    /* 6E8FC 8007E0FC 09F84000 */  jalr       $v0
    /* 6E900 8007E100 1000A627 */   addiu     $a2, $sp, 0x10
  .L8007E104:
    /* 6E904 8007E104 0980013C */  lui        $at, %hi(D_80093A24)
    /* 6E908 8007E108 243A20AC */  sw         $zero, %lo(D_80093A24)($at)
  .L8007E10C:
    /* 6E90C 8007E10C 3000BF8F */  lw         $ra, 0x30($sp)
    /* 6E910 8007E110 2C00B38F */  lw         $s3, 0x2C($sp)
    /* 6E914 8007E114 2800B28F */  lw         $s2, 0x28($sp)
    /* 6E918 8007E118 2400B18F */  lw         $s1, 0x24($sp)
    /* 6E91C 8007E11C 2000B08F */  lw         $s0, 0x20($sp)
    /* 6E920 8007E120 0800E003 */  jr         $ra
    /* 6E924 8007E124 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel func_8007DE4C
