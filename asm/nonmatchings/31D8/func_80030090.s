nonmatching func_80030090, 0x1C

glabel func_80030090
    /* 20890 80030090 0F80023C */  lui        $v0, %hi(D_800EB184)
    /* 20894 80030094 84B1438C */  lw         $v1, %lo(D_800EB184)($v0)
    /* 20898 80030098 40000224 */  addiu      $v0, $zero, 0x40
    /* 2089C 8003009C 0E0062A0 */  sb         $v0, 0xE($v1)
    /* 208A0 800300A0 0D0062A0 */  sb         $v0, 0xD($v1)
    /* 208A4 800300A4 0800E003 */  jr         $ra
    /* 208A8 800300A8 0C0062A0 */   sb        $v0, 0xC($v1)
endlabel func_80030090
