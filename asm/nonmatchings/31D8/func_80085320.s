nonmatching func_80085320, 0x10

glabel func_80085320
    /* 75B20 80085320 1080023C */  lui        $v0, %hi(D_800FE0CC)
    /* 75B24 80085324 CCE04284 */  lh         $v0, %lo(D_800FE0CC)($v0)
    /* 75B28 80085328 0800E003 */  jr         $ra
    /* 75B2C 8008532C 00000000 */   nop
endlabel func_80085320
