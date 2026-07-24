nonmatching func_80073464, 0x10

glabel func_80073464
    /* 63C64 80073464 0F80033C */  lui        $v1, %hi(D_800F5C7F)
    /* 63C68 80073468 01000224 */  addiu      $v0, $zero, 0x1
    /* 63C6C 8007346C 0800E003 */  jr         $ra
    /* 63C70 80073470 7F5C62A0 */   sb        $v0, %lo(D_800F5C7F)($v1)
endlabel func_80073464
