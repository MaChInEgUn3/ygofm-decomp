nonmatching func_80081424, 0x24

glabel func_80081424
    /* 71C24 80081424 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 71C28 80081428 1000BFAF */  sw         $ra, 0x10($sp)
    /* 71C2C 8008142C 2138C000 */  addu       $a3, $a2, $zero
    /* 71C30 80081430 1205020C */  jal        func_80081448
    /* 71C34 80081434 21300000 */   addu      $a2, $zero, $zero
    /* 71C38 80081438 1000BF8F */  lw         $ra, 0x10($sp)
    /* 71C3C 8008143C 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 71C40 80081440 0800E003 */  jr         $ra
    /* 71C44 80081444 00000000 */   nop
endlabel func_80081424
