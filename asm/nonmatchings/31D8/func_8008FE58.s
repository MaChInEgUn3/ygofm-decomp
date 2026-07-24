nonmatching func_8008FE58, 0x24

glabel func_8008FE58
    /* 80658 8008FE58 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 8065C 8008FE5C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 80660 8008FE60 21288000 */  addu       $a1, $a0, $zero
    /* 80664 8008FE64 FCD0010C */  jal        func_800743F0
    /* 80668 8008FE68 21200000 */   addu      $a0, $zero, $zero
    /* 8066C 8008FE6C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 80670 8008FE70 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 80674 8008FE74 0800E003 */  jr         $ra
    /* 80678 8008FE78 00000000 */   nop
endlabel func_8008FE58
