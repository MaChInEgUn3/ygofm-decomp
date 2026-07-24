nonmatching func_8002BF3C, 0x90

glabel func_8002BF3C
    /* 1C73C 8002BF3C E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 1C740 8002BF40 1D80023C */  lui        $v0, %hi(D_801D0250)
    /* 1C744 8002BF44 1400B1AF */  sw         $s1, 0x14($sp)
    /* 1C748 8002BF48 50025124 */  addiu      $s1, $v0, %lo(D_801D0250)
    /* 1C74C 8002BF4C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1C750 8002BF50 21800000 */  addu       $s0, $zero, $zero
    /* 1C754 8002BF54 1800BFAF */  sw         $ra, 0x18($sp)
  .L8002BF58:
    /* 1C758 8002BF58 00002292 */  lbu        $v0, 0x0($s1)
    /* 1C75C 8002BF5C 00000000 */  nop
    /* 1C760 8002BF60 03004010 */  beqz       $v0, .L8002BF70
    /* 1C764 8002BF64 00000000 */   nop
    /* 1C768 8002BF68 39B3000C */  jal        func_8002CCE4
    /* 1C76C 8002BF6C 21010426 */   addiu     $a0, $s0, 0x121
  .L8002BF70:
    /* 1C770 8002BF70 01001026 */  addiu      $s0, $s0, 0x1
    /* 1C774 8002BF74 D202022A */  slti       $v0, $s0, 0x2D2
    /* 1C778 8002BF78 F7FF4014 */  bnez       $v0, .L8002BF58
    /* 1C77C 8002BF7C 01003126 */   addiu     $s1, $s1, 0x1
    /* 1C780 8002BF80 1D80023C */  lui        $v0, %hi(D_801D0200)
    /* 1C784 8002BF84 00025124 */  addiu      $s1, $v0, %lo(D_801D0200)
    /* 1C788 8002BF88 21800000 */  addu       $s0, $zero, $zero
  .L8002BF8C:
    /* 1C78C 8002BF8C 00002296 */  lhu        $v0, 0x0($s1)
    /* 1C790 8002BF90 00000000 */  nop
    /* 1C794 8002BF94 04004010 */  beqz       $v0, .L8002BFA8
    /* 1C798 8002BF98 00000000 */   nop
    /* 1C79C 8002BF9C 21204000 */  addu       $a0, $v0, $zero
    /* 1C7A0 8002BFA0 39B3000C */  jal        func_8002CCE4
    /* 1C7A4 8002BFA4 20018424 */   addiu     $a0, $a0, 0x120
  .L8002BFA8:
    /* 1C7A8 8002BFA8 01001026 */  addiu      $s0, $s0, 0x1
    /* 1C7AC 8002BFAC 2800022A */  slti       $v0, $s0, 0x28
    /* 1C7B0 8002BFB0 F6FF4014 */  bnez       $v0, .L8002BF8C
    /* 1C7B4 8002BFB4 02003126 */   addiu     $s1, $s1, 0x2
    /* 1C7B8 8002BFB8 1800BF8F */  lw         $ra, 0x18($sp)
    /* 1C7BC 8002BFBC 1400B18F */  lw         $s1, 0x14($sp)
    /* 1C7C0 8002BFC0 1000B08F */  lw         $s0, 0x10($sp)
    /* 1C7C4 8002BFC4 0800E003 */  jr         $ra
    /* 1C7C8 8002BFC8 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8002BF3C
