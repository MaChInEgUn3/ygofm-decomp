nonmatching func_80075AB8, 0x5C

glabel func_80075AB8
    /* 662B8 80075AB8 F8FFBD27 */  addiu      $sp, $sp, -0x8
    /* 662BC 80075ABC 0D000224 */  addiu      $v0, $zero, 0xD
    /* 662C0 80075AC0 0400A2AF */  sw         $v0, 0x4($sp)
    /* 662C4 80075AC4 BED60108 */  j          .L80075AF8
    /* 662C8 80075AC8 0000A0AF */   sw        $zero, 0x0($sp)
  .L80075ACC:
    /* 662CC 80075ACC 0400A38F */  lw         $v1, 0x4($sp)
    /* 662D0 80075AD0 00000000 */  nop
    /* 662D4 80075AD4 40100300 */  sll        $v0, $v1, 1
    /* 662D8 80075AD8 21104300 */  addu       $v0, $v0, $v1
    /* 662DC 80075ADC 80100200 */  sll        $v0, $v0, 2
    /* 662E0 80075AE0 21104300 */  addu       $v0, $v0, $v1
    /* 662E4 80075AE4 0400A2AF */  sw         $v0, 0x4($sp)
    /* 662E8 80075AE8 0000A28F */  lw         $v0, 0x0($sp)
    /* 662EC 80075AEC 00000000 */  nop
    /* 662F0 80075AF0 01004224 */  addiu      $v0, $v0, 0x1
    /* 662F4 80075AF4 0000A2AF */  sw         $v0, 0x0($sp)
  .L80075AF8:
    /* 662F8 80075AF8 0000A28F */  lw         $v0, 0x0($sp)
    /* 662FC 80075AFC 00000000 */  nop
    /* 66300 80075B00 3C004228 */  slti       $v0, $v0, 0x3C
    /* 66304 80075B04 F1FF4014 */  bnez       $v0, .L80075ACC
    /* 66308 80075B08 00000000 */   nop
    /* 6630C 80075B0C 0800E003 */  jr         $ra
    /* 66310 80075B10 0800BD27 */   addiu     $sp, $sp, 0x8
endlabel func_80075AB8
    /* 66314 80075B14 00000000 */  nop
    /* 66318 80075B18 00000000 */  nop
    /* 6631C 80075B1C 00000000 */  nop
