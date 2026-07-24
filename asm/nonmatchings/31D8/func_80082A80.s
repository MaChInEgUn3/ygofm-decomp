nonmatching func_80082A80, 0x10

glabel func_80082A80
    /* 73280 80082A80 1080013C */  lui        $at, %hi(D_800FE000)
    /* 73284 80082A84 00E024AC */  sw         $a0, %lo(D_800FE000)($at)
    /* 73288 80082A88 0800E003 */  jr         $ra
    /* 7328C 80082A8C 21100000 */   addu      $v0, $zero, $zero
endlabel func_80082A80
