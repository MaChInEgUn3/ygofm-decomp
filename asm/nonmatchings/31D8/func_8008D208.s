nonmatching func_8008D208, 0x14

glabel func_8008D208
    /* 7DA08 8008D208 01000224 */  addiu      $v0, $zero, 0x1
    /* 7DA0C 8008D20C 1080013C */  lui        $at, %hi(D_800FE420)
    /* 7DA10 8008D210 20E422AC */  sw         $v0, %lo(D_800FE420)($at)
    /* 7DA14 8008D214 0800E003 */  jr         $ra
    /* 7DA18 8008D218 21100000 */   addu      $v0, $zero, $zero
endlabel func_8008D208
