nonmatching func_8007DA58, 0x29C

glabel func_8007DA58
    /* 6E258 8007DA58 0980023C */  lui        $v0, %hi(D_80093A08)
    /* 6E25C 8007DA5C 083A428C */  lw         $v0, %lo(D_80093A08)($v0)
    /* 6E260 8007DA60 C0FFBD27 */  addiu      $sp, $sp, -0x40
    /* 6E264 8007DA64 3800B6AF */  sw         $s6, 0x38($sp)
    /* 6E268 8007DA68 21B08000 */  addu       $s6, $a0, $zero
    /* 6E26C 8007DA6C 3C00BFAF */  sw         $ra, 0x3C($sp)
    /* 6E270 8007DA70 3400B5AF */  sw         $s5, 0x34($sp)
    /* 6E274 8007DA74 3000B4AF */  sw         $s4, 0x30($sp)
    /* 6E278 8007DA78 2C00B3AF */  sw         $s3, 0x2C($sp)
    /* 6E27C 8007DA7C 2800B2AF */  sw         $s2, 0x28($sp)
    /* 6E280 8007DA80 2400B1AF */  sw         $s1, 0x24($sp)
    /* 6E284 8007DA84 9000C212 */  beq        $s6, $v0, .L8007DCC8
    /* 6E288 8007DA88 2000B0AF */   sw        $s0, 0x20($sp)
    /* 6E28C 8007DA8C 01000424 */  addiu      $a0, $zero, 0x1
    /* 6E290 8007DA90 40101600 */  sll        $v0, $s6, 1
    /* 6E294 8007DA94 21105600 */  addu       $v0, $v0, $s6
    /* 6E298 8007DA98 80100200 */  sll        $v0, $v0, 2
    /* 6E29C 8007DA9C 23105600 */  subu       $v0, $v0, $s6
    /* 6E2A0 8007DAA0 80100200 */  sll        $v0, $v0, 2
    /* 6E2A4 8007DAA4 0F80053C */  lui        $a1, %hi(D_800F656C)
    /* 6E2A8 8007DAA8 2128A200 */  addu       $a1, $a1, $v0
    /* 6E2AC 8007DAAC 6C65A58C */  lw         $a1, %lo(D_800F656C)($a1)
    /* 6E2B0 8007DAB0 0F80103C */  lui        $s0, %hi(D_800F7B90)
    /* 6E2B4 8007DAB4 907B1026 */  addiu      $s0, $s0, %lo(D_800F7B90)
    /* 6E2B8 8007DAB8 3DF7010C */  jal        func_8007DCF4
    /* 6E2BC 8007DABC 21300002 */   addu      $a2, $s0, $zero
    /* 6E2C0 8007DAC0 01000324 */  addiu      $v1, $zero, 0x1
    /* 6E2C4 8007DAC4 0B004310 */  beq        $v0, $v1, .L8007DAF4
    /* 6E2C8 8007DAC8 00000000 */   nop
    /* 6E2CC 8007DACC 0980023C */  lui        $v0, %hi(D_800934E8)
    /* 6E2D0 8007DAD0 E834428C */  lw         $v0, %lo(D_800934E8)($v0)
    /* 6E2D4 8007DAD4 00000000 */  nop
    /* 6E2D8 8007DAD8 7C004018 */  blez       $v0, .L8007DCCC
    /* 6E2DC 8007DADC FFFF0224 */   addiu     $v0, $zero, -0x1
    /* 6E2E0 8007DAE0 0180043C */  lui        $a0, %hi(D_80012024)
    /* 6E2E4 8007DAE4 BC3E020C */  jal        func_8008FAF0
    /* 6E2E8 8007DAE8 24208424 */   addiu     $a0, $a0, %lo(D_80012024)
    /* 6E2EC 8007DAEC 33F70108 */  j          .L8007DCCC
    /* 6E2F0 8007DAF0 FFFF0224 */   addiu     $v0, $zero, -0x1
  .L8007DAF4:
    /* 6E2F4 8007DAF4 0980023C */  lui        $v0, %hi(D_800934E8)
    /* 6E2F8 8007DAF8 E834428C */  lw         $v0, %lo(D_800934E8)($v0)
    /* 6E2FC 8007DAFC 00000000 */  nop
    /* 6E300 8007DB00 02004228 */  slti       $v0, $v0, 0x2
    /* 6E304 8007DB04 05004014 */  bnez       $v0, .L8007DB1C
    /* 6E308 8007DB08 00080226 */   addiu     $v0, $s0, 0x800
    /* 6E30C 8007DB0C 0180043C */  lui        $a0, %hi(D_80012044)
    /* 6E310 8007DB10 BC3E020C */  jal        func_8008FAF0
    /* 6E314 8007DB14 44208424 */   addiu     $a0, $a0, %lo(D_80012044)
    /* 6E318 8007DB18 00080226 */  addiu      $v0, $s0, 0x800
  .L8007DB1C:
    /* 6E31C 8007DB1C 2B100202 */  sltu       $v0, $s0, $v0
    /* 6E320 8007DB20 55004010 */  beqz       $v0, .L8007DC78
    /* 6E324 8007DB24 21900000 */   addu      $s2, $zero, $zero
    /* 6E328 8007DB28 0F80153C */  lui        $s5, %hi(D_800F5F90)
    /* 6E32C 8007DB2C 905FB526 */  addiu      $s5, $s5, %lo(D_800F5F90)
    /* 6E330 8007DB30 0800B326 */  addiu      $s3, $s5, 0x8
    /* 6E334 8007DB34 21880000 */  addu       $s1, $zero, $zero
    /* 6E338 8007DB38 21A0A002 */  addu       $s4, $s5, $zero
  .L8007DB3C:
    /* 6E33C 8007DB3C 00000292 */  lbu        $v0, 0x0($s0)
    /* 6E340 8007DB40 00000000 */  nop
    /* 6E344 8007DB44 4C004010 */  beqz       $v0, .L8007DC78
    /* 6E348 8007DB48 00000000 */   nop
    /* 6E34C 8007DB4C 0500028A */  lwl        $v0, 0x5($s0)
    /* 6E350 8007DB50 0200029A */  lwr        $v0, 0x2($s0)
    /* 6E354 8007DB54 00000000 */  nop
    /* 6E358 8007DB58 1B00A2AB */  swl        $v0, 0x1B($sp)
    /* 6E35C 8007DB5C 1800A2BB */  swr        $v0, 0x18($sp)
    /* 6E360 8007DB60 1800A48F */  lw         $a0, 0x18($sp)
    /* 6E364 8007DB64 80F9010C */  jal        func_8007E600
    /* 6E368 8007DB68 21288002 */   addu      $a1, $s4, $zero
    /* 6E36C 8007DB6C 0400A226 */  addiu      $v0, $s5, 0x4
    /* 6E370 8007DB70 21102202 */  addu       $v0, $s1, $v0
    /* 6E374 8007DB74 0D00038A */  lwl        $v1, 0xD($s0)
    /* 6E378 8007DB78 0A00039A */  lwr        $v1, 0xA($s0)
    /* 6E37C 8007DB7C 00000000 */  nop
    /* 6E380 8007DB80 030043A8 */  swl        $v1, 0x3($v0)
    /* 6E384 8007DB84 000043B8 */  swr        $v1, 0x0($v0)
    /* 6E388 8007DB88 05004012 */  beqz       $s2, .L8007DBA0
    /* 6E38C 8007DB8C 01000224 */   addiu     $v0, $zero, 0x1
    /* 6E390 8007DB90 07004212 */  beq        $s2, $v0, .L8007DBB0
    /* 6E394 8007DB94 21206002 */   addu      $a0, $s3, $zero
    /* 6E398 8007DB98 F3F60108 */  j          .L8007DBCC
    /* 6E39C 8007DB9C 00000000 */   nop
  .L8007DBA0:
    /* 6E3A0 8007DBA0 0180023C */  lui        $v0, %hi(D_80012060)
    /* 6E3A4 8007DBA4 60204294 */  lhu        $v0, %lo(D_80012060)($v0)
    /* 6E3A8 8007DBA8 FAF60108 */  j          .L8007DBE8
    /* 6E3AC 8007DBAC 0800A2A6 */   sh        $v0, 0x8($s5)
  .L8007DBB0:
    /* 6E3B0 8007DBB0 0180023C */  lui        $v0, %hi(D_80012064)
    /* 6E3B4 8007DBB4 64204284 */  lh         $v0, %lo(D_80012064)($v0)
    /* 6E3B8 8007DBB8 0180033C */  lui        $v1, %hi(D_80012066)
    /* 6E3BC 8007DBBC 66206380 */  lb         $v1, %lo(D_80012066)($v1)
    /* 6E3C0 8007DBC0 2000A2A6 */  sh         $v0, 0x20($s5)
    /* 6E3C4 8007DBC4 FAF60108 */  j          .L8007DBE8
    /* 6E3C8 8007DBC8 2200A3A2 */   sb        $v1, 0x22($s5)
  .L8007DBCC:
    /* 6E3CC 8007DBCC 20000692 */  lbu        $a2, 0x20($s0)
    /* 6E3D0 8007DBD0 E438020C */  jal        func_8008E390
    /* 6E3D4 8007DBD4 21000526 */   addiu     $a1, $s0, 0x21
    /* 6E3D8 8007DBD8 20000292 */  lbu        $v0, 0x20($s0)
    /* 6E3DC 8007DBDC 00000000 */  nop
    /* 6E3E0 8007DBE0 21106202 */  addu       $v0, $s3, $v0
    /* 6E3E4 8007DBE4 000040A0 */  sb         $zero, 0x0($v0)
  .L8007DBE8:
    /* 6E3E8 8007DBE8 0980023C */  lui        $v0, %hi(D_800934E8)
    /* 6E3EC 8007DBEC E834428C */  lw         $v0, %lo(D_800934E8)($v0)
    /* 6E3F0 8007DBF0 00000000 */  nop
    /* 6E3F4 8007DBF4 02004228 */  slti       $v0, $v0, 0x2
    /* 6E3F8 8007DBF8 12004014 */  bnez       $v0, .L8007DC44
    /* 6E3FC 8007DBFC 00000000 */   nop
    /* 6E400 8007DC00 0F80053C */  lui        $a1, %hi(D_800F5F90)
    /* 6E404 8007DC04 2128B100 */  addu       $a1, $a1, $s1
    /* 6E408 8007DC08 905FA590 */  lbu        $a1, %lo(D_800F5F90)($a1)
    /* 6E40C 8007DC0C 0F80063C */  lui        $a2, %hi(D_800F5F91)
    /* 6E410 8007DC10 2130D100 */  addu       $a2, $a2, $s1
    /* 6E414 8007DC14 915FC690 */  lbu        $a2, %lo(D_800F5F91)($a2)
    /* 6E418 8007DC18 0F80073C */  lui        $a3, %hi(D_800F5F92)
    /* 6E41C 8007DC1C 2138F100 */  addu       $a3, $a3, $s1
    /* 6E420 8007DC20 925FE790 */  lbu        $a3, %lo(D_800F5F92)($a3)
    /* 6E424 8007DC24 0F80023C */  lui        $v0, %hi(D_800F5F94)
    /* 6E428 8007DC28 21105100 */  addu       $v0, $v0, $s1
    /* 6E42C 8007DC2C 945F428C */  lw         $v0, %lo(D_800F5F94)($v0)
    /* 6E430 8007DC30 0180043C */  lui        $a0, %hi(D_80012068)
    /* 6E434 8007DC34 68208424 */  addiu      $a0, $a0, %lo(D_80012068)
    /* 6E438 8007DC38 1400B3AF */  sw         $s3, 0x14($sp)
    /* 6E43C 8007DC3C 1C3A020C */  jal        func_8008E870
    /* 6E440 8007DC40 1000A2AF */   sw        $v0, 0x10($sp)
  .L8007DC44:
    /* 6E444 8007DC44 18007326 */  addiu      $s3, $s3, 0x18
    /* 6E448 8007DC48 18003126 */  addiu      $s1, $s1, 0x18
    /* 6E44C 8007DC4C 00000292 */  lbu        $v0, 0x0($s0)
    /* 6E450 8007DC50 01005226 */  addiu      $s2, $s2, 0x1
    /* 6E454 8007DC54 21800202 */  addu       $s0, $s0, $v0
    /* 6E458 8007DC58 4000422A */  slti       $v0, $s2, 0x40
    /* 6E45C 8007DC5C 06004010 */  beqz       $v0, .L8007DC78
    /* 6E460 8007DC60 18009426 */   addiu     $s4, $s4, 0x18
    /* 6E464 8007DC64 1080023C */  lui        $v0, %hi(D_800F8390)
    /* 6E468 8007DC68 90834224 */  addiu      $v0, $v0, %lo(D_800F8390)
    /* 6E46C 8007DC6C 2B100202 */  sltu       $v0, $s0, $v0
    /* 6E470 8007DC70 B2FF4014 */  bnez       $v0, .L8007DB3C
    /* 6E474 8007DC74 00000000 */   nop
  .L8007DC78:
    /* 6E478 8007DC78 0980013C */  lui        $at, %hi(D_80093A08)
    /* 6E47C 8007DC7C 083A36AC */  sw         $s6, %lo(D_80093A08)($at)
    /* 6E480 8007DC80 4000422A */  slti       $v0, $s2, 0x40
    /* 6E484 8007DC84 06004010 */  beqz       $v0, .L8007DCA0
    /* 6E488 8007DC88 40101200 */   sll       $v0, $s2, 1
    /* 6E48C 8007DC8C 21105200 */  addu       $v0, $v0, $s2
    /* 6E490 8007DC90 C0100200 */  sll        $v0, $v0, 3
    /* 6E494 8007DC94 0F80013C */  lui        $at, %hi(D_800F5F98)
    /* 6E498 8007DC98 21082200 */  addu       $at, $at, $v0
    /* 6E49C 8007DC9C 985F20A0 */  sb         $zero, %lo(D_800F5F98)($at)
  .L8007DCA0:
    /* 6E4A0 8007DCA0 0980023C */  lui        $v0, %hi(D_800934E8)
    /* 6E4A4 8007DCA4 E834428C */  lw         $v0, %lo(D_800934E8)($v0)
    /* 6E4A8 8007DCA8 00000000 */  nop
    /* 6E4AC 8007DCAC 02004228 */  slti       $v0, $v0, 0x2
    /* 6E4B0 8007DCB0 06004014 */  bnez       $v0, .L8007DCCC
    /* 6E4B4 8007DCB4 01000224 */   addiu     $v0, $zero, 0x1
    /* 6E4B8 8007DCB8 0180043C */  lui        $a0, %hi(D_80012084)
    /* 6E4BC 8007DCBC 84208424 */  addiu      $a0, $a0, %lo(D_80012084)
    /* 6E4C0 8007DCC0 1C3A020C */  jal        func_8008E870
    /* 6E4C4 8007DCC4 21284002 */   addu      $a1, $s2, $zero
  .L8007DCC8:
    /* 6E4C8 8007DCC8 01000224 */  addiu      $v0, $zero, 0x1
  .L8007DCCC:
    /* 6E4CC 8007DCCC 3C00BF8F */  lw         $ra, 0x3C($sp)
    /* 6E4D0 8007DCD0 3800B68F */  lw         $s6, 0x38($sp)
    /* 6E4D4 8007DCD4 3400B58F */  lw         $s5, 0x34($sp)
    /* 6E4D8 8007DCD8 3000B48F */  lw         $s4, 0x30($sp)
    /* 6E4DC 8007DCDC 2C00B38F */  lw         $s3, 0x2C($sp)
    /* 6E4E0 8007DCE0 2800B28F */  lw         $s2, 0x28($sp)
    /* 6E4E4 8007DCE4 2400B18F */  lw         $s1, 0x24($sp)
    /* 6E4E8 8007DCE8 2000B08F */  lw         $s0, 0x20($sp)
    /* 6E4EC 8007DCEC 0800E003 */  jr         $ra
    /* 6E4F0 8007DCF0 4000BD27 */   addiu     $sp, $sp, 0x40
endlabel func_8007DA58
