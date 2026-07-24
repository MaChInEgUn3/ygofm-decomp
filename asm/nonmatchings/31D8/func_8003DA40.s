nonmatching func_8003DA40, 0x1DC

glabel func_8003DA40
    /* 2E240 8003DA40 B9048393 */  lbu        $v1, %gp_rel(D_8009B3C1)($gp)
    /* 2E244 8003DA44 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 2E248 8003DA48 2800B2AF */  sw         $s2, 0x28($sp)
    /* 2E24C 8003DA4C 21908000 */  addu       $s2, $a0, $zero
    /* 2E250 8003DA50 2C00BFAF */  sw         $ra, 0x2C($sp)
    /* 2E254 8003DA54 2400B1AF */  sw         $s1, 0x24($sp)
    /* 2E258 8003DA58 80006230 */  andi       $v0, $v1, 0x80
    /* 2E25C 8003DA5C 38004014 */  bnez       $v0, .L8003DB40
    /* 2E260 8003DA60 2000B0AF */   sw        $s0, 0x20($sp)
    /* 2E264 8003DA64 80006234 */  ori        $v0, $v1, 0x80
    /* 2E268 8003DA68 B90482A3 */  sb         $v0, %gp_rel(D_8009B3C1)($gp)
    /* 2E26C 8003DA6C 0B00010C */  jal        func_8004002C
    /* 2E270 8003DA70 00000000 */   nop
    /* 2E274 8003DA74 21204000 */  addu       $a0, $v0, $zero
    /* 2E278 8003DA78 2B00010C */  jal        func_800400AC
    /* 2E27C 8003DA7C 02000524 */   addiu     $a1, $zero, 0x2
    /* 2E280 8003DA80 21804000 */  addu       $s0, $v0, $zero
    /* 2E284 8003DA84 21200002 */  addu       $a0, $s0, $zero
    /* 2E288 8003DA88 20000524 */  addiu      $a1, $zero, 0x20
    /* 2E28C 8003DA8C C0FF0624 */  addiu      $a2, $zero, -0x40
    /* 2E290 8003DA90 03000724 */  addiu      $a3, $zero, 0x3
    /* 2E294 8003DA94 02000224 */  addiu      $v0, $zero, 0x2
    /* 2E298 8003DA98 1000A2AF */  sw         $v0, 0x10($sp)
    /* 2E29C 8003DA9C 0B000224 */  addiu      $v0, $zero, 0xB
    /* 2E2A0 8003DAA0 1800A2AF */  sw         $v0, 0x18($sp)
    /* 2E2A4 8003DAA4 0C020224 */  addiu      $v0, $zero, 0x20C
    /* 2E2A8 8003DAA8 1400A0AF */  sw         $zero, 0x14($sp)
    /* 2E2AC 8003DAAC 3301010C */  jal        func_800404CC
    /* 2E2B0 8003DAB0 1C00A2AF */   sw        $v0, 0x1C($sp)
    /* 2E2B4 8003DAB4 08000296 */  lhu        $v0, 0x8($s0)
    /* 2E2B8 8003DAB8 21200002 */  addu       $a0, $s0, $zero
    /* 2E2BC 8003DABC 28004234 */  ori        $v0, $v0, 0x28
    /* 2E2C0 8003DAC0 460A010C */  jal        func_80042918
    /* 2E2C4 8003DAC4 080002A6 */   sh        $v0, 0x8($s0)
    /* 2E2C8 8003DAC8 0A80053C */  lui        $a1, %hi(D_8009AF76)
    /* 2E2CC 8003DACC 76AFA590 */  lbu        $a1, %lo(D_8009AF76)($a1)
    /* 2E2D0 8003DAD0 21200002 */  addu       $a0, $s0, $zero
    /* 2E2D4 8003DAD4 FEFFA524 */  addiu      $a1, $a1, -0x2
    /* 2E2D8 8003DAD8 002E0500 */  sll        $a1, $a1, 24
    /* 2E2DC 8003DADC 3B0A010C */  jal        func_800428EC
    /* 2E2E0 8003DAE0 032E0500 */   sra       $a1, $a1, 24
    /* 2E2E4 8003DAE4 21200002 */  addu       $a0, $s0, $zero
    /* 2E2E8 8003DAE8 5E0C010C */  jal        func_80043178
    /* 2E2EC 8003DAEC 000050AE */   sw        $s0, 0x0($s2)
    /* 2E2F0 8003DAF0 D0000424 */  addiu      $a0, $zero, 0xD0
    /* 2E2F4 8003DAF4 21280000 */  addu       $a1, $zero, $zero
    /* 2E2F8 8003DAF8 00FC0224 */  addiu      $v0, $zero, -0x400
    /* 2E2FC 8003DAFC 1BF5000C */  jal        func_8003D46C
    /* 2E300 8003DB00 600002A6 */   sh        $v0, 0x60($s0)
    /* 2E304 8003DB04 21884000 */  addu       $s1, $v0, $zero
    /* 2E308 8003DB08 34002296 */  lhu        $v0, 0x34($s1)
    /* 2E30C 8003DB0C 00000000 */  nop
    /* 2E310 8003DB10 04004234 */  ori        $v0, $v0, 0x4
    /* 2E314 8003DB14 340022A6 */  sh         $v0, 0x34($s1)
  .L8003DB18:
    /* 2E318 8003DB18 E5E5000C */  jal        func_80039794
    /* 2E31C 8003DB1C 00000000 */   nop
    /* 2E320 8003DB20 3000228E */  lw         $v0, 0x30($s1)
    /* 2E324 8003DB24 00000000 */  nop
    /* 2E328 8003DB28 FBFF4010 */  beqz       $v0, .L8003DB18
    /* 2E32C 8003DB2C 00000000 */   nop
    /* 2E330 8003DB30 30000586 */  lh         $a1, 0x30($s0)
    /* 2E334 8003DB34 32000686 */  lh         $a2, 0x32($s0)
    /* 2E338 8003DB38 4DE6000C */  jal        func_80039934
    /* 2E33C 8003DB3C 21202002 */   addu      $a0, $s1, $zero
  .L8003DB40:
    /* 2E340 8003DB40 1A004392 */  lbu        $v1, 0x1A($s2)
    /* 2E344 8003DB44 0000508E */  lw         $s0, 0x0($s2)
    /* 2E348 8003DB48 B9048493 */  lbu        $a0, %gp_rel(D_8009B3C1)($gp)
    /* 2E34C 8003DB4C 40100300 */  sll        $v0, $v1, 1
    /* 2E350 8003DB50 21104300 */  addu       $v0, $v0, $v1
    /* 2E354 8003DB54 C0100200 */  sll        $v0, $v0, 3
    /* 2E358 8003DB58 21104300 */  addu       $v0, $v0, $v1
    /* 2E35C 8003DB5C 80100200 */  sll        $v0, $v0, 2
    /* 2E360 8003DB60 0F80033C */  lui        $v1, %hi(D_800EB0F8)
    /* 2E364 8003DB64 F8B06324 */  addiu      $v1, $v1, %lo(D_800EB0F8)
    /* 2E368 8003DB68 21884300 */  addu       $s1, $v0, $v1
    /* 2E36C 8003DB6C 40008230 */  andi       $v0, $a0, 0x40
    /* 2E370 8003DB70 0B004010 */  beqz       $v0, .L8003DBA0
    /* 2E374 8003DB74 00000000 */   nop
    /* 2E378 8003DB78 E5E5000C */  jal        func_80039794
    /* 2E37C 8003DB7C 00000000 */   nop
    /* 2E380 8003DB80 34002296 */  lhu        $v0, 0x34($s1)
    /* 2E384 8003DB84 00000000 */  nop
    /* 2E388 8003DB88 00204230 */  andi       $v0, $v0, 0x2000
    /* 2E38C 8003DB8C 1D004010 */  beqz       $v0, .L8003DC04
    /* 2E390 8003DB90 00000000 */   nop
    /* 2E394 8003DB94 B90480A3 */  sb         $zero, %gp_rel(D_8009B3C1)($gp)
    /* 2E398 8003DB98 01F70008 */  j          .L8003DC04
    /* 2E39C 8003DB9C 00000000 */   nop
  .L8003DBA0:
    /* 2E3A0 8003DBA0 60000296 */  lhu        $v0, 0x60($s0)
    /* 2E3A4 8003DBA4 00000000 */  nop
    /* 2E3A8 8003DBA8 20004224 */  addiu      $v0, $v0, 0x20
    /* 2E3AC 8003DBAC 600002A6 */  sh         $v0, 0x60($s0)
    /* 2E3B0 8003DBB0 00140200 */  sll        $v0, $v0, 16
    /* 2E3B4 8003DBB4 033C0200 */  sra        $a3, $v0, 16
    /* 2E3B8 8003DBB8 0A00E004 */  bltz       $a3, .L8003DBE4
    /* 2E3BC 8003DBBC 20000224 */   addiu     $v0, $zero, 0x20
    /* 2E3C0 8003DBC0 300002A6 */  sh         $v0, 0x30($s0)
    /* 2E3C4 8003DBC4 50000224 */  addiu      $v0, $zero, 0x50
    /* 2E3C8 8003DBC8 320002A6 */  sh         $v0, 0x32($s0)
    /* 2E3CC 8003DBCC 34002296 */  lhu        $v0, 0x34($s1)
    /* 2E3D0 8003DBD0 40008334 */  ori        $v1, $a0, 0x40
    /* 2E3D4 8003DBD4 B90483A3 */  sb         $v1, %gp_rel(D_8009B3C1)($gp)
    /* 2E3D8 8003DBD8 FBFF4230 */  andi       $v0, $v0, 0xFFFB
    /* 2E3DC 8003DBDC FDF60008 */  j          .L8003DBF4
    /* 2E3E0 8003DBE0 340022A6 */   sh        $v0, 0x34($s1)
  .L8003DBE4:
    /* 2E3E4 8003DBE4 21200002 */  addu       $a0, $s0, $zero
    /* 2E3E8 8003DBE8 20000524 */  addiu      $a1, $zero, 0x20
    /* 2E3EC 8003DBEC 8C0C010C */  jal        func_80043230
    /* 2E3F0 8003DBF0 50000624 */   addiu     $a2, $zero, 0x50
  .L8003DBF4:
    /* 2E3F4 8003DBF4 30000586 */  lh         $a1, 0x30($s0)
    /* 2E3F8 8003DBF8 32000686 */  lh         $a2, 0x32($s0)
    /* 2E3FC 8003DBFC 4DE6000C */  jal        func_80039934
    /* 2E400 8003DC00 21202002 */   addu      $a0, $s1, $zero
  .L8003DC04:
    /* 2E404 8003DC04 2C00BF8F */  lw         $ra, 0x2C($sp)
    /* 2E408 8003DC08 2800B28F */  lw         $s2, 0x28($sp)
    /* 2E40C 8003DC0C 2400B18F */  lw         $s1, 0x24($sp)
    /* 2E410 8003DC10 2000B08F */  lw         $s0, 0x20($sp)
    /* 2E414 8003DC14 0800E003 */  jr         $ra
    /* 2E418 8003DC18 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel func_8003DA40
