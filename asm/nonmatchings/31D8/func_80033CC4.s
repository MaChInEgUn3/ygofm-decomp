nonmatching func_80033CC4, 0x34

glabel func_80033CC4
    /* 244C4 80033CC4 0980023C */  lui        $v0, %hi(D_80090DD8)
    /* 244C8 80033CC8 D80D4224 */  addiu      $v0, $v0, %lo(D_80090DD8)
    /* 244CC 80033CCC 472D8590 */  lbu        $a1, 0x2D47($a0)
    /* 244D0 80033CD0 462D8380 */  lb         $v1, 0x2D46($a0)
    /* 244D4 80033CD4 00290500 */  sll        $a1, $a1, 4
    /* 244D8 80033CD8 40180300 */  sll        $v1, $v1, 1
    /* 244DC 80033CDC 21186200 */  addu       $v1, $v1, $v0
    /* 244E0 80033CE0 2128A300 */  addu       $a1, $a1, $v1
    /* 244E4 80033CE4 0100A290 */  lbu        $v0, 0x1($a1)
    /* 244E8 80033CE8 00000000 */  nop
    /* 244EC 80033CEC 0F004230 */  andi       $v0, $v0, 0xF
    /* 244F0 80033CF0 0800E003 */  jr         $ra
    /* 244F4 80033CF4 452D82A0 */   sb        $v0, 0x2D45($a0)
endlabel func_80033CC4
