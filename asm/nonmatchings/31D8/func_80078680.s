nonmatching func_80078680, 0x1C

glabel func_80078680
    /* 68E80 80078680 0F80013C */  lui        $at, %hi(D_800F5D70)
    /* 68E84 80078684 705D24AC */  sw         $a0, %lo(D_800F5D70)($at)
    /* 68E88 80078688 0F80013C */  lui        $at, %hi(D_800F5D4C)
    /* 68E8C 8007868C 4C5D25AC */  sw         $a1, %lo(D_800F5D4C)($at)
    /* 68E90 80078690 0F80013C */  lui        $at, %hi(D_800F5D6C)
    /* 68E94 80078694 0800E003 */  jr         $ra
    /* 68E98 80078698 6C5D26AC */   sw        $a2, %lo(D_800F5D6C)($at)
endlabel func_80078680
    /* 68E9C 8007869C 00000000 */  nop
