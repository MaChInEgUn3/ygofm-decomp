nonmatching func_8005F588, 0x40

glabel func_8005F588
    /* 4FD88 8005F588 73018393 */  lbu        $v1, %gp_rel(D_8009B07B)($gp)
    /* 4FD8C 8005F58C 01000224 */  addiu      $v0, $zero, 0x1
    /* 4FD90 8005F590 05006214 */  bne        $v1, $v0, .L8005F5A8
    /* 4FD94 8005F594 00000000 */   nop
    /* 4FD98 8005F598 74018293 */  lbu        $v0, %gp_rel(D_8009B07C)($gp)
    /* 4FD9C 8005F59C 00000000 */  nop
    /* 4FDA0 8005F5A0 07004310 */  beq        $v0, $v1, .L8005F5C0
    /* 4FDA4 8005F5A4 00000000 */   nop
  .L8005F5A8:
    /* 4FDA8 8005F5A8 04008014 */  bnez       $a0, .L8005F5BC
    /* 4FDAC 8005F5AC FFFF0224 */   addiu     $v0, $zero, -0x1
    /* 4FDB0 8005F5B0 720182A3 */  sb         $v0, %gp_rel(D_8009B07A)($gp)
    /* 4FDB4 8005F5B4 0800E003 */  jr         $ra
    /* 4FDB8 8005F5B8 00000000 */   nop
  .L8005F5BC:
    /* 4FDBC 8005F5BC 720180A3 */  sb         $zero, %gp_rel(D_8009B07A)($gp)
  .L8005F5C0:
    /* 4FDC0 8005F5C0 0800E003 */  jr         $ra
    /* 4FDC4 8005F5C4 00000000 */   nop
endlabel func_8005F588
