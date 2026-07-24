nonmatching func_8002D6C8, 0x68

glabel func_8002D6C8
    /* 1DEC8 8002D6C8 64038393 */  lbu        $v1, %gp_rel(D_8009B26C)($gp)
    /* 1DECC 8002D6CC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1DED0 8002D6D0 40006230 */  andi       $v0, $v1, 0x40
    /* 1DED4 8002D6D4 09004014 */  bnez       $v0, .L8002D6FC
    /* 1DED8 8002D6D8 1000BFAF */   sw        $ra, 0x10($sp)
    /* 1DEDC 8002D6DC 40006234 */  ori        $v0, $v1, 0x40
    /* 1DEE0 8002D6E0 640382A3 */  sb         $v0, %gp_rel(D_8009B26C)($gp)
    /* 1DEE4 8002D6E4 ADF0000C */  jal        func_8003C2B4
    /* 1DEE8 8002D6E8 00000000 */   nop
    /* 1DEEC 8002D6EC 8AF1000C */  jal        func_8003C628
    /* 1DEF0 8002D6F0 00000000 */   nop
    /* 1DEF4 8002D6F4 8056000C */  jal        func_80015A00
    /* 1DEF8 8002D6F8 00000000 */   nop
  .L8002D6FC:
    /* 1DEFC 8002D6FC 33F2000C */  jal        func_8003C8CC
    /* 1DF00 8002D700 00000000 */   nop
    /* 1DF04 8002D704 06004014 */  bnez       $v0, .L8002D720
    /* 1DF08 8002D708 00000000 */   nop
    /* 1DF0C 8002D70C CDFF000C */  jal        func_8003FF34
    /* 1DF10 8002D710 00000000 */   nop
    /* 1DF14 8002D714 61038293 */  lbu        $v0, %gp_rel(D_8009B269)($gp)
    /* 1DF18 8002D718 00000000 */  nop
    /* 1DF1C 8002D71C 640382A3 */  sb         $v0, %gp_rel(D_8009B26C)($gp)
  .L8002D720:
    /* 1DF20 8002D720 1000BF8F */  lw         $ra, 0x10($sp)
    /* 1DF24 8002D724 00000000 */  nop
    /* 1DF28 8002D728 0800E003 */  jr         $ra
    /* 1DF2C 8002D72C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8002D6C8
