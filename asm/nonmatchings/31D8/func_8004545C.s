nonmatching func_8004545C, 0x28

glabel func_8004545C
    /* 35C5C 8004545C 0A80033C */  lui        $v1, %hi(D_8009B45C)
    /* 35C60 80045460 5CB4638C */  lw         $v1, %lo(D_8009B45C)($v1)
    /* 35C64 80045464 01000224 */  addiu      $v0, $zero, 0x1
    /* 35C68 80045468 181662A0 */  sb         $v0, 0x1618($v1)
    /* 35C6C 8004546C 0480023C */  lui        $v0, %hi(func_8004544C)
    /* 35C70 80045470 4C544224 */  addiu      $v0, $v0, %lo(func_8004544C)
    /* 35C74 80045474 0A80013C */  lui        $at, %hi(D_8009B128)
    /* 35C78 80045478 28B122AC */  sw         $v0, %lo(D_8009B128)($at)
    /* 35C7C 8004547C 0800E003 */  jr         $ra
    /* 35C80 80045480 00000000 */   nop
endlabel func_8004545C
