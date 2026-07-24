nonmatching func_8003F87C, 0x58

glabel func_8003F87C
    /* 3007C 8003F87C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 30080 8003F880 1000B0AF */  sw         $s0, 0x10($sp)
    /* 30084 8003F884 1D80103C */  lui        $s0, %hi(D_801D3200)
    /* 30088 8003F888 00321026 */  addiu      $s0, $s0, %lo(D_801D3200)
    /* 3008C 8003F88C 21200002 */  addu       $a0, $s0, $zero
    /* 30090 8003F890 1D80053C */  lui        $a1, %hi(D_801D0200)
    /* 30094 8003F894 0002A524 */  addiu      $a1, $a1, %lo(D_801D0200)
    /* 30098 8003F898 1400BFAF */  sw         $ra, 0x14($sp)
    /* 3009C 8003F89C A8D5000C */  jal        func_800356A0
    /* 300A0 8003F8A0 80060624 */   addiu     $a2, $zero, 0x680
    /* 300A4 8003F8A4 0FF4000C */  jal        func_8003D03C
    /* 300A8 8003F8A8 00FE0426 */   addiu     $a0, $s0, -0x200
    /* 300AC 8003F8AC 21200002 */  addu       $a0, $s0, $zero
    /* 300B0 8003F8B0 000D0524 */  addiu      $a1, $zero, 0xD00
    /* 300B4 8003F8B4 0180063C */  lui        $a2, %hi(D_80010384)
    /* 300B8 8003F8B8 8403C624 */  addiu      $a2, $a2, %lo(D_80010384)
    /* 300BC 8003F8BC D6FD000C */  jal        func_8003F758
    /* 300C0 8003F8C0 02000724 */   addiu     $a3, $zero, 0x2
    /* 300C4 8003F8C4 1400BF8F */  lw         $ra, 0x14($sp)
    /* 300C8 8003F8C8 1000B08F */  lw         $s0, 0x10($sp)
    /* 300CC 8003F8CC 0800E003 */  jr         $ra
    /* 300D0 8003F8D0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8003F87C
