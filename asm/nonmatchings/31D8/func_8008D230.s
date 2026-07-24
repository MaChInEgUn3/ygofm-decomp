nonmatching func_8008D230, 0x14

glabel func_8008D230
    /* 7DA30 8008D230 01000224 */  addiu      $v0, $zero, 0x1
    /* 7DA34 8008D234 1080013C */  lui        $at, %hi(D_800FE428)
    /* 7DA38 8008D238 28E422AC */  sw         $v0, %lo(D_800FE428)($at)
    /* 7DA3C 8008D23C 0800E003 */  jr         $ra
    /* 7DA40 8008D240 21100000 */   addu      $v0, $zero, $zero
endlabel func_8008D230
