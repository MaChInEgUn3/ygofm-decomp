nonmatching func_80074AA0, 0x58

glabel func_80074AA0
    /* 652A0 80074AA0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 652A4 80074AA4 0980043C */  lui        $a0, %hi(D_80092AA8)
    /* 652A8 80074AA8 A82A8424 */  addiu      $a0, $a0, %lo(D_80092AA8)
    /* 652AC 80074AAC 0980033C */  lui        $v1, %hi(D_80092ACC)
    /* 652B0 80074AB0 CC2A638C */  lw         $v1, %lo(D_80092ACC)($v1)
    /* 652B4 80074AB4 00010224 */  addiu      $v0, $zero, 0x100
    /* 652B8 80074AB8 1000BFAF */  sw         $ra, 0x10($sp)
    /* 652BC 80074ABC 000062AC */  sw         $v0, 0x0($v1)
    /* 652C0 80074AC0 0980013C */  lui        $at, %hi(D_80092AC8)
    /* 652C4 80074AC4 C82A20AC */  sw         $zero, %lo(D_80092AC8)($at)
    /* 652C8 80074AC8 E4D2010C */  jal        func_80074B90
    /* 652CC 80074ACC 08000524 */   addiu     $a1, $zero, 0x8
    /* 652D0 80074AD0 0780053C */  lui        $a1, %hi(func_80074AF8)
    /* 652D4 80074AD4 F84AA524 */  addiu      $a1, $a1, %lo(func_80074AF8)
    /* 652D8 80074AD8 F0D0010C */  jal        func_800743C0
    /* 652DC 80074ADC 21200000 */   addu      $a0, $zero, $zero
    /* 652E0 80074AE0 0780023C */  lui        $v0, %hi(func_80074B64)
    /* 652E4 80074AE4 644B4224 */  addiu      $v0, $v0, %lo(func_80074B64)
    /* 652E8 80074AE8 1000BF8F */  lw         $ra, 0x10($sp)
    /* 652EC 80074AEC 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 652F0 80074AF0 0800E003 */  jr         $ra
    /* 652F4 80074AF4 00000000 */   nop
endlabel func_80074AA0
