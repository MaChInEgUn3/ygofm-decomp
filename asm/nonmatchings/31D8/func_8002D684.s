nonmatching func_8002D684, 0x44

glabel func_8002D684
    /* 1DE84 8002D684 64038393 */  lbu        $v1, %gp_rel(D_8009B26C)($gp)
    /* 1DE88 8002D688 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1DE8C 8002D68C 40006230 */  andi       $v0, $v1, 0x40
    /* 1DE90 8002D690 07004014 */  bnez       $v0, .L8002D6B0
    /* 1DE94 8002D694 1000BFAF */   sw        $ra, 0x10($sp)
    /* 1DE98 8002D698 40006234 */  ori        $v0, $v1, 0x40
    /* 1DE9C 8002D69C 640382A3 */  sb         $v0, %gp_rel(D_8009B26C)($gp)
    /* 1DEA0 8002D6A0 AEEF000C */  jal        func_8003BEB8
    /* 1DEA4 8002D6A4 00000000 */   nop
    /* 1DEA8 8002D6A8 20A8050C */  jal        func_8016A080
    /* 1DEAC 8002D6AC 00000000 */   nop
  .L8002D6B0:
    /* 1DEB0 8002D6B0 DFA8050C */  jal        func_8016A37C
    /* 1DEB4 8002D6B4 00000000 */   nop
    /* 1DEB8 8002D6B8 1000BF8F */  lw         $ra, 0x10($sp)
    /* 1DEBC 8002D6BC 00000000 */  nop
    /* 1DEC0 8002D6C0 0800E003 */  jr         $ra
    /* 1DEC4 8002D6C4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8002D684
