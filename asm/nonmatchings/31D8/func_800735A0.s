nonmatching func_800735A0, 0x3C

glabel func_800735A0
    /* 63DA0 800735A0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 63DA4 800735A4 1400BFAF */  sw         $ra, 0x14($sp)
    /* 63DA8 800735A8 6BC1010C */  jal        func_800705AC
    /* 63DAC 800735AC 1000B0AF */   sw        $s0, 0x10($sp)
    /* 63DB0 800735B0 63C1010C */  jal        func_8007058C
    /* 63DB4 800735B4 21804000 */   addu      $s0, $v0, $zero
    /* 63DB8 800735B8 0F80033C */  lui        $v1, %hi(D_800F5B98)
    /* 63DBC 800735BC 985B6324 */  addiu      $v1, $v1, %lo(D_800F5B98)
    /* 63DC0 800735C0 80100200 */  sll        $v0, $v0, 2
    /* 63DC4 800735C4 21104300 */  addu       $v0, $v0, $v1
    /* 63DC8 800735C8 000050AC */  sw         $s0, 0x0($v0)
    /* 63DCC 800735CC 1400BF8F */  lw         $ra, 0x14($sp)
    /* 63DD0 800735D0 1000B08F */  lw         $s0, 0x10($sp)
    /* 63DD4 800735D4 0800E003 */  jr         $ra
    /* 63DD8 800735D8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800735A0
