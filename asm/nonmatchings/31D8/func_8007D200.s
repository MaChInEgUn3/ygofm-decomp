nonmatching func_8007D200, 0x14

glabel func_8007D200
    /* 6DA00 8007D200 0980023C */  lui        $v0, %hi(D_800939FC)
    /* 6DA04 8007D204 FC39428C */  lw         $v0, %lo(D_800939FC)($v0)
    /* 6DA08 8007D208 0980013C */  lui        $at, %hi(D_800939FC)
    /* 6DA0C 8007D20C 0800E003 */  jr         $ra
    /* 6DA10 8007D210 FC3924AC */   sw        $a0, %lo(D_800939FC)($at)
endlabel func_8007D200
