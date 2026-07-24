nonmatching func_8008B3A0, 0x34

glabel func_8008B3A0
    /* 7BBA0 8008B3A0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 7BBA4 8008B3A4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 7BBA8 8008B3A8 1400BFAF */  sw         $ra, 0x14($sp)
    /* 7BBAC 8008B3AC DC2C020C */  jal        func_8008B370
    /* 7BBB0 8008B3B0 21808000 */   addu      $s0, $a0, $zero
    /* 7BBB4 8008B3B4 21200002 */  addu       $a0, $s0, $zero
    /* 7BBB8 8008B3B8 3F000524 */  addiu      $a1, $zero, 0x3F
    /* 7BBBC 8008B3BC D42C020C */  jal        func_8008B350
    /* 7BBC0 8008B3C0 21300000 */   addu      $a2, $zero, $zero
    /* 7BBC4 8008B3C4 1400BF8F */  lw         $ra, 0x14($sp)
    /* 7BBC8 8008B3C8 1000B08F */  lw         $s0, 0x10($sp)
    /* 7BBCC 8008B3CC 0800E003 */  jr         $ra
    /* 7BBD0 8008B3D0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8008B3A0
    /* 7BBD4 8008B3D4 00000000 */  nop
    /* 7BBD8 8008B3D8 00000000 */  nop
    /* 7BBDC 8008B3DC 00000000 */  nop
