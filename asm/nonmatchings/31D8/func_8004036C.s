nonmatching func_8004036C, 0x24

glabel func_8004036C
    /* 30B6C 8004036C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 30B70 80040370 03008010 */  beqz       $a0, .L80040380
    /* 30B74 80040374 1000BFAF */   sw        $ra, 0x10($sp)
    /* 30B78 80040378 8300010C */  jal        func_8004020C
    /* 30B7C 8004037C 00000000 */   nop
  .L80040380:
    /* 30B80 80040380 1000BF8F */  lw         $ra, 0x10($sp)
    /* 30B84 80040384 00000000 */  nop
    /* 30B88 80040388 0800E003 */  jr         $ra
    /* 30B8C 8004038C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8004036C
