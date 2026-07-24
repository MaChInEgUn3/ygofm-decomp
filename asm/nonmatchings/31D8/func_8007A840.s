nonmatching func_8007A840, 0x14

glabel func_8007A840
    /* 6B040 8007A840 0980023C */  lui        $v0, %hi(D_800934E4)
    /* 6B044 8007A844 E434428C */  lw         $v0, %lo(D_800934E4)($v0)
    /* 6B048 8007A848 0980013C */  lui        $at, %hi(D_800934E4)
    /* 6B04C 8007A84C 0800E003 */  jr         $ra
    /* 6B050 8007A850 E43424AC */   sw        $a0, %lo(D_800934E4)($at)
endlabel func_8007A840
    /* 6B054 8007A854 00000000 */  nop
    /* 6B058 8007A858 00000000 */  nop
    /* 6B05C 8007A85C 00000000 */  nop
