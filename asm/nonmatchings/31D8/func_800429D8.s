nonmatching func_800429D8, 0x28

glabel func_800429D8
    /* 331D8 800429D8 07008010 */  beqz       $a0, .L800429F8
    /* 331DC 800429DC 80000224 */   addiu     $v0, $zero, 0x80
    /* 331E0 800429E0 360080A4 */  sh         $zero, 0x36($a0)
    /* 331E4 800429E4 380080A4 */  sh         $zero, 0x38($a0)
    /* 331E8 800429E8 3A0080A4 */  sh         $zero, 0x3A($a0)
    /* 331EC 800429EC 620082A0 */  sb         $v0, 0x62($a0)
    /* 331F0 800429F0 630082A0 */  sb         $v0, 0x63($a0)
    /* 331F4 800429F4 640082A0 */  sb         $v0, 0x64($a0)
  .L800429F8:
    /* 331F8 800429F8 0800E003 */  jr         $ra
    /* 331FC 800429FC 00000000 */   nop
endlabel func_800429D8
