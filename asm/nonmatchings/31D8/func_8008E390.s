nonmatching func_8008E390, 0x34

glabel func_8008E390
    /* 7EB90 8008E390 0A008010 */  beqz       $a0, .L8008E3BC
    /* 7EB94 8008E394 21100000 */   addu      $v0, $zero, $zero
    /* 7EB98 8008E398 0700C018 */  blez       $a2, .L8008E3B8
    /* 7EB9C 8008E39C 21188000 */   addu      $v1, $a0, $zero
  .L8008E3A0:
    /* 7EBA0 8008E3A0 0000A290 */  lbu        $v0, 0x0($a1)
    /* 7EBA4 8008E3A4 0100A524 */  addiu      $a1, $a1, 0x1
    /* 7EBA8 8008E3A8 FFFFC624 */  addiu      $a2, $a2, -0x1
    /* 7EBAC 8008E3AC 000082A0 */  sb         $v0, 0x0($a0)
    /* 7EBB0 8008E3B0 FBFFC01C */  bgtz       $a2, .L8008E3A0
    /* 7EBB4 8008E3B4 01008424 */   addiu     $a0, $a0, 0x1
  .L8008E3B8:
    /* 7EBB8 8008E3B8 21106000 */  addu       $v0, $v1, $zero
  .L8008E3BC:
    /* 7EBBC 8008E3BC 0800E003 */  jr         $ra
    /* 7EBC0 8008E3C0 00000000 */   nop
endlabel func_8008E390
    /* 7EBC4 8008E3C4 00000000 */  nop
    /* 7EBC8 8008E3C8 00000000 */  nop
    /* 7EBCC 8008E3CC 00000000 */  nop
