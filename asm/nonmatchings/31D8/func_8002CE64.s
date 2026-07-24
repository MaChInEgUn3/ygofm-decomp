nonmatching func_8002CE64, 0x84

glabel func_8002CE64
    /* 1D664 8002CE64 64038393 */  lbu        $v1, %gp_rel(D_8009B26C)($gp)
    /* 1D668 8002CE68 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1D66C 8002CE6C 40006230 */  andi       $v0, $v1, 0x40
    /* 1D670 8002CE70 0B004014 */  bnez       $v0, .L8002CEA0
    /* 1D674 8002CE74 1000BFAF */   sw        $ra, 0x10($sp)
    /* 1D678 8002CE78 0A80043C */  lui        $a0, %hi(D_8009B27A)
    /* 1D67C 8002CE7C 7AB28490 */  lbu        $a0, %lo(D_8009B27A)($a0)
    /* 1D680 8002CE80 40006234 */  ori        $v0, $v1, 0x40
    /* 1D684 8002CE84 640382A3 */  sb         $v0, %gp_rel(D_8009B26C)($gp)
    /* 1D688 8002CE88 44BF000C */  jal        func_8002FD10
    /* 1D68C 8002CE8C 00000000 */   nop
    /* 1D690 8002CE90 0A80013C */  lui        $at, %hi(D_8009B254)
    /* 1D694 8002CE94 54B220A0 */  sb         $zero, %lo(D_8009B254)($at)
    /* 1D698 8002CE98 B6B30008 */  j          .L8002CED8
    /* 1D69C 8002CE9C 00000000 */   nop
  .L8002CEA0:
    /* 1D6A0 8002CEA0 0F80043C */  lui        $a0, %hi(D_800EAE98)
    /* 1D6A4 8002CEA4 F5BF000C */  jal        func_8002FFD4
    /* 1D6A8 8002CEA8 98AE8424 */   addiu     $a0, $a0, %lo(D_800EAE98)
    /* 1D6AC 8002CEAC 95BE000C */  jal        func_8002FA54
    /* 1D6B0 8002CEB0 00000000 */   nop
    /* 1D6B4 8002CEB4 64038293 */  lbu        $v0, %gp_rel(D_8009B26C)($gp)
    /* 1D6B8 8002CEB8 00000000 */  nop
    /* 1D6BC 8002CEBC 40004230 */  andi       $v0, $v0, 0x40
    /* 1D6C0 8002CEC0 05004014 */  bnez       $v0, .L8002CED8
    /* 1D6C4 8002CEC4 00000000 */   nop
    /* 1D6C8 8002CEC8 CDFF000C */  jal        func_8003FF34
    /* 1D6CC 8002CECC 00000000 */   nop
    /* 1D6D0 8002CED0 C056000C */  jal        func_80015B00
    /* 1D6D4 8002CED4 00000000 */   nop
  .L8002CED8:
    /* 1D6D8 8002CED8 1000BF8F */  lw         $ra, 0x10($sp)
    /* 1D6DC 8002CEDC 00000000 */  nop
    /* 1D6E0 8002CEE0 0800E003 */  jr         $ra
    /* 1D6E4 8002CEE4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8002CE64
