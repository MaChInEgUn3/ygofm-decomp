nonmatching func_8003B7E0, 0x28

glabel func_8003B7E0
    /* 2BFE0 8003B7E0 58008280 */  lb         $v0, 0x58($a0)
    /* 2BFE4 8003B7E4 00000000 */  nop
    /* 2BFE8 8003B7E8 80100200 */  sll        $v0, $v0, 2
    /* 2BFEC 8003B7EC 21208200 */  addu       $a0, $a0, $v0
    /* 2BFF0 8003B7F0 0000838C */  lw         $v1, 0x0($a0)
    /* 2BFF4 8003B7F4 00000000 */  nop
    /* 2BFF8 8003B7F8 00006290 */  lbu        $v0, 0x0($v1)
    /* 2BFFC 8003B7FC 01006324 */  addiu      $v1, $v1, 0x1
    /* 2C000 8003B800 0800E003 */  jr         $ra
    /* 2C004 8003B804 000083AC */   sw        $v1, 0x0($a0)
endlabel func_8003B7E0
