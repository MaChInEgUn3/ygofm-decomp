nonmatching func_80030E7C, 0x4C

glabel func_80030E7C
    /* 2167C 80030E7C E3038393 */  lbu        $v1, %gp_rel(D_8009B2EB)($gp)
    /* 21680 80030E80 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 21684 80030E84 80006230 */  andi       $v0, $v1, 0x80
    /* 21688 80030E88 06004014 */  bnez       $v0, .L80030EA4
    /* 2168C 80030E8C 1000BFAF */   sw        $ra, 0x10($sp)
    /* 21690 80030E90 80006234 */  ori        $v0, $v1, 0x80
    /* 21694 80030E94 E30382A3 */  sb         $v0, %gp_rel(D_8009B2EB)($gp)
    /* 21698 80030E98 04000224 */  addiu      $v0, $zero, 0x4
    /* 2169C 80030E9C 0A80013C */  lui        $at, %hi(D_8009B254)
    /* 216A0 80030EA0 54B222A0 */  sb         $v0, %lo(D_8009B254)($at)
  .L80030EA4:
    /* 216A4 80030EA4 4BA2000C */  jal        func_8002892C
    /* 216A8 80030EA8 00000000 */   nop
    /* 216AC 80030EAC 02004014 */  bnez       $v0, .L80030EB8
    /* 216B0 80030EB0 00000000 */   nop
    /* 216B4 80030EB4 E30380A3 */  sb         $zero, %gp_rel(D_8009B2EB)($gp)
  .L80030EB8:
    /* 216B8 80030EB8 1000BF8F */  lw         $ra, 0x10($sp)
    /* 216BC 80030EBC 00000000 */  nop
    /* 216C0 80030EC0 0800E003 */  jr         $ra
    /* 216C4 80030EC4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80030E7C
