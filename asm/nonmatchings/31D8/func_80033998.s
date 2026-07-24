nonmatching func_80033998, 0x38

glabel func_80033998
    /* 24198 80033998 F403828F */  lw         $v0, %gp_rel(D_8009B2FC)($gp)
    /* 2419C 8003399C 21200000 */  addu       $a0, $zero, $zero
    /* 241A0 800339A0 502D4324 */  addiu      $v1, $v0, 0x2D50
  .L800339A4:
    /* 241A4 800339A4 0D006290 */  lbu        $v0, 0xD($v1)
    /* 241A8 800339A8 00000000 */  nop
    /* 241AC 800339AC 03004014 */  bnez       $v0, .L800339BC
    /* 241B0 800339B0 01008424 */   addiu     $a0, $a0, 0x1
    /* 241B4 800339B4 0800E003 */  jr         $ra
    /* 241B8 800339B8 01000224 */   addiu     $v0, $zero, 0x1
  .L800339BC:
    /* 241BC 800339BC 28008228 */  slti       $v0, $a0, 0x28
    /* 241C0 800339C0 F8FF4014 */  bnez       $v0, .L800339A4
    /* 241C4 800339C4 10006324 */   addiu     $v1, $v1, 0x10
    /* 241C8 800339C8 0800E003 */  jr         $ra
    /* 241CC 800339CC 21100000 */   addu      $v0, $zero, $zero
endlabel func_80033998
