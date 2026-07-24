nonmatching func_8007BEBC, 0xC

glabel func_8007BEBC
    /* 6C6BC 8007BEBC 0F80013C */  lui        $at, %hi(D_800F5F80)
    /* 6C6C0 8007BEC0 0800E003 */  jr         $ra
    /* 6C6C4 8007BEC4 805F24AC */   sw        $a0, %lo(D_800F5F80)($at)
endlabel func_8007BEBC
