nonmatching func_800866A0, 0x3C

glabel func_800866A0
    /* 76EA0 800866A0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 76EA4 800866A4 05008004 */  bltz       $a0, .L800866BC
    /* 76EA8 800866A8 1000BFAF */   sw        $ra, 0x10($sp)
    /* 76EAC 800866AC B719020C */  jal        func_800866DC
    /* 76EB0 800866B0 FF0F8430 */   andi      $a0, $a0, 0xFFF
    /* 76EB4 800866B4 B3190208 */  j          .L800866CC
    /* 76EB8 800866B8 00000000 */   nop
  .L800866BC:
    /* 76EBC 800866BC 23200400 */  negu       $a0, $a0
    /* 76EC0 800866C0 B719020C */  jal        func_800866DC
    /* 76EC4 800866C4 FF0F8430 */   andi      $a0, $a0, 0xFFF
    /* 76EC8 800866C8 23100200 */  negu       $v0, $v0
  .L800866CC:
    /* 76ECC 800866CC 1000BF8F */  lw         $ra, 0x10($sp)
    /* 76ED0 800866D0 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 76ED4 800866D4 0800E003 */  jr         $ra
    /* 76ED8 800866D8 00000000 */   nop
endlabel func_800866A0
