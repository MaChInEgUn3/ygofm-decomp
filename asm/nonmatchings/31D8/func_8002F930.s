nonmatching func_8002F930, 0x1C

glabel func_8002F930
    /* 20130 8002F930 0C000224 */  addiu      $v0, $zero, 0xC
    /* 20134 8002F934 0A80013C */  lui        $at, %hi(D_8009B26C)
    /* 20138 8002F938 6CB222A0 */  sb         $v0, %lo(D_8009B26C)($at)
    /* 2013C 8002F93C 0A80013C */  lui        $at, %hi(D_8009B269)
    /* 20140 8002F940 69B222A0 */  sb         $v0, %lo(D_8009B269)($at)
    /* 20144 8002F944 0800E003 */  jr         $ra
    /* 20148 8002F948 00000000 */   nop
endlabel func_8002F930
