nonmatching func_800865A0, 0x80

glabel func_800865A0
    /* 76DA0 800865A0 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 76DA4 800865A4 2000B0AF */  sw         $s0, 0x20($sp)
    /* 76DA8 800865A8 21808000 */  addu       $s0, $a0, $zero
    /* 76DAC 800865AC 2400B1AF */  sw         $s1, 0x24($sp)
    /* 76DB0 800865B0 2188A000 */  addu       $s1, $a1, $zero
    /* 76DB4 800865B4 14002526 */  addiu      $a1, $s1, 0x14
    /* 76DB8 800865B8 2800BFAF */  sw         $ra, 0x28($sp)
    /* 76DBC 800865BC 1C1C020C */  jal        func_80087070
    /* 76DC0 800865C0 1000A627 */   addiu     $a2, $sp, 0x10
    /* 76DC4 800865C4 21200002 */  addu       $a0, $s0, $zero
    /* 76DC8 800865C8 201D020C */  jal        func_80087480
    /* 76DCC 800865CC 21282002 */   addu      $a1, $s1, $zero
    /* 76DD0 800865D0 1000A28F */  lw         $v0, 0x10($sp)
    /* 76DD4 800865D4 1400038E */  lw         $v1, 0x14($s0)
    /* 76DD8 800865D8 00000000 */  nop
    /* 76DDC 800865DC 21104300 */  addu       $v0, $v0, $v1
    /* 76DE0 800865E0 140022AE */  sw         $v0, 0x14($s1)
    /* 76DE4 800865E4 1400A28F */  lw         $v0, 0x14($sp)
    /* 76DE8 800865E8 1800038E */  lw         $v1, 0x18($s0)
    /* 76DEC 800865EC 00000000 */  nop
    /* 76DF0 800865F0 21104300 */  addu       $v0, $v0, $v1
    /* 76DF4 800865F4 180022AE */  sw         $v0, 0x18($s1)
    /* 76DF8 800865F8 1800A28F */  lw         $v0, 0x18($sp)
    /* 76DFC 800865FC 1C00038E */  lw         $v1, 0x1C($s0)
    /* 76E00 80086600 00000000 */  nop
    /* 76E04 80086604 21104300 */  addu       $v0, $v0, $v1
    /* 76E08 80086608 1C0022AE */  sw         $v0, 0x1C($s1)
    /* 76E0C 8008660C 2800BF8F */  lw         $ra, 0x28($sp)
    /* 76E10 80086610 2400B18F */  lw         $s1, 0x24($sp)
    /* 76E14 80086614 2000B08F */  lw         $s0, 0x20($sp)
    /* 76E18 80086618 0800E003 */  jr         $ra
    /* 76E1C 8008661C 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel func_800865A0
