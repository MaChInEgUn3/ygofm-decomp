nonmatching func_8003F454, 0x2B8

glabel func_8003F454
    /* 2FC54 8003F454 F2048497 */  lhu        $a0, %gp_rel(D_8009B3FA)($gp)
    /* 2FC58 8003F458 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 2FC5C 8003F45C 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 2FC60 8003F460 00088230 */  andi       $v0, $a0, 0x800
    /* 2FC64 8003F464 1E004010 */  beqz       $v0, .L8003F4E0
    /* 2FC68 8003F468 1800B0AF */   sw        $s0, 0x18($sp)
    /* 2FC6C 8003F46C D004848F */  lw         $a0, %gp_rel(D_8009B3D8)($gp)
    /* 2FC70 8003F470 00000000 */  nop
    /* 2FC74 8003F474 04008014 */  bnez       $a0, .L8003F488
    /* 2FC78 8003F478 20000524 */   addiu     $a1, $zero, 0x20
    /* 2FC7C 8003F47C F20480A7 */  sh         $zero, %gp_rel(D_8009B3FA)($gp)
    /* 2FC80 8003F480 BFFD0008 */  j          .L8003F6FC
    /* 2FC84 8003F484 00000000 */   nop
  .L8003F488:
    /* 2FC88 8003F488 E6048793 */  lbu        $a3, %gp_rel(D_8009B3EE)($gp)
    /* 2FC8C 8003F48C ACFC000C */  jal        func_8003F2B0
    /* 2FC90 8003F490 00010624 */   addiu     $a2, $zero, 0x100
    /* 2FC94 8003F494 99004014 */  bnez       $v0, .L8003F6FC
    /* 2FC98 8003F498 00000000 */   nop
    /* 2FC9C 8003F49C E6048293 */  lbu        $v0, %gp_rel(D_8009B3EE)($gp)
    /* 2FCA0 8003F4A0 00000000 */  nop
    /* 2FCA4 8003F4A4 40200200 */  sll        $a0, $v0, 1
    /* 2FCA8 8003F4A8 21208200 */  addu       $a0, $a0, $v0
    /* 2FCAC 8003F4AC C0200400 */  sll        $a0, $a0, 3
    /* 2FCB0 8003F4B0 21208200 */  addu       $a0, $a0, $v0
    /* 2FCB4 8003F4B4 80200400 */  sll        $a0, $a0, 2
    /* 2FCB8 8003F4B8 0F80023C */  lui        $v0, %hi(D_800EB0F8)
    /* 2FCBC 8003F4BC F8B04224 */  addiu      $v0, $v0, %lo(D_800EB0F8)
    /* 2FCC0 8003F4C0 DFD6000C */  jal        func_80035B7C
    /* 2FCC4 8003F4C4 21208200 */   addu      $a0, $a0, $v0
    /* 2FCC8 8003F4C8 D004848F */  lw         $a0, %gp_rel(D_8009B3D8)($gp)
    /* 2FCCC 8003F4CC DB00010C */  jal        func_8004036C
    /* 2FCD0 8003F4D0 00000000 */   nop
    /* 2FCD4 8003F4D4 D00480AF */  sw         $zero, %gp_rel(D_8009B3D8)($gp)
    /* 2FCD8 8003F4D8 BFFD0008 */  j          .L8003F6FC
    /* 2FCDC 8003F4DC 00000000 */   nop
  .L8003F4E0:
    /* 2FCE0 8003F4E0 80408330 */  andi       $v1, $a0, 0x4080
    /* 2FCE4 8003F4E4 80400224 */  addiu      $v0, $zero, 0x4080
    /* 2FCE8 8003F4E8 46006214 */  bne        $v1, $v0, .L8003F604
    /* 2FCEC 8003F4EC 00408230 */   andi      $v0, $a0, 0x4000
    /* 2FCF0 8003F4F0 40008230 */  andi       $v0, $a0, 0x40
    /* 2FCF4 8003F4F4 28004014 */  bnez       $v0, .L8003F598
    /* 2FCF8 8003F4F8 20000624 */   addiu     $a2, $zero, 0x20
    /* 2FCFC 8003F4FC 40008234 */  ori        $v0, $a0, 0x40
    /* 2FD00 8003F500 E6048493 */  lbu        $a0, %gp_rel(D_8009B3EE)($gp)
    /* 2FD04 8003F504 BE048593 */  lbu        $a1, %gp_rel(D_8009B3C6)($gp)
    /* 2FD08 8003F508 50000724 */  addiu      $a3, $zero, 0x50
    /* 2FD0C 8003F50C F20482A7 */  sh         $v0, %gp_rel(D_8009B3FA)($gp)
    /* 2FD10 8003F510 00010224 */  addiu      $v0, $zero, 0x100
    /* 2FD14 8003F514 1000A2AF */  sw         $v0, 0x10($sp)
    /* 2FD18 8003F518 30000224 */  addiu      $v0, $zero, 0x30
    /* 2FD1C 8003F51C F9D6000C */  jal        func_80035BE4
    /* 2FD20 8003F520 1400A2AF */   sw        $v0, 0x14($sp)
    /* 2FD24 8003F524 21804000 */  addu       $s0, $v0, $zero
    /* 2FD28 8003F528 DCB8000C */  jal        func_8002E370
    /* 2FD2C 8003F52C 21200002 */   addu      $a0, $s0, $zero
    /* 2FD30 8003F530 10000224 */  addiu      $v0, $zero, 0x10
    /* 2FD34 8003F534 590002A2 */  sb         $v0, 0x59($s0)
    /* 2FD38 8003F538 F2048397 */  lhu        $v1, %gp_rel(D_8009B3FA)($gp)
    /* 2FD3C 8003F53C 00000000 */  nop
    /* 2FD40 8003F540 20006230 */  andi       $v0, $v1, 0x20
    /* 2FD44 8003F544 09004010 */  beqz       $v0, .L8003F56C
    /* 2FD48 8003F548 10006230 */   andi      $v0, $v1, 0x10
  .L8003F54C:
    /* 2FD4C 8003F54C E5E5000C */  jal        func_80039794
    /* 2FD50 8003F550 00000000 */   nop
    /* 2FD54 8003F554 3000028E */  lw         $v0, 0x30($s0)
    /* 2FD58 8003F558 00000000 */  nop
    /* 2FD5C 8003F55C FBFF4010 */  beqz       $v0, .L8003F54C
    /* 2FD60 8003F560 00000000 */   nop
    /* 2FD64 8003F564 BFFD0008 */  j          .L8003F6FC
    /* 2FD68 8003F568 00000000 */   nop
  .L8003F56C:
    /* 2FD6C 8003F56C 06004010 */  beqz       $v0, .L8003F588
    /* 2FD70 8003F570 00000000 */   nop
    /* 2FD74 8003F574 34000296 */  lhu        $v0, 0x34($s0)
    /* 2FD78 8003F578 00000000 */  nop
    /* 2FD7C 8003F57C 08104234 */  ori        $v0, $v0, 0x1008
    /* 2FD80 8003F580 BFFD0008 */  j          .L8003F6FC
    /* 2FD84 8003F584 340002A6 */   sh        $v0, 0x34($s0)
  .L8003F588:
    /* 2FD88 8003F588 85E6000C */  jal        func_80039A14
    /* 2FD8C 8003F58C 21200002 */   addu      $a0, $s0, $zero
    /* 2FD90 8003F590 77FD0008 */  j          .L8003F5DC
    /* 2FD94 8003F594 00000000 */   nop
  .L8003F598:
    /* 2FD98 8003F598 E5E5000C */  jal        func_80039794
    /* 2FD9C 8003F59C 00000000 */   nop
    /* 2FDA0 8003F5A0 E6048393 */  lbu        $v1, %gp_rel(D_8009B3EE)($gp)
    /* 2FDA4 8003F5A4 00000000 */  nop
    /* 2FDA8 8003F5A8 40100300 */  sll        $v0, $v1, 1
    /* 2FDAC 8003F5AC 21104300 */  addu       $v0, $v0, $v1
    /* 2FDB0 8003F5B0 C0100200 */  sll        $v0, $v0, 3
    /* 2FDB4 8003F5B4 21104300 */  addu       $v0, $v0, $v1
    /* 2FDB8 8003F5B8 80100200 */  sll        $v0, $v0, 2
    /* 2FDBC 8003F5BC 0F80033C */  lui        $v1, %hi(D_800EB0F8)
    /* 2FDC0 8003F5C0 F8B06324 */  addiu      $v1, $v1, %lo(D_800EB0F8)
    /* 2FDC4 8003F5C4 21804300 */  addu       $s0, $v0, $v1
    /* 2FDC8 8003F5C8 3400028E */  lw         $v0, 0x34($s0)
    /* 2FDCC 8003F5CC 00200324 */  addiu      $v1, $zero, 0x2000
    /* 2FDD0 8003F5D0 08204230 */  andi       $v0, $v0, 0x2008
    /* 2FDD4 8003F5D4 49004314 */  bne        $v0, $v1, .L8003F6FC
    /* 2FDD8 8003F5D8 00000000 */   nop
  .L8003F5DC:
    /* 2FDDC 8003F5DC F2048297 */  lhu        $v0, %gp_rel(D_8009B3FA)($gp)
    /* 2FDE0 8003F5E0 00000000 */  nop
    /* 2FDE4 8003F5E4 7FFF4330 */  andi       $v1, $v0, 0xFF7F
    /* 2FDE8 8003F5E8 08004230 */  andi       $v0, $v0, 0x8
    /* 2FDEC 8003F5EC F20483A7 */  sh         $v1, %gp_rel(D_8009B3FA)($gp)
    /* 2FDF0 8003F5F0 42004010 */  beqz       $v0, .L8003F6FC
    /* 2FDF4 8003F5F4 00000000 */   nop
    /* 2FDF8 8003F5F8 F20480A7 */  sh         $zero, %gp_rel(D_8009B3FA)($gp)
    /* 2FDFC 8003F5FC B8FD0008 */  j          .L8003F6E0
    /* 2FE00 8003F600 00000000 */   nop
  .L8003F604:
    /* 2FE04 8003F604 1C004014 */  bnez       $v0, .L8003F678
    /* 2FE08 8003F608 00108230 */   andi      $v0, $a0, 0x1000
    /* 2FE0C 8003F60C 00208230 */  andi       $v0, $a0, 0x2000
    /* 2FE10 8003F610 0D004014 */  bnez       $v0, .L8003F648
    /* 2FE14 8003F614 20000524 */   addiu     $a1, $zero, 0x20
    /* 2FE18 8003F618 00208234 */  ori        $v0, $a0, 0x2000
    /* 2FE1C 8003F61C F20482A7 */  sh         $v0, %gp_rel(D_8009B3FA)($gp)
    /* 2FE20 8003F620 172E020C */  jal        func_8008B85C
    /* 2FE24 8003F624 00000000 */   nop
    /* 2FE28 8003F628 02000224 */  addiu      $v0, $zero, 0x2
    /* 2FE2C 8003F62C E70482A3 */  sb         $v0, %gp_rel(D_8009B3EF)($gp)
    /* 2FE30 8003F630 E2FC000C */  jal        func_8003F388
    /* 2FE34 8003F634 00000000 */   nop
    /* 2FE38 8003F638 D004838F */  lw         $v1, %gp_rel(D_8009B3D8)($gp)
    /* 2FE3C 8003F63C 00FC0224 */  addiu      $v0, $zero, -0x400
    /* 2FE40 8003F640 BFFD0008 */  j          .L8003F6FC
    /* 2FE44 8003F644 600062A4 */   sh        $v0, 0x60($v1)
  .L8003F648:
    /* 2FE48 8003F648 D004848F */  lw         $a0, %gp_rel(D_8009B3D8)($gp)
    /* 2FE4C 8003F64C 50000624 */  addiu      $a2, $zero, 0x50
    /* 2FE50 8003F650 ACFC000C */  jal        func_8003F2B0
    /* 2FE54 8003F654 FFFF0724 */   addiu     $a3, $zero, -0x1
    /* 2FE58 8003F658 28004014 */  bnez       $v0, .L8003F6FC
    /* 2FE5C 8003F65C 00000000 */   nop
    /* 2FE60 8003F660 F2048297 */  lhu        $v0, %gp_rel(D_8009B3FA)($gp)
    /* 2FE64 8003F664 00000000 */  nop
    /* 2FE68 8003F668 00404234 */  ori        $v0, $v0, 0x4000
    /* 2FE6C 8003F66C F20482A7 */  sh         $v0, %gp_rel(D_8009B3FA)($gp)
    /* 2FE70 8003F670 BFFD0008 */  j          .L8003F6FC
    /* 2FE74 8003F674 00000000 */   nop
  .L8003F678:
    /* 2FE78 8003F678 0D004010 */  beqz       $v0, .L8003F6B0
    /* 2FE7C 8003F67C 0980033C */   lui       $v1, %hi(D_80090F9C)
    /* 2FE80 8003F680 E8048527 */  addiu      $a1, $gp, %gp_rel(D_8009B3F0)
    /* 2FE84 8003F684 EC048627 */  addiu      $a2, $gp, %gp_rel(D_8009B3F4)
    /* 2FE88 8003F688 3A33020C */  jal        func_8008CCE8
    /* 2FE8C 8003F68C 01000424 */   addiu     $a0, $zero, 0x1
    /* 2FE90 8003F690 B40482AF */  sw         $v0, %gp_rel(D_8009B3BC)($gp)
    /* 2FE94 8003F694 01000324 */  addiu      $v1, $zero, 0x1
    /* 2FE98 8003F698 18004314 */  bne        $v0, $v1, .L8003F6FC
    /* 2FE9C 8003F69C 0980033C */   lui       $v1, %hi(D_80090F9C)
    /* 2FEA0 8003F6A0 F2048297 */  lhu        $v0, %gp_rel(D_8009B3FA)($gp)
    /* 2FEA4 8003F6A4 00000000 */  nop
    /* 2FEA8 8003F6A8 FFEF4230 */  andi       $v0, $v0, 0xEFFF
    /* 2FEAC 8003F6AC F20482A7 */  sh         $v0, %gp_rel(D_8009B3FA)($gp)
  .L8003F6B0:
    /* 2FEB0 8003F6B0 D6048293 */  lbu        $v0, %gp_rel(D_8009B3DE)($gp)
    /* 2FEB4 8003F6B4 9C0F6324 */  addiu      $v1, $v1, %lo(D_80090F9C)
    /* 2FEB8 8003F6B8 80100200 */  sll        $v0, $v0, 2
    /* 2FEBC 8003F6BC 21104300 */  addu       $v0, $v0, $v1
    /* 2FEC0 8003F6C0 0000428C */  lw         $v0, 0x0($v0)
    /* 2FEC4 8003F6C4 00000000 */  nop
    /* 2FEC8 8003F6C8 09F84000 */  jalr       $v0
    /* 2FECC 8003F6CC 00000000 */   nop
    /* 2FED0 8003F6D0 F2048297 */  lhu        $v0, %gp_rel(D_8009B3FA)($gp)
    /* 2FED4 8003F6D4 00000000 */  nop
    /* 2FED8 8003F6D8 08004014 */  bnez       $v0, .L8003F6FC
    /* 2FEDC 8003F6DC 00000000 */   nop
  .L8003F6E0:
    /* 2FEE0 8003F6E0 F2048297 */  lhu        $v0, %gp_rel(D_8009B3FA)($gp)
    /* 2FEE4 8003F6E4 D004838F */  lw         $v1, %gp_rel(D_8009B3D8)($gp)
    /* 2FEE8 8003F6E8 00084234 */  ori        $v0, $v0, 0x800
    /* 2FEEC 8003F6EC F20482A7 */  sh         $v0, %gp_rel(D_8009B3FA)($gp)
    /* 2FEF0 8003F6F0 00040224 */  addiu      $v0, $zero, 0x400
    /* 2FEF4 8003F6F4 332E020C */  jal        func_8008B8CC
    /* 2FEF8 8003F6F8 600062A4 */   sh        $v0, 0x60($v1)
  .L8003F6FC:
    /* 2FEFC 8003F6FC 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 2FF00 8003F700 1800B08F */  lw         $s0, 0x18($sp)
    /* 2FF04 8003F704 0800E003 */  jr         $ra
    /* 2FF08 8003F708 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8003F454
