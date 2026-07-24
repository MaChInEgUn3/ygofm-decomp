nonmatching func_8003FF08, 0x2C

glabel func_8003FF08
    /* 30708 8003FF08 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 3070C 8003FF0C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 30710 8003FF10 00709034 */  ori        $s0, $a0, 0x7000
    /* 30714 8003FF14 1400BFAF */  sw         $ra, 0x14($sp)
    /* 30718 8003FF18 C51C010C */  jal        func_80047314
    /* 3071C 8003FF1C FFFF0432 */   andi      $a0, $s0, 0xFFFF
    /* 30720 8003FF20 1400BF8F */  lw         $ra, 0x14($sp)
    /* 30724 8003FF24 F80490AF */  sw         $s0, %gp_rel(D_8009B400)($gp)
    /* 30728 8003FF28 1000B08F */  lw         $s0, 0x10($sp)
    /* 3072C 8003FF2C 0800E003 */  jr         $ra
    /* 30730 8003FF30 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8003FF08
