nonmatching func_8008B7B0, 0x30

glabel func_8008B7B0
    /* 7BFB0 8008B7B0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 7BFB4 8008B7B4 1000BFAF */  sw         $ra, 0x10($sp)
    /* 7BFB8 8008B7B8 F82C020C */  jal        func_8008B3E0
    /* 7BFBC 8008B7BC 00000000 */   nop
    /* 7BFC0 8008B7C0 1C2D020C */  jal        func_8008B470
    /* 7BFC4 8008B7C4 00000000 */   nop
    /* 7BFC8 8008B7C8 10CE010C */  jal        func_80073840
    /* 7BFCC 8008B7CC 00000000 */   nop
    /* 7BFD0 8008B7D0 1000BF8F */  lw         $ra, 0x10($sp)
    /* 7BFD4 8008B7D4 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 7BFD8 8008B7D8 0800E003 */  jr         $ra
    /* 7BFDC 8008B7DC 00000000 */   nop
endlabel func_8008B7B0
