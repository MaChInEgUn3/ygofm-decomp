nonmatching func_80019CC8, 0x50

glabel func_80019CC8
    /* A4C8 80019CC8 CD028293 */  lbu        $v0, %gp_rel(D_8009B1D5)($gp)
    /* A4CC 80019CCC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* A4D0 80019CD0 0D004014 */  bnez       $v0, .L80019D08
    /* A4D4 80019CD4 1000BFAF */   sw        $ra, 0x10($sp)
    /* A4D8 80019CD8 0A80023C */  lui        $v0, %hi(D_8009B360)
    /* A4DC 80019CDC 60B34280 */  lb         $v0, %lo(D_8009B360)($v0)
    /* A4E0 80019CE0 00000000 */  nop
    /* A4E4 80019CE4 08004104 */  bgez       $v0, .L80019D08
    /* A4E8 80019CE8 00000000 */   nop
    /* A4EC 80019CEC 0A80023C */  lui        $v0, %hi(D_8009B361)
    /* A4F0 80019CF0 61B34280 */  lb         $v0, %lo(D_8009B361)($v0)
    /* A4F4 80019CF4 00000000 */  nop
    /* A4F8 80019CF8 03004004 */  bltz       $v0, .L80019D08
    /* A4FC 80019CFC 00000000 */   nop
    /* A500 80019D00 39B3000C */  jal        func_8002CCE4
    /* A504 80019D04 20018424 */   addiu     $a0, $a0, 0x120
  .L80019D08:
    /* A508 80019D08 1000BF8F */  lw         $ra, 0x10($sp)
    /* A50C 80019D0C 00000000 */  nop
    /* A510 80019D10 0800E003 */  jr         $ra
    /* A514 80019D14 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80019CC8
