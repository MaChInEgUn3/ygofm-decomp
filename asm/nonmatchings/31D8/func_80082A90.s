nonmatching func_80082A90, 0x64

glabel func_80082A90
    /* 73290 80082A90 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 73294 80082A94 1000B0AF */  sw         $s0, 0x10($sp)
    /* 73298 80082A98 21808000 */  addu       $s0, $a0, $zero
    /* 7329C 80082A9C 1080043C */  lui        $a0, %hi(D_800FE000)
    /* 732A0 80082AA0 00E0848C */  lw         $a0, %lo(D_800FE000)($a0)
    /* 732A4 80082AA4 1400BFAF */  sw         $ra, 0x14($sp)
    /* 732A8 80082AA8 BD0A020C */  jal        func_80082AF4
    /* 732AC 80082AAC 21280002 */   addu      $a1, $s0, $zero
    /* 732B0 80082AB0 21204000 */  addu       $a0, $v0, $zero
    /* 732B4 80082AB4 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 732B8 80082AB8 09008210 */  beq        $a0, $v0, .L80082AE0
    /* 732BC 80082ABC 80200400 */   sll       $a0, $a0, 2
    /* 732C0 80082AC0 1080033C */  lui        $v1, %hi(D_800FE000)
    /* 732C4 80082AC4 00E0638C */  lw         $v1, %lo(D_800FE000)($v1)
    /* 732C8 80082AC8 00000000 */  nop
    /* 732CC 80082ACC 21186400 */  addu       $v1, $v1, $a0
    /* 732D0 80082AD0 1080013C */  lui        $at, %hi(D_800FE000)
    /* 732D4 80082AD4 00E023AC */  sw         $v1, %lo(D_800FE000)($at)
    /* 732D8 80082AD8 B90A0208 */  j          .L80082AE4
    /* 732DC 80082ADC 21100002 */   addu      $v0, $s0, $zero
  .L80082AE0:
    /* 732E0 80082AE0 21100000 */  addu       $v0, $zero, $zero
  .L80082AE4:
    /* 732E4 80082AE4 1400BF8F */  lw         $ra, 0x14($sp)
    /* 732E8 80082AE8 1000B08F */  lw         $s0, 0x10($sp)
    /* 732EC 80082AEC 0800E003 */  jr         $ra
    /* 732F0 80082AF0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80082A90
