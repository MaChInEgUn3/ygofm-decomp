nonmatching func_8007FCC0, 0x70

glabel func_8007FCC0
    /* 704C0 8007FCC0 0980023C */  lui        $v0, %hi(D_8009466A)
    /* 704C4 8007FCC4 6A464290 */  lbu        $v0, %lo(D_8009466A)($v0)
    /* 704C8 8007FCC8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 704CC 8007FCCC 1000B0AF */  sw         $s0, 0x10($sp)
    /* 704D0 8007FCD0 21808000 */  addu       $s0, $a0, $zero
    /* 704D4 8007FCD4 0200422C */  sltiu      $v0, $v0, 0x2
    /* 704D8 8007FCD8 08004014 */  bnez       $v0, .L8007FCFC
    /* 704DC 8007FCDC 1400BFAF */   sw        $ra, 0x14($sp)
    /* 704E0 8007FCE0 0180043C */  lui        $a0, %hi(D_800122C8)
    /* 704E4 8007FCE4 C8228424 */  addiu      $a0, $a0, %lo(D_800122C8)
    /* 704E8 8007FCE8 0980023C */  lui        $v0, %hi(D_80094664)
    /* 704EC 8007FCEC 6446428C */  lw         $v0, %lo(D_80094664)($v0)
    /* 704F0 8007FCF0 00000000 */  nop
    /* 704F4 8007FCF4 09F84000 */  jalr       $v0
    /* 704F8 8007FCF8 21280002 */   addu      $a1, $s0, $zero
  .L8007FCFC:
    /* 704FC 8007FCFC 21280002 */  addu       $a1, $s0, $zero
    /* 70500 8007FD00 0980023C */  lui        $v0, %hi(D_80094660)
    /* 70504 8007FD04 6046428C */  lw         $v0, %lo(D_80094660)($v0)
    /* 70508 8007FD08 21300000 */  addu       $a2, $zero, $zero
    /* 7050C 8007FD0C 1800448C */  lw         $a0, 0x18($v0)
    /* 70510 8007FD10 0800428C */  lw         $v0, 0x8($v0)
    /* 70514 8007FD14 00000000 */  nop
    /* 70518 8007FD18 09F84000 */  jalr       $v0
    /* 7051C 8007FD1C 21380000 */   addu      $a3, $zero, $zero
    /* 70520 8007FD20 1400BF8F */  lw         $ra, 0x14($sp)
    /* 70524 8007FD24 1000B08F */  lw         $s0, 0x10($sp)
    /* 70528 8007FD28 0800E003 */  jr         $ra
    /* 7052C 8007FD2C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8007FCC0
