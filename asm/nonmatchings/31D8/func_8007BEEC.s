nonmatching func_8007BEEC, 0x18

glabel func_8007BEEC
    /* 6C6EC 8007BEEC 80200400 */  sll        $a0, $a0, 2
    /* 6C6F0 8007BEF0 0980023C */  lui        $v0, %hi(D_800938A0)
    /* 6C6F4 8007BEF4 21104400 */  addu       $v0, $v0, $a0
    /* 6C6F8 8007BEF8 A038428C */  lw         $v0, %lo(D_800938A0)($v0)
    /* 6C6FC 8007BEFC 0800E003 */  jr         $ra
    /* 6C700 8007BF00 00000000 */   nop
endlabel func_8007BEEC
