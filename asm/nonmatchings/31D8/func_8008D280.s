nonmatching func_8008D280, 0x30

glabel func_8008D280
    /* 7DA80 8008D280 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 7DA84 8008D284 1000BFAF */  sw         $ra, 0x10($sp)
    /* 7DA88 8008D288 F82C020C */  jal        func_8008B3E0
    /* 7DA8C 8008D28C 00000000 */   nop
    /* 7DA90 8008D290 1C2D020C */  jal        func_8008B470
    /* 7DA94 8008D294 00000000 */   nop
    /* 7DA98 8008D298 10CE010C */  jal        func_80073840
    /* 7DA9C 8008D29C 00000000 */   nop
    /* 7DAA0 8008D2A0 1000BF8F */  lw         $ra, 0x10($sp)
    /* 7DAA4 8008D2A4 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 7DAA8 8008D2A8 0800E003 */  jr         $ra
    /* 7DAAC 8008D2AC 00000000 */   nop
endlabel func_8008D280
