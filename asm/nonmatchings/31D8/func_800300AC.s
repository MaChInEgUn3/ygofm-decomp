nonmatching func_800300AC, 0x1C

glabel func_800300AC
    /* 208AC 800300AC 0F80023C */  lui        $v0, %hi(D_800EB184)
    /* 208B0 800300B0 84B1438C */  lw         $v1, %lo(D_800EB184)($v0)
    /* 208B4 800300B4 80000224 */  addiu      $v0, $zero, 0x80
    /* 208B8 800300B8 0E0062A0 */  sb         $v0, 0xE($v1)
    /* 208BC 800300BC 0D0062A0 */  sb         $v0, 0xD($v1)
    /* 208C0 800300C0 0800E003 */  jr         $ra
    /* 208C4 800300C4 0C0062A0 */   sb        $v0, 0xC($v1)
endlabel func_800300AC
