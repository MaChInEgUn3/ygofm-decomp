nonmatching func_8005988C, 0x58

glabel func_8005988C
    /* 4A08C 8005988C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 4A090 80059890 21280000 */  addu       $a1, $zero, $zero
    /* 4A094 80059894 2130A000 */  addu       $a2, $a1, $zero
    /* 4A098 80059898 1400BFAF */  sw         $ra, 0x14($sp)
    /* 4A09C 8005989C C1CD010C */  jal        func_80073704
    /* 4A0A0 800598A0 1000B0AF */   sw        $s0, 0x10($sp)
    /* 4A0A4 800598A4 21804000 */  addu       $s0, $v0, $zero
    /* 4A0A8 800598A8 09000006 */  bltz       $s0, .L800598D0
    /* 4A0AC 800598AC 21200002 */   addu      $a0, $s0, $zero
    /* 4A0B0 800598B0 21280000 */  addu       $a1, $zero, $zero
    /* 4A0B4 800598B4 CDCD010C */  jal        func_80073734
    /* 4A0B8 800598B8 02000624 */   addiu     $a2, $zero, 0x2
    /* 4A0BC 800598BC 21200002 */  addu       $a0, $s0, $zero
    /* 4A0C0 800598C0 C9CD010C */  jal        func_80073724
    /* 4A0C4 800598C4 21804000 */   addu      $s0, $v0, $zero
    /* 4A0C8 800598C8 35660108 */  j          .L800598D4
    /* 4A0CC 800598CC 21100002 */   addu      $v0, $s0, $zero
  .L800598D0:
    /* 4A0D0 800598D0 FFFF0224 */  addiu      $v0, $zero, -0x1
  .L800598D4:
    /* 4A0D4 800598D4 1400BF8F */  lw         $ra, 0x14($sp)
    /* 4A0D8 800598D8 1000B08F */  lw         $s0, 0x10($sp)
    /* 4A0DC 800598DC 0800E003 */  jr         $ra
    /* 4A0E0 800598E0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8005988C
