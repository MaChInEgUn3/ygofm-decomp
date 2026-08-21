nonmatching func_8002DD74, 0x88

glabel func_8002DD74
    /* 1E574 8002DD74 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1E578 8002DD78 1400BFAF */  sw         $ra, 0x14($sp)
    /* 1E57C 8002DD7C 7AB3000C */  jal        func_8002CDE8
    /* 1E580 8002DD80 1000B0AF */   sw        $s0, 0x10($sp)
    /* 1E584 8002DD84 0980023C */  lui        $v0, %hi(D_80090B64)
    /* 1E588 8002DD88 640B5024 */  addiu      $s0, $v0, %lo(D_80090B64)
  .L8002DD8C:
    /* 1E58C 8002DD8C 534B000C */  jal        func_80012D4C
    /* 1E590 8002DD90 00000000 */   nop
    /* 1E594 8002DD94 64038393 */  lbu        $v1, %gp_rel(D_8009B26C)($gp)
    /* 1E598 8002DD98 00000000 */  nop
    /* 1E59C 8002DD9C 80006230 */  andi       $v0, $v1, 0x80
    /* 1E5A0 8002DDA0 07004014 */  bnez       $v0, .L8002DDC0
    /* 1E5A4 8002DDA4 1F006230 */   andi      $v0, $v1, 0x1F
    /* 1E5A8 8002DDA8 80006234 */  ori        $v0, $v1, 0x80
    /* 1E5AC 8002DDAC 640382A3 */  sb         $v0, %gp_rel(D_8009B26C)($gp)
    /* 1E5B0 8002DDB0 63B3000C */  jal        func_8002CD8C
    /* 1E5B4 8002DDB4 00000000 */   nop
    /* 1E5B8 8002DDB8 63B70008 */  j          .L8002DD8C
    /* 1E5BC 8002DDBC 00000000 */   nop
  .L8002DDC0:
    /* 1E5C0 8002DDC0 80100200 */  sll        $v0, $v0, 2
    /* 1E5C4 8002DDC4 21105000 */  addu       $v0, $v0, $s0
    /* 1E5C8 8002DDC8 0000428C */  lw         $v0, 0x0($v0)
    /* 1E5CC 8002DDCC 00000000 */  nop
    /* 1E5D0 8002DDD0 09F84000 */  jalr       $v0
    /* 1E5D4 8002DDD4 00000000 */   nop
    /* 1E5D8 8002DDD8 64038293 */  lbu        $v0, %gp_rel(D_8009B26C)($gp)
    /* 1E5DC 8002DDDC 00000000 */  nop
    /* 1E5E0 8002DDE0 40004230 */  andi       $v0, $v0, 0x40
    /* 1E5E4 8002DDE4 E9FF4014 */  bnez       $v0, .L8002DD8C
    /* 1E5E8 8002DDE8 00000000 */   nop
    /* 1E5EC 8002DDEC C056000C */  jal        func_80015B00
    /* 1E5F0 8002DDF0 00000000 */   nop
    /* 1E5F4 8002DDF4 63B70008 */  j          .L8002DD8C
    /* 1E5F8 8002DDF8 00000000 */   nop
endlabel func_8002DD74
