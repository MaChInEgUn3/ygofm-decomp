nonmatching func_80038690, 0x28

glabel func_80038690
    /* 28E90 80038690 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 28E94 80038694 1000BFAF */  sw         $ra, 0x10($sp)
    /* 28E98 80038698 4FDB000C */  jal        func_80036D3C
    /* 28E9C 8003869C 00000000 */   nop
    /* 28EA0 800386A0 C2FF000C */  jal        func_8003FF08
    /* 28EA4 800386A4 FFFF4430 */   andi      $a0, $v0, 0xFFFF
    /* 28EA8 800386A8 1000BF8F */  lw         $ra, 0x10($sp)
    /* 28EAC 800386AC 00000000 */  nop
    /* 28EB0 800386B0 0800E003 */  jr         $ra
    /* 28EB4 800386B4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80038690
