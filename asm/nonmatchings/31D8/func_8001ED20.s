nonmatching func_8001ED20, 0x124

glabel func_8001ED20
    /* F520 8001ED20 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* F524 8001ED24 1000B0AF */  sw         $s0, 0x10($sp)
    /* F528 8001ED28 1400BFAF */  sw         $ra, 0x14($sp)
    /* F52C 8001ED2C E60A010C */  jal        func_80042B98
    /* F530 8001ED30 21808000 */   addu      $s0, $a0, $zero
    /* F534 8001ED34 05004014 */  bnez       $v0, .L8001ED4C
    /* F538 8001ED38 00000000 */   nop
    /* F53C 8001ED3C 5E0C010C */  jal        func_80043178
    /* F540 8001ED40 21200002 */   addu      $a0, $s0, $zero
    /* F544 8001ED44 600000A6 */  sh         $zero, 0x60($s0)
    /* F548 8001ED48 2E0000A6 */  sh         $zero, 0x2E($s0)
  .L8001ED4C:
    /* F54C 8001ED4C 22000492 */  lbu        $a0, 0x22($s0)
    /* F550 8001ED50 00000000 */  nop
    /* F554 8001ED54 11008010 */  beqz       $a0, .L8001ED9C
    /* F558 8001ED58 40000224 */   addiu     $v0, $zero, 0x40
    /* F55C 8001ED5C 2C000386 */  lh         $v1, 0x2C($s0)
    /* F560 8001ED60 00000000 */  nop
    /* F564 8001ED64 1A004300 */  div        $zero, $v0, $v1
    /* F568 8001ED68 02006014 */  bnez       $v1, .L8001ED74
    /* F56C 8001ED6C 00000000 */   nop
    /* F570 8001ED70 0D000700 */  break      7
  .L8001ED74:
    /* F574 8001ED74 FFFF0124 */  addiu      $at, $zero, -0x1
    /* F578 8001ED78 04006114 */  bne        $v1, $at, .L8001ED8C
    /* F57C 8001ED7C 0080013C */   lui       $at, (0x80000000 >> 16)
    /* F580 8001ED80 02004114 */  bne        $v0, $at, .L8001ED8C
    /* F584 8001ED84 00000000 */   nop
    /* F588 8001ED88 0D000600 */  break      6
  .L8001ED8C:
    /* F58C 8001ED8C 12100000 */  mflo       $v0
    /* F590 8001ED90 00000000 */  nop
    /* F594 8001ED94 21108200 */  addu       $v0, $a0, $v0
    /* F598 8001ED98 220002A2 */  sb         $v0, 0x22($s0)
  .L8001ED9C:
    /* F59C 8001ED9C 28000586 */  lh         $a1, 0x28($s0)
    /* F5A0 8001EDA0 2A000686 */  lh         $a2, 0x2A($s0)
    /* F5A4 8001EDA4 60000786 */  lh         $a3, 0x60($s0)
    /* F5A8 8001EDA8 630C010C */  jal        func_8004318C
    /* F5AC 8001EDAC 21200002 */   addu      $a0, $s0, $zero
    /* F5B0 8001EDB0 2C000286 */  lh         $v0, 0x2C($s0)
    /* F5B4 8001EDB4 00080324 */  addiu      $v1, $zero, 0x800
    /* F5B8 8001EDB8 1A006200 */  div        $zero, $v1, $v0
    /* F5BC 8001EDBC 02004014 */  bnez       $v0, .L8001EDC8
    /* F5C0 8001EDC0 00000000 */   nop
    /* F5C4 8001EDC4 0D000700 */  break      7
  .L8001EDC8:
    /* F5C8 8001EDC8 FFFF0124 */  addiu      $at, $zero, -0x1
    /* F5CC 8001EDCC 04004114 */  bne        $v0, $at, .L8001EDE0
    /* F5D0 8001EDD0 0080013C */   lui       $at, (0x80000000 >> 16)
    /* F5D4 8001EDD4 02006114 */  bne        $v1, $at, .L8001EDE0
    /* F5D8 8001EDD8 00000000 */   nop
    /* F5DC 8001EDDC 0D000600 */  break      6
  .L8001EDE0:
    /* F5E0 8001EDE0 12180000 */  mflo       $v1
    /* F5E4 8001EDE4 60000296 */  lhu        $v0, 0x60($s0)
    /* F5E8 8001EDE8 00000000 */  nop
    /* F5EC 8001EDEC 21104300 */  addu       $v0, $v0, $v1
    /* F5F0 8001EDF0 600002A6 */  sh         $v0, 0x60($s0)
    /* F5F4 8001EDF4 00140200 */  sll        $v0, $v0, 16
    /* F5F8 8001EDF8 03140200 */  sra        $v0, $v0, 16
    /* F5FC 8001EDFC 00084228 */  slti       $v0, $v0, 0x800
    /* F600 8001EE00 0C004014 */  bnez       $v0, .L8001EE34
    /* F604 8001EE04 00000000 */   nop
    /* F608 8001EE08 2800028E */  lw         $v0, 0x28($s0)
    /* F60C 8001EE0C 21000392 */  lbu        $v1, 0x21($s0)
    /* F610 8001EE10 220000A2 */  sb         $zero, 0x22($s0)
    /* F614 8001EE14 05006014 */  bnez       $v1, .L8001EE2C
    /* F618 8001EE18 300002AE */   sw        $v0, 0x30($s0)
    /* F61C 8001EE1C 08000296 */  lhu        $v0, 0x8($s0)
    /* F620 8001EE20 00000000 */  nop
    /* F624 8001EE24 FBFF4230 */  andi       $v0, $v0, 0xFFFB
    /* F628 8001EE28 080002A6 */  sh         $v0, 0x8($s0)
  .L8001EE2C:
    /* F62C 8001EE2C 6C0000A2 */  sb         $zero, 0x6C($s0)
    /* F630 8001EE30 240000AE */  sw         $zero, 0x24($s0)
  .L8001EE34:
    /* F634 8001EE34 1400BF8F */  lw         $ra, 0x14($sp)
    /* F638 8001EE38 1000B08F */  lw         $s0, 0x10($sp)
    /* F63C 8001EE3C 0800E003 */  jr         $ra
    /* F640 8001EE40 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8001ED20
