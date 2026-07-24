nonmatching func_8008FA80, 0x6C

glabel func_8008FA80
    /* 80280 8008FA80 21388000 */  addu       $a3, $a0, $zero
    /* 80284 8008FA84 2B10E500 */  sltu       $v0, $a3, $a1
    /* 80288 8008FA88 0C004014 */  bnez       $v0, .L8008FABC
    /* 8028C 8008FA8C 2110C000 */   addu      $v0, $a2, $zero
    /* 80290 8008FA90 13004018 */  blez       $v0, .L8008FAE0
    /* 80294 8008FA94 FFFFC624 */   addiu     $a2, $a2, -0x1
  .L8008FA98:
    /* 80298 8008FA98 2120E600 */  addu       $a0, $a3, $a2
    /* 8029C 8008FA9C 2110A600 */  addu       $v0, $a1, $a2
    /* 802A0 8008FAA0 2118C000 */  addu       $v1, $a2, $zero
    /* 802A4 8008FAA4 00004290 */  lbu        $v0, 0x0($v0)
    /* 802A8 8008FAA8 FFFFC624 */  addiu      $a2, $a2, -0x1
    /* 802AC 8008FAAC FAFF601C */  bgtz       $v1, .L8008FA98
    /* 802B0 8008FAB0 000082A0 */   sb        $v0, 0x0($a0)
    /* 802B4 8008FAB4 B93E0208 */  j          .L8008FAE4
    /* 802B8 8008FAB8 2110E000 */   addu      $v0, $a3, $zero
  .L8008FABC:
    /* 802BC 8008FABC 08004018 */  blez       $v0, .L8008FAE0
    /* 802C0 8008FAC0 FFFFC624 */   addiu     $a2, $a2, -0x1
  .L8008FAC4:
    /* 802C4 8008FAC4 0000A290 */  lbu        $v0, 0x0($a1)
    /* 802C8 8008FAC8 0100A524 */  addiu      $a1, $a1, 0x1
    /* 802CC 8008FACC 2118C000 */  addu       $v1, $a2, $zero
    /* 802D0 8008FAD0 FFFFC624 */  addiu      $a2, $a2, -0x1
    /* 802D4 8008FAD4 0000E2A0 */  sb         $v0, 0x0($a3)
    /* 802D8 8008FAD8 FAFF601C */  bgtz       $v1, .L8008FAC4
    /* 802DC 8008FADC 0100E724 */   addiu     $a3, $a3, 0x1
  .L8008FAE0:
    /* 802E0 8008FAE0 2110E000 */  addu       $v0, $a3, $zero
  .L8008FAE4:
    /* 802E4 8008FAE4 0800E003 */  jr         $ra
    /* 802E8 8008FAE8 00000000 */   nop
endlabel func_8008FA80
    /* 802EC 8008FAEC 00000000 */  nop
