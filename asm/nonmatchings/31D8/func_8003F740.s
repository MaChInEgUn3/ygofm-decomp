nonmatching func_8003F740, 0x18

glabel func_8003F740
    /* 2FF40 8003F740 00800234 */  ori        $v0, $zero, 0x8000
    /* 2FF44 8003F744 F20482A7 */  sh         $v0, %gp_rel(D_8009B3FA)($gp)
    /* 2FF48 8003F748 D60484A3 */  sb         $a0, %gp_rel(D_8009B3DE)($gp)
    /* 2FF4C 8003F74C B90480A3 */  sb         $zero, %gp_rel(D_8009B3C1)($gp)
    /* 2FF50 8003F750 0800E003 */  jr         $ra
    /* 2FF54 8003F754 00000000 */   nop
endlabel func_8003F740
