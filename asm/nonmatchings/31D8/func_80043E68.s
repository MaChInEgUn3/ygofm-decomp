nonmatching func_80043E68, 0x54

glabel func_80043E68
    /* 34668 80043E68 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 3466C 80043E6C 0F80023C */  lui        $v0, %hi(D_800F2AE0)
    /* 34670 80043E70 1400B1AF */  sw         $s1, 0x14($sp)
    /* 34674 80043E74 E02A5124 */  addiu      $s1, $v0, %lo(D_800F2AE0)
    /* 34678 80043E78 1800BFAF */  sw         $ra, 0x18($sp)
    /* 3467C 80043E7C 2CCE010C */  jal        func_800738B0
    /* 34680 80043E80 1000B0AF */   sw        $s0, 0x10($sp)
    /* 34684 80043E84 08001024 */  addiu      $s0, $zero, 0x8
  .L80043E88:
    /* 34688 80043E88 0000248E */  lw         $a0, 0x0($s1)
    /* 3468C 80043E8C 04003126 */  addiu      $s1, $s1, 0x4
    /* 34690 80043E90 1CCE010C */  jal        func_80073870
    /* 34694 80043E94 FFFF1026 */   addiu     $s0, $s0, -0x1
    /* 34698 80043E98 FBFF0016 */  bnez       $s0, .L80043E88
    /* 3469C 80043E9C 00000000 */   nop
    /* 346A0 80043EA0 30CE010C */  jal        func_800738C0
    /* 346A4 80043EA4 00000000 */   nop
    /* 346A8 80043EA8 1800BF8F */  lw         $ra, 0x18($sp)
    /* 346AC 80043EAC 1400B18F */  lw         $s1, 0x14($sp)
    /* 346B0 80043EB0 1000B08F */  lw         $s0, 0x10($sp)
    /* 346B4 80043EB4 0800E003 */  jr         $ra
    /* 346B8 80043EB8 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_80043E68
