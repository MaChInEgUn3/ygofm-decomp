nonmatching func_800804D8, 0x40

glabel func_800804D8
    /* 70CD8 800804D8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 70CDC 800804DC 1000B0AF */  sw         $s0, 0x10($sp)
    /* 70CE0 800804E0 21808000 */  addu       $s0, $a0, $zero
    /* 70CE4 800804E4 02000224 */  addiu      $v0, $zero, 0x2
    /* 70CE8 800804E8 1400BFAF */  sw         $ra, 0x14($sp)
    /* 70CEC 800804EC 030002A2 */  sb         $v0, 0x3($s0)
    /* 70CF0 800804F0 0000A484 */  lh         $a0, 0x0($a1)
    /* 70CF4 800804F4 0200A584 */  lh         $a1, 0x2($a1)
    /* 70CF8 800804F8 B402020C */  jal        func_80080AD0
    /* 70CFC 800804FC 00000000 */   nop
    /* 70D00 80080500 040002AE */  sw         $v0, 0x4($s0)
    /* 70D04 80080504 080000AE */  sw         $zero, 0x8($s0)
    /* 70D08 80080508 1400BF8F */  lw         $ra, 0x14($sp)
    /* 70D0C 8008050C 1000B08F */  lw         $s0, 0x10($sp)
    /* 70D10 80080510 0800E003 */  jr         $ra
    /* 70D14 80080514 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800804D8
