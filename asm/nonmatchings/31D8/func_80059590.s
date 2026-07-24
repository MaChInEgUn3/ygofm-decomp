nonmatching func_80059590, 0x38

glabel func_80059590
    /* 49D90 80059590 C0100400 */  sll        $v0, $a0, 3
    /* 49D94 80059594 23104400 */  subu       $v0, $v0, $a0
    /* 49D98 80059598 00110200 */  sll        $v0, $v0, 4
    /* 49D9C 8005959C 21104400 */  addu       $v0, $v0, $a0
    /* 49DA0 800595A0 40110200 */  sll        $v0, $v0, 5
    /* 49DA4 800595A4 0F80033C */  lui        $v1, %hi(D_800F2C40)
    /* 49DA8 800595A8 402C6324 */  addiu      $v1, $v1, %lo(D_800F2C40)
    /* 49DAC 800595AC 1000A48F */  lw         $a0, 0x10($sp)
    /* 49DB0 800595B0 21104300 */  addu       $v0, $v0, $v1
    /* 49DB4 800595B4 C30D45A0 */  sb         $a1, 0xDC3($v0)
    /* 49DB8 800595B8 C00D46A0 */  sb         $a2, 0xDC0($v0)
    /* 49DBC 800595BC C10D47A0 */  sb         $a3, 0xDC1($v0)
    /* 49DC0 800595C0 0800E003 */  jr         $ra
    /* 49DC4 800595C4 C20D44A0 */   sb        $a0, 0xDC2($v0)
endlabel func_80059590
