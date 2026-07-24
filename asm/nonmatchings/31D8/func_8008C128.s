nonmatching func_8008C128, 0x44

glabel func_8008C128
    /* 7C928 8008C128 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 7C92C 8008C12C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 7C930 8008C130 1080103C */  lui        $s0, %hi(D_800FE35C)
    /* 7C934 8008C134 5CE31026 */  addiu      $s0, $s0, %lo(D_800FE35C)
    /* 7C938 8008C138 1400BFAF */  sw         $ra, 0x14($sp)
    /* 7C93C 8008C13C 0000048E */  lw         $a0, 0x0($s0)
    /* 7C940 8008C140 00000000 */  nop
    /* 7C944 8008C144 05008004 */  bltz       $a0, .L8008C15C
    /* 7C948 8008C148 00000000 */   nop
    /* 7C94C 8008C14C 44CE010C */  jal        func_80073910
    /* 7C950 8008C150 00000000 */   nop
    /* 7C954 8008C154 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 7C958 8008C158 000002AE */  sw         $v0, 0x0($s0)
  .L8008C15C:
    /* 7C95C 8008C15C 1400BF8F */  lw         $ra, 0x14($sp)
    /* 7C960 8008C160 1000B08F */  lw         $s0, 0x10($sp)
    /* 7C964 8008C164 0800E003 */  jr         $ra
    /* 7C968 8008C168 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8008C128
