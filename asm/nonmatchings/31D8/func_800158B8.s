nonmatching func_800158B8, 0x4C

glabel func_800158B8
    /* 60B8 800158B8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 60BC 800158BC 1000B0AF */  sw         $s0, 0x10($sp)
    /* 60C0 800158C0 0F80103C */  lui        $s0, %hi(D_800E9EC8)
    /* 60C4 800158C4 C89E1026 */  addiu      $s0, $s0, %lo(D_800E9EC8)
    /* 60C8 800158C8 1400BFAF */  sw         $ra, 0x14($sp)
    /* 60CC 800158CC 04000492 */  lbu        $a0, 0x4($s0)
    /* 60D0 800158D0 FF000224 */  addiu      $v0, $zero, 0xFF
    /* 60D4 800158D4 080002A6 */  sh         $v0, 0x8($s0)
    /* 60D8 800158D8 80000224 */  addiu      $v0, $zero, 0x80
    /* 60DC 800158DC 050000A2 */  sb         $zero, 0x5($s0)
    /* 60E0 800158E0 AE55000C */  jal        func_800156B8
    /* 60E4 800158E4 060002A2 */   sb        $v0, 0x6($s0)
    /* 60E8 800158E8 0C000224 */  addiu      $v0, $zero, 0xC
    /* 60EC 800158EC 1C56000C */  jal        func_80015870
    /* 60F0 800158F0 070002A2 */   sb        $v0, 0x7($s0)
    /* 60F4 800158F4 1400BF8F */  lw         $ra, 0x14($sp)
    /* 60F8 800158F8 1000B08F */  lw         $s0, 0x10($sp)
    /* 60FC 800158FC 0800E003 */  jr         $ra
    /* 6100 80015900 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800158B8
