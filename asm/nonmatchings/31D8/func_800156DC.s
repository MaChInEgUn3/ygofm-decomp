nonmatching func_800156DC, 0x50

glabel func_800156DC
    /* 5EDC 800156DC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 5EE0 800156E0 01000224 */  addiu      $v0, $zero, 0x1
    /* 5EE4 800156E4 1000BFAF */  sw         $ra, 0x10($sp)
    /* 5EE8 800156E8 3D0282A3 */  sb         $v0, %gp_rel(D_8009B145)($gp)
    /* 5EEC 800156EC 2E56000C */  jal        func_800158B8
    /* 5EF0 800156F0 00000000 */   nop
    /* 5EF4 800156F4 0F80023C */  lui        $v0, %hi(D_800E9EC8)
    /* 5EF8 800156F8 C89E4224 */  addiu      $v0, $v0, %lo(D_800E9EC8)
    /* 5EFC 800156FC 060040A0 */  sb         $zero, 0x6($v0)
    /* 5F00 80015700 040040A0 */  sb         $zero, 0x4($v0)
    /* 5F04 80015704 FF000224 */  addiu      $v0, $zero, 0xFF
    /* 5F08 80015708 3A0282A3 */  sb         $v0, %gp_rel(D_8009B142)($gp)
    /* 5F0C 8001570C 3B0282A3 */  sb         $v0, %gp_rel(D_8009B143)($gp)
    /* 5F10 80015710 3C0282A3 */  sb         $v0, %gp_rel(D_8009B144)($gp)
    /* 5F14 80015714 4357000C */  jal        func_80015D0C
    /* 5F18 80015718 00000000 */   nop
    /* 5F1C 8001571C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 5F20 80015720 00000000 */  nop
    /* 5F24 80015724 0800E003 */  jr         $ra
    /* 5F28 80015728 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800156DC
