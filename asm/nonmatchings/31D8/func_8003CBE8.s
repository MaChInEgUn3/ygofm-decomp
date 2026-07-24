nonmatching func_8003CBE8, 0x50

glabel func_8003CBE8
    /* 2D3E8 8003CBE8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2D3EC 8003CBEC 0F80043C */  lui        $a0, %hi(D_800EF668)
    /* 2D3F0 8003CBF0 68F68424 */  addiu      $a0, $a0, %lo(D_800EF668)
    /* 2D3F4 8003CBF4 22000524 */  addiu      $a1, $zero, 0x22
    /* 2D3F8 8003CBF8 21308500 */  addu       $a2, $a0, $a1
    /* 2D3FC 8003CBFC 1000BFAF */  sw         $ra, 0x10($sp)
    /* 2D400 8003CC00 87CF010C */  jal        func_80073E1C
    /* 2D404 8003CC04 2138A000 */   addu      $a3, $a1, $zero
    /* 2D408 8003CC08 ABCF010C */  jal        func_80073EAC
    /* 2D40C 8003CC0C 00000000 */   nop
    /* 2D410 8003CC10 18000224 */  addiu      $v0, $zero, 0x18
    /* 2D414 8003CC14 940482A3 */  sb         $v0, %gp_rel(D_8009B39C)($gp)
    /* 2D418 8003CC18 14000224 */  addiu      $v0, $zero, 0x14
    /* 2D41C 8003CC1C 9A0482A3 */  sb         $v0, %gp_rel(D_8009B3A2)($gp)
    /* 2D420 8003CC20 DFF2000C */  jal        func_8003CB7C
    /* 2D424 8003CC24 00000000 */   nop
    /* 2D428 8003CC28 1000BF8F */  lw         $ra, 0x10($sp)
    /* 2D42C 8003CC2C 00000000 */  nop
    /* 2D430 8003CC30 0800E003 */  jr         $ra
    /* 2D434 8003CC34 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8003CBE8
