nonmatching func_80047314, 0x28

glabel func_80047314
    /* 37B14 80047314 5405828F */  lw         $v0, %gp_rel(D_8009B45C)($gp)
    /* 37B18 80047318 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 37B1C 8004731C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 37B20 80047320 4B164590 */  lbu        $a1, 0x164B($v0)
    /* 37B24 80047324 CF1C010C */  jal        func_8004733C
    /* 37B28 80047328 FFFF8430 */   andi      $a0, $a0, 0xFFFF
    /* 37B2C 8004732C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 37B30 80047330 00000000 */  nop
    /* 37B34 80047334 0800E003 */  jr         $ra
    /* 37B38 80047338 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80047314
