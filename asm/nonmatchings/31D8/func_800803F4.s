nonmatching func_800803F4, 0x34

glabel func_800803F4
    /* 70BF4 800803F4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 70BF8 800803F8 1000B0AF */  sw         $s0, 0x10($sp)
    /* 70BFC 800803FC 21808000 */  addu       $s0, $a0, $zero
    /* 70C00 80080400 0980053C */  lui        $a1, %hi(D_800946D4)
    /* 70C04 80080404 D446A524 */  addiu      $a1, $a1, %lo(D_800946D4)
    /* 70C08 80080408 1400BFAF */  sw         $ra, 0x14($sp)
    /* 70C0C 8008040C E438020C */  jal        func_8008E390
    /* 70C10 80080410 14000624 */   addiu     $a2, $zero, 0x14
    /* 70C14 80080414 21100002 */  addu       $v0, $s0, $zero
    /* 70C18 80080418 1400BF8F */  lw         $ra, 0x14($sp)
    /* 70C1C 8008041C 1000B08F */  lw         $s0, 0x10($sp)
    /* 70C20 80080420 0800E003 */  jr         $ra
    /* 70C24 80080424 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800803F4
