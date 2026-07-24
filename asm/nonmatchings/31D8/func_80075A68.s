nonmatching func_80075A68, 0x28

glabel func_80075A68
    /* 66268 80075A68 0980043C */  lui        $a0, %hi(D_80092B9C)
    /* 6626C 80075A6C 9C2B848C */  lw         $a0, %lo(D_80092B9C)($a0)
    /* 66270 80075A70 FFF0033C */  lui        $v1, (0xF0FFFFFF >> 16)
    /* 66274 80075A74 0000828C */  lw         $v0, 0x0($a0)
    /* 66278 80075A78 FFFF6334 */  ori        $v1, $v1, (0xF0FFFFFF & 0xFFFF)
    /* 6627C 80075A7C 24104300 */  and        $v0, $v0, $v1
    /* 66280 80075A80 0020033C */  lui        $v1, (0x20000000 >> 16)
    /* 66284 80075A84 25104300 */  or         $v0, $v0, $v1
    /* 66288 80075A88 0800E003 */  jr         $ra
    /* 6628C 80075A8C 000082AC */   sw        $v0, 0x0($a0)
endlabel func_80075A68
