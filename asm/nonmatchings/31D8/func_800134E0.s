nonmatching func_800134E0, 0x4C

glabel func_800134E0
    /* 3CE0 800134E0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 3CE4 800134E4 21188000 */  addu       $v1, $a0, $zero
    /* 3CE8 800134E8 10006424 */  addiu      $a0, $v1, 0x10
    /* 3CEC 800134EC 1000BFAF */  sw         $ra, 0x10($sp)
    /* 3CF0 800134F0 0C00828C */  lw         $v0, 0xC($a0)
    /* 3CF4 800134F4 00000000 */  nop
    /* 3CF8 800134F8 2128A200 */  addu       $a1, $a1, $v0
    /* 3CFC 800134FC 100065AC */  sw         $a1, 0x10($v1)
    /* 3D00 80013500 1000828C */  lw         $v0, 0x10($a0)
    /* 3D04 80013504 1400838C */  lw         $v1, 0x14($a0)
    /* 3D08 80013508 2130C200 */  addu       $a2, $a2, $v0
    /* 3D0C 8001350C 2138E300 */  addu       $a3, $a3, $v1
    /* 3D10 80013510 040086AC */  sw         $a2, 0x4($a0)
    /* 3D14 80013514 542B020C */  jal        func_8008AD50
    /* 3D18 80013518 080087AC */   sw        $a3, 0x8($a0)
    /* 3D1C 8001351C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 3D20 80013520 00000000 */  nop
    /* 3D24 80013524 0800E003 */  jr         $ra
    /* 3D28 80013528 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800134E0
