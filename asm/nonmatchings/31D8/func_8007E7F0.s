nonmatching func_8007E7F0, 0x68

glabel func_8007E7F0
    /* 6EFF0 8007E7F0 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 6EFF4 8007E7F4 1400B1AF */  sw         $s1, 0x14($sp)
    /* 6EFF8 8007E7F8 2188C000 */  addu       $s1, $a2, $zero
    /* 6EFFC 8007E7FC FF008430 */  andi       $a0, $a0, 0xFF
    /* 6F000 8007E800 21300000 */  addu       $a2, $zero, $zero
    /* 6F004 8007E804 21380000 */  addu       $a3, $zero, $zero
    /* 6F008 8007E808 1800BFAF */  sw         $ra, 0x18($sp)
    /* 6F00C 8007E80C 7DEC010C */  jal        func_8007B1F4
    /* 6F010 8007E810 1000B0AF */   sw        $s0, 0x10($sp)
    /* 6F014 8007E814 21804000 */  addu       $s0, $v0, $zero
    /* 6F018 8007E818 03000016 */  bnez       $s0, .L8007E828
    /* 6F01C 8007E81C 21200002 */   addu      $a0, $s0, $zero
    /* 6F020 8007E820 11FA0108 */  j          .L8007E844
    /* 6F024 8007E824 21100000 */   addu      $v0, $zero, $zero
  .L8007E828:
    /* 6F028 8007E828 0FEE010C */  jal        func_8007B83C
    /* 6F02C 8007E82C 21282002 */   addu      $a1, $s1, $zero
    /* 6F030 8007E830 FF004230 */  andi       $v0, $v0, 0xFF
    /* 6F034 8007E834 FCFF4010 */  beqz       $v0, .L8007E828
    /* 6F038 8007E838 21200002 */   addu      $a0, $s0, $zero
    /* 6F03C 8007E83C 02004238 */  xori       $v0, $v0, 0x2
    /* 6F040 8007E840 0100422C */  sltiu      $v0, $v0, 0x1
  .L8007E844:
    /* 6F044 8007E844 1800BF8F */  lw         $ra, 0x18($sp)
    /* 6F048 8007E848 1400B18F */  lw         $s1, 0x14($sp)
    /* 6F04C 8007E84C 1000B08F */  lw         $s0, 0x10($sp)
    /* 6F050 8007E850 0800E003 */  jr         $ra
    /* 6F054 8007E854 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8007E7F0
    /* 6F058 8007E858 00000000 */  nop
    /* 6F05C 8007E85C 00000000 */  nop
