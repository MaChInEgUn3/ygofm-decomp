nonmatching func_80080AD0, 0x1C

glabel func_80080AD0
    /* 712D0 80080AD0 FF07A530 */  andi       $a1, $a1, 0x7FF
    /* 712D4 80080AD4 C02A0500 */  sll        $a1, $a1, 11
    /* 712D8 80080AD8 FF078230 */  andi       $v0, $a0, 0x7FF
    /* 712DC 80080ADC 00E5033C */  lui        $v1, (0xE5000000 >> 16)
    /* 712E0 80080AE0 25104300 */  or         $v0, $v0, $v1
    /* 712E4 80080AE4 0800E003 */  jr         $ra
    /* 712E8 80080AE8 2510A200 */   or        $v0, $a1, $v0
endlabel func_80080AD0
