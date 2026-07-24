nonmatching func_8008D244, 0x14

glabel func_8008D244
    /* 7DA44 8008D244 01000224 */  addiu      $v0, $zero, 0x1
    /* 7DA48 8008D248 1080013C */  lui        $at, %hi(D_800FE42C)
    /* 7DA4C 8008D24C 2CE422AC */  sw         $v0, %lo(D_800FE42C)($at)
    /* 7DA50 8008D250 0800E003 */  jr         $ra
    /* 7DA54 8008D254 21100000 */   addu      $v0, $zero, $zero
endlabel func_8008D244
