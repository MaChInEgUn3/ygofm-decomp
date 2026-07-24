nonmatching func_8008FAF0, 0x54

glabel func_8008FAF0
    /* 802F0 8008FAF0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 802F4 8008FAF4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 802F8 8008FAF8 21808000 */  addu       $s0, $a0, $zero
    /* 802FC 8008FAFC 06000016 */  bnez       $s0, .L8008FB18
    /* 80300 8008FB00 1400BFAF */   sw        $ra, 0x14($sp)
    /* 80304 8008FB04 0180103C */  lui        $s0, %hi(D_80012978)
    /* 80308 8008FB08 C63E0208 */  j          .L8008FB18
    /* 8030C 8008FB0C 78291026 */   addiu     $s0, $s0, %lo(D_80012978)
  .L8008FB10:
    /* 80310 8008FB10 E83B020C */  jal        func_8008EFA0
    /* 80314 8008FB14 03260400 */   sra       $a0, $a0, 24
  .L8008FB18:
    /* 80318 8008FB18 00000492 */  lbu        $a0, 0x0($s0)
    /* 8031C 8008FB1C 00000000 */  nop
    /* 80320 8008FB20 00260400 */  sll        $a0, $a0, 24
    /* 80324 8008FB24 FAFF8014 */  bnez       $a0, .L8008FB10
    /* 80328 8008FB28 01001026 */   addiu     $s0, $s0, 0x1
    /* 8032C 8008FB2C 273C020C */  jal        func_8008F09C
    /* 80330 8008FB30 00000000 */   nop
    /* 80334 8008FB34 1400BF8F */  lw         $ra, 0x14($sp)
    /* 80338 8008FB38 1000B08F */  lw         $s0, 0x10($sp)
    /* 8033C 8008FB3C 0800E003 */  jr         $ra
    /* 80340 8008FB40 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8008FAF0
    /* 80344 8008FB44 00000000 */  nop
    /* 80348 8008FB48 00000000 */  nop
    /* 8034C 8008FB4C 00000000 */  nop
