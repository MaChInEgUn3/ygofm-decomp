nonmatching func_8005B5FC, 0x24

glabel func_8005B5FC
    /* 4BDFC 8005B5FC 0600C010 */  beqz       $a2, .L8005B618
    /* 4BE00 8005B600 FFFFC224 */   addiu     $v0, $a2, -0x1
    /* 4BE04 8005B604 FFFF0324 */  addiu      $v1, $zero, -0x1
  .L8005B608:
    /* 4BE08 8005B608 000085AC */  sw         $a1, 0x0($a0)
    /* 4BE0C 8005B60C FFFF4224 */  addiu      $v0, $v0, -0x1
    /* 4BE10 8005B610 FDFF4314 */  bne        $v0, $v1, .L8005B608
    /* 4BE14 8005B614 04008424 */   addiu     $a0, $a0, 0x4
  .L8005B618:
    /* 4BE18 8005B618 0800E003 */  jr         $ra
    /* 4BE1C 8005B61C 00000000 */   nop
endlabel func_8005B5FC
