nonmatching func_8002BAB4, 0x258

glabel func_8002BAB4
    /* 1C2B4 8002BAB4 0F80023C */  lui        $v0, %hi(D_800EA1E8)
    /* 1C2B8 8002BAB8 E8A14390 */  lbu        $v1, %lo(D_800EA1E8)($v0)
    /* 1C2BC 8002BABC D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 1C2C0 8002BAC0 1400B1AF */  sw         $s1, 0x14($sp)
    /* 1C2C4 8002BAC4 E8A15124 */  addiu      $s1, $v0, %lo(D_800EA1E8)
    /* 1C2C8 8002BAC8 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 1C2CC 8002BACC 01001324 */  addiu      $s3, $zero, 0x1
    /* 1C2D0 8002BAD0 2000BFAF */  sw         $ra, 0x20($sp)
    /* 1C2D4 8002BAD4 1800B2AF */  sw         $s2, 0x18($sp)
    /* 1C2D8 8002BAD8 0F006330 */  andi       $v1, $v1, 0xF
    /* 1C2DC 8002BADC 13007310 */  beq        $v1, $s3, .L8002BB2C
    /* 1C2E0 8002BAE0 1000B0AF */   sw        $s0, 0x10($sp)
    /* 1C2E4 8002BAE4 02006228 */  slti       $v0, $v1, 0x2
    /* 1C2E8 8002BAE8 05004010 */  beqz       $v0, .L8002BB00
    /* 1C2EC 8002BAEC 00000000 */   nop
    /* 1C2F0 8002BAF0 0A006010 */  beqz       $v1, .L8002BB1C
    /* 1C2F4 8002BAF4 00000000 */   nop
    /* 1C2F8 8002BAF8 3CAF0008 */  j          .L8002BCF0
    /* 1C2FC 8002BAFC 00000000 */   nop
  .L8002BB00:
    /* 1C300 8002BB00 02000224 */  addiu      $v0, $zero, 0x2
    /* 1C304 8002BB04 0D006210 */  beq        $v1, $v0, .L8002BB3C
    /* 1C308 8002BB08 03000224 */   addiu     $v0, $zero, 0x3
    /* 1C30C 8002BB0C 76006210 */  beq        $v1, $v0, .L8002BCE8
    /* 1C310 8002BB10 00000000 */   nop
    /* 1C314 8002BB14 3CAF0008 */  j          .L8002BCF0
    /* 1C318 8002BB18 00000000 */   nop
  .L8002BB1C:
    /* 1C31C 8002BB1C A8AE000C */  jal        func_8002BAA0
    /* 1C320 8002BB20 21202002 */   addu      $a0, $s1, $zero
    /* 1C324 8002BB24 3CAF0008 */  j          .L8002BCF0
    /* 1C328 8002BB28 00000000 */   nop
  .L8002BB2C:
    /* 1C32C 8002BB2C E2A9000C */  jal        func_8002A788
    /* 1C330 8002BB30 21202002 */   addu      $a0, $s1, $zero
    /* 1C334 8002BB34 3CAF0008 */  j          .L8002BCF0
    /* 1C338 8002BB38 00000000 */   nop
  .L8002BB3C:
    /* 1C33C 8002BB3C 29AB000C */  jal        func_8002ACA4
    /* 1C340 8002BB40 21202002 */   addu      $a0, $s1, $zero
    /* 1C344 8002BB44 21200000 */  addu       $a0, $zero, $zero
    /* 1C348 8002BB48 0F80023C */  lui        $v0, %hi(D_800F2848)
    /* 1C34C 8002BB4C 7663010C */  jal        func_80058DD8
    /* 1C350 8002BB50 48285224 */   addiu     $s2, $v0, %lo(D_800F2848)
    /* 1C354 8002BB54 21804000 */  addu       $s0, $v0, $zero
    /* 1C358 8002BB58 47001316 */  bne        $s0, $s3, .L8002BC78
    /* 1C35C 8002BB5C 0F80033C */   lui       $v1, %hi(D_800F2848)
    /* 1C360 8002BB60 9A63010C */  jal        func_80058E68
    /* 1C364 8002BB64 21200000 */   addu      $a0, $zero, $zero
    /* 1C368 8002BB68 20005010 */  beq        $v0, $s0, .L8002BBEC
    /* 1C36C 8002BB6C 21200000 */   addu      $a0, $zero, $zero
    /* 1C370 8002BB70 1880053C */  lui        $a1, (0x80181010 >> 16)
    /* 1C374 8002BB74 EC63010C */  jal        func_80058FB0
    /* 1C378 8002BB78 1010A534 */   ori       $a1, $a1, (0x80181010 & 0xFFFF)
    /* 1C37C 8002BB7C AA2A033C */  lui        $v1, (0x2AAAAAAB >> 16)
    /* 1C380 8002BB80 1880053C */  lui        $a1, %hi(D_80181012)
    /* 1C384 8002BB84 1210A584 */  lh         $a1, %lo(D_80181012)($a1)
    /* 1C388 8002BB88 1880023C */  lui        $v0, %hi(D_80181002)
    /* 1C38C 8002BB8C 02104284 */  lh         $v0, %lo(D_80181002)($v0)
    /* 1C390 8002BB90 ABAA6334 */  ori        $v1, $v1, (0x2AAAAAAB & 0xFFFF)
    /* 1C394 8002BB94 2380A200 */  subu       $s0, $a1, $v0
    /* 1C398 8002BB98 02000106 */  bgez       $s0, .L8002BBA4
    /* 1C39C 8002BB9C 21100002 */   addu      $v0, $s0, $zero
    /* 1C3A0 8002BBA0 23100200 */  negu       $v0, $v0
  .L8002BBA4:
    /* 1C3A4 8002BBA4 18004300 */  mult       $v0, $v1
    /* 1C3A8 8002BBA8 2000448E */  lw         $a0, 0x20($s2)
    /* 1C3AC 8002BBAC C3170200 */  sra        $v0, $v0, 31
    /* 1C3B0 8002BBB0 10380000 */  mfhi       $a3
    /* 1C3B4 8002BBB4 83180700 */  sra        $v1, $a3, 2
    /* 1C3B8 8002BBB8 23186200 */  subu       $v1, $v1, $v0
    /* 1C3BC 8002BBBC 2A10A400 */  slt        $v0, $a1, $a0
    /* 1C3C0 8002BBC0 04004010 */  beqz       $v0, .L8002BBD4
    /* 1C3C4 8002BBC4 01006324 */   addiu     $v1, $v1, 0x1
    /* 1C3C8 8002BBC8 23108300 */  subu       $v0, $a0, $v1
    /* 1C3CC 8002BBCC 200042AE */  sw         $v0, 0x20($s2)
    /* 1C3D0 8002BBD0 2000448E */  lw         $a0, 0x20($s2)
  .L8002BBD4:
    /* 1C3D4 8002BBD4 00000000 */  nop
    /* 1C3D8 8002BBD8 2A108500 */  slt        $v0, $a0, $a1
    /* 1C3DC 8002BBDC 25004010 */  beqz       $v0, .L8002BC74
    /* 1C3E0 8002BBE0 21108300 */   addu      $v0, $a0, $v1
    /* 1C3E4 8002BBE4 1DAF0008 */  j          .L8002BC74
    /* 1C3E8 8002BBE8 200042AE */   sw        $v0, 0x20($s2)
  .L8002BBEC:
    /* 1C3EC 8002BBEC 2000508E */  lw         $s0, 0x20($s2)
    /* 1C3F0 8002BBF0 1880033C */  lui        $v1, %hi(D_80181002)
    /* 1C3F4 8002BBF4 02106384 */  lh         $v1, %lo(D_80181002)($v1)
    /* 1C3F8 8002BBF8 00000000 */  nop
    /* 1C3FC 8002BBFC 0C000312 */  beq        $s0, $v1, .L8002BC30
    /* 1C400 8002BC00 2A107000 */   slt       $v0, $v1, $s0
    /* 1C404 8002BC04 04004010 */  beqz       $v0, .L8002BC18
    /* 1C408 8002BC08 00000000 */   nop
    /* 1C40C 8002BC0C F8FF1026 */  addiu      $s0, $s0, -0x8
    /* 1C410 8002BC10 08AF0008 */  j          .L8002BC20
    /* 1C414 8002BC14 2A100302 */   slt       $v0, $s0, $v1
  .L8002BC18:
    /* 1C418 8002BC18 08001026 */  addiu      $s0, $s0, 0x8
    /* 1C41C 8002BC1C 2A107000 */  slt        $v0, $v1, $s0
  .L8002BC20:
    /* 1C420 8002BC20 02004010 */  beqz       $v0, .L8002BC2C
    /* 1C424 8002BC24 00000000 */   nop
    /* 1C428 8002BC28 21806000 */  addu       $s0, $v1, $zero
  .L8002BC2C:
    /* 1C42C 8002BC2C 200050AE */  sw         $s0, 0x20($s2)
  .L8002BC30:
    /* 1C430 8002BC30 2000228E */  lw         $v0, 0x20($s1)
    /* 1C434 8002BC34 00000000 */  nop
    /* 1C438 8002BC38 FFFF4224 */  addiu      $v0, $v0, -0x1
    /* 1C43C 8002BC3C 0D00401C */  bgtz       $v0, .L8002BC74
    /* 1C440 8002BC40 200022AE */   sw        $v0, 0x20($s1)
    /* 1C444 8002BC44 2C010224 */  addiu      $v0, $zero, 0x12C
    /* 1C448 8002BC48 200022AE */  sw         $v0, 0x20($s1)
    /* 1C44C 8002BC4C 6439020C */  jal        func_8008E590
    /* 1C450 8002BC50 02001024 */   addiu     $s0, $zero, 0x2
    /* 1C454 8002BC54 01004230 */  andi       $v0, $v0, 0x1
    /* 1C458 8002BC58 02004010 */  beqz       $v0, .L8002BC64
    /* 1C45C 8002BC5C 00000000 */   nop
    /* 1C460 8002BC60 07001024 */  addiu      $s0, $zero, 0x7
  .L8002BC64:
    /* 1C464 8002BC64 21200000 */  addu       $a0, $zero, $zero
    /* 1C468 8002BC68 21280002 */  addu       $a1, $s0, $zero
    /* 1C46C 8002BC6C BD5E010C */  jal        func_80057AF4
    /* 1C470 8002BC70 01000624 */   addiu     $a2, $zero, 0x1
  .L8002BC74:
    /* 1C474 8002BC74 0F80033C */  lui        $v1, %hi(D_800F2848)
  .L8002BC78:
    /* 1C478 8002BC78 48286324 */  addiu      $v1, $v1, %lo(D_800F2848)
    /* 1C47C 8002BC7C 02006294 */  lhu        $v0, 0x2($v1)
    /* 1C480 8002BC80 00000000 */  nop
    /* 1C484 8002BC84 0C004224 */  addiu      $v0, $v0, 0xC
    /* 1C488 8002BC88 4B4D000C */  jal        func_8001352C
    /* 1C48C 8002BC8C 020062A4 */   sh        $v0, 0x2($v1)
    /* 1C490 8002BC90 7F64010C */  jal        func_800591FC
    /* 1C494 8002BC94 00000000 */   nop
    /* 1C498 8002BC98 1000488E */  lw         $t0, 0x10($s2)
    /* 1C49C 8002BC9C 1400498E */  lw         $t1, 0x14($s2)
    /* 1C4A0 8002BCA0 18004A8E */  lw         $t2, 0x18($s2)
    /* 1C4A4 8002BCA4 1C00478E */  lw         $a3, 0x1C($s2)
    /* 1C4A8 8002BCA8 000048AC */  sw         $t0, 0x0($v0)
    /* 1C4AC 8002BCAC 040049AC */  sw         $t1, 0x4($v0)
    /* 1C4B0 8002BCB0 08004AAC */  sw         $t2, 0x8($v0)
    /* 1C4B4 8002BCB4 0C0047AC */  sw         $a3, 0xC($v0)
    /* 1C4B8 8002BCB8 2000488E */  lw         $t0, 0x20($s2)
    /* 1C4BC 8002BCBC 2400498E */  lw         $t1, 0x24($s2)
    /* 1C4C0 8002BCC0 28004A8E */  lw         $t2, 0x28($s2)
    /* 1C4C4 8002BCC4 2C00478E */  lw         $a3, 0x2C($s2)
    /* 1C4C8 8002BCC8 100048AC */  sw         $t0, 0x10($v0)
    /* 1C4CC 8002BCCC 140049AC */  sw         $t1, 0x14($v0)
    /* 1C4D0 8002BCD0 18004AAC */  sw         $t2, 0x18($v0)
    /* 1C4D4 8002BCD4 1C0047AC */  sw         $a3, 0x1C($v0)
    /* 1C4D8 8002BCD8 CE5F010C */  jal        func_80057F38
    /* 1C4DC 8002BCDC 21200000 */   addu      $a0, $zero, $zero
    /* 1C4E0 8002BCE0 3CAF0008 */  j          .L8002BCF0
    /* 1C4E4 8002BCE4 00000000 */   nop
  .L8002BCE8:
    /* 1C4E8 8002BCE8 ABAE000C */  jal        func_8002BAAC
    /* 1C4EC 8002BCEC 21202002 */   addu      $a0, $s1, $zero
  .L8002BCF0:
    /* 1C4F0 8002BCF0 2000BF8F */  lw         $ra, 0x20($sp)
    /* 1C4F4 8002BCF4 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 1C4F8 8002BCF8 1800B28F */  lw         $s2, 0x18($sp)
    /* 1C4FC 8002BCFC 1400B18F */  lw         $s1, 0x14($sp)
    /* 1C500 8002BD00 1000B08F */  lw         $s0, 0x10($sp)
    /* 1C504 8002BD04 0800E003 */  jr         $ra
    /* 1C508 8002BD08 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_8002BAB4
