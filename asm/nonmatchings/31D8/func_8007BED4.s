nonmatching func_8007BED4, 0xC

glabel func_8007BED4
    /* 6C6D4 8007BED4 0F80013C */  lui        $at, %hi(D_800F5F88)
    /* 6C6D8 8007BED8 0800E003 */  jr         $ra
    /* 6C6DC 8007BEDC 885F24AC */   sw        $a0, %lo(D_800F5F88)($at)
endlabel func_8007BED4
