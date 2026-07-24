nonmatching func_8002D370, 0x88

glabel func_8002D370
    /* 1DB70 8002D370 64038393 */  lbu        $v1, %gp_rel(D_8009B26C)($gp)
    /* 1DB74 8002D374 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1DB78 8002D378 40006230 */  andi       $v0, $v1, 0x40
    /* 1DB7C 8002D37C 0F004014 */  bnez       $v0, .L8002D3BC
    /* 1DB80 8002D380 1000BFAF */   sw        $ra, 0x10($sp)
    /* 1DB84 8002D384 40006234 */  ori        $v0, $v1, 0x40
    /* 1DB88 8002D388 1D80053C */  lui        $a1, %hi(D_801D0200)
    /* 1DB8C 8002D38C 0002A524 */  addiu      $a1, $a1, %lo(D_801D0200)
    /* 1DB90 8002D390 0180043C */  lui        $a0, %hi(D_80010000)
    /* 1DB94 8002D394 0000848C */  lw         $a0, %lo(D_80010000)($a0)
    /* 1DB98 8002D398 0A80073C */  lui        $a3, %hi(D_8009B2F8)
    /* 1DB9C 8002D39C F8B2E790 */  lbu        $a3, %lo(D_8009B2F8)($a3)
    /* 1DBA0 8002D3A0 640382A3 */  sb         $v0, %gp_rel(D_8009B26C)($gp)
    /* 1DBA4 8002D3A4 FEC8000C */  jal        func_800323F8
    /* 1DBA8 8002D3A8 21300000 */   addu      $a2, $zero, $zero
    /* 1DBAC 8002D3AC 8056000C */  jal        func_80015A00
    /* 1DBB0 8002D3B0 00000000 */   nop
    /* 1DBB4 8002D3B4 FAB40008 */  j          .L8002D3E8
    /* 1DBB8 8002D3B8 00000000 */   nop
  .L8002D3BC:
    /* 1DBBC 8002D3BC FACE000C */  jal        func_80033BE8
    /* 1DBC0 8002D3C0 00000000 */   nop
    /* 1DBC4 8002D3C4 08004014 */  bnez       $v0, .L8002D3E8
    /* 1DBC8 8002D3C8 00000000 */   nop
    /* 1DBCC 8002D3CC CDFF000C */  jal        func_8003FF34
    /* 1DBD0 8002D3D0 00000000 */   nop
    /* 1DBD4 8002D3D4 C056000C */  jal        func_80015B00
    /* 1DBD8 8002D3D8 00000000 */   nop
    /* 1DBDC 8002D3DC 61038293 */  lbu        $v0, %gp_rel(D_8009B269)($gp)
    /* 1DBE0 8002D3E0 00000000 */  nop
    /* 1DBE4 8002D3E4 640382A3 */  sb         $v0, %gp_rel(D_8009B26C)($gp)
  .L8002D3E8:
    /* 1DBE8 8002D3E8 1000BF8F */  lw         $ra, 0x10($sp)
    /* 1DBEC 8002D3EC 00000000 */  nop
    /* 1DBF0 8002D3F0 0800E003 */  jr         $ra
    /* 1DBF4 8002D3F4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8002D370
