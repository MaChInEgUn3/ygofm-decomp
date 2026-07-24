nonmatching func_80038AB0, 0x58

glabel func_80038AB0
    /* 292B0 80038AB0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 292B4 80038AB4 1400BFAF */  sw         $ra, 0x14($sp)
    /* 292B8 80038AB8 1000B0AF */  sw         $s0, 0x10($sp)
    /* 292BC 80038ABC 58008280 */  lb         $v0, 0x58($a0)
    /* 292C0 80038AC0 00000000 */  nop
    /* 292C4 80038AC4 80100200 */  sll        $v0, $v0, 2
    /* 292C8 80038AC8 21208200 */  addu       $a0, $a0, $v0
    /* 292CC 80038ACC 0000828C */  lw         $v0, 0x0($a0)
    /* 292D0 80038AD0 00000000 */  nop
    /* 292D4 80038AD4 00004390 */  lbu        $v1, 0x0($v0)
    /* 292D8 80038AD8 01004224 */  addiu      $v0, $v0, 0x1
    /* 292DC 80038ADC 21806000 */  addu       $s0, $v1, $zero
    /* 292E0 80038AE0 0500001A */  blez       $s0, .L80038AF8
    /* 292E4 80038AE4 000082AC */   sw        $v0, 0x0($a0)
    /* 292E8 80038AE8 39B3000C */  jal        func_8002CCE4
    /* 292EC 80038AEC 1F000426 */   addiu     $a0, $s0, 0x1F
    /* 292F0 80038AF0 39B3000C */  jal        func_8002CCE4
    /* 292F4 80038AF4 E0060426 */   addiu     $a0, $s0, 0x6E0
  .L80038AF8:
    /* 292F8 80038AF8 1400BF8F */  lw         $ra, 0x14($sp)
    /* 292FC 80038AFC 1000B08F */  lw         $s0, 0x10($sp)
    /* 29300 80038B00 0800E003 */  jr         $ra
    /* 29304 80038B04 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80038AB0
