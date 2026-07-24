nonmatching func_8002E00C, 0x54

glabel func_8002E00C
    /* 1E80C 8002E00C E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 1E810 8002E010 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1E814 8002E014 21808000 */  addu       $s0, $a0, $zero
    /* 1E818 8002E018 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 1E81C 8002E01C 1400B1AF */  sw         $s1, 0x14($sp)
    /* 1E820 8002E020 21880000 */  addu       $s1, $zero, $zero
    /* 1E824 8002E024 1800BFAF */  sw         $ra, 0x18($sp)
    /* 1E828 8002E028 3C0002A6 */  sh         $v0, 0x3C($s0)
  .L8002E02C:
    /* 1E82C 8002E02C 0000048E */  lw         $a0, 0x0($s0)
    /* 1E830 8002E030 DB00010C */  jal        func_8004036C
    /* 1E834 8002E034 01003126 */   addiu     $s1, $s1, 0x1
    /* 1E838 8002E038 000000AE */  sw         $zero, 0x0($s0)
    /* 1E83C 8002E03C 040000A6 */  sh         $zero, 0x4($s0)
    /* 1E840 8002E040 0300222A */  slti       $v0, $s1, 0x3
    /* 1E844 8002E044 F9FF4014 */  bnez       $v0, .L8002E02C
    /* 1E848 8002E048 14001026 */   addiu     $s0, $s0, 0x14
    /* 1E84C 8002E04C 1800BF8F */  lw         $ra, 0x18($sp)
    /* 1E850 8002E050 1400B18F */  lw         $s1, 0x14($sp)
    /* 1E854 8002E054 1000B08F */  lw         $s0, 0x10($sp)
    /* 1E858 8002E058 0800E003 */  jr         $ra
    /* 1E85C 8002E05C 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8002E00C
