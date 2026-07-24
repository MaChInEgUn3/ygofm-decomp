nonmatching func_8002EDB0, 0x70

glabel func_8002EDB0
    /* 1F5B0 8002EDB0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1F5B4 8002EDB4 1400BFAF */  sw         $ra, 0x14($sp)
    /* 1F5B8 8002EDB8 EDB8000C */  jal        func_8002E3B4
    /* 1F5BC 8002EDBC 1000B0AF */   sw        $s0, 0x10($sp)
    /* 1F5C0 8002EDC0 12004014 */  bnez       $v0, .L8002EE0C
    /* 1F5C4 8002EDC4 00000000 */   nop
    /* 1F5C8 8002EDC8 8803828F */  lw         $v0, %gp_rel(D_8009B290)($gp)
    /* 1F5CC 8002EDCC 00000000 */  nop
    /* 1F5D0 8002EDD0 00004390 */  lbu        $v1, 0x0($v0)
    /* 1F5D4 8002EDD4 01004224 */  addiu      $v0, $v0, 0x1
    /* 1F5D8 8002EDD8 880382AF */  sw         $v0, %gp_rel(D_8009B290)($gp)
    /* 1F5DC 8002EDDC 7F006430 */  andi       $a0, $v1, 0x7F
    /* 1F5E0 8002EDE0 05008014 */  bnez       $a0, .L8002EDF8
    /* 1F5E4 8002EDE4 21806000 */   addu      $s0, $v1, $zero
    /* 1F5E8 8002EDE8 CDFF000C */  jal        func_8003FF34
    /* 1F5EC 8002EDEC 00000000 */   nop
    /* 1F5F0 8002EDF0 81BB0008 */  j          .L8002EE04
    /* 1F5F4 8002EDF4 80000232 */   andi      $v0, $s0, 0x80
  .L8002EDF8:
    /* 1F5F8 8002EDF8 D6FF000C */  jal        func_8003FF58
    /* 1F5FC 8002EDFC 00000000 */   nop
    /* 1F600 8002EE00 80000232 */  andi       $v0, $s0, 0x80
  .L8002EE04:
    /* 1F604 8002EE04 02004014 */  bnez       $v0, .L8002EE10
    /* 1F608 8002EE08 00000000 */   nop
  .L8002EE0C:
    /* 1F60C 8002EE0C 740380A7 */  sh         $zero, %gp_rel(D_8009B27C)($gp)
  .L8002EE10:
    /* 1F610 8002EE10 1400BF8F */  lw         $ra, 0x14($sp)
    /* 1F614 8002EE14 1000B08F */  lw         $s0, 0x10($sp)
    /* 1F618 8002EE18 0800E003 */  jr         $ra
    /* 1F61C 8002EE1C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8002EDB0
