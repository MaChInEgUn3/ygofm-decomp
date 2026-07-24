nonmatching func_8005969C, 0x64

glabel func_8005969C
    /* 49E9C 8005969C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 49EA0 800596A0 C0100400 */  sll        $v0, $a0, 3
    /* 49EA4 800596A4 23104400 */  subu       $v0, $v0, $a0
    /* 49EA8 800596A8 00110200 */  sll        $v0, $v0, 4
    /* 49EAC 800596AC 21104400 */  addu       $v0, $v0, $a0
    /* 49EB0 800596B0 40110200 */  sll        $v0, $v0, 5
    /* 49EB4 800596B4 0F80033C */  lui        $v1, %hi(D_800F2C40)
    /* 49EB8 800596B8 402C6324 */  addiu      $v1, $v1, %lo(D_800F2C40)
    /* 49EBC 800596BC 21184300 */  addu       $v1, $v0, $v1
    /* 49EC0 800596C0 FCFFA224 */  addiu      $v0, $a1, -0x4
    /* 49EC4 800596C4 1D00422C */  sltiu      $v0, $v0, 0x1D
    /* 49EC8 800596C8 02004014 */  bnez       $v0, .L800596D4
    /* 49ECC 800596CC 1000BFAF */   sw        $ra, 0x10($sp)
    /* 49ED0 800596D0 08000524 */  addiu      $a1, $zero, 0x8
  .L800596D4:
    /* 49ED4 800596D4 0D0E65A0 */  sb         $a1, 0xE0D($v1)
    /* 49ED8 800596D8 160E6390 */  lbu        $v1, 0xE16($v1)
    /* 49EDC 800596DC 3E000224 */  addiu      $v0, $zero, 0x3E
    /* 49EE0 800596E0 03006214 */  bne        $v1, $v0, .L800596F0
    /* 49EE4 800596E4 00000000 */   nop
    /* 49EE8 800596E8 C065010C */  jal        func_80059700
    /* 49EEC 800596EC 01000524 */   addiu     $a1, $zero, 0x1
  .L800596F0:
    /* 49EF0 800596F0 1000BF8F */  lw         $ra, 0x10($sp)
    /* 49EF4 800596F4 00000000 */  nop
    /* 49EF8 800596F8 0800E003 */  jr         $ra
    /* 49EFC 800596FC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8005969C
