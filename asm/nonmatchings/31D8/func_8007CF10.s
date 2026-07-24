nonmatching func_8007CF10, 0x34

glabel func_8007CF10
    /* 6D710 8007CF10 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 6D714 8007CF14 FF008430 */  andi       $a0, $a0, 0xFF
    /* 6D718 8007CF18 02000224 */  addiu      $v0, $zero, 0x2
    /* 6D71C 8007CF1C 05008214 */  bne        $a0, $v0, .L8007CF34
    /* 6D720 8007CF20 1000BFAF */   sw        $ra, 0x10($sp)
    /* 6D724 8007CF24 0880043C */  lui        $a0, %hi(func_8007CF44)
    /* 6D728 8007CF28 44CF8424 */  addiu      $a0, $a0, %lo(func_8007CF44)
    /* 6D72C 8007CF2C 54F7010C */  jal        func_8007DD50
    /* 6D730 8007CF30 FFFF0524 */   addiu     $a1, $zero, -0x1
  .L8007CF34:
    /* 6D734 8007CF34 1000BF8F */  lw         $ra, 0x10($sp)
    /* 6D738 8007CF38 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 6D73C 8007CF3C 0800E003 */  jr         $ra
    /* 6D740 8007CF40 00000000 */   nop
endlabel func_8007CF10
