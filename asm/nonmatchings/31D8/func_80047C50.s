nonmatching func_80047C50, 0x20

glabel func_80047C50
    /* 38450 80047C50 21108000 */  addu       $v0, $a0, $zero
    /* 38454 80047C54 00808430 */  andi       $a0, $a0, 0x8000
    /* 38458 80047C58 03008014 */  bnez       $a0, .L80047C68
    /* 3845C 80047C5C 00000000 */   nop
    /* 38460 80047C60 0800E003 */  jr         $ra
    /* 38464 80047C64 FFFF0234 */   ori       $v0, $zero, 0xFFFF
  .L80047C68:
    /* 38468 80047C68 0800E003 */  jr         $ra
    /* 3846C 80047C6C FFFF4230 */   andi      $v0, $v0, 0xFFFF
endlabel func_80047C50
