nonmatching func_8003C0C0, 0x60

glabel func_8003C0C0
    /* 2C8C0 8003C0C0 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 2C8C4 8003C0C4 2000B0AF */  sw         $s0, 0x20($sp)
    /* 2C8C8 8003C0C8 21800000 */  addu       $s0, $zero, $zero
    /* 2C8CC 8003C0CC 2400BFAF */  sw         $ra, 0x24($sp)
    /* 2C8D0 8003C0D0 2AB3000C */  jal        func_8002CCA8
    /* 2C8D4 8003C0D4 47000424 */   addiu     $a0, $zero, 0x47
    /* 2C8D8 8003C0D8 02004010 */  beqz       $v0, .L8003C0E4
    /* 2C8DC 8003C0DC 21200000 */   addu      $a0, $zero, $zero
    /* 2C8E0 8003C0E0 9E001024 */  addiu      $s0, $zero, 0x9E
  .L8003C0E4:
    /* 2C8E4 8003C0E4 0480023C */  lui        $v0, %hi(func_8003BF00)
    /* 2C8E8 8003C0E8 00BF4224 */  addiu      $v0, $v0, %lo(func_8003BF00)
    /* 2C8EC 8003C0EC 21288000 */  addu       $a1, $a0, $zero
    /* 2C8F0 8003C0F0 D91F0626 */  addiu      $a2, $s0, 0x1FD9
    /* 2C8F4 8003C0F4 9E000724 */  addiu      $a3, $zero, 0x9E
    /* 2C8F8 8003C0F8 1000A2AF */  sw         $v0, 0x10($sp)
    /* 2C8FC 8003C0FC 1400A0AF */  sw         $zero, 0x14($sp)
    /* 2C900 8003C100 8753000C */  jal        func_80014E1C
    /* 2C904 8003C104 1800A0AF */   sw        $zero, 0x18($sp)
    /* 2C908 8003C108 F94D000C */  jal        func_800137E4
    /* 2C90C 8003C10C 00000000 */   nop
    /* 2C910 8003C110 2400BF8F */  lw         $ra, 0x24($sp)
    /* 2C914 8003C114 2000B08F */  lw         $s0, 0x20($sp)
    /* 2C918 8003C118 0800E003 */  jr         $ra
    /* 2C91C 8003C11C 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_8003C0C0
