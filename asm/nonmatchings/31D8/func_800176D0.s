nonmatching func_800176D0, 0x38

glabel func_800176D0
    /* 7ED0 800176D0 0F80023C */  lui        $v0, %hi(D_800EA030)
    /* 7ED4 800176D4 30A04424 */  addiu      $a0, $v0, %lo(D_800EA030)
    /* 7ED8 800176D8 21280000 */  addu       $a1, $zero, $zero
    /* 7EDC 800176DC 09008324 */  addiu      $v1, $a0, 0x9
  .L800176E0:
    /* 7EE0 800176E0 FBFF60AC */  sw         $zero, -0x5($v1)
    /* 7EE4 800176E4 000080AC */  sw         $zero, 0x0($a0)
    /* 7EE8 800176E8 000060A0 */  sb         $zero, 0x0($v1)
    /* 7EEC 800176EC 0C006324 */  addiu      $v1, $v1, 0xC
    /* 7EF0 800176F0 0100A524 */  addiu      $a1, $a1, 0x1
    /* 7EF4 800176F4 0500A228 */  slti       $v0, $a1, 0x5
    /* 7EF8 800176F8 F9FF4014 */  bnez       $v0, .L800176E0
    /* 7EFC 800176FC 0C008424 */   addiu     $a0, $a0, 0xC
    /* 7F00 80017700 0800E003 */  jr         $ra
    /* 7F04 80017704 00000000 */   nop
endlabel func_800176D0
