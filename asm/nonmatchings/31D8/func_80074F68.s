nonmatching func_80074F68, 0x70

glabel func_80074F68
    /* 65768 80074F68 0980023C */  lui        $v0, %hi(D_80092B78)
    /* 6576C 80074F6C 782B428C */  lw         $v0, %lo(D_80092B78)($v0)
    /* 65770 80074F70 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 65774 80074F74 14004014 */  bnez       $v0, .L80074FC8
    /* 65778 80074F78 1000BFAF */   sw        $ra, 0x10($sp)
    /* 6577C 80074F7C 01000224 */  addiu      $v0, $zero, 0x1
    /* 65780 80074F80 0980013C */  lui        $at, %hi(D_80092B78)
    /* 65784 80074F84 2CCE010C */  jal        func_800738B0
    /* 65788 80074F88 782B22AC */   sw        $v0, %lo(D_80092B78)($at)
    /* 6578C 80074F8C 0780043C */  lui        $a0, %hi(func_80075420)
    /* 65790 80074F90 CCD6010C */  jal        func_80075B30
    /* 65794 80074F94 20548424 */   addiu     $a0, $a0, %lo(func_80075420)
    /* 65798 80074F98 00F0043C */  lui        $a0, (0xF0000009 >> 16)
    /* 6579C 80074F9C 09008434 */  ori        $a0, $a0, (0xF0000009 & 0xFFFF)
    /* 657A0 80074FA0 20000524 */  addiu      $a1, $zero, 0x20
    /* 657A4 80074FA4 00200624 */  addiu      $a2, $zero, 0x2000
    /* 657A8 80074FA8 18CE010C */  jal        func_80073860
    /* 657AC 80074FAC 21380000 */   addu      $a3, $zero, $zero
    /* 657B0 80074FB0 21204000 */  addu       $a0, $v0, $zero
    /* 657B4 80074FB4 0980013C */  lui        $at, %hi(D_80092B10)
    /* 657B8 80074FB8 24CE010C */  jal        func_80073890
    /* 657BC 80074FBC 102B24AC */   sw        $a0, %lo(D_80092B10)($at)
    /* 657C0 80074FC0 30CE010C */  jal        func_800738C0
    /* 657C4 80074FC4 00000000 */   nop
  .L80074FC8:
    /* 657C8 80074FC8 1000BF8F */  lw         $ra, 0x10($sp)
    /* 657CC 80074FCC 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 657D0 80074FD0 0800E003 */  jr         $ra
    /* 657D4 80074FD4 00000000 */   nop
endlabel func_80074F68
    /* 657D8 80074FD8 00000000 */  nop
    /* 657DC 80074FDC 00000000 */  nop
