nonmatching func_800495EC, 0x14

glabel func_800495EC
    /* 39DEC 800495EC 0A80033C */  lui        $v1, %hi(D_8009B458)
    /* 39DF0 800495F0 58B4638C */  lw         $v1, %lo(D_8009B458)($v1)
    /* 39DF4 800495F4 01000224 */  addiu      $v0, $zero, 0x1
    /* 39DF8 800495F8 0800E003 */  jr         $ra
    /* 39DFC 800495FC 150862A0 */   sb        $v0, 0x815($v1)
endlabel func_800495EC
