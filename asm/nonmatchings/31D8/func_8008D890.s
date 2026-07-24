nonmatching func_8008D890, 0x3D0

glabel func_8008D890
    /* 7E090 8008D890 C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* 7E094 8008D894 2000B4AF */  sw         $s4, 0x20($sp)
    /* 7E098 8008D898 21A08000 */  addu       $s4, $a0, $zero
    /* 7E09C 8008D89C 3000BEAF */  sw         $fp, 0x30($sp)
    /* 7E0A0 8008D8A0 21F00000 */  addu       $fp, $zero, $zero
    /* 7E0A4 8008D8A4 1800B2AF */  sw         $s2, 0x18($sp)
    /* 7E0A8 8008D8A8 21900000 */  addu       $s2, $zero, $zero
    /* 7E0AC 8008D8AC 2800B6AF */  sw         $s6, 0x28($sp)
    /* 7E0B0 8008D8B0 1080163C */  lui        $s6, %hi(D_800FE678)
    /* 7E0B4 8008D8B4 78E6D626 */  addiu      $s6, $s6, %lo(D_800FE678)
    /* 7E0B8 8008D8B8 2C00B7AF */  sw         $s7, 0x2C($sp)
    /* 7E0BC 8008D8BC 04001724 */  addiu      $s7, $zero, 0x4
    /* 7E0C0 8008D8C0 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 7E0C4 8008D8C4 1080133C */  lui        $s3, %hi(D_800FE438)
    /* 7E0C8 8008D8C8 38E47326 */  addiu      $s3, $s3, %lo(D_800FE438)
    /* 7E0CC 8008D8CC 3400BFAF */  sw         $ra, 0x34($sp)
    /* 7E0D0 8008D8D0 2400B5AF */  sw         $s5, 0x24($sp)
    /* 7E0D4 8008D8D4 1400B1AF */  sw         $s1, 0x14($sp)
    /* 7E0D8 8008D8D8 1000B0AF */  sw         $s0, 0x10($sp)
  .L8008D8DC:
    /* 7E0DC 8008D8DC 2120C002 */  addu       $a0, $s6, $zero
    /* 7E0E0 8008D8E0 D838020C */  jal        func_8008E360
    /* 7E0E4 8008D8E4 80000524 */   addiu     $a1, $zero, 0x80
    /* 7E0E8 8008D8E8 21206002 */  addu       $a0, $s3, $zero
    /* 7E0EC 8008D8EC D838020C */  jal        func_8008E360
    /* 7E0F0 8008D8F0 20000524 */   addiu     $a1, $zero, 0x20
    /* 7E0F4 8008D8F4 40191200 */  sll        $v1, $s2, 5
    /* 7E0F8 8008D8F8 A0000724 */  addiu      $a3, $zero, 0xA0
    /* 7E0FC 8008D8FC FFFF0234 */  ori        $v0, $zero, 0xFFFF
    /* 7E100 8008D900 1080013C */  lui        $at, %hi(D_800FE438)
    /* 7E104 8008D904 21082300 */  addu       $at, $at, $v1
    /* 7E108 8008D908 38E427AC */  sw         $a3, %lo(D_800FE438)($at)
    /* 7E10C 8008D90C 1080013C */  lui        $at, %hi(D_800FE43C)
    /* 7E110 8008D910 21082300 */  addu       $at, $at, $v1
    /* 7E114 8008D914 3CE420AC */  sw         $zero, %lo(D_800FE43C)($at)
    /* 7E118 8008D918 1080013C */  lui        $at, %hi(D_800FE440)
    /* 7E11C 8008D91C 21082300 */  addu       $at, $at, $v1
    /* 7E120 8008D920 40E422A4 */  sh         $v0, %lo(D_800FE440)($at)
    /* 7E124 8008D924 0300628A */  lwl        $v0, 0x3($s3)
    /* 7E128 8008D928 0000629A */  lwr        $v0, 0x0($s3)
    /* 7E12C 8008D92C 0700638A */  lwl        $v1, 0x7($s3)
    /* 7E130 8008D930 0400639A */  lwr        $v1, 0x4($s3)
    /* 7E134 8008D934 0B00648A */  lwl        $a0, 0xB($s3)
    /* 7E138 8008D938 0800649A */  lwr        $a0, 0x8($s3)
    /* 7E13C 8008D93C 0F00658A */  lwl        $a1, 0xF($s3)
    /* 7E140 8008D940 0C00659A */  lwr        $a1, 0xC($s3)
    /* 7E144 8008D944 0300C2AA */  swl        $v0, 0x3($s6)
    /* 7E148 8008D948 0000C2BA */  swr        $v0, 0x0($s6)
    /* 7E14C 8008D94C 0700C3AA */  swl        $v1, 0x7($s6)
    /* 7E150 8008D950 0400C3BA */  swr        $v1, 0x4($s6)
    /* 7E154 8008D954 0B00C4AA */  swl        $a0, 0xB($s6)
    /* 7E158 8008D958 0800C4BA */  swr        $a0, 0x8($s6)
    /* 7E15C 8008D95C 0F00C5AA */  swl        $a1, 0xF($s6)
    /* 7E160 8008D960 0C00C5BA */  swr        $a1, 0xC($s6)
    /* 7E164 8008D964 1300628A */  lwl        $v0, 0x13($s3)
    /* 7E168 8008D968 1000629A */  lwr        $v0, 0x10($s3)
    /* 7E16C 8008D96C 1700638A */  lwl        $v1, 0x17($s3)
    /* 7E170 8008D970 1400639A */  lwr        $v1, 0x14($s3)
    /* 7E174 8008D974 1B00648A */  lwl        $a0, 0x1B($s3)
    /* 7E178 8008D978 1800649A */  lwr        $a0, 0x18($s3)
    /* 7E17C 8008D97C 1F00658A */  lwl        $a1, 0x1F($s3)
    /* 7E180 8008D980 1C00659A */  lwr        $a1, 0x1C($s3)
    /* 7E184 8008D984 1300C2AA */  swl        $v0, 0x13($s6)
    /* 7E188 8008D988 1000C2BA */  swr        $v0, 0x10($s6)
    /* 7E18C 8008D98C 1700C3AA */  swl        $v1, 0x17($s6)
    /* 7E190 8008D990 1400C3BA */  swr        $v1, 0x14($s6)
    /* 7E194 8008D994 1B00C4AA */  swl        $a0, 0x1B($s6)
    /* 7E198 8008D998 1800C4BA */  swr        $a0, 0x18($s6)
    /* 7E19C 8008D99C 1F00C5AA */  swl        $a1, 0x1F($s6)
    /* 7E1A0 8008D9A0 1C00C5BA */  swr        $a1, 0x1C($s6)
    /* 7E1A4 8008D9A4 01005526 */  addiu      $s5, $s2, 0x1
    /* 7E1A8 8008D9A8 21880000 */  addu       $s1, $zero, $zero
    /* 7E1AC 8008D9AC 2120C002 */  addu       $a0, $s6, $zero
    /* 7E1B0 8008D9B0 21280000 */  addu       $a1, $zero, $zero
    /* 7E1B4 8008D9B4 7E000324 */  addiu      $v1, $zero, 0x7E
  .L8008D9B8:
    /* 7E1B8 8008D9B8 00008290 */  lbu        $v0, 0x0($a0)
    /* 7E1BC 8008D9BC 01008424 */  addiu      $a0, $a0, 0x1
    /* 7E1C0 8008D9C0 FFFF6324 */  addiu      $v1, $v1, -0x1
    /* 7E1C4 8008D9C4 2610A200 */  xor        $v0, $a1, $v0
    /* 7E1C8 8008D9C8 FBFF6104 */  bgez       $v1, .L8008D9B8
    /* 7E1CC 8008D9CC 21284000 */   addu      $a1, $v0, $zero
    /* 7E1D0 8008D9D0 000082A0 */  sb         $v0, 0x0($a0)
  .L8008D9D4:
    /* 7E1D4 8008D9D4 5835020C */  jal        func_8008D560
    /* 7E1D8 8008D9D8 00000000 */   nop
    /* 7E1DC 8008D9DC 21208002 */  addu       $a0, $s4, $zero
    /* 7E1E0 8008D9E0 1080063C */  lui        $a2, %hi(D_800FE678)
    /* 7E1E4 8008D9E4 78E6C624 */  addiu      $a2, $a2, %lo(D_800FE678)
    /* 7E1E8 8008D9E8 D42C020C */  jal        func_8008B350
    /* 7E1EC 8008D9EC 2128A002 */   addu      $a1, $s5, $zero
    /* 7E1F0 8008D9F0 D035020C */  jal        func_8008D740
    /* 7E1F4 8008D9F4 00000000 */   nop
    /* 7E1F8 8008D9F8 21804000 */  addu       $s0, $v0, $zero
    /* 7E1FC 8008D9FC 0D000012 */  beqz       $s0, .L8008DA34
    /* 7E200 8008DA00 00000000 */   nop
    /* 7E204 8008DA04 07001716 */  bne        $s0, $s7, .L8008DA24
    /* 7E208 8008DA08 00000000 */   nop
    /* 7E20C 8008DA0C 5835020C */  jal        func_8008D560
    /* 7E210 8008DA10 00000000 */   nop
    /* 7E214 8008DA14 E82C020C */  jal        func_8008B3A0
    /* 7E218 8008DA18 21208002 */   addu      $a0, $s4, $zero
    /* 7E21C 8008DA1C D035020C */  jal        func_8008D740
    /* 7E220 8008DA20 00000000 */   nop
  .L8008DA24:
    /* 7E224 8008DA24 01003126 */  addiu      $s1, $s1, 0x1
    /* 7E228 8008DA28 0800222A */  slti       $v0, $s1, 0x8
    /* 7E22C 8008DA2C E9FF4014 */  bnez       $v0, .L8008D9D4
    /* 7E230 8008DA30 00000000 */   nop
  .L8008DA34:
    /* 7E234 8008DA34 7D000016 */  bnez       $s0, .L8008DC2C
    /* 7E238 8008DA38 01005226 */   addiu     $s2, $s2, 0x1
    /* 7E23C 8008DA3C 0F00422A */  slti       $v0, $s2, 0xF
    /* 7E240 8008DA40 A6FF4014 */  bnez       $v0, .L8008D8DC
    /* 7E244 8008DA44 20007326 */   addiu     $s3, $s3, 0x20
    /* 7E248 8008DA48 21900000 */  addu       $s2, $zero, $zero
    /* 7E24C 8008DA4C 1080163C */  lui        $s6, %hi(D_800FE678)
    /* 7E250 8008DA50 78E6D626 */  addiu      $s6, $s6, %lo(D_800FE678)
    /* 7E254 8008DA54 04001724 */  addiu      $s7, $zero, 0x4
    /* 7E258 8008DA58 1080133C */  lui        $s3, %hi(D_800FE618)
    /* 7E25C 8008DA5C 18E67326 */  addiu      $s3, $s3, %lo(D_800FE618)
  .L8008DA60:
    /* 7E260 8008DA60 FFFF0724 */  addiu      $a3, $zero, -0x1
    /* 7E264 8008DA64 000067AE */  sw         $a3, 0x0($s3)
    /* 7E268 8008DA68 2120C002 */  addu       $a0, $s6, $zero
    /* 7E26C 8008DA6C D838020C */  jal        func_8008E360
    /* 7E270 8008DA70 80000524 */   addiu     $a1, $zero, 0x80
    /* 7E274 8008DA74 0300628A */  lwl        $v0, 0x3($s3)
    /* 7E278 8008DA78 0000629A */  lwr        $v0, 0x0($s3)
    /* 7E27C 8008DA7C 00000000 */  nop
    /* 7E280 8008DA80 0300C2AA */  swl        $v0, 0x3($s6)
    /* 7E284 8008DA84 0000C2BA */  swr        $v0, 0x0($s6)
    /* 7E288 8008DA88 10005526 */  addiu      $s5, $s2, 0x10
    /* 7E28C 8008DA8C 21880000 */  addu       $s1, $zero, $zero
    /* 7E290 8008DA90 2120C002 */  addu       $a0, $s6, $zero
    /* 7E294 8008DA94 21280000 */  addu       $a1, $zero, $zero
    /* 7E298 8008DA98 7E000324 */  addiu      $v1, $zero, 0x7E
  .L8008DA9C:
    /* 7E29C 8008DA9C 00008290 */  lbu        $v0, 0x0($a0)
    /* 7E2A0 8008DAA0 01008424 */  addiu      $a0, $a0, 0x1
    /* 7E2A4 8008DAA4 FFFF6324 */  addiu      $v1, $v1, -0x1
    /* 7E2A8 8008DAA8 2610A200 */  xor        $v0, $a1, $v0
    /* 7E2AC 8008DAAC FBFF6104 */  bgez       $v1, .L8008DA9C
    /* 7E2B0 8008DAB0 21284000 */   addu      $a1, $v0, $zero
    /* 7E2B4 8008DAB4 000082A0 */  sb         $v0, 0x0($a0)
  .L8008DAB8:
    /* 7E2B8 8008DAB8 5835020C */  jal        func_8008D560
    /* 7E2BC 8008DABC 00000000 */   nop
    /* 7E2C0 8008DAC0 21208002 */  addu       $a0, $s4, $zero
    /* 7E2C4 8008DAC4 1080063C */  lui        $a2, %hi(D_800FE678)
    /* 7E2C8 8008DAC8 78E6C624 */  addiu      $a2, $a2, %lo(D_800FE678)
    /* 7E2CC 8008DACC D42C020C */  jal        func_8008B350
    /* 7E2D0 8008DAD0 2128A002 */   addu      $a1, $s5, $zero
    /* 7E2D4 8008DAD4 D035020C */  jal        func_8008D740
    /* 7E2D8 8008DAD8 00000000 */   nop
    /* 7E2DC 8008DADC 21804000 */  addu       $s0, $v0, $zero
    /* 7E2E0 8008DAE0 0D000012 */  beqz       $s0, .L8008DB18
    /* 7E2E4 8008DAE4 00000000 */   nop
    /* 7E2E8 8008DAE8 07001716 */  bne        $s0, $s7, .L8008DB08
    /* 7E2EC 8008DAEC 00000000 */   nop
    /* 7E2F0 8008DAF0 5835020C */  jal        func_8008D560
    /* 7E2F4 8008DAF4 00000000 */   nop
    /* 7E2F8 8008DAF8 E82C020C */  jal        func_8008B3A0
    /* 7E2FC 8008DAFC 21208002 */   addu      $a0, $s4, $zero
    /* 7E300 8008DB00 D035020C */  jal        func_8008D740
    /* 7E304 8008DB04 00000000 */   nop
  .L8008DB08:
    /* 7E308 8008DB08 01003126 */  addiu      $s1, $s1, 0x1
    /* 7E30C 8008DB0C 0800222A */  slti       $v0, $s1, 0x8
    /* 7E310 8008DB10 E9FF4014 */  bnez       $v0, .L8008DAB8
    /* 7E314 8008DB14 00000000 */   nop
  .L8008DB18:
    /* 7E318 8008DB18 44000016 */  bnez       $s0, .L8008DC2C
    /* 7E31C 8008DB1C 01005226 */   addiu     $s2, $s2, 0x1
    /* 7E320 8008DB20 1400422A */  slti       $v0, $s2, 0x14
    /* 7E324 8008DB24 CEFF4014 */  bnez       $v0, .L8008DA60
    /* 7E328 8008DB28 04007326 */   addiu     $s3, $s3, 0x4
    /* 7E32C 8008DB2C 1080103C */  lui        $s0, %hi(D_800FE678)
    /* 7E330 8008DB30 78E61026 */  addiu      $s0, $s0, %lo(D_800FE678)
    /* 7E334 8008DB34 21200002 */  addu       $a0, $s0, $zero
    /* 7E338 8008DB38 D838020C */  jal        func_8008E360
    /* 7E33C 8008DB3C 80000524 */   addiu     $a1, $zero, 0x80
    /* 7E340 8008DB40 21880000 */  addu       $s1, $zero, $zero
    /* 7E344 8008DB44 21200000 */  addu       $a0, $zero, $zero
    /* 7E348 8008DB48 7E000324 */  addiu      $v1, $zero, 0x7E
    /* 7E34C 8008DB4C 4D000224 */  addiu      $v0, $zero, 0x4D
    /* 7E350 8008DB50 000002A2 */  sb         $v0, 0x0($s0)
    /* 7E354 8008DB54 43000224 */  addiu      $v0, $zero, 0x43
    /* 7E358 8008DB58 010002A2 */  sb         $v0, 0x1($s0)
  .L8008DB5C:
    /* 7E35C 8008DB5C 00000292 */  lbu        $v0, 0x0($s0)
    /* 7E360 8008DB60 01001026 */  addiu      $s0, $s0, 0x1
    /* 7E364 8008DB64 FFFF6324 */  addiu      $v1, $v1, -0x1
    /* 7E368 8008DB68 26108200 */  xor        $v0, $a0, $v0
    /* 7E36C 8008DB6C FBFF6104 */  bgez       $v1, .L8008DB5C
    /* 7E370 8008DB70 21204000 */   addu      $a0, $v0, $zero
    /* 7E374 8008DB74 000002A2 */  sb         $v0, 0x0($s0)
    /* 7E378 8008DB78 04001224 */  addiu      $s2, $zero, 0x4
  .L8008DB7C:
    /* 7E37C 8008DB7C 5835020C */  jal        func_8008D560
    /* 7E380 8008DB80 00000000 */   nop
    /* 7E384 8008DB84 21208002 */  addu       $a0, $s4, $zero
    /* 7E388 8008DB88 1080063C */  lui        $a2, %hi(D_800FE678)
    /* 7E38C 8008DB8C 78E6C624 */  addiu      $a2, $a2, %lo(D_800FE678)
    /* 7E390 8008DB90 D42C020C */  jal        func_8008B350
    /* 7E394 8008DB94 21280000 */   addu      $a1, $zero, $zero
    /* 7E398 8008DB98 D035020C */  jal        func_8008D740
    /* 7E39C 8008DB9C 00000000 */   nop
    /* 7E3A0 8008DBA0 21804000 */  addu       $s0, $v0, $zero
    /* 7E3A4 8008DBA4 0D000012 */  beqz       $s0, .L8008DBDC
    /* 7E3A8 8008DBA8 00000000 */   nop
    /* 7E3AC 8008DBAC 07001216 */  bne        $s0, $s2, .L8008DBCC
    /* 7E3B0 8008DBB0 00000000 */   nop
    /* 7E3B4 8008DBB4 5835020C */  jal        func_8008D560
    /* 7E3B8 8008DBB8 00000000 */   nop
    /* 7E3BC 8008DBBC E82C020C */  jal        func_8008B3A0
    /* 7E3C0 8008DBC0 21208002 */   addu      $a0, $s4, $zero
    /* 7E3C4 8008DBC4 D035020C */  jal        func_8008D740
    /* 7E3C8 8008DBC8 00000000 */   nop
  .L8008DBCC:
    /* 7E3CC 8008DBCC 01003126 */  addiu      $s1, $s1, 0x1
    /* 7E3D0 8008DBD0 0800222A */  slti       $v0, $s1, 0x8
    /* 7E3D4 8008DBD4 E9FF4014 */  bnez       $v0, .L8008DB7C
    /* 7E3D8 8008DBD8 00000000 */   nop
  .L8008DBDC:
    /* 7E3DC 8008DBDC 14000016 */  bnez       $s0, .L8008DC30
    /* 7E3E0 8008DBE0 21100002 */   addu      $v0, $s0, $zero
  .L8008DBE4:
    /* 7E3E4 8008DBE4 5835020C */  jal        func_8008D560
    /* 7E3E8 8008DBE8 00000000 */   nop
    /* 7E3EC 8008DBEC D02C020C */  jal        func_8008B340
    /* 7E3F0 8008DBF0 21208002 */   addu      $a0, $s4, $zero
    /* 7E3F4 8008DBF4 9A35020C */  jal        func_8008D668
    /* 7E3F8 8008DBF8 00000000 */   nop
    /* 7E3FC 8008DBFC 21804000 */  addu       $s0, $v0, $zero
    /* 7E400 8008DC00 0B000012 */  beqz       $s0, .L8008DC30
    /* 7E404 8008DC04 21100000 */   addu      $v0, $zero, $zero
    /* 7E408 8008DC08 5835020C */  jal        func_8008D560
    /* 7E40C 8008DC0C 0100DE27 */   addiu     $fp, $fp, 0x1
    /* 7E410 8008DC10 E82C020C */  jal        func_8008B3A0
    /* 7E414 8008DC14 21208002 */   addu      $a0, $s4, $zero
    /* 7E418 8008DC18 D035020C */  jal        func_8008D740
    /* 7E41C 8008DC1C 00000000 */   nop
    /* 7E420 8008DC20 0800C22B */  slti       $v0, $fp, 0x8
    /* 7E424 8008DC24 EFFF4014 */  bnez       $v0, .L8008DBE4
    /* 7E428 8008DC28 00000000 */   nop
  .L8008DC2C:
    /* 7E42C 8008DC2C 21100002 */  addu       $v0, $s0, $zero
  .L8008DC30:
    /* 7E430 8008DC30 3400BF8F */  lw         $ra, 0x34($sp)
    /* 7E434 8008DC34 3000BE8F */  lw         $fp, 0x30($sp)
    /* 7E438 8008DC38 2C00B78F */  lw         $s7, 0x2C($sp)
    /* 7E43C 8008DC3C 2800B68F */  lw         $s6, 0x28($sp)
    /* 7E440 8008DC40 2400B58F */  lw         $s5, 0x24($sp)
    /* 7E444 8008DC44 2000B48F */  lw         $s4, 0x20($sp)
    /* 7E448 8008DC48 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 7E44C 8008DC4C 1800B28F */  lw         $s2, 0x18($sp)
    /* 7E450 8008DC50 1400B18F */  lw         $s1, 0x14($sp)
    /* 7E454 8008DC54 1000B08F */  lw         $s0, 0x10($sp)
    /* 7E458 8008DC58 0800E003 */  jr         $ra
    /* 7E45C 8008DC5C 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel func_8008D890
