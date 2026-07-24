nonmatching func_8007CC8C, 0x78

glabel func_8007CC8C
    /* 6D48C 8007CC8C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 6D490 8007CC90 1000B0AF */  sw         $s0, 0x10($sp)
    /* 6D494 8007CC94 0980103C */  lui        $s0, %hi(D_80093880)
    /* 6D498 8007CC98 80381026 */  addiu      $s0, $s0, %lo(D_80093880)
    /* 6D49C 8007CC9C 1400BFAF */  sw         $ra, 0x14($sp)
    /* 6D4A0 8007CCA0 34E8010C */  jal        func_8007A0D0
    /* 6D4A4 8007CCA4 000000AE */   sw        $zero, 0x0($s0)
    /* 6D4A8 8007CCA8 2000038E */  lw         $v1, 0x20($s0)
    /* 6D4AC 8007CCAC 02000224 */  addiu      $v0, $zero, 0x2
    /* 6D4B0 8007CCB0 480000AE */  sw         $zero, 0x48($s0)
    /* 6D4B4 8007CCB4 0F006214 */  bne        $v1, $v0, .L8007CCF4
    /* 6D4B8 8007CCB8 440000AE */   sw        $zero, 0x44($s0)
    /* 6D4BC 8007CCBC 2400038E */  lw         $v1, 0x24($s0)
    /* 6D4C0 8007CCC0 0B000224 */  addiu      $v0, $zero, 0xB
    /* 6D4C4 8007CCC4 05006210 */  beq        $v1, $v0, .L8007CCDC
    /* 6D4C8 8007CCC8 11000224 */   addiu     $v0, $zero, 0x11
    /* 6D4CC 8007CCCC 03006210 */  beq        $v1, $v0, .L8007CCDC
    /* 6D4D0 8007CCD0 10000224 */   addiu     $v0, $zero, 0x10
    /* 6D4D4 8007CCD4 07006214 */  bne        $v1, $v0, .L8007CCF4
    /* 6D4D8 8007CCD8 00000000 */   nop
  .L8007CCDC:
    /* 6D4DC 8007CCDC 0980023C */  lui        $v0, %hi(D_800938A0)
    /* 6D4E0 8007CCE0 A0384224 */  addiu      $v0, $v0, %lo(D_800938A0)
    /* 6D4E4 8007CCE4 01000324 */  addiu      $v1, $zero, 0x1
    /* 6D4E8 8007CCE8 000043AC */  sw         $v1, 0x0($v0)
    /* 6D4EC 8007CCEC 0B000324 */  addiu      $v1, $zero, 0xB
    /* 6D4F0 8007CCF0 040043AC */  sw         $v1, 0x4($v0)
  .L8007CCF4:
    /* 6D4F4 8007CCF4 1400BF8F */  lw         $ra, 0x14($sp)
    /* 6D4F8 8007CCF8 1000B08F */  lw         $s0, 0x10($sp)
    /* 6D4FC 8007CCFC 0800E003 */  jr         $ra
    /* 6D500 8007CD00 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8007CC8C
