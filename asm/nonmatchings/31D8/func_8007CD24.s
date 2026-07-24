nonmatching func_8007CD24, 0x48

glabel func_8007CD24
    /* 6D524 8007CD24 0C00A010 */  beqz       $a1, .L8007CD58
    /* 6D528 8007CD28 00000000 */   nop
    /* 6D52C 8007CD2C 0D008010 */  beqz       $a0, .L8007CD64
    /* 6D530 8007CD30 21180000 */   addu      $v1, $zero, $zero
  .L8007CD34:
    /* 6D534 8007CD34 0000A290 */  lbu        $v0, 0x0($a1)
    /* 6D538 8007CD38 0100A524 */  addiu      $a1, $a1, 0x1
    /* 6D53C 8007CD3C 01006324 */  addiu      $v1, $v1, 0x1
    /* 6D540 8007CD40 000082A0 */  sb         $v0, 0x0($a0)
    /* 6D544 8007CD44 04006228 */  slti       $v0, $v1, 0x4
    /* 6D548 8007CD48 FAFF4014 */  bnez       $v0, .L8007CD34
    /* 6D54C 8007CD4C 01008424 */   addiu     $a0, $a0, 0x1
    /* 6D550 8007CD50 59F30108 */  j          .L8007CD64
    /* 6D554 8007CD54 00000000 */   nop
  .L8007CD58:
    /* 6D558 8007CD58 02008010 */  beqz       $a0, .L8007CD64
    /* 6D55C 8007CD5C 00000000 */   nop
    /* 6D560 8007CD60 000080A0 */  sb         $zero, 0x0($a0)
  .L8007CD64:
    /* 6D564 8007CD64 0800E003 */  jr         $ra
    /* 6D568 8007CD68 00000000 */   nop
endlabel func_8007CD24
