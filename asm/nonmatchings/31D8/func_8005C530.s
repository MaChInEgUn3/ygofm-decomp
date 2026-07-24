nonmatching func_8005C530, 0x38

glabel func_8005C530
    /* 4CD30 8005C530 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 4CD34 8005C534 1400BFAF */  sw         $ra, 0x14($sp)
    /* 4CD38 8005C538 8F6F010C */  jal        func_8005BE3C
    /* 4CD3C 8005C53C 1000B0AF */   sw        $s0, 0x10($sp)
    /* 4CD40 8005C540 21804000 */  addu       $s0, $v0, $zero
    /* 4CD44 8005C544 04000012 */  beqz       $s0, .L8005C558
    /* 4CD48 8005C548 21100002 */   addu      $v0, $s0, $zero
    /* 4CD4C 8005C54C DF6E010C */  jal        func_8005BB7C
    /* 4CD50 8005C550 21200000 */   addu      $a0, $zero, $zero
    /* 4CD54 8005C554 21100002 */  addu       $v0, $s0, $zero
  .L8005C558:
    /* 4CD58 8005C558 1400BF8F */  lw         $ra, 0x14($sp)
    /* 4CD5C 8005C55C 1000B08F */  lw         $s0, 0x10($sp)
    /* 4CD60 8005C560 0800E003 */  jr         $ra
    /* 4CD64 8005C564 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8005C530
