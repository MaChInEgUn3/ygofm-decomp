nonmatching func_8002D2D8, 0x98

glabel func_8002D2D8
    /* 1DAD8 8002D2D8 64038393 */  lbu        $v1, %gp_rel(D_8009B26C)($gp)
    /* 1DADC 8002D2DC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1DAE0 8002D2E0 40006230 */  andi       $v0, $v1, 0x40
    /* 1DAE4 8002D2E4 10004014 */  bnez       $v0, .L8002D328
    /* 1DAE8 8002D2E8 1000BFAF */   sw        $ra, 0x10($sp)
    /* 1DAEC 8002D2EC 40006234 */  ori        $v0, $v1, 0x40
    /* 1DAF0 8002D2F0 640382A3 */  sb         $v0, %gp_rel(D_8009B26C)($gp)
    /* 1DAF4 8002D2F4 0A000224 */  addiu      $v0, $zero, 0xA
    /* 1DAF8 8002D2F8 0A80013C */  lui        $at, %hi(D_8009B0A3)
    /* 1DAFC 8002D2FC A3B022A0 */  sb         $v0, %lo(D_8009B0A3)($at)
    /* 1DB00 8002D300 30F0000C */  jal        func_8003C0C0
    /* 1DB04 8002D304 00000000 */   nop
    /* 1DB08 8002D308 0A80043C */  lui        $a0, %hi(D_8009B363)
    /* 1DB0C 8002D30C 63B38490 */  lbu        $a0, %lo(D_8009B363)($a0)
    /* 1DB10 8002D310 9BA1050C */  jal        func_8016866C
    /* 1DB14 8002D314 00000000 */   nop
    /* 1DB18 8002D318 F755000C */  jal        func_800157DC
    /* 1DB1C 8002D31C 00000000 */   nop
    /* 1DB20 8002D320 D8B40008 */  j          .L8002D360
    /* 1DB24 8002D324 00000000 */   nop
  .L8002D328:
    /* 1DB28 8002D328 F3A3050C */  jal        func_80168FCC
    /* 1DB2C 8002D32C 00000000 */   nop
    /* 1DB30 8002D330 64038293 */  lbu        $v0, %gp_rel(D_8009B26C)($gp)
    /* 1DB34 8002D334 00000000 */  nop
    /* 1DB38 8002D338 40004230 */  andi       $v0, $v0, 0x40
    /* 1DB3C 8002D33C 08004014 */  bnez       $v0, .L8002D360
    /* 1DB40 8002D340 00000000 */   nop
    /* 1DB44 8002D344 2D4D000C */  jal        func_800134B4
    /* 1DB48 8002D348 00000000 */   nop
    /* 1DB4C 8002D34C 06000224 */  addiu      $v0, $zero, 0x6
    /* 1DB50 8002D350 0A80013C */  lui        $at, %hi(D_8009B0A3)
    /* 1DB54 8002D354 A3B022A0 */  sb         $v0, %lo(D_8009B0A3)($at)
    /* 1DB58 8002D358 534B000C */  jal        func_80012D4C
    /* 1DB5C 8002D35C 00000000 */   nop
  .L8002D360:
    /* 1DB60 8002D360 1000BF8F */  lw         $ra, 0x10($sp)
    /* 1DB64 8002D364 00000000 */  nop
    /* 1DB68 8002D368 0800E003 */  jr         $ra
    /* 1DB6C 8002D36C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8002D2D8
