nonmatching func_80059B90, 0x88

glabel func_80059B90
    /* 4A390 80059B90 68FFBD27 */  addiu      $sp, $sp, -0x98
    /* 4A394 80059B94 8800B0AF */  sw         $s0, 0x88($sp)
    /* 4A398 80059B98 21808000 */  addu       $s0, $a0, $zero
    /* 4A39C 80059B9C 8C00B1AF */  sw         $s1, 0x8C($sp)
    /* 4A3A0 80059BA0 2188A000 */  addu       $s1, $a1, $zero
    /* 4A3A4 80059BA4 1000A427 */  addiu      $a0, $sp, 0x10
    /* 4A3A8 80059BA8 21280000 */  addu       $a1, $zero, $zero
    /* 4A3AC 80059BAC 9000BFAF */  sw         $ra, 0x90($sp)
    /* 4A3B0 80059BB0 F438020C */  jal        func_8008E3D0
    /* 4A3B4 80059BB4 08000624 */   addiu     $a2, $zero, 0x8
    /* 4A3B8 80059BB8 21200000 */  addu       $a0, $zero, $zero
    /* 4A3BC 80059BBC 0F000524 */  addiu      $a1, $zero, 0xF
    /* 4A3C0 80059BC0 1000A627 */  addiu      $a2, $sp, 0x10
    /* 4A3C4 80059BC4 1000B0A7 */  sh         $s0, 0x10($sp)
    /* 4A3C8 80059BC8 1800B027 */  addiu      $s0, $sp, 0x18
    /* 4A3CC 80059BCC 3560010C */  jal        func_800580D4
    /* 4A3D0 80059BD0 21380002 */   addu      $a3, $s0, $zero
    /* 4A3D4 80059BD4 21200002 */  addu       $a0, $s0, $zero
    /* 4A3D8 80059BD8 2829020C */  jal        func_8008A4A0
    /* 4A3DC 80059BDC 6800A527 */   addiu     $a1, $sp, 0x68
    /* 4A3E0 80059BE0 7C00A297 */  lhu        $v0, 0x7C($sp)
    /* 4A3E4 80059BE4 00000000 */  nop
    /* 4A3E8 80059BE8 000022A6 */  sh         $v0, 0x0($s1)
    /* 4A3EC 80059BEC 8000A297 */  lhu        $v0, 0x80($sp)
    /* 4A3F0 80059BF0 00000000 */  nop
    /* 4A3F4 80059BF4 020022A6 */  sh         $v0, 0x2($s1)
    /* 4A3F8 80059BF8 8400A297 */  lhu        $v0, 0x84($sp)
    /* 4A3FC 80059BFC 060020A6 */  sh         $zero, 0x6($s1)
    /* 4A400 80059C00 040022A6 */  sh         $v0, 0x4($s1)
    /* 4A404 80059C04 9000BF8F */  lw         $ra, 0x90($sp)
    /* 4A408 80059C08 8C00B18F */  lw         $s1, 0x8C($sp)
    /* 4A40C 80059C0C 8800B08F */  lw         $s0, 0x88($sp)
    /* 4A410 80059C10 0800E003 */  jr         $ra
    /* 4A414 80059C14 9800BD27 */   addiu     $sp, $sp, 0x98
endlabel func_80059B90
