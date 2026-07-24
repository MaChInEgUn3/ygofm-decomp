nonmatching func_8003A198, 0x54

glabel func_8003A198
    /* 2A998 8003A198 40280500 */  sll        $a1, $a1, 1
    /* 2A99C 8003A19C 21288500 */  addu       $a1, $a0, $a1
    /* 2A9A0 8003A1A0 0000A294 */  lhu        $v0, 0x0($a1)
    /* 2A9A4 8003A1A4 00000000 */  nop
    /* 2A9A8 8003A1A8 0D004010 */  beqz       $v0, .L8003A1E0
    /* 2A9AC 8003A1AC 21108200 */   addu      $v0, $a0, $v0
    /* 2A9B0 8003A1B0 40180600 */  sll        $v1, $a2, 1
    /* 2A9B4 8003A1B4 21284300 */  addu       $a1, $v0, $v1
    /* 2A9B8 8003A1B8 0000A294 */  lhu        $v0, 0x0($a1)
    /* 2A9BC 8003A1BC 00000000 */  nop
    /* 2A9C0 8003A1C0 07004010 */  beqz       $v0, .L8003A1E0
    /* 2A9C4 8003A1C4 21108200 */   addu      $v0, $a0, $v0
    /* 2A9C8 8003A1C8 40180700 */  sll        $v1, $a3, 1
    /* 2A9CC 8003A1CC 21284300 */  addu       $a1, $v0, $v1
    /* 2A9D0 8003A1D0 0000A394 */  lhu        $v1, 0x0($a1)
    /* 2A9D4 8003A1D4 00000000 */  nop
    /* 2A9D8 8003A1D8 02006014 */  bnez       $v1, .L8003A1E4
    /* 2A9DC 8003A1DC 01000224 */   addiu     $v0, $zero, 0x1
  .L8003A1E0:
    /* 2A9E0 8003A1E0 21100000 */  addu       $v0, $zero, $zero
  .L8003A1E4:
    /* 2A9E4 8003A1E4 0800E003 */  jr         $ra
    /* 2A9E8 8003A1E8 00000000 */   nop
endlabel func_8003A198
