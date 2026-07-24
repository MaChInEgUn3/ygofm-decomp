nonmatching func_8003FEE0, 0x28

glabel func_8003FEE0
    /* 306E0 8003FEE0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 306E4 8003FEE4 FFFF8430 */  andi       $a0, $a0, 0xFFFF
    /* 306E8 8003FEE8 FF000524 */  addiu      $a1, $zero, 0xFF
    /* 306EC 8003FEEC 1000BFAF */  sw         $ra, 0x10($sp)
    /* 306F0 8003FEF0 9621010C */  jal        func_80048658
    /* 306F4 8003FEF4 21300000 */   addu      $a2, $zero, $zero
    /* 306F8 8003FEF8 1000BF8F */  lw         $ra, 0x10($sp)
    /* 306FC 8003FEFC 00000000 */  nop
    /* 30700 8003FF00 0800E003 */  jr         $ra
    /* 30704 8003FF04 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8003FEE0
