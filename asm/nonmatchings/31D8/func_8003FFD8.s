nonmatching func_8003FFD8, 0x24

glabel func_8003FFD8
    /* 307D8 8003FFD8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 307DC 8003FFDC FFFF8430 */  andi       $a0, $a0, 0xFFFF
    /* 307E0 8003FFE0 1000BFAF */  sw         $ra, 0x10($sp)
    /* 307E4 8003FFE4 C51C010C */  jal        func_80047314
    /* 307E8 8003FFE8 00A08434 */   ori       $a0, $a0, 0xA000
    /* 307EC 8003FFEC 1000BF8F */  lw         $ra, 0x10($sp)
    /* 307F0 8003FFF0 00000000 */  nop
    /* 307F4 8003FFF4 0800E003 */  jr         $ra
    /* 307F8 8003FFF8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8003FFD8
