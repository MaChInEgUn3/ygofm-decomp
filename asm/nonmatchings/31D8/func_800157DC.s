nonmatching func_800157DC, 0x40

glabel func_800157DC
    /* 5FDC 800157DC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 5FE0 800157E0 1000BFAF */  sw         $ra, 0x10($sp)
    /* 5FE4 800157E4 E055000C */  jal        func_80015780
    /* 5FE8 800157E8 00000000 */   nop
    /* 5FEC 800157EC 0F80023C */  lui        $v0, %hi(D_800E9EC8)
    /* 5FF0 800157F0 C89E4224 */  addiu      $v0, $v0, %lo(D_800E9EC8)
    /* 5FF4 800157F4 06004390 */  lbu        $v1, 0x6($v0)
    /* 5FF8 800157F8 08000424 */  addiu      $a0, $zero, 0x8
    /* 5FFC 800157FC 070044A0 */  sb         $a0, 0x7($v0)
    /* 6000 80015800 01006334 */  ori        $v1, $v1, 0x1
    /* 6004 80015804 CB55000C */  jal        func_8001572C
    /* 6008 80015808 060043A0 */   sb        $v1, 0x6($v0)
    /* 600C 8001580C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 6010 80015810 00000000 */  nop
    /* 6014 80015814 0800E003 */  jr         $ra
    /* 6018 80015818 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800157DC
