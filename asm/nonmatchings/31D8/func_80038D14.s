nonmatching func_80038D14, 0x18

glabel func_80038D14
    /* 29514 80038D14 04000224 */  addiu      $v0, $zero, 0x4
    /* 29518 80038D18 510082A0 */  sb         $v0, 0x51($a0)
    /* 2951C 80038D1C 01000224 */  addiu      $v0, $zero, 0x1
    /* 29520 80038D20 480482AF */  sw         $v0, %gp_rel(D_8009B350)($gp)
    /* 29524 80038D24 0800E003 */  jr         $ra
    /* 29528 80038D28 00000000 */   nop
endlabel func_80038D14
