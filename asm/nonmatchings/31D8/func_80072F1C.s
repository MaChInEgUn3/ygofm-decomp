nonmatching func_80072F1C, 0x38

glabel func_80072F1C
    /* 6371C 80072F1C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 63720 80072F20 1000BFAF */  sw         $ra, 0x10($sp)
    /* 63724 80072F24 63C1010C */  jal        func_8007058C
    /* 63728 80072F28 00000000 */   nop
    /* 6372C 80072F2C 63C1010C */  jal        func_8007058C
    /* 63730 80072F30 00000000 */   nop
    /* 63734 80072F34 63C1010C */  jal        func_8007058C
    /* 63738 80072F38 00000000 */   nop
    /* 6373C 80072F3C 63C1010C */  jal        func_8007058C
    /* 63740 80072F40 00000000 */   nop
    /* 63744 80072F44 1000BF8F */  lw         $ra, 0x10($sp)
    /* 63748 80072F48 00000000 */  nop
    /* 6374C 80072F4C 0800E003 */  jr         $ra
    /* 63750 80072F50 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80072F1C
