nonmatching func_8002D458, 0x130

glabel func_8002D458
    /* 1DC58 8002D458 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1DC5C 8002D45C 01000224 */  addiu      $v0, $zero, 0x1
    /* 1DC60 8002D460 600382A3 */  sb         $v0, %gp_rel(D_8009B268)($gp)
    /* 1DC64 8002D464 0B00822C */  sltiu      $v0, $a0, 0xB
    /* 1DC68 8002D468 1000BFAF */  sw         $ra, 0x10($sp)
    /* 1DC6C 8002D46C 650384A3 */  sb         $a0, %gp_rel(D_8009B26D)($gp)
    /* 1DC70 8002D470 40004010 */  beqz       $v0, .L8002D574
    /* 1DC74 8002D474 0180023C */   lui       $v0, %hi(jtbl_80010224)
    /* 1DC78 8002D478 24024224 */  addiu      $v0, $v0, %lo(jtbl_80010224)
    /* 1DC7C 8002D47C 80180400 */  sll        $v1, $a0, 2
    /* 1DC80 8002D480 21186200 */  addu       $v1, $v1, $v0
    /* 1DC84 8002D484 0000628C */  lw         $v0, 0x0($v1)
    /* 1DC88 8002D488 00000000 */  nop
    /* 1DC8C 8002D48C 08004000 */  jr         $v0
    /* 1DC90 8002D490 00000000 */   nop
  jlabel .L8002D494
    /* 1DC94 8002D494 FEEE000C */  jal        func_8003BBF8
    /* 1DC98 8002D498 00000000 */   nop
    /* 1DC9C 8002D49C 9BAA050C */  jal        func_8016AA6C
    /* 1DCA0 8002D4A0 00000000 */   nop
    /* 1DCA4 8002D4A4 1D80033C */  lui        $v1, %hi(D_801D07DC)
    /* 1DCA8 8002D4A8 30000224 */  addiu      $v0, $zero, 0x30
    /* 1DCAC 8002D4AC DC0762A4 */  sh         $v0, %lo(D_801D07DC)($v1)
    /* 1DCB0 8002D4B0 0A80013C */  lui        $at, %hi(D_8009B27A)
    /* 1DCB4 8002D4B4 7AB222A0 */  sb         $v0, %lo(D_8009B27A)($at)
    /* 1DCB8 8002D4B8 01000224 */  addiu      $v0, $zero, 0x1
    /* 1DCBC 8002D4BC 0A80013C */  lui        $at, %hi(D_8009B3D4)
    /* 1DCC0 8002D4C0 D4B322A0 */  sb         $v0, %lo(D_8009B3D4)($at)
    /* 1DCC4 8002D4C4 02000224 */  addiu      $v0, $zero, 0x2
    /* 1DCC8 8002D4C8 0A80013C */  lui        $at, %hi(D_8009B0D1)
    /* 1DCCC 8002D4CC D1B020A0 */  sb         $zero, %lo(D_8009B0D1)($at)
    /* 1DCD0 8002D4D0 640382A3 */  sb         $v0, %gp_rel(D_8009B26C)($gp)
    /* 1DCD4 8002D4D4 5EB50008 */  j          .L8002D578
    /* 1DCD8 8002D4D8 00000000 */   nop
  jlabel .L8002D4DC
    /* 1DCDC 8002D4DC 10000224 */  addiu      $v0, $zero, 0x10
    /* 1DCE0 8002D4E0 640382A3 */  sb         $v0, %gp_rel(D_8009B26C)($gp)
    /* 1DCE4 8002D4E4 5EB50008 */  j          .L8002D578
    /* 1DCE8 8002D4E8 00000000 */   nop
  jlabel .L8002D4EC
    /* 1DCEC 8002D4EC 0E000224 */  addiu      $v0, $zero, 0xE
    /* 1DCF0 8002D4F0 640382A3 */  sb         $v0, %gp_rel(D_8009B26C)($gp)
    /* 1DCF4 8002D4F4 5EB50008 */  j          .L8002D578
    /* 1DCF8 8002D4F8 00000000 */   nop
  jlabel .L8002D4FC
    /* 1DCFC 8002D4FC 04000224 */  addiu      $v0, $zero, 0x4
    /* 1DD00 8002D500 640382A3 */  sb         $v0, %gp_rel(D_8009B26C)($gp)
    /* 1DD04 8002D504 5EB50008 */  j          .L8002D578
    /* 1DD08 8002D508 00000000 */   nop
  jlabel .L8002D50C
    /* 1DD0C 8002D50C 1D80023C */  lui        $v0, %hi(D_801D07DC)
    /* 1DD10 8002D510 DC074390 */  lbu        $v1, %lo(D_801D07DC)($v0)
    /* 1DD14 8002D514 02000224 */  addiu      $v0, $zero, 0x2
    /* 1DD18 8002D518 640382A3 */  sb         $v0, %gp_rel(D_8009B26C)($gp)
    /* 1DD1C 8002D51C 0A80013C */  lui        $at, %hi(D_8009B27A)
    /* 1DD20 8002D520 7AB223A0 */  sb         $v1, %lo(D_8009B27A)($at)
    /* 1DD24 8002D524 5EB50008 */  j          .L8002D578
    /* 1DD28 8002D528 00000000 */   nop
  jlabel .L8002D52C
    /* 1DD2C 8002D52C 06000224 */  addiu      $v0, $zero, 0x6
    /* 1DD30 8002D530 0A80013C */  lui        $at, %hi(D_8009B365)
    /* 1DD34 8002D534 65B320A0 */  sb         $zero, %lo(D_8009B365)($at)
    /* 1DD38 8002D538 640382A3 */  sb         $v0, %gp_rel(D_8009B26C)($gp)
    /* 1DD3C 8002D53C 5EB50008 */  j          .L8002D578
    /* 1DD40 8002D540 00000000 */   nop
  jlabel .L8002D544
    /* 1DD44 8002D544 24CF000C */  jal        func_80033C90
    /* 1DD48 8002D548 00000000 */   nop
    /* 1DD4C 8002D54C 600380A3 */  sb         $zero, %gp_rel(D_8009B268)($gp)
    /* 1DD50 8002D550 5EB50008 */  j          .L8002D578
    /* 1DD54 8002D554 00000000 */   nop
  jlabel .L8002D558
    /* 1DD58 8002D558 59B50008 */  j          .L8002D564
    /* 1DD5C 8002D55C 0B000224 */   addiu     $v0, $zero, 0xB
  jlabel .L8002D560
    /* 1DD60 8002D560 0A000224 */  addiu      $v0, $zero, 0xA
  .L8002D564:
    /* 1DD64 8002D564 640382A3 */  sb         $v0, %gp_rel(D_8009B26C)($gp)
    /* 1DD68 8002D568 600380A3 */  sb         $zero, %gp_rel(D_8009B268)($gp)
    /* 1DD6C 8002D56C 5EB50008 */  j          .L8002D578
    /* 1DD70 8002D570 00000000 */   nop
  jlabel .L8002D574
    /* 1DD74 8002D574 640380A3 */  sb         $zero, %gp_rel(D_8009B26C)($gp)
  .L8002D578:
    /* 1DD78 8002D578 1000BF8F */  lw         $ra, 0x10($sp)
    /* 1DD7C 8002D57C 00000000 */  nop
    /* 1DD80 8002D580 0800E003 */  jr         $ra
    /* 1DD84 8002D584 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8002D458
