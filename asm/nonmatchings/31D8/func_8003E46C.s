nonmatching func_8003E46C, 0x24

glabel func_8003E46C
    /* 2EC6C 8003E46C F2048297 */  lhu        $v0, %gp_rel(D_8009B3FA)($gp)
    /* 2EC70 8003E470 8000A534 */  ori        $a1, $a1, 0x80
    /* 2EC74 8003E474 BE0484A3 */  sb         $a0, %gp_rel(D_8009B3C6)($gp)
    /* 2EC78 8003E478 87FF4230 */  andi       $v0, $v0, 0xFF87
    /* 2EC7C 8003E47C F20482A7 */  sh         $v0, %gp_rel(D_8009B3FA)($gp)
    /* 2EC80 8003E480 25104500 */  or         $v0, $v0, $a1
    /* 2EC84 8003E484 F20482A7 */  sh         $v0, %gp_rel(D_8009B3FA)($gp)
    /* 2EC88 8003E488 0800E003 */  jr         $ra
    /* 2EC8C 8003E48C 00000000 */   nop
endlabel func_8003E46C
