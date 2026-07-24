nonmatching func_800358A0, 0x5C

glabel func_800358A0
    /* 260A0 800358A0 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 260A4 800358A4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 260A8 800358A8 2180A000 */  addu       $s0, $a1, $zero
    /* 260AC 800358AC 1400B1AF */  sw         $s1, 0x14($sp)
    /* 260B0 800358B0 1800BFAF */  sw         $ra, 0x18($sp)
    /* 260B4 800358B4 FAD5000C */  jal        func_800357E8
    /* 260B8 800358B8 2188C000 */   addu      $s1, $a2, $zero
  .L800358BC:
    /* 260BC 800358BC FFFF1026 */  addiu      $s0, $s0, -0x1
  .L800358C0:
    /* 260C0 800358C0 0900001A */  blez       $s0, .L800358E8
    /* 260C4 800358C4 21183002 */   addu      $v1, $s1, $s0
    /* 260C8 800358C8 00006290 */  lbu        $v0, 0x0($v1)
    /* 260CC 800358CC 00000000 */  nop
    /* 260D0 800358D0 0A00422C */  sltiu      $v0, $v0, 0xA
    /* 260D4 800358D4 FAFF4014 */  bnez       $v0, .L800358C0
    /* 260D8 800358D8 FFFF1026 */   addiu     $s0, $s0, -0x1
    /* 260DC 800358DC 01001026 */  addiu      $s0, $s0, 0x1
    /* 260E0 800358E0 2FD60008 */  j          .L800358BC
    /* 260E4 800358E4 000060A0 */   sb        $zero, 0x0($v1)
  .L800358E8:
    /* 260E8 800358E8 1800BF8F */  lw         $ra, 0x18($sp)
    /* 260EC 800358EC 1400B18F */  lw         $s1, 0x14($sp)
    /* 260F0 800358F0 1000B08F */  lw         $s0, 0x10($sp)
    /* 260F4 800358F4 0800E003 */  jr         $ra
    /* 260F8 800358F8 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_800358A0
