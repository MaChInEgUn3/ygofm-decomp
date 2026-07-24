nonmatching func_80040410, 0x14

glabel func_80040410
    /* 30C10 80040410 08008294 */  lhu        $v0, 0x8($a0)
    /* 30C14 80040414 690085A0 */  sb         $a1, 0x69($a0)
    /* 30C18 80040418 EFFF4230 */  andi       $v0, $v0, 0xFFEF
    /* 30C1C 8004041C 0800E003 */  jr         $ra
    /* 30C20 80040420 080082A4 */   sh        $v0, 0x8($a0)
endlabel func_80040410
