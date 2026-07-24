nonmatching func_80049BAC, 0x94

glabel func_80049BAC
    /* 3A3AC 80049BAC 0A80023C */  lui        $v0, %hi(D_8009B458)
    /* 3A3B0 80049BB0 58B4428C */  lw         $v0, %lo(D_8009B458)($v0)
    /* 3A3B4 80049BB4 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 3A3B8 80049BB8 1400B1AF */  sw         $s1, 0x14($sp)
    /* 3A3BC 80049BBC 21888000 */  addu       $s1, $a0, $zero
    /* 3A3C0 80049BC0 1000B0AF */  sw         $s0, 0x10($sp)
    /* 3A3C4 80049BC4 01001024 */  addiu      $s0, $zero, 0x1
    /* 3A3C8 80049BC8 1800BFAF */  sw         $ra, 0x18($sp)
    /* 3A3CC 80049BCC 000550A0 */  sb         $s0, 0x500($v0)
    /* 3A3D0 80049BD0 0A80043C */  lui        $a0, %hi(D_8009B458)
    /* 3A3D4 80049BD4 58B4848C */  lw         $a0, %lo(D_8009B458)($a0)
    /* 3A3D8 80049BD8 00000000 */  nop
    /* 3A3DC 80049BDC E0078384 */  lh         $v1, 0x7E0($a0)
    /* 3A3E0 80049BE0 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 3A3E4 80049BE4 03006214 */  bne        $v1, $v0, .L80049BF4
    /* 3A3E8 80049BE8 0100023C */   lui       $v0, (0x10000 >> 16)
    /* 3A3EC 80049BEC 0B270108 */  j          .L80049C2C
    /* 3A3F0 80049BF0 000580A0 */   sb        $zero, 0x500($a0)
  .L80049BF4:
    /* 3A3F4 80049BF4 E807838C */  lw         $v1, 0x7E8($a0)
    /* 3A3F8 80049BF8 EC0782AC */  sw         $v0, 0x7EC($a0)
    /* 3A3FC 80049BFC DF31010C */  jal        func_8004C77C
    /* 3A400 80049C00 DC0783AC */   sw        $v1, 0x7DC($a0)
    /* 3A404 80049C04 0A80023C */  lui        $v0, %hi(D_8009B458)
    /* 3A408 80049C08 58B4428C */  lw         $v0, %lo(D_8009B458)($v0)
    /* 3A40C 80049C0C 00000000 */  nop
    /* 3A410 80049C10 020550A0 */  sb         $s0, 0x502($v0)
    /* 3A414 80049C14 0A80033C */  lui        $v1, %hi(D_8009B458)
    /* 3A418 80049C18 58B4638C */  lw         $v1, %lo(D_8009B458)($v1)
    /* 3A41C 80049C1C 0C0851AC */  sw         $s1, 0x80C($v0)
    /* 3A420 80049C20 01000224 */  addiu      $v0, $zero, 0x1
    /* 3A424 80049C24 E20762A4 */  sh         $v0, 0x7E2($v1)
    /* 3A428 80049C28 000560A0 */  sb         $zero, 0x500($v1)
  .L80049C2C:
    /* 3A42C 80049C2C 1800BF8F */  lw         $ra, 0x18($sp)
    /* 3A430 80049C30 1400B18F */  lw         $s1, 0x14($sp)
    /* 3A434 80049C34 1000B08F */  lw         $s0, 0x10($sp)
    /* 3A438 80049C38 0800E003 */  jr         $ra
    /* 3A43C 80049C3C 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_80049BAC
