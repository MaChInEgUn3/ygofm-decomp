nonmatching func_8007D2F0, 0xD4

glabel func_8007D2F0
    /* 6DAF0 8007D2F0 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 6DAF4 8007D2F4 2000B2AF */  sw         $s2, 0x20($sp)
    /* 6DAF8 8007D2F8 21908000 */  addu       $s2, $a0, $zero
    /* 6DAFC 8007D2FC 1800B0AF */  sw         $s0, 0x18($sp)
    /* 6DB00 8007D300 2180A000 */  addu       $s0, $a1, $zero
    /* 6DB04 8007D304 00010232 */  andi       $v0, $s0, 0x100
    /* 6DB08 8007D308 2400BFAF */  sw         $ra, 0x24($sp)
    /* 6DB0C 8007D30C 20004010 */  beqz       $v0, .L8007D390
    /* 6DB10 8007D310 1C00B1AF */   sw        $s1, 0x1C($sp)
    /* 6DB14 8007D314 20000232 */  andi       $v0, $s0, 0x20
    /* 6DB18 8007D318 04004010 */  beqz       $v0, .L8007D32C
    /* 6DB1C 8007D31C 01000224 */   addiu     $v0, $zero, 0x1
    /* 6DB20 8007D320 0F80013C */  lui        $at, %hi(D_800F5DD8)
    /* 6DB24 8007D324 CDF40108 */  j          .L8007D334
    /* 6DB28 8007D328 D85D20AC */   sw        $zero, %lo(D_800F5DD8)($at)
  .L8007D32C:
    /* 6DB2C 8007D32C 0F80013C */  lui        $at, %hi(D_800F5DD8)
    /* 6DB30 8007D330 D85D22AC */  sw         $v0, %lo(D_800F5DD8)($at)
  .L8007D334:
    /* 6DB34 8007D334 0880043C */  lui        $a0, %hi(func_80078350)
    /* 6DB38 8007D338 28FA010C */  jal        func_8007E8A0
    /* 6DB3C 8007D33C 50838424 */   addiu     $a0, $a0, %lo(func_80078350)
    /* 6DB40 8007D340 0880043C */  lui        $a0, %hi(func_8007D3C4)
    /* 6DB44 8007D344 C4D38424 */  addiu      $a0, $a0, %lo(func_8007D3C4)
    /* 6DB48 8007D348 18FA010C */  jal        func_8007E860
    /* 6DB4C 8007D34C 21884000 */   addu      $s1, $v0, $zero
    /* 6DB50 8007D350 FFFF0324 */  addiu      $v1, $zero, -0x1
    /* 6DB54 8007D354 1000A3AF */  sw         $v1, 0x10($sp)
    /* 6DB58 8007D358 FF000432 */  andi       $a0, $s0, 0xFF
    /* 6DB5C 8007D35C 21284002 */  addu       $a1, $s2, $zero
    /* 6DB60 8007D360 1B000624 */  addiu      $a2, $zero, 0x1B
    /* 6DB64 8007D364 21380000 */  addu       $a3, $zero, $zero
    /* 6DB68 8007D368 1AED010C */  jal        func_8007B468
    /* 6DB6C 8007D36C 21804000 */   addu      $s0, $v0, $zero
    /* 6DB70 8007D370 0E004014 */  bnez       $v0, .L8007D3AC
    /* 6DB74 8007D374 00000000 */   nop
    /* 6DB78 8007D378 28FA010C */  jal        func_8007E8A0
    /* 6DB7C 8007D37C 21202002 */   addu      $a0, $s1, $zero
    /* 6DB80 8007D380 18FA010C */  jal        func_8007E860
    /* 6DB84 8007D384 21200002 */   addu      $a0, $s0, $zero
    /* 6DB88 8007D388 EBF40108 */  j          .L8007D3AC
    /* 6DB8C 8007D38C 21100000 */   addu      $v0, $zero, $zero
  .L8007D390:
    /* 6DB90 8007D390 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 6DB94 8007D394 1000A2AF */  sw         $v0, 0x10($sp)
    /* 6DB98 8007D398 FF000432 */  andi       $a0, $s0, 0xFF
    /* 6DB9C 8007D39C 21284002 */  addu       $a1, $s2, $zero
    /* 6DBA0 8007D3A0 1B000624 */  addiu      $a2, $zero, 0x1B
    /* 6DBA4 8007D3A4 1AED010C */  jal        func_8007B468
    /* 6DBA8 8007D3A8 21380000 */   addu      $a3, $zero, $zero
  .L8007D3AC:
    /* 6DBAC 8007D3AC 2400BF8F */  lw         $ra, 0x24($sp)
    /* 6DBB0 8007D3B0 2000B28F */  lw         $s2, 0x20($sp)
    /* 6DBB4 8007D3B4 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 6DBB8 8007D3B8 1800B08F */  lw         $s0, 0x18($sp)
    /* 6DBBC 8007D3BC 0800E003 */  jr         $ra
    /* 6DBC0 8007D3C0 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_8007D2F0
