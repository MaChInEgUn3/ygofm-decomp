nonmatching func_8008CCD4, 0x14

glabel func_8008CCD4
    /* 7D4D4 8008CCD4 1080033C */  lui        $v1, %hi(D_800FE38C)
    /* 7D4D8 8008CCD8 8CE36324 */  addiu      $v1, $v1, %lo(D_800FE38C)
    /* 7D4DC 8008CCDC 0000628C */  lw         $v0, 0x0($v1)
    /* 7D4E0 8008CCE0 0800E003 */  jr         $ra
    /* 7D4E4 8008CCE4 000064AC */   sw        $a0, 0x0($v1)
endlabel func_8008CCD4
