nonmatching func_8002E6B8, 0x78

glabel func_8002E6B8
    /* 1EEB8 8002E6B8 8803868F */  lw         $a2, %gp_rel(D_8009B290)($gp)
    /* 1EEBC 8002E6BC A20380A7 */  sh         $zero, %gp_rel(D_8009B2AA)($gp)
    /* 1EEC0 8002E6C0 A00380A7 */  sh         $zero, %gp_rel(D_8009B2A8)($gp)
    /* 1EEC4 8002E6C4 0200C724 */  addiu      $a3, $a2, 0x2
    /* 1EEC8 8002E6C8 880387AF */  sw         $a3, %gp_rel(D_8009B290)($gp)
    /* 1EECC 8002E6CC 0100C390 */  lbu        $v1, 0x1($a2)
    /* 1EED0 8002E6D0 0000C290 */  lbu        $v0, 0x0($a2)
    /* 1EED4 8002E6D4 001A0300 */  sll        $v1, $v1, 8
    /* 1EED8 8002E6D8 25104300 */  or         $v0, $v0, $v1
    /* 1EEDC 8002E6DC 680382A7 */  sh         $v0, %gp_rel(D_8009B270)($gp)
    /* 1EEE0 8002E6E0 00804230 */  andi       $v0, $v0, 0x8000
    /* 1EEE4 8002E6E4 0E004010 */  beqz       $v0, .L8002E720
    /* 1EEE8 8002E6E8 0400C524 */   addiu     $a1, $a2, 0x4
    /* 1EEEC 8002E6EC 880385AF */  sw         $a1, %gp_rel(D_8009B290)($gp)
    /* 1EEF0 8002E6F0 0200C490 */  lbu        $a0, 0x2($a2)
    /* 1EEF4 8002E6F4 0100E290 */  lbu        $v0, 0x1($a3)
    /* 1EEF8 8002E6F8 0600C324 */  addiu      $v1, $a2, 0x6
    /* 1EEFC 8002E6FC 880383AF */  sw         $v1, %gp_rel(D_8009B290)($gp)
    /* 1EF00 8002E700 00120200 */  sll        $v0, $v0, 8
    /* 1EF04 8002E704 25208200 */  or         $a0, $a0, $v0
    /* 1EF08 8002E708 A00384A7 */  sh         $a0, %gp_rel(D_8009B2A8)($gp)
    /* 1EF0C 8002E70C 0100A290 */  lbu        $v0, 0x1($a1)
    /* 1EF10 8002E710 0400C390 */  lbu        $v1, 0x4($a2)
    /* 1EF14 8002E714 00120200 */  sll        $v0, $v0, 8
    /* 1EF18 8002E718 25186200 */  or         $v1, $v1, $v0
    /* 1EF1C 8002E71C A20383A7 */  sh         $v1, %gp_rel(D_8009B2AA)($gp)
  .L8002E720:
    /* 1EF20 8002E720 05000224 */  addiu      $v0, $zero, 0x5
    /* 1EF24 8002E724 740382A7 */  sh         $v0, %gp_rel(D_8009B27C)($gp)
    /* 1EF28 8002E728 0800E003 */  jr         $ra
    /* 1EF2C 8002E72C 00000000 */   nop
endlabel func_8002E6B8
