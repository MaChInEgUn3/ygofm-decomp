nonmatching func_8008D2B0, 0x1DC

glabel func_8008D2B0
    /* 7DAB0 8008D2B0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 7DAB4 8008D2B4 1400BFAF */  sw         $ra, 0x14($sp)
    /* 7DAB8 8008D2B8 2CCE010C */  jal        func_800738B0
    /* 7DABC 8008D2BC 1000B0AF */   sw        $s0, 0x10($sp)
    /* 7DAC0 8008D2C0 00F4043C */  lui        $a0, (0xF4000001 >> 16)
    /* 7DAC4 8008D2C4 01008434 */  ori        $a0, $a0, (0xF4000001 & 0xFFFF)
    /* 7DAC8 8008D2C8 04000524 */  addiu      $a1, $zero, 0x4
    /* 7DACC 8008D2CC 00100624 */  addiu      $a2, $zero, 0x1000
    /* 7DAD0 8008D2D0 0980073C */  lui        $a3, %hi(func_8008D1E0)
    /* 7DAD4 8008D2D4 E0D1E724 */  addiu      $a3, $a3, %lo(func_8008D1E0)
    /* 7DAD8 8008D2D8 18CE010C */  jal        func_80073860
    /* 7DADC 8008D2DC 21804000 */   addu      $s0, $v0, $zero
    /* 7DAE0 8008D2E0 00F4043C */  lui        $a0, (0xF4000001 >> 16)
    /* 7DAE4 8008D2E4 01008434 */  ori        $a0, $a0, (0xF4000001 & 0xFFFF)
    /* 7DAE8 8008D2E8 00800534 */  ori        $a1, $zero, 0x8000
    /* 7DAEC 8008D2EC 0980073C */  lui        $a3, %hi(func_8008D1F4)
    /* 7DAF0 8008D2F0 F4D1E724 */  addiu      $a3, $a3, %lo(func_8008D1F4)
    /* 7DAF4 8008D2F4 1080013C */  lui        $at, %hi(D_800FE3F8)
    /* 7DAF8 8008D2F8 F8E322AC */  sw         $v0, %lo(D_800FE3F8)($at)
    /* 7DAFC 8008D2FC 18CE010C */  jal        func_80073860
    /* 7DB00 8008D300 00100624 */   addiu     $a2, $zero, 0x1000
    /* 7DB04 8008D304 00F4043C */  lui        $a0, (0xF4000001 >> 16)
    /* 7DB08 8008D308 01008434 */  ori        $a0, $a0, (0xF4000001 & 0xFFFF)
    /* 7DB0C 8008D30C 00010524 */  addiu      $a1, $zero, 0x100
    /* 7DB10 8008D310 0980073C */  lui        $a3, %hi(func_8008D208)
    /* 7DB14 8008D314 08D2E724 */  addiu      $a3, $a3, %lo(func_8008D208)
    /* 7DB18 8008D318 1080013C */  lui        $at, %hi(D_800FE3FC)
    /* 7DB1C 8008D31C FCE322AC */  sw         $v0, %lo(D_800FE3FC)($at)
    /* 7DB20 8008D320 18CE010C */  jal        func_80073860
    /* 7DB24 8008D324 00100624 */   addiu     $a2, $zero, 0x1000
    /* 7DB28 8008D328 00F4043C */  lui        $a0, (0xF4000001 >> 16)
    /* 7DB2C 8008D32C 01008434 */  ori        $a0, $a0, (0xF4000001 & 0xFFFF)
    /* 7DB30 8008D330 00200524 */  addiu      $a1, $zero, 0x2000
    /* 7DB34 8008D334 0980073C */  lui        $a3, %hi(func_8008D21C)
    /* 7DB38 8008D338 1CD2E724 */  addiu      $a3, $a3, %lo(func_8008D21C)
    /* 7DB3C 8008D33C 1080013C */  lui        $at, %hi(D_800FE400)
    /* 7DB40 8008D340 00E422AC */  sw         $v0, %lo(D_800FE400)($at)
    /* 7DB44 8008D344 18CE010C */  jal        func_80073860
    /* 7DB48 8008D348 00100624 */   addiu     $a2, $zero, 0x1000
    /* 7DB4C 8008D34C 00F0043C */  lui        $a0, (0xF0000011 >> 16)
    /* 7DB50 8008D350 11008434 */  ori        $a0, $a0, (0xF0000011 & 0xFFFF)
    /* 7DB54 8008D354 04000524 */  addiu      $a1, $zero, 0x4
    /* 7DB58 8008D358 0980073C */  lui        $a3, %hi(func_8008D230)
    /* 7DB5C 8008D35C 30D2E724 */  addiu      $a3, $a3, %lo(func_8008D230)
    /* 7DB60 8008D360 1080013C */  lui        $at, %hi(D_800FE404)
    /* 7DB64 8008D364 04E422AC */  sw         $v0, %lo(D_800FE404)($at)
    /* 7DB68 8008D368 18CE010C */  jal        func_80073860
    /* 7DB6C 8008D36C 00100624 */   addiu     $a2, $zero, 0x1000
    /* 7DB70 8008D370 00F0043C */  lui        $a0, (0xF0000011 >> 16)
    /* 7DB74 8008D374 11008434 */  ori        $a0, $a0, (0xF0000011 & 0xFFFF)
    /* 7DB78 8008D378 00800534 */  ori        $a1, $zero, 0x8000
    /* 7DB7C 8008D37C 0980073C */  lui        $a3, %hi(func_8008D244)
    /* 7DB80 8008D380 44D2E724 */  addiu      $a3, $a3, %lo(func_8008D244)
    /* 7DB84 8008D384 1080013C */  lui        $at, %hi(D_800FE408)
    /* 7DB88 8008D388 08E422AC */  sw         $v0, %lo(D_800FE408)($at)
    /* 7DB8C 8008D38C 18CE010C */  jal        func_80073860
    /* 7DB90 8008D390 00100624 */   addiu     $a2, $zero, 0x1000
    /* 7DB94 8008D394 00F0043C */  lui        $a0, (0xF0000011 >> 16)
    /* 7DB98 8008D398 11008434 */  ori        $a0, $a0, (0xF0000011 & 0xFFFF)
    /* 7DB9C 8008D39C 00010524 */  addiu      $a1, $zero, 0x100
    /* 7DBA0 8008D3A0 0980073C */  lui        $a3, %hi(func_8008D258)
    /* 7DBA4 8008D3A4 58D2E724 */  addiu      $a3, $a3, %lo(func_8008D258)
    /* 7DBA8 8008D3A8 1080013C */  lui        $at, %hi(D_800FE40C)
    /* 7DBAC 8008D3AC 0CE422AC */  sw         $v0, %lo(D_800FE40C)($at)
    /* 7DBB0 8008D3B0 18CE010C */  jal        func_80073860
    /* 7DBB4 8008D3B4 00100624 */   addiu     $a2, $zero, 0x1000
    /* 7DBB8 8008D3B8 00F0043C */  lui        $a0, (0xF0000011 >> 16)
    /* 7DBBC 8008D3BC 11008434 */  ori        $a0, $a0, (0xF0000011 & 0xFFFF)
    /* 7DBC0 8008D3C0 00200524 */  addiu      $a1, $zero, 0x2000
    /* 7DBC4 8008D3C4 0980073C */  lui        $a3, %hi(func_8008D26C)
    /* 7DBC8 8008D3C8 6CD2E724 */  addiu      $a3, $a3, %lo(func_8008D26C)
    /* 7DBCC 8008D3CC 1080013C */  lui        $at, %hi(D_800FE410)
    /* 7DBD0 8008D3D0 10E422AC */  sw         $v0, %lo(D_800FE410)($at)
    /* 7DBD4 8008D3D4 18CE010C */  jal        func_80073860
    /* 7DBD8 8008D3D8 00100624 */   addiu     $a2, $zero, 0x1000
    /* 7DBDC 8008D3DC 1080043C */  lui        $a0, %hi(D_800FE3F8)
    /* 7DBE0 8008D3E0 F8E3848C */  lw         $a0, %lo(D_800FE3F8)($a0)
    /* 7DBE4 8008D3E4 1080013C */  lui        $at, %hi(D_800FE414)
    /* 7DBE8 8008D3E8 24CE010C */  jal        func_80073890
    /* 7DBEC 8008D3EC 14E422AC */   sw        $v0, %lo(D_800FE414)($at)
    /* 7DBF0 8008D3F0 1080043C */  lui        $a0, %hi(D_800FE3FC)
    /* 7DBF4 8008D3F4 FCE3848C */  lw         $a0, %lo(D_800FE3FC)($a0)
    /* 7DBF8 8008D3F8 24CE010C */  jal        func_80073890
    /* 7DBFC 8008D3FC 00000000 */   nop
    /* 7DC00 8008D400 1080043C */  lui        $a0, %hi(D_800FE400)
    /* 7DC04 8008D404 00E4848C */  lw         $a0, %lo(D_800FE400)($a0)
    /* 7DC08 8008D408 24CE010C */  jal        func_80073890
    /* 7DC0C 8008D40C 00000000 */   nop
    /* 7DC10 8008D410 1080043C */  lui        $a0, %hi(D_800FE404)
    /* 7DC14 8008D414 04E4848C */  lw         $a0, %lo(D_800FE404)($a0)
    /* 7DC18 8008D418 24CE010C */  jal        func_80073890
    /* 7DC1C 8008D41C 00000000 */   nop
    /* 7DC20 8008D420 1080043C */  lui        $a0, %hi(D_800FE408)
    /* 7DC24 8008D424 08E4848C */  lw         $a0, %lo(D_800FE408)($a0)
    /* 7DC28 8008D428 24CE010C */  jal        func_80073890
    /* 7DC2C 8008D42C 00000000 */   nop
    /* 7DC30 8008D430 1080043C */  lui        $a0, %hi(D_800FE40C)
    /* 7DC34 8008D434 0CE4848C */  lw         $a0, %lo(D_800FE40C)($a0)
    /* 7DC38 8008D438 24CE010C */  jal        func_80073890
    /* 7DC3C 8008D43C 00000000 */   nop
    /* 7DC40 8008D440 1080043C */  lui        $a0, %hi(D_800FE410)
    /* 7DC44 8008D444 10E4848C */  lw         $a0, %lo(D_800FE410)($a0)
    /* 7DC48 8008D448 24CE010C */  jal        func_80073890
    /* 7DC4C 8008D44C 00000000 */   nop
    /* 7DC50 8008D450 1080043C */  lui        $a0, %hi(D_800FE414)
    /* 7DC54 8008D454 14E4848C */  lw         $a0, %lo(D_800FE414)($a0)
    /* 7DC58 8008D458 24CE010C */  jal        func_80073890
    /* 7DC5C 8008D45C 00000000 */   nop
    /* 7DC60 8008D460 5835020C */  jal        func_8008D560
    /* 7DC64 8008D464 00000000 */   nop
    /* 7DC68 8008D468 01000224 */  addiu      $v0, $zero, 0x1
    /* 7DC6C 8008D46C 03000216 */  bne        $s0, $v0, .L8008D47C
    /* 7DC70 8008D470 00000000 */   nop
    /* 7DC74 8008D474 30CE010C */  jal        func_800738C0
    /* 7DC78 8008D478 00000000 */   nop
  .L8008D47C:
    /* 7DC7C 8008D47C 1400BF8F */  lw         $ra, 0x14($sp)
    /* 7DC80 8008D480 1000B08F */  lw         $s0, 0x10($sp)
    /* 7DC84 8008D484 0800E003 */  jr         $ra
    /* 7DC88 8008D488 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8008D2B0
