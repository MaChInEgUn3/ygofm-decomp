nonmatching func_8008B4B8, 0x28

glabel func_8008B4B8
    /* 7BCB8 8008B4B8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 7BCBC 8008B4BC 1000BFAF */  sw         $ra, 0x10($sp)
    /* 7BCC0 8008B4C0 402D020C */  jal        func_8008B500
    /* 7BCC4 8008B4C4 00000000 */   nop
    /* 7BCC8 8008B4C8 CC2D020C */  jal        func_8008B730
    /* 7BCCC 8008B4CC 00000000 */   nop
    /* 7BCD0 8008B4D0 1000BF8F */  lw         $ra, 0x10($sp)
    /* 7BCD4 8008B4D4 21100000 */  addu       $v0, $zero, $zero
    /* 7BCD8 8008B4D8 0800E003 */  jr         $ra
    /* 7BCDC 8008B4DC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8008B4B8
