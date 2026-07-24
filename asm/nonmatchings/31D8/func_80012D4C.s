nonmatching func_80012D4C, 0x38

glabel func_80012D4C
    /* 354C 80012D4C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 3550 80012D50 1000BFAF */  sw         $ra, 0x10($sp)
    /* 3554 80012D54 1B4C000C */  jal        func_8001306C
    /* 3558 80012D58 00000000 */   nop
    /* 355C 80012D5C 6D4B000C */  jal        func_80012DB4
    /* 3560 80012D60 00000000 */   nop
    /* 3564 80012D64 974B000C */  jal        func_80012E5C
    /* 3568 80012D68 00000000 */   nop
    /* 356C 80012D6C 36F3000C */  jal        func_8003CCD8
    /* 3570 80012D70 00000000 */   nop
    /* 3574 80012D74 1000BF8F */  lw         $ra, 0x10($sp)
    /* 3578 80012D78 00000000 */  nop
    /* 357C 80012D7C 0800E003 */  jr         $ra
    /* 3580 80012D80 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80012D4C
