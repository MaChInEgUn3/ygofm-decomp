nonmatching func_8008D1F4, 0x14

glabel func_8008D1F4
    /* 7D9F4 8008D1F4 01000224 */  addiu      $v0, $zero, 0x1
    /* 7D9F8 8008D1F8 1080013C */  lui        $at, %hi(D_800FE41C)
    /* 7D9FC 8008D1FC 1CE422AC */  sw         $v0, %lo(D_800FE41C)($at)
    /* 7DA00 8008D200 0800E003 */  jr         $ra
    /* 7DA04 8008D204 21100000 */   addu      $v0, $zero, $zero
endlabel func_8008D1F4
