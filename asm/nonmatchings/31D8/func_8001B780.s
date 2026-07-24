nonmatching func_8001B780, 0x2C

glabel func_8001B780
    /* BF80 8001B780 0E008380 */  lb         $v1, 0xE($a0)
    /* BF84 8001B784 00000000 */  nop
    /* BF88 8001B788 00110300 */  sll        $v0, $v1, 4
    /* BF8C 8001B78C 23104300 */  subu       $v0, $v0, $v1
    /* BF90 8001B790 80100200 */  sll        $v0, $v0, 2
    /* BF94 8001B794 0400838C */  lw         $v1, 0x4($a0)
    /* BF98 8001B798 0E004224 */  addiu      $v0, $v0, 0xE
    /* BF9C 8001B79C 300062A4 */  sh         $v0, 0x30($v1)
    /* BFA0 8001B7A0 C2000224 */  addiu      $v0, $zero, 0xC2
    /* BFA4 8001B7A4 0800E003 */  jr         $ra
    /* BFA8 8001B7A8 320062A4 */   sh        $v0, 0x32($v1)
endlabel func_8001B780
