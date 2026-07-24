nonmatching func_8002D180, 0x158

glabel func_8002D180
    /* 1D980 8002D180 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 1D984 8002D184 A0000424 */  addiu      $a0, $zero, 0xA0
    /* 1D988 8002D188 78000524 */  addiu      $a1, $zero, 0x78
    /* 1D98C 8002D18C 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 1D990 8002D190 2C1E020C */  jal        func_800878B0
    /* 1D994 8002D194 1800B0AF */   sw        $s0, 0x18($sp)
    /* 1D998 8002D198 341E020C */  jal        func_800878D0
    /* 1D99C 8002D19C 2C010424 */   addiu     $a0, $zero, 0x12C
    /* 1D9A0 8002D1A0 64038393 */  lbu        $v1, %gp_rel(D_8009B26C)($gp)
    /* 1D9A4 8002D1A4 00000000 */  nop
    /* 1D9A8 8002D1A8 40006230 */  andi       $v0, $v1, 0x40
    /* 1D9AC 8002D1AC 33004014 */  bnez       $v0, .L8002D27C
    /* 1D9B0 8002D1B0 20006230 */   andi      $v0, $v1, 0x20
    /* 1D9B4 8002D1B4 40006234 */  ori        $v0, $v1, 0x40
    /* 1D9B8 8002D1B8 640382A3 */  sb         $v0, %gp_rel(D_8009B26C)($gp)
    /* 1D9BC 8002D1BC 01000224 */  addiu      $v0, $zero, 0x1
    /* 1D9C0 8002D1C0 0A80013C */  lui        $at, %hi(D_8009B0C0)
    /* 1D9C4 8002D1C4 C0B022A0 */  sb         $v0, %lo(D_8009B0C0)($at)
    /* 1D9C8 8002D1C8 314C010C */  jal        func_800530C4
    /* 1D9CC 8002D1CC 00000000 */   nop
    /* 1D9D0 8002D1D0 F64C010C */  jal        func_800533D8
    /* 1D9D4 8002D1D4 00000000 */   nop
    /* 1D9D8 8002D1D8 0F80023C */  lui        $v0, %hi(D_800EF658)
    /* 1D9DC 8002D1DC 58F65024 */  addiu      $s0, $v0, %lo(D_800EF658)
    /* 1D9E0 8002D1E0 58F64584 */  lh         $a1, %lo(D_800EF658)($v0)
    /* 1D9E4 8002D1E4 09030224 */  addiu      $v0, $zero, 0x309
    /* 1D9E8 8002D1E8 0900A214 */  bne        $a1, $v0, .L8002D210
    /* 1D9EC 8002D1EC 21200000 */   addu      $a0, $zero, $zero
    /* 1D9F0 8002D1F0 64038293 */  lbu        $v0, %gp_rel(D_8009B26C)($gp)
    /* 1D9F4 8002D1F4 00000000 */  nop
    /* 1D9F8 8002D1F8 20004234 */  ori        $v0, $v0, 0x20
    /* 1D9FC 8002D1FC 640382A3 */  sb         $v0, %gp_rel(D_8009B26C)($gp)
    /* 1DA00 8002D200 0967010C */  jal        func_80059C24
    /* 1DA04 8002D204 00000000 */   nop
    /* 1DA08 8002D208 9BB40008 */  j          .L8002D26C
    /* 1DA0C 8002D20C 00000000 */   nop
  .L8002D210:
    /* 1DA10 8002D210 02000686 */  lh         $a2, 0x2($s0)
    /* 1DA14 8002D214 04000786 */  lh         $a3, 0x4($s0)
    /* 1DA18 8002D218 07000292 */  lbu        $v0, 0x7($s0)
    /* 1DA1C 8002D21C FFFFA524 */  addiu      $a1, $a1, -0x1
    /* 1DA20 8002D220 1000A2AF */  sw         $v0, 0x10($sp)
    /* 1DA24 8002D224 06000292 */  lbu        $v0, 0x6($s0)
    /* 1DA28 8002D228 08001026 */  addiu      $s0, $s0, 0x8
    /* 1DA2C 8002D22C 924C010C */  jal        func_80053248
    /* 1DA30 8002D230 1400A2AF */   sw        $v0, 0x14($sp)
    /* 1DA34 8002D234 00000586 */  lh         $a1, 0x0($s0)
    /* 1DA38 8002D238 02000686 */  lh         $a2, 0x2($s0)
    /* 1DA3C 8002D23C 04000786 */  lh         $a3, 0x4($s0)
    /* 1DA40 8002D240 07000292 */  lbu        $v0, 0x7($s0)
    /* 1DA44 8002D244 01000424 */  addiu      $a0, $zero, 0x1
    /* 1DA48 8002D248 1000A2AF */  sw         $v0, 0x10($sp)
    /* 1DA4C 8002D24C 06000292 */  lbu        $v0, 0x6($s0)
    /* 1DA50 8002D250 FFFFA524 */  addiu      $a1, $a1, -0x1
    /* 1DA54 8002D254 924C010C */  jal        func_80053248
    /* 1DA58 8002D258 1400A2AF */   sw        $v0, 0x14($sp)
    /* 1DA5C 8002D25C 0A80053C */  lui        $a1, %hi(D_8009B364)
    /* 1DA60 8002D260 64B3A590 */  lbu        $a1, %lo(D_8009B364)($a1)
    /* 1DA64 8002D264 924C010C */  jal        func_80053248
    /* 1DA68 8002D268 02000424 */   addiu     $a0, $zero, 0x2
  .L8002D26C:
    /* 1DA6C 8002D26C 7656000C */  jal        func_800159D8
    /* 1DA70 8002D270 00000000 */   nop
    /* 1DA74 8002D274 B2B40008 */  j          .L8002D2C8
    /* 1DA78 8002D278 00000000 */   nop
  .L8002D27C:
    /* 1DA7C 8002D27C 05004010 */  beqz       $v0, .L8002D294
    /* 1DA80 8002D280 00000000 */   nop
    /* 1DA84 8002D284 2267010C */  jal        func_80059C88
    /* 1DA88 8002D288 00000000 */   nop
    /* 1DA8C 8002D28C A7B40008 */  j          .L8002D29C
    /* 1DA90 8002D290 00000000 */   nop
  .L8002D294:
    /* 1DA94 8002D294 2E4D010C */  jal        func_800534B8
    /* 1DA98 8002D298 00000000 */   nop
  .L8002D29C:
    /* 1DA9C 8002D29C 08004010 */  beqz       $v0, .L8002D2C0
    /* 1DAA0 8002D2A0 00000000 */   nop
    /* 1DAA4 8002D2A4 B11F010C */  jal        func_80047EC4
    /* 1DAA8 8002D2A8 00000000 */   nop
    /* 1DAAC 8002D2AC CDFF000C */  jal        func_8003FF34
    /* 1DAB0 8002D2B0 00000000 */   nop
    /* 1DAB4 8002D2B4 61038293 */  lbu        $v0, %gp_rel(D_8009B269)($gp)
    /* 1DAB8 8002D2B8 00000000 */  nop
    /* 1DABC 8002D2BC 640382A3 */  sb         $v0, %gp_rel(D_8009B26C)($gp)
  .L8002D2C0:
    /* 1DAC0 8002D2C0 3967010C */  jal        func_80059CE4
    /* 1DAC4 8002D2C4 00000000 */   nop
  .L8002D2C8:
    /* 1DAC8 8002D2C8 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 1DACC 8002D2CC 1800B08F */  lw         $s0, 0x18($sp)
    /* 1DAD0 8002D2D0 0800E003 */  jr         $ra
    /* 1DAD4 8002D2D4 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8002D180
