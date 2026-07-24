nonmatching func_8002DC38, 0x13C

glabel func_8002DC38
    /* 1E438 8002DC38 64038393 */  lbu        $v1, %gp_rel(D_8009B26C)($gp)
    /* 1E43C 8002DC3C D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 1E440 8002DC40 2400BFAF */  sw         $ra, 0x24($sp)
    /* 1E444 8002DC44 40006230 */  andi       $v0, $v1, 0x40
    /* 1E448 8002DC48 2C004014 */  bnez       $v0, .L8002DCFC
    /* 1E44C 8002DC4C 2000B0AF */   sw        $s0, 0x20($sp)
    /* 1E450 8002DC50 0A80043C */  lui        $a0, %hi(D_8009B234)
    /* 1E454 8002DC54 34B28424 */  addiu      $a0, $a0, %lo(D_8009B234)
    /* 1E458 8002DC58 0A80053C */  lui        $a1, %hi(D_8009B236)
    /* 1E45C 8002DC5C 36B2A524 */  addiu      $a1, $a1, %lo(D_8009B236)
    /* 1E460 8002DC60 0A80063C */  lui        $a2, %hi(D_8009B230)
    /* 1E464 8002DC64 30B2C624 */  addiu      $a2, $a2, %lo(D_8009B230)
    /* 1E468 8002DC68 40006234 */  ori        $v0, $v1, 0x40
    /* 1E46C 8002DC6C 640382A3 */  sb         $v0, %gp_rel(D_8009B26C)($gp)
    /* 1E470 8002DC70 401F0224 */  addiu      $v0, $zero, 0x1F40
    /* 1E474 8002DC74 0A80013C */  lui        $at, %hi(D_8009B236)
    /* 1E478 8002DC78 36B222A4 */  sh         $v0, %lo(D_8009B236)($at)
    /* 1E47C 8002DC7C 0A80013C */  lui        $at, %hi(D_8009B234)
    /* 1E480 8002DC80 34B222A4 */  sh         $v0, %lo(D_8009B234)($at)
    /* 1E484 8002DC84 F603060C */  jal        func_80180FD8
    /* 1E488 8002DC88 0F80103C */   lui       $s0, %hi(D_800EB0F8)
    /* 1E48C 8002DC8C 21200000 */  addu       $a0, $zero, $zero
    /* 1E490 8002DC90 25000524 */  addiu      $a1, $zero, 0x25
    /* 1E494 8002DC94 34000624 */  addiu      $a2, $zero, 0x34
    /* 1E498 8002DC98 B4000724 */  addiu      $a3, $zero, 0xB4
    /* 1E49C 8002DC9C D8000224 */  addiu      $v0, $zero, 0xD8
    /* 1E4A0 8002DCA0 1000A2AF */  sw         $v0, 0x10($sp)
    /* 1E4A4 8002DCA4 20000224 */  addiu      $v0, $zero, 0x20
    /* 1E4A8 8002DCA8 1400A2AF */  sw         $v0, 0x14($sp)
    /* 1E4AC 8002DCAC 0ED7000C */  jal        func_80035C38
    /* 1E4B0 8002DCB0 1800A2AF */   sw        $v0, 0x18($sp)
    /* 1E4B4 8002DCB4 F8B01026 */  addiu      $s0, $s0, %lo(D_800EB0F8)
    /* 1E4B8 8002DCB8 85E6000C */  jal        func_80039A14
    /* 1E4BC 8002DCBC 21200002 */   addu      $a0, $s0, $zero
    /* 1E4C0 8002DCC0 01000424 */  addiu      $a0, $zero, 0x1
    /* 1E4C4 8002DCC4 26000524 */  addiu      $a1, $zero, 0x26
    /* 1E4C8 8002DCC8 0E000624 */  addiu      $a2, $zero, 0xE
    /* 1E4CC 8002DCCC 66000724 */  addiu      $a3, $zero, 0x66
    /* 1E4D0 8002DCD0 00010224 */  addiu      $v0, $zero, 0x100
    /* 1E4D4 8002DCD4 1000A2AF */  sw         $v0, 0x10($sp)
    /* 1E4D8 8002DCD8 30000224 */  addiu      $v0, $zero, 0x30
    /* 1E4DC 8002DCDC F9D6000C */  jal        func_80035BE4
    /* 1E4E0 8002DCE0 1400A2AF */   sw        $v0, 0x14($sp)
    /* 1E4E4 8002DCE4 85E6000C */  jal        func_80039A14
    /* 1E4E8 8002DCE8 64000426 */   addiu     $a0, $s0, 0x64
    /* 1E4EC 8002DCEC C2FF000C */  jal        func_8003FF08
    /* 1E4F0 8002DCF0 C0720424 */   addiu     $a0, $zero, 0x72C0
    /* 1E4F4 8002DCF4 8056000C */  jal        func_80015A00
    /* 1E4F8 8002DCF8 00000000 */   nop
  .L8002DCFC:
    /* 1E4FC 8002DCFC AD04060C */  jal        func_801812B4
    /* 1E500 8002DD00 00000000 */   nop
    /* 1E504 8002DD04 21804000 */  addu       $s0, $v0, $zero
    /* 1E508 8002DD08 16000012 */  beqz       $s0, .L8002DD64
    /* 1E50C 8002DD0C 00000000 */   nop
    /* 1E510 8002DD10 CDFF000C */  jal        func_8003FF34
    /* 1E514 8002DD14 00000000 */   nop
    /* 1E518 8002DD18 C056000C */  jal        func_80015B00
    /* 1E51C 8002DD1C 00000000 */   nop
    /* 1E520 8002DD20 8C07060C */  jal        func_80181E30
    /* 1E524 8002DD24 00000000 */   nop
    /* 1E528 8002DD28 01000224 */  addiu      $v0, $zero, 0x1
    /* 1E52C 8002DD2C 0A000216 */  bne        $s0, $v0, .L8002DD58
    /* 1E530 8002DD30 FFFF0424 */   addiu     $a0, $zero, -0x1
    /* 1E534 8002DD34 21288000 */  addu       $a1, $a0, $zero
    /* 1E538 8002DD38 21300000 */  addu       $a2, $zero, $zero
    /* 1E53C 8002DD3C 7293000C */  jal        func_80024DC8
    /* 1E540 8002DD40 2138C000 */   addu      $a3, $a2, $zero
    /* 1E544 8002DD44 08000224 */  addiu      $v0, $zero, 0x8
    /* 1E548 8002DD48 0A80013C */  lui        $at, %hi(D_8009B368)
    /* 1E54C 8002DD4C 68B322A0 */  sb         $v0, %lo(D_8009B368)($at)
    /* 1E550 8002DD50 59B70008 */  j          .L8002DD64
    /* 1E554 8002DD54 00000000 */   nop
  .L8002DD58:
    /* 1E558 8002DD58 61038293 */  lbu        $v0, %gp_rel(D_8009B269)($gp)
    /* 1E55C 8002DD5C 00000000 */  nop
    /* 1E560 8002DD60 640382A3 */  sb         $v0, %gp_rel(D_8009B26C)($gp)
  .L8002DD64:
    /* 1E564 8002DD64 2400BF8F */  lw         $ra, 0x24($sp)
    /* 1E568 8002DD68 2000B08F */  lw         $s0, 0x20($sp)
    /* 1E56C 8002DD6C 0800E003 */  jr         $ra
    /* 1E570 8002DD70 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_8002DC38
