nonmatching func_8008B2F0, 0x40

glabel func_8008B2F0
    /* 7BAF0 8008B2F0 2110A000 */  addu       $v0, $a1, $zero
    /* 7BAF4 8008B2F4 0000898C */  lw         $t1, 0x0($a0)
    /* 7BAF8 8008B2F8 04008A8C */  lw         $t2, 0x4($a0)
    /* 7BAFC 8008B2FC 0400A9AC */  sw         $t1, 0x4($a1)
    /* 7BB00 8008B300 0000AAAC */  sw         $t2, 0x0($a1)
    /* 7BB04 8008B304 0000A9A4 */  sh         $t1, 0x0($a1)
    /* 7BB08 8008B308 08008B8C */  lw         $t3, 0x8($a0)
    /* 7BB0C 8008B30C 0C00898C */  lw         $t1, 0xC($a0)
    /* 7BB10 8008B310 0C00ABAC */  sw         $t3, 0xC($a1)
    /* 7BB14 8008B314 0800A9AC */  sw         $t1, 0x8($a1)
    /* 7BB18 8008B318 0C00AAA4 */  sh         $t2, 0xC($a1)
    /* 7BB1C 8008B31C 0800ABA4 */  sh         $t3, 0x8($a1)
    /* 7BB20 8008B320 10008A84 */  lh         $t2, 0x10($a0)
    /* 7BB24 8008B324 0400A9A4 */  sh         $t1, 0x4($a1)
    /* 7BB28 8008B328 0800E003 */  jr         $ra
    /* 7BB2C 8008B32C 1000AAA4 */   sh        $t2, 0x10($a1)
endlabel func_8008B2F0
