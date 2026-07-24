nonmatching func_8002CBF4, 0xB4

glabel func_8002CBF4
    /* 1D3F4 8002CBF4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1D3F8 8002CBF8 1400BFAF */  sw         $ra, 0x14($sp)
    /* 1D3FC 8002CBFC 0900A010 */  beqz       $a1, .L8002CC24
    /* 1D400 8002CC00 1000B0AF */   sw        $s0, 0x10($sp)
    /* 1D404 8002CC04 1D80033C */  lui        $v1, %hi(D_801D4244)
    /* 1D408 8002CC08 44426324 */  addiu      $v1, $v1, %lo(D_801D4244)
    /* 1D40C 8002CC0C FFFF8224 */  addiu      $v0, $a0, -0x1
    /* 1D410 8002CC10 80100200 */  sll        $v0, $v0, 2
    /* 1D414 8002CC14 21104300 */  addu       $v0, $v0, $v1
    /* 1D418 8002CC18 0000438C */  lw         $v1, 0x0($v0)
    /* 1D41C 8002CC1C 0FB30008 */  j          .L8002CC3C
    /* 1D420 8002CC20 431A0300 */   sra       $v1, $v1, 9
  .L8002CC24:
    /* 1D424 8002CC24 1D80033C */  lui        $v1, %hi(D_801D4244)
    /* 1D428 8002CC28 44426324 */  addiu      $v1, $v1, %lo(D_801D4244)
    /* 1D42C 8002CC2C FFFF8224 */  addiu      $v0, $a0, -0x1
    /* 1D430 8002CC30 80100200 */  sll        $v0, $v0, 2
    /* 1D434 8002CC34 21104300 */  addu       $v0, $v0, $v1
    /* 1D438 8002CC38 0000438C */  lw         $v1, 0x0($v0)
  .L8002CC3C:
    /* 1D43C 8002CC3C 00000000 */  nop
    /* 1D440 8002CC40 FF016330 */  andi       $v1, $v1, 0x1FF
    /* 1D444 8002CC44 80100300 */  sll        $v0, $v1, 2
    /* 1D448 8002CC48 21104300 */  addu       $v0, $v0, $v1
    /* 1D44C 8002CC4C 40800200 */  sll        $s0, $v0, 1
    /* 1D450 8002CC50 1D80023C */  lui        $v0, %hi(D_801D4244)
    /* 1D454 8002CC54 44424224 */  addiu      $v0, $v0, %lo(D_801D4244)
    /* 1D458 8002CC58 FFFF8324 */  addiu      $v1, $a0, -0x1
    /* 1D45C 8002CC5C 80180300 */  sll        $v1, $v1, 2
    /* 1D460 8002CC60 21186200 */  addu       $v1, $v1, $v0
    /* 1D464 8002CC64 0000648C */  lw         $a0, 0x0($v1)
    /* 1D468 8002CC68 00000000 */  nop
    /* 1D46C 8002CC6C 83260400 */  sra        $a0, $a0, 26
    /* 1D470 8002CC70 5F92000C */  jal        func_8002497C
    /* 1D474 8002CC74 1F008430 */   andi      $a0, $a0, 0x1F
    /* 1D478 8002CC78 21800202 */  addu       $s0, $s0, $v0
    /* 1D47C 8002CC7C 06000006 */  bltz       $s0, .L8002CC98
    /* 1D480 8002CC80 21100000 */   addu      $v0, $zero, $zero
    /* 1D484 8002CC84 1027022A */  slti       $v0, $s0, 0x2710
    /* 1D488 8002CC88 03004014 */  bnez       $v0, .L8002CC98
    /* 1D48C 8002CC8C 21100002 */   addu      $v0, $s0, $zero
    /* 1D490 8002CC90 0F271024 */  addiu      $s0, $zero, 0x270F
    /* 1D494 8002CC94 21100002 */  addu       $v0, $s0, $zero
  .L8002CC98:
    /* 1D498 8002CC98 1400BF8F */  lw         $ra, 0x14($sp)
    /* 1D49C 8002CC9C 1000B08F */  lw         $s0, 0x10($sp)
    /* 1D4A0 8002CCA0 0800E003 */  jr         $ra
    /* 1D4A4 8002CCA4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8002CBF4
