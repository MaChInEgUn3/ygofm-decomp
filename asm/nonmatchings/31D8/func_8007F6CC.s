nonmatching func_8007F6CC, 0x68

glabel func_8007F6CC
    /* 6FECC 8007F6CC 0980023C */  lui        $v0, %hi(D_8009466A)
    /* 6FED0 8007F6D0 6A464290 */  lbu        $v0, %lo(D_8009466A)($v0)
    /* 6FED4 8007F6D4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 6FED8 8007F6D8 1000B0AF */  sw         $s0, 0x10($sp)
    /* 6FEDC 8007F6DC 21808000 */  addu       $s0, $a0, $zero
    /* 6FEE0 8007F6E0 0200422C */  sltiu      $v0, $v0, 0x2
    /* 6FEE4 8007F6E4 08004014 */  bnez       $v0, .L8007F708
    /* 6FEE8 8007F6E8 1400BFAF */   sw        $ra, 0x14($sp)
    /* 6FEEC 8007F6EC 0180043C */  lui        $a0, %hi(D_80012224)
    /* 6FEF0 8007F6F0 24228424 */  addiu      $a0, $a0, %lo(D_80012224)
    /* 6FEF4 8007F6F4 0980023C */  lui        $v0, %hi(D_80094664)
    /* 6FEF8 8007F6F8 6446428C */  lw         $v0, %lo(D_80094664)($v0)
    /* 6FEFC 8007F6FC 00000000 */  nop
    /* 6FF00 8007F700 09F84000 */  jalr       $v0
    /* 6FF04 8007F704 21280002 */   addu      $a1, $s0, $zero
  .L8007F708:
    /* 6FF08 8007F708 0980023C */  lui        $v0, %hi(D_80094660)
    /* 6FF0C 8007F70C 6046428C */  lw         $v0, %lo(D_80094660)($v0)
    /* 6FF10 8007F710 00000000 */  nop
    /* 6FF14 8007F714 3C00428C */  lw         $v0, 0x3C($v0)
    /* 6FF18 8007F718 00000000 */  nop
    /* 6FF1C 8007F71C 09F84000 */  jalr       $v0
    /* 6FF20 8007F720 21200002 */   addu      $a0, $s0, $zero
    /* 6FF24 8007F724 1400BF8F */  lw         $ra, 0x14($sp)
    /* 6FF28 8007F728 1000B08F */  lw         $s0, 0x10($sp)
    /* 6FF2C 8007F72C 0800E003 */  jr         $ra
    /* 6FF30 8007F730 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8007F6CC
