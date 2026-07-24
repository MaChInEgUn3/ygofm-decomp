nonmatching func_8002E370, 0x44

glabel func_8002E370
    /* 1EB70 8002E370 02000524 */  addiu      $a1, $zero, 0x2
    /* 1EB74 8002E374 0F80023C */  lui        $v0, %hi(D_800EB010)
    /* 1EB78 8002E378 10B04224 */  addiu      $v0, $v0, %lo(D_800EB010)
    /* 1EB7C 8002E37C 98004324 */  addiu      $v1, $v0, 0x98
  .L8002E380:
    /* 1EB80 8002E380 30006280 */  lb         $v0, 0x30($v1)
    /* 1EB84 8002E384 00000000 */  nop
    /* 1EB88 8002E388 06004004 */  bltz       $v0, .L8002E3A4
    /* 1EB8C 8002E38C FFFFA524 */   addiu     $a1, $a1, -0x1
    /* 1EB90 8002E390 34008294 */  lhu        $v0, 0x34($a0)
    /* 1EB94 8002E394 00000000 */  nop
    /* 1EB98 8002E398 02004234 */  ori        $v0, $v0, 0x2
    /* 1EB9C 8002E39C 0800E003 */  jr         $ra
    /* 1EBA0 8002E3A0 340082A4 */   sh        $v0, 0x34($a0)
  .L8002E3A4:
    /* 1EBA4 8002E3A4 F6FFA104 */  bgez       $a1, .L8002E380
    /* 1EBA8 8002E3A8 B4FF6324 */   addiu     $v1, $v1, -0x4C
    /* 1EBAC 8002E3AC 0800E003 */  jr         $ra
    /* 1EBB0 8002E3B0 00000000 */   nop
endlabel func_8002E370
