nonmatching func_800495DC, 0x10

glabel func_800495DC
    /* 39DDC 800495DC 0A80023C */  lui        $v0, %hi(D_8009B458)
    /* 39DE0 800495E0 58B4428C */  lw         $v0, %lo(D_8009B458)($v0)
    /* 39DE4 800495E4 0800E003 */  jr         $ra
    /* 39DE8 800495E8 150840A0 */   sb        $zero, 0x815($v0)
endlabel func_800495DC
