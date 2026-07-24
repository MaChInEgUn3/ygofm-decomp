nonmatching func_8007E350, 0x20

glabel func_8007E350
    /* 6EB50 8007E350 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 6EB54 8007E354 1000BFAF */  sw         $ra, 0x10($sp)
    /* 6EB58 8007E358 80EF010C */  jal        func_8007BE00
    /* 6EB5C 8007E35C 00000000 */   nop
    /* 6EB60 8007E360 1000BF8F */  lw         $ra, 0x10($sp)
    /* 6EB64 8007E364 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 6EB68 8007E368 0800E003 */  jr         $ra
    /* 6EB6C 8007E36C 00000000 */   nop
endlabel func_8007E350
