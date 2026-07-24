nonmatching func_800138F4, 0x4C

glabel func_800138F4
    /* 40F4 800138F4 C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* 40F8 800138F8 2C00B1AF */  sw         $s1, 0x2C($sp)
    /* 40FC 800138FC 21888000 */  addu       $s1, $a0, $zero
    /* 4100 80013900 2800B0AF */  sw         $s0, 0x28($sp)
    /* 4104 80013904 2180A000 */  addu       $s0, $a1, $zero
    /* 4108 80013908 3000BFAF */  sw         $ra, 0x30($sp)
    /* 410C 8001390C 1000A427 */  addiu      $a0, $sp, 0x10
  .L80013910:
    /* 4110 80013910 FCF4010C */  jal        func_8007D3F0
    /* 4114 80013914 21280002 */   addu      $a1, $s0, $zero
    /* 4118 80013918 FDFF4010 */  beqz       $v0, .L80013910
    /* 411C 8001391C 1000A427 */   addiu     $a0, $sp, 0x10
    /* 4120 80013920 C4F9010C */  jal        func_8007E710
    /* 4124 80013924 1000A427 */   addiu     $a0, $sp, 0x10
    /* 4128 80013928 000022AE */  sw         $v0, 0x0($s1)
    /* 412C 8001392C 3000BF8F */  lw         $ra, 0x30($sp)
    /* 4130 80013930 2C00B18F */  lw         $s1, 0x2C($sp)
    /* 4134 80013934 2800B08F */  lw         $s0, 0x28($sp)
    /* 4138 80013938 0800E003 */  jr         $ra
    /* 413C 8001393C 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel func_800138F4
