nonmatching func_8005B260, 0x10C

glabel func_8005B260
    /* 4BA60 8005B260 2158A000 */  addu       $t3, $a1, $zero
    /* 4BA64 8005B264 00E1053C */  lui        $a1, (0xE1000200 >> 16)
    /* 4BA68 8005B268 0002A534 */  ori        $a1, $a1, (0xE1000200 & 0xFFFF)
    /* 4BA6C 8005B26C 03008A90 */  lbu        $t2, 0x3($a0)
    /* 4BA70 8005B270 0000828C */  lw         $v0, 0x0($a0)
    /* 4BA74 8005B274 04008424 */  addiu      $a0, $a0, 0x4
    /* 4BA78 8005B278 1080033C */  lui        $v1, %hi(D_800FE240)
    /* 4BA7C 8005B27C 40E2638C */  lw         $v1, %lo(D_800FE240)($v1)
    /* 4BA80 8005B280 FFFF4825 */  addiu      $t0, $t2, -0x1
    /* 4BA84 8005B284 000062AC */  sw         $v0, 0x0($v1)
    /* 4BA88 8005B288 0300E230 */  andi       $v0, $a3, 0x3
    /* 4BA8C 8005B28C 40110200 */  sll        $v0, $v0, 5
    /* 4BA90 8005B290 25104500 */  or         $v0, $v0, $a1
    /* 4BA94 8005B294 1080033C */  lui        $v1, %hi(D_800FE240)
    /* 4BA98 8005B298 40E2638C */  lw         $v1, %lo(D_800FE240)($v1)
    /* 4BA9C 8005B29C 2128C000 */  addu       $a1, $a2, $zero
    /* 4BAA0 8005B2A0 08006924 */  addiu      $t1, $v1, 0x8
    /* 4BAA4 8005B2A4 08004011 */  beqz       $t2, .L8005B2C8
    /* 4BAA8 8005B2A8 040062AC */   sw        $v0, 0x4($v1)
    /* 4BAAC 8005B2AC FFFF0324 */  addiu      $v1, $zero, -0x1
  .L8005B2B0:
    /* 4BAB0 8005B2B0 0000828C */  lw         $v0, 0x0($a0)
    /* 4BAB4 8005B2B4 04008424 */  addiu      $a0, $a0, 0x4
    /* 4BAB8 8005B2B8 FFFF0825 */  addiu      $t0, $t0, -0x1
    /* 4BABC 8005B2BC 000022AD */  sw         $v0, 0x0($t1)
    /* 4BAC0 8005B2C0 FBFF0315 */  bne        $t0, $v1, .L8005B2B0
    /* 4BAC4 8005B2C4 04002925 */   addiu     $t1, $t1, 0x4
  .L8005B2C8:
    /* 4BAC8 8005B2C8 1080033C */  lui        $v1, %hi(D_800FE240)
    /* 4BACC 8005B2CC 40E2638C */  lw         $v1, %lo(D_800FE240)($v1)
    /* 4BAD0 8005B2D0 01004225 */  addiu      $v0, $t2, 0x1
    /* 4BAD4 8005B2D4 0800E004 */  bltz       $a3, .L8005B2F8
    /* 4BAD8 8005B2D8 030062A0 */   sb        $v0, 0x3($v1)
    /* 4BADC 8005B2DC 1080033C */  lui        $v1, %hi(D_800FE240)
    /* 4BAE0 8005B2E0 40E2638C */  lw         $v1, %lo(D_800FE240)($v1)
    /* 4BAE4 8005B2E4 00000000 */  nop
    /* 4BAE8 8005B2E8 0B006290 */  lbu        $v0, 0xB($v1)
    /* 4BAEC 8005B2EC 00000000 */  nop
    /* 4BAF0 8005B2F0 02004234 */  ori        $v0, $v0, 0x2
    /* 4BAF4 8005B2F4 0B0062A0 */  sb         $v0, 0xB($v1)
  .L8005B2F8:
    /* 4BAF8 8005B2F8 FF00063C */  lui        $a2, (0xFFFFFF >> 16)
    /* 4BAFC 8005B2FC FFFFC634 */  ori        $a2, $a2, (0xFFFFFF & 0xFFFF)
    /* 4BB00 8005B300 FFFFA430 */  andi       $a0, $a1, 0xFFFF
    /* 4BB04 8005B304 80200400 */  sll        $a0, $a0, 2
    /* 4BB08 8005B308 00FF073C */  lui        $a3, (0xFF000000 >> 16)
    /* 4BB0C 8005B30C 0400628D */  lw         $v0, 0x4($t3)
    /* 4BB10 8005B310 1080053C */  lui        $a1, %hi(D_800FE240)
    /* 4BB14 8005B314 40E2A58C */  lw         $a1, %lo(D_800FE240)($a1)
    /* 4BB18 8005B318 21108200 */  addu       $v0, $a0, $v0
    /* 4BB1C 8005B31C 0000A38C */  lw         $v1, 0x0($a1)
    /* 4BB20 8005B320 0000428C */  lw         $v0, 0x0($v0)
    /* 4BB24 8005B324 24186700 */  and        $v1, $v1, $a3
    /* 4BB28 8005B328 24104600 */  and        $v0, $v0, $a2
    /* 4BB2C 8005B32C 25186200 */  or         $v1, $v1, $v0
    /* 4BB30 8005B330 0000A3AC */  sw         $v1, 0x0($a1)
    /* 4BB34 8005B334 0400628D */  lw         $v0, 0x4($t3)
    /* 4BB38 8005B338 00000000 */  nop
    /* 4BB3C 8005B33C 21208200 */  addu       $a0, $a0, $v0
    /* 4BB40 8005B340 80100A00 */  sll        $v0, $t2, 2
    /* 4BB44 8005B344 08004224 */  addiu      $v0, $v0, 0x8
    /* 4BB48 8005B348 2110A200 */  addu       $v0, $a1, $v0
    /* 4BB4C 8005B34C 0000838C */  lw         $v1, 0x0($a0)
    /* 4BB50 8005B350 2428A600 */  and        $a1, $a1, $a2
    /* 4BB54 8005B354 1080013C */  lui        $at, %hi(D_800FE240)
    /* 4BB58 8005B358 40E222AC */  sw         $v0, %lo(D_800FE240)($at)
    /* 4BB5C 8005B35C 24186700 */  and        $v1, $v1, $a3
    /* 4BB60 8005B360 25186500 */  or         $v1, $v1, $a1
    /* 4BB64 8005B364 0800E003 */  jr         $ra
    /* 4BB68 8005B368 000083AC */   sw        $v1, 0x0($a0)
endlabel func_8005B260
