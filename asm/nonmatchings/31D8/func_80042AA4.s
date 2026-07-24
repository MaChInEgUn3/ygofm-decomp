nonmatching func_80042AA4, 0x34

glabel func_80042AA4
    /* 332A4 80042AA4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 332A8 80042AA8 1000B0AF */  sw         $s0, 0x10($sp)
    /* 332AC 80042AAC 1400BFAF */  sw         $ra, 0x14($sp)
    /* 332B0 80042AB0 800A010C */  jal        func_80042A00
    /* 332B4 80042AB4 21808000 */   addu      $s0, $a0, $zero
    /* 332B8 80042AB8 8A0A010C */  jal        func_80042A28
    /* 332BC 80042ABC 21200002 */   addu      $a0, $s0, $zero
    /* 332C0 80042AC0 940A010C */  jal        func_80042A50
    /* 332C4 80042AC4 21200002 */   addu      $a0, $s0, $zero
    /* 332C8 80042AC8 1400BF8F */  lw         $ra, 0x14($sp)
    /* 332CC 80042ACC 1000B08F */  lw         $s0, 0x10($sp)
    /* 332D0 80042AD0 0800E003 */  jr         $ra
    /* 332D4 80042AD4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80042AA4
