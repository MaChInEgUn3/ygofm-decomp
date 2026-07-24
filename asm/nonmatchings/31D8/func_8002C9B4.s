nonmatching func_8002C9B4, 0x19C

glabel func_8002C9B4
    /* 1D1B4 8002C9B4 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 1D1B8 8002C9B8 1800B2AF */  sw         $s2, 0x18($sp)
    /* 1D1BC 8002C9BC 21908000 */  addu       $s2, $a0, $zero
    /* 1D1C0 8002C9C0 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 1D1C4 8002C9C4 2198A000 */  addu       $s3, $a1, $zero
    /* 1D1C8 8002C9C8 2000BFAF */  sw         $ra, 0x20($sp)
    /* 1D1CC 8002C9CC 1400B1AF */  sw         $s1, 0x14($sp)
    /* 1D1D0 8002C9D0 1E006106 */  bgez       $s3, .L8002CA4C
    /* 1D1D4 8002C9D4 1000B0AF */   sw        $s0, 0x10($sp)
    /* 1D1D8 8002C9D8 1A80023C */  lui        $v0, %hi(D_801A7B64)
    /* 1D1DC 8002C9DC 647B5024 */  addiu      $s0, $v0, %lo(D_801A7B64)
    /* 1D1E0 8002C9E0 A4010326 */  addiu      $v1, $s0, 0x1A4
    /* 1D1E4 8002C9E4 21880000 */  addu       $s1, $zero, $zero
  .L8002C9E8:
    /* 1D1E8 8002C9E8 16000296 */  lhu        $v0, 0x16($s0)
    /* 1D1EC 8002C9EC 00000000 */  nop
    /* 1D1F0 8002C9F0 00804230 */  andi       $v0, $v0, 0x8000
    /* 1D1F4 8002C9F4 05004010 */  beqz       $v0, .L8002CA0C
    /* 1D1F8 8002C9F8 00000000 */   nop
    /* 1D1FC 8002C9FC 0000028E */  lw         $v0, 0x0($s0)
    /* 1D200 8002CA00 00000000 */  nop
    /* 1D204 8002CA04 000042AE */  sw         $v0, 0x0($s2)
    /* 1D208 8002CA08 04005226 */  addiu      $s2, $s2, 0x4
  .L8002CA0C:
    /* 1D20C 8002CA0C 16006294 */  lhu        $v0, 0x16($v1)
    /* 1D210 8002CA10 00000000 */  nop
    /* 1D214 8002CA14 00804230 */  andi       $v0, $v0, 0x8000
    /* 1D218 8002CA18 05004010 */  beqz       $v0, .L8002CA30
    /* 1D21C 8002CA1C 00000000 */   nop
    /* 1D220 8002CA20 0000628C */  lw         $v0, 0x0($v1)
    /* 1D224 8002CA24 00000000 */  nop
    /* 1D228 8002CA28 000042AE */  sw         $v0, 0x0($s2)
    /* 1D22C 8002CA2C 04005226 */  addiu      $s2, $s2, 0x4
  .L8002CA30:
    /* 1D230 8002CA30 01003126 */  addiu      $s1, $s1, 0x1
    /* 1D234 8002CA34 1C001026 */  addiu      $s0, $s0, 0x1C
    /* 1D238 8002CA38 0A00222A */  slti       $v0, $s1, 0xA
    /* 1D23C 8002CA3C EAFF4014 */  bnez       $v0, .L8002C9E8
    /* 1D240 8002CA40 1C006324 */   addiu     $v1, $v1, 0x1C
    /* 1D244 8002CA44 CDB20008 */  j          .L8002CB34
    /* 1D248 8002CA48 000040AE */   sw        $zero, 0x0($s2)
  .L8002CA4C:
    /* 1D24C 8002CA4C 0A80023C */  lui        $v0, %hi(D_8009B1D5)
    /* 1D250 8002CA50 D5B14290 */  lbu        $v0, %lo(D_8009B1D5)($v0)
    /* 1D254 8002CA54 00000000 */  nop
    /* 1D258 8002CA58 02004010 */  beqz       $v0, .L8002CA64
    /* 1D25C 8002CA5C 14001124 */   addiu     $s1, $zero, 0x14
    /* 1D260 8002CA60 05001124 */  addiu      $s1, $zero, 0x5
  .L8002CA64:
    /* 1D264 8002CA64 C0101100 */  sll        $v0, $s1, 3
    /* 1D268 8002CA68 23105100 */  subu       $v0, $v0, $s1
    /* 1D26C 8002CA6C 80100200 */  sll        $v0, $v0, 2
    /* 1D270 8002CA70 1A80033C */  lui        $v1, %hi(D_801A7AD8)
    /* 1D274 8002CA74 D87A6324 */  addiu      $v1, $v1, %lo(D_801A7AD8)
    /* 1D278 8002CA78 21804300 */  addu       $s0, $v0, $v1
    /* 1D27C 8002CA7C 1500622A */  slti       $v0, $s3, 0x15
    /* 1D280 8002CA80 16004014 */  bnez       $v0, .L8002CADC
    /* 1D284 8002CA84 21880000 */   addu      $s1, $zero, $zero
  .L8002CA88:
    /* 1D288 8002CA88 16000296 */  lhu        $v0, 0x16($s0)
    /* 1D28C 8002CA8C 00000000 */  nop
    /* 1D290 8002CA90 00804230 */  andi       $v0, $v0, 0x8000
    /* 1D294 8002CA94 0B004010 */  beqz       $v0, .L8002CAC4
    /* 1D298 8002CA98 00000000 */   nop
    /* 1D29C 8002CA9C 325C000C */  jal        func_800170C8
    /* 1D2A0 8002CAA0 21200002 */   addu      $a0, $s0, $zero
    /* 1D2A4 8002CAA4 FFFF4230 */  andi       $v0, $v0, 0xFFFF
    /* 1D2A8 8002CAA8 2A105300 */  slt        $v0, $v0, $s3
    /* 1D2AC 8002CAAC 05004014 */  bnez       $v0, .L8002CAC4
    /* 1D2B0 8002CAB0 00000000 */   nop
    /* 1D2B4 8002CAB4 0000028E */  lw         $v0, 0x0($s0)
    /* 1D2B8 8002CAB8 00000000 */  nop
    /* 1D2BC 8002CABC 000042AE */  sw         $v0, 0x0($s2)
    /* 1D2C0 8002CAC0 04005226 */  addiu      $s2, $s2, 0x4
  .L8002CAC4:
    /* 1D2C4 8002CAC4 01003126 */  addiu      $s1, $s1, 0x1
    /* 1D2C8 8002CAC8 0500222A */  slti       $v0, $s1, 0x5
    /* 1D2CC 8002CACC EEFF4014 */  bnez       $v0, .L8002CA88
    /* 1D2D0 8002CAD0 1C001026 */   addiu     $s0, $s0, 0x1C
    /* 1D2D4 8002CAD4 CDB20008 */  j          .L8002CB34
    /* 1D2D8 8002CAD8 000040AE */   sw        $zero, 0x0($s2)
  .L8002CADC:
    /* 1D2DC 8002CADC 16000296 */  lhu        $v0, 0x16($s0)
    /* 1D2E0 8002CAE0 00000000 */  nop
    /* 1D2E4 8002CAE4 00804230 */  andi       $v0, $v0, 0x8000
    /* 1D2E8 8002CAE8 0D004010 */  beqz       $v0, .L8002CB20
    /* 1D2EC 8002CAEC 00000000 */   nop
    /* 1D2F0 8002CAF0 07006006 */  bltz       $s3, .L8002CB10
    /* 1D2F4 8002CAF4 00000000 */   nop
    /* 1D2F8 8002CAF8 0000028E */  lw         $v0, 0x0($s0)
    /* 1D2FC 8002CAFC 00000000 */  nop
    /* 1D300 8002CB00 68004290 */  lbu        $v0, 0x68($v0)
    /* 1D304 8002CB04 00000000 */  nop
    /* 1D308 8002CB08 05005314 */  bne        $v0, $s3, .L8002CB20
    /* 1D30C 8002CB0C 00000000 */   nop
  .L8002CB10:
    /* 1D310 8002CB10 0000028E */  lw         $v0, 0x0($s0)
    /* 1D314 8002CB14 00000000 */  nop
    /* 1D318 8002CB18 000042AE */  sw         $v0, 0x0($s2)
    /* 1D31C 8002CB1C 04005226 */  addiu      $s2, $s2, 0x4
  .L8002CB20:
    /* 1D320 8002CB20 01003126 */  addiu      $s1, $s1, 0x1
    /* 1D324 8002CB24 0500222A */  slti       $v0, $s1, 0x5
    /* 1D328 8002CB28 ECFF4014 */  bnez       $v0, .L8002CADC
    /* 1D32C 8002CB2C 1C001026 */   addiu     $s0, $s0, 0x1C
    /* 1D330 8002CB30 000040AE */  sw         $zero, 0x0($s2)
  .L8002CB34:
    /* 1D334 8002CB34 2000BF8F */  lw         $ra, 0x20($sp)
    /* 1D338 8002CB38 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 1D33C 8002CB3C 1800B28F */  lw         $s2, 0x18($sp)
    /* 1D340 8002CB40 1400B18F */  lw         $s1, 0x14($sp)
    /* 1D344 8002CB44 1000B08F */  lw         $s0, 0x10($sp)
    /* 1D348 8002CB48 0800E003 */  jr         $ra
    /* 1D34C 8002CB4C 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_8002C9B4
