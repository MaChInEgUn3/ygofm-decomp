nonmatching func_8002EC74, 0x13C

glabel func_8002EC74
    /* 1F474 8002EC74 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1F478 8002EC78 1400BFAF */  sw         $ra, 0x14($sp)
    /* 1F47C 8002EC7C EDB8000C */  jal        func_8002E3B4
    /* 1F480 8002EC80 1000B0AF */   sw        $s0, 0x10($sp)
    /* 1F484 8002EC84 3C004014 */  bnez       $v0, .L8002ED78
    /* 1F488 8002EC88 0002023C */   lui       $v0, (0x2000030 >> 16)
    /* 1F48C 8002EC8C 8803838F */  lw         $v1, %gp_rel(D_8009B290)($gp)
    /* 1F490 8002EC90 00000000 */  nop
    /* 1F494 8002EC94 00006290 */  lbu        $v0, 0x0($v1)
    /* 1F498 8002EC98 01006324 */  addiu      $v1, $v1, 0x1
    /* 1F49C 8002EC9C 880383AF */  sw         $v1, %gp_rel(D_8009B290)($gp)
    /* 1F4A0 8002ECA0 21804000 */  addu       $s0, $v0, $zero
    /* 1F4A4 8002ECA4 3F000232 */  andi       $v0, $s0, 0x3F
    /* 1F4A8 8002ECA8 14004014 */  bnez       $v0, .L8002ECFC
    /* 1F4AC 8002ECAC 01000232 */   andi      $v0, $s0, 0x1
    /* 1F4B0 8002ECB0 40000232 */  andi       $v0, $s0, 0x40
    /* 1F4B4 8002ECB4 09004010 */  beqz       $v0, .L8002ECDC
    /* 1F4B8 8002ECB8 02006224 */   addiu     $v0, $v1, 0x2
    /* 1F4BC 8002ECBC 880382AF */  sw         $v0, %gp_rel(D_8009B290)($gp)
    /* 1F4C0 8002ECC0 01006490 */  lbu        $a0, 0x1($v1)
    /* 1F4C4 8002ECC4 00006290 */  lbu        $v0, 0x0($v1)
    /* 1F4C8 8002ECC8 00220400 */  sll        $a0, $a0, 8
    /* 1F4CC 8002ECCC B8FF000C */  jal        func_8003FEE0
    /* 1F4D0 8002ECD0 25204400 */   or        $a0, $v0, $a0
    /* 1F4D4 8002ECD4 5ABB0008 */  j          .L8002ED68
    /* 1F4D8 8002ECD8 80000232 */   andi      $v0, $s0, 0x80
  .L8002ECDC:
    /* 1F4DC 8002ECDC 880382AF */  sw         $v0, %gp_rel(D_8009B290)($gp)
    /* 1F4E0 8002ECE0 01006490 */  lbu        $a0, 0x1($v1)
    /* 1F4E4 8002ECE4 00006290 */  lbu        $v0, 0x0($v1)
    /* 1F4E8 8002ECE8 00220400 */  sll        $a0, $a0, 8
    /* 1F4EC 8002ECEC C2FF000C */  jal        func_8003FF08
    /* 1F4F0 8002ECF0 25204400 */   or        $a0, $v0, $a0
    /* 1F4F4 8002ECF4 5ABB0008 */  j          .L8002ED68
    /* 1F4F8 8002ECF8 80000232 */   andi      $v0, $s0, 0x80
  .L8002ECFC:
    /* 1F4FC 8002ECFC 06004010 */  beqz       $v0, .L8002ED18
    /* 1F500 8002ED00 02000232 */   andi      $v0, $s0, 0x2
    /* 1F504 8002ED04 0A80043C */  lui        $a0, %hi(D_8009B404)
    /* 1F508 8002ED08 04B4848C */  lw         $a0, %lo(D_8009B404)($a0)
    /* 1F50C 8002ED0C C2FF000C */  jal        func_8003FF08
    /* 1F510 8002ED10 00000000 */   nop
    /* 1F514 8002ED14 02000232 */  andi       $v0, $s0, 0x2
  .L8002ED18:
    /* 1F518 8002ED18 0C004010 */  beqz       $v0, .L8002ED4C
    /* 1F51C 8002ED1C 04000232 */   andi      $v0, $s0, 0x4
    /* 1F520 8002ED20 8803838F */  lw         $v1, %gp_rel(D_8009B290)($gp)
    /* 1F524 8002ED24 00000000 */  nop
    /* 1F528 8002ED28 02006224 */  addiu      $v0, $v1, 0x2
    /* 1F52C 8002ED2C 880382AF */  sw         $v0, %gp_rel(D_8009B290)($gp)
    /* 1F530 8002ED30 01006290 */  lbu        $v0, 0x1($v1)
    /* 1F534 8002ED34 00006390 */  lbu        $v1, 0x0($v1)
    /* 1F538 8002ED38 00120200 */  sll        $v0, $v0, 8
    /* 1F53C 8002ED3C 25186200 */  or         $v1, $v1, $v0
    /* 1F540 8002ED40 0A80013C */  lui        $at, %hi(D_8009B404)
    /* 1F544 8002ED44 04B423AC */  sw         $v1, %lo(D_8009B404)($at)
    /* 1F548 8002ED48 04000232 */  andi       $v0, $s0, 0x4
  .L8002ED4C:
    /* 1F54C 8002ED4C 06004010 */  beqz       $v0, .L8002ED68
    /* 1F550 8002ED50 80000232 */   andi      $v0, $s0, 0x80
    /* 1F554 8002ED54 0A80023C */  lui        $v0, %hi(D_8009B400)
    /* 1F558 8002ED58 00B4428C */  lw         $v0, %lo(D_8009B400)($v0)
    /* 1F55C 8002ED5C 0A80013C */  lui        $at, %hi(D_8009B404)
    /* 1F560 8002ED60 04B422AC */  sw         $v0, %lo(D_8009B404)($at)
    /* 1F564 8002ED64 80000232 */  andi       $v0, $s0, 0x80
  .L8002ED68:
    /* 1F568 8002ED68 0C004010 */  beqz       $v0, .L8002ED9C
    /* 1F56C 8002ED6C 00000000 */   nop
    /* 1F570 8002ED70 68BB0008 */  j          .L8002EDA0
    /* 1F574 8002ED74 00000000 */   nop
  .L8002ED78:
    /* 1F578 8002ED78 30004234 */  ori        $v0, $v0, (0x2000030 & 0xFFFF)
    /* 1F57C 8002ED7C 0A80033C */  lui        $v1, %hi(D_8009B0F4)
    /* 1F580 8002ED80 F4B0638C */  lw         $v1, %lo(D_8009B0F4)($v1)
    /* 1F584 8002ED84 0A80043C */  lui        $a0, %hi(D_8009B134)
    /* 1F588 8002ED88 34B1848C */  lw         $a0, %lo(D_8009B134)($a0)
    /* 1F58C 8002ED8C 24186200 */  and        $v1, $v1, $v0
    /* 1F590 8002ED90 25186400 */  or         $v1, $v1, $a0
    /* 1F594 8002ED94 02006014 */  bnez       $v1, .L8002EDA0
    /* 1F598 8002ED98 00000000 */   nop
  .L8002ED9C:
    /* 1F59C 8002ED9C 740380A7 */  sh         $zero, %gp_rel(D_8009B27C)($gp)
  .L8002EDA0:
    /* 1F5A0 8002EDA0 1400BF8F */  lw         $ra, 0x14($sp)
    /* 1F5A4 8002EDA4 1000B08F */  lw         $s0, 0x10($sp)
    /* 1F5A8 8002EDA8 0800E003 */  jr         $ra
    /* 1F5AC 8002EDAC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8002EC74
