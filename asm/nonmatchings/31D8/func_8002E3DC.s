nonmatching func_8002E3DC, 0x20

glabel func_8002E3DC
    /* 1EBDC 8002E3DC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1EBE0 8002E3E0 1000BFAF */  sw         $ra, 0x10($sp)
    /* 1EBE4 8002E3E4 EDB8000C */  jal        func_8002E3B4
    /* 1EBE8 8002E3E8 00000000 */   nop
    /* 1EBEC 8002E3EC 1000BF8F */  lw         $ra, 0x10($sp)
    /* 1EBF0 8002E3F0 00000000 */  nop
    /* 1EBF4 8002E3F4 0800E003 */  jr         $ra
    /* 1EBF8 8002E3F8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8002E3DC
