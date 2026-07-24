nonmatching func_8002CB50, 0x30

glabel func_8002CB50
    /* 1D350 8002CB50 21280000 */  addu       $a1, $zero, $zero
    /* 1D354 8002CB54 0F80023C */  lui        $v0, %hi(D_800E9EF0)
    /* 1D358 8002CB58 F09E4324 */  addiu      $v1, $v0, %lo(D_800E9EF0)
  .L8002CB5C:
    /* 1D35C 8002CB5C 0000628C */  lw         $v0, 0x0($v1)
    /* 1D360 8002CB60 04006324 */  addiu      $v1, $v1, 0x4
    /* 1D364 8002CB64 0100A524 */  addiu      $a1, $a1, 0x1
    /* 1D368 8002CB68 000082AC */  sw         $v0, 0x0($a0)
    /* 1D36C 8002CB6C 0500A228 */  slti       $v0, $a1, 0x5
    /* 1D370 8002CB70 FAFF4014 */  bnez       $v0, .L8002CB5C
    /* 1D374 8002CB74 04008424 */   addiu     $a0, $a0, 0x4
    /* 1D378 8002CB78 0800E003 */  jr         $ra
    /* 1D37C 8002CB7C 000080AC */   sw        $zero, 0x0($a0)
endlabel func_8002CB50
