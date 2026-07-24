nonmatching func_8003C8CC, 0x84

glabel func_8003C8CC
    /* 2D0CC 8003C8CC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2D0D0 8003C8D0 74048293 */  lbu        $v0, %gp_rel(D_8009B37C)($gp)
    /* 2D0D4 8003C8D4 01000424 */  addiu      $a0, $zero, 0x1
    /* 2D0D8 8003C8D8 0F004330 */  andi       $v1, $v0, 0xF
    /* 2D0DC 8003C8DC 12006410 */  beq        $v1, $a0, .L8003C928
    /* 2D0E0 8003C8E0 1000BFAF */   sw        $ra, 0x10($sp)
    /* 2D0E4 8003C8E4 02006228 */  slti       $v0, $v1, 0x2
    /* 2D0E8 8003C8E8 05004010 */  beqz       $v0, .L8003C900
    /* 2D0EC 8003C8EC 02000224 */   addiu     $v0, $zero, 0x2
    /* 2D0F0 8003C8F0 09006010 */  beqz       $v1, .L8003C918
    /* 2D0F4 8003C8F4 00000000 */   nop
    /* 2D0F8 8003C8F8 4FF20008 */  j          .L8003C93C
    /* 2D0FC 8003C8FC 00000000 */   nop
  .L8003C900:
    /* 2D100 8003C900 0E006210 */  beq        $v1, $v0, .L8003C93C
    /* 2D104 8003C904 03000224 */   addiu     $v0, $zero, 0x3
    /* 2D108 8003C908 0B006210 */  beq        $v1, $v0, .L8003C938
    /* 2D10C 8003C90C 00000000 */   nop
    /* 2D110 8003C910 4FF20008 */  j          .L8003C93C
    /* 2D114 8003C914 00000000 */   nop
  .L8003C918:
    /* 2D118 8003C918 C056000C */  jal        func_80015B00
    /* 2D11C 8003C91C 00000000 */   nop
    /* 2D120 8003C920 4FF20008 */  j          .L8003C93C
    /* 2D124 8003C924 00000000 */   nop
  .L8003C928:
    /* 2D128 8003C928 E8F1000C */  jal        func_8003C7A0
    /* 2D12C 8003C92C 00000000 */   nop
    /* 2D130 8003C930 4FF20008 */  j          .L8003C93C
    /* 2D134 8003C934 00000000 */   nop
  .L8003C938:
    /* 2D138 8003C938 740484A3 */  sb         $a0, %gp_rel(D_8009B37C)($gp)
  .L8003C93C:
    /* 2D13C 8003C93C 74048293 */  lbu        $v0, %gp_rel(D_8009B37C)($gp)
    /* 2D140 8003C940 1000BF8F */  lw         $ra, 0x10($sp)
    /* 2D144 8003C944 00000000 */  nop
    /* 2D148 8003C948 0800E003 */  jr         $ra
    /* 2D14C 8003C94C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8003C8CC
