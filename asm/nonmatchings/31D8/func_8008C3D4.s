nonmatching func_8008C3D4, 0xB8

glabel func_8008C3D4
    /* 7CBD4 8008C3D4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 7CBD8 8008C3D8 1080073C */  lui        $a3, %hi(D_800FE35C)
    /* 7CBDC 8008C3DC 5CE3E724 */  addiu      $a3, $a3, %lo(D_800FE35C)
    /* 7CBE0 8008C3E0 1000BFAF */  sw         $ra, 0x10($sp)
    /* 7CBE4 8008C3E4 0000E28C */  lw         $v0, 0x0($a3)
    /* 7CBE8 8008C3E8 00000000 */  nop
    /* 7CBEC 8008C3EC 04004104 */  bgez       $v0, .L8008C400
    /* 7CBF0 8008C3F0 21408000 */   addu      $t0, $a0, $zero
    /* 7CBF4 8008C3F4 0180043C */  lui        $a0, %hi(D_8001259C)
    /* 7CBF8 8008C3F8 1C310208 */  j          .L8008C470
    /* 7CBFC 8008C3FC 9C258424 */   addiu     $a0, $a0, %lo(D_8001259C)
  .L8008C400:
    /* 7CC00 8008C400 ECFFE28C */  lw         $v0, -0x14($a3)
    /* 7CC04 8008C404 00000000 */  nop
    /* 7CC08 8008C408 04004018 */  blez       $v0, .L8008C41C
    /* 7CC0C 8008C40C ECFFE324 */   addiu     $v1, $a3, -0x14
    /* 7CC10 8008C410 0180043C */  lui        $a0, %hi(D_80012478)
    /* 7CC14 8008C414 1C310208 */  j          .L8008C470
    /* 7CC18 8008C418 78248424 */   addiu     $a0, $a0, %lo(D_80012478)
  .L8008C41C:
    /* 7CC1C 8008C41C 7F00C230 */  andi       $v0, $a2, 0x7F
    /* 7CC20 8008C420 04004010 */  beqz       $v0, .L8008C434
    /* 7CC24 8008C424 7F00A230 */   andi      $v0, $a1, 0x7F
    /* 7CC28 8008C428 0180043C */  lui        $a0, %hi(D_800125C0)
    /* 7CC2C 8008C42C 1C310208 */  j          .L8008C470
    /* 7CC30 8008C430 C0258424 */   addiu     $a0, $a0, %lo(D_800125C0)
  .L8008C434:
    /* 7CC34 8008C434 0C004014 */  bnez       $v0, .L8008C468
    /* 7CC38 8008C438 06000224 */   addiu     $v0, $zero, 0x6
    /* 7CC3C 8008C43C 0980043C */  lui        $a0, %hi(func_8008C48C)
    /* 7CC40 8008C440 8CC48424 */  addiu      $a0, $a0, %lo(func_8008C48C)
    /* 7CC44 8008C444 ECFFE2AC */  sw         $v0, -0x14($a3)
    /* 7CC48 8008C448 040060AC */  sw         $zero, 0x4($v1)
    /* 7CC4C 8008C44C 080060AC */  sw         $zero, 0x8($v1)
    /* 7CC50 8008C450 180065AC */  sw         $a1, 0x18($v1)
    /* 7CC54 8008C454 200068AC */  sw         $t0, 0x20($v1)
    /* 7CC58 8008C458 3834020C */  jal        func_8008D0E0
    /* 7CC5C 8008C45C 1C0066AC */   sw        $a2, 0x1C($v1)
    /* 7CC60 8008C460 1F310208 */  j          .L8008C47C
    /* 7CC64 8008C464 01000224 */   addiu     $v0, $zero, 0x1
  .L8008C468:
    /* 7CC68 8008C468 0180043C */  lui        $a0, %hi(D_800125EC)
    /* 7CC6C 8008C46C EC258424 */  addiu      $a0, $a0, %lo(D_800125EC)
  .L8008C470:
    /* 7CC70 8008C470 1C3A020C */  jal        func_8008E870
    /* 7CC74 8008C474 00000000 */   nop
    /* 7CC78 8008C478 21100000 */  addu       $v0, $zero, $zero
  .L8008C47C:
    /* 7CC7C 8008C47C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 7CC80 8008C480 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 7CC84 8008C484 0800E003 */  jr         $ra
    /* 7CC88 8008C488 00000000 */   nop
endlabel func_8008C3D4
