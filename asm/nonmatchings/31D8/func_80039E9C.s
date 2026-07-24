nonmatching func_80039E9C, 0x80

glabel func_80039E9C
    /* 2A69C 80039E9C 02000524 */  addiu      $a1, $zero, 0x2
    /* 2A6A0 80039EA0 FFFF0624 */  addiu      $a2, $zero, -0x1
    /* 2A6A4 80039EA4 0F80023C */  lui        $v0, %hi(D_800EB010)
    /* 2A6A8 80039EA8 10B04224 */  addiu      $v0, $v0, %lo(D_800EB010)
    /* 2A6AC 80039EAC 98004224 */  addiu      $v0, $v0, 0x98
  .L80039EB0:
    /* 2A6B0 80039EB0 02000424 */  addiu      $a0, $zero, 0x2
    /* 2A6B4 80039EB4 08004324 */  addiu      $v1, $v0, 0x8
    /* 2A6B8 80039EB8 300046A0 */  sb         $a2, 0x30($v0)
    /* 2A6BC 80039EBC 320040A0 */  sb         $zero, 0x32($v0)
    /* 2A6C0 80039EC0 3A0040A0 */  sb         $zero, 0x3A($v0)
    /* 2A6C4 80039EC4 3B0040A0 */  sb         $zero, 0x3B($v0)
  .L80039EC8:
    /* 2A6C8 80039EC8 000060AC */  sw         $zero, 0x0($v1)
    /* 2A6CC 80039ECC 0C0060AC */  sw         $zero, 0xC($v1)
    /* 2A6D0 80039ED0 180060AC */  sw         $zero, 0x18($v1)
    /* 2A6D4 80039ED4 240060AC */  sw         $zero, 0x24($v1)
    /* 2A6D8 80039ED8 FFFF8424 */  addiu      $a0, $a0, -0x1
    /* 2A6DC 80039EDC FAFF8104 */  bgez       $a0, .L80039EC8
    /* 2A6E0 80039EE0 FCFF6324 */   addiu     $v1, $v1, -0x4
    /* 2A6E4 80039EE4 FFFFA524 */  addiu      $a1, $a1, -0x1
    /* 2A6E8 80039EE8 F1FFA104 */  bgez       $a1, .L80039EB0
    /* 2A6EC 80039EEC B4FF4224 */   addiu     $v0, $v0, -0x4C
    /* 2A6F0 80039EF0 FFFF0324 */  addiu      $v1, $zero, -0x1
    /* 2A6F4 80039EF4 04000524 */  addiu      $a1, $zero, 0x4
    /* 2A6F8 80039EF8 1680023C */  lui        $v0, %hi(D_8015C410)
    /* 2A6FC 80039EFC 10C44224 */  addiu      $v0, $v0, %lo(D_8015C410)
    /* 2A700 80039F00 21104500 */  addu       $v0, $v0, $a1
  .L80039F04:
    /* 2A704 80039F04 000043A0 */  sb         $v1, 0x0($v0)
    /* 2A708 80039F08 FFFFA524 */  addiu      $a1, $a1, -0x1
    /* 2A70C 80039F0C FDFFA104 */  bgez       $a1, .L80039F04
    /* 2A710 80039F10 FFFF4224 */   addiu     $v0, $v0, -0x1
    /* 2A714 80039F14 0800E003 */  jr         $ra
    /* 2A718 80039F18 00000000 */   nop
endlabel func_80039E9C
