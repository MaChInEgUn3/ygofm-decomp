nonmatching func_8005A3D0, 0x98

glabel func_8005A3D0
    /* 4ABD0 8005A3D0 170E8390 */  lbu        $v1, 0xE17($a0)
    /* 4ABD4 8005A3D4 00000000 */  nop
    /* 4ABD8 8005A3D8 21006010 */  beqz       $v1, .L8005A460
    /* 4ABDC 8005A3DC 21400000 */   addu      $t0, $zero, $zero
    /* 4ABE0 8005A3E0 21580001 */  addu       $t3, $t0, $zero
    /* 4ABE4 8005A3E4 140D8A8C */  lw         $t2, 0xD14($a0)
  .L8005A3E8:
    /* 4ABE8 8005A3E8 00000000 */  nop
    /* 4ABEC 8005A3EC 4C00428D */  lw         $v0, 0x4C($t2)
    /* 4ABF0 8005A3F0 00000000 */  nop
    /* 4ABF4 8005A3F4 14004514 */  bne        $v0, $a1, .L8005A448
    /* 4ABF8 8005A3F8 21300000 */   addu      $a2, $zero, $zero
    /* 4ABFC 8005A3FC 12006010 */  beqz       $v1, .L8005A448
    /* 4AC00 8005A400 21486000 */   addu      $t1, $v1, $zero
    /* 4AC04 8005A404 140D828C */  lw         $v0, 0xD14($a0)
    /* 4AC08 8005A408 00000000 */  nop
    /* 4AC0C 8005A40C 21384B00 */  addu       $a3, $v0, $t3
    /* 4AC10 8005A410 21184000 */  addu       $v1, $v0, $zero
  .L8005A414:
    /* 4AC14 8005A414 4C00628C */  lw         $v0, 0x4C($v1)
    /* 4AC18 8005A418 00000000 */  nop
    /* 4AC1C 8005A41C 05004710 */  beq        $v0, $a3, .L8005A434
    /* 4AC20 8005A420 00000000 */   nop
    /* 4AC24 8005A424 0100C624 */  addiu      $a2, $a2, 0x1
    /* 4AC28 8005A428 2A10C900 */  slt        $v0, $a2, $t1
    /* 4AC2C 8005A42C F9FF4014 */  bnez       $v0, .L8005A414
    /* 4AC30 8005A430 50006324 */   addiu     $v1, $v1, 0x50
  .L8005A434:
    /* 4AC34 8005A434 170E8290 */  lbu        $v0, 0xE17($a0)
    /* 4AC38 8005A438 00000000 */  nop
    /* 4AC3C 8005A43C 2A10C200 */  slt        $v0, $a2, $v0
    /* 4AC40 8005A440 07004014 */  bnez       $v0, .L8005A460
    /* 4AC44 8005A444 00000000 */   nop
  .L8005A448:
    /* 4AC48 8005A448 50006B25 */  addiu      $t3, $t3, 0x50
    /* 4AC4C 8005A44C 170E8390 */  lbu        $v1, 0xE17($a0)
    /* 4AC50 8005A450 01000825 */  addiu      $t0, $t0, 0x1
    /* 4AC54 8005A454 2A100301 */  slt        $v0, $t0, $v1
    /* 4AC58 8005A458 E3FF4014 */  bnez       $v0, .L8005A3E8
    /* 4AC5C 8005A45C 50004A25 */   addiu     $t2, $t2, 0x50
  .L8005A460:
    /* 4AC60 8005A460 0800E003 */  jr         $ra
    /* 4AC64 8005A464 21100001 */   addu      $v0, $t0, $zero
endlabel func_8005A3D0
