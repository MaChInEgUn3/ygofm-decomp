nonmatching func_80044D34, 0x14

glabel func_80044D34
    /* 35534 80044D34 0A80033C */  lui        $v1, %hi(D_8009B450)
    /* 35538 80044D38 03000224 */  addiu      $v0, $zero, 0x3
    /* 3553C 80044D3C 50B462AC */  sw         $v0, %lo(D_8009B450)($v1)
    /* 35540 80044D40 0800E003 */  jr         $ra
    /* 35544 80044D44 21100000 */   addu      $v0, $zero, $zero
endlabel func_80044D34
