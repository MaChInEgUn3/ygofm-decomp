nonmatching func_8005B620, 0x2C

glabel func_8005B620
    /* 4BE20 8005B620 0800C010 */  beqz       $a2, .L8005B644
    /* 4BE24 8005B624 FFFFC324 */   addiu     $v1, $a2, -0x1
    /* 4BE28 8005B628 FFFF0624 */  addiu      $a2, $zero, -0x1
  .L8005B62C:
    /* 4BE2C 8005B62C 0000A28C */  lw         $v0, 0x0($a1)
    /* 4BE30 8005B630 0400A524 */  addiu      $a1, $a1, 0x4
    /* 4BE34 8005B634 FFFF6324 */  addiu      $v1, $v1, -0x1
    /* 4BE38 8005B638 000082AC */  sw         $v0, 0x0($a0)
    /* 4BE3C 8005B63C FBFF6614 */  bne        $v1, $a2, .L8005B62C
    /* 4BE40 8005B640 04008424 */   addiu     $a0, $a0, 0x4
  .L8005B644:
    /* 4BE44 8005B644 0800E003 */  jr         $ra
    /* 4BE48 8005B648 00000000 */   nop
endlabel func_8005B620
