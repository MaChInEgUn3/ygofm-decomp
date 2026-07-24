nonmatching func_8008FBE0, 0x34

glabel func_8008FBE0
    /* 803E0 8008FBE0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 803E4 8008FBE4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 803E8 8008FBE8 21808000 */  addu       $s0, $a0, $zero
    /* 803EC 8008FBEC 03000016 */  bnez       $s0, .L8008FBFC
    /* 803F0 8008FBF0 1400BFAF */   sw        $ra, 0x14($sp)
    /* 803F4 8008FBF4 E4D0010C */  jal        func_80074390
    /* 803F8 8008FBF8 00000000 */   nop
  .L8008FBFC:
    /* 803FC 8008FBFC A83F020C */  jal        func_8008FEA0
    /* 80400 8008FC00 21200002 */   addu      $a0, $s0, $zero
    /* 80404 8008FC04 1400BF8F */  lw         $ra, 0x14($sp)
    /* 80408 8008FC08 1000B08F */  lw         $s0, 0x10($sp)
    /* 8040C 8008FC0C 0800E003 */  jr         $ra
    /* 80410 8008FC10 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8008FBE0
