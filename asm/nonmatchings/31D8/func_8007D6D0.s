nonmatching func_8007D6D0, 0x20

glabel func_8007D6D0
    /* 6DED0 8007D6D0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 6DED4 8007D6D4 1000BFAF */  sw         $ra, 0x10($sp)
    /* 6DED8 8007D6D8 E039020C */  jal        func_8008E780
    /* 6DEDC 8007D6DC 0C000624 */   addiu     $a2, $zero, 0xC
    /* 6DEE0 8007D6E0 1000BF8F */  lw         $ra, 0x10($sp)
    /* 6DEE4 8007D6E4 0100422C */  sltiu      $v0, $v0, 0x1
    /* 6DEE8 8007D6E8 0800E003 */  jr         $ra
    /* 6DEEC 8007D6EC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8007D6D0
