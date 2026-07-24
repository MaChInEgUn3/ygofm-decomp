nonmatching func_8004B6E8, 0x24

glabel func_8004B6E8
    /* 3BEE8 8004B6E8 FF008430 */  andi       $a0, $a0, 0xFF
    /* 3BEEC 8004B6EC 40100400 */  sll        $v0, $a0, 1
    /* 3BEF0 8004B6F0 21104400 */  addu       $v0, $v0, $a0
    /* 3BEF4 8004B6F4 0A80033C */  lui        $v1, %hi(D_8009B458)
    /* 3BEF8 8004B6F8 58B4638C */  lw         $v1, %lo(D_8009B458)($v1)
    /* 3BEFC 8004B6FC C0100200 */  sll        $v0, $v0, 3
    /* 3BF00 8004B700 21186200 */  addu       $v1, $v1, $v0
    /* 3BF04 8004B704 0800E003 */  jr         $ra
    /* 3BF08 8004B708 000065A0 */   sb        $a1, 0x0($v1)
endlabel func_8004B6E8
