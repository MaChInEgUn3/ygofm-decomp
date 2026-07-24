nonmatching func_8003B378, 0x194

glabel func_8003B378
    /* 2BB78 8003B378 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 2BB7C 8003B37C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 2BB80 8003B380 21808000 */  addu       $s0, $a0, $zero
    /* 2BB84 8003B384 1800BFAF */  sw         $ra, 0x18($sp)
    /* 2BB88 8003B388 1400B1AF */  sw         $s1, 0x14($sp)
    /* 2BB8C 8003B38C 32000392 */  lbu        $v1, 0x32($s0)
    /* 2BB90 8003B390 00000000 */  nop
    /* 2BB94 8003B394 10006230 */  andi       $v0, $v1, 0x10
    /* 2BB98 8003B398 04004010 */  beqz       $v0, .L8003B3AC
    /* 2BB9C 8003B39C 2188A000 */   addu      $s1, $a1, $zero
    /* 2BBA0 8003B3A0 FC006230 */  andi       $v0, $v1, 0xFC
    /* 2BBA4 8003B3A4 3EED0008 */  j          .L8003B4F8
    /* 2BBA8 8003B3A8 320002A2 */   sb        $v0, 0x32($s0)
  .L8003B3AC:
    /* 2BBAC 8003B3AC 0400048E */  lw         $a0, 0x4($s0)
    /* 2BBB0 8003B3B0 00000000 */  nop
    /* 2BBB4 8003B3B4 1F008010 */  beqz       $a0, .L8003B434
    /* 2BBB8 8003B3B8 01006230 */   andi      $v0, $v1, 0x1
    /* 2BBBC 8003B3BC 10004010 */  beqz       $v0, .L8003B400
    /* 2BBC0 8003B3C0 00000000 */   nop
    /* 2BBC4 8003B3C4 5A008284 */  lh         $v0, 0x5A($a0)
    /* 2BBC8 8003B3C8 00000000 */  nop
    /* 2BBCC 8003B3CC 19004014 */  bnez       $v0, .L8003B434
    /* 2BBD0 8003B3D0 00000000 */   nop
    /* 2BBD4 8003B3D4 6439020C */  jal        func_8008E590
    /* 2BBD8 8003B3D8 00000000 */   nop
    /* 2BBDC 8003B3DC 21280000 */  addu       $a1, $zero, $zero
    /* 2BBE0 8003B3E0 FF004230 */  andi       $v0, $v0, 0xFF
    /* 2BBE4 8003B3E4 0400048E */  lw         $a0, 0x4($s0)
    /* 2BBE8 8003B3E8 32000392 */  lbu        $v1, 0x32($s0)
    /* 2BBEC 8003B3EC 3C004224 */  addiu      $v0, $v0, 0x3C
    /* 2BBF0 8003B3F0 3E0002A6 */  sh         $v0, 0x3E($s0)
    /* 2BBF4 8003B3F4 FE006330 */  andi       $v1, $v1, 0xFE
    /* 2BBF8 8003B3F8 0BED0008 */  j          .L8003B42C
    /* 2BBFC 8003B3FC 320003A2 */   sb        $v1, 0x32($s0)
  .L8003B400:
    /* 2BC00 8003B400 3E000296 */  lhu        $v0, 0x3E($s0)
    /* 2BC04 8003B404 00000000 */  nop
    /* 2BC08 8003B408 FFFF4224 */  addiu      $v0, $v0, -0x1
    /* 2BC0C 8003B40C 3E0002A6 */  sh         $v0, 0x3E($s0)
    /* 2BC10 8003B410 00140200 */  sll        $v0, $v0, 16
    /* 2BC14 8003B414 0700401C */  bgtz       $v0, .L8003B434
    /* 2BC18 8003B418 01000524 */   addiu     $a1, $zero, 0x1
    /* 2BC1C 8003B41C 32000292 */  lbu        $v0, 0x32($s0)
    /* 2BC20 8003B420 0400048E */  lw         $a0, 0x4($s0)
    /* 2BC24 8003B424 25104500 */  or         $v0, $v0, $a1
    /* 2BC28 8003B428 320002A2 */  sb         $v0, 0x32($s0)
  .L8003B42C:
    /* 2BC2C 8003B42C 0401010C */  jal        func_80040410
    /* 2BC30 8003B430 00000000 */   nop
  .L8003B434:
    /* 2BC34 8003B434 0800028E */  lw         $v0, 0x8($s0)
    /* 2BC38 8003B438 00000000 */  nop
    /* 2BC3C 8003B43C 2E004010 */  beqz       $v0, .L8003B4F8
    /* 2BC40 8003B440 00000000 */   nop
    /* 2BC44 8003B444 32000392 */  lbu        $v1, 0x32($s0)
    /* 2BC48 8003B448 00000000 */  nop
    /* 2BC4C 8003B44C 02006230 */  andi       $v0, $v1, 0x2
    /* 2BC50 8003B450 12004010 */  beqz       $v0, .L8003B49C
    /* 2BC54 8003B454 00000000 */   nop
    /* 2BC58 8003B458 3B000292 */  lbu        $v0, 0x3B($s0)
    /* 2BC5C 8003B45C 0800038E */  lw         $v1, 0x8($s0)
    /* 2BC60 8003B460 FFFF4424 */  addiu      $a0, $v0, -0x1
    /* 2BC64 8003B464 3B0004A2 */  sb         $a0, 0x3B($s0)
    /* 2BC68 8003B468 5A006284 */  lh         $v0, 0x5A($v1)
    /* 2BC6C 8003B46C 00000000 */  nop
    /* 2BC70 8003B470 21004014 */  bnez       $v0, .L8003B4F8
    /* 2BC74 8003B474 00160400 */   sll       $v0, $a0, 24
    /* 2BC78 8003B478 1F00401C */  bgtz       $v0, .L8003B4F8
    /* 2BC7C 8003B47C 00000000 */   nop
    /* 2BC80 8003B480 0A00201E */  bgtz       $s1, .L8003B4AC
    /* 2BC84 8003B484 21282002 */   addu      $a1, $s1, $zero
    /* 2BC88 8003B488 32000292 */  lbu        $v0, 0x32($s0)
    /* 2BC8C 8003B48C 3B0000A2 */  sb         $zero, 0x3B($s0)
    /* 2BC90 8003B490 FD004230 */  andi       $v0, $v0, 0xFD
    /* 2BC94 8003B494 3EED0008 */  j          .L8003B4F8
    /* 2BC98 8003B498 320002A2 */   sb        $v0, 0x32($s0)
  .L8003B49C:
    /* 2BC9C 8003B49C 0A002006 */  bltz       $s1, .L8003B4C8
    /* 2BCA0 8003B4A0 02006234 */   ori       $v0, $v1, 0x2
    /* 2BCA4 8003B4A4 320002A2 */  sb         $v0, 0x32($s0)
    /* 2BCA8 8003B4A8 21282002 */  addu       $a1, $s1, $zero
  .L8003B4AC:
    /* 2BCAC 8003B4AC 0800048E */  lw         $a0, 0x8($s0)
    /* 2BCB0 8003B4B0 06000224 */  addiu      $v0, $zero, 0x6
    /* 2BCB4 8003B4B4 3B0002A2 */  sb         $v0, 0x3B($s0)
    /* 2BCB8 8003B4B8 0401010C */  jal        func_80040410
    /* 2BCBC 8003B4BC 3A0005A2 */   sb        $a1, 0x3A($s0)
    /* 2BCC0 8003B4C0 3EED0008 */  j          .L8003B4F8
    /* 2BCC4 8003B4C4 00000000 */   nop
  .L8003B4C8:
    /* 2BCC8 8003B4C8 3B000292 */  lbu        $v0, 0x3B($s0)
    /* 2BCCC 8003B4CC 00000000 */  nop
    /* 2BCD0 8003B4D0 01004224 */  addiu      $v0, $v0, 0x1
    /* 2BCD4 8003B4D4 3B0002A2 */  sb         $v0, 0x3B($s0)
    /* 2BCD8 8003B4D8 00160200 */  sll        $v0, $v0, 24
    /* 2BCDC 8003B4DC 03160200 */  sra        $v0, $v0, 24
    /* 2BCE0 8003B4E0 06004228 */  slti       $v0, $v0, 0x6
    /* 2BCE4 8003B4E4 04004014 */  bnez       $v0, .L8003B4F8
    /* 2BCE8 8003B4E8 00000000 */   nop
    /* 2BCEC 8003B4EC 0800048E */  lw         $a0, 0x8($s0)
    /* 2BCF0 8003B4F0 0901010C */  jal        func_80040424
    /* 2BCF4 8003B4F4 21280000 */   addu      $a1, $zero, $zero
  .L8003B4F8:
    /* 2BCF8 8003B4F8 1800BF8F */  lw         $ra, 0x18($sp)
    /* 2BCFC 8003B4FC 1400B18F */  lw         $s1, 0x14($sp)
    /* 2BD00 8003B500 1000B08F */  lw         $s0, 0x10($sp)
    /* 2BD04 8003B504 0800E003 */  jr         $ra
    /* 2BD08 8003B508 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8003B378
