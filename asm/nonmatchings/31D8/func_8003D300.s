nonmatching func_8003D300, 0x2C

glabel func_8003D300
    /* 2DB00 8003D300 0F80023C */  lui        $v0, %hi(D_800EF6E0)
    /* 2DB04 8003D304 01000324 */  addiu      $v1, $zero, 0x1
    /* 2DB08 8003D308 E0F643A0 */  sb         $v1, %lo(D_800EF6E0)($v0)
    /* 2DB0C 8003D30C 00800234 */  ori        $v0, $zero, 0x8000
    /* 2DB10 8003D310 C70480A3 */  sb         $zero, %gp_rel(D_8009B3CF)($gp)
    /* 2DB14 8003D314 B90480A3 */  sb         $zero, %gp_rel(D_8009B3C1)($gp)
    /* 2DB18 8003D318 C40482A7 */  sh         $v0, %gp_rel(D_8009B3CC)($gp)
    /* 2DB1C 8003D31C D50480A3 */  sb         $zero, %gp_rel(D_8009B3DD)($gp)
    /* 2DB20 8003D320 BF0484A3 */  sb         $a0, %gp_rel(D_8009B3C7)($gp)
    /* 2DB24 8003D324 0800E003 */  jr         $ra
    /* 2DB28 8003D328 00000000 */   nop
endlabel func_8003D300
