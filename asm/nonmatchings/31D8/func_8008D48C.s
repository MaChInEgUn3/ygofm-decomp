nonmatching func_8008D48C, 0x20

glabel func_8008D48C
    /* 7DC8C 8008D48C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 7DC90 8008D490 1000BFAF */  sw         $ra, 0x10($sp)
    /* 7DC94 8008D494 2E2D020C */  jal        func_8008B4B8
    /* 7DC98 8008D498 00000000 */   nop
    /* 7DC9C 8008D49C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 7DCA0 8008D4A0 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 7DCA4 8008D4A4 0800E003 */  jr         $ra
    /* 7DCA8 8008D4A8 00000000 */   nop
endlabel func_8008D48C
