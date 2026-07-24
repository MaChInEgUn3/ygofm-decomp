nonmatching func_8007A860, 0x24

glabel func_8007A860
    /* 6B060 8007A860 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 6B064 8007A864 1000BFAF */  sw         $ra, 0x10($sp)
    /* 6B068 8007A868 21288000 */  addu       $a1, $a0, $zero
    /* 6B06C 8007A86C FCD0010C */  jal        func_800743F0
    /* 6B070 8007A870 03000424 */   addiu     $a0, $zero, 0x3
    /* 6B074 8007A874 1000BF8F */  lw         $ra, 0x10($sp)
    /* 6B078 8007A878 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 6B07C 8007A87C 0800E003 */  jr         $ra
    /* 6B080 8007A880 00000000 */   nop
endlabel func_8007A860
    /* 6B084 8007A884 00000000 */  nop
    /* 6B088 8007A888 00000000 */  nop
    /* 6B08C 8007A88C 00000000 */  nop
