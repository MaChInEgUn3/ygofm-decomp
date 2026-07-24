nonmatching func_8002EE5C, 0x38

glabel func_8002EE5C
    /* 1F65C 8002EE5C 1D80023C */  lui        $v0, %hi(D_801D0200)
    /* 1F660 8002EE60 00024424 */  addiu      $a0, $v0, %lo(D_801D0200)
    /* 1F664 8002EE64 21180000 */  addu       $v1, $zero, $zero
  .L8002EE68:
    /* 1F668 8002EE68 00008294 */  lhu        $v0, 0x0($a0)
    /* 1F66C 8002EE6C 00000000 */  nop
    /* 1F670 8002EE70 03004014 */  bnez       $v0, .L8002EE80
    /* 1F674 8002EE74 01006324 */   addiu     $v1, $v1, 0x1
    /* 1F678 8002EE78 0800E003 */  jr         $ra
    /* 1F67C 8002EE7C 21100000 */   addu      $v0, $zero, $zero
  .L8002EE80:
    /* 1F680 8002EE80 28006228 */  slti       $v0, $v1, 0x28
    /* 1F684 8002EE84 F8FF4014 */  bnez       $v0, .L8002EE68
    /* 1F688 8002EE88 02008424 */   addiu     $a0, $a0, 0x2
    /* 1F68C 8002EE8C 0800E003 */  jr         $ra
    /* 1F690 8002EE90 01000224 */   addiu     $v0, $zero, 0x1
endlabel func_8002EE5C
