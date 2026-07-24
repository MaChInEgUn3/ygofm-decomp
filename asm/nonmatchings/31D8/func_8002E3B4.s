nonmatching func_8002E3B4, 0x28

glabel func_8002E3B4
    /* 1EBB4 8002E3B4 74038397 */  lhu        $v1, %gp_rel(D_8009B27C)($gp)
    /* 1EBB8 8002E3B8 00000000 */  nop
    /* 1EBBC 8002E3BC 00806230 */  andi       $v0, $v1, 0x8000
    /* 1EBC0 8002E3C0 03004010 */  beqz       $v0, .L8002E3D0
    /* 1EBC4 8002E3C4 00806234 */   ori       $v0, $v1, 0x8000
    /* 1EBC8 8002E3C8 0800E003 */  jr         $ra
    /* 1EBCC 8002E3CC 01000224 */   addiu     $v0, $zero, 0x1
  .L8002E3D0:
    /* 1EBD0 8002E3D0 740382A7 */  sh         $v0, %gp_rel(D_8009B27C)($gp)
    /* 1EBD4 8002E3D4 0800E003 */  jr         $ra
    /* 1EBD8 8002E3D8 21100000 */   addu      $v0, $zero, $zero
endlabel func_8002E3B4
