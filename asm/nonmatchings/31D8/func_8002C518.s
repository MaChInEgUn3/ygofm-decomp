nonmatching func_8002C518, 0x48

glabel func_8002C518
    /* 1CD18 8002C518 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1CD1C 8002C51C 1D80023C */  lui        $v0, %hi(D_801D0000)
    /* 1CD20 8002C520 00004224 */  addiu      $v0, $v0, %lo(D_801D0000)
    /* 1CD24 8002C524 21108200 */  addu       $v0, $a0, $v0
    /* 1CD28 8002C528 1000BFAF */  sw         $ra, 0x10($sp)
    /* 1CD2C 8002C52C 4F024290 */  lbu        $v0, 0x24F($v0)
    /* 1CD30 8002C530 00000000 */  nop
    /* 1CD34 8002C534 02004010 */  beqz       $v0, .L8002C540
    /* 1CD38 8002C538 FFFF0324 */   addiu     $v1, $zero, -0x1
    /* 1CD3C 8002C53C 01000324 */  addiu      $v1, $zero, 0x1
  .L8002C540:
    /* 1CD40 8002C540 03006104 */  bgez       $v1, .L8002C550
    /* 1CD44 8002C544 01000224 */   addiu     $v0, $zero, 0x1
    /* 1CD48 8002C548 37B1000C */  jal        func_8002C4DC
    /* 1CD4C 8002C54C 00000000 */   nop
  .L8002C550:
    /* 1CD50 8002C550 1000BF8F */  lw         $ra, 0x10($sp)
    /* 1CD54 8002C554 00000000 */  nop
    /* 1CD58 8002C558 0800E003 */  jr         $ra
    /* 1CD5C 8002C55C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8002C518
