nonmatching func_8003EE90, 0x38

glabel func_8003EE90
    /* 2F690 8003EE90 B9048393 */  lbu        $v1, %gp_rel(D_8009B3C1)($gp)
    /* 2F694 8003EE94 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2F698 8003EE98 80006230 */  andi       $v0, $v1, 0x80
    /* 2F69C 8003EE9C 04004014 */  bnez       $v0, .L8003EEB0
    /* 2F6A0 8003EEA0 1000BFAF */   sw        $ra, 0x10($sp)
    /* 2F6A4 8003EEA4 80006234 */  ori        $v0, $v1, 0x80
    /* 2F6A8 8003EEA8 B90482A3 */  sb         $v0, %gp_rel(D_8009B3C1)($gp)
    /* 2F6AC 8003EEAC E30480A3 */  sb         $zero, %gp_rel(D_8009B3EB)($gp)
  .L8003EEB0:
    /* 2F6B0 8003EEB0 15FA000C */  jal        func_8003E854
    /* 2F6B4 8003EEB4 00000000 */   nop
    /* 2F6B8 8003EEB8 1000BF8F */  lw         $ra, 0x10($sp)
    /* 2F6BC 8003EEBC 00000000 */  nop
    /* 2F6C0 8003EEC0 0800E003 */  jr         $ra
    /* 2F6C4 8003EEC4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8003EE90
