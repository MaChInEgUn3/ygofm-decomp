nonmatching func_80015998, 0x40

glabel func_80015998
    /* 6198 80015998 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 619C 8001599C 0F80023C */  lui        $v0, %hi(D_800E9EC8)
    /* 61A0 800159A0 1000B0AF */  sw         $s0, 0x10($sp)
    /* 61A4 800159A4 C89E5024 */  addiu      $s0, $v0, %lo(D_800E9EC8)
    /* 61A8 800159A8 1400BFAF */  sw         $ra, 0x14($sp)
  .L800159AC:
    /* 61AC 800159AC 534B000C */  jal        func_80012D4C
    /* 61B0 800159B0 00000000 */   nop
    /* 61B4 800159B4 06000292 */  lbu        $v0, 0x6($s0)
    /* 61B8 800159B8 00000000 */  nop
    /* 61BC 800159BC 80004230 */  andi       $v0, $v0, 0x80
    /* 61C0 800159C0 FAFF4014 */  bnez       $v0, .L800159AC
    /* 61C4 800159C4 00000000 */   nop
    /* 61C8 800159C8 1400BF8F */  lw         $ra, 0x14($sp)
    /* 61CC 800159CC 1000B08F */  lw         $s0, 0x10($sp)
    /* 61D0 800159D0 0800E003 */  jr         $ra
    /* 61D4 800159D4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80015998
