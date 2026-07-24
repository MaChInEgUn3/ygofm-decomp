nonmatching func_80073420, 0x28

glabel func_80073420
    /* 63C20 80073420 18000324 */  addiu      $v1, $zero, 0x18
    /* 63C24 80073424 0F80023C */  lui        $v0, %hi(D_800F5BE8)
    /* 63C28 80073428 E85B4224 */  addiu      $v0, $v0, %lo(D_800F5BE8)
    /* 63C2C 8007342C 21104300 */  addu       $v0, $v0, $v1
  .L80073430:
    /* 63C30 80073430 7E0040A0 */  sb         $zero, 0x7E($v0)
    /* 63C34 80073434 FFFF6324 */  addiu      $v1, $v1, -0x1
    /* 63C38 80073438 FDFF6104 */  bgez       $v1, .L80073430
    /* 63C3C 8007343C FFFF4224 */   addiu     $v0, $v0, -0x1
    /* 63C40 80073440 0800E003 */  jr         $ra
    /* 63C44 80073444 00000000 */   nop
endlabel func_80073420
