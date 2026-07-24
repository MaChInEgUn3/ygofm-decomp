nonmatching func_80029EB0, 0x14

glabel func_80029EB0
    /* 1A6B0 80029EB0 80280500 */  sll        $a1, $a1, 2
    /* 1A6B4 80029EB4 21208500 */  addu       $a0, $a0, $a1
    /* 1A6B8 80029EB8 56008290 */  lbu        $v0, 0x56($a0)
    /* 1A6BC 80029EBC 0800E003 */  jr         $ra
    /* 1A6C0 80029EC0 00000000 */   nop
endlabel func_80029EB0
