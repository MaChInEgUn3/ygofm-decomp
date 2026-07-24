nonmatching func_80047EC4, 0x74

glabel func_80047EC4
    /* 386C4 80047EC4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 386C8 80047EC8 1000B0AF */  sw         $s0, 0x10($sp)
    /* 386CC 80047ECC 21800000 */  addu       $s0, $zero, $zero
    /* 386D0 80047ED0 1400BFAF */  sw         $ra, 0x14($sp)
    /* 386D4 80047ED4 21200000 */  addu       $a0, $zero, $zero
  .L80047ED8:
    /* 386D8 80047ED8 B4DB010C */  jal        func_80076ED0
    /* 386DC 80047EDC F000053C */   lui       $a1, (0xF00000 >> 16)
    /* 386E0 80047EE0 0A80043C */  lui        $a0, %hi(D_8009B45C)
    /* 386E4 80047EE4 5CB4848C */  lw         $a0, %lo(D_8009B45C)($a0)
    /* 386E8 80047EE8 F1DC010C */  jal        func_800773C4
    /* 386EC 80047EEC D8158424 */   addiu     $a0, $a0, 0x15D8
    /* 386F0 80047EF0 0A80033C */  lui        $v1, %hi(D_8009B45C)
    /* 386F4 80047EF4 5CB4638C */  lw         $v1, %lo(D_8009B45C)($v1)
    /* 386F8 80047EF8 00000000 */  nop
    /* 386FC 80047EFC EF156490 */  lbu        $a0, 0x15EF($v1)
    /* 38700 80047F00 ED156290 */  lbu        $v0, 0x15ED($v1)
    /* 38704 80047F04 EE156390 */  lbu        $v1, 0x15EE($v1)
    /* 38708 80047F08 21108200 */  addu       $v0, $a0, $v0
    /* 3870C 80047F0C 21104300 */  addu       $v0, $v0, $v1
    /* 38710 80047F10 21104400 */  addu       $v0, $v0, $a0
    /* 38714 80047F14 04004010 */  beqz       $v0, .L80047F28
    /* 38718 80047F18 01001026 */   addiu     $s0, $s0, 0x1
    /* 3871C 80047F1C 1800022A */  slti       $v0, $s0, 0x18
    /* 38720 80047F20 EDFF4014 */  bnez       $v0, .L80047ED8
    /* 38724 80047F24 21200000 */   addu      $a0, $zero, $zero
  .L80047F28:
    /* 38728 80047F28 1400BF8F */  lw         $ra, 0x14($sp)
    /* 3872C 80047F2C 1000B08F */  lw         $s0, 0x10($sp)
    /* 38730 80047F30 0800E003 */  jr         $ra
    /* 38734 80047F34 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80047EC4
