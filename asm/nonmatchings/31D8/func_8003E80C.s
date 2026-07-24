nonmatching func_8003E80C, 0x48

glabel func_8003E80C
    /* 2F00C 8003E80C B9048393 */  lbu        $v1, %gp_rel(D_8009B3C1)($gp)
    /* 2F010 8003E810 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2F014 8003E814 80006230 */  andi       $v0, $v1, 0x80
    /* 2F018 8003E818 08004014 */  bnez       $v0, .L8003E83C
    /* 2F01C 8003E81C 1000BFAF */   sw        $ra, 0x10($sp)
    /* 2F020 8003E820 80006234 */  ori        $v0, $v1, 0x80
    /* 2F024 8003E824 B90482A3 */  sb         $v0, %gp_rel(D_8009B3C1)($gp)
    /* 2F028 8003E828 F2048297 */  lhu        $v0, %gp_rel(D_8009B3FA)($gp)
    /* 2F02C 8003E82C 01000324 */  addiu      $v1, $zero, 0x1
    /* 2F030 8003E830 E30483A3 */  sb         $v1, %gp_rel(D_8009B3EB)($gp)
    /* 2F034 8003E834 00024234 */  ori        $v0, $v0, 0x200
    /* 2F038 8003E838 F20482A7 */  sh         $v0, %gp_rel(D_8009B3FA)($gp)
  .L8003E83C:
    /* 2F03C 8003E83C 24F9000C */  jal        func_8003E490
    /* 2F040 8003E840 00000000 */   nop
    /* 2F044 8003E844 1000BF8F */  lw         $ra, 0x10($sp)
    /* 2F048 8003E848 00000000 */  nop
    /* 2F04C 8003E84C 0800E003 */  jr         $ra
    /* 2F050 8003E850 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8003E80C
