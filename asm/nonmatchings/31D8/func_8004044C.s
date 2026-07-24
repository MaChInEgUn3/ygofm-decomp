nonmatching func_8004044C, 0x1C

glabel func_8004044C
    /* 30C4C 8004044C 08008294 */  lhu        $v0, 0x8($a0)
    /* 30C50 80040450 670085A0 */  sb         $a1, 0x67($a0)
    /* 30C54 80040454 680086A0 */  sb         $a2, 0x68($a0)
    /* 30C58 80040458 690087A0 */  sb         $a3, 0x69($a0)
    /* 30C5C 8004045C EFFF4230 */  andi       $v0, $v0, 0xFFEF
    /* 30C60 80040460 0800E003 */  jr         $ra
    /* 30C64 80040464 080082A4 */   sh        $v0, 0x8($a0)
endlabel func_8004044C
