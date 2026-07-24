nonmatching func_8002EB48, 0x30

glabel func_8002EB48
    /* 1F348 8002EB48 8803828F */  lw         $v0, %gp_rel(D_8009B290)($gp)
    /* 1F34C 8002EB4C 00000000 */  nop
    /* 1F350 8002EB50 00004390 */  lbu        $v1, 0x0($v0)
    /* 1F354 8002EB54 01004224 */  addiu      $v0, $v0, 0x1
    /* 1F358 8002EB58 880382AF */  sw         $v0, %gp_rel(D_8009B290)($gp)
    /* 1F35C 8002EB5C 05000224 */  addiu      $v0, $zero, 0x5
    /* 1F360 8002EB60 0A80013C */  lui        $at, %hi(D_8009B26C)
    /* 1F364 8002EB64 6CB222A0 */  sb         $v0, %lo(D_8009B26C)($at)
    /* 1F368 8002EB68 0A80013C */  lui        $at, %hi(D_8009B363)
    /* 1F36C 8002EB6C 63B323A0 */  sb         $v1, %lo(D_8009B363)($at)
    /* 1F370 8002EB70 0800E003 */  jr         $ra
    /* 1F374 8002EB74 00000000 */   nop
endlabel func_8002EB48
