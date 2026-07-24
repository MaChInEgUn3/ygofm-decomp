nonmatching func_8005B85C, 0x44

glabel func_8005B85C
    /* 4C05C 8005B85C D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 4C060 8005B860 0680023C */  lui        $v0, %hi(func_8005B64C)
    /* 4C064 8005B864 4CB64224 */  addiu      $v0, $v0, %lo(func_8005B64C)
    /* 4C068 8005B868 0180053C */  lui        $a1, %hi(D_800117C8)
    /* 4C06C 8005B86C 01000424 */  addiu      $a0, $zero, 0x1
    /* 4C070 8005B870 C817A524 */  addiu      $a1, $a1, %lo(D_800117C8)
    /* 4C074 8005B874 21300000 */  addu       $a2, $zero, $zero
    /* 4C078 8005B878 73000724 */  addiu      $a3, $zero, 0x73
    /* 4C07C 8005B87C 2000BFAF */  sw         $ra, 0x20($sp)
    /* 4C080 8005B880 1000A2AF */  sw         $v0, 0x10($sp)
    /* 4C084 8005B884 1400A0AF */  sw         $zero, 0x14($sp)
    /* 4C088 8005B888 8753000C */  jal        func_80014E1C
    /* 4C08C 8005B88C 1800A0AF */   sw        $zero, 0x18($sp)
    /* 4C090 8005B890 2000BF8F */  lw         $ra, 0x20($sp)
    /* 4C094 8005B894 00000000 */  nop
    /* 4C098 8005B898 0800E003 */  jr         $ra
    /* 4C09C 8005B89C 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_8005B85C
