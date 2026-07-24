nonmatching func_8007D234, 0x9C

glabel func_8007D234
    /* 6DA34 8007D234 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 6DA38 8007D238 0980033C */  lui        $v1, %hi(D_800939F8)
    /* 6DA3C 8007D23C F839638C */  lw         $v1, %lo(D_800939F8)($v1)
    /* 6DA40 8007D240 01000224 */  addiu      $v0, $zero, 0x1
    /* 6DA44 8007D244 1C006214 */  bne        $v1, $v0, .L8007D2B8
    /* 6DA48 8007D248 1000BFAF */   sw        $ra, 0x10($sp)
    /* 6DA4C 8007D24C 0E008010 */  beqz       $a0, .L8007D288
    /* 6DA50 8007D250 00000000 */   nop
    /* 6DA54 8007D254 23F3010C */  jal        func_8007CC8C
    /* 6DA58 8007D258 00000000 */   nop
    /* 6DA5C 8007D25C 6BEA010C */  jal        func_8007A9AC
    /* 6DA60 8007D260 00000000 */   nop
    /* 6DA64 8007D264 A6F8010C */  jal        func_8007E298
    /* 6DA68 8007D268 00000000 */   nop
    /* 6DA6C 8007D26C 41F3010C */  jal        func_8007CD04
    /* 6DA70 8007D270 00000000 */   nop
    /* 6DA74 8007D274 09000424 */  addiu      $a0, $zero, 0x9
    /* 6DA78 8007D278 DCEF010C */  jal        func_8007BF70
    /* 6DA7C 8007D27C 21280000 */   addu      $a1, $zero, $zero
    /* 6DA80 8007D280 A4F40108 */  j          .L8007D290
    /* 6DA84 8007D284 00000000 */   nop
  .L8007D288:
    /* 6DA88 8007D288 E4F8010C */  jal        func_8007E390
    /* 6DA8C 8007D28C 00000000 */   nop
  .L8007D290:
    /* 6DA90 8007D290 0980033C */  lui        $v1, %hi(D_800939E4)
    /* 6DA94 8007D294 E4396324 */  addiu      $v1, $v1, %lo(D_800939E4)
    /* 6DA98 8007D298 0000628C */  lw         $v0, 0x0($v1)
    /* 6DA9C 8007D29C 00000000 */  nop
    /* 6DAA0 8007D2A0 01004230 */  andi       $v0, $v0, 0x1
    /* 6DAA4 8007D2A4 04004010 */  beqz       $v0, .L8007D2B8
    /* 6DAA8 8007D2A8 00000000 */   nop
    /* 6DAAC 8007D2AC 0800648C */  lw         $a0, 0x8($v1)
    /* 6DAB0 8007D2B0 28FA010C */  jal        func_8007E8A0
    /* 6DAB4 8007D2B4 00000000 */   nop
  .L8007D2B8:
    /* 6DAB8 8007D2B8 0980013C */  lui        $at, %hi(D_800939F8)
    /* 6DABC 8007D2BC F83920AC */  sw         $zero, %lo(D_800939F8)($at)
    /* 6DAC0 8007D2C0 1000BF8F */  lw         $ra, 0x10($sp)
    /* 6DAC4 8007D2C4 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 6DAC8 8007D2C8 0800E003 */  jr         $ra
    /* 6DACC 8007D2CC 00000000 */   nop
endlabel func_8007D234
