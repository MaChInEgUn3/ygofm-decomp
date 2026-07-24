nonmatching func_800245A0, 0x4C

glabel func_800245A0
    /* 14DA0 800245A0 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 14DA4 800245A4 1400B1AF */  sw         $s1, 0x14($sp)
    /* 14DA8 800245A8 2188A000 */  addu       $s1, $a1, $zero
    /* 14DAC 800245AC 1000B0AF */  sw         $s0, 0x10($sp)
    /* 14DB0 800245B0 1780103C */  lui        $s0, %hi(D_80177FE8)
    /* 14DB4 800245B4 E87F1026 */  addiu      $s0, $s0, %lo(D_80177FE8)
    /* 14DB8 800245B8 21280002 */  addu       $a1, $s0, $zero
    /* 14DBC 800245BC 1800BFAF */  sw         $ra, 0x18($sp)
    /* 14DC0 800245C0 FD90000C */  jal        func_800243F4
    /* 14DC4 800245C4 ACFF0626 */   addiu     $a2, $s0, -0x54
    /* 14DC8 800245C8 21202002 */  addu       $a0, $s1, $zero
    /* 14DCC 800245CC 50000526 */  addiu      $a1, $s0, 0x50
    /* 14DD0 800245D0 FD90000C */  jal        func_800243F4
    /* 14DD4 800245D4 D4FF0626 */   addiu     $a2, $s0, -0x2C
    /* 14DD8 800245D8 1800BF8F */  lw         $ra, 0x18($sp)
    /* 14DDC 800245DC 1400B18F */  lw         $s1, 0x14($sp)
    /* 14DE0 800245E0 1000B08F */  lw         $s0, 0x10($sp)
    /* 14DE4 800245E4 0800E003 */  jr         $ra
    /* 14DE8 800245E8 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_800245A0
