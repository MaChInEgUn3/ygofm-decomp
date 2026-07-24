nonmatching func_80058E1C, 0x20

glabel func_80058E1C
    /* 4961C 80058E1C 9B008293 */  lbu        $v0, %gp_rel(D_8009AFA3)($gp)
    /* 49620 80058E20 06000324 */  addiu      $v1, $zero, 0x6
    /* 49624 80058E24 2B104300 */  sltu       $v0, $v0, $v1
    /* 49628 80058E28 02004010 */  beqz       $v0, .L80058E34
    /* 4962C 80058E2C 00000000 */   nop
    /* 49630 80058E30 9B008393 */  lbu        $v1, %gp_rel(D_8009AFA3)($gp)
  .L80058E34:
    /* 49634 80058E34 0800E003 */  jr         $ra
    /* 49638 80058E38 21106000 */   addu      $v0, $v1, $zero
endlabel func_80058E1C
