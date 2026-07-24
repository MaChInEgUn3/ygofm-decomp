nonmatching func_8008A420, 0x80

glabel func_8008A420
    /* 7AC20 8008A420 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 7AC24 8008A424 1000B0AF */  sw         $s0, 0x10($sp)
    /* 7AC28 8008A428 1400BFAF */  sw         $ra, 0x14($sp)
    /* 7AC2C 8008A42C 4E28020C */  jal        func_8008A138
    /* 7AC30 8008A430 21808000 */   addu      $s0, $a0, $zero
    /* 7AC34 8008A434 0000448C */  lw         $a0, 0x0($v0)
    /* 7AC38 8008A438 21280000 */  addu       $a1, $zero, $zero
    /* 7AC3C 8008A43C 80180400 */  sll        $v1, $a0, 2
    /* 7AC40 8008A440 21186200 */  addu       $v1, $v1, $v0
    /* 7AC44 8008A444 0000638C */  lw         $v1, 0x0($v1)
    /* 7AC48 8008A448 FFFF8424 */  addiu      $a0, $a0, -0x1
    /* 7AC4C 8008A44C 000044AC */  sw         $a0, 0x0($v0)
    /* 7AC50 8008A450 0000668C */  lw         $a2, 0x0($v1)
    /* 7AC54 8008A454 00000000 */  nop
    /* 7AC58 8008A458 0C00C018 */  blez       $a2, .L8008A48C
    /* 7AC5C 8008A45C 04006324 */   addiu     $v1, $v1, 0x4
    /* 7AC60 8008A460 4C006424 */  addiu      $a0, $v1, 0x4C
  .L8008A464:
    /* 7AC64 8008A464 0000828C */  lw         $v0, 0x0($a0)
    /* 7AC68 8008A468 00000000 */  nop
    /* 7AC6C 8008A46C 03004010 */  beqz       $v0, .L8008A47C
    /* 7AC70 8008A470 80100200 */   sll       $v0, $v0, 2
    /* 7AC74 8008A474 21100202 */  addu       $v0, $s0, $v0
    /* 7AC78 8008A478 000082AC */  sw         $v0, 0x0($a0)
  .L8008A47C:
    /* 7AC7C 8008A47C 0100A524 */  addiu      $a1, $a1, 0x1
    /* 7AC80 8008A480 2A10A600 */  slt        $v0, $a1, $a2
    /* 7AC84 8008A484 F7FF4014 */  bnez       $v0, .L8008A464
    /* 7AC88 8008A488 50008424 */   addiu     $a0, $a0, 0x50
  .L8008A48C:
    /* 7AC8C 8008A48C 21106000 */  addu       $v0, $v1, $zero
    /* 7AC90 8008A490 1400BF8F */  lw         $ra, 0x14($sp)
    /* 7AC94 8008A494 1000B08F */  lw         $s0, 0x10($sp)
    /* 7AC98 8008A498 0800E003 */  jr         $ra
    /* 7AC9C 8008A49C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8008A420
