nonmatching func_8003771C, 0x90

glabel func_8003771C
    /* 27F1C 8003771C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 27F20 80037720 1000B0AF */  sw         $s0, 0x10($sp)
    /* 27F24 80037724 21808000 */  addu       $s0, $a0, $zero
    /* 27F28 80037728 1400BFAF */  sw         $ra, 0x14($sp)
    /* 27F2C 8003772C 4FDB000C */  jal        func_80036D3C
    /* 27F30 80037730 510000A2 */   sb        $zero, 0x51($s0)
    /* 27F34 80037734 0A80013C */  lui        $at, %hi(D_8009B2A8)
    /* 27F38 80037738 A8B222A4 */  sh         $v0, %lo(D_8009B2A8)($at)
    /* 27F3C 8003773C 4FDB000C */  jal        func_80036D3C
    /* 27F40 80037740 21200002 */   addu      $a0, $s0, $zero
    /* 27F44 80037744 0A80013C */  lui        $at, %hi(D_8009B2AA)
    /* 27F48 80037748 AAB222A4 */  sh         $v0, %lo(D_8009B2AA)($at)
    /* 27F4C 8003774C 4FDB000C */  jal        func_80036D3C
    /* 27F50 80037750 21200002 */   addu      $a0, $s0, $zero
    /* 27F54 80037754 0A80033C */  lui        $v1, %hi(D_8009B2AA)
    /* 27F58 80037758 AAB26384 */  lh         $v1, %lo(D_8009B2AA)($v1)
    /* 27F5C 8003775C 0A80013C */  lui        $at, %hi(D_8009B29C)
    /* 27F60 80037760 9CB222A4 */  sh         $v0, %lo(D_8009B29C)($at)
    /* 27F64 80037764 0A80023C */  lui        $v0, %hi(D_8009B2AA)
    /* 27F68 80037768 AAB24294 */  lhu        $v0, %lo(D_8009B2AA)($v0)
    /* 27F6C 8003776C 00106328 */  slti       $v1, $v1, 0x1000
    /* 27F70 80037770 05006014 */  bnez       $v1, .L80037788
    /* 27F74 80037774 00F04224 */   addiu     $v0, $v0, -0x1000
    /* 27F78 80037778 0A80013C */  lui        $at, %hi(D_8009B2AA)
    /* 27F7C 8003777C AAB222A4 */  sh         $v0, %lo(D_8009B2AA)($at)
    /* 27F80 80037780 0A000224 */  addiu      $v0, $zero, 0xA
    /* 27F84 80037784 510002A2 */  sb         $v0, 0x51($s0)
  .L80037788:
    /* 27F88 80037788 1400BF8F */  lw         $ra, 0x14($sp)
    /* 27F8C 8003778C 1000B08F */  lw         $s0, 0x10($sp)
    /* 27F90 80037790 07000224 */  addiu      $v0, $zero, 0x7
    /* 27F94 80037794 4F0482A3 */  sb         $v0, %gp_rel(D_8009B357)($gp)
    /* 27F98 80037798 07000224 */  addiu      $v0, $zero, 0x7
    /* 27F9C 8003779C 0A80013C */  lui        $at, %hi(D_8009B27C)
    /* 27FA0 800377A0 7CB222A4 */  sh         $v0, %lo(D_8009B27C)($at)
    /* 27FA4 800377A4 0800E003 */  jr         $ra
    /* 27FA8 800377A8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8003771C
