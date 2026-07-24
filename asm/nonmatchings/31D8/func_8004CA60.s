nonmatching func_8004CA60, 0x5C

glabel func_8004CA60
    /* 3D260 8004CA60 0A80033C */  lui        $v1, %hi(D_8009B458)
    /* 3D264 8004CA64 58B4638C */  lw         $v1, %lo(D_8009B458)($v1)
    /* 3D268 8004CA68 00000000 */  nop
    /* 3D26C 8004CA6C FA076294 */  lhu        $v0, 0x7FA($v1)
    /* 3D270 8004CA70 00000000 */  nop
    /* 3D274 8004CA74 0F004010 */  beqz       $v0, .L8004CAB4
    /* 3D278 8004CA78 21280000 */   addu      $a1, $zero, $zero
    /* 3D27C 8004CA7C 01000624 */  addiu      $a2, $zero, 0x1
    /* 3D280 8004CA80 2120A000 */  addu       $a0, $a1, $zero
  .L8004CA84:
    /* 3D284 8004CA84 21106400 */  addu       $v0, $v1, $a0
    /* 3D288 8004CA88 3C0546A0 */  sb         $a2, 0x53C($v0)
    /* 3D28C 8004CA8C 0A80033C */  lui        $v1, %hi(D_8009B458)
    /* 3D290 8004CA90 58B4638C */  lw         $v1, %lo(D_8009B458)($v1)
    /* 3D294 8004CA94 0100A524 */  addiu      $a1, $a1, 0x1
    /* 3D298 8004CA98 21106400 */  addu       $v0, $v1, $a0
    /* 3D29C 8004CA9C 180540AC */  sw         $zero, 0x518($v0)
    /* 3D2A0 8004CAA0 FA076294 */  lhu        $v0, 0x7FA($v1)
    /* 3D2A4 8004CAA4 00000000 */  nop
    /* 3D2A8 8004CAA8 2A10A200 */  slt        $v0, $a1, $v0
    /* 3D2AC 8004CAAC F5FF4014 */  bnez       $v0, .L8004CA84
    /* 3D2B0 8004CAB0 2C008424 */   addiu     $a0, $a0, 0x2C
  .L8004CAB4:
    /* 3D2B4 8004CAB4 0800E003 */  jr         $ra
    /* 3D2B8 8004CAB8 00000000 */   nop
endlabel func_8004CA60
