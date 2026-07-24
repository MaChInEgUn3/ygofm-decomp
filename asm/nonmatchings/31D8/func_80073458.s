nonmatching func_80073458, 0xC

glabel func_80073458
    /* 63C58 80073458 0F80023C */  lui        $v0, %hi(D_800EAE90)
    /* 63C5C 8007345C 0800E003 */  jr         $ra
    /* 63C60 80073460 90AE40A0 */   sb        $zero, %lo(D_800EAE90)($v0)
endlabel func_80073458
