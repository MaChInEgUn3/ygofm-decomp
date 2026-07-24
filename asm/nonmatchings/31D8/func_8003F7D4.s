nonmatching func_8003F7D4, 0x3C

glabel func_8003F7D4
    /* 2FFD4 8003F7D4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2FFD8 8003F7D8 1D80043C */  lui        $a0, %hi(D_801D3200)
    /* 2FFDC 8003F7DC 0180063C */  lui        $a2, %hi(D_80010384)
    /* 2FFE0 8003F7E0 00328424 */  addiu      $a0, $a0, %lo(D_801D3200)
    /* 2FFE4 8003F7E4 80060524 */  addiu      $a1, $zero, 0x680
    /* 2FFE8 8003F7E8 8403C624 */  addiu      $a2, $a2, %lo(D_80010384)
    /* 2FFEC 8003F7EC 1000BFAF */  sw         $ra, 0x10($sp)
    /* 2FFF0 8003F7F0 0A80013C */  lui        $at, %hi(D_8009B0D1)
    /* 2FFF4 8003F7F4 D1B020A0 */  sb         $zero, %lo(D_8009B0D1)($at)
    /* 2FFF8 8003F7F8 D6FD000C */  jal        func_8003F758
    /* 2FFFC 8003F7FC 21380000 */   addu      $a3, $zero, $zero
    /* 30000 8003F800 1000BF8F */  lw         $ra, 0x10($sp)
    /* 30004 8003F804 00000000 */  nop
    /* 30008 8003F808 0800E003 */  jr         $ra
    /* 3000C 8003F80C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8003F7D4
