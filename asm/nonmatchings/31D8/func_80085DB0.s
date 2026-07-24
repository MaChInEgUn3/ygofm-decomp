nonmatching func_80085DB0, 0x58

glabel func_80085DB0
    /* 765B0 80085DB0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 765B4 80085DB4 FFFF8430 */  andi       $a0, $a0, 0xFFFF
    /* 765B8 80085DB8 FFFFA530 */  andi       $a1, $a1, 0xFFFF
    /* 765BC 80085DBC 1000BFAF */  sw         $ra, 0x10($sp)
    /* 765C0 80085DC0 0800C4AC */  sw         $a0, 0x8($a2)
    /* 765C4 80085DC4 0000C48C */  lw         $a0, 0x0($a2)
    /* 765C8 80085DC8 0400C28C */  lw         $v0, 0x4($a2)
    /* 765CC 80085DCC 04000324 */  addiu      $v1, $zero, 0x4
    /* 765D0 80085DD0 0C00C5AC */  sw         $a1, 0xC($a2)
    /* 765D4 80085DD4 0000C58C */  lw         $a1, 0x0($a2)
    /* 765D8 80085DD8 04188300 */  sllv       $v1, $v1, $a0
    /* 765DC 80085DDC 21104300 */  addu       $v0, $v0, $v1
    /* 765E0 80085DE0 FCFF4224 */  addiu      $v0, $v0, -0x4
    /* 765E4 80085DE4 1000C2AC */  sw         $v0, 0x10($a2)
    /* 765E8 80085DE8 01000224 */  addiu      $v0, $zero, 0x1
    /* 765EC 80085DEC 0400C48C */  lw         $a0, 0x4($a2)
    /* 765F0 80085DF0 EEFE010C */  jal        func_8007FBB8
    /* 765F4 80085DF4 0428A200 */   sllv      $a1, $v0, $a1
    /* 765F8 80085DF8 1000BF8F */  lw         $ra, 0x10($sp)
    /* 765FC 80085DFC 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 76600 80085E00 0800E003 */  jr         $ra
    /* 76604 80085E04 00000000 */   nop
endlabel func_80085DB0
    /* 76608 80085E08 00000000 */  nop
    /* 7660C 80085E0C 00000000 */  nop
