nonmatching func_8002F4C0, 0x170

glabel func_8002F4C0
    /* 1FCC0 8002F4C0 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 1FCC4 8002F4C4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1FCC8 8002F4C8 21808000 */  addu       $s0, $a0, $zero
    /* 1FCCC 8002F4CC 1400B1AF */  sw         $s1, 0x14($sp)
    /* 1FCD0 8002F4D0 01001124 */  addiu      $s1, $zero, 0x1
    /* 1FCD4 8002F4D4 2C00B110 */  beq        $a1, $s1, .L8002F588
    /* 1FCD8 8002F4D8 1800BFAF */   sw        $ra, 0x18($sp)
    /* 1FCDC 8002F4DC 0200A228 */  slti       $v0, $a1, 0x2
    /* 1FCE0 8002F4E0 05004010 */  beqz       $v0, .L8002F4F8
    /* 1FCE4 8002F4E4 00000000 */   nop
    /* 1FCE8 8002F4E8 0800A010 */  beqz       $a1, .L8002F50C
    /* 1FCEC 8002F4EC DDFF043C */   lui       $a0, (0xFFDDFFFF >> 16)
    /* 1FCF0 8002F4F0 87BD0008 */  j          .L8002F61C
    /* 1FCF4 8002F4F4 00000000 */   nop
  .L8002F4F8:
    /* 1FCF8 8002F4F8 02000224 */  addiu      $v0, $zero, 0x2
    /* 1FCFC 8002F4FC 3000A210 */  beq        $a1, $v0, .L8002F5C0
    /* 1FD00 8002F500 F4000224 */   addiu     $v0, $zero, 0xF4
    /* 1FD04 8002F504 87BD0008 */  j          .L8002F61C
    /* 1FD08 8002F508 00000000 */   nop
  .L8002F50C:
    /* 1FD0C 8002F50C FFFF8434 */  ori        $a0, $a0, (0xFFDDFFFF & 0xFFFF)
    /* 1FD10 8002F510 0100053C */  lui        $a1, (0x18000 >> 16)
    /* 1FD14 8002F514 0080A534 */  ori        $a1, $a1, (0x18000 & 0xFFFF)
    /* 1FD18 8002F518 C0010224 */  addiu      $v0, $zero, 0x1C0
    /* 1FD1C 8002F51C 300002A6 */  sh         $v0, 0x30($s0)
    /* 1FD20 8002F520 00010224 */  addiu      $v0, $zero, 0x100
    /* 1FD24 8002F524 320002A6 */  sh         $v0, 0x32($s0)
    /* 1FD28 8002F528 0A80023C */  lui        $v0, %hi(D_8009B0F4)
    /* 1FD2C 8002F52C F4B0428C */  lw         $v0, %lo(D_8009B0F4)($v0)
    /* 1FD30 8002F530 40000324 */  addiu      $v1, $zero, 0x40
    /* 1FD34 8002F534 040003A6 */  sh         $v1, 0x4($s0)
    /* 1FD38 8002F538 24104400 */  and        $v0, $v0, $a0
    /* 1FD3C 8002F53C 0A80013C */  lui        $at, %hi(D_8009B0F4)
    /* 1FD40 8002F540 F4B022AC */  sw         $v0, %lo(D_8009B0F4)($at)
    /* 1FD44 8002F544 0A80023C */  lui        $v0, %hi(D_8009B0F4)
    /* 1FD48 8002F548 F4B0428C */  lw         $v0, %lo(D_8009B0F4)($v0)
    /* 1FD4C 8002F54C 0100033C */  lui        $v1, (0x10000 >> 16)
    /* 1FD50 8002F550 1C0005AE */  sw         $a1, 0x1C($s0)
    /* 1FD54 8002F554 25104300 */  or         $v0, $v0, $v1
    /* 1FD58 8002F558 0A80013C */  lui        $at, %hi(D_8009B0F4)
    /* 1FD5C 8002F55C F4B022AC */  sw         $v0, %lo(D_8009B0F4)($at)
    /* 1FD60 8002F560 02000224 */  addiu      $v0, $zero, 0x2
    /* 1FD64 8002F564 460002A2 */  sb         $v0, 0x46($s0)
    /* 1FD68 8002F568 0A80033C */  lui        $v1, %hi(D_8009B118)
    /* 1FD6C 8002F56C 18B1638C */  lw         $v1, %lo(D_8009B118)($v1)
    /* 1FD70 8002F570 10000224 */  addiu      $v0, $zero, 0x10
    /* 1FD74 8002F574 060002A6 */  sh         $v0, 0x6($s0)
    /* 1FD78 8002F578 080003AE */  sw         $v1, 0x8($s0)
    /* 1FD7C 8002F57C 00086324 */  addiu      $v1, $v1, 0x800
    /* 1FD80 8002F580 87BD0008 */  j          .L8002F61C
    /* 1FD84 8002F584 0C0003AE */   sw        $v1, 0xC($s0)
  .L8002F588:
    /* 1FD88 8002F588 DCFF043C */  lui        $a0, (0xFFDCFFFF >> 16)
    /* 1FD8C 8002F58C FFFF8434 */  ori        $a0, $a0, (0xFFDCFFFF & 0xFFFF)
    /* 1FD90 8002F590 00080224 */  addiu      $v0, $zero, 0x800
    /* 1FD94 8002F594 1C0002AE */  sw         $v0, 0x1C($s0)
    /* 1FD98 8002F598 0A80023C */  lui        $v0, %hi(D_8009B0F4)
    /* 1FD9C 8002F59C F4B0428C */  lw         $v0, %lo(D_8009B0F4)($v0)
    /* 1FDA0 8002F5A0 0A80033C */  lui        $v1, %hi(D_8009B118)
    /* 1FDA4 8002F5A4 18B1638C */  lw         $v1, %lo(D_8009B118)($v1)
    /* 1FDA8 8002F5A8 24104400 */  and        $v0, $v0, $a0
    /* 1FDAC 8002F5AC 0A80013C */  lui        $at, %hi(D_8009B0F4)
    /* 1FDB0 8002F5B0 F4B022AC */  sw         $v0, %lo(D_8009B0F4)($at)
    /* 1FDB4 8002F5B4 0C0003AE */  sw         $v1, 0xC($s0)
    /* 1FDB8 8002F5B8 86BD0008 */  j          .L8002F618
    /* 1FDBC 8002F5BC 080003AE */   sw        $v1, 0x8($s0)
  .L8002F5C0:
    /* 1FDC0 8002F5C0 020002A6 */  sh         $v0, 0x2($s0)
    /* 1FDC4 8002F5C4 00010224 */  addiu      $v0, $zero, 0x100
    /* 1FDC8 8002F5C8 060005A6 */  sh         $a1, 0x6($s0)
    /* 1FDCC 8002F5CC 0A80053C */  lui        $a1, %hi(D_8009B118)
    /* 1FDD0 8002F5D0 18B1A58C */  lw         $a1, %lo(D_8009B118)($a1)
    /* 1FDD4 8002F5D4 21200002 */  addu       $a0, $s0, $zero
    /* 1FDD8 8002F5D8 000000A6 */  sh         $zero, 0x0($s0)
    /* 1FDDC 8002F5DC 7A07020C */  jal        func_80081DE8
    /* 1FDE0 8002F5E0 040002A6 */   sh        $v0, 0x4($s0)
    /* 1FDE4 8002F5E4 DCFF043C */  lui        $a0, (0xFFDCFFFF >> 16)
    /* 1FDE8 8002F5E8 FFFF8434 */  ori        $a0, $a0, (0xFFDCFFFF & 0xFFFF)
    /* 1FDEC 8002F5EC 1B80023C */  lui        $v0, %hi(D_801AF000)
    /* 1FDF0 8002F5F0 00F04224 */  addiu      $v0, $v0, %lo(D_801AF000)
    /* 1FDF4 8002F5F4 0C0002AE */  sw         $v0, 0xC($s0)
    /* 1FDF8 8002F5F8 080002AE */  sw         $v0, 0x8($s0)
    /* 1FDFC 8002F5FC 0A80023C */  lui        $v0, %hi(D_8009B0F4)
    /* 1FE00 8002F600 F4B0428C */  lw         $v0, %lo(D_8009B0F4)($v0)
    /* 1FE04 8002F604 00080324 */  addiu      $v1, $zero, 0x800
    /* 1FE08 8002F608 1C0003AE */  sw         $v1, 0x1C($s0)
    /* 1FE0C 8002F60C 24104400 */  and        $v0, $v0, $a0
    /* 1FE10 8002F610 0A80013C */  lui        $at, %hi(D_8009B0F4)
    /* 1FE14 8002F614 F4B022AC */  sw         $v0, %lo(D_8009B0F4)($at)
  .L8002F618:
    /* 1FE18 8002F618 460011A2 */  sb         $s1, 0x46($s0)
  .L8002F61C:
    /* 1FE1C 8002F61C 1800BF8F */  lw         $ra, 0x18($sp)
    /* 1FE20 8002F620 1400B18F */  lw         $s1, 0x14($sp)
    /* 1FE24 8002F624 1000B08F */  lw         $s0, 0x10($sp)
    /* 1FE28 8002F628 0800E003 */  jr         $ra
    /* 1FE2C 8002F62C 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8002F4C0
