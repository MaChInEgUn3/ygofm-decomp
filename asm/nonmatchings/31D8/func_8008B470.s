nonmatching func_8008B470, 0x48

glabel func_8008B470
    /* 7BC70 8008B470 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 7BC74 8008B474 1400BFAF */  sw         $ra, 0x14($sp)
    /* 7BC78 8008B478 2CCE010C */  jal        func_800738B0
    /* 7BC7C 8008B47C 1000B0AF */   sw        $s0, 0x10($sp)
    /* 7BC80 8008B480 3C2D020C */  jal        func_8008B4F0
    /* 7BC84 8008B484 21804000 */   addu      $s0, $v0, $zero
    /* 7BC88 8008B488 50CE010C */  jal        func_80073940
    /* 7BC8C 8008B48C 21200000 */   addu      $a0, $zero, $zero
    /* 7BC90 8008B490 01000224 */  addiu      $v0, $zero, 0x1
    /* 7BC94 8008B494 04000216 */  bne        $s0, $v0, .L8008B4A8
    /* 7BC98 8008B498 21100000 */   addu      $v0, $zero, $zero
    /* 7BC9C 8008B49C 30CE010C */  jal        func_800738C0
    /* 7BCA0 8008B4A0 00000000 */   nop
    /* 7BCA4 8008B4A4 21100000 */  addu       $v0, $zero, $zero
  .L8008B4A8:
    /* 7BCA8 8008B4A8 1400BF8F */  lw         $ra, 0x14($sp)
    /* 7BCAC 8008B4AC 1000B08F */  lw         $s0, 0x10($sp)
    /* 7BCB0 8008B4B0 0800E003 */  jr         $ra
    /* 7BCB4 8008B4B4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8008B470
