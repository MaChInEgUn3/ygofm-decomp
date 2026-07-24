nonmatching func_8008CF00, 0x74

glabel func_8008CF00
    /* 7D700 8008CF00 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 7D704 8008CF04 1080023C */  lui        $v0, %hi(D_800FE348)
    /* 7D708 8008CF08 48E34224 */  addiu      $v0, $v0, %lo(D_800FE348)
    /* 7D70C 8008CF0C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 7D710 8008CF10 0000428C */  lw         $v0, 0x0($v0)
    /* 7D714 8008CF14 00000000 */  nop
    /* 7D718 8008CF18 06004010 */  beqz       $v0, .L8008CF34
    /* 7D71C 8008CF1C 00000000 */   nop
    /* 7D720 8008CF20 0180043C */  lui        $a0, %hi(D_8001261C)
    /* 7D724 8008CF24 1C3A020C */  jal        func_8008E870
    /* 7D728 8008CF28 1C268424 */   addiu     $a0, $a0, %lo(D_8001261C)
    /* 7D72C 8008CF2C D9330208 */  j          .L8008CF64
    /* 7D730 8008CF30 FFFF0224 */   addiu     $v0, $zero, -0x1
  .L8008CF34:
    /* 7D734 8008CF34 2436020C */  jal        func_8008D890
    /* 7D738 8008CF38 00000000 */   nop
    /* 7D73C 8008CF3C 21204000 */  addu       $a0, $v0, $zero
    /* 7D740 8008CF40 07008010 */  beqz       $a0, .L8008CF60
    /* 7D744 8008CF44 04000224 */   addiu     $v0, $zero, 0x4
    /* 7D748 8008CF48 06008210 */  beq        $a0, $v0, .L8008CF64
    /* 7D74C 8008CF4C 02000224 */   addiu     $v0, $zero, 0x2
    /* 7D750 8008CF50 DD33020C */  jal        func_8008CF74
    /* 7D754 8008CF54 00000000 */   nop
    /* 7D758 8008CF58 D9330208 */  j          .L8008CF64
    /* 7D75C 8008CF5C 00000000 */   nop
  .L8008CF60:
    /* 7D760 8008CF60 21100000 */  addu       $v0, $zero, $zero
  .L8008CF64:
    /* 7D764 8008CF64 1000BF8F */  lw         $ra, 0x10($sp)
    /* 7D768 8008CF68 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 7D76C 8008CF6C 0800E003 */  jr         $ra
    /* 7D770 8008CF70 00000000 */   nop
endlabel func_8008CF00
