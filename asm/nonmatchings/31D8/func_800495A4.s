nonmatching func_800495A4, 0x38

glabel func_800495A4
    /* 39DA4 800495A4 0A80023C */  lui        $v0, %hi(D_8009B458)
    /* 39DA8 800495A8 58B4428C */  lw         $v0, %lo(D_8009B458)($v0)
    /* 39DAC 800495AC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 39DB0 800495B0 1000BFAF */  sw         $ra, 0x10($sp)
    /* 39DB4 800495B4 14084290 */  lbu        $v0, 0x814($v0)
    /* 39DB8 800495B8 00000000 */  nop
    /* 39DBC 800495BC 03004010 */  beqz       $v0, .L800495CC
    /* 39DC0 800495C0 00000000 */   nop
    /* 39DC4 800495C4 782E010C */  jal        func_8004B9E0
    /* 39DC8 800495C8 00000000 */   nop
  .L800495CC:
    /* 39DCC 800495CC 1000BF8F */  lw         $ra, 0x10($sp)
    /* 39DD0 800495D0 00000000 */  nop
    /* 39DD4 800495D4 0800E003 */  jr         $ra
    /* 39DD8 800495D8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800495A4
