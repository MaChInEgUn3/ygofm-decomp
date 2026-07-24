nonmatching func_8004BB34, 0x88

glabel func_8004BB34
    /* 3C334 8004BB34 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 3C338 8004BB38 1400B1AF */  sw         $s1, 0x14($sp)
    /* 3C33C 8004BB3C 21888000 */  addu       $s1, $a0, $zero
    /* 3C340 8004BB40 1800BFAF */  sw         $ra, 0x18($sp)
    /* 3C344 8004BB44 B92E010C */  jal        func_8004BAE4
    /* 3C348 8004BB48 1000B0AF */   sw        $s0, 0x10($sp)
    /* 3C34C 8004BB4C 21204000 */  addu       $a0, $v0, $zero
    /* 3C350 8004BB50 15008010 */  beqz       $a0, .L8004BBA8
    /* 3C354 8004BB54 21100000 */   addu      $v0, $zero, $zero
    /* 3C358 8004BB58 FF000224 */  addiu      $v0, $zero, 0xFF
    /* 3C35C 8004BB5C 05008214 */  bne        $a0, $v0, .L8004BB74
    /* 3C360 8004BB60 21808000 */   addu      $s0, $a0, $zero
    /* 3C364 8004BB64 01000224 */  addiu      $v0, $zero, 0x1
    /* 3C368 8004BB68 240022A2 */  sb         $v0, 0x24($s1)
    /* 3C36C 8004BB6C EA2E0108 */  j          .L8004BBA8
    /* 3C370 8004BB70 21100000 */   addu      $v0, $zero, $zero
  .L8004BB74:
    /* 3C374 8004BB74 80000232 */  andi       $v0, $s0, 0x80
    /* 3C378 8004BB78 0B004010 */  beqz       $v0, .L8004BBA8
    /* 3C37C 8004BB7C 21100002 */   addu      $v0, $s0, $zero
    /* 3C380 8004BB80 7F001032 */  andi       $s0, $s0, 0x7F
  .L8004BB84:
    /* 3C384 8004BB84 B92E010C */  jal        func_8004BAE4
    /* 3C388 8004BB88 21202002 */   addu      $a0, $s1, $zero
    /* 3C38C 8004BB8C 21204000 */  addu       $a0, $v0, $zero
    /* 3C390 8004BB90 C0111000 */  sll        $v0, $s0, 7
    /* 3C394 8004BB94 7F008330 */  andi       $v1, $a0, 0x7F
    /* 3C398 8004BB98 21804300 */  addu       $s0, $v0, $v1
    /* 3C39C 8004BB9C 80008230 */  andi       $v0, $a0, 0x80
    /* 3C3A0 8004BBA0 F8FF4014 */  bnez       $v0, .L8004BB84
    /* 3C3A4 8004BBA4 21100002 */   addu      $v0, $s0, $zero
  .L8004BBA8:
    /* 3C3A8 8004BBA8 1800BF8F */  lw         $ra, 0x18($sp)
    /* 3C3AC 8004BBAC 1400B18F */  lw         $s1, 0x14($sp)
    /* 3C3B0 8004BBB0 1000B08F */  lw         $s0, 0x10($sp)
    /* 3C3B4 8004BBB4 0800E003 */  jr         $ra
    /* 3C3B8 8004BBB8 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8004BB34
