nonmatching func_80059AA8, 0x38

glabel func_80059AA8
    /* 4A2A8 80059AA8 0F80033C */  lui        $v1, %hi(D_800F2C40)
    /* 4A2AC 80059AAC 402C6324 */  addiu      $v1, $v1, %lo(D_800F2C40)
    /* 4A2B0 80059AB0 C0100400 */  sll        $v0, $a0, 3
    /* 4A2B4 80059AB4 23104400 */  subu       $v0, $v0, $a0
    /* 4A2B8 80059AB8 00110200 */  sll        $v0, $v0, 4
    /* 4A2BC 80059ABC 21104400 */  addu       $v0, $v0, $a0
    /* 4A2C0 80059AC0 40110200 */  sll        $v0, $v0, 5
    /* 4A2C4 80059AC4 21104300 */  addu       $v0, $v0, $v1
    /* 4A2C8 80059AC8 120E4390 */  lbu        $v1, 0xE12($v0)
    /* 4A2CC 80059ACC 0200A004 */  bltz       $a1, .L80059AD8
    /* 4A2D0 80059AD0 00000000 */   nop
    /* 4A2D4 80059AD4 120E45A0 */  sb         $a1, 0xE12($v0)
  .L80059AD8:
    /* 4A2D8 80059AD8 0800E003 */  jr         $ra
    /* 4A2DC 80059ADC 21106000 */   addu      $v0, $v1, $zero
endlabel func_80059AA8
