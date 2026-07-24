nonmatching func_80013A94, 0x70

glabel func_80013A94
    /* 4294 80013A94 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 4298 80013A98 21188000 */  addu       $v1, $a0, $zero
    /* 429C 80013A9C EC01828F */  lw         $v0, %gp_rel(D_8009B0F4)($gp)
    /* 42A0 80013AA0 2130A000 */  addu       $a2, $a1, $zero
    /* 42A4 80013AA4 1400BFAF */  sw         $ra, 0x14($sp)
    /* 42A8 80013AA8 20004230 */  andi       $v0, $v0, 0x20
    /* 42AC 80013AAC 10004014 */  bnez       $v0, .L80013AF0
    /* 42B0 80013AB0 1000B0AF */   sw        $s0, 0x10($sp)
    /* 42B4 80013AB4 0F80103C */  lui        $s0, %hi(D_800E9E18)
    /* 42B8 80013AB8 189E1026 */  addiu      $s0, $s0, %lo(D_800E9E18)
    /* 42BC 80013ABC 21200002 */  addu       $a0, $s0, $zero
    /* 42C0 80013AC0 0F006530 */  andi       $a1, $v1, 0xF
    /* 42C4 80013AC4 504E000C */  jal        func_80013940
    /* 42C8 80013AC8 21380000 */   addu      $a3, $zero, $zero
    /* 42CC 80013ACC 21100002 */  addu       $v0, $s0, $zero
    /* 42D0 80013AD0 460040A0 */  sb         $zero, 0x46($v0)
    /* 42D4 80013AD4 EC01838F */  lw         $v1, %gp_rel(D_8009B0F4)($gp)
    /* 42D8 80013AD8 1000043C */  lui        $a0, (0x100000 >> 16)
    /* 42DC 80013ADC 2C0044AC */  sw         $a0, 0x2C($v0)
    /* 42E0 80013AE0 20006334 */  ori        $v1, $v1, 0x20
    /* 42E4 80013AE4 EC0183AF */  sw         $v1, %gp_rel(D_8009B0F4)($gp)
    /* 42E8 80013AE8 BD4E0008 */  j          .L80013AF4
    /* 42EC 80013AEC 00000000 */   nop
  .L80013AF0:
    /* 42F0 80013AF0 21100000 */  addu       $v0, $zero, $zero
  .L80013AF4:
    /* 42F4 80013AF4 1400BF8F */  lw         $ra, 0x14($sp)
    /* 42F8 80013AF8 1000B08F */  lw         $s0, 0x10($sp)
    /* 42FC 80013AFC 0800E003 */  jr         $ra
    /* 4300 80013B00 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80013A94
