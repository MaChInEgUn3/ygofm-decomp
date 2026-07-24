nonmatching func_8008B2D4, 0x1C

glabel func_8008B2D4
    /* 7BAD4 8008B2D4 04008018 */  blez       $a0, .L8008B2E8
    /* 7BAD8 8008B2D8 21100000 */   addu      $v0, $zero, $zero
  .L8008B2DC:
    /* 7BADC 8008B2DC 43200400 */  sra        $a0, $a0, 1
    /* 7BAE0 8008B2E0 FEFF801C */  bgtz       $a0, .L8008B2DC
    /* 7BAE4 8008B2E4 01004224 */   addiu     $v0, $v0, 0x1
  .L8008B2E8:
    /* 7BAE8 8008B2E8 0800E003 */  jr         $ra
    /* 7BAEC 8008B2EC 00000000 */   nop
endlabel func_8008B2D4
