/* Handwritten function */
nonmatching func_80074078, 0x70

glabel func_80074078
    /* 64878 80074078 0F80013C */  lui        $at, %hi(D_800F5D00)
    /* 6487C 8007407C 005D3FAC */  sw         $ra, %lo(D_800F5D00)($at)
    /* 64880 80074080 2CCE010C */  jal        func_800738B0
    /* 64884 80074084 00000000 */   nop
    /* 64888 80074088 57000924 */  addiu      $t1, $zero, 0x57
    /* 6488C 8007408C B0000A24 */  addiu      $t2, $zero, 0xB0
    /* 64890 80074090 09F84001 */  jalr       $t2
    /* 64894 80074094 00000000 */   nop
    /* 64898 80074098 6C01428C */  lw         $v0, 0x16C($v0)
    /* 6489C 8007409C 0B000924 */  addiu      $t1, $zero, 0xB
    /* 648A0 800740A0 84084320 */  addi       $v1, $v0, 0x884 /* handwritten instruction */
    /* 648A4 800740A4 0F80013C */  lui        $at, %hi(jtbl_800F5D08)
    /* 648A8 800740A8 085D23AC */  sw         $v1, %lo(jtbl_800F5D08)($at)
    /* 648AC 800740AC 94084320 */  addi       $v1, $v0, 0x894 /* handwritten instruction */
    /* 648B0 800740B0 0F80013C */  lui        $at, %hi(jtbl_800F5D0C)
    /* 648B4 800740B4 0C5D23AC */  sw         $v1, %lo(jtbl_800F5D0C)($at)
  .L800740B8:
    /* 648B8 800740B8 940540AC */  sw         $zero, 0x594($v0)
    /* 648BC 800740BC 04004224 */  addiu      $v0, $v0, 0x4
    /* 648C0 800740C0 FFFF2925 */  addiu      $t1, $t1, -0x1
    /* 648C4 800740C4 FCFF2015 */  bnez       $t1, .L800740B8
    /* 648C8 800740C8 00000000 */   nop
    /* 648CC 800740CC 3CD0010C */  jal        func_800740F0
    /* 648D0 800740D0 00000000 */   nop
    /* 648D4 800740D4 0F801F3C */  lui        $ra, %hi(D_800F5D00)
    /* 648D8 800740D8 005DFF8F */  lw         $ra, %lo(D_800F5D00)($ra)
    /* 648DC 800740DC 00000000 */  nop
    /* 648E0 800740E0 0800E003 */  jr         $ra
    /* 648E4 800740E4 00000000 */   nop
endlabel func_80074078
    /* 648E8 800740E8 00000000 */  nop
    /* 648EC 800740EC 00000000 */  nop
