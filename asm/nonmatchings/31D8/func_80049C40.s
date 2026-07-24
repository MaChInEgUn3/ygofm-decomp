nonmatching func_80049C40, 0x70

glabel func_80049C40
    /* 3A440 80049C40 0A80043C */  lui        $a0, %hi(D_8009B458)
    /* 3A444 80049C44 58B4848C */  lw         $a0, %lo(D_8009B458)($a0)
    /* 3A448 80049C48 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 3A44C 80049C4C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 3A450 80049C50 E0078384 */  lh         $v1, 0x7E0($a0)
    /* 3A454 80049C54 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 3A458 80049C58 11006210 */  beq        $v1, $v0, .L80049CA0
    /* 3A45C 80049C5C 01000224 */   addiu     $v0, $zero, 0x1
    /* 3A460 80049C60 9832010C */  jal        func_8004CA60
    /* 3A464 80049C64 000582A0 */   sb        $v0, 0x500($a0)
    /* 3A468 80049C68 4629010C */  jal        func_8004A518
    /* 3A46C 80049C6C 00000000 */   nop
    /* 3A470 80049C70 0A80033C */  lui        $v1, %hi(D_8009B458)
    /* 3A474 80049C74 58B4638C */  lw         $v1, %lo(D_8009B458)($v1)
    /* 3A478 80049C78 00000000 */  nop
    /* 3A47C 80049C7C 000560A0 */  sb         $zero, 0x500($v1)
    /* 3A480 80049C80 0A80043C */  lui        $a0, %hi(D_8009B458)
    /* 3A484 80049C84 58B4848C */  lw         $a0, %lo(D_8009B458)($a0)
    /* 3A488 80049C88 7F000224 */  addiu      $v0, $zero, 0x7F
    /* 3A48C 80049C8C E60762A4 */  sh         $v0, 0x7E6($v1)
    /* 3A490 80049C90 E40762A4 */  sh         $v0, 0x7E4($v1)
    /* 3A494 80049C94 02000224 */  addiu      $v0, $zero, 0x2
    /* 3A498 80049C98 E20762A4 */  sh         $v0, 0x7E2($v1)
    /* 3A49C 80049C9C 020580A0 */  sb         $zero, 0x502($a0)
  .L80049CA0:
    /* 3A4A0 80049CA0 1000BF8F */  lw         $ra, 0x10($sp)
    /* 3A4A4 80049CA4 00000000 */  nop
    /* 3A4A8 80049CA8 0800E003 */  jr         $ra
    /* 3A4AC 80049CAC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80049C40
