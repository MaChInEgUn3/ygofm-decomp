nonmatching func_8001B170, 0x610

glabel func_8001B170
    /* B970 8001B170 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* B974 8001B174 32038397 */  lhu        $v1, %gp_rel(D_8009B23A)($gp)
    /* B978 8001B178 0F80023C */  lui        $v0, %hi(D_800E9EF0)
    /* B97C 8001B17C 2400B1AF */  sw         $s1, 0x24($sp)
    /* B980 8001B180 F09E518C */  lw         $s1, %lo(D_800E9EF0)($v0)
    /* B984 8001B184 2C00BFAF */  sw         $ra, 0x2C($sp)
    /* B988 8001B188 2800B2AF */  sw         $s2, 0x28($sp)
    /* B98C 8001B18C 00806230 */  andi       $v0, $v1, 0x8000
    /* B990 8001B190 3E004014 */  bnez       $v0, .L8001B28C
    /* B994 8001B194 2000B0AF */   sw        $s0, 0x20($sp)
    /* B998 8001B198 00806234 */  ori        $v0, $v1, 0x8000
    /* B99C 8001B19C 320382A7 */  sh         $v0, %gp_rel(D_8009B23A)($gp)
    /* B9A0 8001B1A0 00404230 */  andi       $v0, $v0, 0x4000
    /* B9A4 8001B1A4 AB004014 */  bnez       $v0, .L8001B454
    /* B9A8 8001B1A8 04000224 */   addiu     $v0, $zero, 0x4
    /* B9AC 8001B1AC CD028293 */  lbu        $v0, %gp_rel(D_8009B1D5)($gp)
    /* B9B0 8001B1B0 0A80033C */  lui        $v1, %hi(D_8009B360)
    /* B9B4 8001B1B4 60B36324 */  addiu      $v1, $v1, %lo(D_8009B360)
    /* B9B8 8001B1B8 21104300 */  addu       $v0, $v0, $v1
    /* B9BC 8001B1BC 00004280 */  lb         $v0, 0x0($v0)
    /* B9C0 8001B1C0 00000000 */  nop
    /* B9C4 8001B1C4 22004004 */  bltz       $v0, .L8001B250
    /* B9C8 8001B1C8 01000224 */   addiu     $v0, $zero, 0x1
    /* B9CC 8001B1CC 68002292 */  lbu        $v0, 0x68($s1)
    /* B9D0 8001B1D0 00000000 */  nop
    /* B9D4 8001B1D4 1400422C */  sltiu      $v0, $v0, 0x14
    /* B9D8 8001B1D8 1C004010 */  beqz       $v0, .L8001B24C
    /* B9DC 8001B1DC 1A80023C */   lui       $v0, %hi(D_801A7AD8)
    /* B9E0 8001B1E0 6A002392 */  lbu        $v1, 0x6A($s1)
    /* B9E4 8001B1E4 D87A4424 */  addiu      $a0, $v0, %lo(D_801A7AD8)
    /* B9E8 8001B1E8 C0100300 */  sll        $v0, $v1, 3
    /* B9EC 8001B1EC 23104300 */  subu       $v0, $v0, $v1
    /* B9F0 8001B1F0 80100200 */  sll        $v0, $v0, 2
    /* B9F4 8001B1F4 21104400 */  addu       $v0, $v0, $a0
    /* B9F8 8001B1F8 16004394 */  lhu        $v1, 0x16($v0)
    /* B9FC 8001B1FC 00000000 */  nop
    /* BA00 8001B200 FFFD6330 */  andi       $v1, $v1, 0xFDFF
    /* BA04 8001B204 160043A4 */  sh         $v1, 0x16($v0)
    /* BA08 8001B208 0F80023C */  lui        $v0, %hi(D_800EAE8F)
    /* BA0C 8001B20C 8FAE4290 */  lbu        $v0, %lo(D_800EAE8F)($v0)
    /* BA10 8001B210 00000000 */  nop
    /* BA14 8001B214 01004230 */  andi       $v0, $v0, 0x1
    /* BA18 8001B218 8E004010 */  beqz       $v0, .L8001B454
    /* BA1C 8001B21C 04000224 */   addiu     $v0, $zero, 0x4
    /* BA20 8001B220 6A002292 */  lbu        $v0, 0x6A($s1)
    /* BA24 8001B224 00000000 */  nop
    /* BA28 8001B228 C0180200 */  sll        $v1, $v0, 3
    /* BA2C 8001B22C 23186200 */  subu       $v1, $v1, $v0
    /* BA30 8001B230 80180300 */  sll        $v1, $v1, 2
    /* BA34 8001B234 21186400 */  addu       $v1, $v1, $a0
    /* BA38 8001B238 16006294 */  lhu        $v0, 0x16($v1)
    /* BA3C 8001B23C 00000000 */  nop
    /* BA40 8001B240 00024234 */  ori        $v0, $v0, 0x200
    /* BA44 8001B244 146D0008 */  j          .L8001B450
    /* BA48 8001B248 160062A4 */   sh        $v0, 0x16($v1)
  .L8001B24C:
    /* BA4C 8001B24C 01000224 */  addiu      $v0, $zero, 0x1
  .L8001B250:
    /* BA50 8001B250 6C0282A3 */  sb         $v0, %gp_rel(D_8009B174)($gp)
    /* BA54 8001B254 5E0C010C */  jal        func_80043178
    /* BA58 8001B258 21202002 */   addu      $a0, $s1, $zero
    /* BA5C 8001B25C 30002386 */  lh         $v1, 0x30($s1)
    /* BA60 8001B260 86000224 */  addiu      $v0, $zero, 0x86
    /* BA64 8001B264 05006210 */  beq        $v1, $v0, .L8001B27C
    /* BA68 8001B268 600020A6 */   sh        $zero, 0x60($s1)
    /* BA6C 8001B26C 32002386 */  lh         $v1, 0x32($s1)
    /* BA70 8001B270 2A000224 */  addiu      $v0, $zero, 0x2A
    /* BA74 8001B274 05006214 */  bne        $v1, $v0, .L8001B28C
    /* BA78 8001B278 00000000 */   nop
  .L8001B27C:
    /* BA7C 8001B27C 02000224 */  addiu      $v0, $zero, 0x2
    /* BA80 8001B280 6C0282A3 */  sb         $v0, %gp_rel(D_8009B174)($gp)
    /* BA84 8001B284 DA6D0008 */  j          .L8001B768
    /* BA88 8001B288 00000000 */   nop
  .L8001B28C:
    /* BA8C 8001B28C 6C028293 */  lbu        $v0, %gp_rel(D_8009B174)($gp)
    /* BA90 8001B290 00000000 */  nop
    /* BA94 8001B294 0F004230 */  andi       $v0, $v0, 0xF
    /* BA98 8001B298 FFFF4324 */  addiu      $v1, $v0, -0x1
    /* BA9C 8001B29C 0600622C */  sltiu      $v0, $v1, 0x6
    /* BAA0 8001B2A0 31014010 */  beqz       $v0, .L8001B768
    /* BAA4 8001B2A4 0180023C */   lui       $v0, %hi(jtbl_80010130)
    /* BAA8 8001B2A8 30014224 */  addiu      $v0, $v0, %lo(jtbl_80010130)
    /* BAAC 8001B2AC 80180300 */  sll        $v1, $v1, 2
    /* BAB0 8001B2B0 21186200 */  addu       $v1, $v1, $v0
    /* BAB4 8001B2B4 0000628C */  lw         $v0, 0x0($v1)
    /* BAB8 8001B2B8 00000000 */  nop
    /* BABC 8001B2BC 08004000 */  jr         $v0
    /* BAC0 8001B2C0 00000000 */   nop
  jlabel .L8001B2C4
    /* BAC4 8001B2C4 21202002 */  addu       $a0, $s1, $zero
    /* BAC8 8001B2C8 86000524 */  addiu      $a1, $zero, 0x86
    /* BACC 8001B2CC 60002786 */  lh         $a3, 0x60($s1)
    /* BAD0 8001B2D0 630C010C */  jal        func_8004318C
    /* BAD4 8001B2D4 2A000624 */   addiu     $a2, $zero, 0x2A
    /* BAD8 8001B2D8 60002296 */  lhu        $v0, 0x60($s1)
    /* BADC 8001B2DC 00000000 */  nop
    /* BAE0 8001B2E0 80004224 */  addiu      $v0, $v0, 0x80
    /* BAE4 8001B2E4 600022A6 */  sh         $v0, 0x60($s1)
    /* BAE8 8001B2E8 00140200 */  sll        $v0, $v0, 16
    /* BAEC 8001B2EC 03140200 */  sra        $v0, $v0, 16
    /* BAF0 8001B2F0 00084228 */  slti       $v0, $v0, 0x800
    /* BAF4 8001B2F4 1C014014 */  bnez       $v0, .L8001B768
    /* BAF8 8001B2F8 86000224 */   addiu     $v0, $zero, 0x86
    /* BAFC 8001B2FC 300022A6 */  sh         $v0, 0x30($s1)
    /* BB00 8001B300 2A000224 */  addiu      $v0, $zero, 0x2A
    /* BB04 8001B304 320022A6 */  sh         $v0, 0x32($s1)
    /* BB08 8001B308 02000224 */  addiu      $v0, $zero, 0x2
    /* BB0C 8001B30C 6C0282A3 */  sb         $v0, %gp_rel(D_8009B174)($gp)
  jlabel .L8001B310
    /* BB10 8001B310 68002292 */  lbu        $v0, 0x68($s1)
    /* BB14 8001B314 00000000 */  nop
    /* BB18 8001B318 1400422C */  sltiu      $v0, $v0, 0x14
    /* BB1C 8001B31C 4C004010 */  beqz       $v0, .L8001B450
    /* BB20 8001B320 03000224 */   addiu     $v0, $zero, 0x3
    /* BB24 8001B324 6C0282A3 */  sb         $v0, %gp_rel(D_8009B174)($gp)
  jlabel .L8001B328
    /* BB28 8001B328 6C028393 */  lbu        $v1, %gp_rel(D_8009B174)($gp)
    /* BB2C 8001B32C 00000000 */  nop
    /* BB30 8001B330 80006230 */  andi       $v0, $v1, 0x80
    /* BB34 8001B334 2B004014 */  bnez       $v0, .L8001B3E4
    /* BB38 8001B338 10006230 */   andi      $v0, $v1, 0x10
    /* BB3C 8001B33C 0400063C */  lui        $a2, (0x48000 >> 16)
    /* BB40 8001B340 0080C634 */  ori        $a2, $a2, (0x48000 & 0xFFFF)
    /* BB44 8001B344 21200000 */  addu       $a0, $zero, $zero
    /* BB48 8001B348 80006234 */  ori        $v0, $v1, 0x80
    /* BB4C 8001B34C 1680033C */  lui        $v1, %hi(D_8015C424)
    /* BB50 8001B350 6C0282A3 */  sb         $v0, %gp_rel(D_8009B174)($gp)
    /* BB54 8001B354 6A002592 */  lbu        $a1, 0x6A($s1)
    /* BB58 8001B358 24C46324 */  addiu      $v1, $v1, %lo(D_8015C424)
    /* BB5C 8001B35C C0100500 */  sll        $v0, $a1, 3
    /* BB60 8001B360 23104500 */  subu       $v0, $v0, $a1
    /* BB64 8001B364 80100200 */  sll        $v0, $v0, 2
    /* BB68 8001B368 21104300 */  addu       $v0, $v0, $v1
    /* BB6C 8001B36C 21104600 */  addu       $v0, $v0, $a2
    /* BB70 8001B370 C0364294 */  lhu        $v0, 0x36C0($v0)
    /* BB74 8001B374 0A80013C */  lui        $at, %hi(D_8009B338)
    /* BB78 8001B378 38B322A4 */  sh         $v0, %lo(D_8009B338)($at)
    /* BB7C 8001B37C ABED000C */  jal        func_8003B6AC
    /* BB80 8001B380 0B000524 */   addiu     $a1, $zero, 0xB
    /* BB84 8001B384 21200000 */  addu       $a0, $zero, $zero
    /* BB88 8001B388 21000524 */  addiu      $a1, $zero, 0x21
    /* BB8C 8001B38C 48000624 */  addiu      $a2, $zero, 0x48
    /* BB90 8001B390 6E000724 */  addiu      $a3, $zero, 0x6E
    /* BB94 8001B394 B0000224 */  addiu      $v0, $zero, 0xB0
    /* BB98 8001B398 1000A2AF */  sw         $v0, 0x10($sp)
    /* BB9C 8001B39C 30000224 */  addiu      $v0, $zero, 0x30
    /* BBA0 8001B3A0 1400A2AF */  sw         $v0, 0x14($sp)
    /* BBA4 8001B3A4 20000224 */  addiu      $v0, $zero, 0x20
    /* BBA8 8001B3A8 0ED7000C */  jal        func_80035C38
    /* BBAC 8001B3AC 1800A2AF */   sw        $v0, 0x18($sp)
    /* BBB0 8001B3B0 21804000 */  addu       $s0, $v0, $zero
    /* BBB4 8001B3B4 08000224 */  addiu      $v0, $zero, 0x8
    /* BBB8 8001B3B8 5A0002A2 */  sb         $v0, 0x5A($s0)
    /* BBBC 8001B3BC 10000224 */  addiu      $v0, $zero, 0x10
    /* BBC0 8001B3C0 5B0002A2 */  sb         $v0, 0x5B($s0)
  .L8001B3C4:
    /* BBC4 8001B3C4 E5E5000C */  jal        func_80039794
    /* BBC8 8001B3C8 00000000 */   nop
    /* BBCC 8001B3CC 3000028E */  lw         $v0, 0x30($s0)
    /* BBD0 8001B3D0 00000000 */  nop
    /* BBD4 8001B3D4 FBFF4010 */  beqz       $v0, .L8001B3C4
    /* BBD8 8001B3D8 00000000 */   nop
    /* BBDC 8001B3DC DA6D0008 */  j          .L8001B768
    /* BBE0 8001B3E0 00000000 */   nop
  .L8001B3E4:
    /* BBE4 8001B3E4 1E004010 */  beqz       $v0, .L8001B460
    /* BBE8 8001B3E8 1A80023C */   lui       $v0, %hi(D_801A7AD8)
    /* BBEC 8001B3EC 6A002392 */  lbu        $v1, 0x6A($s1)
    /* BBF0 8001B3F0 D87A4524 */  addiu      $a1, $v0, %lo(D_801A7AD8)
    /* BBF4 8001B3F4 C0100300 */  sll        $v0, $v1, 3
    /* BBF8 8001B3F8 23104300 */  subu       $v0, $v0, $v1
    /* BBFC 8001B3FC 80100200 */  sll        $v0, $v0, 2
    /* BC00 8001B400 21104500 */  addu       $v0, $v0, $a1
    /* BC04 8001B404 16004394 */  lhu        $v1, 0x16($v0)
    /* BC08 8001B408 0A80043C */  lui        $a0, %hi(D_8009B34D)
    /* BC0C 8001B40C 4DB38480 */  lb         $a0, %lo(D_8009B34D)($a0)
    /* BC10 8001B410 FFFD6330 */  andi       $v1, $v1, 0xFDFF
    /* BC14 8001B414 0B008010 */  beqz       $a0, .L8001B444
    /* BC18 8001B418 160043A4 */   sh        $v1, 0x16($v0)
    /* BC1C 8001B41C 6A002292 */  lbu        $v0, 0x6A($s1)
    /* BC20 8001B420 00000000 */  nop
    /* BC24 8001B424 C0180200 */  sll        $v1, $v0, 3
    /* BC28 8001B428 23186200 */  subu       $v1, $v1, $v0
    /* BC2C 8001B42C 80180300 */  sll        $v1, $v1, 2
    /* BC30 8001B430 21186500 */  addu       $v1, $v1, $a1
    /* BC34 8001B434 16006294 */  lhu        $v0, 0x16($v1)
    /* BC38 8001B438 00000000 */  nop
    /* BC3C 8001B43C 00024234 */  ori        $v0, $v0, 0x200
    /* BC40 8001B440 160062A4 */  sh         $v0, 0x16($v1)
  .L8001B444:
    /* BC44 8001B444 0F80043C */  lui        $a0, %hi(D_800EB0F8)
    /* BC48 8001B448 DFD6000C */  jal        func_80035B7C
    /* BC4C 8001B44C F8B08424 */   addiu     $a0, $a0, %lo(D_800EB0F8)
  .L8001B450:
    /* BC50 8001B450 04000224 */  addiu      $v0, $zero, 0x4
  .L8001B454:
    /* BC54 8001B454 6C0282A3 */  sb         $v0, %gp_rel(D_8009B174)($gp)
    /* BC58 8001B458 DA6D0008 */  j          .L8001B768
    /* BC5C 8001B45C 00000000 */   nop
  .L8001B460:
    /* BC60 8001B460 0F80043C */  lui        $a0, %hi(D_800EB0F8)
    /* BC64 8001B464 03DC000C */  jal        func_8003700C
    /* BC68 8001B468 F8B08424 */   addiu     $a0, $a0, %lo(D_800EB0F8)
    /* BC6C 8001B46C BE004014 */  bnez       $v0, .L8001B768
    /* BC70 8001B470 00000000 */   nop
    /* BC74 8001B474 0A80023C */  lui        $v0, %hi(D_8009B398)
    /* BC78 8001B478 98B34294 */  lhu        $v0, %lo(D_8009B398)($v0)
    /* BC7C 8001B47C 00000000 */  nop
    /* BC80 8001B480 C0004230 */  andi       $v0, $v0, 0xC0
    /* BC84 8001B484 B8004010 */  beqz       $v0, .L8001B768
    /* BC88 8001B488 00000000 */   nop
    /* BC8C 8001B48C B8FF000C */  jal        func_8003FEE0
    /* BC90 8001B490 07000424 */   addiu     $a0, $zero, 0x7
    /* BC94 8001B494 6C028293 */  lbu        $v0, %gp_rel(D_8009B174)($gp)
    /* BC98 8001B498 00000000 */  nop
    /* BC9C 8001B49C 10004234 */  ori        $v0, $v0, 0x10
    /* BCA0 8001B4A0 6C0282A3 */  sb         $v0, %gp_rel(D_8009B174)($gp)
    /* BCA4 8001B4A4 DA6D0008 */  j          .L8001B768
    /* BCA8 8001B4A8 00000000 */   nop
  jlabel .L8001B4AC
    /* BCAC 8001B4AC 6C028393 */  lbu        $v1, %gp_rel(D_8009B174)($gp)
    /* BCB0 8001B4B0 00000000 */  nop
    /* BCB4 8001B4B4 80006230 */  andi       $v0, $v1, 0x80
    /* BCB8 8001B4B8 0B004014 */  bnez       $v0, .L8001B4E8
    /* BCBC 8001B4BC 80006234 */   ori       $v0, $v1, 0x80
    /* BCC0 8001B4C0 94028493 */  lbu        $a0, %gp_rel(D_8009B19C)($gp)
    /* BCC4 8001B4C4 6C0282A3 */  sb         $v0, %gp_rel(D_8009B174)($gp)
    /* BCC8 8001B4C8 336C000C */  jal        func_8001B0CC
    /* BCCC 8001B4CC 00000000 */   nop
    /* BCD0 8001B4D0 21202002 */  addu       $a0, $s1, $zero
    /* BCD4 8001B4D4 E2FF4224 */  addiu      $v0, $v0, -0x1E
    /* BCD8 8001B4D8 5E0C010C */  jal        func_80043178
    /* BCDC 8001B4DC 2E0022A6 */   sh        $v0, 0x2E($s1)
    /* BCE0 8001B4E0 00040224 */  addiu      $v0, $zero, 0x400
    /* BCE4 8001B4E4 600022A6 */  sh         $v0, 0x60($s1)
  .L8001B4E8:
    /* BCE8 8001B4E8 6C028293 */  lbu        $v0, %gp_rel(D_8009B174)($gp)
    /* BCEC 8001B4EC 00000000 */  nop
    /* BCF0 8001B4F0 40004230 */  andi       $v0, $v0, 0x40
    /* BCF4 8001B4F4 4A004014 */  bnez       $v0, .L8001B620
    /* BCF8 8001B4F8 21202002 */   addu      $a0, $s1, $zero
    /* BCFC 8001B4FC 2E002586 */  lh         $a1, 0x2E($s1)
    /* BD00 8001B500 60002786 */  lh         $a3, 0x60($s1)
    /* BD04 8001B504 8C0C010C */  jal        func_80043230
    /* BD08 8001B508 44FF0624 */   addiu     $a2, $zero, -0xBC
    /* BD0C 8001B50C 60002296 */  lhu        $v0, 0x60($s1)
    /* BD10 8001B510 00000000 */  nop
    /* BD14 8001B514 D6FF4224 */  addiu      $v0, $v0, -0x2A
    /* BD18 8001B518 600022A6 */  sh         $v0, 0x60($s1)
    /* BD1C 8001B51C 00140200 */  sll        $v0, $v0, 16
    /* BD20 8001B520 9100401C */  bgtz       $v0, .L8001B768
    /* BD24 8001B524 801F123C */   lui       $s2, (0x1F800012 >> 16)
    /* BD28 8001B528 1A80103C */  lui        $s0, %hi(D_801A7AD8)
    /* BD2C 8001B52C 6C028293 */  lbu        $v0, %gp_rel(D_8009B174)($gp)
    /* BD30 8001B530 D87A1026 */  addiu      $s0, $s0, %lo(D_801A7AD8)
    /* BD34 8001B534 40004234 */  ori        $v0, $v0, 0x40
    /* BD38 8001B538 6C0282A3 */  sb         $v0, %gp_rel(D_8009B174)($gp)
    /* BD3C 8001B53C 6A002392 */  lbu        $v1, 0x6A($s1)
    /* BD40 8001B540 94028493 */  lbu        $a0, %gp_rel(D_8009B19C)($gp)
    /* BD44 8001B544 C0100300 */  sll        $v0, $v1, 3
    /* BD48 8001B548 23104300 */  subu       $v0, $v0, $v1
    /* BD4C 8001B54C 80100200 */  sll        $v0, $v0, 2
    /* BD50 8001B550 21105000 */  addu       $v0, $v0, $s0
    /* BD54 8001B554 0000488C */  lw         $t0, 0x0($v0)
    /* BD58 8001B558 0400498C */  lw         $t1, 0x4($v0)
    /* BD5C 8001B55C 08004A8C */  lw         $t2, 0x8($v0)
    /* BD60 8001B560 0C004B8C */  lw         $t3, 0xC($v0)
    /* BD64 8001B564 000048AE */  sw         $t0, (0x1F800000 & 0xFFFF)($s2)
    /* BD68 8001B568 040049AE */  sw         $t1, (0x1F800004 & 0xFFFF)($s2)
    /* BD6C 8001B56C 08004AAE */  sw         $t2, (0x1F800008 & 0xFFFF)($s2)
    /* BD70 8001B570 0C004BAE */  sw         $t3, (0x1F80000C & 0xFFFF)($s2)
    /* BD74 8001B574 1000488C */  lw         $t0, 0x10($v0)
    /* BD78 8001B578 1400498C */  lw         $t1, 0x14($v0)
    /* BD7C 8001B57C 18004A8C */  lw         $t2, 0x18($v0)
    /* BD80 8001B580 100048AE */  sw         $t0, (0x1F800010 & 0xFFFF)($s2)
    /* BD84 8001B584 140049AE */  sw         $t1, (0x1F800014 & 0xFFFF)($s2)
    /* BD88 8001B588 18004AAE */  sw         $t2, (0x1F800018 & 0xFFFF)($s2)
    /* BD8C 8001B58C 6B002592 */  lbu        $a1, 0x6B($s1)
    /* BD90 8001B590 4D93000C */  jal        func_80024D34
    /* BD94 8001B594 00000000 */   nop
    /* BD98 8001B598 94028393 */  lbu        $v1, %gp_rel(D_8009B19C)($gp)
    /* BD9C 8001B59C 00000000 */  nop
    /* BDA0 8001B5A0 C0100300 */  sll        $v0, $v1, 3
    /* BDA4 8001B5A4 23104300 */  subu       $v0, $v0, $v1
    /* BDA8 8001B5A8 80100200 */  sll        $v0, $v0, 2
    /* BDAC 8001B5AC 21805000 */  addu       $s0, $v0, $s0
    /* BDB0 8001B5B0 16004296 */  lhu        $v0, (0x1F800016 & 0xFFFF)($s2)
    /* BDB4 8001B5B4 16000396 */  lhu        $v1, 0x16($s0)
    /* BDB8 8001B5B8 007E4230 */  andi       $v0, $v0, 0x7E00
    /* BDBC 8001B5BC 25186200 */  or         $v1, $v1, $v0
    /* BDC0 8001B5C0 FFFB6230 */  andi       $v0, $v1, 0xFBFF
    /* BDC4 8001B5C4 160002A6 */  sh         $v0, 0x16($s0)
    /* BDC8 8001B5C8 00106230 */  andi       $v0, $v1, 0x1000
    /* BDCC 8001B5CC 02004014 */  bnez       $v0, .L8001B5D8
    /* BDD0 8001B5D0 FFDB6230 */   andi      $v0, $v1, 0xDBFF
    /* BDD4 8001B5D4 160002A6 */  sh         $v0, 0x16($s0)
  .L8001B5D8:
    /* BDD8 8001B5D8 12004296 */  lhu        $v0, (0x1F800012 & 0xFFFF)($s2)
    /* BDDC 8001B5DC 21202002 */  addu       $a0, $s1, $zero
    /* BDE0 8001B5E0 DB00010C */  jal        func_8004036C
    /* BDE4 8001B5E4 120002A6 */   sh        $v0, 0x12($s0)
    /* BDE8 8001B5E8 0000028E */  lw         $v0, 0x0($s0)
    /* BDEC 8001B5EC 00000000 */  nop
    /* BDF0 8001B5F0 21884000 */  addu       $s1, $v0, $zero
    /* BDF4 8001B5F4 21202002 */  addu       $a0, $s1, $zero
    /* BDF8 8001B5F8 0F80023C */  lui        $v0, %hi(D_800E9EF0)
    /* BDFC 8001B5FC 2060000C */  jal        func_80018080
    /* BE00 8001B600 F09E51AC */   sw        $s1, %lo(D_800E9EF0)($v0)
    /* BE04 8001B604 21202002 */  addu       $a0, $s1, $zero
    /* BE08 8001B608 10FF0224 */  addiu      $v0, $zero, -0xF0
    /* BE0C 8001B60C 5E0C010C */  jal        func_80043178
    /* BE10 8001B610 320022A6 */   sh        $v0, 0x32($s1)
    /* BE14 8001B614 00FC0224 */  addiu      $v0, $zero, -0x400
    /* BE18 8001B618 DA6D0008 */  j          .L8001B768
    /* BE1C 8001B61C 600022A6 */   sh        $v0, 0x60($s1)
  .L8001B620:
    /* BE20 8001B620 30002586 */  lh         $a1, 0x30($s1)
    /* BE24 8001B624 60002786 */  lh         $a3, 0x60($s1)
    /* BE28 8001B628 8C0C010C */  jal        func_80043230
    /* BE2C 8001B62C E8FF0624 */   addiu     $a2, $zero, -0x18
    /* BE30 8001B630 60002296 */  lhu        $v0, 0x60($s1)
    /* BE34 8001B634 00000000 */  nop
    /* BE38 8001B638 2A004224 */  addiu      $v0, $v0, 0x2A
    /* BE3C 8001B63C 600022A6 */  sh         $v0, 0x60($s1)
    /* BE40 8001B640 00140200 */  sll        $v0, $v0, 16
    /* BE44 8001B644 48004004 */  bltz       $v0, .L8001B768
    /* BE48 8001B648 E8FF0224 */   addiu     $v0, $zero, -0x18
    /* BE4C 8001B64C 320022A6 */  sh         $v0, 0x32($s1)
    /* BE50 8001B650 05000224 */  addiu      $v0, $zero, 0x5
    /* BE54 8001B654 6C0282A3 */  sb         $v0, %gp_rel(D_8009B174)($gp)
    /* BE58 8001B658 B8FF000C */  jal        func_8003FEE0
    /* BE5C 8001B65C 0C000424 */   addiu     $a0, $zero, 0xC
    /* BE60 8001B660 DA6D0008 */  j          .L8001B768
    /* BE64 8001B664 00000000 */   nop
  jlabel .L8001B668
    /* BE68 8001B668 4C028287 */  lh         $v0, %gp_rel(D_8009B154)($gp)
    /* BE6C 8001B66C 00000000 */  nop
    /* BE70 8001B670 09004010 */  beqz       $v0, .L8001B698
    /* BE74 8001B674 05000224 */   addiu     $v0, $zero, 0x5
    /* BE78 8001B678 0A94000C */  jal        func_80025028
    /* BE7C 8001B67C B1020424 */   addiu     $a0, $zero, 0x2B1
    /* BE80 8001B680 04004010 */  beqz       $v0, .L8001B694
    /* BE84 8001B684 06000224 */   addiu     $v0, $zero, 0x6
    /* BE88 8001B688 6C0282A3 */  sb         $v0, %gp_rel(D_8009B174)($gp)
    /* BE8C 8001B68C DA6D0008 */  j          .L8001B768
    /* BE90 8001B690 00000000 */   nop
  .L8001B694:
    /* BE94 8001B694 05000224 */  addiu      $v0, $zero, 0x5
  .L8001B698:
    /* BE98 8001B698 320382A7 */  sh         $v0, %gp_rel(D_8009B23A)($gp)
    /* BE9C 8001B69C DA6D0008 */  j          .L8001B768
    /* BEA0 8001B6A0 00000000 */   nop
  jlabel .L8001B6A4
    /* BEA4 8001B6A4 6C028393 */  lbu        $v1, %gp_rel(D_8009B174)($gp)
    /* BEA8 8001B6A8 00000000 */  nop
    /* BEAC 8001B6AC 80006230 */  andi       $v0, $v1, 0x80
    /* BEB0 8001B6B0 03004014 */  bnez       $v0, .L8001B6C0
    /* BEB4 8001B6B4 C0006234 */   ori       $v0, $v1, 0xC0
    /* BEB8 8001B6B8 6C0282A3 */  sb         $v0, %gp_rel(D_8009B174)($gp)
    /* BEBC 8001B6BC 080380A7 */  sh         $zero, %gp_rel(D_8009B210)($gp)
  .L8001B6C0:
    /* BEC0 8001B6C0 6C028293 */  lbu        $v0, %gp_rel(D_8009B174)($gp)
    /* BEC4 8001B6C4 00000000 */  nop
    /* BEC8 8001B6C8 40004230 */  andi       $v0, $v0, 0x40
    /* BECC 8001B6CC 19004010 */  beqz       $v0, .L8001B734
    /* BED0 8001B6D0 05000224 */   addiu     $v0, $zero, 0x5
    /* BED4 8001B6D4 D97C000C */  jal        func_8001F364
    /* BED8 8001B6D8 00000000 */   nop
    /* BEDC 8001B6DC 22004014 */  bnez       $v0, .L8001B768
    /* BEE0 8001B6E0 00000000 */   nop
    /* BEE4 8001B6E4 A3B1000C */  jal        func_8002C68C
    /* BEE8 8001B6E8 0D000424 */   addiu     $a0, $zero, 0xD
    /* BEEC 8001B6EC 30002396 */  lhu        $v1, 0x30($s1)
    /* BEF0 8001B6F0 00000000 */  nop
    /* BEF4 8001B6F4 000043A4 */  sh         $v1, 0x0($v0)
    /* BEF8 8001B6F8 32002396 */  lhu        $v1, 0x32($s1)
    /* BEFC 8001B6FC 21000424 */  addiu      $a0, $zero, 0x21
    /* BF00 8001B700 020043A4 */  sh         $v1, 0x2($v0)
    /* BF04 8001B704 4C028397 */  lhu        $v1, %gp_rel(D_8009B154)($gp)
    /* BF08 8001B708 34002596 */  lhu        $a1, 0x34($s1)
    /* BF0C 8001B70C 23180300 */  negu       $v1, $v1
    /* BF10 8001B710 120043A4 */  sh         $v1, 0x12($v0)
    /* BF14 8001B714 B8FF000C */  jal        func_8003FEE0
    /* BF18 8001B718 040045A4 */   sh        $a1, 0x4($v0)
    /* BF1C 8001B71C 6C028293 */  lbu        $v0, %gp_rel(D_8009B174)($gp)
    /* BF20 8001B720 00000000 */  nop
    /* BF24 8001B724 BF004230 */  andi       $v0, $v0, 0xBF
    /* BF28 8001B728 6C0282A3 */  sb         $v0, %gp_rel(D_8009B174)($gp)
    /* BF2C 8001B72C DA6D0008 */  j          .L8001B768
    /* BF30 8001B730 00000000 */   nop
  .L8001B734:
    /* BF34 8001B734 6A002492 */  lbu        $a0, 0x6A($s1)
    /* BF38 8001B738 320382A7 */  sh         $v0, %gp_rel(D_8009B23A)($gp)
    /* BF3C 8001B73C 1A80023C */  lui        $v0, %hi(D_801A7AD8)
    /* BF40 8001B740 D87A4224 */  addiu      $v0, $v0, %lo(D_801A7AD8)
    /* BF44 8001B744 C0180400 */  sll        $v1, $a0, 3
    /* BF48 8001B748 23186400 */  subu       $v1, $v1, $a0
    /* BF4C 8001B74C 80180300 */  sll        $v1, $v1, 2
    /* BF50 8001B750 21806200 */  addu       $s0, $v1, $v0
    /* BF54 8001B754 4C028287 */  lh         $v0, %gp_rel(D_8009B154)($gp)
    /* BF58 8001B758 12000396 */  lhu        $v1, 0x12($s0)
    /* BF5C 8001B75C 40100200 */  sll        $v0, $v0, 1
    /* BF60 8001B760 23186200 */  subu       $v1, $v1, $v0
    /* BF64 8001B764 120003A6 */  sh         $v1, 0x12($s0)
  .L8001B768:
    /* BF68 8001B768 2C00BF8F */  lw         $ra, 0x2C($sp)
    /* BF6C 8001B76C 2800B28F */  lw         $s2, 0x28($sp)
    /* BF70 8001B770 2400B18F */  lw         $s1, 0x24($sp)
    /* BF74 8001B774 2000B08F */  lw         $s0, 0x20($sp)
    /* BF78 8001B778 0800E003 */  jr         $ra
    /* BF7C 8001B77C 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel func_8001B170
