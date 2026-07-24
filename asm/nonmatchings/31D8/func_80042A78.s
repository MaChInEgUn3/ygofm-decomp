nonmatching func_80042A78, 0x2C

glabel func_80042A78
    /* 33278 80042A78 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 3327C 80042A7C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 33280 80042A80 1400BFAF */  sw         $ra, 0x14($sp)
    /* 33284 80042A84 800A010C */  jal        func_80042A00
    /* 33288 80042A88 21808000 */   addu      $s0, $a0, $zero
    /* 3328C 80042A8C 8A0A010C */  jal        func_80042A28
    /* 33290 80042A90 21200002 */   addu      $a0, $s0, $zero
    /* 33294 80042A94 1400BF8F */  lw         $ra, 0x14($sp)
    /* 33298 80042A98 1000B08F */  lw         $s0, 0x10($sp)
    /* 3329C 80042A9C 0800E003 */  jr         $ra
    /* 332A0 80042AA0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80042A78
