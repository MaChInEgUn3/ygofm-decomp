nonmatching func_8003F2B0, 0xD8

glabel func_8003F2B0
    /* 2FAB0 8003F2B0 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 2FAB4 8003F2B4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 2FAB8 8003F2B8 21808000 */  addu       $s0, $a0, $zero
    /* 2FABC 8003F2BC 1800B2AF */  sw         $s2, 0x18($sp)
    /* 2FAC0 8003F2C0 2190A000 */  addu       $s2, $a1, $zero
    /* 2FAC4 8003F2C4 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 2FAC8 8003F2C8 2198C000 */  addu       $s3, $a2, $zero
    /* 2FACC 8003F2CC 1400B1AF */  sw         $s1, 0x14($sp)
    /* 2FAD0 8003F2D0 2000BFAF */  sw         $ra, 0x20($sp)
    /* 2FAD4 8003F2D4 E60A010C */  jal        func_80042B98
    /* 2FAD8 8003F2D8 2188E000 */   addu      $s1, $a3, $zero
    /* 2FADC 8003F2DC 03004014 */  bnez       $v0, .L8003F2EC
    /* 2FAE0 8003F2E0 00000000 */   nop
    /* 2FAE4 8003F2E4 5E0C010C */  jal        func_80043178
    /* 2FAE8 8003F2E8 21200002 */   addu      $a0, $s0, $zero
  .L8003F2EC:
    /* 2FAEC 8003F2EC 60000786 */  lh         $a3, 0x60($s0)
    /* 2FAF0 8003F2F0 00000000 */  nop
    /* 2FAF4 8003F2F4 0600E104 */  bgez       $a3, .L8003F310
    /* 2FAF8 8003F2F8 00000000 */   nop
    /* 2FAFC 8003F2FC 4000E724 */  addiu      $a3, $a3, 0x40
    /* 2FB00 8003F300 0800E004 */  bltz       $a3, .L8003F324
    /* 2FB04 8003F304 00000000 */   nop
    /* 2FB08 8003F308 C8FC0008 */  j          .L8003F320
    /* 2FB0C 8003F30C 6C0000A2 */   sb        $zero, 0x6C($s0)
  .L8003F310:
    /* 2FB10 8003F310 C0FFE724 */  addiu      $a3, $a3, -0x40
    /* 2FB14 8003F314 0300E01C */  bgtz       $a3, .L8003F324
    /* 2FB18 8003F318 00000000 */   nop
    /* 2FB1C 8003F31C 6C0000A2 */  sb         $zero, 0x6C($s0)
  .L8003F320:
    /* 2FB20 8003F320 21380000 */  addu       $a3, $zero, $zero
  .L8003F324:
    /* 2FB24 8003F324 600007A6 */  sh         $a3, 0x60($s0)
    /* 2FB28 8003F328 21200002 */  addu       $a0, $s0, $zero
    /* 2FB2C 8003F32C 21284002 */  addu       $a1, $s2, $zero
    /* 2FB30 8003F330 8C0C010C */  jal        func_80043230
    /* 2FB34 8003F334 21306002 */   addu      $a2, $s3, $zero
    /* 2FB38 8003F338 0B002006 */  bltz       $s1, .L8003F368
    /* 2FB3C 8003F33C 0F80023C */   lui       $v0, %hi(D_800EB0F8)
    /* 2FB40 8003F340 40201100 */  sll        $a0, $s1, 1
    /* 2FB44 8003F344 21209100 */  addu       $a0, $a0, $s1
    /* 2FB48 8003F348 C0200400 */  sll        $a0, $a0, 3
    /* 2FB4C 8003F34C 21209100 */  addu       $a0, $a0, $s1
    /* 2FB50 8003F350 80200400 */  sll        $a0, $a0, 2
    /* 2FB54 8003F354 F8B04224 */  addiu      $v0, $v0, %lo(D_800EB0F8)
    /* 2FB58 8003F358 30000586 */  lh         $a1, 0x30($s0)
    /* 2FB5C 8003F35C 32000686 */  lh         $a2, 0x32($s0)
    /* 2FB60 8003F360 4DE6000C */  jal        func_80039934
    /* 2FB64 8003F364 21208200 */   addu      $a0, $a0, $v0
  .L8003F368:
    /* 2FB68 8003F368 6C000292 */  lbu        $v0, 0x6C($s0)
    /* 2FB6C 8003F36C 2000BF8F */  lw         $ra, 0x20($sp)
    /* 2FB70 8003F370 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 2FB74 8003F374 1800B28F */  lw         $s2, 0x18($sp)
    /* 2FB78 8003F378 1400B18F */  lw         $s1, 0x14($sp)
    /* 2FB7C 8003F37C 1000B08F */  lw         $s0, 0x10($sp)
    /* 2FB80 8003F380 0800E003 */  jr         $ra
    /* 2FB84 8003F384 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_8003F2B0
