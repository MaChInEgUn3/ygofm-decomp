nonmatching func_8007F4C4, 0x5C

glabel func_8007F4C4
    /* 6FCC4 8007F4C4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 6FCC8 8007F4C8 0980033C */  lui        $v1, %hi(D_8009466A)
    /* 6FCCC 8007F4CC 6A466324 */  addiu      $v1, $v1, %lo(D_8009466A)
    /* 6FCD0 8007F4D0 1400BFAF */  sw         $ra, 0x14($sp)
    /* 6FCD4 8007F4D4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 6FCD8 8007F4D8 00007090 */  lbu        $s0, 0x0($v1)
    /* 6FCDC 8007F4DC 000064A0 */  sb         $a0, 0x0($v1)
    /* 6FCE0 8007F4E0 FF008430 */  andi       $a0, $a0, 0xFF
    /* 6FCE4 8007F4E4 0A008010 */  beqz       $a0, .L8007F510
    /* 6FCE8 8007F4E8 21100002 */   addu      $v0, $s0, $zero
    /* 6FCEC 8007F4EC 0980023C */  lui        $v0, %hi(D_80094664)
    /* 6FCF0 8007F4F0 6446428C */  lw         $v0, %lo(D_80094664)($v0)
    /* 6FCF4 8007F4F4 00006590 */  lbu        $a1, 0x0($v1)
    /* 6FCF8 8007F4F8 FEFF6690 */  lbu        $a2, -0x2($v1)
    /* 6FCFC 8007F4FC 01006790 */  lbu        $a3, 0x1($v1)
    /* 6FD00 8007F500 0180043C */  lui        $a0, %hi(D_800121B4)
    /* 6FD04 8007F504 09F84000 */  jalr       $v0
    /* 6FD08 8007F508 B4218424 */   addiu     $a0, $a0, %lo(D_800121B4)
    /* 6FD0C 8007F50C 21100002 */  addu       $v0, $s0, $zero
  .L8007F510:
    /* 6FD10 8007F510 1400BF8F */  lw         $ra, 0x14($sp)
    /* 6FD14 8007F514 1000B08F */  lw         $s0, 0x10($sp)
    /* 6FD18 8007F518 0800E003 */  jr         $ra
    /* 6FD1C 8007F51C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8007F4C4
