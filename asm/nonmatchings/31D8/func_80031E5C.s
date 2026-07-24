nonmatching func_80031E5C, 0x88

glabel func_80031E5C
    /* 2265C 80031E5C D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 22660 80031E60 21288000 */  addu       $a1, $a0, $zero
    /* 22664 80031E64 03000424 */  addiu      $a0, $zero, 0x3
    /* 22668 80031E68 1D80033C */  lui        $v1, %hi(D_801D5608)
    /* 2266C 80031E6C 16000624 */  addiu      $a2, $zero, 0x16
    /* 22670 80031E70 2400BFAF */  sw         $ra, 0x24($sp)
    /* 22674 80031E74 2000B0AF */  sw         $s0, 0x20($sp)
    /* 22678 80031E78 9C5AA28C */  lw         $v0, 0x5A9C($a1)
    /* 2267C 80031E7C 17000724 */  addiu      $a3, $zero, 0x17
    /* 22680 80031E80 085662AC */  sw         $v0, %lo(D_801D5608)($v1)
    /* 22684 80031E84 A05AA58C */  lw         $a1, 0x5AA0($a1)
    /* 22688 80031E88 80020224 */  addiu      $v0, $zero, 0x280
    /* 2268C 80031E8C 1000A2AF */  sw         $v0, 0x10($sp)
    /* 22690 80031E90 10000224 */  addiu      $v0, $zero, 0x10
    /* 22694 80031E94 1400A2AF */  sw         $v0, 0x14($sp)
    /* 22698 80031E98 00010224 */  addiu      $v0, $zero, 0x100
    /* 2269C 80031E9C 08566324 */  addiu      $v1, $v1, %lo(D_801D5608)
    /* 226A0 80031EA0 1800A2AF */  sw         $v0, 0x18($sp)
    /* 226A4 80031EA4 040065AC */  sw         $a1, 0x4($v1)
    /* 226A8 80031EA8 0ED7000C */  jal        func_80035C38
    /* 226AC 80031EAC 0E000524 */   addiu     $a1, $zero, 0xE
    /* 226B0 80031EB0 21804000 */  addu       $s0, $v0, $zero
    /* 226B4 80031EB4 85E6000C */  jal        func_80039A14
    /* 226B8 80031EB8 21200002 */   addu      $a0, $s0, $zero
    /* 226BC 80031EBC 2800038E */  lw         $v1, 0x28($s0)
    /* 226C0 80031EC0 00000000 */  nop
    /* 226C4 80031EC4 08006294 */  lhu        $v0, 0x8($v1)
    /* 226C8 80031EC8 00000000 */  nop
    /* 226CC 80031ECC F7FF4230 */  andi       $v0, $v0, 0xFFF7
    /* 226D0 80031ED0 080062A4 */  sh         $v0, 0x8($v1)
    /* 226D4 80031ED4 2400BF8F */  lw         $ra, 0x24($sp)
    /* 226D8 80031ED8 2000B08F */  lw         $s0, 0x20($sp)
    /* 226DC 80031EDC 0800E003 */  jr         $ra
    /* 226E0 80031EE0 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_80031E5C
