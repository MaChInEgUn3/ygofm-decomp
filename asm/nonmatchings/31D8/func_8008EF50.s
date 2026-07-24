nonmatching func_8008EF50, 0x50

glabel func_8008EF50
    /* 7F750 8008EF50 11008010 */  beqz       $a0, .L8008EF98
    /* 7F754 8008EF54 21100000 */   addu      $v0, $zero, $zero
    /* 7F758 8008EF58 0F00C018 */  blez       $a2, .L8008EF98
    /* 7F75C 8008EF5C 00000000 */   nop
    /* 7F760 8008EF60 DC3B0208 */  j          .L8008EF70
    /* 7F764 8008EF64 FFFFC624 */   addiu     $a2, $a2, -0x1
  .L8008EF68:
    /* 7F768 8008EF68 E63B0208 */  j          .L8008EF98
    /* 7F76C 8008EF6C FFFF8224 */   addiu     $v0, $a0, -0x1
  .L8008EF70:
    /* 7F770 8008EF70 0900C004 */  bltz       $a2, .L8008EF98
    /* 7F774 8008EF74 21100000 */   addu      $v0, $zero, $zero
    /* 7F778 8008EF78 FF00A530 */  andi       $a1, $a1, 0xFF
  .L8008EF7C:
    /* 7F77C 8008EF7C 00008290 */  lbu        $v0, 0x0($a0)
    /* 7F780 8008EF80 00000000 */  nop
    /* 7F784 8008EF84 F8FF4510 */  beq        $v0, $a1, .L8008EF68
    /* 7F788 8008EF88 01008424 */   addiu     $a0, $a0, 0x1
    /* 7F78C 8008EF8C FFFFC624 */  addiu      $a2, $a2, -0x1
    /* 7F790 8008EF90 FAFFC104 */  bgez       $a2, .L8008EF7C
    /* 7F794 8008EF94 21100000 */   addu      $v0, $zero, $zero
  .L8008EF98:
    /* 7F798 8008EF98 0800E003 */  jr         $ra
    /* 7F79C 8008EF9C 00000000 */   nop
endlabel func_8008EF50
