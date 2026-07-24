nonmatching func_8007A294, 0x4C

glabel func_8007A294
    /* 6AA94 8007A294 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 6AA98 8007A298 1000BFAF */  sw         $ra, 0x10($sp)
    /* 6AA9C 8007A29C 0980013C */  lui        $at, %hi(D_800934E4)
    /* 6AAA0 8007A2A0 E43420AC */  sw         $zero, %lo(D_800934E4)($at)
    /* 6AAA4 8007A2A4 0980013C */  lui        $at, %hi(D_800934E0)
    /* 6AAA8 8007A2A8 E03420AC */  sw         $zero, %lo(D_800934E0)($at)
    /* 6AAAC 8007A2AC 0980013C */  lui        $at, %hi(D_800934F0)
    /* 6AAB0 8007A2B0 F03420AC */  sw         $zero, %lo(D_800934F0)($at)
    /* 6AAB4 8007A2B4 0980013C */  lui        $at, %hi(D_800934EC)
    /* 6AAB8 8007A2B8 E4D0010C */  jal        func_80074390
    /* 6AABC 8007A2BC EC3420AC */   sw        $zero, %lo(D_800934EC)($at)
    /* 6AAC0 8007A2C0 0880053C */  lui        $a1, %hi(func_8007A634)
    /* 6AAC4 8007A2C4 34A6A524 */  addiu      $a1, $a1, %lo(func_8007A634)
    /* 6AAC8 8007A2C8 F0D0010C */  jal        func_800743C0
    /* 6AACC 8007A2CC 02000424 */   addiu     $a0, $zero, 0x2
    /* 6AAD0 8007A2D0 1000BF8F */  lw         $ra, 0x10($sp)
    /* 6AAD4 8007A2D4 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 6AAD8 8007A2D8 0800E003 */  jr         $ra
    /* 6AADC 8007A2DC 00000000 */   nop
endlabel func_8007A294
