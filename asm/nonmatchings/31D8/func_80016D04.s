nonmatching func_80016D04, 0x28

glabel func_80016D04
    /* 7504 80016D04 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 7508 80016D08 1000BFAF */  sw         $ra, 0x10($sp)
    /* 750C 80016D0C 30008684 */  lh         $a2, 0x30($a0)
    /* 7510 80016D10 32008784 */  lh         $a3, 0x32($a0)
    /* 7514 80016D14 E159000C */  jal        func_80016784
    /* 7518 80016D18 00000000 */   nop
    /* 751C 80016D1C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 7520 80016D20 00000000 */  nop
    /* 7524 80016D24 0800E003 */  jr         $ra
    /* 7528 80016D28 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80016D04
