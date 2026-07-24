nonmatching func_8003CC38, 0xA0

glabel func_8003CC38
    /* 2D438 8003CC38 0F80023C */  lui        $v0, %hi(D_800EF668)
    /* 2D43C 8003CC3C 68F64390 */  lbu        $v1, %lo(D_800EF668)($v0)
    /* 2D440 8003CC40 00000000 */  nop
    /* 2D444 8003CC44 0F006014 */  bnez       $v1, .L8003CC84
    /* 2D448 8003CC48 68F64424 */   addiu     $a0, $v0, %lo(D_800EF668)
    /* 2D44C 8003CC4C 01008290 */  lbu        $v0, 0x1($a0)
    /* 2D450 8003CC50 00000000 */  nop
    /* 2D454 8003CC54 0F004230 */  andi       $v0, $v0, 0xF
    /* 2D458 8003CC58 0A004010 */  beqz       $v0, .L8003CC84
    /* 2D45C 8003CC5C 0F80023C */   lui       $v0, %hi(D_800EF668)
    /* 2D460 8003CC60 02008290 */  lbu        $v0, 0x2($a0)
    /* 2D464 8003CC64 03008390 */  lbu        $v1, 0x3($a0)
    /* 2D468 8003CC68 00120200 */  sll        $v0, $v0, 8
    /* 2D46C 8003CC6C 25104300 */  or         $v0, $v0, $v1
    /* 2D470 8003CC70 A004838F */  lw         $v1, %gp_rel(D_8009B3A8)($gp)
    /* 2D474 8003CC74 FFFF4238 */  xori       $v0, $v0, 0xFFFF
    /* 2D478 8003CC78 25186200 */  or         $v1, $v1, $v0
    /* 2D47C 8003CC7C A00483AF */  sw         $v1, %gp_rel(D_8009B3A8)($gp)
    /* 2D480 8003CC80 0F80023C */  lui        $v0, %hi(D_800EF668)
  .L8003CC84:
    /* 2D484 8003CC84 68F64324 */  addiu      $v1, $v0, %lo(D_800EF668)
    /* 2D488 8003CC88 22006290 */  lbu        $v0, 0x22($v1)
    /* 2D48C 8003CC8C 00000000 */  nop
    /* 2D490 8003CC90 0F004014 */  bnez       $v0, .L8003CCD0
    /* 2D494 8003CC94 00000000 */   nop
    /* 2D498 8003CC98 23006290 */  lbu        $v0, 0x23($v1)
    /* 2D49C 8003CC9C 00000000 */  nop
    /* 2D4A0 8003CCA0 0F004230 */  andi       $v0, $v0, 0xF
    /* 2D4A4 8003CCA4 0A004010 */  beqz       $v0, .L8003CCD0
    /* 2D4A8 8003CCA8 00000000 */   nop
    /* 2D4AC 8003CCAC 24006290 */  lbu        $v0, 0x24($v1)
    /* 2D4B0 8003CCB0 25006390 */  lbu        $v1, 0x25($v1)
    /* 2D4B4 8003CCB4 00120200 */  sll        $v0, $v0, 8
    /* 2D4B8 8003CCB8 25104300 */  or         $v0, $v0, $v1
    /* 2D4BC 8003CCBC FFFF4238 */  xori       $v0, $v0, 0xFFFF
    /* 2D4C0 8003CCC0 A004838F */  lw         $v1, %gp_rel(D_8009B3A8)($gp)
    /* 2D4C4 8003CCC4 00140200 */  sll        $v0, $v0, 16
    /* 2D4C8 8003CCC8 25186200 */  or         $v1, $v1, $v0
    /* 2D4CC 8003CCCC A00483AF */  sw         $v1, %gp_rel(D_8009B3A8)($gp)
  .L8003CCD0:
    /* 2D4D0 8003CCD0 0800E003 */  jr         $ra
    /* 2D4D4 8003CCD4 00000000 */   nop
endlabel func_8003CC38
