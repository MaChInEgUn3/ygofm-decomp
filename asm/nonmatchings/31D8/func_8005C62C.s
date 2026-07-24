nonmatching func_8005C62C, 0x64

glabel func_8005C62C
    /* 4CE2C 8005C62C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 4CE30 8005C630 1000B0AF */  sw         $s0, 0x10($sp)
    /* 4CE34 8005C634 21808000 */  addu       $s0, $a0, $zero
    /* 4CE38 8005C638 1400BFAF */  sw         $ra, 0x14($sp)
    /* 4CE3C 8005C63C 02000424 */  addiu      $a0, $zero, 0x2
  .L8005C640:
    /* 4CE40 8005C640 21280002 */  addu       $a1, $s0, $zero
    /* 4CE44 8005C644 FCF9010C */  jal        func_8007E7F0
    /* 4CE48 8005C648 21300000 */   addu      $a2, $zero, $zero
    /* 4CE4C 8005C64C FCFF4010 */  beqz       $v0, .L8005C640
    /* 4CE50 8005C650 02000424 */   addiu     $a0, $zero, 0x2
    /* 4CE54 8005C654 16000424 */  addiu      $a0, $zero, 0x16
  .L8005C658:
    /* 4CE58 8005C658 21280002 */  addu       $a1, $s0, $zero
    /* 4CE5C 8005C65C FCF9010C */  jal        func_8007E7F0
    /* 4CE60 8005C660 21300000 */   addu      $a2, $zero, $zero
    /* 4CE64 8005C664 FCFF4010 */  beqz       $v0, .L8005C658
    /* 4CE68 8005C668 16000424 */   addiu     $a0, $zero, 0x16
    /* 4CE6C 8005C66C 21200002 */  addu       $a0, $s0, $zero
  .L8005C670:
    /* 4CE70 8005C670 BCF4010C */  jal        func_8007D2F0
    /* 4CE74 8005C674 E0010524 */   addiu     $a1, $zero, 0x1E0
    /* 4CE78 8005C678 FDFF4010 */  beqz       $v0, .L8005C670
    /* 4CE7C 8005C67C 21200002 */   addu      $a0, $s0, $zero
    /* 4CE80 8005C680 1400BF8F */  lw         $ra, 0x14($sp)
    /* 4CE84 8005C684 1000B08F */  lw         $s0, 0x10($sp)
    /* 4CE88 8005C688 0800E003 */  jr         $ra
    /* 4CE8C 8005C68C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8005C62C
