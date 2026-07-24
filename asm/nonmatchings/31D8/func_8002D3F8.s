nonmatching func_8002D3F8, 0x60

glabel func_8002D3F8
    /* 1DBF8 8002D3F8 64038393 */  lbu        $v1, %gp_rel(D_8009B26C)($gp)
    /* 1DBFC 8002D3FC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1DC00 8002D400 40006230 */  andi       $v0, $v1, 0x40
    /* 1DC04 8002D404 07004014 */  bnez       $v0, .L8002D424
    /* 1DC08 8002D408 1000BFAF */   sw        $ra, 0x10($sp)
    /* 1DC0C 8002D40C 40006234 */  ori        $v0, $v1, 0x40
    /* 1DC10 8002D410 640382A3 */  sb         $v0, %gp_rel(D_8009B26C)($gp)
    /* 1DC14 8002D414 6FEE000C */  jal        func_8003B9BC
    /* 1DC18 8002D418 00000000 */   nop
    /* 1DC1C 8002D41C 8056000C */  jal        func_80015A00
    /* 1DC20 8002D420 00000000 */   nop
  .L8002D424:
    /* 1DC24 8002D424 EDA3050C */  jal        func_80168FB4
    /* 1DC28 8002D428 00000000 */   nop
    /* 1DC2C 8002D42C 64038293 */  lbu        $v0, %gp_rel(D_8009B26C)($gp)
    /* 1DC30 8002D430 00000000 */  nop
    /* 1DC34 8002D434 40004230 */  andi       $v0, $v0, 0x40
    /* 1DC38 8002D438 03004014 */  bnez       $v0, .L8002D448
    /* 1DC3C 8002D43C 00000000 */   nop
    /* 1DC40 8002D440 CDFF000C */  jal        func_8003FF34
    /* 1DC44 8002D444 00000000 */   nop
  .L8002D448:
    /* 1DC48 8002D448 1000BF8F */  lw         $ra, 0x10($sp)
    /* 1DC4C 8002D44C 00000000 */  nop
    /* 1DC50 8002D450 0800E003 */  jr         $ra
    /* 1DC54 8002D454 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8002D3F8
