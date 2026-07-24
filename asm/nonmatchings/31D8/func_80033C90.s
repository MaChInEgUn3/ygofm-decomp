nonmatching func_80033C90, 0x18

glabel func_80033C90
    /* 24490 80033C90 07000224 */  addiu      $v0, $zero, 0x7
    /* 24494 80033C94 F00380A3 */  sb         $zero, %gp_rel(D_8009B2F8)($gp)
    /* 24498 80033C98 0A80013C */  lui        $at, %hi(D_8009B26C)
    /* 2449C 80033C9C 6CB222A0 */  sb         $v0, %lo(D_8009B26C)($at)
    /* 244A0 80033CA0 0800E003 */  jr         $ra
    /* 244A4 80033CA4 00000000 */   nop
endlabel func_80033C90
