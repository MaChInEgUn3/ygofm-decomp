nonmatching func_80075A90, 0x28

glabel func_80075A90
    /* 66290 80075A90 0980043C */  lui        $a0, %hi(D_80092B9C)
    /* 66294 80075A94 9C2B848C */  lw         $a0, %lo(D_80092B9C)($a0)
    /* 66298 80075A98 FFF0033C */  lui        $v1, (0xF0FFFFFF >> 16)
    /* 6629C 80075A9C 0000828C */  lw         $v0, 0x0($a0)
    /* 662A0 80075AA0 FFFF6334 */  ori        $v1, $v1, (0xF0FFFFFF & 0xFFFF)
    /* 662A4 80075AA4 24104300 */  and        $v0, $v0, $v1
    /* 662A8 80075AA8 0022033C */  lui        $v1, (0x22000000 >> 16)
    /* 662AC 80075AAC 25104300 */  or         $v0, $v0, $v1
    /* 662B0 80075AB0 0800E003 */  jr         $ra
    /* 662B4 80075AB4 000082AC */   sw        $v0, 0x0($a0)
endlabel func_80075A90
