nonmatching func_8003BA14, 0x1E4

glabel func_8003BA14
    /* 2C214 8003BA14 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 2C218 8003BA18 1000B0AF */  sw         $s0, 0x10($sp)
    /* 2C21C 8003BA1C 21808000 */  addu       $s0, $a0, $zero
    /* 2C220 8003BA20 1400B1AF */  sw         $s1, 0x14($sp)
    /* 2C224 8003BA24 01001124 */  addiu      $s1, $zero, 0x1
    /* 2C228 8003BA28 2D00B110 */  beq        $a1, $s1, .L8003BAE0
    /* 2C22C 8003BA2C 1800BFAF */   sw        $ra, 0x18($sp)
    /* 2C230 8003BA30 0200A228 */  slti       $v0, $a1, 0x2
    /* 2C234 8003BA34 05004010 */  beqz       $v0, .L8003BA4C
    /* 2C238 8003BA38 00000000 */   nop
    /* 2C23C 8003BA3C 0A00A010 */  beqz       $a1, .L8003BA68
    /* 2C240 8003BA40 DDFF043C */   lui       $a0, (0xFFDDFFFF >> 16)
    /* 2C244 8003BA44 F9EE0008 */  j          .L8003BBE4
    /* 2C248 8003BA48 00000000 */   nop
  .L8003BA4C:
    /* 2C24C 8003BA4C 02000224 */  addiu      $v0, $zero, 0x2
    /* 2C250 8003BA50 4200A210 */  beq        $a1, $v0, .L8003BB5C
    /* 2C254 8003BA54 03000224 */   addiu     $v0, $zero, 0x3
    /* 2C258 8003BA58 4A00A210 */  beq        $a1, $v0, .L8003BB84
    /* 2C25C 8003BA5C 00010324 */   addiu     $v1, $zero, 0x100
    /* 2C260 8003BA60 F9EE0008 */  j          .L8003BBE4
    /* 2C264 8003BA64 00000000 */   nop
  .L8003BA68:
    /* 2C268 8003BA68 FFFF8434 */  ori        $a0, $a0, (0xFFDDFFFF & 0xFFFF)
    /* 2C26C 8003BA6C 0100053C */  lui        $a1, (0x18000 >> 16)
    /* 2C270 8003BA70 0080A534 */  ori        $a1, $a1, (0x18000 & 0xFFFF)
    /* 2C274 8003BA74 00010224 */  addiu      $v0, $zero, 0x100
    /* 2C278 8003BA78 300002A6 */  sh         $v0, 0x30($s0)
    /* 2C27C 8003BA7C 320002A6 */  sh         $v0, 0x32($s0)
    /* 2C280 8003BA80 0A80023C */  lui        $v0, %hi(D_8009B0F4)
    /* 2C284 8003BA84 F4B0428C */  lw         $v0, %lo(D_8009B0F4)($v0)
    /* 2C288 8003BA88 40000324 */  addiu      $v1, $zero, 0x40
    /* 2C28C 8003BA8C 040003A6 */  sh         $v1, 0x4($s0)
    /* 2C290 8003BA90 24104400 */  and        $v0, $v0, $a0
    /* 2C294 8003BA94 0A80013C */  lui        $at, %hi(D_8009B0F4)
    /* 2C298 8003BA98 F4B022AC */  sw         $v0, %lo(D_8009B0F4)($at)
    /* 2C29C 8003BA9C 0A80023C */  lui        $v0, %hi(D_8009B0F4)
    /* 2C2A0 8003BAA0 F4B0428C */  lw         $v0, %lo(D_8009B0F4)($v0)
    /* 2C2A4 8003BAA4 0100033C */  lui        $v1, (0x10000 >> 16)
    /* 2C2A8 8003BAA8 1C0005AE */  sw         $a1, 0x1C($s0)
    /* 2C2AC 8003BAAC 25104300 */  or         $v0, $v0, $v1
    /* 2C2B0 8003BAB0 0A80013C */  lui        $at, %hi(D_8009B0F4)
    /* 2C2B4 8003BAB4 F4B022AC */  sw         $v0, %lo(D_8009B0F4)($at)
    /* 2C2B8 8003BAB8 02000224 */  addiu      $v0, $zero, 0x2
    /* 2C2BC 8003BABC 460002A2 */  sb         $v0, 0x46($s0)
    /* 2C2C0 8003BAC0 0A80033C */  lui        $v1, %hi(D_8009B118)
    /* 2C2C4 8003BAC4 18B1638C */  lw         $v1, %lo(D_8009B118)($v1)
    /* 2C2C8 8003BAC8 10000224 */  addiu      $v0, $zero, 0x10
    /* 2C2CC 8003BACC 060002A6 */  sh         $v0, 0x6($s0)
    /* 2C2D0 8003BAD0 080003AE */  sw         $v1, 0x8($s0)
    /* 2C2D4 8003BAD4 00086324 */  addiu      $v1, $v1, 0x800
    /* 2C2D8 8003BAD8 F9EE0008 */  j          .L8003BBE4
    /* 2C2DC 8003BADC 0C0003AE */   sw        $v1, 0xC($s0)
  .L8003BAE0:
    /* 2C2E0 8003BAE0 DDFF043C */  lui        $a0, (0xFFDDFFFF >> 16)
    /* 2C2E4 8003BAE4 FFFF8434 */  ori        $a0, $a0, (0xFFDDFFFF & 0xFFFF)
    /* 2C2E8 8003BAE8 C0010224 */  addiu      $v0, $zero, 0x1C0
    /* 2C2EC 8003BAEC 300002A6 */  sh         $v0, 0x30($s0)
    /* 2C2F0 8003BAF0 00010224 */  addiu      $v0, $zero, 0x100
    /* 2C2F4 8003BAF4 320002A6 */  sh         $v0, 0x32($s0)
    /* 2C2F8 8003BAF8 40000224 */  addiu      $v0, $zero, 0x40
    /* 2C2FC 8003BAFC 040002A6 */  sh         $v0, 0x4($s0)
    /* 2C300 8003BB00 0A80023C */  lui        $v0, %hi(D_8009B0F4)
    /* 2C304 8003BB04 F4B0428C */  lw         $v0, %lo(D_8009B0F4)($v0)
    /* 2C308 8003BB08 10000324 */  addiu      $v1, $zero, 0x10
    /* 2C30C 8003BB0C 060003A6 */  sh         $v1, 0x6($s0)
    /* 2C310 8003BB10 24104400 */  and        $v0, $v0, $a0
    /* 2C314 8003BB14 0A80013C */  lui        $at, %hi(D_8009B0F4)
    /* 2C318 8003BB18 F4B022AC */  sw         $v0, %lo(D_8009B0F4)($at)
    /* 2C31C 8003BB1C 0A80023C */  lui        $v0, %hi(D_8009B0F4)
    /* 2C320 8003BB20 F4B0428C */  lw         $v0, %lo(D_8009B0F4)($v0)
    /* 2C324 8003BB24 0100033C */  lui        $v1, (0x10000 >> 16)
    /* 2C328 8003BB28 25104300 */  or         $v0, $v0, $v1
    /* 2C32C 8003BB2C 0A80013C */  lui        $at, %hi(D_8009B0F4)
    /* 2C330 8003BB30 F4B022AC */  sw         $v0, %lo(D_8009B0F4)($at)
    /* 2C334 8003BB34 02000224 */  addiu      $v0, $zero, 0x2
    /* 2C338 8003BB38 460002A2 */  sb         $v0, 0x46($s0)
    /* 2C33C 8003BB3C 0A80023C */  lui        $v0, %hi(D_8009B118)
    /* 2C340 8003BB40 18B1428C */  lw         $v0, %lo(D_8009B118)($v0)
    /* 2C344 8003BB44 00800334 */  ori        $v1, $zero, 0x8000
    /* 2C348 8003BB48 1C0003AE */  sw         $v1, 0x1C($s0)
    /* 2C34C 8003BB4C 080002AE */  sw         $v0, 0x8($s0)
    /* 2C350 8003BB50 00084224 */  addiu      $v0, $v0, 0x800
    /* 2C354 8003BB54 F9EE0008 */  j          .L8003BBE4
    /* 2C358 8003BB58 0C0002AE */   sw        $v0, 0xC($s0)
  .L8003BB5C:
    /* 2C35C 8003BB5C DCFF043C */  lui        $a0, (0xFFDCFFFF >> 16)
    /* 2C360 8003BB60 FFFF8434 */  ori        $a0, $a0, (0xFFDCFFFF & 0xFFFF)
    /* 2C364 8003BB64 00080224 */  addiu      $v0, $zero, 0x800
    /* 2C368 8003BB68 1C0002AE */  sw         $v0, 0x1C($s0)
    /* 2C36C 8003BB6C 0A80023C */  lui        $v0, %hi(D_8009B0F4)
    /* 2C370 8003BB70 F4B0428C */  lw         $v0, %lo(D_8009B0F4)($v0)
    /* 2C374 8003BB74 0A80033C */  lui        $v1, %hi(D_8009B118)
    /* 2C378 8003BB78 18B1638C */  lw         $v1, %lo(D_8009B118)($v1)
    /* 2C37C 8003BB7C F4EE0008 */  j          .L8003BBD0
    /* 2C380 8003BB80 24104400 */   and       $v0, $v0, $a0
  .L8003BB84:
    /* 2C384 8003BB84 F0000224 */  addiu      $v0, $zero, 0xF0
    /* 2C388 8003BB88 020002A6 */  sh         $v0, 0x2($s0)
    /* 2C38C 8003BB8C 04000224 */  addiu      $v0, $zero, 0x4
    /* 2C390 8003BB90 0A80053C */  lui        $a1, %hi(D_8009B118)
    /* 2C394 8003BB94 18B1A58C */  lw         $a1, %lo(D_8009B118)($a1)
    /* 2C398 8003BB98 21200002 */  addu       $a0, $s0, $zero
    /* 2C39C 8003BB9C 000003A6 */  sh         $v1, 0x0($s0)
    /* 2C3A0 8003BBA0 040003A6 */  sh         $v1, 0x4($s0)
    /* 2C3A4 8003BBA4 7A07020C */  jal        func_80081DE8
    /* 2C3A8 8003BBA8 060002A6 */   sh        $v0, 0x6($s0)
    /* 2C3AC 8003BBAC DCFF043C */  lui        $a0, (0xFFDCFFFF >> 16)
    /* 2C3B0 8003BBB0 FFFF8434 */  ori        $a0, $a0, (0xFFDCFFFF & 0xFFFF)
    /* 2C3B4 8003BBB4 00780224 */  addiu      $v0, $zero, 0x7800
    /* 2C3B8 8003BBB8 1C0002AE */  sw         $v0, 0x1C($s0)
    /* 2C3BC 8003BBBC 0A80023C */  lui        $v0, %hi(D_8009B0F4)
    /* 2C3C0 8003BBC0 F4B0428C */  lw         $v0, %lo(D_8009B0F4)($v0)
    /* 2C3C4 8003BBC4 0180033C */  lui        $v1, %hi(D_800101D8)
    /* 2C3C8 8003BBC8 D801638C */  lw         $v1, %lo(D_800101D8)($v1)
    /* 2C3CC 8003BBCC 24104400 */  and        $v0, $v0, $a0
  .L8003BBD0:
    /* 2C3D0 8003BBD0 0A80013C */  lui        $at, %hi(D_8009B0F4)
    /* 2C3D4 8003BBD4 F4B022AC */  sw         $v0, %lo(D_8009B0F4)($at)
    /* 2C3D8 8003BBD8 0C0003AE */  sw         $v1, 0xC($s0)
    /* 2C3DC 8003BBDC 080003AE */  sw         $v1, 0x8($s0)
    /* 2C3E0 8003BBE0 460011A2 */  sb         $s1, 0x46($s0)
  .L8003BBE4:
    /* 2C3E4 8003BBE4 1800BF8F */  lw         $ra, 0x18($sp)
    /* 2C3E8 8003BBE8 1400B18F */  lw         $s1, 0x14($sp)
    /* 2C3EC 8003BBEC 1000B08F */  lw         $s0, 0x10($sp)
    /* 2C3F0 8003BBF0 0800E003 */  jr         $ra
    /* 2C3F4 8003BBF4 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8003BA14
