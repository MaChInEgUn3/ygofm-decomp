nonmatching func_8003BBF8, 0x48

glabel func_8003BBF8
    /* 2C3F8 8003BBF8 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 2C3FC 8003BBFC 0480023C */  lui        $v0, %hi(func_8003BA14)
    /* 2C400 8003BC00 14BA4224 */  addiu      $v0, $v0, %lo(func_8003BA14)
    /* 2C404 8003BC04 21200000 */  addu       $a0, $zero, $zero
    /* 2C408 8003BC08 21288000 */  addu       $a1, $a0, $zero
    /* 2C40C 8003BC0C DF1E0624 */  addiu      $a2, $zero, 0x1EDF
    /* 2C410 8003BC10 50000724 */  addiu      $a3, $zero, 0x50
    /* 2C414 8003BC14 2000BFAF */  sw         $ra, 0x20($sp)
    /* 2C418 8003BC18 1000A2AF */  sw         $v0, 0x10($sp)
    /* 2C41C 8003BC1C 1400A0AF */  sw         $zero, 0x14($sp)
    /* 2C420 8003BC20 8753000C */  jal        func_80014E1C
    /* 2C424 8003BC24 1800A0AF */   sw        $zero, 0x18($sp)
    /* 2C428 8003BC28 F94D000C */  jal        func_800137E4
    /* 2C42C 8003BC2C 00000000 */   nop
    /* 2C430 8003BC30 2000BF8F */  lw         $ra, 0x20($sp)
    /* 2C434 8003BC34 00000000 */  nop
    /* 2C438 8003BC38 0800E003 */  jr         $ra
    /* 2C43C 8003BC3C 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_8003BBF8
