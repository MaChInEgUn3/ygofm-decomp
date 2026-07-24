nonmatching func_80043E30, 0x38

glabel func_80043E30
    /* 34630 80043E30 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 34634 80043E34 1000BFAF */  sw         $ra, 0x10($sp)
    /* 34638 80043E38 F82C020C */  jal        func_8008B3E0
    /* 3463C 80043E3C 00000000 */   nop
    /* 34640 80043E40 1C2D020C */  jal        func_8008B470
    /* 34644 80043E44 00000000 */   nop
    /* 34648 80043E48 50CE010C */  jal        func_80073940
    /* 3464C 80043E4C 21200000 */   addu      $a0, $zero, $zero
    /* 34650 80043E50 10CE010C */  jal        func_80073840
    /* 34654 80043E54 00000000 */   nop
    /* 34658 80043E58 1000BF8F */  lw         $ra, 0x10($sp)
    /* 3465C 80043E5C 00000000 */  nop
    /* 34660 80043E60 0800E003 */  jr         $ra
    /* 34664 80043E64 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80043E30
