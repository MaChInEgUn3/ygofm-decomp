nonmatching func_8005F564, 0x24

glabel func_8005F564
    /* 4FD64 8005F564 72018383 */  lb         $v1, %gp_rel(D_8009B07A)($gp)
    /* 4FD68 8005F568 72018293 */  lbu        $v0, %gp_rel(D_8009B07A)($gp)
    /* 4FD6C 8005F56C 04006004 */  bltz       $v1, .L8005F580
    /* 4FD70 8005F570 01004224 */   addiu     $v0, $v0, 0x1
    /* 4FD74 8005F574 720182A3 */  sb         $v0, %gp_rel(D_8009B07A)($gp)
    /* 4FD78 8005F578 0800E003 */  jr         $ra
    /* 4FD7C 8005F57C 2A100300 */   slt       $v0, $zero, $v1
  .L8005F580:
    /* 4FD80 8005F580 0800E003 */  jr         $ra
    /* 4FD84 8005F584 21100000 */   addu      $v0, $zero, $zero
endlabel func_8005F564
