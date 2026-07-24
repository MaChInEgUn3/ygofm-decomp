nonmatching func_8008D1E0, 0x14

glabel func_8008D1E0
    /* 7D9E0 8008D1E0 01000224 */  addiu      $v0, $zero, 0x1
    /* 7D9E4 8008D1E4 1080013C */  lui        $at, %hi(D_800FE418)
    /* 7D9E8 8008D1E8 18E422AC */  sw         $v0, %lo(D_800FE418)($at)
    /* 7D9EC 8008D1EC 0800E003 */  jr         $ra
    /* 7D9F0 8008D1F0 21100000 */   addu      $v0, $zero, $zero
endlabel func_8008D1E0
