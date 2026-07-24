nonmatching func_8008FE7C, 0x24

glabel func_8008FE7C
    /* 8067C 8008FE7C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 80680 8008FE80 1000BFAF */  sw         $ra, 0x10($sp)
    /* 80684 8008FE84 21288000 */  addu       $a1, $a0, $zero
    /* 80688 8008FE88 FCD0010C */  jal        func_800743F0
    /* 8068C 8008FE8C 01000424 */   addiu     $a0, $zero, 0x1
    /* 80690 8008FE90 1000BF8F */  lw         $ra, 0x10($sp)
    /* 80694 8008FE94 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 80698 8008FE98 0800E003 */  jr         $ra
    /* 8069C 8008FE9C 00000000 */   nop
endlabel func_8008FE7C
