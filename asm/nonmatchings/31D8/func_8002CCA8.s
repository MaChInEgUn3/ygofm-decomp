nonmatching func_8002CCA8, 0x3C

glabel func_8002CCA8
    /* 1D4A8 8002CCA8 FF078330 */  andi       $v1, $a0, 0x7FF
    /* 1D4AC 8002CCAC C3180300 */  sra        $v1, $v1, 3
    /* 1D4B0 8002CCB0 07008630 */  andi       $a2, $a0, 0x7
    /* 1D4B4 8002CCB4 80000524 */  addiu      $a1, $zero, 0x80
    /* 1D4B8 8002CCB8 1D80023C */  lui        $v0, %hi(D_801D0000)
    /* 1D4BC 8002CCBC 00004224 */  addiu      $v0, $v0, %lo(D_801D0000)
    /* 1D4C0 8002CCC0 21186200 */  addu       $v1, $v1, $v0
    /* 1D4C4 8002CCC4 18066290 */  lbu        $v0, 0x618($v1)
    /* 1D4C8 8002CCC8 0728C500 */  srav       $a1, $a1, $a2
    /* 1D4CC 8002CCCC 00808430 */  andi       $a0, $a0, 0x8000
    /* 1D4D0 8002CCD0 02008010 */  beqz       $a0, .L8002CCDC
    /* 1D4D4 8002CCD4 24104500 */   and       $v0, $v0, $a1
    /* 1D4D8 8002CCD8 0100422C */  sltiu      $v0, $v0, 0x1
  .L8002CCDC:
    /* 1D4DC 8002CCDC 0800E003 */  jr         $ra
    /* 1D4E0 8002CCE0 00000000 */   nop
endlabel func_8002CCA8
