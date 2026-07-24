nonmatching func_800156B8, 0x24

glabel func_800156B8
    /* 5EB8 800156B8 0F80023C */  lui        $v0, %hi(D_800E9EC8)
    /* 5EBC 800156BC C89E4524 */  addiu      $a1, $v0, %lo(D_800E9EC8)
    /* 5EC0 800156C0 1D000324 */  addiu      $v1, $zero, 0x1D
  .L800156C4:
    /* 5EC4 800156C4 2110A300 */  addu       $v0, $a1, $v1
    /* 5EC8 800156C8 FFFF6324 */  addiu      $v1, $v1, -0x1
    /* 5ECC 800156CC FDFF6104 */  bgez       $v1, .L800156C4
    /* 5ED0 800156D0 0A0044A0 */   sb        $a0, 0xA($v0)
    /* 5ED4 800156D4 0800E003 */  jr         $ra
    /* 5ED8 800156D8 00000000 */   nop
endlabel func_800156B8
