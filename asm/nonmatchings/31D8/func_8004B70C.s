nonmatching func_8004B70C, 0x28

glabel func_8004B70C
    /* 3BF0C 8004B70C FF008430 */  andi       $a0, $a0, 0xFF
    /* 3BF10 8004B710 40100400 */  sll        $v0, $a0, 1
    /* 3BF14 8004B714 21104400 */  addu       $v0, $v0, $a0
    /* 3BF18 8004B718 C0100200 */  sll        $v0, $v0, 3
    /* 3BF1C 8004B71C 0A80033C */  lui        $v1, %hi(D_8009B458)
    /* 3BF20 8004B720 58B4638C */  lw         $v1, %lo(D_8009B458)($v1)
    /* 3BF24 8004B724 7F00C630 */  andi       $a2, $a2, 0x7F
    /* 3BF28 8004B728 21186200 */  addu       $v1, $v1, $v0
    /* 3BF2C 8004B72C 0800E003 */  jr         $ra
    /* 3BF30 8004B730 070066A0 */   sb        $a2, 0x7($v1)
endlabel func_8004B70C
