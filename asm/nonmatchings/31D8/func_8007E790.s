nonmatching func_8007E790, 0x54

glabel func_8007E790
    /* 6EF90 8007E790 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 6EF94 8007E794 1000B0AF */  sw         $s0, 0x10($sp)
    /* 6EF98 8007E798 21808000 */  addu       $s0, $a0, $zero
    /* 6EF9C 8007E79C 05000016 */  bnez       $s0, .L8007E7B4
    /* 6EFA0 8007E7A0 1400BFAF */   sw        $ra, 0x14($sp)
    /* 6EFA4 8007E7A4 C9EF010C */  jal        func_8007BF24
    /* 6EFA8 8007E7A8 00000000 */   nop
    /* 6EFAC 8007E7AC F5F90108 */  j          .L8007E7D4
    /* 6EFB0 8007E7B0 00000000 */   nop
  .L8007E7B4:
    /* 6EFB4 8007E7B4 C9EF010C */  jal        func_8007BF24
    /* 6EFB8 8007E7B8 00000000 */   nop
    /* 6EFBC 8007E7BC 03004388 */  lwl        $v1, 0x3($v0)
    /* 6EFC0 8007E7C0 00004398 */  lwr        $v1, 0x0($v0)
    /* 6EFC4 8007E7C4 00000000 */  nop
    /* 6EFC8 8007E7C8 030003AA */  swl        $v1, 0x3($s0)
    /* 6EFCC 8007E7CC 000003BA */  swr        $v1, 0x0($s0)
    /* 6EFD0 8007E7D0 21100002 */  addu       $v0, $s0, $zero
  .L8007E7D4:
    /* 6EFD4 8007E7D4 1400BF8F */  lw         $ra, 0x14($sp)
    /* 6EFD8 8007E7D8 1000B08F */  lw         $s0, 0x10($sp)
    /* 6EFDC 8007E7DC 0800E003 */  jr         $ra
    /* 6EFE0 8007E7E0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8007E790
    /* 6EFE4 8007E7E4 00000000 */  nop
    /* 6EFE8 8007E7E8 00000000 */  nop
    /* 6EFEC 8007E7EC 00000000 */  nop
