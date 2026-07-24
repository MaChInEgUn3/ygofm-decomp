nonmatching func_8005A4C4, 0x78

glabel func_8005A4C4
    /* 4ACC4 8005A4C4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 4ACC8 8005A4C8 1000BFAF */  sw         $ra, 0x10($sp)
    /* 4ACCC 8005A4CC 180D828C */  lw         $v0, 0xD18($a0)
    /* 4ACD0 8005A4D0 00000000 */  nop
    /* 4ACD4 8005A4D4 12004010 */  beqz       $v0, .L8005A520
    /* 4ACD8 8005A4D8 00000000 */   nop
    /* 4ACDC 8005A4DC 440040A4 */  sh         $zero, 0x44($v0)
    /* 4ACE0 8005A4E0 180D838C */  lw         $v1, 0xD18($a0)
    /* 4ACE4 8005A4E4 2800A28F */  lw         $v0, 0x28($sp)
    /* 4ACE8 8005A4E8 00000000 */  nop
    /* 4ACEC 8005A4EC 460062A4 */  sh         $v0, 0x46($v1)
    /* 4ACF0 8005A4F0 180D828C */  lw         $v0, 0xD18($a0)
    /* 4ACF4 8005A4F4 00000000 */  nop
    /* 4ACF8 8005A4F8 480040A4 */  sh         $zero, 0x48($v0)
    /* 4ACFC 8005A4FC 180D828C */  lw         $v0, 0xD18($a0)
    /* 4AD00 8005A500 00000000 */  nop
    /* 4AD04 8005A504 180045AC */  sw         $a1, 0x18($v0)
    /* 4AD08 8005A508 180D828C */  lw         $v0, 0xD18($a0)
    /* 4AD0C 8005A50C 00000000 */  nop
    /* 4AD10 8005A510 1C0046AC */  sw         $a2, 0x1C($v0)
    /* 4AD14 8005A514 180D828C */  lw         $v0, 0xD18($a0)
    /* 4AD18 8005A518 00000000 */  nop
    /* 4AD1C 8005A51C 200047AC */  sw         $a3, 0x20($v0)
  .L8005A520:
    /* 4AD20 8005A520 180D848C */  lw         $a0, 0xD18($a0)
    /* 4AD24 8005A524 8B64010C */  jal        func_8005922C
    /* 4AD28 8005A528 21280000 */   addu      $a1, $zero, $zero
    /* 4AD2C 8005A52C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 4AD30 8005A530 00000000 */  nop
    /* 4AD34 8005A534 0800E003 */  jr         $ra
    /* 4AD38 8005A538 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8005A4C4
