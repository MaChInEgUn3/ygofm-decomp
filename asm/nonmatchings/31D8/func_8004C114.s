nonmatching func_8004C114, 0x30C

glabel func_8004C114
    /* 3C914 8004C114 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 3C918 8004C118 1000BFAF */  sw         $ra, 0x10($sp)
    /* 3C91C 8004C11C 21688000 */  addu       $t5, $a0, $zero
    /* 3C920 8004C120 0F00AC30 */  andi       $t4, $a1, 0xF
    /* 3C924 8004C124 F000A530 */  andi       $a1, $a1, 0xF0
    /* 3C928 8004C128 B0000224 */  addiu      $v0, $zero, 0xB0
    /* 3C92C 8004C12C 2300A210 */  beq        $a1, $v0, .L8004C1BC
    /* 3C930 8004C130 2158C000 */   addu      $t3, $a2, $zero
    /* 3C934 8004C134 B100A228 */  slti       $v0, $a1, 0xB1
    /* 3C938 8004C138 07004010 */  beqz       $v0, .L8004C158
    /* 3C93C 8004C13C 80000224 */   addiu     $v0, $zero, 0x80
    /* 3C940 8004C140 0C00A210 */  beq        $a1, $v0, .L8004C174
    /* 3C944 8004C144 90000224 */   addiu     $v0, $zero, 0x90
    /* 3C948 8004C148 1000A210 */  beq        $a1, $v0, .L8004C18C
    /* 3C94C 8004C14C 00000000 */   nop
    /* 3C950 8004C150 04310108 */  j          .L8004C410
    /* 3C954 8004C154 00000000 */   nop
  .L8004C158:
    /* 3C958 8004C158 C0000224 */  addiu      $v0, $zero, 0xC0
    /* 3C95C 8004C15C A400A210 */  beq        $a1, $v0, .L8004C3F0
    /* 3C960 8004C160 E0000224 */   addiu     $v0, $zero, 0xE0
    /* 3C964 8004C164 A700A210 */  beq        $a1, $v0, .L8004C404
    /* 3C968 8004C168 21208001 */   addu      $a0, $t4, $zero
    /* 3C96C 8004C16C 04310108 */  j          .L8004C410
    /* 3C970 8004C170 00000000 */   nop
  .L8004C174:
    /* 3C974 8004C174 21208001 */  addu       $a0, $t4, $zero
    /* 3C978 8004C178 FF006531 */  andi       $a1, $t3, 0xFF
    /* 3C97C 8004C17C DD2C010C */  jal        func_8004B374
    /* 3C980 8004C180 FF00E630 */   andi      $a2, $a3, 0xFF
    /* 3C984 8004C184 04310108 */  j          .L8004C410
    /* 3C988 8004C188 00000000 */   nop
  .L8004C18C:
    /* 3C98C 8004C18C FF00E630 */  andi       $a2, $a3, 0xFF
    /* 3C990 8004C190 0500C010 */  beqz       $a2, .L8004C1A8
    /* 3C994 8004C194 21208001 */   addu      $a0, $t4, $zero
    /* 3C998 8004C198 7A2B010C */  jal        func_8004ADE8
    /* 3C99C 8004C19C FF006531 */   andi      $a1, $t3, 0xFF
    /* 3C9A0 8004C1A0 04310108 */  j          .L8004C410
    /* 3C9A4 8004C1A4 00000000 */   nop
  .L8004C1A8:
    /* 3C9A8 8004C1A8 FF006531 */  andi       $a1, $t3, 0xFF
    /* 3C9AC 8004C1AC DD2C010C */  jal        func_8004B374
    /* 3C9B0 8004C1B0 21300000 */   addu      $a2, $zero, $zero
    /* 3C9B4 8004C1B4 04310108 */  j          .L8004C410
    /* 3C9B8 8004C1B8 00000000 */   nop
  .L8004C1BC:
    /* 3C9BC 8004C1BC FF006331 */  andi       $v1, $t3, 0xFF
    /* 3C9C0 8004C1C0 63000224 */  addiu      $v0, $zero, 0x63
    /* 3C9C4 8004C1C4 61006214 */  bne        $v1, $v0, .L8004C34C
    /* 3C9C8 8004C1C8 06000224 */   addiu     $v0, $zero, 0x6
    /* 3C9CC 8004C1CC FF00E330 */  andi       $v1, $a3, 0xFF
    /* 3C9D0 8004C1D0 14000224 */  addiu      $v0, $zero, 0x14
    /* 3C9D4 8004C1D4 2A006214 */  bne        $v1, $v0, .L8004C280
    /* 3C9D8 8004C1D8 1E000224 */   addiu     $v0, $zero, 0x1E
    /* 3C9DC 8004C1DC 0A80093C */  lui        $t1, %hi(D_8009B458)
    /* 3C9E0 8004C1E0 58B4298D */  lw         $t1, %lo(D_8009B458)($t1)
    /* 3C9E4 8004C1E4 00000000 */  nop
    /* 3C9E8 8004C1E8 F8072295 */  lhu        $v0, 0x7F8($t1)
    /* 3C9EC 8004C1EC 00000000 */  nop
    /* 3C9F0 8004C1F0 1F004010 */  beqz       $v0, .L8004C270
    /* 3C9F4 8004C1F4 7F000224 */   addiu     $v0, $zero, 0x7F
    /* 3C9F8 8004C1F8 FA072295 */  lhu        $v0, 0x7FA($t1)
    /* 3C9FC 8004C1FC 00000000 */  nop
    /* 3CA00 8004C200 15004010 */  beqz       $v0, .L8004C258
    /* 3CA04 8004C204 21400000 */   addu      $t0, $zero, $zero
    /* 3CA08 8004C208 18050A24 */  addiu      $t2, $zero, 0x518
  .L8004C20C:
    /* 3CA0C 8004C20C 21282A01 */  addu       $a1, $t1, $t2
    /* 3CA10 8004C210 2400A290 */  lbu        $v0, 0x24($a1)
    /* 3CA14 8004C214 2900A390 */  lbu        $v1, 0x29($a1)
    /* 3CA18 8004C218 1800A494 */  lhu        $a0, 0x18($a1)
    /* 3CA1C 8004C21C 2600A7A0 */  sb         $a3, 0x26($a1)
    /* 3CA20 8004C220 2500A2A0 */  sb         $v0, 0x25($a1)
    /* 3CA24 8004C224 2A00A3A0 */  sb         $v1, 0x2A($a1)
    /* 3CA28 8004C228 0A80093C */  lui        $t1, %hi(D_8009B458)
    /* 3CA2C 8004C22C 58B4298D */  lw         $t1, %lo(D_8009B458)($t1)
    /* 3CA30 8004C230 0000A28C */  lw         $v0, 0x0($a1)
    /* 3CA34 8004C234 1C00A38C */  lw         $v1, 0x1C($a1)
    /* 3CA38 8004C238 1A00A4A4 */  sh         $a0, 0x1A($a1)
    /* 3CA3C 8004C23C 0400A2AC */  sw         $v0, 0x4($a1)
    /* 3CA40 8004C240 2000A3AC */  sw         $v1, 0x20($a1)
    /* 3CA44 8004C244 FA072295 */  lhu        $v0, 0x7FA($t1)
    /* 3CA48 8004C248 01000825 */  addiu      $t0, $t0, 0x1
    /* 3CA4C 8004C24C 2A100201 */  slt        $v0, $t0, $v0
    /* 3CA50 8004C250 EEFF4014 */  bnez       $v0, .L8004C20C
    /* 3CA54 8004C254 2C004A25 */   addiu     $t2, $t2, 0x2C
  .L8004C258:
    /* 3CA58 8004C258 0A80033C */  lui        $v1, %hi(D_8009B458)
    /* 3CA5C 8004C25C 58B4638C */  lw         $v1, %lo(D_8009B458)($v1)
    /* 3CA60 8004C260 00000000 */  nop
    /* 3CA64 8004C264 F007628C */  lw         $v0, 0x7F0($v1)
    /* 3CA68 8004C268 D1300108 */  j          .L8004C344
    /* 3CA6C 8004C26C F40762AC */   sw        $v0, 0x7F4($v1)
  .L8004C270:
    /* 3CA70 8004C270 0000A38D */  lw         $v1, 0x0($t5)
    /* 3CA74 8004C274 2600A2A1 */  sb         $v0, 0x26($t5)
    /* 3CA78 8004C278 D1300108 */  j          .L8004C344
    /* 3CA7C 8004C27C 0400A3AD */   sw        $v1, 0x4($t5)
  .L8004C280:
    /* 3CA80 8004C280 31006214 */  bne        $v1, $v0, .L8004C348
    /* 3CA84 8004C284 FF006331 */   andi      $v1, $t3, 0xFF
    /* 3CA88 8004C288 2600A391 */  lbu        $v1, 0x26($t5)
    /* 3CA8C 8004C28C 00000000 */  nop
    /* 3CA90 8004C290 FF006230 */  andi       $v0, $v1, 0xFF
    /* 3CA94 8004C294 2B004010 */  beqz       $v0, .L8004C344
    /* 3CA98 8004C298 7F00422C */   sltiu     $v0, $v0, 0x7F
    /* 3CA9C 8004C29C 02004010 */  beqz       $v0, .L8004C2A8
    /* 3CAA0 8004C2A0 FFFF6224 */   addiu     $v0, $v1, -0x1
    /* 3CAA4 8004C2A4 2600A2A1 */  sb         $v0, 0x26($t5)
  .L8004C2A8:
    /* 3CAA8 8004C2A8 0A80093C */  lui        $t1, %hi(D_8009B458)
    /* 3CAAC 8004C2AC 58B4298D */  lw         $t1, %lo(D_8009B458)($t1)
    /* 3CAB0 8004C2B0 00000000 */  nop
    /* 3CAB4 8004C2B4 F8072295 */  lhu        $v0, 0x7F8($t1)
    /* 3CAB8 8004C2B8 00000000 */  nop
    /* 3CABC 8004C2BC 1E004010 */  beqz       $v0, .L8004C338
    /* 3CAC0 8004C2C0 00000000 */   nop
    /* 3CAC4 8004C2C4 FA072295 */  lhu        $v0, 0x7FA($t1)
    /* 3CAC8 8004C2C8 00000000 */  nop
    /* 3CACC 8004C2CC 14004010 */  beqz       $v0, .L8004C320
    /* 3CAD0 8004C2D0 21400000 */   addu      $t0, $zero, $zero
    /* 3CAD4 8004C2D4 18050A24 */  addiu      $t2, $zero, 0x518
  .L8004C2D8:
    /* 3CAD8 8004C2D8 21282A01 */  addu       $a1, $t1, $t2
    /* 3CADC 8004C2DC 2500A290 */  lbu        $v0, 0x25($a1)
    /* 3CAE0 8004C2E0 2A00A390 */  lbu        $v1, 0x2A($a1)
    /* 3CAE4 8004C2E4 1A00A494 */  lhu        $a0, 0x1A($a1)
    /* 3CAE8 8004C2E8 2400A2A0 */  sb         $v0, 0x24($a1)
    /* 3CAEC 8004C2EC 2900A3A0 */  sb         $v1, 0x29($a1)
    /* 3CAF0 8004C2F0 0A80093C */  lui        $t1, %hi(D_8009B458)
    /* 3CAF4 8004C2F4 58B4298D */  lw         $t1, %lo(D_8009B458)($t1)
    /* 3CAF8 8004C2F8 0400A28C */  lw         $v0, 0x4($a1)
    /* 3CAFC 8004C2FC 2000A38C */  lw         $v1, 0x20($a1)
    /* 3CB00 8004C300 1800A4A4 */  sh         $a0, 0x18($a1)
    /* 3CB04 8004C304 0000A2AC */  sw         $v0, 0x0($a1)
    /* 3CB08 8004C308 1C00A3AC */  sw         $v1, 0x1C($a1)
    /* 3CB0C 8004C30C FA072295 */  lhu        $v0, 0x7FA($t1)
    /* 3CB10 8004C310 01000825 */  addiu      $t0, $t0, 0x1
    /* 3CB14 8004C314 2A100201 */  slt        $v0, $t0, $v0
    /* 3CB18 8004C318 EFFF4014 */  bnez       $v0, .L8004C2D8
    /* 3CB1C 8004C31C 2C004A25 */   addiu     $t2, $t2, 0x2C
  .L8004C320:
    /* 3CB20 8004C320 0A80033C */  lui        $v1, %hi(D_8009B458)
    /* 3CB24 8004C324 58B4638C */  lw         $v1, %lo(D_8009B458)($v1)
    /* 3CB28 8004C328 00000000 */  nop
    /* 3CB2C 8004C32C F407628C */  lw         $v0, 0x7F4($v1)
    /* 3CB30 8004C330 D1300108 */  j          .L8004C344
    /* 3CB34 8004C334 F00762AC */   sw        $v0, 0x7F0($v1)
  .L8004C338:
    /* 3CB38 8004C338 0400A28D */  lw         $v0, 0x4($t5)
    /* 3CB3C 8004C33C 00000000 */  nop
    /* 3CB40 8004C340 0000A2AD */  sw         $v0, 0x0($t5)
  .L8004C344:
    /* 3CB44 8004C344 FF006331 */  andi       $v1, $t3, 0xFF
  .L8004C348:
    /* 3CB48 8004C348 06000224 */  addiu      $v0, $zero, 0x6
  .L8004C34C:
    /* 3CB4C 8004C34C 23006214 */  bne        $v1, $v0, .L8004C3DC
    /* 3CB50 8004C350 21208001 */   addu      $a0, $t4, $zero
    /* 3CB54 8004C354 40100C00 */  sll        $v0, $t4, 1
    /* 3CB58 8004C358 21104C00 */  addu       $v0, $v0, $t4
    /* 3CB5C 8004C35C 0A80043C */  lui        $a0, %hi(D_8009B458)
    /* 3CB60 8004C360 58B4848C */  lw         $a0, %lo(D_8009B458)($a0)
    /* 3CB64 8004C364 C0100200 */  sll        $v0, $v0, 3
    /* 3CB68 8004C368 21108200 */  addu       $v0, $a0, $v0
    /* 3CB6C 8004C36C 12004390 */  lbu        $v1, 0x12($v0)
    /* 3CB70 8004C370 14000224 */  addiu      $v0, $zero, 0x14
    /* 3CB74 8004C374 18006214 */  bne        $v1, $v0, .L8004C3D8
    /* 3CB78 8004C378 00000000 */   nop
    /* 3CB7C 8004C37C F8078294 */  lhu        $v0, 0x7F8($a0)
    /* 3CB80 8004C380 00000000 */  nop
    /* 3CB84 8004C384 12004010 */  beqz       $v0, .L8004C3D0
    /* 3CB88 8004C388 00000000 */   nop
    /* 3CB8C 8004C38C FA078294 */  lhu        $v0, 0x7FA($a0)
    /* 3CB90 8004C390 00000000 */  nop
    /* 3CB94 8004C394 10004010 */  beqz       $v0, .L8004C3D8
    /* 3CB98 8004C398 21400000 */   addu      $t0, $zero, $zero
    /* 3CB9C 8004C39C 21180001 */  addu       $v1, $t0, $zero
  .L8004C3A0:
    /* 3CBA0 8004C3A0 21108300 */  addu       $v0, $a0, $v1
    /* 3CBA4 8004C3A4 3E0547A0 */  sb         $a3, 0x53E($v0)
    /* 3CBA8 8004C3A8 0A80043C */  lui        $a0, %hi(D_8009B458)
    /* 3CBAC 8004C3AC 58B4848C */  lw         $a0, %lo(D_8009B458)($a0)
    /* 3CBB0 8004C3B0 00000000 */  nop
    /* 3CBB4 8004C3B4 FA078294 */  lhu        $v0, 0x7FA($a0)
    /* 3CBB8 8004C3B8 01000825 */  addiu      $t0, $t0, 0x1
    /* 3CBBC 8004C3BC 2A100201 */  slt        $v0, $t0, $v0
    /* 3CBC0 8004C3C0 F7FF4014 */  bnez       $v0, .L8004C3A0
    /* 3CBC4 8004C3C4 2C006324 */   addiu     $v1, $v1, 0x2C
    /* 3CBC8 8004C3C8 F7300108 */  j          .L8004C3DC
    /* 3CBCC 8004C3CC 21208001 */   addu      $a0, $t4, $zero
  .L8004C3D0:
    /* 3CBD0 8004C3D0 04310108 */  j          .L8004C410
    /* 3CBD4 8004C3D4 2600A7A1 */   sb        $a3, 0x26($t5)
  .L8004C3D8:
    /* 3CBD8 8004C3D8 21208001 */  addu       $a0, $t4, $zero
  .L8004C3DC:
    /* 3CBDC 8004C3DC FF006531 */  andi       $a1, $t3, 0xFF
    /* 3CBE0 8004C3E0 272D010C */  jal        func_8004B49C
    /* 3CBE4 8004C3E4 FF00E630 */   andi      $a2, $a3, 0xFF
    /* 3CBE8 8004C3E8 04310108 */  j          .L8004C410
    /* 3CBEC 8004C3EC 00000000 */   nop
  .L8004C3F0:
    /* 3CBF0 8004C3F0 21208001 */  addu       $a0, $t4, $zero
    /* 3CBF4 8004C3F4 BA2D010C */  jal        func_8004B6E8
    /* 3CBF8 8004C3F8 FF006531 */   andi      $a1, $t3, 0xFF
    /* 3CBFC 8004C3FC 04310108 */  j          .L8004C410
    /* 3CC00 8004C400 00000000 */   nop
  .L8004C404:
    /* 3CC04 8004C404 FF006531 */  andi       $a1, $t3, 0xFF
    /* 3CC08 8004C408 C32D010C */  jal        func_8004B70C
    /* 3CC0C 8004C40C FF00E630 */   andi      $a2, $a3, 0xFF
  .L8004C410:
    /* 3CC10 8004C410 1000BF8F */  lw         $ra, 0x10($sp)
    /* 3CC14 8004C414 00000000 */  nop
    /* 3CC18 8004C418 0800E003 */  jr         $ra
    /* 3CC1C 8004C41C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8004C114
