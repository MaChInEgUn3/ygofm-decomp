nonmatching func_8008FB50, 0x3C

glabel func_8008FB50
    /* 80350 8008FB50 00009FAC */  sw         $ra, 0x0($a0)
    /* 80354 8008FB54 2C009CAC */  sw         $gp, 0x2C($a0)
    /* 80358 8008FB58 04009DAC */  sw         $sp, 0x4($a0)
    /* 8035C 8008FB5C 08009EAC */  sw         $fp, 0x8($a0)
    /* 80360 8008FB60 0C0090AC */  sw         $s0, 0xC($a0)
    /* 80364 8008FB64 100091AC */  sw         $s1, 0x10($a0)
    /* 80368 8008FB68 140092AC */  sw         $s2, 0x14($a0)
    /* 8036C 8008FB6C 180093AC */  sw         $s3, 0x18($a0)
    /* 80370 8008FB70 1C0094AC */  sw         $s4, 0x1C($a0)
    /* 80374 8008FB74 200095AC */  sw         $s5, 0x20($a0)
    /* 80378 8008FB78 240096AC */  sw         $s6, 0x24($a0)
    /* 8037C 8008FB7C 280097AC */  sw         $s7, 0x28($a0)
    /* 80380 8008FB80 21100000 */  addu       $v0, $zero, $zero
    /* 80384 8008FB84 0800E003 */  jr         $ra
    /* 80388 8008FB88 00000000 */   nop
endlabel func_8008FB50
