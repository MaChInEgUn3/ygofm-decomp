nonmatching func_8008E320, 0x34

glabel func_8008E320
    /* 7EB20 8008E320 0A008010 */  beqz       $a0, .L8008E34C
    /* 7EB24 8008E324 21100000 */   addu      $v0, $zero, $zero
    /* 7EB28 8008E328 0700C018 */  blez       $a2, .L8008E348
    /* 7EB2C 8008E32C 21188000 */   addu      $v1, $a0, $zero
  .L8008E330:
    /* 7EB30 8008E330 00008290 */  lbu        $v0, 0x0($a0)
    /* 7EB34 8008E334 01008424 */  addiu      $a0, $a0, 0x1
    /* 7EB38 8008E338 FFFFC624 */  addiu      $a2, $a2, -0x1
    /* 7EB3C 8008E33C 0000A2A0 */  sb         $v0, 0x0($a1)
    /* 7EB40 8008E340 FBFFC01C */  bgtz       $a2, .L8008E330
    /* 7EB44 8008E344 0100A524 */   addiu     $a1, $a1, 0x1
  .L8008E348:
    /* 7EB48 8008E348 21106000 */  addu       $v0, $v1, $zero
  .L8008E34C:
    /* 7EB4C 8008E34C 0800E003 */  jr         $ra
    /* 7EB50 8008E350 00000000 */   nop
endlabel func_8008E320
    /* 7EB54 8008E354 00000000 */  nop
    /* 7EB58 8008E358 00000000 */  nop
    /* 7EB5C 8008E35C 00000000 */  nop
