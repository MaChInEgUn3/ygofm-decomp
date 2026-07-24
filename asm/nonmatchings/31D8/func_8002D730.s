nonmatching func_8002D730, 0x94

glabel func_8002D730
    /* 1DF30 8002D730 64038393 */  lbu        $v1, %gp_rel(D_8009B26C)($gp)
    /* 1DF34 8002D734 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1DF38 8002D738 40006230 */  andi       $v0, $v1, 0x40
    /* 1DF3C 8002D73C 07004014 */  bnez       $v0, .L8002D75C
    /* 1DF40 8002D740 1000BFAF */   sw        $ra, 0x10($sp)
    /* 1DF44 8002D744 40006234 */  ori        $v0, $v1, 0x40
    /* 1DF48 8002D748 640382A3 */  sb         $v0, %gp_rel(D_8009B26C)($gp)
    /* 1DF4C 8002D74C 26F1000C */  jal        func_8003C498
    /* 1DF50 8002D750 00000000 */   nop
    /* 1DF54 8002D754 54F2000C */  jal        func_8003C950
    /* 1DF58 8002D758 00000000 */   nop
  .L8002D75C:
    /* 1DF5C 8002D75C 97F2000C */  jal        func_8003CA5C
    /* 1DF60 8002D760 00000000 */   nop
    /* 1DF64 8002D764 13004014 */  bnez       $v0, .L8002D7B4
    /* 1DF68 8002D768 00000000 */   nop
    /* 1DF6C 8002D76C CDFF000C */  jal        func_8003FF34
    /* 1DF70 8002D770 00000000 */   nop
    /* 1DF74 8002D774 C056000C */  jal        func_80015B00
    /* 1DF78 8002D778 00000000 */   nop
    /* 1DF7C 8002D77C 61038293 */  lbu        $v0, %gp_rel(D_8009B269)($gp)
    /* 1DF80 8002D780 00000000 */  nop
    /* 1DF84 8002D784 640382A3 */  sb         $v0, %gp_rel(D_8009B26C)($gp)
    /* 1DF88 8002D788 FF004230 */  andi       $v0, $v0, 0xFF
    /* 1DF8C 8002D78C 09004010 */  beqz       $v0, .L8002D7B4
    /* 1DF90 8002D790 01000224 */   addiu     $v0, $zero, 0x1
    /* 1DF94 8002D794 600382A3 */  sb         $v0, %gp_rel(D_8009B268)($gp)
    /* 1DF98 8002D798 08000224 */  addiu      $v0, $zero, 0x8
    /* 1DF9C 8002D79C 0F80043C */  lui        $a0, %hi(D_800E9DC0)
    /* 1DFA0 8002D7A0 C09D8424 */  addiu      $a0, $a0, %lo(D_800E9DC0)
    /* 1DFA4 8002D7A4 650380A3 */  sb         $zero, %gp_rel(D_8009B26D)($gp)
    /* 1DFA8 8002D7A8 640382A3 */  sb         $v0, %gp_rel(D_8009B26C)($gp)
    /* 1DFAC 8002D7AC E33E020C */  jal        func_8008FB8C
    /* 1DFB0 8002D7B0 01000524 */   addiu     $a1, $zero, 0x1
  .L8002D7B4:
    /* 1DFB4 8002D7B4 1000BF8F */  lw         $ra, 0x10($sp)
    /* 1DFB8 8002D7B8 00000000 */  nop
    /* 1DFBC 8002D7BC 0800E003 */  jr         $ra
    /* 1DFC0 8002D7C0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8002D730
