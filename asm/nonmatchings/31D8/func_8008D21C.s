nonmatching func_8008D21C, 0x14

glabel func_8008D21C
    /* 7DA1C 8008D21C 01000224 */  addiu      $v0, $zero, 0x1
    /* 7DA20 8008D220 1080013C */  lui        $at, %hi(D_800FE424)
    /* 7DA24 8008D224 24E422AC */  sw         $v0, %lo(D_800FE424)($at)
    /* 7DA28 8008D228 0800E003 */  jr         $ra
    /* 7DA2C 8008D22C 21100000 */   addu      $v0, $zero, $zero
endlabel func_8008D21C
