nonmatching func_8004B990, 0x50

glabel func_8004B990
    /* 3C190 8004B990 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 3C194 8004B994 0A80023C */  lui        $v0, %hi(D_8009B458)
    /* 3C198 8004B998 58B4428C */  lw         $v0, %lo(D_8009B458)($v0)
    /* 3C19C 8004B99C 01000324 */  addiu      $v1, $zero, 0x1
    /* 3C1A0 8004B9A0 1000BFAF */  sw         $ra, 0x10($sp)
    /* 3C1A4 8004B9A4 2CCE010C */  jal        func_800738B0
    /* 3C1A8 8004B9A8 030543A0 */   sb        $v1, 0x503($v0)
    /* 3C1AC 8004B9AC 00F2043C */  lui        $a0, (0xF2000002 >> 16)
    /* 3C1B0 8004B9B0 95CE010C */  jal        func_80073A54
    /* 3C1B4 8004B9B4 02008434 */   ori       $a0, $a0, (0xF2000002 & 0xFFFF)
    /* 3C1B8 8004B9B8 30CE010C */  jal        func_800738C0
    /* 3C1BC 8004B9BC 00000000 */   nop
    /* 3C1C0 8004B9C0 0A80023C */  lui        $v0, %hi(D_8009B458)
    /* 3C1C4 8004B9C4 58B4428C */  lw         $v0, %lo(D_8009B458)($v0)
    /* 3C1C8 8004B9C8 00000000 */  nop
    /* 3C1CC 8004B9CC 000540A0 */  sb         $zero, 0x500($v0)
    /* 3C1D0 8004B9D0 1000BF8F */  lw         $ra, 0x10($sp)
    /* 3C1D4 8004B9D4 00000000 */  nop
    /* 3C1D8 8004B9D8 0800E003 */  jr         $ra
    /* 3C1DC 8004B9DC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8004B990
