nonmatching func_8008D258, 0x14

glabel func_8008D258
    /* 7DA58 8008D258 01000224 */  addiu      $v0, $zero, 0x1
    /* 7DA5C 8008D25C 1080013C */  lui        $at, %hi(D_800FE430)
    /* 7DA60 8008D260 30E422AC */  sw         $v0, %lo(D_800FE430)($at)
    /* 7DA64 8008D264 0800E003 */  jr         $ra
    /* 7DA68 8008D268 21100000 */   addu      $v0, $zero, $zero
endlabel func_8008D258
