nonmatching func_80076790, 0x4C

glabel func_80076790
    /* 66F90 80076790 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 66F94 80076794 0A008010 */  beqz       $a0, .L800767C0
    /* 66F98 80076798 1000BFAF */   sw        $ra, 0x10($sp)
    /* 66F9C 8007679C 0980043C */  lui        $a0, %hi(D_80092B24)
    /* 66FA0 800767A0 242B848C */  lw         $a0, %lo(D_80092B24)($a0)
    /* 66FA4 800767A4 4CD7010C */  jal        func_80075D30
    /* 66FA8 800767A8 00000000 */   nop
    /* 66FAC 800767AC 04004014 */  bnez       $v0, .L800767C0
    /* 66FB0 800767B0 01000224 */   addiu     $v0, $zero, 0x1
    /* 66FB4 800767B4 0980013C */  lui        $at, %hi(D_80092B20)
    /* 66FB8 800767B8 F3D90108 */  j          .L800767CC
    /* 66FBC 800767BC 202B22AC */   sw        $v0, %lo(D_80092B20)($at)
  .L800767C0:
    /* 66FC0 800767C0 0980013C */  lui        $at, %hi(D_80092B20)
    /* 66FC4 800767C4 202B20AC */  sw         $zero, %lo(D_80092B20)($at)
    /* 66FC8 800767C8 21100000 */  addu       $v0, $zero, $zero
  .L800767CC:
    /* 66FCC 800767CC 1000BF8F */  lw         $ra, 0x10($sp)
    /* 66FD0 800767D0 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 66FD4 800767D4 0800E003 */  jr         $ra
    /* 66FD8 800767D8 00000000 */   nop
endlabel func_80076790
    /* 66FDC 800767DC 00000000 */  nop
