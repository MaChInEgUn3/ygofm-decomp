nonmatching func_800451E0, 0x28

glabel func_800451E0
    /* 359E0 800451E0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 359E4 800451E4 FFFF8430 */  andi       $a0, $a0, 0xFFFF
    /* 359E8 800451E8 1000BFAF */  sw         $ra, 0x10($sp)
    /* 359EC 800451EC 8214010C */  jal        func_80045208
    /* 359F0 800451F0 80000524 */   addiu     $a1, $zero, 0x80
    /* 359F4 800451F4 00140200 */  sll        $v0, $v0, 16
    /* 359F8 800451F8 1000BF8F */  lw         $ra, 0x10($sp)
    /* 359FC 800451FC 03140200 */  sra        $v0, $v0, 16
    /* 35A00 80045200 0800E003 */  jr         $ra
    /* 35A04 80045204 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800451E0
