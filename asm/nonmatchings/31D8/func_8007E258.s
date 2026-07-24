nonmatching func_8007E258, 0x30

glabel func_8007E258
    /* 6EA58 8007E258 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 6EA5C 8007E25C FF008430 */  andi       $a0, $a0, 0xFF
    /* 6EA60 8007E260 02000224 */  addiu      $v0, $zero, 0x2
    /* 6EA64 8007E264 04008214 */  bne        $a0, $v0, .L8007E278
    /* 6EA68 8007E268 1000BFAF */   sw        $ra, 0x10($sp)
    /* 6EA6C 8007E26C 0880043C */  lui        $a0, %hi(func_8007DE4C)
    /* 6EA70 8007E270 18FA010C */  jal        func_8007E860
    /* 6EA74 8007E274 4CDE8424 */   addiu     $a0, $a0, %lo(func_8007DE4C)
  .L8007E278:
    /* 6EA78 8007E278 1000BF8F */  lw         $ra, 0x10($sp)
    /* 6EA7C 8007E27C 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 6EA80 8007E280 0800E003 */  jr         $ra
    /* 6EA84 8007E284 00000000 */   nop
endlabel func_8007E258
