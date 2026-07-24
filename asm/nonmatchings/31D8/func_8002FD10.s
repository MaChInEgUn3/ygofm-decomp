nonmatching func_8002FD10, 0x1C0

glabel func_8002FD10
    /* 20510 8002FD10 C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* 20514 8002FD14 9C0384A7 */  sh         $a0, %gp_rel(D_8009B2A4)($gp)
    /* 20518 8002FD18 21200000 */  addu       $a0, $zero, $zero
    /* 2051C 8002FD1C 21288000 */  addu       $a1, $a0, $zero
    /* 20520 8002FD20 0380023C */  lui        $v0, %hi(func_8002FB78)
    /* 20524 8002FD24 78FB4224 */  addiu      $v0, $v0, %lo(func_8002FB78)
    /* 20528 8002FD28 2000B0AF */  sw         $s0, 0x20($sp)
    /* 2052C 8002FD2C 0F80103C */  lui        $s0, %hi(D_800EAE98)
    /* 20530 8002FD30 98AE1026 */  addiu      $s0, $s0, %lo(D_800EAE98)
    /* 20534 8002FD34 571E0624 */  addiu      $a2, $zero, 0x1E57
    /* 20538 8002FD38 31000724 */  addiu      $a3, $zero, 0x31
    /* 2053C 8002FD3C 3000BFAF */  sw         $ra, 0x30($sp)
    /* 20540 8002FD40 2C00B3AF */  sw         $s3, 0x2C($sp)
    /* 20544 8002FD44 2800B2AF */  sw         $s2, 0x28($sp)
    /* 20548 8002FD48 2400B1AF */  sw         $s1, 0x24($sp)
    /* 2054C 8002FD4C 0A80013C */  lui        $at, %hi(D_8009B148)
    /* 20550 8002FD50 48B120A4 */  sh         $zero, %lo(D_8009B148)($at)
    /* 20554 8002FD54 0A80013C */  lui        $at, %hi(D_8009B146)
    /* 20558 8002FD58 46B120A4 */  sh         $zero, %lo(D_8009B146)($at)
    /* 2055C 8002FD5C 980380AF */  sw         $zero, %gp_rel(D_8009B2A0)($gp)
    /* 20560 8002FD60 1000A2AF */  sw         $v0, 0x10($sp)
    /* 20564 8002FD64 1400A0AF */  sw         $zero, 0x14($sp)
    /* 20568 8002FD68 8753000C */  jal        func_80014E1C
    /* 2056C 8002FD6C 1800A0AF */   sw        $zero, 0x18($sp)
    /* 20570 8002FD70 A7E7000C */  jal        func_80039E9C
    /* 20574 8002FD74 21880000 */   addu      $s1, $zero, $zero
    /* 20578 8002FD78 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 2057C 8002FD7C 3C0002A6 */  sh         $v0, 0x3C($s0)
  .L8002FD80:
    /* 20580 8002FD80 000000AE */  sw         $zero, 0x0($s0)
    /* 20584 8002FD84 040000A6 */  sh         $zero, 0x4($s0)
    /* 20588 8002FD88 01003126 */  addiu      $s1, $s1, 0x1
    /* 2058C 8002FD8C 0300222A */  slti       $v0, $s1, 0x3
    /* 20590 8002FD90 FBFF4014 */  bnez       $v0, .L8002FD80
    /* 20594 8002FD94 14001026 */   addiu     $s0, $s0, 0x14
    /* 20598 8002FD98 F94D000C */  jal        func_800137E4
    /* 2059C 8002FD9C 00000000 */   nop
  .L8002FDA0:
    /* 205A0 8002FDA0 C908020C */  jal        func_80082324
    /* 205A4 8002FDA4 0A000424 */   addiu     $a0, $zero, 0xA
    /* 205A8 8002FDA8 FDFF4014 */  bnez       $v0, .L8002FDA0
    /* 205AC 8002FDAC 0F80023C */   lui       $v0, %hi(D_800E9D70)
    /* 205B0 8002FDB0 21880000 */  addu       $s1, $zero, $zero
    /* 205B4 8002FDB4 21984000 */  addu       $s3, $v0, $zero
    /* 205B8 8002FDB8 709D6226 */  addiu      $v0, $s3, %lo(D_800E9D70)
    /* 205BC 8002FDBC 21804000 */  addu       $s0, $v0, $zero
    /* 205C0 8002FDC0 80030324 */  addiu      $v1, $zero, 0x380
    /* 205C4 8002FDC4 0180123C */  lui        $s2, %hi(D_80010000)
    /* 205C8 8002FDC8 0000528E */  lw         $s2, %lo(D_80010000)($s2)
    /* 205CC 8002FDCC 18000224 */  addiu      $v0, $zero, 0x18
    /* 205D0 8002FDD0 709D63A6 */  sh         $v1, %lo(D_800E9D70)($s3)
    /* 205D4 8002FDD4 040002A6 */  sh         $v0, 0x4($s0)
    /* 205D8 8002FDD8 30000224 */  addiu      $v0, $zero, 0x30
    /* 205DC 8002FDDC 080003A6 */  sh         $v1, 0x8($s0)
    /* 205E0 8002FDE0 08000326 */  addiu      $v1, $s0, 0x8
    /* 205E4 8002FDE4 060002A6 */  sh         $v0, 0x6($s0)
    /* 205E8 8002FDE8 F0000224 */  addiu      $v0, $zero, 0xF0
    /* 205EC 8002FDEC 020000A6 */  sh         $zero, 0x2($s0)
    /* 205F0 8002FDF0 020062A4 */  sh         $v0, 0x2($v1)
    /* 205F4 8002FDF4 40000224 */  addiu      $v0, $zero, 0x40
    /* 205F8 8002FDF8 040062A4 */  sh         $v0, 0x4($v1)
    /* 205FC 8002FDFC 01000224 */  addiu      $v0, $zero, 0x1
    /* 20600 8002FE00 060062A4 */  sh         $v0, 0x6($v1)
  .L8002FE04:
    /* 20604 8002FE04 21200002 */  addu       $a0, $s0, $zero
    /* 20608 8002FE08 7A07020C */  jal        func_80081DE8
    /* 2060C 8002FE0C 21284002 */   addu      $a1, $s2, $zero
    /* 20610 8002FE10 08000426 */  addiu      $a0, $s0, 0x8
    /* 20614 8002FE14 7A07020C */  jal        func_80081DE8
    /* 20618 8002FE18 00094526 */   addiu     $a1, $s2, 0x900
    /* 2061C 8002FE1C 01003126 */  addiu      $s1, $s1, 0x1
    /* 20620 8002FE20 6666023C */  lui        $v0, (0x66666667 >> 16)
    /* 20624 8002FE24 67664234 */  ori        $v0, $v0, (0x66666667 & 0xFFFF)
    /* 20628 8002FE28 18002202 */  mult       $s1, $v0
    /* 2062C 8002FE2C 0A000496 */  lhu        $a0, 0xA($s0)
    /* 20630 8002FE30 C3171100 */  sra        $v0, $s1, 31
    /* 20634 8002FE34 01008424 */  addiu      $a0, $a0, 0x1
    /* 20638 8002FE38 0A0004A6 */  sh         $a0, 0xA($s0)
    /* 2063C 8002FE3C 00240400 */  sll        $a0, $a0, 16
    /* 20640 8002FE40 03240400 */  sra        $a0, $a0, 16
    /* 20644 8002FE44 00018428 */  slti       $a0, $a0, 0x100
    /* 20648 8002FE48 10400000 */  mfhi       $t0
    /* 2064C 8002FE4C 43280800 */  sra        $a1, $t0, 1
    /* 20650 8002FE50 2328A200 */  subu       $a1, $a1, $v0
    /* 20654 8002FE54 80180500 */  sll        $v1, $a1, 2
    /* 20658 8002FE58 21186500 */  addu       $v1, $v1, $a1
    /* 2065C 8002FE5C 23182302 */  subu       $v1, $s1, $v1
    /* 20660 8002FE60 40100300 */  sll        $v0, $v1, 1
    /* 20664 8002FE64 21104300 */  addu       $v0, $v0, $v1
    /* 20668 8002FE68 C0100200 */  sll        $v0, $v0, 3
    /* 2066C 8002FE6C 80034224 */  addiu      $v0, $v0, 0x380
    /* 20670 8002FE70 709D62A6 */  sh         $v0, %lo(D_800E9D70)($s3)
    /* 20674 8002FE74 40100500 */  sll        $v0, $a1, 1
    /* 20678 8002FE78 21104500 */  addu       $v0, $v0, $a1
    /* 2067C 8002FE7C 00110200 */  sll        $v0, $v0, 4
    /* 20680 8002FE80 06008014 */  bnez       $a0, .L8002FE9C
    /* 20684 8002FE84 020002A6 */   sh        $v0, 0x2($s0)
    /* 20688 8002FE88 08000396 */  lhu        $v1, 0x8($s0)
    /* 2068C 8002FE8C F0000224 */  addiu      $v0, $zero, 0xF0
    /* 20690 8002FE90 0A0002A6 */  sh         $v0, 0xA($s0)
    /* 20694 8002FE94 40006324 */  addiu      $v1, $v1, 0x40
    /* 20698 8002FE98 080003A6 */  sh         $v1, 0x8($s0)
  .L8002FE9C:
    /* 2069C 8002FE9C 1900222A */  slti       $v0, $s1, 0x19
    /* 206A0 8002FEA0 D8FF4014 */  bnez       $v0, .L8002FE04
    /* 206A4 8002FEA4 80095226 */   addiu     $s2, $s2, 0x980
    /* 206A8 8002FEA8 FFB8000C */  jal        func_8002E3FC
    /* 206AC 8002FEAC 00000000 */   nop
    /* 206B0 8002FEB0 3000BF8F */  lw         $ra, 0x30($sp)
    /* 206B4 8002FEB4 2C00B38F */  lw         $s3, 0x2C($sp)
    /* 206B8 8002FEB8 2800B28F */  lw         $s2, 0x28($sp)
    /* 206BC 8002FEBC 2400B18F */  lw         $s1, 0x24($sp)
    /* 206C0 8002FEC0 2000B08F */  lw         $s0, 0x20($sp)
    /* 206C4 8002FEC4 980382AF */  sw         $v0, %gp_rel(D_8009B2A0)($gp)
    /* 206C8 8002FEC8 0800E003 */  jr         $ra
    /* 206CC 8002FECC 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel func_8002FD10
