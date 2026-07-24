nonmatching func_8002F440, 0x80

glabel func_8002F440
    /* 1FC40 8002F440 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1FC44 8002F444 1400BFAF */  sw         $ra, 0x14($sp)
    /* 1FC48 8002F448 EDB8000C */  jal        func_8002E3B4
    /* 1FC4C 8002F44C 1000B0AF */   sw        $s0, 0x10($sp)
    /* 1FC50 8002F450 11004014 */  bnez       $v0, .L8002F498
    /* 1FC54 8002F454 0F80023C */   lui       $v0, %hi(D_800E9ECE)
    /* 1FC58 8002F458 8803828F */  lw         $v0, %gp_rel(D_8009B290)($gp)
    /* 1FC5C 8002F45C 00000000 */  nop
    /* 1FC60 8002F460 00005090 */  lbu        $s0, 0x0($v0)
    /* 1FC64 8002F464 01004224 */  addiu      $v0, $v0, 0x1
    /* 1FC68 8002F468 880382AF */  sw         $v0, %gp_rel(D_8009B290)($gp)
    /* 1FC6C 8002F46C 2E56000C */  jal        func_800158B8
    /* 1FC70 8002F470 00000000 */   nop
    /* 1FC74 8002F474 3F000332 */  andi       $v1, $s0, 0x3F
    /* 1FC78 8002F478 02006010 */  beqz       $v1, .L8002F484
    /* 1FC7C 8002F47C 0F80023C */   lui       $v0, %hi(D_800E9ECF)
    /* 1FC80 8002F480 CF9E43A0 */  sb         $v1, %lo(D_800E9ECF)($v0)
  .L8002F484:
    /* 1FC84 8002F484 80000232 */  andi       $v0, $s0, 0x80
    /* 1FC88 8002F488 08004010 */  beqz       $v0, .L8002F4AC
    /* 1FC8C 8002F48C 00000000 */   nop
    /* 1FC90 8002F490 2CBD0008 */  j          .L8002F4B0
    /* 1FC94 8002F494 00000000 */   nop
  .L8002F498:
    /* 1FC98 8002F498 CE9E4290 */  lbu        $v0, %lo(D_800E9ECE)($v0)
    /* 1FC9C 8002F49C 00000000 */  nop
    /* 1FCA0 8002F4A0 80004230 */  andi       $v0, $v0, 0x80
    /* 1FCA4 8002F4A4 02004014 */  bnez       $v0, .L8002F4B0
    /* 1FCA8 8002F4A8 00000000 */   nop
  .L8002F4AC:
    /* 1FCAC 8002F4AC 740380A7 */  sh         $zero, %gp_rel(D_8009B27C)($gp)
  .L8002F4B0:
    /* 1FCB0 8002F4B0 1400BF8F */  lw         $ra, 0x14($sp)
    /* 1FCB4 8002F4B4 1000B08F */  lw         $s0, 0x10($sp)
    /* 1FCB8 8002F4B8 0800E003 */  jr         $ra
    /* 1FCBC 8002F4BC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8002F440
