nonmatching func_80041340, 0xDC

glabel func_80041340
    /* 31B40 80041340 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 31B44 80041344 60000424 */  addiu      $a0, $zero, 0x60
    /* 31B48 80041348 21288000 */  addu       $a1, $a0, $zero
    /* 31B4C 8004134C 21308000 */  addu       $a2, $a0, $zero
    /* 31B50 80041350 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 31B54 80041354 1800B2AF */  sw         $s2, 0x18($sp)
    /* 31B58 80041358 1400B1AF */  sw         $s1, 0x14($sp)
    /* 31B5C 8004135C 1C1E020C */  jal        func_80087870
    /* 31B60 80041360 1000B0AF */   sw        $s0, 0x10($sp)
    /* 31B64 80041364 21200000 */  addu       $a0, $zero, $zero
    /* 31B68 80041368 21288000 */  addu       $a1, $a0, $zero
    /* 31B6C 8004136C 241E020C */  jal        func_80087890
    /* 31B70 80041370 21308000 */   addu      $a2, $a0, $zero
    /* 31B74 80041374 21200000 */  addu       $a0, $zero, $zero
    /* 31B78 80041378 0980053C */  lui        $a1, %hi(D_80090FCC)
    /* 31B7C 8004137C F815020C */  jal        func_800857E0
    /* 31B80 80041380 CC0FA524 */   addiu     $a1, $a1, %lo(D_80090FCC)
    /* 31B84 80041384 01000424 */  addiu      $a0, $zero, 0x1
    /* 31B88 80041388 0980103C */  lui        $s0, %hi(D_80090FDC)
    /* 31B8C 8004138C DC0F1026 */  addiu      $s0, $s0, %lo(D_80090FDC)
    /* 31B90 80041390 F815020C */  jal        func_800857E0
    /* 31B94 80041394 21280002 */   addu      $a1, $s0, $zero
    /* 31B98 80041398 02000424 */  addiu      $a0, $zero, 0x2
    /* 31B9C 8004139C F815020C */  jal        func_800857E0
    /* 31BA0 800413A0 21280002 */   addu      $a1, $s0, $zero
    /* 31BA4 800413A4 06001224 */  addiu      $s2, $zero, 0x6
    /* 31BA8 800413A8 0980023C */  lui        $v0, %hi(D_80090FB0)
    /* 31BAC 800413AC B00F4224 */  addiu      $v0, $v0, %lo(D_80090FB0)
    /* 31BB0 800413B0 18005124 */  addiu      $s1, $v0, 0x18
    /* 31BB4 800413B4 0F80023C */  lui        $v0, %hi(D_800EFE38)
    /* 31BB8 800413B8 38FE4224 */  addiu      $v0, $v0, %lo(D_800EFE38)
    /* 31BBC 800413BC 0C005024 */  addiu      $s0, $v0, 0xC
  .L800413C0:
    /* 31BC0 800413C0 00000286 */  lh         $v0, 0x0($s0)
    /* 31BC4 800413C4 00000000 */  nop
    /* 31BC8 800413C8 0A004004 */  bltz       $v0, .L800413F4
    /* 31BCC 800413CC 00000000 */   nop
    /* 31BD0 800413D0 341E020C */  jal        func_800878D0
    /* 31BD4 800413D4 96000424 */   addiu     $a0, $zero, 0x96
    /* 31BD8 800413D8 21200000 */  addu       $a0, $zero, $zero
    /* 31BDC 800413DC 2C1E020C */  jal        func_800878B0
    /* 31BE0 800413E0 21288000 */   addu      $a1, $a0, $zero
    /* 31BE4 800413E4 0000228E */  lw         $v0, 0x0($s1)
    /* 31BE8 800413E8 00000000 */  nop
    /* 31BEC 800413EC 09F84000 */  jalr       $v0
    /* 31BF0 800413F0 00000000 */   nop
  .L800413F4:
    /* 31BF4 800413F4 FCFF3126 */  addiu      $s1, $s1, -0x4
    /* 31BF8 800413F8 FFFF5226 */  addiu      $s2, $s2, -0x1
    /* 31BFC 800413FC F0FF4106 */  bgez       $s2, .L800413C0
    /* 31C00 80041400 FEFF1026 */   addiu     $s0, $s0, -0x2
    /* 31C04 80041404 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 31C08 80041408 1800B28F */  lw         $s2, 0x18($sp)
    /* 31C0C 8004140C 1400B18F */  lw         $s1, 0x14($sp)
    /* 31C10 80041410 1000B08F */  lw         $s0, 0x10($sp)
    /* 31C14 80041414 0800E003 */  jr         $ra
    /* 31C18 80041418 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_80041340
