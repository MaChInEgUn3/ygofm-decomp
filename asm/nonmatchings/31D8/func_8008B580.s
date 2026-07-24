nonmatching func_8008B580, 0x44

glabel func_8008B580
    /* 7BD80 8008B580 7410628C */  lw         $v0, 0x1074($v1)
    /* 7BD84 8008B584 00000000 */  nop
    /* 7BD88 8008B588 80004230 */  andi       $v0, $v0, 0x80
    /* 7BD8C 8008B58C 0B004010 */  beqz       $v0, .L8008B5BC
    /* 7BD90 8008B590 00000000 */   nop
  .L8008B594:
    /* 7BD94 8008B594 4410628C */  lw         $v0, 0x1044($v1)
    /* 7BD98 8008B598 00000000 */  nop
    /* 7BD9C 8008B59C 80004230 */  andi       $v0, $v0, 0x80
    /* 7BDA0 8008B5A0 FCFF4014 */  bnez       $v0, .L8008B594
    /* 7BDA4 8008B5A4 00000000 */   nop
    /* 7BDA8 8008B5A8 0100023C */  lui        $v0, (0x10000 >> 16)
    /* 7BDAC 8008B5AC FCDF428C */  lw         $v0, -0x2004($v0)
    /* 7BDB0 8008B5B0 00000000 */  nop
    /* 7BDB4 8008B5B4 08004000 */  jr         $v0
    /* 7BDB8 8008B5B8 00000000 */   nop
  .L8008B5BC:
    /* 7BDBC 8008B5BC 0800E003 */  jr         $ra
    /* 7BDC0 8008B5C0 00000000 */   nop
endlabel func_8008B580
