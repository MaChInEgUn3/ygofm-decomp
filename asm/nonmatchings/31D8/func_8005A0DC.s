nonmatching func_8005A0DC, 0x54

glabel func_8005A0DC
    /* 4A8DC 8005A0DC E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 4A8E0 8005A0E0 1400B1AF */  sw         $s1, 0x14($sp)
    /* 4A8E4 8005A0E4 21888000 */  addu       $s1, $a0, $zero
    /* 4A8E8 8005A0E8 1800BFAF */  sw         $ra, 0x18($sp)
    /* 4A8EC 8005A0EC 5D7C010C */  jal        func_8005F174
    /* 4A8F0 8005A0F0 1000B0AF */   sw        $s0, 0x10($sp)
    /* 4A8F4 8005A0F4 21804000 */  addu       $s0, $v0, $zero
    /* 4A8F8 8005A0F8 01000224 */  addiu      $v0, $zero, 0x1
    /* 4A8FC 8005A0FC 05000216 */  bne        $s0, $v0, .L8005A114
    /* 4A900 8005A100 0F80033C */   lui       $v1, %hi(D_800F2B22)
    /* 4A904 8005A104 637C010C */  jal        func_8005F18C
    /* 4A908 8005A108 00000000 */   nop
    /* 4A90C 8005A10C 03005010 */  beq        $v0, $s0, .L8005A11C
    /* 4A910 8005A110 0F80033C */   lui       $v1, %hi(D_800F2B22)
  .L8005A114:
    /* 4A914 8005A114 40101100 */  sll        $v0, $s1, 1
    /* 4A918 8005A118 222B62A4 */  sh         $v0, %lo(D_800F2B22)($v1)
  .L8005A11C:
    /* 4A91C 8005A11C 1800BF8F */  lw         $ra, 0x18($sp)
    /* 4A920 8005A120 1400B18F */  lw         $s1, 0x14($sp)
    /* 4A924 8005A124 1000B08F */  lw         $s0, 0x10($sp)
    /* 4A928 8005A128 0800E003 */  jr         $ra
    /* 4A92C 8005A12C 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8005A0DC
