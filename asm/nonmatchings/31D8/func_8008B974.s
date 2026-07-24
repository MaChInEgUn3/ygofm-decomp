nonmatching func_8008B974, 0x31C

glabel func_8008B974
    /* 7C174 8008B974 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 7C178 8008B978 1000B0AF */  sw         $s0, 0x10($sp)
    /* 7C17C 8008B97C 21808000 */  addu       $s0, $a0, $zero
    /* 7C180 8008B980 2000BFAF */  sw         $ra, 0x20($sp)
    /* 7C184 8008B984 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 7C188 8008B988 1800B2AF */  sw         $s2, 0x18($sp)
    /* 7C18C 8008B98C 1400B1AF */  sw         $s1, 0x14($sp)
    /* 7C190 8008B990 0000038E */  lw         $v1, 0x0($s0)
    /* 7C194 8008B994 0A001224 */  addiu      $s2, $zero, 0xA
    /* 7C198 8008B998 1D007210 */  beq        $v1, $s2, .L8008BA10
    /* 7C19C 8008B99C 0B006228 */   slti      $v0, $v1, 0xB
    /* 7C1A0 8008B9A0 05004010 */  beqz       $v0, .L8008B9B8
    /* 7C1A4 8008B9A4 0B000224 */   addiu     $v0, $zero, 0xB
    /* 7C1A8 8008B9A8 09006010 */  beqz       $v1, .L8008B9D0
    /* 7C1AC 8008B9AC 00000000 */   nop
    /* 7C1B0 8008B9B0 192F0208 */  j          .L8008BC64
    /* 7C1B4 8008B9B4 00000000 */   nop
  .L8008B9B8:
    /* 7C1B8 8008B9B8 20006210 */  beq        $v1, $v0, .L8008BA3C
    /* 7C1BC 8008B9BC 15000224 */   addiu     $v0, $zero, 0x15
    /* 7C1C0 8008B9C0 A0006210 */  beq        $v1, $v0, .L8008BC44
    /* 7C1C4 8008B9C4 00000000 */   nop
    /* 7C1C8 8008B9C8 192F0208 */  j          .L8008BC64
    /* 7C1CC 8008B9CC 00000000 */   nop
  .L8008B9D0:
    /* 7C1D0 8008B9D0 1080023C */  lui        $v0, %hi(D_800FE358)
    /* 7C1D4 8008B9D4 58E34224 */  addiu      $v0, $v0, %lo(D_800FE358)
    /* 7C1D8 8008B9D8 1080013C */  lui        $at, %hi(D_800FE31C)
    /* 7C1DC 8008B9DC 1CE320AC */  sw         $zero, %lo(D_800FE31C)($at)
    /* 7C1E0 8008B9E0 1080013C */  lui        $at, %hi(D_800FE318)
    /* 7C1E4 8008B9E4 18E320AC */  sw         $zero, %lo(D_800FE318)($at)
    /* 7C1E8 8008B9E8 000012AE */  sw         $s2, 0x0($s0)
    /* 7C1EC 8008B9EC 0000438C */  lw         $v1, 0x0($v0)
    /* 7C1F0 8008B9F0 40004224 */  addiu      $v0, $v0, 0x40
    /* 7C1F4 8008B9F4 03190300 */  sra        $v1, $v1, 4
    /* 7C1F8 8008B9F8 80180300 */  sll        $v1, $v1, 2
    /* 7C1FC 8008B9FC 21186200 */  addu       $v1, $v1, $v0
    /* 7C200 8008BA00 0000628C */  lw         $v0, 0x0($v1)
    /* 7C204 8008BA04 000060AC */  sw         $zero, 0x0($v1)
    /* 7C208 8008BA08 0A80013C */  lui        $at, %hi(D_80099E88)
    /* 7C20C 8008BA0C 889E22AC */  sw         $v0, %lo(D_80099E88)($at)
  .L8008BA10:
    /* 7C210 8008BA10 5835020C */  jal        func_8008D560
    /* 7C214 8008BA14 00000000 */   nop
    /* 7C218 8008BA18 1080043C */  lui        $a0, %hi(D_800FE358)
    /* 7C21C 8008BA1C 58E3848C */  lw         $a0, %lo(D_800FE358)($a0)
    /* 7C220 8008BA20 CC2C020C */  jal        func_8008B330
    /* 7C224 8008BA24 00000000 */   nop
    /* 7C228 8008BA28 0000028E */  lw         $v0, 0x0($s0)
    /* 7C22C 8008BA2C 00000000 */  nop
    /* 7C230 8008BA30 01004224 */  addiu      $v0, $v0, 0x1
    /* 7C234 8008BA34 1C2F0208 */  j          .L8008BC70
    /* 7C238 8008BA38 000002AE */   sw        $v0, 0x0($s0)
  .L8008BA3C:
    /* 7C23C 8008BA3C 0636020C */  jal        func_8008D818
    /* 7C240 8008BA40 00000000 */   nop
    /* 7C244 8008BA44 8B004010 */  beqz       $v0, .L8008BC74
    /* 7C248 8008BA48 21100000 */   addu      $v0, $zero, $zero
    /* 7C24C 8008BA4C 9A35020C */  jal        func_8008D668
    /* 7C250 8008BA50 00000000 */   nop
    /* 7C254 8008BA54 1080113C */  lui        $s1, %hi(D_800FE358)
    /* 7C258 8008BA58 58E33126 */  addiu      $s1, $s1, %lo(D_800FE358)
    /* 7C25C 8008BA5C 38003326 */  addiu      $s3, $s1, 0x38
    /* 7C260 8008BA60 0000278E */  lw         $a3, 0x0($s1)
    /* 7C264 8008BA64 21204000 */  addu       $a0, $v0, $zero
    /* 7C268 8008BA68 1080013C */  lui        $at, %hi(D_800FE31C)
    /* 7C26C 8008BA6C 1CE322AC */  sw         $v0, %lo(D_800FE31C)($at)
    /* 7C270 8008BA70 03190700 */  sra        $v1, $a3, 4
    /* 7C274 8008BA74 80180300 */  sll        $v1, $v1, 2
    /* 7C278 8008BA78 21287300 */  addu       $a1, $v1, $s3
    /* 7C27C 8008BA7C 0000A68C */  lw         $a2, 0x0($a1)
    /* 7C280 8008BA80 01000324 */  addiu      $v1, $zero, 0x1
    /* 7C284 8008BA84 0A80013C */  lui        $at, %hi(D_80099E8C)
    /* 7C288 8008BA88 8C9E26AC */  sw         $a2, %lo(D_80099E8C)($at)
    /* 7C28C 8008BA8C 47008310 */  beq        $a0, $v1, .L8008BBAC
    /* 7C290 8008BA90 02008228 */   slti      $v0, $a0, 0x2
    /* 7C294 8008BA94 05004010 */  beqz       $v0, .L8008BAAC
    /* 7C298 8008BA98 02000224 */   addiu     $v0, $zero, 0x2
    /* 7C29C 8008BA9C 27008010 */  beqz       $a0, .L8008BB3C
    /* 7C2A0 8008BAA0 00000000 */   nop
    /* 7C2A4 8008BAA4 022F0208 */  j          .L8008BC08
    /* 7C2A8 8008BAA8 00000000 */   nop
  .L8008BAAC:
    /* 7C2AC 8008BAAC 2E008210 */  beq        $a0, $v0, .L8008BB68
    /* 7C2B0 8008BAB0 04000224 */   addiu     $v0, $zero, 0x4
    /* 7C2B4 8008BAB4 54008214 */  bne        $a0, $v0, .L8008BC08
    /* 7C2B8 8008BAB8 00000000 */   nop
    /* 7C2BC 8008BABC 0F00C014 */  bnez       $a2, .L8008BAFC
    /* 7C2C0 8008BAC0 00000000 */   nop
    /* 7C2C4 8008BAC4 0A80023C */  lui        $v0, %hi(D_80099E88)
    /* 7C2C8 8008BAC8 889E428C */  lw         $v0, %lo(D_80099E88)($v0)
    /* 7C2CC 8008BACC 00000000 */  nop
    /* 7C2D0 8008BAD0 8000422C */  sltiu      $v0, $v0, 0x80
    /* 7C2D4 8008BAD4 09004010 */  beqz       $v0, .L8008BAFC
    /* 7C2D8 8008BAD8 00000000 */   nop
    /* 7C2DC 8008BADC 5835020C */  jal        func_8008D560
    /* 7C2E0 8008BAE0 00000000 */   nop
    /* 7C2E4 8008BAE4 0000248E */  lw         $a0, 0x0($s1)
    /* 7C2E8 8008BAE8 E82C020C */  jal        func_8008B3A0
    /* 7C2EC 8008BAEC 00000000 */   nop
    /* 7C2F0 8008BAF0 15000224 */  addiu      $v0, $zero, 0x15
    /* 7C2F4 8008BAF4 1C2F0208 */  j          .L8008BC70
    /* 7C2F8 8008BAF8 000002AE */   sw        $v0, 0x0($s0)
  .L8008BAFC:
    /* 7C2FC 8008BAFC 1080103C */  lui        $s0, %hi(D_800FE358)
    /* 7C300 8008BB00 58E31026 */  addiu      $s0, $s0, %lo(D_800FE358)
    /* 7C304 8008BB04 01000324 */  addiu      $v1, $zero, 0x1
    /* 7C308 8008BB08 0000028E */  lw         $v0, 0x0($s0)
    /* 7C30C 8008BB0C 1080043C */  lui        $a0, %hi(D_800FE31C)
    /* 7C310 8008BB10 1CE3848C */  lw         $a0, %lo(D_800FE31C)($a0)
    /* 7C314 8008BB14 03110200 */  sra        $v0, $v0, 4
    /* 7C318 8008BB18 80100200 */  sll        $v0, $v0, 2
    /* 7C31C 8008BB1C 21100202 */  addu       $v0, $s0, $v0
    /* 7C320 8008BB20 DD33020C */  jal        func_8008CF74
    /* 7C324 8008BB24 380043AC */   sw        $v1, 0x38($v0)
    /* 7C328 8008BB28 21184000 */  addu       $v1, $v0, $zero
    /* 7C32C 8008BB2C 01000224 */  addiu      $v0, $zero, 0x1
    /* 7C330 8008BB30 F0FF1026 */  addiu      $s0, $s0, -0x10
    /* 7C334 8008BB34 1D2F0208 */  j          .L8008BC74
    /* 7C338 8008BB38 040003AE */   sw        $v1, 0x4($s0)
  .L8008BB3C:
    /* 7C33C 8008BB3C FCFF228E */  lw         $v0, -0x4($s1)
    /* 7C340 8008BB40 0418E300 */  sllv       $v1, $v1, $a3
    /* 7C344 8008BB44 24104300 */  and        $v0, $v0, $v1
    /* 7C348 8008BB48 03004014 */  bnez       $v0, .L8008BB58
    /* 7C34C 8008BB4C 04000224 */   addiu     $v0, $zero, 0x4
    /* 7C350 8008BB50 1080013C */  lui        $at, %hi(D_800FE31C)
    /* 7C354 8008BB54 1CE322AC */  sw         $v0, %lo(D_800FE31C)($at)
  .L8008BB58:
    /* 7C358 8008BB58 1080043C */  lui        $a0, %hi(D_800FE31C)
    /* 7C35C 8008BB5C 1CE3848C */  lw         $a0, %lo(D_800FE31C)($a0)
    /* 7C360 8008BB60 E42E0208 */  j          .L8008BB90
    /* 7C364 8008BB64 0000A0AC */   sw        $zero, 0x0($a1)
  .L8008BB68:
    /* 7C368 8008BB68 1080023C */  lui        $v0, %hi(D_800FE318)
    /* 7C36C 8008BB6C 18E3428C */  lw         $v0, %lo(D_800FE318)($v0)
    /* 7C370 8008BB70 00000000 */  nop
    /* 7C374 8008BB74 01004224 */  addiu      $v0, $v0, 0x1
    /* 7C378 8008BB78 1080013C */  lui        $at, %hi(D_800FE318)
    /* 7C37C 8008BB7C 18E322AC */  sw         $v0, %lo(D_800FE318)($at)
    /* 7C380 8008BB80 03004228 */  slti       $v0, $v0, 0x3
    /* 7C384 8008BB84 12004014 */  bnez       $v0, .L8008BBD0
    /* 7C388 8008BB88 02000424 */   addiu     $a0, $zero, 0x2
    /* 7C38C 8008BB8C 0000A3AC */  sw         $v1, 0x0($a1)
  .L8008BB90:
    /* 7C390 8008BB90 DD33020C */  jal        func_8008CF74
    /* 7C394 8008BB94 00000000 */   nop
    /* 7C398 8008BB98 21204000 */  addu       $a0, $v0, $zero
    /* 7C39C 8008BB9C 01000224 */  addiu      $v0, $zero, 0x1
    /* 7C3A0 8008BBA0 F0FF2326 */  addiu      $v1, $s1, -0x10
    /* 7C3A4 8008BBA4 1D2F0208 */  j          .L8008BC74
    /* 7C3A8 8008BBA8 040064AC */   sw        $a0, 0x4($v1)
  .L8008BBAC:
    /* 7C3AC 8008BBAC 1080023C */  lui        $v0, %hi(D_800FE318)
    /* 7C3B0 8008BBB0 18E3428C */  lw         $v0, %lo(D_800FE318)($v0)
    /* 7C3B4 8008BBB4 00000000 */  nop
    /* 7C3B8 8008BBB8 01004224 */  addiu      $v0, $v0, 0x1
    /* 7C3BC 8008BBBC 1080013C */  lui        $at, %hi(D_800FE318)
    /* 7C3C0 8008BBC0 18E322AC */  sw         $v0, %lo(D_800FE318)($at)
    /* 7C3C4 8008BBC4 11004228 */  slti       $v0, $v0, 0x11
    /* 7C3C8 8008BBC8 03004010 */  beqz       $v0, .L8008BBD8
    /* 7C3CC 8008BBCC 00000000 */   nop
  .L8008BBD0:
    /* 7C3D0 8008BBD0 1C2F0208 */  j          .L8008BC70
    /* 7C3D4 8008BBD4 000012AE */   sw        $s2, 0x0($s0)
  .L8008BBD8:
    /* 7C3D8 8008BBD8 DD33020C */  jal        func_8008CF74
    /* 7C3DC 8008BBDC 01000424 */   addiu     $a0, $zero, 0x1
    /* 7C3E0 8008BBE0 21184000 */  addu       $v1, $v0, $zero
    /* 7C3E4 8008BBE4 01000224 */  addiu      $v0, $zero, 0x1
    /* 7C3E8 8008BBE8 0000248E */  lw         $a0, 0x0($s1)
    /* 7C3EC 8008BBEC F0FF2526 */  addiu      $a1, $s1, -0x10
    /* 7C3F0 8008BBF0 0400A3AC */  sw         $v1, 0x4($a1)
    /* 7C3F4 8008BBF4 03210400 */  sra        $a0, $a0, 4
    /* 7C3F8 8008BBF8 80200400 */  sll        $a0, $a0, 2
    /* 7C3FC 8008BBFC 21209300 */  addu       $a0, $a0, $s3
    /* 7C400 8008BC00 1D2F0208 */  j          .L8008BC74
    /* 7C404 8008BC04 000080AC */   sw        $zero, 0x0($a0)
  .L8008BC08:
    /* 7C408 8008BC08 1080043C */  lui        $a0, %hi(D_800FE31C)
    /* 7C40C 8008BC0C 1CE3848C */  lw         $a0, %lo(D_800FE31C)($a0)
    /* 7C410 8008BC10 DD33020C */  jal        func_8008CF74
    /* 7C414 8008BC14 00000000 */   nop
    /* 7C418 8008BC18 21284000 */  addu       $a1, $v0, $zero
    /* 7C41C 8008BC1C 1080043C */  lui        $a0, %hi(D_800FE348)
    /* 7C420 8008BC20 48E38424 */  addiu      $a0, $a0, %lo(D_800FE348)
    /* 7C424 8008BC24 1000838C */  lw         $v1, 0x10($a0)
    /* 7C428 8008BC28 01000224 */  addiu      $v0, $zero, 0x1
    /* 7C42C 8008BC2C 040085AC */  sw         $a1, 0x4($a0)
    /* 7C430 8008BC30 03190300 */  sra        $v1, $v1, 4
    /* 7C434 8008BC34 80180300 */  sll        $v1, $v1, 2
    /* 7C438 8008BC38 21208300 */  addu       $a0, $a0, $v1
    /* 7C43C 8008BC3C 1D2F0208 */  j          .L8008BC74
    /* 7C440 8008BC40 480080AC */   sw        $zero, 0x48($a0)
  .L8008BC44:
    /* 7C444 8008BC44 1536020C */  jal        func_8008D854
    /* 7C448 8008BC48 00000000 */   nop
    /* 7C44C 8008BC4C 09004010 */  beqz       $v0, .L8008BC74
    /* 7C450 8008BC50 21100000 */   addu      $v0, $zero, $zero
    /* 7C454 8008BC54 D035020C */  jal        func_8008D740
    /* 7C458 8008BC58 00000000 */   nop
    /* 7C45C 8008BC5C 1C2F0208 */  j          .L8008BC70
    /* 7C460 8008BC60 000000AE */   sw        $zero, 0x0($s0)
  .L8008BC64:
    /* 7C464 8008BC64 0180043C */  lui        $a0, %hi(D_800124A0)
    /* 7C468 8008BC68 1C3A020C */  jal        func_8008E870
    /* 7C46C 8008BC6C A0248424 */   addiu     $a0, $a0, %lo(D_800124A0)
  .L8008BC70:
    /* 7C470 8008BC70 21100000 */  addu       $v0, $zero, $zero
  .L8008BC74:
    /* 7C474 8008BC74 2000BF8F */  lw         $ra, 0x20($sp)
    /* 7C478 8008BC78 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 7C47C 8008BC7C 1800B28F */  lw         $s2, 0x18($sp)
    /* 7C480 8008BC80 1400B18F */  lw         $s1, 0x14($sp)
    /* 7C484 8008BC84 1000B08F */  lw         $s0, 0x10($sp)
    /* 7C488 8008BC88 0800E003 */  jr         $ra
    /* 7C48C 8008BC8C 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_8008B974
