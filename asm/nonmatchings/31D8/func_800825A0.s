nonmatching func_800825A0, 0x64

glabel func_800825A0
    /* 72DA0 800825A0 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 72DA4 800825A4 21108000 */  addu       $v0, $a0, $zero
    /* 72DA8 800825A8 1800B0AF */  sw         $s0, 0x18($sp)
    /* 72DAC 800825AC 2180A000 */  addu       $s0, $a1, $zero
    /* 72DB0 800825B0 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 72DB4 800825B4 2188C000 */  addu       $s1, $a2, $zero
    /* 72DB8 800825B8 1000A427 */  addiu      $a0, $sp, 0x10
    /* 72DBC 800825BC 21284000 */  addu       $a1, $v0, $zero
    /* 72DC0 800825C0 00010224 */  addiu      $v0, $zero, 0x100
    /* 72DC4 800825C4 1400A2A7 */  sh         $v0, 0x14($sp)
    /* 72DC8 800825C8 01000224 */  addiu      $v0, $zero, 0x1
    /* 72DCC 800825CC 2000BFAF */  sw         $ra, 0x20($sp)
    /* 72DD0 800825D0 1000B0A7 */  sh         $s0, 0x10($sp)
    /* 72DD4 800825D4 1200B1A7 */  sh         $s1, 0x12($sp)
    /* 72DD8 800825D8 5EFE010C */  jal        func_8007F978
    /* 72DDC 800825DC 1600A2A7 */   sh        $v0, 0x16($sp)
    /* 72DE0 800825E0 21200002 */  addu       $a0, $s0, $zero
    /* 72DE4 800825E4 F009020C */  jal        func_800827C0
    /* 72DE8 800825E8 21282002 */   addu      $a1, $s1, $zero
    /* 72DEC 800825EC FFFF4230 */  andi       $v0, $v0, 0xFFFF
    /* 72DF0 800825F0 2000BF8F */  lw         $ra, 0x20($sp)
    /* 72DF4 800825F4 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 72DF8 800825F8 1800B08F */  lw         $s0, 0x18($sp)
    /* 72DFC 800825FC 0800E003 */  jr         $ra
    /* 72E00 80082600 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_800825A0
    /* 72E04 80082604 00000000 */  nop
    /* 72E08 80082608 00000000 */  nop
    /* 72E0C 8008260C 00000000 */  nop
