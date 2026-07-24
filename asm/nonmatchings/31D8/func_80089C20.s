nonmatching func_80089C20, 0x20

glabel func_80089C20
    /* 7A420 80089C20 000080C8 */  lwc2       $0, 0x0($a0)
    /* 7A424 80089C24 040081C8 */  lwc2       $1, 0x4($a0)
    /* 7A428 80089C28 0000A6C8 */  lwc2       $6, 0x0($a1)
    /* 7A42C 80089C2C 00000000 */  nop
    /* 7A430 80089C30 1B04084B */  nccs
    /* 7A434 80089C34 0000D6E8 */  swc2       $22, 0x0($a2)
    /* 7A438 80089C38 0800E003 */  jr         $ra
    /* 7A43C 80089C3C 00000000 */   nop
endlabel func_80089C20
