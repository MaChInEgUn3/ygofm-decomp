nonmatching func_80028220, 0x40

glabel func_80028220
    /* 18A20 80028220 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 18A24 80028224 1000B0AF */  sw         $s0, 0x10($sp)
    /* 18A28 80028228 1B80103C */  lui        $s0, %hi(D_801AB00C)
    /* 18A2C 8002822C 0CB01026 */  addiu      $s0, $s0, %lo(D_801AB00C)
    /* 18A30 80028230 CD028593 */  lbu        $a1, %gp_rel(D_8009B1D5)($gp)
    /* 18A34 80028234 1400BFAF */  sw         $ra, 0x14($sp)
    /* 18A38 80028238 7E9F000C */  jal        func_80027DF8
    /* 18A3C 8002823C 21200002 */   addu      $a0, $s0, $zero
    /* 18A40 80028240 CD028593 */  lbu        $a1, %gp_rel(D_8009B1D5)($gp)
    /* 18A44 80028244 94020426 */  addiu      $a0, $s0, 0x294
    /* 18A48 80028248 7E9F000C */  jal        func_80027DF8
    /* 18A4C 8002824C 0100A538 */   xori      $a1, $a1, 0x1
    /* 18A50 80028250 1400BF8F */  lw         $ra, 0x14($sp)
    /* 18A54 80028254 1000B08F */  lw         $s0, 0x10($sp)
    /* 18A58 80028258 0800E003 */  jr         $ra
    /* 18A5C 8002825C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80028220
