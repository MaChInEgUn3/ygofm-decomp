nonmatching func_800598E4, 0x24

glabel func_800598E4
    /* 4A0E4 800598E4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 4A0E8 800598E8 21300000 */  addu       $a2, $zero, $zero
    /* 4A0EC 800598EC 1000BFAF */  sw         $ra, 0x10($sp)
    /* 4A0F0 800598F0 4266010C */  jal        func_80059908
    /* 4A0F4 800598F4 2138C000 */   addu      $a3, $a2, $zero
    /* 4A0F8 800598F8 1000BF8F */  lw         $ra, 0x10($sp)
    /* 4A0FC 800598FC 00000000 */  nop
    /* 4A100 80059900 0800E003 */  jr         $ra
    /* 4A104 80059904 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800598E4
