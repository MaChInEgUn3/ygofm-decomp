nonmatching func_80084DD0, 0x74

glabel func_80084DD0
    /* 755D0 80084DD0 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 755D4 80084DD4 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 755D8 80084DD8 FFFF9130 */  andi       $s1, $a0, 0xFFFF
    /* 755DC 80084DDC 21202002 */  addu       $a0, $s1, $zero
    /* 755E0 80084DE0 1800B0AF */  sw         $s0, 0x18($sp)
    /* 755E4 80084DE4 FFFFB030 */  andi       $s0, $a1, 0xFFFF
    /* 755E8 80084DE8 21280002 */  addu       $a1, $s0, $zero
    /* 755EC 80084DEC FFFFC630 */  andi       $a2, $a2, 0xFFFF
    /* 755F0 80084DF0 3800A297 */  lhu        $v0, 0x38($sp)
    /* 755F4 80084DF4 FFFFE730 */  andi       $a3, $a3, 0xFFFF
    /* 755F8 80084DF8 2000BFAF */  sw         $ra, 0x20($sp)
    /* 755FC 80084DFC 9113020C */  jal        func_80084E44
    /* 75600 80084E00 1000A2AF */   sw        $v0, 0x10($sp)
    /* 75604 80084E04 2C18020C */  jal        func_800860B0
    /* 75608 80084E08 00000000 */   nop
    /* 7560C 80084E0C 21202002 */  addu       $a0, $s1, $zero
    /* 75610 80084E10 1080013C */  lui        $at, %hi(D_800FE0CC)
    /* 75614 80084E14 CCE020A4 */  sh         $zero, %lo(D_800FE0CC)($at)
    /* 75618 80084E18 F213020C */  jal        func_80084FC8
    /* 7561C 80084E1C 21280002 */   addu      $a1, $s0, $zero
    /* 75620 80084E20 1015020C */  jal        func_80085440
    /* 75624 80084E24 00000000 */   nop
    /* 75628 80084E28 CC14020C */  jal        func_80085330
    /* 7562C 80084E2C 00000000 */   nop
    /* 75630 80084E30 2000BF8F */  lw         $ra, 0x20($sp)
    /* 75634 80084E34 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 75638 80084E38 1800B08F */  lw         $s0, 0x18($sp)
    /* 7563C 80084E3C 0800E003 */  jr         $ra
    /* 75640 80084E40 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_80084DD0
