nonmatching func_80015780, 0x5C

glabel func_80015780
    /* 5F80 80015780 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 5F84 80015784 1000B0AF */  sw         $s0, 0x10($sp)
    /* 5F88 80015788 0F80103C */  lui        $s0, %hi(D_800E9EC8)
    /* 5F8C 8001578C C89E1026 */  addiu      $s0, $s0, %lo(D_800E9EC8)
    /* 5F90 80015790 FF000224 */  addiu      $v0, $zero, 0xFF
    /* 5F94 80015794 1400BFAF */  sw         $ra, 0x14($sp)
    /* 5F98 80015798 050002A2 */  sb         $v0, 0x5($s0)
    /* 5F9C 8001579C 80000224 */  addiu      $v0, $zero, 0x80
    /* 5FA0 800157A0 060002A2 */  sb         $v0, 0x6($s0)
    /* 5FA4 800157A4 39028293 */  lbu        $v0, %gp_rel(D_8009B141)($gp)
    /* 5FA8 800157A8 04000492 */  lbu        $a0, 0x4($s0)
    /* 5FAC 800157AC 080000A6 */  sh         $zero, 0x8($s0)
    /* 5FB0 800157B0 7F004230 */  andi       $v0, $v0, 0x7F
    /* 5FB4 800157B4 390282A3 */  sb         $v0, %gp_rel(D_8009B141)($gp)
    /* 5FB8 800157B8 AE55000C */  jal        func_800156B8
    /* 5FBC 800157BC 00000000 */   nop
    /* 5FC0 800157C0 0C000224 */  addiu      $v0, $zero, 0xC
    /* 5FC4 800157C4 CB55000C */  jal        func_8001572C
    /* 5FC8 800157C8 070002A2 */   sb        $v0, 0x7($s0)
    /* 5FCC 800157CC 1400BF8F */  lw         $ra, 0x14($sp)
    /* 5FD0 800157D0 1000B08F */  lw         $s0, 0x10($sp)
    /* 5FD4 800157D4 0800E003 */  jr         $ra
    /* 5FD8 800157D8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80015780
