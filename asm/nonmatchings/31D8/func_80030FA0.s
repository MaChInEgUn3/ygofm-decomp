nonmatching func_80030FA0, 0x30

glabel func_80030FA0
    /* 217A0 80030FA0 0980023C */  lui        $v0, %hi(D_80090D68)
    /* 217A4 80030FA4 E9038383 */  lb         $v1, %gp_rel(D_8009B2F1)($gp)
    /* 217A8 80030FA8 680D4224 */  addiu      $v0, $v0, %lo(D_80090D68)
    /* 217AC 80030FAC 0A80013C */  lui        $at, %hi(D_8009B365)
    /* 217B0 80030FB0 65B320A0 */  sb         $zero, %lo(D_8009B365)($at)
    /* 217B4 80030FB4 21186200 */  addu       $v1, $v1, $v0
    /* 217B8 80030FB8 00006290 */  lbu        $v0, 0x0($v1)
    /* 217BC 80030FBC AA0380A3 */  sb         $zero, %gp_rel(D_8009B2B2)($gp)
    /* 217C0 80030FC0 0A80013C */  lui        $at, %hi(D_8009B26C)
    /* 217C4 80030FC4 6CB222A0 */  sb         $v0, %lo(D_8009B26C)($at)
    /* 217C8 80030FC8 0800E003 */  jr         $ra
    /* 217CC 80030FCC 00000000 */   nop
endlabel func_80030FA0
