nonmatching func_80030250, 0x44

glabel func_80030250
    /* 20A50 80030250 1000A28F */  lw         $v0, 0x10($sp)
    /* 20A54 80030254 1400A38F */  lw         $v1, 0x14($sp)
    /* 20A58 80030258 1800A88F */  lw         $t0, 0x18($sp)
    /* 20A5C 8003025C E20380A3 */  sb         $zero, %gp_rel(D_8009B2EA)($gp)
    /* 20A60 80030260 E40384AF */  sw         $a0, %gp_rel(D_8009B2EC)($gp)
    /* 20A64 80030264 AC0385A3 */  sb         $a1, %gp_rel(D_8009B2B4)($gp)
    /* 20A68 80030268 AD0386A3 */  sb         $a2, %gp_rel(D_8009B2B5)($gp)
    /* 20A6C 8003026C AE0387A3 */  sb         $a3, %gp_rel(D_8009B2B6)($gp)
    /* 20A70 80030270 E10380A3 */  sb         $zero, %gp_rel(D_8009B2E9)($gp)
    /* 20A74 80030274 D40380A3 */  sb         $zero, %gp_rel(D_8009B2DC)($gp)
    /* 20A78 80030278 B00382A3 */  sb         $v0, %gp_rel(D_8009B2B8)($gp)
    /* 20A7C 8003027C BA0383A3 */  sb         $v1, %gp_rel(D_8009B2C2)($gp)
    /* 20A80 80030280 B90383A3 */  sb         $v1, %gp_rel(D_8009B2C1)($gp)
    /* 20A84 80030284 B80383A3 */  sb         $v1, %gp_rel(D_8009B2C0)($gp)
    /* 20A88 80030288 D80388A3 */  sb         $t0, %gp_rel(D_8009B2E0)($gp)
    /* 20A8C 8003028C 0800E003 */  jr         $ra
    /* 20A90 80030290 00000000 */   nop
endlabel func_80030250
