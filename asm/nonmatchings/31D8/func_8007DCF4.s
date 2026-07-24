nonmatching func_8007DCF4, 0x5C

glabel func_8007DCF4
    /* 6E4F4 8007DCF4 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 6E4F8 8007DCF8 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 6E4FC 8007DCFC 21888000 */  addu       $s1, $a0, $zero
    /* 6E500 8007DD00 2120A000 */  addu       $a0, $a1, $zero
    /* 6E504 8007DD04 1000A527 */  addiu      $a1, $sp, 0x10
    /* 6E508 8007DD08 1800B0AF */  sw         $s0, 0x18($sp)
    /* 6E50C 8007DD0C 2000BFAF */  sw         $ra, 0x20($sp)
    /* 6E510 8007DD10 80F9010C */  jal        func_8007E600
    /* 6E514 8007DD14 2180C000 */   addu      $s0, $a2, $zero
    /* 6E518 8007DD18 1000A427 */  addiu      $a0, $sp, 0x10
    /* 6E51C 8007DD1C 21282002 */  addu       $a1, $s1, $zero
    /* 6E520 8007DD20 21300002 */  addu       $a2, $s0, $zero
    /* 6E524 8007DD24 78F3010C */  jal        func_8007CDE0
    /* 6E528 8007DD28 80000724 */   addiu     $a3, $zero, 0x80
  .L8007DD2C:
    /* 6E52C 8007DD2C 64F4010C */  jal        func_8007D190
    /* 6E530 8007DD30 21200000 */   addu      $a0, $zero, $zero
    /* 6E534 8007DD34 FDFF401C */  bgtz       $v0, .L8007DD2C
    /* 6E538 8007DD38 0100422C */   sltiu     $v0, $v0, 0x1
    /* 6E53C 8007DD3C 2000BF8F */  lw         $ra, 0x20($sp)
    /* 6E540 8007DD40 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 6E544 8007DD44 1800B08F */  lw         $s0, 0x18($sp)
    /* 6E548 8007DD48 0800E003 */  jr         $ra
    /* 6E54C 8007DD4C 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_8007DCF4
