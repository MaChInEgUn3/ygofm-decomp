nonmatching func_800429A8, 0x14

glabel func_800429A8
    /* 331A8 800429A8 01008290 */  lbu        $v0, 0x1($a0)
    /* 331AC 800429AC 00008390 */  lbu        $v1, 0x0($a0)
    /* 331B0 800429B0 00120200 */  sll        $v0, $v0, 8
    /* 331B4 800429B4 0800E003 */  jr         $ra
    /* 331B8 800429B8 25104300 */   or        $v0, $v0, $v1
endlabel func_800429A8
