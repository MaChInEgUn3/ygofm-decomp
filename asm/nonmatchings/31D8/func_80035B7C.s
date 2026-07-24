nonmatching func_80035B7C, 0x68

glabel func_80035B7C
    /* 2637C 80035B7C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 26380 80035B80 1000B0AF */  sw         $s0, 0x10($sp)
    /* 26384 80035B84 21808000 */  addu       $s0, $a0, $zero
    /* 26388 80035B88 1400BFAF */  sw         $ra, 0x14($sp)
    /* 2638C 80035B8C 57000492 */  lbu        $a0, 0x57($s0)
    /* 26390 80035B90 2AD7000C */  jal        func_80035CA8
    /* 26394 80035B94 00000000 */   nop
    /* 26398 80035B98 57000492 */  lbu        $a0, 0x57($s0)
    /* 2639C 80035B9C 6ED7000C */  jal        func_80035DB8
    /* 263A0 80035BA0 00000000 */   nop
    /* 263A4 80035BA4 3000048E */  lw         $a0, 0x30($s0)
    /* 263A8 80035BA8 DB00010C */  jal        func_8004036C
    /* 263AC 80035BAC 340000A6 */   sh        $zero, 0x34($s0)
    /* 263B0 80035BB0 2C00048E */  lw         $a0, 0x2C($s0)
    /* 263B4 80035BB4 DB00010C */  jal        func_8004036C
    /* 263B8 80035BB8 00000000 */   nop
    /* 263BC 80035BBC 2800048E */  lw         $a0, 0x28($s0)
    /* 263C0 80035BC0 DB00010C */  jal        func_8004036C
    /* 263C4 80035BC4 00000000 */   nop
    /* 263C8 80035BC8 300000AE */  sw         $zero, 0x30($s0)
    /* 263CC 80035BCC 2C0000AE */  sw         $zero, 0x2C($s0)
    /* 263D0 80035BD0 280000AE */  sw         $zero, 0x28($s0)
    /* 263D4 80035BD4 1400BF8F */  lw         $ra, 0x14($sp)
    /* 263D8 80035BD8 1000B08F */  lw         $s0, 0x10($sp)
    /* 263DC 80035BDC 0800E003 */  jr         $ra
    /* 263E0 80035BE0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80035B7C
