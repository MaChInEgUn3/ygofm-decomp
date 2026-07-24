nonmatching func_8002F94C, 0x1C

glabel func_8002F94C
    /* 2014C 8002F94C 0F000224 */  addiu      $v0, $zero, 0xF
    /* 20150 8002F950 0A80013C */  lui        $at, %hi(D_8009B26C)
    /* 20154 8002F954 6CB222A0 */  sb         $v0, %lo(D_8009B26C)($at)
    /* 20158 8002F958 0A80013C */  lui        $at, %hi(D_8009B269)
    /* 2015C 8002F95C 69B222A0 */  sb         $v0, %lo(D_8009B269)($at)
    /* 20160 8002F960 0800E003 */  jr         $ra
    /* 20164 8002F964 00000000 */   nop
endlabel func_8002F94C
