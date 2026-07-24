nonmatching func_8003F70C, 0x34

glabel func_8003F70C
    /* 2FF0C 8003F70C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2FF10 8003F710 1000BFAF */  sw         $ra, 0x10($sp)
    /* 2FF14 8003F714 15FD000C */  jal        func_8003F454
    /* 2FF18 8003F718 00000000 */   nop
    /* 2FF1C 8003F71C F2048297 */  lhu        $v0, %gp_rel(D_8009B3FA)($gp)
    /* 2FF20 8003F720 00000000 */  nop
    /* 2FF24 8003F724 02004014 */  bnez       $v0, .L8003F730
    /* 2FF28 8003F728 21100000 */   addu      $v0, $zero, $zero
    /* 2FF2C 8003F72C E7048293 */  lbu        $v0, %gp_rel(D_8009B3EF)($gp)
  .L8003F730:
    /* 2FF30 8003F730 1000BF8F */  lw         $ra, 0x10($sp)
    /* 2FF34 8003F734 00000000 */  nop
    /* 2FF38 8003F738 0800E003 */  jr         $ra
    /* 2FF3C 8003F73C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8003F70C
