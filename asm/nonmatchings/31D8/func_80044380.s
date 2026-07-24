nonmatching func_80044380, 0x6C

glabel func_80044380
    /* 34B80 80044380 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 34B84 80044384 1000B0AF */  sw         $s0, 0x10($sp)
    /* 34B88 80044388 21808000 */  addu       $s0, $a0, $zero
    /* 34B8C 8004438C 1800B2AF */  sw         $s2, 0x18($sp)
    /* 34B90 80044390 2190A000 */  addu       $s2, $a1, $zero
    /* 34B94 80044394 1400B1AF */  sw         $s1, 0x14($sp)
    /* 34B98 80044398 2188C000 */  addu       $s1, $a2, $zero
    /* 34B9C 8004439C 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 34BA0 800443A0 2D10010C */  jal        func_800440B4
    /* 34BA4 800443A4 0C000524 */   addiu     $a1, $zero, 0xC
    /* 34BA8 800443A8 09004010 */  beqz       $v0, .L800443D0
    /* 34BAC 800443AC 0F80043C */   lui       $a0, %hi(D_800F2AE0)
    /* 34BB0 800443B0 440591A7 */  sh         $s1, %gp_rel(D_8009B44C)($gp)
    /* 34BB4 800443B4 280592AF */  sw         $s2, %gp_rel(D_8009B430)($gp)
    /* 34BB8 800443B8 520F010C */  jal        func_80043D48
    /* 34BBC 800443BC E02A8424 */   addiu     $a0, $a0, %lo(D_800F2AE0)
    /* 34BC0 800443C0 CC2C020C */  jal        func_8008B330
    /* 34BC4 800443C4 21200002 */   addu      $a0, $s0, $zero
    /* 34BC8 800443C8 F5100108 */  j          .L800443D4
    /* 34BCC 800443CC 01000224 */   addiu     $v0, $zero, 0x1
  .L800443D0:
    /* 34BD0 800443D0 21100000 */  addu       $v0, $zero, $zero
  .L800443D4:
    /* 34BD4 800443D4 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 34BD8 800443D8 1800B28F */  lw         $s2, 0x18($sp)
    /* 34BDC 800443DC 1400B18F */  lw         $s1, 0x14($sp)
    /* 34BE0 800443E0 1000B08F */  lw         $s0, 0x10($sp)
    /* 34BE4 800443E4 0800E003 */  jr         $ra
    /* 34BE8 800443E8 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_80044380
