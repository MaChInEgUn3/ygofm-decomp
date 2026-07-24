nonmatching func_8003FCD8, 0x3C

glabel func_8003FCD8
    /* 304D8 8003FCD8 E5048393 */  lbu        $v1, %gp_rel(D_8009B3ED)($gp)
    /* 304DC 8003FCDC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 304E0 8003FCE0 80006230 */  andi       $v0, $v1, 0x80
    /* 304E4 8003FCE4 05004014 */  bnez       $v0, .L8003FCFC
    /* 304E8 8003FCE8 1000BFAF */   sw        $ra, 0x10($sp)
    /* 304EC 8003FCEC 80006234 */  ori        $v0, $v1, 0x80
    /* 304F0 8003FCF0 E50482A3 */  sb         $v0, %gp_rel(D_8009B3ED)($gp)
    /* 304F4 8003FCF4 29000224 */  addiu      $v0, $zero, 0x29
    /* 304F8 8003FCF8 B80482A3 */  sb         $v0, %gp_rel(D_8009B3C0)($gp)
  .L8003FCFC:
    /* 304FC 8003FCFC 35FE000C */  jal        func_8003F8D4
    /* 30500 8003FD00 00000000 */   nop
    /* 30504 8003FD04 1000BF8F */  lw         $ra, 0x10($sp)
    /* 30508 8003FD08 00000000 */  nop
    /* 3050C 8003FD0C 0800E003 */  jr         $ra
    /* 30510 8003FD10 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8003FCD8
