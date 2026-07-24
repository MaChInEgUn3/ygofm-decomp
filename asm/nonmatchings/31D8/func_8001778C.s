nonmatching func_8001778C, 0x38

glabel func_8001778C
    /* 7F8C 8001778C 1A80023C */  lui        $v0, %hi(D_801A7AD8)
    /* 7F90 80017790 D87A4424 */  addiu      $a0, $v0, %lo(D_801A7AD8)
    /* 7F94 80017794 21280000 */  addu       $a1, $zero, $zero
    /* 7F98 80017798 16008324 */  addiu      $v1, $a0, 0x16
  .L8001779C:
    /* 7F9C 8001779C 000080AC */  sw         $zero, 0x0($a0)
    /* 7FA0 800177A0 EEFF60AC */  sw         $zero, -0x12($v1)
    /* 7FA4 800177A4 000060A4 */  sh         $zero, 0x0($v1)
    /* 7FA8 800177A8 1C006324 */  addiu      $v1, $v1, 0x1C
    /* 7FAC 800177AC 0100A524 */  addiu      $a1, $a1, 0x1
    /* 7FB0 800177B0 1E00A228 */  slti       $v0, $a1, 0x1E
    /* 7FB4 800177B4 F9FF4014 */  bnez       $v0, .L8001779C
    /* 7FB8 800177B8 1C008424 */   addiu     $a0, $a0, 0x1C
    /* 7FBC 800177BC 0800E003 */  jr         $ra
    /* 7FC0 800177C0 00000000 */   nop
endlabel func_8001778C
