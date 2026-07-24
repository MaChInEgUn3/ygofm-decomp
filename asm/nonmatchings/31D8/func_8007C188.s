nonmatching func_8007C188, 0x2D0

glabel func_8007C188
    /* 6C988 8007C188 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 6C98C 8007C18C 0980033C */  lui        $v1, %hi(D_800938C4)
    /* 6C990 8007C190 C4386324 */  addiu      $v1, $v1, %lo(D_800938C4)
    /* 6C994 8007C194 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 6C998 8007C198 1800B0AF */  sw         $s0, 0x18($sp)
    /* 6C99C 8007C19C 0000628C */  lw         $v0, 0x0($v1)
    /* 6C9A0 8007C1A0 00000000 */  nop
    /* 6C9A4 8007C1A4 07004018 */  blez       $v0, .L8007C1C4
    /* 6C9A8 8007C1A8 FFFF4224 */   addiu     $v0, $v0, -0x1
    /* 6C9AC 8007C1AC 05004014 */  bnez       $v0, .L8007C1C4
    /* 6C9B0 8007C1B0 000062AC */   sw        $v0, 0x0($v1)
    /* 6C9B4 8007C1B4 16F1010C */  jal        func_8007C458
    /* 6C9B8 8007C1B8 00000000 */   nop
    /* 6C9BC 8007C1BC 12F10108 */  j          .L8007C448
    /* 6C9C0 8007C1C0 00000000 */   nop
  .L8007C1C4:
    /* 6C9C4 8007C1C4 0980043C */  lui        $a0, %hi(D_800938C0)
    /* 6C9C8 8007C1C8 C0388424 */  addiu      $a0, $a0, %lo(D_800938C0)
    /* 6C9CC 8007C1CC 0000828C */  lw         $v0, 0x0($a0)
    /* 6C9D0 8007C1D0 00000000 */  nop
    /* 6C9D4 8007C1D4 02004018 */  blez       $v0, .L8007C1E0
    /* 6C9D8 8007C1D8 FFFF4224 */   addiu     $v0, $v0, -0x1
    /* 6C9DC 8007C1DC 000082AC */  sw         $v0, 0x0($a0)
  .L8007C1E0:
    /* 6C9E0 8007C1E0 0C00828C */  lw         $v0, 0xC($a0)
    /* 6C9E4 8007C1E4 00000000 */  nop
    /* 6C9E8 8007C1E8 02004018 */  blez       $v0, .L8007C1F4
    /* 6C9EC 8007C1EC FFFF4224 */   addiu     $v0, $v0, -0x1
    /* 6C9F0 8007C1F0 0C0082AC */  sw         $v0, 0xC($a0)
  .L8007C1F4:
    /* 6C9F4 8007C1F4 E0FF838C */  lw         $v1, -0x20($a0)
    /* 6C9F8 8007C1F8 01001024 */  addiu      $s0, $zero, 0x1
    /* 6C9FC 8007C1FC 6D007010 */  beq        $v1, $s0, .L8007C3B4
    /* 6CA00 8007C200 02000224 */   addiu     $v0, $zero, 0x2
    /* 6CA04 8007C204 6B006214 */  bne        $v1, $v0, .L8007C3B4
    /* 6CA08 8007C208 00000000 */   nop
    /* 6CA0C 8007C20C E4FF838C */  lw         $v1, -0x1C($a0)
    /* 6CA10 8007C210 0B000524 */  addiu      $a1, $zero, 0xB
    /* 6CA14 8007C214 67006510 */  beq        $v1, $a1, .L8007C3B4
    /* 6CA18 8007C218 0C000224 */   addiu     $v0, $zero, 0xC
    /* 6CA1C 8007C21C 1E006214 */  bne        $v1, $v0, .L8007C298
    /* 6CA20 8007C220 0D000224 */   addiu     $v0, $zero, 0xD
    /* 6CA24 8007C224 0980023C */  lui        $v0, %hi(D_800939D4)
    /* 6CA28 8007C228 D439428C */  lw         $v0, %lo(D_800939D4)($v0)
    /* 6CA2C 8007C22C 00000000 */  nop
    /* 6CA30 8007C230 0D004010 */  beqz       $v0, .L8007C268
    /* 6CA34 8007C234 1000A527 */   addiu     $a1, $sp, 0x10
    /* 6CA38 8007C238 0980023C */  lui        $v0, %hi(D_800938C4)
    /* 6CA3C 8007C23C C438428C */  lw         $v0, %lo(D_800938C4)($v0)
    /* 6CA40 8007C240 00000000 */  nop
    /* 6CA44 8007C244 0500401C */  bgtz       $v0, .L8007C25C
    /* 6CA48 8007C248 1000A0A3 */   sb        $zero, 0x10($sp)
    /* 6CA4C 8007C24C 20000224 */  addiu      $v0, $zero, 0x20
    /* 6CA50 8007C250 DCFF82AC */  sw         $v0, -0x24($a0)
    /* 6CA54 8007C254 ECEF010C */  jal        func_8007BFB0
    /* 6CA58 8007C258 0E000424 */   addiu     $a0, $zero, 0xE
  .L8007C25C:
    /* 6CA5C 8007C25C 0980013C */  lui        $at, %hi(D_800939D4)
    /* 6CA60 8007C260 EDF00108 */  j          .L8007C3B4
    /* 6CA64 8007C264 D43920AC */   sw        $zero, %lo(D_800939D4)($at)
  .L8007C268:
    /* 6CA68 8007C268 0980023C */  lui        $v0, %hi(D_800938C4)
    /* 6CA6C 8007C26C C438428C */  lw         $v0, %lo(D_800938C4)($v0)
    /* 6CA70 8007C270 00000000 */  nop
    /* 6CA74 8007C274 0500401C */  bgtz       $v0, .L8007C28C
    /* 6CA78 8007C278 20000224 */   addiu     $v0, $zero, 0x20
    /* 6CA7C 8007C27C DCFF82AC */  sw         $v0, -0x24($a0)
    /* 6CA80 8007C280 01000424 */  addiu      $a0, $zero, 0x1
    /* 6CA84 8007C284 ECEF010C */  jal        func_8007BFB0
    /* 6CA88 8007C288 21280000 */   addu      $a1, $zero, $zero
  .L8007C28C:
    /* 6CA8C 8007C28C 0980013C */  lui        $at, %hi(D_800939D4)
    /* 6CA90 8007C290 EDF00108 */  j          .L8007C3B4
    /* 6CA94 8007C294 D43930AC */   sw        $s0, %lo(D_800939D4)($at)
  .L8007C298:
    /* 6CA98 8007C298 06006214 */  bne        $v1, $v0, .L8007C2B4
    /* 6CA9C 8007C29C 0E000224 */   addiu     $v0, $zero, 0xE
    /* 6CAA0 8007C2A0 0980023C */  lui        $v0, %hi(D_800938C4)
    /* 6CAA4 8007C2A4 C438428C */  lw         $v0, %lo(D_800938C4)($v0)
    /* 6CAA8 8007C2A8 0980013C */  lui        $at, %hi(D_800939D4)
    /* 6CAAC 8007C2AC E7F00108 */  j          .L8007C39C
    /* 6CAB0 8007C2B0 D43920AC */   sw        $zero, %lo(D_800939D4)($at)
  .L8007C2B4:
    /* 6CAB4 8007C2B4 1D006214 */  bne        $v1, $v0, .L8007C32C
    /* 6CAB8 8007C2B8 0F000224 */   addiu     $v0, $zero, 0xF
    /* 6CABC 8007C2BC E8FF838C */  lw         $v1, -0x18($a0)
    /* 6CAC0 8007C2C0 15000224 */  addiu      $v0, $zero, 0x15
    /* 6CAC4 8007C2C4 32006210 */  beq        $v1, $v0, .L8007C390
    /* 6CAC8 8007C2C8 16000224 */   addiu     $v0, $zero, 0x16
    /* 6CACC 8007C2CC 09006214 */  bne        $v1, $v0, .L8007C2F4
    /* 6CAD0 8007C2D0 17000224 */   addiu     $v0, $zero, 0x17
    /* 6CAD4 8007C2D4 F8FF828C */  lw         $v0, -0x8($a0)
    /* 6CAD8 8007C2D8 0980033C */  lui        $v1, %hi(D_800938C4)
    /* 6CADC 8007C2DC C438638C */  lw         $v1, %lo(D_800938C4)($v1)
    /* 6CAE0 8007C2E0 01004224 */  addiu      $v0, $v0, 0x1
    /* 6CAE4 8007C2E4 3300601C */  bgtz       $v1, .L8007C3B4
    /* 6CAE8 8007C2E8 F8FF82AC */   sw        $v0, -0x8($a0)
    /* 6CAEC 8007C2EC E9F00108 */  j          .L8007C3A4
    /* 6CAF0 8007C2F0 20000224 */   addiu     $v0, $zero, 0x20
  .L8007C2F4:
    /* 6CAF4 8007C2F4 09006214 */  bne        $v1, $v0, .L8007C31C
    /* 6CAF8 8007C2F8 18000224 */   addiu     $v0, $zero, 0x18
    /* 6CAFC 8007C2FC 0980023C */  lui        $v0, %hi(D_800938C4)
    /* 6CB00 8007C300 C438428C */  lw         $v0, %lo(D_800938C4)($v0)
    /* 6CB04 8007C304 00000000 */  nop
    /* 6CB08 8007C308 2A00401C */  bgtz       $v0, .L8007C3B4
    /* 6CB0C 8007C30C 20000224 */   addiu     $v0, $zero, 0x20
    /* 6CB10 8007C310 DCFF82AC */  sw         $v0, -0x24($a0)
    /* 6CB14 8007C314 EBF00108 */  j          .L8007C3AC
    /* 6CB18 8007C318 13000424 */   addiu     $a0, $zero, 0x13
  .L8007C31C:
    /* 6CB1C 8007C31C 1C006210 */  beq        $v1, $v0, .L8007C390
    /* 6CB20 8007C320 00000000 */   nop
    /* 6CB24 8007C324 EDF00108 */  j          .L8007C3B4
    /* 6CB28 8007C328 00000000 */   nop
  .L8007C32C:
    /* 6CB2C 8007C32C 07006214 */  bne        $v1, $v0, .L8007C34C
    /* 6CB30 8007C330 10000224 */   addiu     $v0, $zero, 0x10
    /* 6CB34 8007C334 0000828C */  lw         $v0, 0x0($a0)
    /* 6CB38 8007C338 00000000 */  nop
    /* 6CB3C 8007C33C 1D004014 */  bnez       $v0, .L8007C3B4
    /* 6CB40 8007C340 00000000 */   nop
    /* 6CB44 8007C344 E2F00108 */  j          .L8007C388
    /* 6CB48 8007C348 E0FF90AC */   sw        $s0, -0x20($a0)
  .L8007C34C:
    /* 6CB4C 8007C34C 07006214 */  bne        $v1, $v0, .L8007C36C
    /* 6CB50 8007C350 11000224 */   addiu     $v0, $zero, 0x11
    /* 6CB54 8007C354 F4FF8290 */  lbu        $v0, -0xC($a0)
    /* 6CB58 8007C358 00000000 */  nop
    /* 6CB5C 8007C35C 0C004010 */  beqz       $v0, .L8007C390
    /* 6CB60 8007C360 00000000 */   nop
    /* 6CB64 8007C364 E2F00108 */  j          .L8007C388
    /* 6CB68 8007C368 E0FF90AC */   sw        $s0, -0x20($a0)
  .L8007C36C:
    /* 6CB6C 8007C36C 11006214 */  bne        $v1, $v0, .L8007C3B4
    /* 6CB70 8007C370 00000000 */   nop
    /* 6CB74 8007C374 F6FF8290 */  lbu        $v0, -0xA($a0)
    /* 6CB78 8007C378 00000000 */  nop
    /* 6CB7C 8007C37C 04004010 */  beqz       $v0, .L8007C390
    /* 6CB80 8007C380 00000000 */   nop
    /* 6CB84 8007C384 E0FF90AC */  sw         $s0, -0x20($a0)
  .L8007C388:
    /* 6CB88 8007C388 EDF00108 */  j          .L8007C3B4
    /* 6CB8C 8007C38C E4FF85AC */   sw        $a1, -0x1C($a0)
  .L8007C390:
    /* 6CB90 8007C390 0980023C */  lui        $v0, %hi(D_800938C4)
    /* 6CB94 8007C394 C438428C */  lw         $v0, %lo(D_800938C4)($v0)
    /* 6CB98 8007C398 00000000 */  nop
  .L8007C39C:
    /* 6CB9C 8007C39C 0500401C */  bgtz       $v0, .L8007C3B4
    /* 6CBA0 8007C3A0 20000224 */   addiu     $v0, $zero, 0x20
  .L8007C3A4:
    /* 6CBA4 8007C3A4 DCFF82AC */  sw         $v0, -0x24($a0)
    /* 6CBA8 8007C3A8 01000424 */  addiu      $a0, $zero, 0x1
  .L8007C3AC:
    /* 6CBAC 8007C3AC ECEF010C */  jal        func_8007BFB0
    /* 6CBB0 8007C3B0 21280000 */   addu      $a1, $zero, $zero
  .L8007C3B4:
    /* 6CBB4 8007C3B4 0F80023C */  lui        $v0, %hi(D_800F5F80)
    /* 6CBB8 8007C3B8 805F428C */  lw         $v0, %lo(D_800F5F80)($v0)
    /* 6CBBC 8007C3BC 00000000 */  nop
    /* 6CBC0 8007C3C0 0B004010 */  beqz       $v0, .L8007C3F0
    /* 6CBC4 8007C3C4 00000000 */   nop
    /* 6CBC8 8007C3C8 0980023C */  lui        $v0, %hi(D_80093880)
    /* 6CBCC 8007C3CC 8038428C */  lw         $v0, %lo(D_80093880)($v0)
    /* 6CBD0 8007C3D0 00000000 */  nop
    /* 6CBD4 8007C3D4 06004010 */  beqz       $v0, .L8007C3F0
    /* 6CBD8 8007C3D8 00000000 */   nop
    /* 6CBDC 8007C3DC 0F80023C */  lui        $v0, %hi(D_800F5F80)
    /* 6CBE0 8007C3E0 805F428C */  lw         $v0, %lo(D_800F5F80)($v0)
    /* 6CBE4 8007C3E4 00000000 */  nop
    /* 6CBE8 8007C3E8 09F84000 */  jalr       $v0
    /* 6CBEC 8007C3EC 00000000 */   nop
  .L8007C3F0:
    /* 6CBF0 8007C3F0 0980043C */  lui        $a0, %hi(D_800938A0)
    /* 6CBF4 8007C3F4 A0388424 */  addiu      $a0, $a0, %lo(D_800938A0)
    /* 6CBF8 8007C3F8 0000838C */  lw         $v1, 0x0($a0)
    /* 6CBFC 8007C3FC 01000224 */  addiu      $v0, $zero, 0x1
    /* 6CC00 8007C400 05006214 */  bne        $v1, $v0, .L8007C418
    /* 6CC04 8007C404 03000224 */   addiu     $v0, $zero, 0x3
    /* 6CC08 8007C408 17008290 */  lbu        $v0, 0x17($a0)
    /* 6CC0C 8007C40C 00000000 */  nop
    /* 6CC10 8007C410 03004010 */  beqz       $v0, .L8007C420
    /* 6CC14 8007C414 03000224 */   addiu     $v0, $zero, 0x3
  .L8007C418:
    /* 6CC18 8007C418 0B006214 */  bne        $v1, $v0, .L8007C448
    /* 6CC1C 8007C41C 00000000 */   nop
  .L8007C420:
    /* 6CC20 8007C420 0980023C */  lui        $v0, %hi(D_800938C4)
    /* 6CC24 8007C424 C438428C */  lw         $v0, %lo(D_800938C4)($v0)
    /* 6CC28 8007C428 00000000 */  nop
    /* 6CC2C 8007C42C 0600401C */  bgtz       $v0, .L8007C448
    /* 6CC30 8007C430 21000224 */   addiu     $v0, $zero, 0x21
    /* 6CC34 8007C434 0980013C */  lui        $at, %hi(D_8009389C)
    /* 6CC38 8007C438 9C3822AC */  sw         $v0, %lo(D_8009389C)($at)
    /* 6CC3C 8007C43C 01000424 */  addiu      $a0, $zero, 0x1
    /* 6CC40 8007C440 ECEF010C */  jal        func_8007BFB0
    /* 6CC44 8007C444 21280000 */   addu      $a1, $zero, $zero
  .L8007C448:
    /* 6CC48 8007C448 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 6CC4C 8007C44C 1800B08F */  lw         $s0, 0x18($sp)
    /* 6CC50 8007C450 0800E003 */  jr         $ra
    /* 6CC54 8007C454 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8007C188
