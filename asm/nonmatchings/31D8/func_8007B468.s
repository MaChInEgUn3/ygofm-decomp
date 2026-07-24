nonmatching func_8007B468, 0x34

glabel func_8007B468
    /* 6BC68 8007B468 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 6BC6C 8007B46C 01000224 */  addiu      $v0, $zero, 0x1
    /* 6BC70 8007B470 FF008430 */  andi       $a0, $a0, 0xFF
    /* 6BC74 8007B474 3000A38F */  lw         $v1, 0x30($sp)
    /* 6BC78 8007B478 FF00C630 */  andi       $a2, $a2, 0xFF
    /* 6BC7C 8007B47C 1800BFAF */  sw         $ra, 0x18($sp)
    /* 6BC80 8007B480 1400A2AF */  sw         $v0, 0x14($sp)
    /* 6BC84 8007B484 27ED010C */  jal        func_8007B49C
    /* 6BC88 8007B488 1000A3AF */   sw        $v1, 0x10($sp)
    /* 6BC8C 8007B48C 1800BF8F */  lw         $ra, 0x18($sp)
    /* 6BC90 8007B490 2000BD27 */  addiu      $sp, $sp, 0x20
    /* 6BC94 8007B494 0800E003 */  jr         $ra
    /* 6BC98 8007B498 00000000 */   nop
endlabel func_8007B468
