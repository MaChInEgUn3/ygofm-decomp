nonmatching func_80039FD4, 0x24

glabel func_80039FD4
    /* 2A7D4 80039FD4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2A7D8 80039FD8 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 2A7DC 80039FDC 1000BFAF */  sw         $ra, 0x10($sp)
    /* 2A7E0 80039FE0 E4E7000C */  jal        func_80039F90
    /* 2A7E4 80039FE4 300082A0 */   sb        $v0, 0x30($a0)
    /* 2A7E8 80039FE8 1000BF8F */  lw         $ra, 0x10($sp)
    /* 2A7EC 80039FEC 00000000 */  nop
    /* 2A7F0 80039FF0 0800E003 */  jr         $ra
    /* 2A7F4 80039FF4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80039FD4
