nonmatching func_8004D134, 0x458

glabel func_8004D134
    /* 3D934 8004D134 F8FFBD27 */  addiu      $sp, $sp, -0x8
    /* 3D938 8004D138 21788000 */  addu       $t7, $a0, $zero
    /* 3D93C 8004D13C 0000B0AF */  sw         $s0, 0x0($sp)
    /* 3D940 8004D140 2180A000 */  addu       $s0, $a1, $zero
    /* 3D944 8004D144 0400B1AF */  sw         $s1, 0x4($sp)
    /* 3D948 8004D148 0000C48C */  lw         $a0, 0x0($a2)
    /* 3D94C 8004D14C 1400C38C */  lw         $v1, 0x14($a2)
    /* 3D950 8004D150 1800B88F */  lw         $t8, 0x18($sp)
    /* 3D954 8004D154 0400828C */  lw         $v0, 0x4($a0)
    /* 3D958 8004D158 02009194 */  lhu        $s1, 0x2($a0)
    /* 3D95C 8004D15C 80100200 */  sll        $v0, $v0, 2
    /* 3D960 8004D160 21186200 */  addu       $v1, $v1, $v0
    /* 3D964 8004D164 0200E22D */  sltiu      $v0, $t7, 0x2
    /* 3D968 8004D168 03004014 */  bnez       $v0, .L8004D178
    /* 3D96C 8004D16C 21702002 */   addu      $t6, $s1, $zero
    /* 3D970 8004D170 5F350108 */  j          .L8004D57C
    /* 3D974 8004D174 21100000 */   addu      $v0, $zero, $zero
  .L8004D178:
    /* 3D978 8004D178 00000496 */  lhu        $a0, 0x0($s0)
    /* 3D97C 8004D17C 15000224 */  addiu      $v0, $zero, 0x15
    /* 3D980 8004D180 34008210 */  beq        $a0, $v0, .L8004D254
    /* 3D984 8004D184 1600822C */   sltiu     $v0, $a0, 0x16
    /* 3D988 8004D188 0E004010 */  beqz       $v0, .L8004D1C4
    /* 3D98C 8004D18C 0D000224 */   addiu     $v0, $zero, 0xD
    /* 3D990 8004D190 26008210 */  beq        $a0, $v0, .L8004D22C
    /* 3D994 8004D194 0E00822C */   sltiu     $v0, $a0, 0xE
    /* 3D998 8004D198 05004010 */  beqz       $v0, .L8004D1B0
    /* 3D99C 8004D19C 09000224 */   addiu     $v0, $zero, 0x9
    /* 3D9A0 8004D1A0 18008210 */  beq        $a0, $v0, .L8004D204
    /* 3D9A4 8004D1A4 21100000 */   addu      $v0, $zero, $zero
    /* 3D9A8 8004D1A8 5F350108 */  j          .L8004D57C
    /* 3D9AC 8004D1AC 00000000 */   nop
  .L8004D1B0:
    /* 3D9B0 8004D1B0 11000224 */  addiu      $v0, $zero, 0x11
    /* 3D9B4 8004D1B4 1D008210 */  beq        $a0, $v0, .L8004D22C
    /* 3D9B8 8004D1B8 21100000 */   addu      $v0, $zero, $zero
    /* 3D9BC 8004D1BC 5F350108 */  j          .L8004D57C
    /* 3D9C0 8004D1C0 00000000 */   nop
  .L8004D1C4:
    /* 3D9C4 8004D1C4 0D020224 */  addiu      $v0, $zero, 0x20D
    /* 3D9C8 8004D1C8 1D008210 */  beq        $a0, $v0, .L8004D240
    /* 3D9CC 8004D1CC 0E02822C */   sltiu     $v0, $a0, 0x20E
    /* 3D9D0 8004D1D0 05004010 */  beqz       $v0, .L8004D1E8
    /* 3D9D4 8004D1D4 09020224 */   addiu     $v0, $zero, 0x209
    /* 3D9D8 8004D1D8 0F008210 */  beq        $a0, $v0, .L8004D218
    /* 3D9DC 8004D1DC 21100000 */   addu      $v0, $zero, $zero
    /* 3D9E0 8004D1E0 5F350108 */  j          .L8004D57C
    /* 3D9E4 8004D1E4 00000000 */   nop
  .L8004D1E8:
    /* 3D9E8 8004D1E8 11020224 */  addiu      $v0, $zero, 0x211
    /* 3D9EC 8004D1EC 14008210 */  beq        $a0, $v0, .L8004D240
    /* 3D9F0 8004D1F0 15020224 */   addiu     $v0, $zero, 0x215
    /* 3D9F4 8004D1F4 1B008210 */  beq        $a0, $v0, .L8004D264
    /* 3D9F8 8004D1F8 21100000 */   addu      $v0, $zero, $zero
    /* 3D9FC 8004D1FC 5F350108 */  j          .L8004D57C
    /* 3DA00 8004D200 00000000 */   nop
  .L8004D204:
    /* 3DA04 8004D204 06000D24 */  addiu      $t5, $zero, 0x6
    /* 3DA08 8004D208 02000C24 */  addiu      $t4, $zero, 0x2
    /* 3DA0C 8004D20C 14000A24 */  addiu      $t2, $zero, 0x14
    /* 3DA10 8004D210 9D340108 */  j          .L8004D274
    /* 3DA14 8004D214 20000B24 */   addiu     $t3, $zero, 0x20
  .L8004D218:
    /* 3DA18 8004D218 0A000D24 */  addiu      $t5, $zero, 0xA
    /* 3DA1C 8004D21C 06000C24 */  addiu      $t4, $zero, 0x6
    /* 3DA20 8004D220 18000A24 */  addiu      $t2, $zero, 0x18
    /* 3DA24 8004D224 9D340108 */  j          .L8004D274
    /* 3DA28 8004D228 20000B24 */   addiu     $t3, $zero, 0x20
  .L8004D22C:
    /* 3DA2C 8004D22C 06000D24 */  addiu      $t5, $zero, 0x6
    /* 3DA30 8004D230 02000C24 */  addiu      $t4, $zero, 0x2
    /* 3DA34 8004D234 18000A24 */  addiu      $t2, $zero, 0x18
    /* 3DA38 8004D238 9D340108 */  j          .L8004D274
    /* 3DA3C 8004D23C 28000B24 */   addiu     $t3, $zero, 0x28
  .L8004D240:
    /* 3DA40 8004D240 0A000D24 */  addiu      $t5, $zero, 0xA
    /* 3DA44 8004D244 06000C24 */  addiu      $t4, $zero, 0x6
    /* 3DA48 8004D248 1C000A24 */  addiu      $t2, $zero, 0x1C
    /* 3DA4C 8004D24C 9D340108 */  j          .L8004D274
    /* 3DA50 8004D250 28000B24 */   addiu     $t3, $zero, 0x28
  .L8004D254:
    /* 3DA54 8004D254 06000D24 */  addiu      $t5, $zero, 0x6
    /* 3DA58 8004D258 02000C24 */  addiu      $t4, $zero, 0x2
    /* 3DA5C 8004D25C 9C340108 */  j          .L8004D270
    /* 3DA60 8004D260 1C000A24 */   addiu     $t2, $zero, 0x1C
  .L8004D264:
    /* 3DA64 8004D264 0A000D24 */  addiu      $t5, $zero, 0xA
    /* 3DA68 8004D268 06000C24 */  addiu      $t4, $zero, 0x6
    /* 3DA6C 8004D26C 20000A24 */  addiu      $t2, $zero, 0x20
  .L8004D270:
    /* 3DA70 8004D270 34000B24 */  addiu      $t3, $zero, 0x34
  .L8004D274:
    /* 3DA74 8004D274 FFFFCE25 */  addiu      $t6, $t6, -0x1
    /* 3DA78 8004D278 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 3DA7C 8004D27C BE00C211 */  beq        $t6, $v0, .L8004D578
    /* 3DA80 8004D280 80100F00 */   sll       $v0, $t7, 2
    /* 3DA84 8004D284 F6FF4524 */  addiu      $a1, $v0, -0xA
    /* 3DA88 8004D288 00110F00 */  sll        $v0, $t7, 4
    /* 3DA8C 8004D28C D83B5924 */  addiu      $t9, $v0, 0x3BD8
    /* 3DA90 8004D290 1C006924 */  addiu      $t1, $v1, 0x1C
  .L8004D294:
    /* 3DA94 8004D294 0200E229 */  slti       $v0, $t7, 0x2
    /* 3DA98 8004D298 20004010 */  beqz       $v0, .L8004D31C
    /* 3DA9C 8004D29C 21206D00 */   addu      $a0, $v1, $t5
    /* 3DAA0 8004D2A0 00008294 */  lhu        $v0, 0x0($a0)
    /* 3DAA4 8004D2A4 00000000 */  nop
    /* 3DAA8 8004D2A8 21404500 */  addu       $t0, $v0, $a1
    /* 3DAAC 8004D2AC C2110200 */  srl        $v0, $v0, 7
    /* 3DAB0 8004D2B0 03004630 */  andi       $a2, $v0, 0x3
    /* 3DAB4 8004D2B4 0300C228 */  slti       $v0, $a2, 0x3
    /* 3DAB8 8004D2B8 03004014 */  bnez       $v0, .L8004D2C8
    /* 3DABC 8004D2BC 000088A4 */   sh        $t0, 0x0($a0)
    /* 3DAC0 8004D2C0 7FFF0231 */  andi       $v0, $t0, 0xFF7F
    /* 3DAC4 8004D2C4 000082A4 */  sh         $v0, 0x0($a0)
  .L8004D2C8:
    /* 3DAC8 8004D2C8 0200C228 */  slti       $v0, $a2, 0x2
    /* 3DACC 8004D2CC 13004010 */  beqz       $v0, .L8004D31C
    /* 3DAD0 8004D2D0 21406C00 */   addu      $t0, $v1, $t4
    /* 3DAD4 8004D2D4 00000295 */  lhu        $v0, 0x0($t0)
    /* 3DAD8 8004D2D8 00000000 */  nop
    /* 3DADC 8004D2DC 21305900 */  addu       $a2, $v0, $t9
    /* 3DAE0 8004D2E0 82210200 */  srl        $a0, $v0, 6
    /* 3DAE4 8004D2E4 10008228 */  slti       $v0, $a0, 0x10
    /* 3DAE8 8004D2E8 0C004014 */  bnez       $v0, .L8004D31C
    /* 3DAEC 8004D2EC 000006A5 */   sh        $a2, 0x0($t0)
    /* 3DAF0 8004D2F0 3F00C230 */  andi       $v0, $a2, 0x3F
    /* 3DAF4 8004D2F4 10004624 */  addiu      $a2, $v0, 0x10
    /* 3DAF8 8004D2F8 000006A5 */  sh         $a2, 0x0($t0)
    /* 3DAFC 8004D2FC 02008104 */  bgez       $a0, .L8004D308
    /* 3DB00 8004D300 21108000 */   addu      $v0, $a0, $zero
    /* 3DB04 8004D304 0F008224 */  addiu      $v0, $a0, 0xF
  .L8004D308:
    /* 3DB08 8004D308 F0074230 */  andi       $v0, $v0, 0x7F0
    /* 3DB0C 8004D30C 23108200 */  subu       $v0, $a0, $v0
    /* 3DB10 8004D310 80110200 */  sll        $v0, $v0, 6
    /* 3DB14 8004D314 2510C200 */  or         $v0, $a2, $v0
    /* 3DB18 8004D318 000002A5 */  sh         $v0, 0x0($t0)
  .L8004D31C:
    /* 3DB1C 8004D31C 8E00E010 */  beqz       $a3, .L8004D558
    /* 3DB20 8004D320 15000224 */   addiu     $v0, $zero, 0x15
    /* 3DB24 8004D324 00000496 */  lhu        $a0, 0x0($s0)
    /* 3DB28 8004D328 00000000 */  nop
    /* 3DB2C 8004D32C 54008210 */  beq        $a0, $v0, .L8004D480
    /* 3DB30 8004D330 1600822C */   sltiu     $v0, $a0, 0x16
    /* 3DB34 8004D334 0E004010 */  beqz       $v0, .L8004D370
    /* 3DB38 8004D338 0D000224 */   addiu     $v0, $zero, 0xD
    /* 3DB3C 8004D33C 24008210 */  beq        $a0, $v0, .L8004D3D0
    /* 3DB40 8004D340 0E00822C */   sltiu     $v0, $a0, 0xE
    /* 3DB44 8004D344 05004010 */  beqz       $v0, .L8004D35C
    /* 3DB48 8004D348 09000224 */   addiu     $v0, $zero, 0x9
    /* 3DB4C 8004D34C 18008210 */  beq        $a0, $v0, .L8004D3B0
    /* 3DB50 8004D350 00000000 */   nop
    /* 3DB54 8004D354 57350108 */  j          .L8004D55C
    /* 3DB58 8004D358 21482A01 */   addu      $t1, $t1, $t2
  .L8004D35C:
    /* 3DB5C 8004D35C 11000224 */  addiu      $v0, $zero, 0x11
    /* 3DB60 8004D360 3F008210 */  beq        $a0, $v0, .L8004D460
    /* 3DB64 8004D364 00000000 */   nop
    /* 3DB68 8004D368 57350108 */  j          .L8004D55C
    /* 3DB6C 8004D36C 21482A01 */   addu      $t1, $t1, $t2
  .L8004D370:
    /* 3DB70 8004D370 0D020224 */  addiu      $v0, $zero, 0x20D
    /* 3DB74 8004D374 28008210 */  beq        $a0, $v0, .L8004D418
    /* 3DB78 8004D378 0E02822C */   sltiu     $v0, $a0, 0x20E
    /* 3DB7C 8004D37C 05004010 */  beqz       $v0, .L8004D394
    /* 3DB80 8004D380 09020224 */   addiu     $v0, $zero, 0x209
    /* 3DB84 8004D384 0E008210 */  beq        $a0, $v0, .L8004D3C0
    /* 3DB88 8004D388 00000000 */   nop
    /* 3DB8C 8004D38C 57350108 */  j          .L8004D55C
    /* 3DB90 8004D390 21482A01 */   addu      $t1, $t1, $t2
  .L8004D394:
    /* 3DB94 8004D394 11020224 */  addiu      $v0, $zero, 0x211
    /* 3DB98 8004D398 35008210 */  beq        $a0, $v0, .L8004D470
    /* 3DB9C 8004D39C 15020224 */   addiu     $v0, $zero, 0x215
    /* 3DBA0 8004D3A0 50008210 */  beq        $a0, $v0, .L8004D4E4
    /* 3DBA4 8004D3A4 00000000 */   nop
    /* 3DBA8 8004D3A8 57350108 */  j          .L8004D55C
    /* 3DBAC 8004D3AC 21482A01 */   addu      $t1, $t1, $t2
  .L8004D3B0:
    /* 3DBB0 8004D3B0 0000E48C */  lw         $a0, 0x0($a3)
    /* 3DBB4 8004D3B4 F0FF2695 */  lhu        $a2, -0x10($t1)
    /* 3DBB8 8004D3B8 52350108 */  j          .L8004D548
    /* 3DBBC 8004D3BC 2A108600 */   slt       $v0, $a0, $a2
  .L8004D3C0:
    /* 3DBC0 8004D3C0 0000E48C */  lw         $a0, 0x0($a3)
    /* 3DBC4 8004D3C4 F4FF2695 */  lhu        $a2, -0xC($t1)
    /* 3DBC8 8004D3C8 52350108 */  j          .L8004D548
    /* 3DBCC 8004D3CC 2A108600 */   slt       $v0, $a0, $a2
  .L8004D3D0:
    /* 3DBD0 8004D3D0 0000E48C */  lw         $a0, 0x0($a3)
    /* 3DBD4 8004D3D4 F0FF2695 */  lhu        $a2, -0x10($t1)
    /* 3DBD8 8004D3D8 00000000 */  nop
    /* 3DBDC 8004D3DC 2A108600 */  slt        $v0, $a0, $a2
    /* 3DBE0 8004D3E0 02004010 */  beqz       $v0, .L8004D3EC
    /* 3DBE4 8004D3E4 00000000 */   nop
    /* 3DBE8 8004D3E8 2120C000 */  addu       $a0, $a2, $zero
  .L8004D3EC:
    /* 3DBEC 8004D3EC 0000E4AC */  sw         $a0, 0x0($a3)
    /* 3DBF0 8004D3F0 F4FF2695 */  lhu        $a2, -0xC($t1)
    /* 3DBF4 8004D3F4 00000000 */  nop
    /* 3DBF8 8004D3F8 2A108600 */  slt        $v0, $a0, $a2
    /* 3DBFC 8004D3FC 03004010 */  beqz       $v0, .L8004D40C
    /* 3DC00 8004D400 00000000 */   nop
    /* 3DC04 8004D404 2120C000 */  addu       $a0, $a2, $zero
    /* 3DC08 8004D408 0000E6AC */  sw         $a2, 0x0($a3)
  .L8004D40C:
    /* 3DC0C 8004D40C F8FF2695 */  lhu        $a2, -0x8($t1)
    /* 3DC10 8004D410 52350108 */  j          .L8004D548
    /* 3DC14 8004D414 2A108600 */   slt       $v0, $a0, $a2
  .L8004D418:
    /* 3DC18 8004D418 0000E48C */  lw         $a0, 0x0($a3)
    /* 3DC1C 8004D41C F4FF2695 */  lhu        $a2, -0xC($t1)
    /* 3DC20 8004D420 00000000 */  nop
    /* 3DC24 8004D424 2A108600 */  slt        $v0, $a0, $a2
    /* 3DC28 8004D428 02004010 */  beqz       $v0, .L8004D434
    /* 3DC2C 8004D42C 00000000 */   nop
    /* 3DC30 8004D430 2120C000 */  addu       $a0, $a2, $zero
  .L8004D434:
    /* 3DC34 8004D434 0000E4AC */  sw         $a0, 0x0($a3)
    /* 3DC38 8004D438 F8FF2695 */  lhu        $a2, -0x8($t1)
    /* 3DC3C 8004D43C 00000000 */  nop
    /* 3DC40 8004D440 2A108600 */  slt        $v0, $a0, $a2
    /* 3DC44 8004D444 03004010 */  beqz       $v0, .L8004D454
    /* 3DC48 8004D448 00000000 */   nop
    /* 3DC4C 8004D44C 2120C000 */  addu       $a0, $a2, $zero
    /* 3DC50 8004D450 0000E6AC */  sw         $a2, 0x0($a3)
  .L8004D454:
    /* 3DC54 8004D454 FCFF2695 */  lhu        $a2, -0x4($t1)
    /* 3DC58 8004D458 52350108 */  j          .L8004D548
    /* 3DC5C 8004D45C 2A108600 */   slt       $v0, $a0, $a2
  .L8004D460:
    /* 3DC60 8004D460 0000E48C */  lw         $a0, 0x0($a3)
    /* 3DC64 8004D464 F2FF2695 */  lhu        $a2, -0xE($t1)
    /* 3DC68 8004D468 52350108 */  j          .L8004D548
    /* 3DC6C 8004D46C 2A108600 */   slt       $v0, $a0, $a2
  .L8004D470:
    /* 3DC70 8004D470 0000E48C */  lw         $a0, 0x0($a3)
    /* 3DC74 8004D474 F6FF2695 */  lhu        $a2, -0xA($t1)
    /* 3DC78 8004D478 52350108 */  j          .L8004D548
    /* 3DC7C 8004D47C 2A108600 */   slt       $v0, $a0, $a2
  .L8004D480:
    /* 3DC80 8004D480 0000E48C */  lw         $a0, 0x0($a3)
    /* 3DC84 8004D484 EEFF2695 */  lhu        $a2, -0x12($t1)
    /* 3DC88 8004D488 00000000 */  nop
    /* 3DC8C 8004D48C 2A108600 */  slt        $v0, $a0, $a2
    /* 3DC90 8004D490 02004010 */  beqz       $v0, .L8004D49C
    /* 3DC94 8004D494 00000000 */   nop
    /* 3DC98 8004D498 2120C000 */  addu       $a0, $a2, $zero
  .L8004D49C:
    /* 3DC9C 8004D49C 0000E4AC */  sw         $a0, 0x0($a3)
    /* 3DCA0 8004D4A0 F4FF2695 */  lhu        $a2, -0xC($t1)
    /* 3DCA4 8004D4A4 00000000 */  nop
    /* 3DCA8 8004D4A8 2A108600 */  slt        $v0, $a0, $a2
    /* 3DCAC 8004D4AC 03004010 */  beqz       $v0, .L8004D4BC
    /* 3DCB0 8004D4B0 00000000 */   nop
    /* 3DCB4 8004D4B4 2120C000 */  addu       $a0, $a2, $zero
    /* 3DCB8 8004D4B8 0000E6AC */  sw         $a2, 0x0($a3)
  .L8004D4BC:
    /* 3DCBC 8004D4BC F8FF2695 */  lhu        $a2, -0x8($t1)
    /* 3DCC0 8004D4C0 00000000 */  nop
    /* 3DCC4 8004D4C4 2A108600 */  slt        $v0, $a0, $a2
    /* 3DCC8 8004D4C8 02004010 */  beqz       $v0, .L8004D4D4
    /* 3DCCC 8004D4CC 00000000 */   nop
    /* 3DCD0 8004D4D0 2120C000 */  addu       $a0, $a2, $zero
  .L8004D4D4:
    /* 3DCD4 8004D4D4 0000E4AC */  sw         $a0, 0x0($a3)
    /* 3DCD8 8004D4D8 FCFF2695 */  lhu        $a2, -0x4($t1)
    /* 3DCDC 8004D4DC 52350108 */  j          .L8004D548
    /* 3DCE0 8004D4E0 2A108600 */   slt       $v0, $a0, $a2
  .L8004D4E4:
    /* 3DCE4 8004D4E4 0000E48C */  lw         $a0, 0x0($a3)
    /* 3DCE8 8004D4E8 F2FF2695 */  lhu        $a2, -0xE($t1)
    /* 3DCEC 8004D4EC 00000000 */  nop
    /* 3DCF0 8004D4F0 2A108600 */  slt        $v0, $a0, $a2
    /* 3DCF4 8004D4F4 02004010 */  beqz       $v0, .L8004D500
    /* 3DCF8 8004D4F8 00000000 */   nop
    /* 3DCFC 8004D4FC 2120C000 */  addu       $a0, $a2, $zero
  .L8004D500:
    /* 3DD00 8004D500 0000E4AC */  sw         $a0, 0x0($a3)
    /* 3DD04 8004D504 F8FF2695 */  lhu        $a2, -0x8($t1)
    /* 3DD08 8004D508 00000000 */  nop
    /* 3DD0C 8004D50C 2A108600 */  slt        $v0, $a0, $a2
    /* 3DD10 8004D510 03004010 */  beqz       $v0, .L8004D520
    /* 3DD14 8004D514 00000000 */   nop
    /* 3DD18 8004D518 2120C000 */  addu       $a0, $a2, $zero
    /* 3DD1C 8004D51C 0000E6AC */  sw         $a2, 0x0($a3)
  .L8004D520:
    /* 3DD20 8004D520 FCFF2695 */  lhu        $a2, -0x4($t1)
    /* 3DD24 8004D524 00000000 */  nop
    /* 3DD28 8004D528 2A108600 */  slt        $v0, $a0, $a2
    /* 3DD2C 8004D52C 02004010 */  beqz       $v0, .L8004D538
    /* 3DD30 8004D530 00000000 */   nop
    /* 3DD34 8004D534 2120C000 */  addu       $a0, $a2, $zero
  .L8004D538:
    /* 3DD38 8004D538 0000E4AC */  sw         $a0, 0x0($a3)
    /* 3DD3C 8004D53C 00002695 */  lhu        $a2, 0x0($t1)
    /* 3DD40 8004D540 00000000 */  nop
    /* 3DD44 8004D544 2A108600 */  slt        $v0, $a0, $a2
  .L8004D548:
    /* 3DD48 8004D548 02004010 */  beqz       $v0, .L8004D554
    /* 3DD4C 8004D54C 00000000 */   nop
    /* 3DD50 8004D550 2120C000 */  addu       $a0, $a2, $zero
  .L8004D554:
    /* 3DD54 8004D554 0000E4AC */  sw         $a0, 0x0($a3)
  .L8004D558:
    /* 3DD58 8004D558 21482A01 */  addu       $t1, $t1, $t2
  .L8004D55C:
    /* 3DD5C 8004D55C 0000028F */  lw         $v0, 0x0($t8)
    /* 3DD60 8004D560 FFFFCE25 */  addiu      $t6, $t6, -0x1
    /* 3DD64 8004D564 21104B00 */  addu       $v0, $v0, $t3
    /* 3DD68 8004D568 000002AF */  sw         $v0, 0x0($t8)
    /* 3DD6C 8004D56C FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 3DD70 8004D570 48FFC215 */  bne        $t6, $v0, .L8004D294
    /* 3DD74 8004D574 21186A00 */   addu      $v1, $v1, $t2
  .L8004D578:
    /* 3DD78 8004D578 21102002 */  addu       $v0, $s1, $zero
  .L8004D57C:
    /* 3DD7C 8004D57C 0400B18F */  lw         $s1, 0x4($sp)
    /* 3DD80 8004D580 0000B08F */  lw         $s0, 0x0($sp)
    /* 3DD84 8004D584 0800E003 */  jr         $ra
    /* 3DD88 8004D588 0800BD27 */   addiu     $sp, $sp, 0x8
endlabel func_8004D134
