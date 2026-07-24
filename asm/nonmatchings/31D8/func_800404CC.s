nonmatching func_800404CC, 0x44

glabel func_800404CC
    /* 30CCC 800404CC E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 30CD0 800404D0 3800A28F */  lw         $v0, 0x38($sp)
    /* 30CD4 800404D4 3C00A38F */  lw         $v1, 0x3C($sp)
    /* 30CD8 800404D8 1800BFAF */  sw         $ra, 0x18($sp)
    /* 30CDC 800404DC 300085A4 */  sh         $a1, 0x30($a0)
    /* 30CE0 800404E0 2128E000 */  addu       $a1, $a3, $zero
    /* 30CE4 800404E4 320086A4 */  sh         $a2, 0x32($a0)
    /* 30CE8 800404E8 1000A2AF */  sw         $v0, 0x10($sp)
    /* 30CEC 800404EC 1400A3AF */  sw         $v1, 0x14($sp)
    /* 30CF0 800404F0 3000A68F */  lw         $a2, 0x30($sp)
    /* 30CF4 800404F4 3400A78F */  lw         $a3, 0x34($sp)
    /* 30CF8 800404F8 1A01010C */  jal        func_80040468
    /* 30CFC 800404FC 00000000 */   nop
    /* 30D00 80040500 1800BF8F */  lw         $ra, 0x18($sp)
    /* 30D04 80040504 00000000 */  nop
    /* 30D08 80040508 0800E003 */  jr         $ra
    /* 30D0C 8004050C 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_800404CC
