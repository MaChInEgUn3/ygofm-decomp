nonmatching func_80035A64, 0x54

glabel func_80035A64
    /* 26264 80035A64 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 26268 80035A68 1000BFAF */  sw         $ra, 0x10($sp)
    /* 2626C 80035A6C 04000324 */  addiu      $v1, $zero, 0x4
    /* 26270 80035A70 0F80023C */  lui        $v0, %hi(D_800EB0F8)
    /* 26274 80035A74 F8B04224 */  addiu      $v0, $v0, %lo(D_800EB0F8)
    /* 26278 80035A78 28004224 */  addiu      $v0, $v0, 0x28
  .L80035A7C:
    /* 2627C 80035A7C 0C0040A4 */  sh         $zero, 0xC($v0)
    /* 26280 80035A80 080040AC */  sw         $zero, 0x8($v0)
    /* 26284 80035A84 040040AC */  sw         $zero, 0x4($v0)
    /* 26288 80035A88 000040AC */  sw         $zero, 0x0($v0)
    /* 2628C 80035A8C FFFF6324 */  addiu      $v1, $v1, -0x1
    /* 26290 80035A90 FAFF6014 */  bnez       $v1, .L80035A7C
    /* 26294 80035A94 64004224 */   addiu     $v0, $v0, 0x64
    /* 26298 80035A98 39D7000C */  jal        func_80035CE4
    /* 2629C 80035A9C 00000000 */   nop
    /* 262A0 80035AA0 7DD7000C */  jal        func_80035DF4
    /* 262A4 80035AA4 00000000 */   nop
    /* 262A8 80035AA8 1000BF8F */  lw         $ra, 0x10($sp)
    /* 262AC 80035AAC 00000000 */  nop
    /* 262B0 80035AB0 0800E003 */  jr         $ra
    /* 262B4 80035AB4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80035A64
