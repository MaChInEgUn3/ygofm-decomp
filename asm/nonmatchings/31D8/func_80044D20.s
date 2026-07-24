nonmatching func_80044D20, 0x14

glabel func_80044D20
    /* 35520 80044D20 0A80033C */  lui        $v1, %hi(D_8009B450)
    /* 35524 80044D24 02000224 */  addiu      $v0, $zero, 0x2
    /* 35528 80044D28 50B462AC */  sw         $v0, %lo(D_8009B450)($v1)
    /* 3552C 80044D2C 0800E003 */  jr         $ra
    /* 35530 80044D30 21100000 */   addu      $v0, $zero, $zero
endlabel func_80044D20
