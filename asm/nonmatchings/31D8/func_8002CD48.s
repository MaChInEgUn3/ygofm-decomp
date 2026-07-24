nonmatching func_8002CD48, 0x44

glabel func_8002CD48
    /* 1D548 8002CD48 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 1D54C 8002CD4C 1400B1AF */  sw         $s1, 0x14($sp)
    /* 1D550 8002CD50 21888000 */  addu       $s1, $a0, $zero
    /* 1D554 8002CD54 1800BFAF */  sw         $ra, 0x18($sp)
    /* 1D558 8002CD58 2AB3000C */  jal        func_8002CCA8
    /* 1D55C 8002CD5C 1000B0AF */   sw        $s0, 0x10($sp)
    /* 1D560 8002CD60 21804000 */  addu       $s0, $v0, $zero
    /* 1D564 8002CD64 04000016 */  bnez       $s0, .L8002CD78
    /* 1D568 8002CD68 21100002 */   addu      $v0, $s0, $zero
    /* 1D56C 8002CD6C 39B3000C */  jal        func_8002CCE4
    /* 1D570 8002CD70 21202002 */   addu      $a0, $s1, $zero
    /* 1D574 8002CD74 21100002 */  addu       $v0, $s0, $zero
  .L8002CD78:
    /* 1D578 8002CD78 1800BF8F */  lw         $ra, 0x18($sp)
    /* 1D57C 8002CD7C 1400B18F */  lw         $s1, 0x14($sp)
    /* 1D580 8002CD80 1000B08F */  lw         $s0, 0x10($sp)
    /* 1D584 8002CD84 0800E003 */  jr         $ra
    /* 1D588 8002CD88 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8002CD48
