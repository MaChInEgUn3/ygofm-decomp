nonmatching func_8005C4F0, 0x40

glabel func_8005C4F0
    /* 4CCF0 8005C4F0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 4CCF4 8005C4F4 1000BFAF */  sw         $ra, 0x10($sp)
    /* 4CCF8 8005C4F8 21108000 */  addu       $v0, $a0, $zero
    /* 4CCFC 8005C4FC 2120A000 */  addu       $a0, $a1, $zero
    /* 4CD00 8005C500 FCF4010C */  jal        func_8007D3F0
    /* 4CD04 8005C504 21284000 */   addu      $a1, $v0, $zero
    /* 4CD08 8005C508 21184000 */  addu       $v1, $v0, $zero
    /* 4CD0C 8005C50C 03006010 */  beqz       $v1, .L8005C51C
    /* 4CD10 8005C510 FFFF0224 */   addiu     $v0, $zero, -0x1
    /* 4CD14 8005C514 02006214 */  bne        $v1, $v0, .L8005C520
    /* 4CD18 8005C518 21100000 */   addu      $v0, $zero, $zero
  .L8005C51C:
    /* 4CD1C 8005C51C FFFF0224 */  addiu      $v0, $zero, -0x1
  .L8005C520:
    /* 4CD20 8005C520 1000BF8F */  lw         $ra, 0x10($sp)
    /* 4CD24 8005C524 00000000 */  nop
    /* 4CD28 8005C528 0800E003 */  jr         $ra
    /* 4CD2C 8005C52C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8005C4F0
