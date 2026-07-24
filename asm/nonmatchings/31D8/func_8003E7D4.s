nonmatching func_8003E7D4, 0x38

glabel func_8003E7D4
    /* 2EFD4 8003E7D4 B9048393 */  lbu        $v1, %gp_rel(D_8009B3C1)($gp)
    /* 2EFD8 8003E7D8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2EFDC 8003E7DC 80006230 */  andi       $v0, $v1, 0x80
    /* 2EFE0 8003E7E0 04004014 */  bnez       $v0, .L8003E7F4
    /* 2EFE4 8003E7E4 1000BFAF */   sw        $ra, 0x10($sp)
    /* 2EFE8 8003E7E8 80006234 */  ori        $v0, $v1, 0x80
    /* 2EFEC 8003E7EC B90482A3 */  sb         $v0, %gp_rel(D_8009B3C1)($gp)
    /* 2EFF0 8003E7F0 E30480A3 */  sb         $zero, %gp_rel(D_8009B3EB)($gp)
  .L8003E7F4:
    /* 2EFF4 8003E7F4 24F9000C */  jal        func_8003E490
    /* 2EFF8 8003E7F8 00000000 */   nop
    /* 2EFFC 8003E7FC 1000BF8F */  lw         $ra, 0x10($sp)
    /* 2F000 8003E800 00000000 */  nop
    /* 2F004 8003E804 0800E003 */  jr         $ra
    /* 2F008 8003E808 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8003E7D4
