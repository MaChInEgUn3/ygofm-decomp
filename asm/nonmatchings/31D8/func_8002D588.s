nonmatching func_8002D588, 0xA4

glabel func_8002D588
    /* 1DD88 8002D588 64038393 */  lbu        $v1, %gp_rel(D_8009B26C)($gp)
    /* 1DD8C 8002D58C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1DD90 8002D590 1400BFAF */  sw         $ra, 0x14($sp)
    /* 1DD94 8002D594 40006230 */  andi       $v0, $v1, 0x40
    /* 1DD98 8002D598 0F004014 */  bnez       $v0, .L8002D5D8
    /* 1DD9C 8002D59C 1000B0AF */   sw        $s0, 0x10($sp)
    /* 1DDA0 8002D5A0 40006234 */  ori        $v0, $v1, 0x40
    /* 1DDA4 8002D5A4 640382A3 */  sb         $v0, %gp_rel(D_8009B26C)($gp)
    /* 1DDA8 8002D5A8 176E010C */  jal        func_8005B85C
    /* 1DDAC 8002D5AC 00000000 */   nop
    /* 1DDB0 8002D5B0 F94D000C */  jal        func_800137E4
    /* 1DDB4 8002D5B4 00000000 */   nop
    /* 1DDB8 8002D5B8 A7E7000C */  jal        func_80039E9C
    /* 1DDBC 8002D5BC 00000000 */   nop
    /* 1DDC0 8002D5C0 60038493 */  lbu        $a0, %gp_rel(D_8009B268)($gp)
    /* 1DDC4 8002D5C4 65038593 */  lbu        $a1, %gp_rel(D_8009B26D)($gp)
    /* 1DDC8 8002D5C8 0700060C */  jal        func_8018001C
    /* 1DDCC 8002D5CC 00000000 */   nop
    /* 1DDD0 8002D5D0 8056000C */  jal        func_80015A00
    /* 1DDD4 8002D5D4 00000000 */   nop
  .L8002D5D8:
    /* 1DDD8 8002D5D8 6439020C */  jal        func_8008E590
    /* 1DDDC 8002D5DC 00000000 */   nop
    /* 1DDE0 8002D5E0 E400060C */  jal        func_80180390
    /* 1DDE4 8002D5E4 00000000 */   nop
    /* 1DDE8 8002D5E8 21804000 */  addu       $s0, $v0, $zero
    /* 1DDEC 8002D5EC 0B000006 */  bltz       $s0, .L8002D61C
    /* 1DDF0 8002D5F0 00000000 */   nop
    /* 1DDF4 8002D5F4 CDFF000C */  jal        func_8003FF34
    /* 1DDF8 8002D5F8 00000000 */   nop
    /* 1DDFC 8002D5FC C056000C */  jal        func_80015B00
    /* 1DE00 8002D600 00000000 */   nop
    /* 1DE04 8002D604 7403060C */  jal        func_80180DD0
    /* 1DE08 8002D608 00000000 */   nop
    /* 1DE0C 8002D60C 16B5000C */  jal        func_8002D458
    /* 1DE10 8002D610 21200002 */   addu      $a0, $s0, $zero
    /* 1DE14 8002D614 08000224 */  addiu      $v0, $zero, 0x8
    /* 1DE18 8002D618 610382A3 */  sb         $v0, %gp_rel(D_8009B269)($gp)
  .L8002D61C:
    /* 1DE1C 8002D61C 1400BF8F */  lw         $ra, 0x14($sp)
    /* 1DE20 8002D620 1000B08F */  lw         $s0, 0x10($sp)
    /* 1DE24 8002D624 0800E003 */  jr         $ra
    /* 1DE28 8002D628 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8002D588
