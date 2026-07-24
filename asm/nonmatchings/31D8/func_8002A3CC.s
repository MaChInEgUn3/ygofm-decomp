nonmatching func_8002A3CC, 0xDC

glabel func_8002A3CC
    /* 1ABCC 8002A3CC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1ABD0 8002A3D0 0F80023C */  lui        $v0, %hi(D_800EA1E8)
    /* 1ABD4 8002A3D4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1ABD8 8002A3D8 E8A15024 */  addiu      $s0, $v0, %lo(D_800EA1E8)
    /* 1ABDC 8002A3DC 1400BFAF */  sw         $ra, 0x14($sp)
    /* 1ABE0 8002A3E0 17000292 */  lbu        $v0, 0x17($s0)
    /* 1ABE4 8002A3E4 00000000 */  nop
    /* 1ABE8 8002A3E8 2B004010 */  beqz       $v0, .L8002A498
    /* 1ABEC 8002A3EC 00000000 */   nop
    /* 1ABF0 8002A3F0 08000286 */  lh         $v0, 0x8($s0)
    /* 1ABF4 8002A3F4 0C000396 */  lhu        $v1, 0xC($s0)
    /* 1ABF8 8002A3F8 1800048E */  lw         $a0, 0x18($s0)
    /* 1ABFC 8002A3FC 00140200 */  sll        $v0, $v0, 16
    /* 1AC00 8002A400 25304300 */  or         $a2, $v0, $v1
    /* 1AC04 8002A404 2130C400 */  addu       $a2, $a2, $a0
    /* 1AC08 8002A408 0A000286 */  lh         $v0, 0xA($s0)
    /* 1AC0C 8002A40C 0E000396 */  lhu        $v1, 0xE($s0)
    /* 1AC10 8002A410 1C00048E */  lw         $a0, 0x1C($s0)
    /* 1AC14 8002A414 032C0600 */  sra        $a1, $a2, 16
    /* 1AC18 8002A418 0C0006A6 */  sh         $a2, 0xC($s0)
    /* 1AC1C 8002A41C 080005A6 */  sh         $a1, 0x8($s0)
    /* 1AC20 8002A420 00140200 */  sll        $v0, $v0, 16
    /* 1AC24 8002A424 25304300 */  or         $a2, $v0, $v1
    /* 1AC28 8002A428 2130C400 */  addu       $a2, $a2, $a0
    /* 1AC2C 8002A42C 16000292 */  lbu        $v0, 0x16($s0)
    /* 1AC30 8002A430 031C0600 */  sra        $v1, $a2, 16
    /* 1AC34 8002A434 0A0003A6 */  sh         $v1, 0xA($s0)
    /* 1AC38 8002A438 0E0006A6 */  sh         $a2, 0xE($s0)
    /* 1AC3C 8002A43C FFFF4224 */  addiu      $v0, $v0, -0x1
    /* 1AC40 8002A440 160002A2 */  sb         $v0, 0x16($s0)
    /* 1AC44 8002A444 FF004230 */  andi       $v0, $v0, 0xFF
    /* 1AC48 8002A448 0A004014 */  bnez       $v0, .L8002A474
    /* 1AC4C 8002A44C 00000000 */   nop
    /* 1AC50 8002A450 12000296 */  lhu        $v0, 0x12($s0)
    /* 1AC54 8002A454 14000396 */  lhu        $v1, 0x14($s0)
    /* 1AC58 8002A458 35000424 */  addiu      $a0, $zero, 0x35
    /* 1AC5C 8002A45C 170000A2 */  sb         $zero, 0x17($s0)
    /* 1AC60 8002A460 080002A6 */  sh         $v0, 0x8($s0)
    /* 1AC64 8002A464 B8FF000C */  jal        func_8003FEE0
    /* 1AC68 8002A468 0A0003A6 */   sh        $v1, 0xA($s0)
    /* 1AC6C 8002A46C BDA8000C */  jal        func_8002A2F4
    /* 1AC70 8002A470 21200002 */   addu      $a0, $s0, $zero
  .L8002A474:
    /* 1AC74 8002A474 4400038E */  lw         $v1, 0x44($s0)
    /* 1AC78 8002A478 08000296 */  lhu        $v0, 0x8($s0)
    /* 1AC7C 8002A47C 00000000 */  nop
    /* 1AC80 8002A480 300062A4 */  sh         $v0, 0x30($v1)
    /* 1AC84 8002A484 4400038E */  lw         $v1, 0x44($s0)
    /* 1AC88 8002A488 0A000296 */  lhu        $v0, 0xA($s0)
    /* 1AC8C 8002A48C 00000000 */  nop
    /* 1AC90 8002A490 320062A4 */  sh         $v0, 0x32($v1)
    /* 1AC94 8002A494 17000292 */  lbu        $v0, 0x17($s0)
  .L8002A498:
    /* 1AC98 8002A498 1400BF8F */  lw         $ra, 0x14($sp)
    /* 1AC9C 8002A49C 1000B08F */  lw         $s0, 0x10($sp)
    /* 1ACA0 8002A4A0 0800E003 */  jr         $ra
    /* 1ACA4 8002A4A4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8002A3CC
