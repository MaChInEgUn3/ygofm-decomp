nonmatching func_80073D8C, 0x90

glabel func_80073D8C
    /* 6458C 80073D8C D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 64590 80073D90 1000B0AF */  sw         $s0, 0x10($sp)
    /* 64594 80073D94 21808000 */  addu       $s0, $a0, $zero
    /* 64598 80073D98 1400B1AF */  sw         $s1, 0x14($sp)
    /* 6459C 80073D9C 2188A000 */  addu       $s1, $a1, $zero
    /* 645A0 80073DA0 1800B2AF */  sw         $s2, 0x18($sp)
    /* 645A4 80073DA4 2190C000 */  addu       $s2, $a2, $zero
    /* 645A8 80073DA8 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 645AC 80073DAC 2000BFAF */  sw         $ra, 0x20($sp)
    /* 645B0 80073DB0 40D0010C */  jal        func_80074100
    /* 645B4 80073DB4 2198E000 */   addu      $s3, $a3, $zero
    /* 645B8 80073DB8 2CCE010C */  jal        func_800738B0
    /* 645BC 80073DBC 00000000 */   nop
    /* 645C0 80073DC0 1ED0010C */  jal        func_80074078
    /* 645C4 80073DC4 00000000 */   nop
    /* 645C8 80073DC8 30CE010C */  jal        func_800738C0
    /* 645CC 80073DCC 00000000 */   nop
    /* 645D0 80073DD0 50CE010C */  jal        func_80073940
    /* 645D4 80073DD4 21200000 */   addu      $a0, $zero, $zero
    /* 645D8 80073DD8 B7CF010C */  jal        func_80073EDC
    /* 645DC 80073DDC 00000000 */   nop
    /* 645E0 80073DE0 21200002 */  addu       $a0, $s0, $zero
    /* 645E4 80073DE4 21282002 */  addu       $a1, $s1, $zero
    /* 645E8 80073DE8 21304002 */  addu       $a2, $s2, $zero
    /* 645EC 80073DEC 08D0010C */  jal        func_80074020
    /* 645F0 80073DF0 21386002 */   addu      $a3, $s3, $zero
    /* 645F4 80073DF4 01000224 */  addiu      $v0, $zero, 0x1
    /* 645F8 80073DF8 0980013C */  lui        $at, %hi(D_80091978)
    /* 645FC 80073DFC 781922AC */  sw         $v0, %lo(D_80091978)($at)
    /* 64600 80073E00 2000BF8F */  lw         $ra, 0x20($sp)
    /* 64604 80073E04 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 64608 80073E08 1800B28F */  lw         $s2, 0x18($sp)
    /* 6460C 80073E0C 1400B18F */  lw         $s1, 0x14($sp)
    /* 64610 80073E10 1000B08F */  lw         $s0, 0x10($sp)
    /* 64614 80073E14 0800E003 */  jr         $ra
    /* 64618 80073E18 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_80073D8C
