nonmatching func_80070DA8, 0x78

glabel func_80070DA8
    /* 615A8 80070DA8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 615AC 80070DAC 0F80023C */  lui        $v0, %hi(D_800F5BE8)
    /* 615B0 80070DB0 E85B4324 */  addiu      $v1, $v0, %lo(D_800F5BE8)
    /* 615B4 80070DB4 1000BFAF */  sw         $ra, 0x10($sp)
    /* 615B8 80070DB8 14006290 */  lbu        $v0, 0x14($v1)
    /* 615BC 80070DBC 00000000 */  nop
    /* 615C0 80070DC0 08004010 */  beqz       $v0, .L80070DE4
    /* 615C4 80070DC4 FFFF4224 */   addiu     $v0, $v0, -0x1
    /* 615C8 80070DC8 140062A0 */  sb         $v0, 0x14($v1)
    /* 615CC 80070DCC FF004230 */  andi       $v0, $v0, 0xFF
    /* 615D0 80070DD0 80100200 */  sll        $v0, $v0, 2
    /* 615D4 80070DD4 21104300 */  addu       $v0, $v0, $v1
    /* 615D8 80070DD8 1800428C */  lw         $v0, 0x18($v0)
    /* 615DC 80070DDC 84C30108 */  j          .L80070E10
    /* 615E0 80070DE0 080062AC */   sw        $v0, 0x8($v1)
  .L80070DE4:
    /* 615E4 80070DE4 0180043C */  lui        $a0, %hi(D_800118E4)
    /* 615E8 80070DE8 1C3A020C */  jal        func_8008E870
    /* 615EC 80070DEC E4188424 */   addiu     $a0, $a0, %lo(D_800118E4)
    /* 615F0 80070DF0 0A80043C */  lui        $a0, %hi(D_8009B084)
    /* 615F4 80070DF4 84B08424 */  addiu      $a0, $a0, %lo(D_8009B084)
    /* 615F8 80070DF8 0180053C */  lui        $a1, %hi(D_800118CC)
    /* 615FC 80070DFC CC18A524 */  addiu      $a1, $a1, %lo(D_800118CC)
    /* 61600 80070E00 1C3A020C */  jal        func_8008E870
    /* 61604 80070E04 93010624 */   addiu     $a2, $zero, 0x193
  .L80070E08:
    /* 61608 80070E08 82C30108 */  j          .L80070E08
    /* 6160C 80070E0C 00000000 */   nop
  .L80070E10:
    /* 61610 80070E10 1000BF8F */  lw         $ra, 0x10($sp)
    /* 61614 80070E14 00000000 */  nop
    /* 61618 80070E18 0800E003 */  jr         $ra
    /* 6161C 80070E1C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80070DA8
