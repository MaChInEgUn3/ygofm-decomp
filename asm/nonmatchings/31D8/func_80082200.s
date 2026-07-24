nonmatching func_80082200, 0x28

glabel func_80082200
    /* 72A00 80082200 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 72A04 80082204 1000BFAF */  sw         $ra, 0x10($sp)
    /* 72A08 80082208 0880053C */  lui        $a1, %hi(func_800816F8)
    /* 72A0C 8008220C F816A524 */  addiu      $a1, $a1, %lo(func_800816F8)
    /* 72A10 80082210 FCD0010C */  jal        func_800743F0
    /* 72A14 80082214 02000424 */   addiu     $a0, $zero, 0x2
    /* 72A18 80082218 1000BF8F */  lw         $ra, 0x10($sp)
    /* 72A1C 8008221C 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 72A20 80082220 0800E003 */  jr         $ra
    /* 72A24 80082224 00000000 */   nop
endlabel func_80082200
