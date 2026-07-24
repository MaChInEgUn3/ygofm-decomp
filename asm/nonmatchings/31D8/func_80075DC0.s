nonmatching func_80075DC0, 0x20

glabel func_80075DC0
    /* 665C0 80075DC0 0980023C */  lui        $v0, %hi(D_80092B88)
    /* 665C4 80075DC4 882B428C */  lw         $v0, %lo(D_80092B88)($v0)
    /* 665C8 80075DC8 00000000 */  nop
    /* 665CC 80075DCC AA014294 */  lhu        $v0, 0x1AA($v0)
    /* 665D0 80075DD0 00000000 */  nop
    /* 665D4 80075DD4 80004230 */  andi       $v0, $v0, 0x80
    /* 665D8 80075DD8 0800E003 */  jr         $ra
    /* 665DC 80075DDC 2B100200 */   sltu      $v0, $zero, $v0
endlabel func_80075DC0
