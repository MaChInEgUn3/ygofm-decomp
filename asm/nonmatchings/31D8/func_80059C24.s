nonmatching func_80059C24, 0x64

glabel func_80059C24
    /* 4A424 80059C24 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 4A428 80059C28 1800BFAF */  sw         $ra, 0x18($sp)
    /* 4A42C 80059C2C F64C010C */  jal        func_800533D8
    /* 4A430 80059C30 00000000 */   nop
    /* 4A434 80059C34 314C010C */  jal        func_800530C4
    /* 4A438 80059C38 00000000 */   nop
    /* 4A43C 80059C3C 21200000 */  addu       $a0, $zero, $zero
    /* 4A440 80059C40 10270524 */  addiu      $a1, $zero, 0x2710
    /* 4A444 80059C44 000E0624 */  addiu      $a2, $zero, 0xE00
    /* 4A448 80059C48 21388000 */  addu       $a3, $a0, $zero
    /* 4A44C 80059C4C 13000224 */  addiu      $v0, $zero, 0x13
    /* 4A450 80059C50 8C0082A3 */  sb         $v0, %gp_rel(D_8009AF94)($gp)
    /* 4A454 80059C54 EE7C010C */  jal        func_8005F3B8
    /* 4A458 80059C58 1000A0AF */   sw        $zero, 0x10($sp)
    /* 4A45C 80059C5C 21200000 */  addu       $a0, $zero, $zero
    /* 4A460 80059C60 05000524 */  addiu      $a1, $zero, 0x5
    /* 4A464 80059C64 21308000 */  addu       $a2, $a0, $zero
    /* 4A468 80059C68 21388000 */  addu       $a3, $a0, $zero
    /* 4A46C 80059C6C 6465010C */  jal        func_80059590
    /* 4A470 80059C70 1000A0AF */   sw        $zero, 0x10($sp)
    /* 4A474 80059C74 1800BF8F */  lw         $ra, 0x18($sp)
    /* 4A478 80059C78 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 4A47C 80059C7C 920082A3 */  sb         $v0, %gp_rel(D_8009AF9A)($gp)
    /* 4A480 80059C80 0800E003 */  jr         $ra
    /* 4A484 80059C84 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_80059C24
