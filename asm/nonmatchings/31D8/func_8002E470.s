nonmatching func_8002E470, 0x13C

glabel func_8002E470
    /* 1EC70 8002E470 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1EC74 8002E474 1400BFAF */  sw         $ra, 0x14($sp)
    /* 1EC78 8002E478 EDB8000C */  jal        func_8002E3B4
    /* 1EC7C 8002E47C 1000B0AF */   sw        $s0, 0x10($sp)
    /* 1EC80 8002E480 28004014 */  bnez       $v0, .L8002E524
    /* 1EC84 8002E484 0F80023C */   lui       $v0, %hi(D_800EAE98)
    /* 1EC88 8002E488 98AE5024 */  addiu      $s0, $v0, %lo(D_800EAE98)
    /* 1EC8C 8002E48C 0A80013C */  lui        $at, %hi(D_8009B148)
    /* 1EC90 8002E490 48B120A4 */  sh         $zero, %lo(D_8009B148)($at)
    /* 1EC94 8002E494 0A80013C */  lui        $at, %hi(D_8009B146)
    /* 1EC98 8002E498 46B120A4 */  sh         $zero, %lo(D_8009B146)($at)
    /* 1EC9C 8002E49C 03B8000C */  jal        func_8002E00C
    /* 1ECA0 8002E4A0 21200002 */   addu      $a0, $s0, $zero
    /* 1ECA4 8002E4A4 8803868F */  lw         $a2, %gp_rel(D_8009B290)($gp)
    /* 1ECA8 8002E4A8 00000000 */  nop
    /* 1ECAC 8002E4AC 0200C724 */  addiu      $a3, $a2, 0x2
    /* 1ECB0 8002E4B0 880387AF */  sw         $a3, %gp_rel(D_8009B290)($gp)
    /* 1ECB4 8002E4B4 0100C290 */  lbu        $v0, 0x1($a2)
    /* 1ECB8 8002E4B8 0000C390 */  lbu        $v1, 0x0($a2)
    /* 1ECBC 8002E4BC 00120200 */  sll        $v0, $v0, 8
    /* 1ECC0 8002E4C0 25186200 */  or         $v1, $v1, $v0
    /* 1ECC4 8002E4C4 00806230 */  andi       $v0, $v1, 0x8000
    /* 1ECC8 8002E4C8 680383A7 */  sh         $v1, %gp_rel(D_8009B270)($gp)
    /* 1ECCC 8002E4CC 12004010 */  beqz       $v0, .L8002E518
    /* 1ECD0 8002E4D0 FF0F6230 */   andi      $v0, $v1, 0xFFF
    /* 1ECD4 8002E4D4 0400C524 */  addiu      $a1, $a2, 0x4
    /* 1ECD8 8002E4D8 680382A7 */  sh         $v0, %gp_rel(D_8009B270)($gp)
    /* 1ECDC 8002E4DC 880385AF */  sw         $a1, %gp_rel(D_8009B290)($gp)
    /* 1ECE0 8002E4E0 0200C490 */  lbu        $a0, 0x2($a2)
    /* 1ECE4 8002E4E4 0100E290 */  lbu        $v0, 0x1($a3)
    /* 1ECE8 8002E4E8 0600C324 */  addiu      $v1, $a2, 0x6
    /* 1ECEC 8002E4EC 880383AF */  sw         $v1, %gp_rel(D_8009B290)($gp)
    /* 1ECF0 8002E4F0 00120200 */  sll        $v0, $v0, 8
    /* 1ECF4 8002E4F4 25208200 */  or         $a0, $a0, $v0
    /* 1ECF8 8002E4F8 0A80013C */  lui        $at, %hi(D_8009B146)
    /* 1ECFC 8002E4FC 46B124A4 */  sh         $a0, %lo(D_8009B146)($at)
    /* 1ED00 8002E500 0100A290 */  lbu        $v0, 0x1($a1)
    /* 1ED04 8002E504 0400C390 */  lbu        $v1, 0x4($a2)
    /* 1ED08 8002E508 00120200 */  sll        $v0, $v0, 8
    /* 1ED0C 8002E50C 25186200 */  or         $v1, $v1, $v0
    /* 1ED10 8002E510 0A80013C */  lui        $at, %hi(D_8009B148)
    /* 1ED14 8002E514 48B123A4 */  sh         $v1, %lo(D_8009B148)($at)
  .L8002E518:
    /* 1ED18 8002E518 68038597 */  lhu        $a1, %gp_rel(D_8009B270)($gp)
    /* 1ED1C 8002E51C CBB7000C */  jal        func_8002DF2C
    /* 1ED20 8002E520 21200002 */   addu      $a0, $s0, $zero
  .L8002E524:
    /* 1ED24 8002E524 74038597 */  lhu        $a1, %gp_rel(D_8009B27C)($gp)
    /* 1ED28 8002E528 00000000 */  nop
    /* 1ED2C 8002E52C 0008A230 */  andi       $v0, $a1, 0x800
    /* 1ED30 8002E530 14004014 */  bnez       $v0, .L8002E584
    /* 1ED34 8002E534 0F80023C */   lui       $v0, %hi(D_800E9ECE)
    /* 1ED38 8002E538 0002023C */  lui        $v0, (0x2000030 >> 16)
    /* 1ED3C 8002E53C 30004234 */  ori        $v0, $v0, (0x2000030 & 0xFFFF)
    /* 1ED40 8002E540 0A80033C */  lui        $v1, %hi(D_8009B0F4)
    /* 1ED44 8002E544 F4B0638C */  lw         $v1, %lo(D_8009B0F4)($v1)
    /* 1ED48 8002E548 0A80043C */  lui        $a0, %hi(D_8009B134)
    /* 1ED4C 8002E54C 34B1848C */  lw         $a0, %lo(D_8009B134)($a0)
    /* 1ED50 8002E550 24186200 */  and        $v1, $v1, $v0
    /* 1ED54 8002E554 25186400 */  or         $v1, $v1, $a0
    /* 1ED58 8002E558 10006014 */  bnez       $v1, .L8002E59C
    /* 1ED5C 8002E55C 0008A234 */   ori       $v0, $a1, 0x800
    /* 1ED60 8002E560 740382A7 */  sh         $v0, %gp_rel(D_8009B27C)($gp)
    /* 1ED64 8002E564 0F80043C */  lui        $a0, %hi(D_800EAE98)
    /* 1ED68 8002E568 98AE8424 */  addiu      $a0, $a0, %lo(D_800EAE98)
    /* 1ED6C 8002E56C 4AB8000C */  jal        func_8002E128
    /* 1ED70 8002E570 FFFF0524 */   addiu     $a1, $zero, -0x1
    /* 1ED74 8002E574 F755000C */  jal        func_800157DC
    /* 1ED78 8002E578 00000000 */   nop
    /* 1ED7C 8002E57C 67B90008 */  j          .L8002E59C
    /* 1ED80 8002E580 00000000 */   nop
  .L8002E584:
    /* 1ED84 8002E584 CE9E4290 */  lbu        $v0, %lo(D_800E9ECE)($v0)
    /* 1ED88 8002E588 00000000 */  nop
    /* 1ED8C 8002E58C 80004230 */  andi       $v0, $v0, 0x80
    /* 1ED90 8002E590 02004014 */  bnez       $v0, .L8002E59C
    /* 1ED94 8002E594 00000000 */   nop
    /* 1ED98 8002E598 740380A7 */  sh         $zero, %gp_rel(D_8009B27C)($gp)
  .L8002E59C:
    /* 1ED9C 8002E59C 1400BF8F */  lw         $ra, 0x14($sp)
    /* 1EDA0 8002E5A0 1000B08F */  lw         $s0, 0x10($sp)
    /* 1EDA4 8002E5A4 0800E003 */  jr         $ra
    /* 1EDA8 8002E5A8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8002E470
