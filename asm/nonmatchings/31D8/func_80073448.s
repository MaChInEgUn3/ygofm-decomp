nonmatching func_80073448, 0x10

glabel func_80073448
    /* 63C48 80073448 0F80033C */  lui        $v1, %hi(D_800EAE90)
    /* 63C4C 8007344C 01000224 */  addiu      $v0, $zero, 0x1
    /* 63C50 80073450 0800E003 */  jr         $ra
    /* 63C54 80073454 90AE62A0 */   sb        $v0, %lo(D_800EAE90)($v1)
endlabel func_80073448
