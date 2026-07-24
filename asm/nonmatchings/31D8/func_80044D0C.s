nonmatching func_80044D0C, 0x14

glabel func_80044D0C
    /* 3550C 80044D0C 0A80033C */  lui        $v1, %hi(D_8009B450)
    /* 35510 80044D10 01000224 */  addiu      $v0, $zero, 0x1
    /* 35514 80044D14 50B462AC */  sw         $v0, %lo(D_8009B450)($v1)
    /* 35518 80044D18 0800E003 */  jr         $ra
    /* 3551C 80044D1C 21100000 */   addu      $v0, $zero, $zero
endlabel func_80044D0C
