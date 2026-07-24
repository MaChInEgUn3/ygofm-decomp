nonmatching func_80033CA8, 0x1C

glabel func_80033CA8
    /* 244A8 80033CA8 80000224 */  addiu      $v0, $zero, 0x80
    /* 244AC 80033CAC F00382A3 */  sb         $v0, %gp_rel(D_8009B2F8)($gp)
    /* 244B0 80033CB0 07000224 */  addiu      $v0, $zero, 0x7
    /* 244B4 80033CB4 0A80013C */  lui        $at, %hi(D_8009B26C)
    /* 244B8 80033CB8 6CB222A0 */  sb         $v0, %lo(D_8009B26C)($at)
    /* 244BC 80033CBC 0800E003 */  jr         $ra
    /* 244C0 80033CC0 00000000 */   nop
endlabel func_80033CA8
