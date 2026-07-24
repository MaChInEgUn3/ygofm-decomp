nonmatching func_80038388, 0x28

glabel func_80038388
    /* 28B88 80038388 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 28B8C 8003838C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 28B90 80038390 1400BFAF */  sw         $ra, 0x14($sp)
    /* 28B94 80038394 4FDB000C */  jal        func_80036D3C
    /* 28B98 80038398 21808000 */   addu      $s0, $a0, $zero
    /* 28B9C 8003839C 380002A6 */  sh         $v0, 0x38($s0)
    /* 28BA0 800383A0 1400BF8F */  lw         $ra, 0x14($sp)
    /* 28BA4 800383A4 1000B08F */  lw         $s0, 0x10($sp)
    /* 28BA8 800383A8 0800E003 */  jr         $ra
    /* 28BAC 800383AC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80038388
