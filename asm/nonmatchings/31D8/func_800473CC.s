nonmatching func_800473CC, 0x24

glabel func_800473CC
    /* 37BCC 800473CC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 37BD0 800473D0 FFFF8430 */  andi       $a0, $a0, 0xFFFF
    /* 37BD4 800473D4 1000BFAF */  sw         $ra, 0x10($sp)
    /* 37BD8 800473D8 FC1C010C */  jal        func_800473F0
    /* 37BDC 800473DC E0FF0524 */   addiu     $a1, $zero, -0x20
    /* 37BE0 800473E0 1000BF8F */  lw         $ra, 0x10($sp)
    /* 37BE4 800473E4 00000000 */  nop
    /* 37BE8 800473E8 0800E003 */  jr         $ra
    /* 37BEC 800473EC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800473CC
