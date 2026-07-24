nonmatching func_8008F09C, 0x3C

glabel func_8008F09C
    /* 7F89C 8008F09C 0A80063C */  lui        $a2, %hi(D_80099EBC)
    /* 7F8A0 8008F0A0 BC9EC68C */  lw         $a2, %lo(D_80099EBC)($a2)
    /* 7F8A4 8008F0A4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 7F8A8 8008F0A8 0700C018 */  blez       $a2, .L8008F0C8
    /* 7F8AC 8008F0AC 1000BFAF */   sw        $ra, 0x10($sp)
    /* 7F8B0 8008F0B0 1080053C */  lui        $a1, %hi(D_800FE708)
    /* 7F8B4 8008F0B4 08E7A524 */  addiu      $a1, $a1, %lo(D_800FE708)
    /* 7F8B8 8008F0B8 40CE010C */  jal        func_80073900
    /* 7F8BC 8008F0BC 01000424 */   addiu     $a0, $zero, 0x1
    /* 7F8C0 8008F0C0 0A80013C */  lui        $at, %hi(D_80099EBC)
    /* 7F8C4 8008F0C4 BC9E20AC */  sw         $zero, %lo(D_80099EBC)($at)
  .L8008F0C8:
    /* 7F8C8 8008F0C8 1000BF8F */  lw         $ra, 0x10($sp)
    /* 7F8CC 8008F0CC 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 7F8D0 8008F0D0 0800E003 */  jr         $ra
    /* 7F8D4 8008F0D4 00000000 */   nop
endlabel func_8008F09C
