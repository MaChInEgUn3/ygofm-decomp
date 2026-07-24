nonmatching func_80075B30, 0x24

glabel func_80075B30
    /* 66330 80075B30 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 66334 80075B34 1000BFAF */  sw         $ra, 0x10($sp)
    /* 66338 80075B38 21288000 */  addu       $a1, $a0, $zero
    /* 6633C 80075B3C FCD0010C */  jal        func_800743F0
    /* 66340 80075B40 04000424 */   addiu     $a0, $zero, 0x4
    /* 66344 80075B44 1000BF8F */  lw         $ra, 0x10($sp)
    /* 66348 80075B48 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 6634C 80075B4C 0800E003 */  jr         $ra
    /* 66350 80075B50 00000000 */   nop
endlabel func_80075B30
    /* 66354 80075B54 00000000 */  nop
    /* 66358 80075B58 00000000 */  nop
    /* 6635C 80075B5C 00000000 */  nop
