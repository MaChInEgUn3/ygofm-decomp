nonmatching func_8003B714, 0x20

glabel func_8003B714
    /* 2BF14 8003B714 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2BF18 8003B718 1000BFAF */  sw         $ra, 0x10($sp)
    /* 2BF1C 8003B71C BCD6000C */  jal        func_80035AF0
    /* 2BF20 8003B720 21300000 */   addu      $a2, $zero, $zero
    /* 2BF24 8003B724 1000BF8F */  lw         $ra, 0x10($sp)
    /* 2BF28 8003B728 00000000 */  nop
    /* 2BF2C 8003B72C 0800E003 */  jr         $ra
    /* 2BF30 8003B730 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8003B714
