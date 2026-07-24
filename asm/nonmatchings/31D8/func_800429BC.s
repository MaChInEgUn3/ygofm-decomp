nonmatching func_800429BC, 0x1C

glabel func_800429BC
    /* 331BC 800429BC 0100A290 */  lbu        $v0, 0x1($a1)
    /* 331C0 800429C0 0000A390 */  lbu        $v1, 0x0($a1)
    /* 331C4 800429C4 5400848C */  lw         $a0, 0x54($a0)
    /* 331C8 800429C8 00120200 */  sll        $v0, $v0, 8
    /* 331CC 800429CC 25104300 */  or         $v0, $v0, $v1
    /* 331D0 800429D0 0800E003 */  jr         $ra
    /* 331D4 800429D4 21108200 */   addu      $v0, $a0, $v0
endlabel func_800429BC
