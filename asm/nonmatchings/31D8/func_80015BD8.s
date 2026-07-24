nonmatching func_80015BD8, 0x18

glabel func_80015BD8
    /* 63D8 80015BD8 0F80023C */  lui        $v0, %hi(D_800E9EC8)
    /* 63DC 80015BDC C89E4224 */  addiu      $v0, $v0, %lo(D_800E9EC8)
    /* 63E0 80015BE0 8000A534 */  ori        $a1, $a1, 0x80
    /* 63E4 80015BE4 050044A0 */  sb         $a0, 0x5($v0)
    /* 63E8 80015BE8 0800E003 */  jr         $ra
    /* 63EC 80015BEC 060045A0 */   sb        $a1, 0x6($v0)
endlabel func_80015BD8
