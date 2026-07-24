nonmatching func_8003B50C, 0xBC

glabel func_8003B50C
    /* 2BD0C 8003B50C D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 2BD10 8003B510 2000B4AF */  sw         $s4, 0x20($sp)
    /* 2BD14 8003B514 21A08000 */  addu       $s4, $a0, $zero
    /* 2BD18 8003B518 0F80023C */  lui        $v0, %hi(D_800EB010)
    /* 2BD1C 8003B51C 1400B1AF */  sw         $s1, 0x14($sp)
    /* 2BD20 8003B520 10B05124 */  addiu      $s1, $v0, %lo(D_800EB010)
    /* 2BD24 8003B524 1800B2AF */  sw         $s2, 0x18($sp)
    /* 2BD28 8003B528 02001224 */  addiu      $s2, $zero, 0x2
    /* 2BD2C 8003B52C 0980023C */  lui        $v0, %hi(D_80090F68)
    /* 2BD30 8003B530 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 2BD34 8003B534 680F5324 */  addiu      $s3, $v0, %lo(D_80090F68)
    /* 2BD38 8003B538 1000B0AF */  sw         $s0, 0x10($sp)
    /* 2BD3C 8003B53C 33003026 */  addiu      $s0, $s1, 0x33
    /* 2BD40 8003B540 2400BFAF */  sw         $ra, 0x24($sp)
  .L8003B544:
    /* 2BD44 8003B544 FDFF0282 */  lb         $v0, -0x3($s0)
    /* 2BD48 8003B548 00000000 */  nop
    /* 2BD4C 8003B54C 12004004 */  bltz       $v0, .L8003B598
    /* 2BD50 8003B550 00000000 */   nop
    /* 2BD54 8003B554 FFFF0292 */  lbu        $v0, -0x1($s0)
    /* 2BD58 8003B558 00000000 */  nop
    /* 2BD5C 8003B55C 40004230 */  andi       $v0, $v0, 0x40
    /* 2BD60 8003B560 03004010 */  beqz       $v0, .L8003B570
    /* 2BD64 8003B564 21202002 */   addu      $a0, $s1, $zero
    /* 2BD68 8003B568 DEEC000C */  jal        func_8003B378
    /* 2BD6C 8003B56C 21288002 */   addu      $a1, $s4, $zero
  .L8003B570:
    /* 2BD70 8003B570 00000292 */  lbu        $v0, 0x0($s0)
    /* 2BD74 8003B574 00000000 */  nop
    /* 2BD78 8003B578 07004010 */  beqz       $v0, .L8003B598
    /* 2BD7C 8003B57C 1F004230 */   andi      $v0, $v0, 0x1F
    /* 2BD80 8003B580 80100200 */  sll        $v0, $v0, 2
    /* 2BD84 8003B584 21105300 */  addu       $v0, $v0, $s3
    /* 2BD88 8003B588 0000428C */  lw         $v0, 0x0($v0)
    /* 2BD8C 8003B58C 00000000 */  nop
    /* 2BD90 8003B590 09F84000 */  jalr       $v0
    /* 2BD94 8003B594 21202002 */   addu      $a0, $s1, $zero
  .L8003B598:
    /* 2BD98 8003B598 4C001026 */  addiu      $s0, $s0, 0x4C
    /* 2BD9C 8003B59C FFFF5226 */  addiu      $s2, $s2, -0x1
    /* 2BDA0 8003B5A0 E8FF4106 */  bgez       $s2, .L8003B544
    /* 2BDA4 8003B5A4 4C003126 */   addiu     $s1, $s1, 0x4C
    /* 2BDA8 8003B5A8 2400BF8F */  lw         $ra, 0x24($sp)
    /* 2BDAC 8003B5AC 2000B48F */  lw         $s4, 0x20($sp)
    /* 2BDB0 8003B5B0 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 2BDB4 8003B5B4 1800B28F */  lw         $s2, 0x18($sp)
    /* 2BDB8 8003B5B8 1400B18F */  lw         $s1, 0x14($sp)
    /* 2BDBC 8003B5BC 1000B08F */  lw         $s0, 0x10($sp)
    /* 2BDC0 8003B5C0 0800E003 */  jr         $ra
    /* 2BDC4 8003B5C4 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_8003B50C
