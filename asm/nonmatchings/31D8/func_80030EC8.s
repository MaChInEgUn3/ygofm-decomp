nonmatching func_80030EC8, 0x78

glabel func_80030EC8
    /* 216C8 80030EC8 E3038393 */  lbu        $v1, %gp_rel(D_8009B2EB)($gp)
    /* 216CC 80030ECC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 216D0 80030ED0 80006230 */  andi       $v0, $v1, 0x80
    /* 216D4 80030ED4 07004014 */  bnez       $v0, .L80030EF4
    /* 216D8 80030ED8 1000BFAF */   sw        $ra, 0x10($sp)
    /* 216DC 80030EDC 80006234 */  ori        $v0, $v1, 0x80
    /* 216E0 80030EE0 E30382A3 */  sb         $v0, %gp_rel(D_8009B2EB)($gp)
    /* 216E4 80030EE4 0A80013C */  lui        $at, %hi(D_8009B3ED)
    /* 216E8 80030EE8 EDB320A0 */  sb         $zero, %lo(D_8009B3ED)($at)
    /* 216EC 80030EEC 0A80013C */  lui        $at, %hi(D_8009B3EA)
    /* 216F0 80030EF0 EAB320A0 */  sb         $zero, %lo(D_8009B3EA)($at)
  .L80030EF4:
    /* 216F4 80030EF4 36FF000C */  jal        func_8003FCD8
    /* 216F8 80030EF8 00000000 */   nop
    /* 216FC 80030EFC 21184000 */  addu       $v1, $v0, $zero
    /* 21700 80030F00 0B006010 */  beqz       $v1, .L80030F30
    /* 21704 80030F04 01000224 */   addiu     $v0, $zero, 0x1
    /* 21708 80030F08 08006214 */  bne        $v1, $v0, .L80030F2C
    /* 2170C 80030F0C 00000000 */   nop
    /* 21710 80030F10 176E010C */  jal        func_8005B85C
    /* 21714 80030F14 00000000 */   nop
    /* 21718 80030F18 F94D000C */  jal        func_800137E4
    /* 2171C 80030F1C 00000000 */   nop
    /* 21720 80030F20 0E000224 */  addiu      $v0, $zero, 0xE
    /* 21724 80030F24 0A80013C */  lui        $at, %hi(D_8009B26C)
    /* 21728 80030F28 6CB222A0 */  sb         $v0, %lo(D_8009B26C)($at)
  .L80030F2C:
    /* 2172C 80030F2C E30380A3 */  sb         $zero, %gp_rel(D_8009B2EB)($gp)
  .L80030F30:
    /* 21730 80030F30 1000BF8F */  lw         $ra, 0x10($sp)
    /* 21734 80030F34 00000000 */  nop
    /* 21738 80030F38 0800E003 */  jr         $ra
    /* 2173C 80030F3C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80030EC8
