nonmatching func_8008D0D0, 0x10

glabel func_8008D0D0
    /* 7D8D0 8008D0D0 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 7D8D4 8008D0D4 0A80013C */  lui        $at, %hi(D_80099EA8)
    /* 7D8D8 8008D0D8 0800E003 */  jr         $ra
    /* 7D8DC 8008D0DC A89E22AC */   sw        $v0, %lo(D_80099EA8)($at)
endlabel func_8008D0D0
