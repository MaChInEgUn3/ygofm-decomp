nonmatching func_80039FF8, 0x24

glabel func_80039FF8
    /* 2A7F8 80039FF8 32008390 */  lbu        $v1, 0x32($a0)
    /* 2A7FC 80039FFC 00000000 */  nop
    /* 2A800 8003A000 03006230 */  andi       $v0, $v1, 0x3
    /* 2A804 8003A004 03004014 */  bnez       $v0, .L8003A014
    /* 2A808 8003A008 10006234 */   ori       $v0, $v1, 0x10
    /* 2A80C 8003A00C 320082A0 */  sb         $v0, 0x32($a0)
    /* 2A810 8003A010 330080A0 */  sb         $zero, 0x33($a0)
  .L8003A014:
    /* 2A814 8003A014 0800E003 */  jr         $ra
    /* 2A818 8003A018 00000000 */   nop
endlabel func_80039FF8
