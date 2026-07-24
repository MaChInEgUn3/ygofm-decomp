nonmatching func_8004BAA0, 0x44

glabel func_8004BAA0
    /* 3C2A0 8004BAA0 0A00C014 */  bnez       $a2, .L8004BACC
    /* 3C2A4 8004BAA4 FFFFC624 */   addiu     $a2, $a2, -0x1
    /* 3C2A8 8004BAA8 0800E003 */  jr         $ra
    /* 3C2AC 8004BAAC FFFF0224 */   addiu     $v0, $zero, -0x1
  .L8004BAB0:
    /* 3C2B0 8004BAB0 00008390 */  lbu        $v1, 0x0($a0)
    /* 3C2B4 8004BAB4 0000A290 */  lbu        $v0, 0x0($a1)
    /* 3C2B8 8004BAB8 00000000 */  nop
    /* 3C2BC 8004BABC 07006214 */  bne        $v1, $v0, .L8004BADC
    /* 3C2C0 8004BAC0 FFFFC624 */   addiu     $a2, $a2, -0x1
    /* 3C2C4 8004BAC4 01008424 */  addiu      $a0, $a0, 0x1
    /* 3C2C8 8004BAC8 0100A524 */  addiu      $a1, $a1, 0x1
  .L8004BACC:
    /* 3C2CC 8004BACC F8FFC014 */  bnez       $a2, .L8004BAB0
    /* 3C2D0 8004BAD0 00000000 */   nop
    /* 3C2D4 8004BAD4 00008390 */  lbu        $v1, 0x0($a0)
    /* 3C2D8 8004BAD8 0000A290 */  lbu        $v0, 0x0($a1)
  .L8004BADC:
    /* 3C2DC 8004BADC 0800E003 */  jr         $ra
    /* 3C2E0 8004BAE0 23106200 */   subu      $v0, $v1, $v0
endlabel func_8004BAA0
