nonmatching func_8007BC48, 0x2C

glabel func_8007BC48
    /* 6C448 8007BC48 1080023C */  lui        $v0, %hi(D_800F8398)
    /* 6C44C 8007BC4C 9883428C */  lw         $v0, %lo(D_800F8398)($v0)
    /* 6C450 8007BC50 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 6C454 8007BC54 03004010 */  beqz       $v0, .L8007BC64
    /* 6C458 8007BC58 1000BFAF */   sw        $ra, 0x10($sp)
    /* 6C45C 8007BC5C 09F84000 */  jalr       $v0
    /* 6C460 8007BC60 FF008430 */   andi      $a0, $a0, 0xFF
  .L8007BC64:
    /* 6C464 8007BC64 1000BF8F */  lw         $ra, 0x10($sp)
    /* 6C468 8007BC68 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 6C46C 8007BC6C 0800E003 */  jr         $ra
    /* 6C470 8007BC70 00000000 */   nop
endlabel func_8007BC48
    /* 6C474 8007BC74 00000000 */  nop
    /* 6C478 8007BC78 00000000 */  nop
    /* 6C47C 8007BC7C 00000000 */  nop
