nonmatching func_8007E3D0, 0x20

glabel func_8007E3D0
    /* 6EBD0 8007E3D0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 6EBD4 8007E3D4 1000BFAF */  sw         $ra, 0x10($sp)
    /* 6EBD8 8007E3D8 FCF8010C */  jal        func_8007E3F0
    /* 6EBDC 8007E3DC 00000000 */   nop
    /* 6EBE0 8007E3E0 1000BF8F */  lw         $ra, 0x10($sp)
    /* 6EBE4 8007E3E4 0100422C */  sltiu      $v0, $v0, 0x1
    /* 6EBE8 8007E3E8 0800E003 */  jr         $ra
    /* 6EBEC 8007E3EC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8007E3D0
