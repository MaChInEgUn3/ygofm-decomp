nonmatching func_8002C68C, 0x3C

glabel func_8002C68C
    /* 1CE8C 8002C68C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1CE90 8002C690 1000BFAF */  sw         $ra, 0x10($sp)
    /* 1CE94 8002C694 81B1000C */  jal        func_8002C604
    /* 1CE98 8002C698 00000000 */   nop
    /* 1CE9C 8002C69C 21184000 */  addu       $v1, $v0, $zero
    /* 1CEA0 8002C6A0 05006010 */  beqz       $v1, .L8002C6B8
    /* 1CEA4 8002C6A4 00000000 */   nop
    /* 1CEA8 8002C6A8 58038293 */  lbu        $v0, %gp_rel(D_8009B260)($gp)
    /* 1CEAC 8002C6AC 00000000 */  nop
    /* 1CEB0 8002C6B0 80004234 */  ori        $v0, $v0, 0x80
    /* 1CEB4 8002C6B4 580382A3 */  sb         $v0, %gp_rel(D_8009B260)($gp)
  .L8002C6B8:
    /* 1CEB8 8002C6B8 1000BF8F */  lw         $ra, 0x10($sp)
    /* 1CEBC 8002C6BC 21106000 */  addu       $v0, $v1, $zero
    /* 1CEC0 8002C6C0 0800E003 */  jr         $ra
    /* 1CEC4 8002C6C4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8002C68C
