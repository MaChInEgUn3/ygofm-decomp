nonmatching func_800498BC, 0x3C

glabel func_800498BC
    /* 3A0BC 800498BC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 3A0C0 800498C0 00240400 */  sll        $a0, $a0, 16
    /* 3A0C4 800498C4 03008010 */  beqz       $a0, .L800498D4
    /* 3A0C8 800498C8 1000BFAF */   sw        $ra, 0x10($sp)
    /* 3A0CC 800498CC 36260108 */  j          .L800498D8
    /* 3A0D0 800498D0 01000424 */   addiu     $a0, $zero, 0x1
  .L800498D4:
    /* 3A0D4 800498D4 21200000 */  addu       $a0, $zero, $zero
  .L800498D8:
    /* 3A0D8 800498D8 90DC010C */  jal        func_80077240
    /* 3A0DC 800498DC 00000000 */   nop
    /* 3A0E0 800498E0 00140200 */  sll        $v0, $v0, 16
    /* 3A0E4 800498E4 03140200 */  sra        $v0, $v0, 16
    /* 3A0E8 800498E8 1000BF8F */  lw         $ra, 0x10($sp)
    /* 3A0EC 800498EC 00000000 */  nop
    /* 3A0F0 800498F0 0800E003 */  jr         $ra
    /* 3A0F4 800498F4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800498BC
