nonmatching func_8007BEC8, 0xC

glabel func_8007BEC8
    /* 6C6C8 8007BEC8 0F80013C */  lui        $at, %hi(D_800F5F84)
    /* 6C6CC 8007BECC 0800E003 */  jr         $ra
    /* 6C6D0 8007BED0 845F24AC */   sw        $a0, %lo(D_800F5F84)($at)
endlabel func_8007BEC8
