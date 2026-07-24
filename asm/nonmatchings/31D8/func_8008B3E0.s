nonmatching func_8008B3E0, 0x90

glabel func_8008B3E0
    /* 7BBE0 8008B3E0 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 7BBE4 8008B3E4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 7BBE8 8008B3E8 21808000 */  addu       $s0, $a0, $zero
    /* 7BBEC 8008B3EC 21200000 */  addu       $a0, $zero, $zero
    /* 7BBF0 8008B3F0 1800BFAF */  sw         $ra, 0x18($sp)
    /* 7BBF4 8008B3F4 50CE010C */  jal        func_80073940
    /* 7BBF8 8008B3F8 1400B1AF */   sw        $s1, 0x14($sp)
    /* 7BBFC 8008B3FC 5CD0010C */  jal        func_80074170
    /* 7BC00 8008B400 21200000 */   addu      $a0, $zero, $zero
    /* 7BC04 8008B404 2CCE010C */  jal        func_800738B0
    /* 7BC08 8008B408 00000000 */   nop
    /* 7BC0C 8008B40C 5FCF010C */  jal        func_80073D7C
    /* 7BC10 8008B410 21884000 */   addu      $s1, $v0, $zero
    /* 7BC14 8008B414 02004014 */  bnez       $v0, .L8008B420
    /* 7BC18 8008B418 00000000 */   nop
    /* 7BC1C 8008B41C 21800000 */  addu       $s0, $zero, $zero
  .L8008B420:
    /* 7BC20 8008B420 382D020C */  jal        func_8008B4E0
    /* 7BC24 8008B424 21200002 */   addu      $a0, $s0, $zero
    /* 7BC28 8008B428 BC2D020C */  jal        func_8008B6F0
    /* 7BC2C 8008B42C 00000000 */   nop
    /* 7BC30 8008B430 7B2D020C */  jal        func_8008B5EC
    /* 7BC34 8008B434 00000000 */   nop
    /* 7BC38 8008B438 A02D020C */  jal        func_8008B680
    /* 7BC3C 8008B43C 00000000 */   nop
    /* 7BC40 8008B440 442D020C */  jal        func_8008B510
    /* 7BC44 8008B444 00000000 */   nop
    /* 7BC48 8008B448 01000224 */  addiu      $v0, $zero, 0x1
    /* 7BC4C 8008B44C 03002216 */  bne        $s1, $v0, .L8008B45C
    /* 7BC50 8008B450 00000000 */   nop
    /* 7BC54 8008B454 30CE010C */  jal        func_800738C0
    /* 7BC58 8008B458 00000000 */   nop
  .L8008B45C:
    /* 7BC5C 8008B45C 1800BF8F */  lw         $ra, 0x18($sp)
    /* 7BC60 8008B460 1400B18F */  lw         $s1, 0x14($sp)
    /* 7BC64 8008B464 1000B08F */  lw         $s0, 0x10($sp)
    /* 7BC68 8008B468 0800E003 */  jr         $ra
    /* 7BC6C 8008B46C 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8008B3E0
