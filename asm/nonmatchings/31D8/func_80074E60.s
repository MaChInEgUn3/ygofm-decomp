nonmatching func_80074E60, 0x20

glabel func_80074E60
    /* 65660 80074E60 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 65664 80074E64 1000BFAF */  sw         $ra, 0x10($sp)
    /* 65668 80074E68 A0D3010C */  jal        func_80074E80
    /* 6566C 80074E6C 21200000 */   addu      $a0, $zero, $zero
    /* 65670 80074E70 1000BF8F */  lw         $ra, 0x10($sp)
    /* 65674 80074E74 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 65678 80074E78 0800E003 */  jr         $ra
    /* 6567C 80074E7C 00000000 */   nop
endlabel func_80074E60
