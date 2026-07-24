nonmatching func_8006C30C, 0x24

glabel func_8006C30C
    /* 5CB0C 8006C30C 0000A290 */  lbu        $v0, 0x0($a1)
    /* 5CB10 8006C310 00000000 */  nop
    /* 5CB14 8006C314 000082A0 */  sb         $v0, 0x0($a0)
    /* 5CB18 8006C318 0100A290 */  lbu        $v0, 0x1($a1)
    /* 5CB1C 8006C31C 00000000 */  nop
    /* 5CB20 8006C320 010082A0 */  sb         $v0, 0x1($a0)
    /* 5CB24 8006C324 0200A290 */  lbu        $v0, 0x2($a1)
    /* 5CB28 8006C328 0800E003 */  jr         $ra
    /* 5CB2C 8006C32C 020082A0 */   sb        $v0, 0x2($a0)
endlabel func_8006C30C
