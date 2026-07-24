nonmatching func_8008E680, 0x64

glabel func_8008E680
    /* 7EE80 8008E680 03008010 */  beqz       $a0, .L8008E690
    /* 7EE84 8008E684 00000000 */   nop
    /* 7EE88 8008E688 0B00A014 */  bnez       $a1, .L8008E6B8
    /* 7EE8C 8008E68C 00000000 */   nop
  .L8008E690:
    /* 7EE90 8008E690 12008510 */  beq        $a0, $a1, .L8008E6DC
    /* 7EE94 8008E694 21100000 */   addu      $v0, $zero, $zero
    /* 7EE98 8008E698 10008010 */  beqz       $a0, .L8008E6DC
    /* 7EE9C 8008E69C FFFF0224 */   addiu     $v0, $zero, -0x1
    /* 7EEA0 8008E6A0 B7390208 */  j          .L8008E6DC
    /* 7EEA4 8008E6A4 01000224 */   addiu     $v0, $zero, 0x1
  .L8008E6A8:
    /* 7EEA8 8008E6A8 B7390208 */  j          .L8008E6DC
    /* 7EEAC 8008E6AC 21100000 */   addu      $v0, $zero, $zero
  .L8008E6B0:
    /* 7EEB0 8008E6B0 FDFFC010 */  beqz       $a2, .L8008E6A8
    /* 7EEB4 8008E6B4 01008424 */   addiu     $a0, $a0, 0x1
  .L8008E6B8:
    /* 7EEB8 8008E6B8 0000A380 */  lb         $v1, 0x0($a1)
    /* 7EEBC 8008E6BC 00008280 */  lb         $v0, 0x0($a0)
    /* 7EEC0 8008E6C0 00008690 */  lbu        $a2, 0x0($a0)
    /* 7EEC4 8008E6C4 FAFF4310 */  beq        $v0, $v1, .L8008E6B0
    /* 7EEC8 8008E6C8 0100A524 */   addiu     $a1, $a1, 0x1
    /* 7EECC 8008E6CC 00008380 */  lb         $v1, 0x0($a0)
    /* 7EED0 8008E6D0 FFFFA280 */  lb         $v0, -0x1($a1)
    /* 7EED4 8008E6D4 00000000 */  nop
    /* 7EED8 8008E6D8 23106200 */  subu       $v0, $v1, $v0
  .L8008E6DC:
    /* 7EEDC 8008E6DC 0800E003 */  jr         $ra
    /* 7EEE0 8008E6E0 00000000 */   nop
endlabel func_8008E680
    /* 7EEE4 8008E6E4 00000000 */  nop
    /* 7EEE8 8008E6E8 00000000 */  nop
    /* 7EEEC 8008E6EC 00000000 */  nop
