nonmatching func_8007BEE0, 0xC

glabel func_8007BEE0
    /* 6C6E0 8007BEE0 0F80013C */  lui        $at, %hi(D_800F5F8C)
    /* 6C6E4 8007BEE4 0800E003 */  jr         $ra
    /* 6C6E8 8007BEE8 8C5F24AC */   sw        $a0, %lo(D_800F5F8C)($at)
endlabel func_8007BEE0
