nonmatching func_8003C328, 0x170

glabel func_8003C328
    /* 2CB28 8003C328 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 2CB2C 8003C32C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 2CB30 8003C330 21808000 */  addu       $s0, $a0, $zero
    /* 2CB34 8003C334 1400B1AF */  sw         $s1, 0x14($sp)
    /* 2CB38 8003C338 01001124 */  addiu      $s1, $zero, 0x1
    /* 2CB3C 8003C33C 2B00B110 */  beq        $a1, $s1, .L8003C3EC
    /* 2CB40 8003C340 1800BFAF */   sw        $ra, 0x18($sp)
    /* 2CB44 8003C344 0200A228 */  slti       $v0, $a1, 0x2
    /* 2CB48 8003C348 05004010 */  beqz       $v0, .L8003C360
    /* 2CB4C 8003C34C 00000000 */   nop
    /* 2CB50 8003C350 0800A010 */  beqz       $a1, .L8003C374
    /* 2CB54 8003C354 DDFF043C */   lui       $a0, (0xFFDDFFFF >> 16)
    /* 2CB58 8003C358 21F10008 */  j          .L8003C484
    /* 2CB5C 8003C35C 00000000 */   nop
  .L8003C360:
    /* 2CB60 8003C360 02000224 */  addiu      $v0, $zero, 0x2
    /* 2CB64 8003C364 2F00A210 */  beq        $a1, $v0, .L8003C424
    /* 2CB68 8003C368 F0000224 */   addiu     $v0, $zero, 0xF0
    /* 2CB6C 8003C36C 21F10008 */  j          .L8003C484
    /* 2CB70 8003C370 00000000 */   nop
  .L8003C374:
    /* 2CB74 8003C374 FFFF8434 */  ori        $a0, $a0, (0xFFDDFFFF & 0xFFFF)
    /* 2CB78 8003C378 0100053C */  lui        $a1, (0x18000 >> 16)
    /* 2CB7C 8003C37C 0080A534 */  ori        $a1, $a1, (0x18000 & 0xFFFF)
    /* 2CB80 8003C380 00010224 */  addiu      $v0, $zero, 0x100
    /* 2CB84 8003C384 320002A6 */  sh         $v0, 0x32($s0)
    /* 2CB88 8003C388 0A80023C */  lui        $v0, %hi(D_8009B0F4)
    /* 2CB8C 8003C38C F4B0428C */  lw         $v0, %lo(D_8009B0F4)($v0)
    /* 2CB90 8003C390 40000324 */  addiu      $v1, $zero, 0x40
    /* 2CB94 8003C394 040003A6 */  sh         $v1, 0x4($s0)
    /* 2CB98 8003C398 24104400 */  and        $v0, $v0, $a0
    /* 2CB9C 8003C39C 0A80013C */  lui        $at, %hi(D_8009B0F4)
    /* 2CBA0 8003C3A0 F4B022AC */  sw         $v0, %lo(D_8009B0F4)($at)
    /* 2CBA4 8003C3A4 0A80023C */  lui        $v0, %hi(D_8009B0F4)
    /* 2CBA8 8003C3A8 F4B0428C */  lw         $v0, %lo(D_8009B0F4)($v0)
    /* 2CBAC 8003C3AC 0100033C */  lui        $v1, (0x10000 >> 16)
    /* 2CBB0 8003C3B0 300000A6 */  sh         $zero, 0x30($s0)
    /* 2CBB4 8003C3B4 1C0005AE */  sw         $a1, 0x1C($s0)
    /* 2CBB8 8003C3B8 25104300 */  or         $v0, $v0, $v1
    /* 2CBBC 8003C3BC 0A80013C */  lui        $at, %hi(D_8009B0F4)
    /* 2CBC0 8003C3C0 F4B022AC */  sw         $v0, %lo(D_8009B0F4)($at)
    /* 2CBC4 8003C3C4 02000224 */  addiu      $v0, $zero, 0x2
    /* 2CBC8 8003C3C8 460002A2 */  sb         $v0, 0x46($s0)
    /* 2CBCC 8003C3CC 0A80033C */  lui        $v1, %hi(D_8009B118)
    /* 2CBD0 8003C3D0 18B1638C */  lw         $v1, %lo(D_8009B118)($v1)
    /* 2CBD4 8003C3D4 10000224 */  addiu      $v0, $zero, 0x10
    /* 2CBD8 8003C3D8 060002A6 */  sh         $v0, 0x6($s0)
    /* 2CBDC 8003C3DC 080003AE */  sw         $v1, 0x8($s0)
    /* 2CBE0 8003C3E0 00086324 */  addiu      $v1, $v1, 0x800
    /* 2CBE4 8003C3E4 21F10008 */  j          .L8003C484
    /* 2CBE8 8003C3E8 0C0003AE */   sw        $v1, 0xC($s0)
  .L8003C3EC:
    /* 2CBEC 8003C3EC DCFF043C */  lui        $a0, (0xFFDCFFFF >> 16)
    /* 2CBF0 8003C3F0 FFFF8434 */  ori        $a0, $a0, (0xFFDCFFFF & 0xFFFF)
    /* 2CBF4 8003C3F4 00080224 */  addiu      $v0, $zero, 0x800
    /* 2CBF8 8003C3F8 1C0002AE */  sw         $v0, 0x1C($s0)
    /* 2CBFC 8003C3FC 0A80023C */  lui        $v0, %hi(D_8009B0F4)
    /* 2CC00 8003C400 F4B0428C */  lw         $v0, %lo(D_8009B0F4)($v0)
    /* 2CC04 8003C404 0A80033C */  lui        $v1, %hi(D_8009B118)
    /* 2CC08 8003C408 18B1638C */  lw         $v1, %lo(D_8009B118)($v1)
    /* 2CC0C 8003C40C 24104400 */  and        $v0, $v0, $a0
    /* 2CC10 8003C410 0A80013C */  lui        $at, %hi(D_8009B0F4)
    /* 2CC14 8003C414 F4B022AC */  sw         $v0, %lo(D_8009B0F4)($at)
    /* 2CC18 8003C418 0C0003AE */  sw         $v1, 0xC($s0)
    /* 2CC1C 8003C41C 20F10008 */  j          .L8003C480
    /* 2CC20 8003C420 080003AE */   sw        $v1, 0x8($s0)
  .L8003C424:
    /* 2CC24 8003C424 020002A6 */  sh         $v0, 0x2($s0)
    /* 2CC28 8003C428 00010224 */  addiu      $v0, $zero, 0x100
    /* 2CC2C 8003C42C 040002A6 */  sh         $v0, 0x4($s0)
    /* 2CC30 8003C430 04000224 */  addiu      $v0, $zero, 0x4
    /* 2CC34 8003C434 0A80053C */  lui        $a1, %hi(D_8009B118)
    /* 2CC38 8003C438 18B1A58C */  lw         $a1, %lo(D_8009B118)($a1)
    /* 2CC3C 8003C43C 21200002 */  addu       $a0, $s0, $zero
    /* 2CC40 8003C440 000000A6 */  sh         $zero, 0x0($s0)
    /* 2CC44 8003C444 7A07020C */  jal        func_80081DE8
    /* 2CC48 8003C448 060002A6 */   sh        $v0, 0x6($s0)
    /* 2CC4C 8003C44C DCFF043C */  lui        $a0, (0xFFDCFFFF >> 16)
    /* 2CC50 8003C450 FFFF8434 */  ori        $a0, $a0, (0xFFDCFFFF & 0xFFFF)
    /* 2CC54 8003C454 1B80023C */  lui        $v0, %hi(D_801AF000)
    /* 2CC58 8003C458 00F04224 */  addiu      $v0, $v0, %lo(D_801AF000)
    /* 2CC5C 8003C45C 0C0002AE */  sw         $v0, 0xC($s0)
    /* 2CC60 8003C460 080002AE */  sw         $v0, 0x8($s0)
    /* 2CC64 8003C464 0A80023C */  lui        $v0, %hi(D_8009B0F4)
    /* 2CC68 8003C468 F4B0428C */  lw         $v0, %lo(D_8009B0F4)($v0)
    /* 2CC6C 8003C46C 00080324 */  addiu      $v1, $zero, 0x800
    /* 2CC70 8003C470 1C0003AE */  sw         $v1, 0x1C($s0)
    /* 2CC74 8003C474 24104400 */  and        $v0, $v0, $a0
    /* 2CC78 8003C478 0A80013C */  lui        $at, %hi(D_8009B0F4)
    /* 2CC7C 8003C47C F4B022AC */  sw         $v0, %lo(D_8009B0F4)($at)
  .L8003C480:
    /* 2CC80 8003C480 460011A2 */  sb         $s1, 0x46($s0)
  .L8003C484:
    /* 2CC84 8003C484 1800BF8F */  lw         $ra, 0x18($sp)
    /* 2CC88 8003C488 1400B18F */  lw         $s1, 0x14($sp)
    /* 2CC8C 8003C48C 1000B08F */  lw         $s0, 0x10($sp)
    /* 2CC90 8003C490 0800E003 */  jr         $ra
    /* 2CC94 8003C494 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8003C328
