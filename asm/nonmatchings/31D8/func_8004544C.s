nonmatching func_8004544C, 0x10

glabel func_8004544C
    /* 35C4C 8004544C 0A80023C */  lui        $v0, %hi(D_8009B45C)
    /* 35C50 80045450 5CB4428C */  lw         $v0, %lo(D_8009B45C)($v0)
    /* 35C54 80045454 0800E003 */  jr         $ra
    /* 35C58 80045458 181640A0 */   sb        $zero, 0x1618($v0)
endlabel func_8004544C
