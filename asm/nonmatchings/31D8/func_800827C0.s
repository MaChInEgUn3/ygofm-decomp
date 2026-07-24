nonmatching func_800827C0, 0x18

glabel func_800827C0
    /* 72FC0 800827C0 80110500 */  sll        $v0, $a1, 6
    /* 72FC4 800827C4 03210400 */  sra        $a0, $a0, 4
    /* 72FC8 800827C8 3F008430 */  andi       $a0, $a0, 0x3F
    /* 72FCC 800827CC 25104400 */  or         $v0, $v0, $a0
    /* 72FD0 800827D0 0800E003 */  jr         $ra
    /* 72FD4 800827D4 FFFF4230 */   andi      $v0, $v0, 0xFFFF
endlabel func_800827C0
    /* 72FD8 800827D8 00000000 */  nop
    /* 72FDC 800827DC 00000000 */  nop
