nonmatching func_8003FE14, 0x5C

glabel func_8003FE14
    /* 30614 8003FE14 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 30618 8003FE18 1000B0AF */  sw         $s0, 0x10($sp)
    /* 3061C 8003FE1C 1D80103C */  lui        $s0, %hi(D_801D1880)
    /* 30620 8003FE20 80181026 */  addiu      $s0, $s0, %lo(D_801D1880)
    /* 30624 8003FE24 21200002 */  addu       $a0, $s0, $zero
    /* 30628 8003FE28 1800BFAF */  sw         $ra, 0x18($sp)
    /* 3062C 8003FE2C C5F3000C */  jal        func_8003CF14
    /* 30630 8003FE30 1400B1AF */   sw        $s1, 0x14($sp)
    /* 30634 8003FE34 00101126 */  addiu      $s1, $s0, 0x1000
    /* 30638 8003FE38 C5F3000C */  jal        func_8003CF14
    /* 3063C 8003FE3C 21202002 */   addu      $a0, $s1, $zero
    /* 30640 8003FE40 21200002 */  addu       $a0, $s0, $zero
    /* 30644 8003FE44 0180063C */  lui        $a2, %hi(D_80010384)
    /* 30648 8003FE48 00040524 */  addiu      $a1, $zero, 0x400
    /* 3064C 8003FE4C 8403C624 */  addiu      $a2, $a2, %lo(D_80010384)
    /* 30650 8003FE50 D80491AF */  sw         $s1, %gp_rel(D_8009B3E0)($gp)
    /* 30654 8003FE54 D6FD000C */  jal        func_8003F758
    /* 30658 8003FE58 04000724 */   addiu     $a3, $zero, 0x4
    /* 3065C 8003FE5C 1800BF8F */  lw         $ra, 0x18($sp)
    /* 30660 8003FE60 1400B18F */  lw         $s1, 0x14($sp)
    /* 30664 8003FE64 1000B08F */  lw         $s0, 0x10($sp)
    /* 30668 8003FE68 0800E003 */  jr         $ra
    /* 3066C 8003FE6C 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8003FE14
