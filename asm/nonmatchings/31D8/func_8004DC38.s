nonmatching func_8004DC38, 0x1EC

glabel func_8004DC38
    /* 3E438 8004DC38 21588000 */  addu       $t3, $a0, $zero
    /* 3E43C 8004DC3C 80200500 */  sll        $a0, $a1, 2
    /* 3E440 8004DC40 40280500 */  sll        $a1, $a1, 1
    /* 3E444 8004DC44 C0100600 */  sll        $v0, $a2, 3
    /* 3E448 8004DC48 23104600 */  subu       $v0, $v0, $a2
    /* 3E44C 8004DC4C 80100200 */  sll        $v0, $v0, 2
    /* 3E450 8004DC50 21104600 */  addu       $v0, $v0, $a2
    /* 3E454 8004DC54 80100200 */  sll        $v0, $v0, 2
    /* 3E458 8004DC58 2110A200 */  addu       $v0, $a1, $v0
    /* 3E45C 8004DC5C 21106201 */  addu       $v0, $t3, $v0
    /* 3E460 8004DC60 21206401 */  addu       $a0, $t3, $a0
    /* 3E464 8004DC64 C8024994 */  lhu        $t1, 0x2C8($v0)
    /* 3E468 8004DC68 D80D628D */  lw         $v0, 0xDD8($t3)
    /* 3E46C 8004DC6C E0018A8C */  lw         $t2, 0x1E0($a0)
    /* 3E470 8004DC70 80180900 */  sll        $v1, $t1, 2
    /* 3E474 8004DC74 69004011 */  beqz       $t2, .L8004DE1C
    /* 3E478 8004DC78 21404300 */   addu      $t0, $v0, $v1
    /* 3E47C 8004DC7C FFFF0234 */  ori        $v0, $zero, 0xFFFF
    /* 3E480 8004DC80 66002211 */  beq        $t1, $v0, .L8004DE1C
    /* 3E484 8004DC84 00110600 */   sll       $v0, $a2, 4
    /* 3E488 8004DC88 23104600 */  subu       $v0, $v0, $a2
    /* 3E48C 8004DC8C 80100200 */  sll        $v0, $v0, 2
    /* 3E490 8004DC90 23104600 */  subu       $v0, $v0, $a2
    /* 3E494 8004DC94 40100200 */  sll        $v0, $v0, 1
    /* 3E498 8004DC98 2110A200 */  addu       $v0, $a1, $v0
    /* 3E49C 8004DC9C 21186201 */  addu       $v1, $t3, $v0
    /* 3E4A0 8004DCA0 50076294 */  lhu        $v0, 0x750($v1)
    /* 3E4A4 8004DCA4 00000000 */  nop
    /* 3E4A8 8004DCA8 5C004010 */  beqz       $v0, .L8004DE1C
    /* 3E4AC 8004DCAC 00210200 */   sll       $a0, $v0, 4
    /* 3E4B0 8004DCB0 1B00E400 */  divu       $zero, $a3, $a0
    /* 3E4B4 8004DCB4 02008014 */  bnez       $a0, .L8004DCC0
    /* 3E4B8 8004DCB8 00000000 */   nop
    /* 3E4BC 8004DCBC 0D000700 */  break      7
  .L8004DCC0:
    /* 3E4C0 8004DCC0 10300000 */  mfhi       $a2
    /* 3E4C4 8004DCC4 00000000 */  nop
    /* 3E4C8 8004DCC8 0800C014 */  bnez       $a2, .L8004DCEC
    /* 3E4CC 8004DCCC FCFF0C25 */   addiu     $t4, $t0, -0x4
    /* 3E4D0 8004DCD0 0600E010 */  beqz       $a3, .L8004DCEC
    /* 3E4D4 8004DCD4 3C000224 */   addiu     $v0, $zero, 0x3C
    /* 3E4D8 8004DCD8 160E6391 */  lbu        $v1, 0xE16($t3)
    /* 3E4DC 8004DCDC 00000000 */  nop
    /* 3E4E0 8004DCE0 02006210 */  beq        $v1, $v0, .L8004DCEC
    /* 3E4E4 8004DCE4 00000000 */   nop
    /* 3E4E8 8004DCE8 21308000 */  addu       $a2, $a0, $zero
  .L8004DCEC:
    /* 3E4EC 8004DCEC 00008295 */  lhu        $v0, 0x0($t4)
    /* 3E4F0 8004DCF0 00000000 */  nop
    /* 3E4F4 8004DCF4 49004010 */  beqz       $v0, .L8004DE1C
    /* 3E4F8 8004DCF8 21280000 */   addu      $a1, $zero, $zero
    /* 3E4FC 8004DCFC 160E6991 */  lbu        $t1, 0xE16($t3)
    /* 3E500 8004DD00 3C000D24 */  addiu      $t5, $zero, 0x3C
    /* 3E504 8004DD04 21384000 */  addu       $a3, $v0, $zero
    /* 3E508 8004DD08 04000425 */  addiu      $a0, $t0, 0x4
  .L8004DD0C:
    /* 3E50C 8004DD0C 09002D11 */  beq        $t1, $t5, .L8004DD34
    /* 3E510 8004DD10 00000000 */   nop
    /* 3E514 8004DD14 FEFF8290 */  lbu        $v0, -0x2($a0)
    /* 3E518 8004DD18 00000000 */  nop
    /* 3E51C 8004DD1C 00110200 */  sll        $v0, $v0, 4
    /* 3E520 8004DD20 2310C200 */  subu       $v0, $a2, $v0
    /* 3E524 8004DD24 13004018 */  blez       $v0, .L8004DD74
    /* 3E528 8004DD28 00000000 */   nop
    /* 3E52C 8004DD2C 53370108 */  j          .L8004DD4C
    /* 3E530 8004DD30 00000000 */   nop
  .L8004DD34:
    /* 3E534 8004DD34 FEFF8290 */  lbu        $v0, -0x2($a0)
    /* 3E538 8004DD38 00000000 */  nop
    /* 3E53C 8004DD3C 00110200 */  sll        $v0, $v0, 4
    /* 3E540 8004DD40 2310C200 */  subu       $v0, $a2, $v0
    /* 3E544 8004DD44 0B004004 */  bltz       $v0, .L8004DD74
    /* 3E548 8004DD48 00000000 */   nop
  .L8004DD4C:
    /* 3E54C 8004DD4C FEFF8290 */  lbu        $v0, -0x2($a0)
    /* 3E550 8004DD50 0000838C */  lw         $v1, 0x0($a0)
    /* 3E554 8004DD54 00110200 */  sll        $v0, $v0, 4
    /* 3E558 8004DD58 06006004 */  bltz       $v1, .L8004DD74
    /* 3E55C 8004DD5C 2330C200 */   subu      $a2, $a2, $v0
    /* 3E560 8004DD60 04008424 */  addiu      $a0, $a0, 0x4
    /* 3E564 8004DD64 0100A524 */  addiu      $a1, $a1, 0x1
    /* 3E568 8004DD68 2A10A700 */  slt        $v0, $a1, $a3
    /* 3E56C 8004DD6C E7FF4014 */  bnez       $v0, .L8004DD0C
    /* 3E570 8004DD70 04000825 */   addiu     $t0, $t0, 0x4
  .L8004DD74:
    /* 3E574 8004DD74 00008495 */  lhu        $a0, 0x0($t4)
    /* 3E578 8004DD78 00000000 */  nop
    /* 3E57C 8004DD7C 2A10A400 */  slt        $v0, $a1, $a0
    /* 3E580 8004DD80 26004010 */  beqz       $v0, .L8004DE1C
    /* 3E584 8004DD84 21180001 */   addu      $v1, $t0, $zero
  .L8004DD88:
    /* 3E588 8004DD88 0400628C */  lw         $v0, 0x4($v1)
    /* 3E58C 8004DD8C 00000000 */  nop
    /* 3E590 8004DD90 05004004 */  bltz       $v0, .L8004DDA8
    /* 3E594 8004DD94 00000000 */   nop
    /* 3E598 8004DD98 0100A524 */  addiu      $a1, $a1, 0x1
    /* 3E59C 8004DD9C 2A10A400 */  slt        $v0, $a1, $a0
    /* 3E5A0 8004DDA0 F9FF4014 */  bnez       $v0, .L8004DD88
    /* 3E5A4 8004DDA4 04006324 */   addiu     $v1, $v1, 0x4
  .L8004DDA8:
    /* 3E5A8 8004DDA8 D80D628D */  lw         $v0, 0xDD8($t3)
    /* 3E5AC 8004DDAC 00000000 */  nop
    /* 3E5B0 8004DDB0 23100201 */  subu       $v0, $t0, $v0
    /* 3E5B4 8004DDB4 83100200 */  sra        $v0, $v0, 2
    /* 3E5B8 8004DDB8 03004010 */  beqz       $v0, .L8004DDC8
    /* 3E5BC 8004DDBC 160042A5 */   sh        $v0, 0x16($t2)
    /* 3E5C0 8004DDC0 76370108 */  j          .L8004DDD8
    /* 3E5C4 8004DDC4 FFFF4224 */   addiu     $v0, $v0, -0x1
  .L8004DDC8:
    /* 3E5C8 8004DDC8 D80D628D */  lw         $v0, 0xDD8($t3)
    /* 3E5CC 8004DDCC 00000000 */  nop
    /* 3E5D0 8004DDD0 23106200 */  subu       $v0, $v1, $v0
    /* 3E5D4 8004DDD4 83100200 */  sra        $v0, $v0, 2
  .L8004DDD8:
    /* 3E5D8 8004DDD8 140042A5 */  sh         $v0, 0x14($t2)
    /* 3E5DC 8004DDDC 02000291 */  lbu        $v0, 0x2($t0)
    /* 3E5E0 8004DDE0 00000000 */  nop
    /* 3E5E4 8004DDE4 00110200 */  sll        $v0, $v0, 4
    /* 3E5E8 8004DDE8 23204600 */  subu       $a0, $v0, $a2
    /* 3E5EC 8004DDEC 120042A5 */  sh         $v0, 0x12($t2)
    /* 3E5F0 8004DDF0 100044A5 */  sh         $a0, 0x10($t2)
    /* 3E5F4 8004DDF4 160E6391 */  lbu        $v1, 0xE16($t3)
    /* 3E5F8 8004DDF8 3C000224 */  addiu      $v0, $zero, 0x3C
    /* 3E5FC 8004DDFC 07006214 */  bne        $v1, $v0, .L8004DE1C
    /* 3E600 8004DE00 00140400 */   sll       $v0, $a0, 16
    /* 3E604 8004DE04 12004395 */  lhu        $v1, 0x12($t2)
    /* 3E608 8004DE08 03140200 */  sra        $v0, $v0, 16
    /* 3E60C 8004DE0C 2A104300 */  slt        $v0, $v0, $v1
    /* 3E610 8004DE10 02004014 */  bnez       $v0, .L8004DE1C
    /* 3E614 8004DE14 00600224 */   addiu     $v0, $zero, 0x6000
    /* 3E618 8004DE18 100042A5 */  sh         $v0, 0x10($t2)
  .L8004DE1C:
    /* 3E61C 8004DE1C 0800E003 */  jr         $ra
    /* 3E620 8004DE20 00000000 */   nop
endlabel func_8004DC38
