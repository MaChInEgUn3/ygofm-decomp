nonmatching func_8002DA1C, 0x21C

glabel func_8002DA1C
    /* 1E21C 8002DA1C D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 1E220 8002DA20 A0000424 */  addiu      $a0, $zero, 0xA0
    /* 1E224 8002DA24 78000524 */  addiu      $a1, $zero, 0x78
    /* 1E228 8002DA28 2800BFAF */  sw         $ra, 0x28($sp)
    /* 1E22C 8002DA2C 2400B1AF */  sw         $s1, 0x24($sp)
    /* 1E230 8002DA30 2C1E020C */  jal        func_800878B0
    /* 1E234 8002DA34 2000B0AF */   sw        $s0, 0x20($sp)
    /* 1E238 8002DA38 341E020C */  jal        func_800878D0
    /* 1E23C 8002DA3C 2C010424 */   addiu     $a0, $zero, 0x12C
    /* 1E240 8002DA40 64038393 */  lbu        $v1, %gp_rel(D_8009B26C)($gp)
    /* 1E244 8002DA44 00000000 */  nop
    /* 1E248 8002DA48 40006230 */  andi       $v0, $v1, 0x40
    /* 1E24C 8002DA4C 13004014 */  bnez       $v0, .L8002DA9C
    /* 1E250 8002DA50 40006234 */   ori       $v0, $v1, 0x40
    /* 1E254 8002DA54 640382A3 */  sb         $v0, %gp_rel(D_8009B26C)($gp)
    /* 1E258 8002DA58 E055000C */  jal        func_80015780
    /* 1E25C 8002DA5C 00000000 */   nop
    /* 1E260 8002DA60 1D80023C */  lui        $v0, %hi(D_801D0200)
  .L8002DA64:
    /* 1E264 8002DA64 00025124 */  addiu      $s1, $v0, %lo(D_801D0200)
    /* 1E268 8002DA68 30000224 */  addiu      $v0, $zero, 0x30
    /* 1E26C 8002DA6C DC0522A6 */  sh         $v0, 0x5DC($s1)
    /* 1E270 8002DA70 20001024 */  addiu      $s0, $zero, 0x20
  .L8002DA74:
    /* 1E274 8002DA74 39B3000C */  jal        func_8002CCE4
    /* 1E278 8002DA78 00800436 */   ori       $a0, $s0, 0x8000
    /* 1E27C 8002DA7C 01001026 */  addiu      $s0, $s0, 0x1
    /* 1E280 8002DA80 2001022A */  slti       $v0, $s0, 0x120
    /* 1E284 8002DA84 FBFF4014 */  bnez       $v0, .L8002DA74
    /* 1E288 8002DA88 00000000 */   nop
    /* 1E28C 8002DA8C DE032292 */  lbu        $v0, 0x3DE($s1)
    /* 1E290 8002DA90 660380A3 */  sb         $zero, %gp_rel(D_8009B26E)($gp)
    /* 1E294 8002DA94 03004234 */  ori        $v0, $v0, 0x3
    /* 1E298 8002DA98 DE0322A2 */  sb         $v0, 0x3DE($s1)
  .L8002DA9C:
    /* 1E29C 8002DA9C 66038693 */  lbu        $a2, %gp_rel(D_8009B26E)($gp)
    /* 1E2A0 8002DAA0 01001024 */  addiu      $s0, $zero, 0x1
    /* 1E2A4 8002DAA4 0F00C330 */  andi       $v1, $a2, 0xF
    /* 1E2A8 8002DAA8 1B007010 */  beq        $v1, $s0, .L8002DB18
    /* 1E2AC 8002DAAC 02006228 */   slti      $v0, $v1, 0x2
    /* 1E2B0 8002DAB0 05004010 */  beqz       $v0, .L8002DAC8
    /* 1E2B4 8002DAB4 00000000 */   nop
    /* 1E2B8 8002DAB8 08006010 */  beqz       $v1, .L8002DADC
    /* 1E2BC 8002DABC 8000C230 */   andi      $v0, $a2, 0x80
    /* 1E2C0 8002DAC0 09B70008 */  j          .L8002DC24
    /* 1E2C4 8002DAC4 00000000 */   nop
  .L8002DAC8:
    /* 1E2C8 8002DAC8 02000224 */  addiu      $v0, $zero, 0x2
    /* 1E2CC 8002DACC 44006210 */  beq        $v1, $v0, .L8002DBE0
    /* 1E2D0 8002DAD0 8000C230 */   andi      $v0, $a2, 0x80
    /* 1E2D4 8002DAD4 09B70008 */  j          .L8002DC24
    /* 1E2D8 8002DAD8 00000000 */   nop
  .L8002DADC:
    /* 1E2DC 8002DADC 04004014 */  bnez       $v0, .L8002DAF0
    /* 1E2E0 8002DAE0 8000C234 */   ori       $v0, $a2, 0x80
    /* 1E2E4 8002DAE4 660382A3 */  sb         $v0, %gp_rel(D_8009B26E)($gp)
    /* 1E2E8 8002DAE8 1FFE000C */  jal        func_8003F87C
    /* 1E2EC 8002DAEC 00000000 */   nop
  .L8002DAF0:
    /* 1E2F0 8002DAF0 C3FD000C */  jal        func_8003F70C
    /* 1E2F4 8002DAF4 00000000 */   nop
    /* 1E2F8 8002DAF8 21304000 */  addu       $a2, $v0, $zero
    /* 1E2FC 8002DAFC 4900C010 */  beqz       $a2, .L8002DC24
    /* 1E300 8002DB00 02000224 */   addiu     $v0, $zero, 0x2
    /* 1E304 8002DB04 D7FFC210 */  beq        $a2, $v0, .L8002DA64
    /* 1E308 8002DB08 1D80023C */   lui       $v0, %hi(D_801D0200)
    /* 1E30C 8002DB0C 660390A3 */  sb         $s0, %gp_rel(D_8009B26E)($gp)
    /* 1E310 8002DB10 09B70008 */  j          .L8002DC24
    /* 1E314 8002DB14 00000000 */   nop
  .L8002DB18:
    /* 1E318 8002DB18 8000C230 */  andi       $v0, $a2, 0x80
    /* 1E31C 8002DB1C 21004014 */  bnez       $v0, .L8002DBA4
    /* 1E320 8002DB20 1D80023C */   lui       $v0, %hi(D_801D0534)
    /* 1E324 8002DB24 3405438C */  lw         $v1, %lo(D_801D0534)($v0)
    /* 1E328 8002DB28 CCCC023C */  lui        $v0, (0xCCCCCCCD >> 16)
    /* 1E32C 8002DB2C CDCC4234 */  ori        $v0, $v0, (0xCCCCCCCD & 0xFFFF)
    /* 1E330 8002DB30 19006200 */  multu      $v1, $v0
    /* 1E334 8002DB34 21200000 */  addu       $a0, $zero, $zero
    /* 1E338 8002DB38 23000524 */  addiu      $a1, $zero, 0x23
    /* 1E33C 8002DB3C 70000724 */  addiu      $a3, $zero, 0x70
    /* 1E340 8002DB40 8000C234 */  ori        $v0, $a2, 0x80
    /* 1E344 8002DB44 660382A3 */  sb         $v0, %gp_rel(D_8009B26E)($gp)
    /* 1E348 8002DB48 10400000 */  mfhi       $t0
    /* 1E34C 8002DB4C 82300800 */  srl        $a2, $t0, 2
    /* 1E350 8002DB50 80100600 */  sll        $v0, $a2, 2
    /* 1E354 8002DB54 21104600 */  addu       $v0, $v0, $a2
    /* 1E358 8002DB58 23306200 */  subu       $a2, $v1, $v0
    /* 1E35C 8002DB5C 0980023C */  lui        $v0, %hi(D_80090B50)
    /* 1E360 8002DB60 500B4224 */  addiu      $v0, $v0, %lo(D_80090B50)
    /* 1E364 8002DB64 80180600 */  sll        $v1, $a2, 2
    /* 1E368 8002DB68 21186200 */  addu       $v1, $v1, $v0
    /* 1E36C 8002DB6C 00006294 */  lhu        $v0, 0x0($v1)
    /* 1E370 8002DB70 1D80063C */  lui        $a2, %hi(D_801D5608)
    /* 1E374 8002DB74 0856C2AC */  sw         $v0, %lo(D_801D5608)($a2)
    /* 1E378 8002DB78 02006394 */  lhu        $v1, 0x2($v1)
    /* 1E37C 8002DB7C 20010224 */  addiu      $v0, $zero, 0x120
    /* 1E380 8002DB80 1000A2AF */  sw         $v0, 0x10($sp)
    /* 1E384 8002DB84 20000224 */  addiu      $v0, $zero, 0x20
    /* 1E388 8002DB88 1400A2AF */  sw         $v0, 0x14($sp)
    /* 1E38C 8002DB8C 08000224 */  addiu      $v0, $zero, 0x8
    /* 1E390 8002DB90 0856C624 */  addiu      $a2, $a2, %lo(D_801D5608)
    /* 1E394 8002DB94 1800A2AF */  sw         $v0, 0x18($sp)
    /* 1E398 8002DB98 0400C3AC */  sw         $v1, 0x4($a2)
    /* 1E39C 8002DB9C 0ED7000C */  jal        func_80035C38
    /* 1E3A0 8002DBA0 10000624 */   addiu     $a2, $zero, 0x10
  .L8002DBA4:
    /* 1E3A4 8002DBA4 E5E5000C */  jal        func_80039794
    /* 1E3A8 8002DBA8 00000000 */   nop
    /* 1E3AC 8002DBAC 0F80023C */  lui        $v0, %hi(D_800EB0F8)
    /* 1E3B0 8002DBB0 F8B04424 */  addiu      $a0, $v0, %lo(D_800EB0F8)
    /* 1E3B4 8002DBB4 34008294 */  lhu        $v0, 0x34($a0)
    /* 1E3B8 8002DBB8 00000000 */  nop
    /* 1E3BC 8002DBBC 08004230 */  andi       $v0, $v0, 0x8
    /* 1E3C0 8002DBC0 18004014 */  bnez       $v0, .L8002DC24
    /* 1E3C4 8002DBC4 00000000 */   nop
    /* 1E3C8 8002DBC8 DFD6000C */  jal        func_80035B7C
    /* 1E3CC 8002DBCC 00000000 */   nop
    /* 1E3D0 8002DBD0 02000224 */  addiu      $v0, $zero, 0x2
    /* 1E3D4 8002DBD4 660382A3 */  sb         $v0, %gp_rel(D_8009B26E)($gp)
    /* 1E3D8 8002DBD8 09B70008 */  j          .L8002DC24
    /* 1E3DC 8002DBDC 00000000 */   nop
  .L8002DBE0:
    /* 1E3E0 8002DBE0 0C004014 */  bnez       $v0, .L8002DC14
    /* 1E3E4 8002DBE4 8000C234 */   ori       $v0, $a2, 0x80
    /* 1E3E8 8002DBE8 660382A3 */  sb         $v0, %gp_rel(D_8009B26E)($gp)
    /* 1E3EC 8002DBEC 0A80013C */  lui        $at, %hi(D_8009B0C0)
    /* 1E3F0 8002DBF0 C0B030A0 */  sb         $s0, %lo(D_8009B0C0)($at)
    /* 1E3F4 8002DBF4 314C010C */  jal        func_800530C4
    /* 1E3F8 8002DBF8 00000000 */   nop
    /* 1E3FC 8002DBFC F64C010C */  jal        func_800533D8
    /* 1E400 8002DC00 00000000 */   nop
    /* 1E404 8002DC04 2767010C */  jal        func_80059C9C
    /* 1E408 8002DC08 00000000 */   nop
    /* 1E40C 8002DC0C 09B70008 */  j          .L8002DC24
    /* 1E410 8002DC10 00000000 */   nop
  .L8002DC14:
    /* 1E414 8002DC14 3467010C */  jal        func_80059CD0
    /* 1E418 8002DC18 00000000 */   nop
    /* 1E41C 8002DC1C 3967010C */  jal        func_80059CE4
    /* 1E420 8002DC20 00000000 */   nop
  .L8002DC24:
    /* 1E424 8002DC24 2800BF8F */  lw         $ra, 0x28($sp)
    /* 1E428 8002DC28 2400B18F */  lw         $s1, 0x24($sp)
    /* 1E42C 8002DC2C 2000B08F */  lw         $s0, 0x20($sp)
    /* 1E430 8002DC30 0800E003 */  jr         $ra
    /* 1E434 8002DC34 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel func_8002DA1C
