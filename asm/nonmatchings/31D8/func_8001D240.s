nonmatching func_8001D240, 0x104

glabel func_8001D240
    /* DA40 8001D240 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* DA44 8001D244 1000B0AF */  sw         $s0, 0x10($sp)
    /* DA48 8001D248 1400BFAF */  sw         $ra, 0x14($sp)
    /* DA4C 8001D24C E60A010C */  jal        func_80042B98
    /* DA50 8001D250 21808000 */   addu      $s0, $a0, $zero
    /* DA54 8001D254 0E004014 */  bnez       $v0, .L8001D290
    /* DA58 8001D258 00000000 */   nop
    /* DA5C 8001D25C 08000296 */  lhu        $v0, 0x8($s0)
    /* DA60 8001D260 22000392 */  lbu        $v1, 0x22($s0)
    /* DA64 8001D264 04004234 */  ori        $v0, $v0, 0x4
    /* DA68 8001D268 06006014 */  bnez       $v1, .L8001D284
    /* DA6C 8001D26C 080002A6 */   sh        $v0, 0x8($s0)
    /* DA70 8001D270 F8FF0224 */  addiu      $v0, $zero, -0x8
    /* DA74 8001D274 280002A6 */  sh         $v0, 0x28($s0)
    /* DA78 8001D278 C0000224 */  addiu      $v0, $zero, 0xC0
    /* DA7C 8001D27C A4740008 */  j          .L8001D290
    /* DA80 8001D280 2A0002A6 */   sh        $v0, 0x2A($s0)
  .L8001D284:
    /* DA84 8001D284 08000224 */  addiu      $v0, $zero, 0x8
    /* DA88 8001D288 280002A6 */  sh         $v0, 0x28($s0)
    /* DA8C 8001D28C 2A0000A6 */  sh         $zero, 0x2A($s0)
  .L8001D290:
    /* DA90 8001D290 22000292 */  lbu        $v0, 0x22($s0)
    /* DA94 8001D294 28000392 */  lbu        $v1, 0x28($s0)
    /* DA98 8001D298 00000000 */  nop
    /* DA9C 8001D29C 21104300 */  addu       $v0, $v0, $v1
    /* DAA0 8001D2A0 220002A2 */  sb         $v0, 0x22($s0)
    /* DAA4 8001D2A4 FF004230 */  andi       $v0, $v0, 0xFF
    /* DAA8 8001D2A8 C000422C */  sltiu      $v0, $v0, 0xC0
    /* DAAC 8001D2AC 21004010 */  beqz       $v0, .L8001D334
    /* DAB0 8001D2B0 00000000 */   nop
    /* DAB4 8001D2B4 6A000292 */  lbu        $v0, 0x6A($s0)
    /* DAB8 8001D2B8 00000000 */  nop
    /* DABC 8001D2BC C0180200 */  sll        $v1, $v0, 3
    /* DAC0 8001D2C0 23186200 */  subu       $v1, $v1, $v0
    /* DAC4 8001D2C4 80180300 */  sll        $v1, $v1, 2
    /* DAC8 8001D2C8 1A80023C */  lui        $v0, %hi(D_801A7AD8)
    /* DACC 8001D2CC D87A4224 */  addiu      $v0, $v0, %lo(D_801A7AD8)
    /* DAD0 8001D2D0 21186200 */  addu       $v1, $v1, $v0
    /* DAD4 8001D2D4 16006294 */  lhu        $v0, 0x16($v1)
    /* DAD8 8001D2D8 00000000 */  nop
    /* DADC 8001D2DC 00084234 */  ori        $v0, $v0, 0x800
    /* DAE0 8001D2E0 160062A4 */  sh         $v0, 0x16($v1)
    /* DAE4 8001D2E4 2A000292 */  lbu        $v0, 0x2A($s0)
    /* DAE8 8001D2E8 00000000 */  nop
    /* DAEC 8001D2EC 220002A2 */  sb         $v0, 0x22($s0)
    /* DAF0 8001D2F0 FF004230 */  andi       $v0, $v0, 0xFF
    /* DAF4 8001D2F4 0D004014 */  bnez       $v0, .L8001D32C
    /* DAF8 8001D2F8 00000000 */   nop
    /* DAFC 8001D2FC 16006294 */  lhu        $v0, 0x16($v1)
    /* DB00 8001D300 00000000 */  nop
    /* DB04 8001D304 FFF74230 */  andi       $v0, $v0, 0xF7FF
    /* DB08 8001D308 160062A4 */  sh         $v0, 0x16($v1)
    /* DB0C 8001D30C 21000292 */  lbu        $v0, 0x21($s0)
    /* DB10 8001D310 00000000 */  nop
    /* DB14 8001D314 05004014 */  bnez       $v0, .L8001D32C
    /* DB18 8001D318 00000000 */   nop
    /* DB1C 8001D31C 08000296 */  lhu        $v0, 0x8($s0)
    /* DB20 8001D320 00000000 */  nop
    /* DB24 8001D324 FBFF4230 */  andi       $v0, $v0, 0xFFFB
    /* DB28 8001D328 080002A6 */  sh         $v0, 0x8($s0)
  .L8001D32C:
    /* DB2C 8001D32C 6C0000A2 */  sb         $zero, 0x6C($s0)
    /* DB30 8001D330 240000AE */  sw         $zero, 0x24($s0)
  .L8001D334:
    /* DB34 8001D334 1400BF8F */  lw         $ra, 0x14($sp)
    /* DB38 8001D338 1000B08F */  lw         $s0, 0x10($sp)
    /* DB3C 8001D33C 0800E003 */  jr         $ra
    /* DB40 8001D340 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8001D240
