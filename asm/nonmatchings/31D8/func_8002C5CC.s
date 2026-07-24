nonmatching func_8002C5CC, 0x38

glabel func_8002C5CC
    /* 1CDCC 8002C5CC 0F80023C */  lui        $v0, %hi(D_800EAD88)
    /* 1CDD0 8002C5D0 88AD4324 */  addiu      $v1, $v0, %lo(D_800EAD88)
    /* 1CDD4 8002C5D4 08000424 */  addiu      $a0, $zero, 0x8
  .L8002C5D8:
    /* 1CDD8 8002C5D8 1C006290 */  lbu        $v0, 0x1C($v1)
    /* 1CDDC 8002C5DC 00000000 */  nop
    /* 1CDE0 8002C5E0 80004230 */  andi       $v0, $v0, 0x80
    /* 1CDE4 8002C5E4 03004014 */  bnez       $v0, .L8002C5F4
    /* 1CDE8 8002C5E8 FFFF8424 */   addiu     $a0, $a0, -0x1
    /* 1CDEC 8002C5EC 0800E003 */  jr         $ra
    /* 1CDF0 8002C5F0 21106000 */   addu      $v0, $v1, $zero
  .L8002C5F4:
    /* 1CDF4 8002C5F4 F8FF8014 */  bnez       $a0, .L8002C5D8
    /* 1CDF8 8002C5F8 20006324 */   addiu     $v1, $v1, 0x20
    /* 1CDFC 8002C5FC 0800E003 */  jr         $ra
    /* 1CE00 8002C600 21100000 */   addu      $v0, $zero, $zero
endlabel func_8002C5CC
