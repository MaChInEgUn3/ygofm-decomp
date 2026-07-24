nonmatching func_80038798, 0x68

glabel func_80038798
    /* 28F98 80038798 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 28F9C 8003879C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 28FA0 800387A0 1400BFAF */  sw         $ra, 0x14($sp)
    /* 28FA4 800387A4 4FDB000C */  jal        func_80036D3C
    /* 28FA8 800387A8 21808000 */   addu      $s0, $a0, $zero
    /* 28FAC 800387AC FFFF4430 */  andi       $a0, $v0, 0xFFFF
    /* 28FB0 800387B0 00808230 */  andi       $v0, $a0, 0x8000
    /* 28FB4 800387B4 0C004010 */  beqz       $v0, .L800387E8
    /* 28FB8 800387B8 00000000 */   nop
    /* 28FBC 800387BC E2FF000C */  jal        func_8003FF88
    /* 28FC0 800387C0 00000000 */   nop
    /* 28FC4 800387C4 4FDB000C */  jal        func_80036D3C
    /* 28FC8 800387C8 21200002 */   addu      $a0, $s0, $zero
    /* 28FCC 800387CC 340482A7 */  sh         $v0, %gp_rel(D_8009B33C)($gp)
    /* 28FD0 800387D0 11000224 */  addiu      $v0, $zero, 0x11
    /* 28FD4 800387D4 510002A2 */  sb         $v0, 0x51($s0)
    /* 28FD8 800387D8 01000224 */  addiu      $v0, $zero, 0x1
    /* 28FDC 800387DC 480482AF */  sw         $v0, %gp_rel(D_8009B350)($gp)
    /* 28FE0 800387E0 FCE10008 */  j          .L800387F0
    /* 28FE4 800387E4 00000000 */   nop
  .L800387E8:
    /* 28FE8 800387E8 B8FF000C */  jal        func_8003FEE0
    /* 28FEC 800387EC 00000000 */   nop
  .L800387F0:
    /* 28FF0 800387F0 1400BF8F */  lw         $ra, 0x14($sp)
    /* 28FF4 800387F4 1000B08F */  lw         $s0, 0x10($sp)
    /* 28FF8 800387F8 0800E003 */  jr         $ra
    /* 28FFC 800387FC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80038798
