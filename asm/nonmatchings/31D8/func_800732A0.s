nonmatching func_800732A0, 0x60

glabel func_800732A0
    /* 63AA0 800732A0 21280000 */  addu       $a1, $zero, $zero
    /* 63AA4 800732A4 0F80023C */  lui        $v0, %hi(D_800F5BE8)
    /* 63AA8 800732A8 E85B4324 */  addiu      $v1, $v0, %lo(D_800F5BE8)
    /* 63AAC 800732AC 2110A000 */  addu       $v0, $a1, $zero
    /* 63AB0 800732B0 11004014 */  bnez       $v0, .L800732F8
    /* 63AB4 800732B4 2120A000 */   addu      $a0, $a1, $zero
    /* 63AB8 800732B8 21306000 */  addu       $a2, $v1, $zero
    /* 63ABC 800732BC 0F80023C */  lui        $v0, %hi(D_800EAE88)
    /* 63AC0 800732C0 88AE4724 */  addiu      $a3, $v0, %lo(D_800EAE88)
    /* 63AC4 800732C4 21108600 */  addu       $v0, $a0, $a2
  .L800732C8:
    /* 63AC8 800732C8 38004390 */  lbu        $v1, 0x38($v0)
    /* 63ACC 800732CC 00000000 */  nop
    /* 63AD0 800732D0 0B006228 */  slti       $v0, $v1, 0xB
    /* 63AD4 800732D4 03004014 */  bnez       $v0, .L800732E4
    /* 63AD8 800732D8 2110A700 */   addu      $v0, $a1, $a3
    /* 63ADC 800732DC 000043A0 */  sb         $v1, 0x0($v0)
    /* 63AE0 800732E0 0100A524 */  addiu      $a1, $a1, 0x1
  .L800732E4:
    /* 63AE4 800732E4 A300C290 */  lbu        $v0, 0xA3($a2)
    /* 63AE8 800732E8 01008424 */  addiu      $a0, $a0, 0x1
    /* 63AEC 800732EC 2A104400 */  slt        $v0, $v0, $a0
    /* 63AF0 800732F0 F5FF4010 */  beqz       $v0, .L800732C8
    /* 63AF4 800732F4 21108600 */   addu      $v0, $a0, $a2
  .L800732F8:
    /* 63AF8 800732F8 0800E003 */  jr         $ra
    /* 63AFC 800732FC 00000000 */   nop
endlabel func_800732A0
