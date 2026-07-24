nonmatching func_8007D3F0, 0x2E0

glabel func_8007D3F0
    /* 6DBF0 8007D3F0 B0FFBD27 */  addiu      $sp, $sp, -0x50
    /* 6DBF4 8007D3F4 4800B6AF */  sw         $s6, 0x48($sp)
    /* 6DBF8 8007D3F8 21B08000 */  addu       $s6, $a0, $zero
    /* 6DBFC 8007D3FC 3C00B3AF */  sw         $s3, 0x3C($sp)
    /* 6DC00 8007D400 2198A000 */  addu       $s3, $a1, $zero
    /* 6DC04 8007D404 4C00BFAF */  sw         $ra, 0x4C($sp)
    /* 6DC08 8007D408 4400B5AF */  sw         $s5, 0x44($sp)
    /* 6DC0C 8007D40C 4000B4AF */  sw         $s4, 0x40($sp)
    /* 6DC10 8007D410 3800B2AF */  sw         $s2, 0x38($sp)
    /* 6DC14 8007D414 3400B1AF */  sw         $s1, 0x34($sp)
    /* 6DC18 8007D418 DCF8010C */  jal        func_8007E370
    /* 6DC1C 8007D41C 3000B0AF */   sw        $s0, 0x30($sp)
    /* 6DC20 8007D420 0980033C */  lui        $v1, %hi(D_80093A0C)
    /* 6DC24 8007D424 0C3A638C */  lw         $v1, %lo(D_80093A0C)($v1)
    /* 6DC28 8007D428 00000000 */  nop
    /* 6DC2C 8007D42C 2A186200 */  slt        $v1, $v1, $v0
    /* 6DC30 8007D430 09006010 */  beqz       $v1, .L8007D458
    /* 6DC34 8007D434 00000000 */   nop
    /* 6DC38 8007D438 BCF5010C */  jal        func_8007D6F0
    /* 6DC3C 8007D43C 00000000 */   nop
    /* 6DC40 8007D440 99004010 */  beqz       $v0, .L8007D6A8
    /* 6DC44 8007D444 21100000 */   addu      $v0, $zero, $zero
    /* 6DC48 8007D448 DCF8010C */  jal        func_8007E370
    /* 6DC4C 8007D44C 00000000 */   nop
    /* 6DC50 8007D450 0980013C */  lui        $at, %hi(D_80093A0C)
    /* 6DC54 8007D454 0C3A22AC */  sw         $v0, %lo(D_80093A0C)($at)
  .L8007D458:
    /* 6DC58 8007D458 00006382 */  lb         $v1, 0x0($s3)
    /* 6DC5C 8007D45C 5C000224 */  addiu      $v0, $zero, 0x5C
    /* 6DC60 8007D460 05006210 */  beq        $v1, $v0, .L8007D478
    /* 6DC64 8007D464 21100000 */   addu      $v0, $zero, $zero
    /* 6DC68 8007D468 AAF50108 */  j          .L8007D6A8
    /* 6DC6C 8007D46C 00000000 */   nop
  .L8007D470:
    /* 6DC70 8007D470 40F50108 */  j          .L8007D500
    /* 6DC74 8007D474 1000A0A3 */   sb        $zero, 0x10($sp)
  .L8007D478:
    /* 6DC78 8007D478 1000A0A3 */  sb         $zero, 0x10($sp)
    /* 6DC7C 8007D47C 01000424 */  addiu      $a0, $zero, 0x1
    /* 6DC80 8007D480 21806002 */  addu       $s0, $s3, $zero
    /* 6DC84 8007D484 21900000 */  addu       $s2, $zero, $zero
    /* 6DC88 8007D488 5C001524 */  addiu      $s5, $zero, 0x5C
    /* 6DC8C 8007D48C FFFF1424 */  addiu      $s4, $zero, -0x1
  .L8007D490:
    /* 6DC90 8007D490 00000282 */  lb         $v0, 0x0($s0)
    /* 6DC94 8007D494 00000392 */  lbu        $v1, 0x0($s0)
    /* 6DC98 8007D498 0C005510 */  beq        $v0, $s5, .L8007D4CC
    /* 6DC9C 8007D49C 1000B127 */   addiu     $s1, $sp, 0x10
    /* 6DCA0 8007D4A0 5C000524 */  addiu      $a1, $zero, 0x5C
  .L8007D4A4:
    /* 6DCA4 8007D4A4 17006010 */  beqz       $v1, .L8007D504
    /* 6DCA8 8007D4A8 0800422A */   slti      $v0, $s2, 0x8
    /* 6DCAC 8007D4AC 01001026 */  addiu      $s0, $s0, 0x1
    /* 6DCB0 8007D4B0 000023A2 */  sb         $v1, 0x0($s1)
    /* 6DCB4 8007D4B4 00000282 */  lb         $v0, 0x0($s0)
    /* 6DCB8 8007D4B8 00000392 */  lbu        $v1, 0x0($s0)
    /* 6DCBC 8007D4BC F9FF4514 */  bne        $v0, $a1, .L8007D4A4
    /* 6DCC0 8007D4C0 01003126 */   addiu     $s1, $s1, 0x1
    /* 6DCC4 8007D4C4 00000282 */  lb         $v0, 0x0($s0)
    /* 6DCC8 8007D4C8 00000000 */  nop
  .L8007D4CC:
    /* 6DCCC 8007D4CC 0D004010 */  beqz       $v0, .L8007D504
    /* 6DCD0 8007D4D0 0800422A */   slti      $v0, $s2, 0x8
    /* 6DCD4 8007D4D4 01001026 */  addiu      $s0, $s0, 0x1
    /* 6DCD8 8007D4D8 000020A2 */  sb         $zero, 0x0($s1)
    /* 6DCDC 8007D4DC 6DF6010C */  jal        func_8007D9B4
    /* 6DCE0 8007D4E0 1000A527 */   addiu     $a1, $sp, 0x10
    /* 6DCE4 8007D4E4 21204000 */  addu       $a0, $v0, $zero
    /* 6DCE8 8007D4E8 E1FF9410 */  beq        $a0, $s4, .L8007D470
    /* 6DCEC 8007D4EC 00000000 */   nop
    /* 6DCF0 8007D4F0 01005226 */  addiu      $s2, $s2, 0x1
    /* 6DCF4 8007D4F4 0800422A */  slti       $v0, $s2, 0x8
    /* 6DCF8 8007D4F8 E5FF4014 */  bnez       $v0, .L8007D490
    /* 6DCFC 8007D4FC 00000000 */   nop
  .L8007D500:
    /* 6DD00 8007D500 0800422A */  slti       $v0, $s2, 0x8
  .L8007D504:
    /* 6DD04 8007D504 0C004014 */  bnez       $v0, .L8007D538
    /* 6DD08 8007D508 00000000 */   nop
    /* 6DD0C 8007D50C 0980023C */  lui        $v0, %hi(D_800934E8)
    /* 6DD10 8007D510 E834428C */  lw         $v0, %lo(D_800934E8)($v0)
    /* 6DD14 8007D514 00000000 */  nop
    /* 6DD18 8007D518 62004018 */  blez       $v0, .L8007D6A4
    /* 6DD1C 8007D51C 21286002 */   addu      $a1, $s3, $zero
    /* 6DD20 8007D520 0180043C */  lui        $a0, %hi(D_80011EB8)
    /* 6DD24 8007D524 B81E8424 */  addiu      $a0, $a0, %lo(D_80011EB8)
    /* 6DD28 8007D528 1C3A020C */  jal        func_8008E870
    /* 6DD2C 8007D52C 21304002 */   addu      $a2, $s2, $zero
    /* 6DD30 8007D530 AAF50108 */  j          .L8007D6A8
    /* 6DD34 8007D534 21100000 */   addu      $v0, $zero, $zero
  .L8007D538:
    /* 6DD38 8007D538 1000A283 */  lb         $v0, 0x10($sp)
    /* 6DD3C 8007D53C 00000000 */  nop
    /* 6DD40 8007D540 09004014 */  bnez       $v0, .L8007D568
    /* 6DD44 8007D544 00000000 */   nop
    /* 6DD48 8007D548 0980023C */  lui        $v0, %hi(D_800934E8)
    /* 6DD4C 8007D54C E834428C */  lw         $v0, %lo(D_800934E8)($v0)
    /* 6DD50 8007D550 00000000 */  nop
    /* 6DD54 8007D554 53004018 */  blez       $v0, .L8007D6A4
    /* 6DD58 8007D558 21286002 */   addu      $a1, $s3, $zero
    /* 6DD5C 8007D55C 0180043C */  lui        $a0, %hi(D_80011ED4)
    /* 6DD60 8007D560 A7F50108 */  j          .L8007D69C
    /* 6DD64 8007D564 D41E8424 */   addiu     $a0, $a0, %lo(D_80011ED4)
  .L8007D568:
    /* 6DD68 8007D568 96F6010C */  jal        func_8007DA58
    /* 6DD6C 8007D56C 000020A2 */   sb        $zero, 0x0($s1)
    /* 6DD70 8007D570 0B004014 */  bnez       $v0, .L8007D5A0
    /* 6DD74 8007D574 00000000 */   nop
    /* 6DD78 8007D578 0980023C */  lui        $v0, %hi(D_800934E8)
    /* 6DD7C 8007D57C E834428C */  lw         $v0, %lo(D_800934E8)($v0)
    /* 6DD80 8007D580 00000000 */  nop
    /* 6DD84 8007D584 48004018 */  blez       $v0, .L8007D6A8
    /* 6DD88 8007D588 21100000 */   addu      $v0, $zero, $zero
    /* 6DD8C 8007D58C 0180043C */  lui        $a0, %hi(D_80011EEC)
    /* 6DD90 8007D590 BC3E020C */  jal        func_8008FAF0
    /* 6DD94 8007D594 EC1E8424 */   addiu     $a0, $a0, %lo(D_80011EEC)
    /* 6DD98 8007D598 AAF50108 */  j          .L8007D6A8
    /* 6DD9C 8007D59C 21100000 */   addu      $v0, $zero, $zero
  .L8007D5A0:
    /* 6DDA0 8007D5A0 0980023C */  lui        $v0, %hi(D_800934E8)
    /* 6DDA4 8007D5A4 E834428C */  lw         $v0, %lo(D_800934E8)($v0)
    /* 6DDA8 8007D5A8 00000000 */  nop
    /* 6DDAC 8007D5AC 02004228 */  slti       $v0, $v0, 0x2
    /* 6DDB0 8007D5B0 06004014 */  bnez       $v0, .L8007D5CC
    /* 6DDB4 8007D5B4 21900000 */   addu      $s2, $zero, $zero
    /* 6DDB8 8007D5B8 0180043C */  lui        $a0, %hi(D_80011F08)
    /* 6DDBC 8007D5BC 081F8424 */  addiu      $a0, $a0, %lo(D_80011F08)
    /* 6DDC0 8007D5C0 1C3A020C */  jal        func_8008E870
    /* 6DDC4 8007D5C4 1000A527 */   addiu     $a1, $sp, 0x10
    /* 6DDC8 8007D5C8 21900000 */  addu       $s2, $zero, $zero
  .L8007D5CC:
    /* 6DDCC 8007D5CC 0F80023C */  lui        $v0, %hi(D_800F5F98)
    /* 6DDD0 8007D5D0 985F4224 */  addiu      $v0, $v0, %lo(D_800F5F98)
    /* 6DDD4 8007D5D4 F8FF5024 */  addiu      $s0, $v0, -0x8
    /* 6DDD8 8007D5D8 21984000 */  addu       $s3, $v0, $zero
    /* 6DDDC 8007D5DC 21880000 */  addu       $s1, $zero, $zero
  .L8007D5E0:
    /* 6DDE0 8007D5E0 0F80023C */  lui        $v0, %hi(D_800F5F98)
    /* 6DDE4 8007D5E4 21105100 */  addu       $v0, $v0, $s1
    /* 6DDE8 8007D5E8 985F4280 */  lb         $v0, %lo(D_800F5F98)($v0)
    /* 6DDEC 8007D5EC 00000000 */  nop
    /* 6DDF0 8007D5F0 23004010 */  beqz       $v0, .L8007D680
    /* 6DDF4 8007D5F4 21206002 */   addu      $a0, $s3, $zero
    /* 6DDF8 8007D5F8 B4F5010C */  jal        func_8007D6D0
    /* 6DDFC 8007D5FC 1000A527 */   addiu     $a1, $sp, 0x10
    /* 6DE00 8007D600 19004010 */  beqz       $v0, .L8007D668
    /* 6DE04 8007D604 00000000 */   nop
    /* 6DE08 8007D608 0980023C */  lui        $v0, %hi(D_800934E8)
    /* 6DE0C 8007D60C E834428C */  lw         $v0, %lo(D_800934E8)($v0)
    /* 6DE10 8007D610 00000000 */  nop
    /* 6DE14 8007D614 02004228 */  slti       $v0, $v0, 0x2
    /* 6DE18 8007D618 05004014 */  bnez       $v0, .L8007D630
    /* 6DE1C 8007D61C 00000000 */   nop
    /* 6DE20 8007D620 0180043C */  lui        $a0, %hi(D_80011F28)
    /* 6DE24 8007D624 281F8424 */  addiu      $a0, $a0, %lo(D_80011F28)
    /* 6DE28 8007D628 1C3A020C */  jal        func_8008E870
    /* 6DE2C 8007D62C 1000A527 */   addiu     $a1, $sp, 0x10
  .L8007D630:
    /* 6DE30 8007D630 0000028E */  lw         $v0, 0x0($s0)
    /* 6DE34 8007D634 0400038E */  lw         $v1, 0x4($s0)
    /* 6DE38 8007D638 0800048E */  lw         $a0, 0x8($s0)
    /* 6DE3C 8007D63C 0C00058E */  lw         $a1, 0xC($s0)
    /* 6DE40 8007D640 0000C2AE */  sw         $v0, 0x0($s6)
    /* 6DE44 8007D644 0400C3AE */  sw         $v1, 0x4($s6)
    /* 6DE48 8007D648 0800C4AE */  sw         $a0, 0x8($s6)
    /* 6DE4C 8007D64C 0C00C5AE */  sw         $a1, 0xC($s6)
    /* 6DE50 8007D650 1000028E */  lw         $v0, 0x10($s0)
    /* 6DE54 8007D654 1400038E */  lw         $v1, 0x14($s0)
    /* 6DE58 8007D658 1000C2AE */  sw         $v0, 0x10($s6)
    /* 6DE5C 8007D65C 1400C3AE */  sw         $v1, 0x14($s6)
    /* 6DE60 8007D660 AAF50108 */  j          .L8007D6A8
    /* 6DE64 8007D664 21100002 */   addu      $v0, $s0, $zero
  .L8007D668:
    /* 6DE68 8007D668 18001026 */  addiu      $s0, $s0, 0x18
    /* 6DE6C 8007D66C 18007326 */  addiu      $s3, $s3, 0x18
    /* 6DE70 8007D670 01005226 */  addiu      $s2, $s2, 0x1
    /* 6DE74 8007D674 4000422A */  slti       $v0, $s2, 0x40
    /* 6DE78 8007D678 D9FF4014 */  bnez       $v0, .L8007D5E0
    /* 6DE7C 8007D67C 18003126 */   addiu     $s1, $s1, 0x18
  .L8007D680:
    /* 6DE80 8007D680 0980023C */  lui        $v0, %hi(D_800934E8)
    /* 6DE84 8007D684 E834428C */  lw         $v0, %lo(D_800934E8)($v0)
    /* 6DE88 8007D688 00000000 */  nop
    /* 6DE8C 8007D68C 05004018 */  blez       $v0, .L8007D6A4
    /* 6DE90 8007D690 1000A527 */   addiu     $a1, $sp, 0x10
    /* 6DE94 8007D694 0180043C */  lui        $a0, %hi(D_80011F34)
    /* 6DE98 8007D698 341F8424 */  addiu      $a0, $a0, %lo(D_80011F34)
  .L8007D69C:
    /* 6DE9C 8007D69C 1C3A020C */  jal        func_8008E870
    /* 6DEA0 8007D6A0 00000000 */   nop
  .L8007D6A4:
    /* 6DEA4 8007D6A4 21100000 */  addu       $v0, $zero, $zero
  .L8007D6A8:
    /* 6DEA8 8007D6A8 4C00BF8F */  lw         $ra, 0x4C($sp)
    /* 6DEAC 8007D6AC 4800B68F */  lw         $s6, 0x48($sp)
    /* 6DEB0 8007D6B0 4400B58F */  lw         $s5, 0x44($sp)
    /* 6DEB4 8007D6B4 4000B48F */  lw         $s4, 0x40($sp)
    /* 6DEB8 8007D6B8 3C00B38F */  lw         $s3, 0x3C($sp)
    /* 6DEBC 8007D6BC 3800B28F */  lw         $s2, 0x38($sp)
    /* 6DEC0 8007D6C0 3400B18F */  lw         $s1, 0x34($sp)
    /* 6DEC4 8007D6C4 3000B08F */  lw         $s0, 0x30($sp)
    /* 6DEC8 8007D6C8 0800E003 */  jr         $ra
    /* 6DECC 8007D6CC 5000BD27 */   addiu     $sp, $sp, 0x50
endlabel func_8007D3F0
