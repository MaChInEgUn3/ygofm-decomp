nonmatching func_8007E390, 0x38

glabel func_8007E390
    /* 6EB90 8007E390 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 6EB94 8007E394 1000BFAF */  sw         $ra, 0x10($sp)
    /* 6EB98 8007E398 23F3010C */  jal        func_8007CC8C
    /* 6EB9C 8007E39C 00000000 */   nop
    /* 6EBA0 8007E3A0 6BEA010C */  jal        func_8007A9AC
    /* 6EBA4 8007E3A4 00000000 */   nop
    /* 6EBA8 8007E3A8 75F7010C */  jal        func_8007DDD4
    /* 6EBAC 8007E3AC 00000000 */   nop
    /* 6EBB0 8007E3B0 41F3010C */  jal        func_8007CD04
    /* 6EBB4 8007E3B4 00000000 */   nop
    /* 6EBB8 8007E3B8 1000BF8F */  lw         $ra, 0x10($sp)
    /* 6EBBC 8007E3BC 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 6EBC0 8007E3C0 0800E003 */  jr         $ra
    /* 6EBC4 8007E3C4 00000000 */   nop
endlabel func_8007E390
    /* 6EBC8 8007E3C8 00000000 */  nop
    /* 6EBCC 8007E3CC 00000000 */  nop
