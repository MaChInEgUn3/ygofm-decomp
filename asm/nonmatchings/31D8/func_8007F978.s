nonmatching func_8007F978, 0x60

glabel func_8007F978
    /* 70178 8007F978 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 7017C 8007F97C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 70180 8007F980 21808000 */  addu       $s0, $a0, $zero
    /* 70184 8007F984 1400B1AF */  sw         $s1, 0x14($sp)
    /* 70188 8007F988 2188A000 */  addu       $s1, $a1, $zero
    /* 7018C 8007F98C 0180043C */  lui        $a0, %hi(D_80012274)
    /* 70190 8007F990 74228424 */  addiu      $a0, $a0, %lo(D_80012274)
    /* 70194 8007F994 1800BFAF */  sw         $ra, 0x18($sp)
    /* 70198 8007F998 CDFD010C */  jal        func_8007F734
    /* 7019C 8007F99C 21280002 */   addu      $a1, $s0, $zero
    /* 701A0 8007F9A0 21280002 */  addu       $a1, $s0, $zero
    /* 701A4 8007F9A4 0980023C */  lui        $v0, %hi(D_80094660)
    /* 701A8 8007F9A8 6046428C */  lw         $v0, %lo(D_80094660)($v0)
    /* 701AC 8007F9AC 08000624 */  addiu      $a2, $zero, 0x8
    /* 701B0 8007F9B0 2000448C */  lw         $a0, 0x20($v0)
    /* 701B4 8007F9B4 0800428C */  lw         $v0, 0x8($v0)
    /* 701B8 8007F9B8 00000000 */  nop
    /* 701BC 8007F9BC 09F84000 */  jalr       $v0
    /* 701C0 8007F9C0 21382002 */   addu      $a3, $s1, $zero
    /* 701C4 8007F9C4 1800BF8F */  lw         $ra, 0x18($sp)
    /* 701C8 8007F9C8 1400B18F */  lw         $s1, 0x14($sp)
    /* 701CC 8007F9CC 1000B08F */  lw         $s0, 0x10($sp)
    /* 701D0 8007F9D0 0800E003 */  jr         $ra
    /* 701D4 8007F9D4 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8007F978
