nonmatching func_8002DD74, 0x1B8

glabel func_8002DD74
    /* 1E574 8002DD74 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1E578 8002DD78 1400BFAF */  sw         $ra, 0x14($sp)
    /* 1E57C 8002DD7C 7AB3000C */  jal        func_8002CDE8
    /* 1E580 8002DD80 1000B0AF */   sw        $s0, 0x10($sp)
    /* 1E584 8002DD84 0980023C */  lui        $v0, %hi(D_80090B64)
    /* 1E588 8002DD88 640B5024 */  addiu      $s0, $v0, %lo(D_80090B64)
  .L8002DD8C:
    /* 1E58C 8002DD8C 534B000C */  jal        func_80012D4C
    /* 1E590 8002DD90 00000000 */   nop
    /* 1E594 8002DD94 64038393 */  lbu        $v1, %gp_rel(D_8009B26C)($gp)
    /* 1E598 8002DD98 00000000 */  nop
    /* 1E59C 8002DD9C 80006230 */  andi       $v0, $v1, 0x80
    /* 1E5A0 8002DDA0 07004014 */  bnez       $v0, .L8002DDC0
    /* 1E5A4 8002DDA4 1F006230 */   andi      $v0, $v1, 0x1F
    /* 1E5A8 8002DDA8 80006234 */  ori        $v0, $v1, 0x80
    /* 1E5AC 8002DDAC 640382A3 */  sb         $v0, %gp_rel(D_8009B26C)($gp)
    /* 1E5B0 8002DDB0 63B3000C */  jal        func_8002CD8C
    /* 1E5B4 8002DDB4 00000000 */   nop
    /* 1E5B8 8002DDB8 63B70008 */  j          .L8002DD8C
    /* 1E5BC 8002DDBC 00000000 */   nop
  .L8002DDC0:
    /* 1E5C0 8002DDC0 80100200 */  sll        $v0, $v0, 2
    /* 1E5C4 8002DDC4 21105000 */  addu       $v0, $v0, $s0
    /* 1E5C8 8002DDC8 0000428C */  lw         $v0, 0x0($v0)
    /* 1E5CC 8002DDCC 00000000 */  nop
    /* 1E5D0 8002DDD0 09F84000 */  jalr       $v0
    /* 1E5D4 8002DDD4 00000000 */   nop
    /* 1E5D8 8002DDD8 64038293 */  lbu        $v0, %gp_rel(D_8009B26C)($gp)
    /* 1E5DC 8002DDDC 00000000 */  nop
    /* 1E5E0 8002DDE0 40004230 */  andi       $v0, $v0, 0x40
    /* 1E5E4 8002DDE4 E9FF4014 */  bnez       $v0, .L8002DD8C
    /* 1E5E8 8002DDE8 00000000 */   nop
    /* 1E5EC 8002DDEC C056000C */  jal        func_80015B00
    /* 1E5F0 8002DDF0 00000000 */   nop
    /* 1E5F4 8002DDF4 63B70008 */  j          .L8002DD8C
    /* 1E5F8 8002DDF8 00000000 */   nop
  alabel D_8002DDFC
    /* 1E5FC 8002DDFC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1E600 8002DE00 1000BFAF */  sw         $ra, 0x10($sp)
    /* 1E604 8002DE04 01000224 */  addiu      $v0, $zero, 0x1
    /* 1E608 8002DE08 2B00A210 */  beq        $a1, $v0, .L8002DEB8
    /* 1E60C 8002DE0C 21308000 */   addu      $a2, $a0, $zero
    /* 1E610 8002DE10 0200A228 */  slti       $v0, $a1, 0x2
    /* 1E614 8002DE14 05004010 */  beqz       $v0, .L8002DE2C
    /* 1E618 8002DE18 00000000 */   nop
    /* 1E61C 8002DE1C 0800A010 */  beqz       $a1, .L8002DE40
    /* 1E620 8002DE20 DDFF043C */   lui       $a0, (0xFFDDFFFF >> 16)
    /* 1E624 8002DE24 C7B70008 */  j          .L8002DF1C
    /* 1E628 8002DE28 00000000 */   nop
  .L8002DE2C:
    /* 1E62C 8002DE2C 02000224 */  addiu      $v0, $zero, 0x2
    /* 1E630 8002DE30 3000A210 */  beq        $a1, $v0, .L8002DEF4
    /* 1E634 8002DE34 F0000224 */   addiu     $v0, $zero, 0xF0
    /* 1E638 8002DE38 C7B70008 */  j          .L8002DF1C
    /* 1E63C 8002DE3C 00000000 */   nop
  .L8002DE40:
    /* 1E640 8002DE40 FFFF8434 */  ori        $a0, $a0, (0xFFDDFFFF & 0xFFFF)
    /* 1E644 8002DE44 00010224 */  addiu      $v0, $zero, 0x100
    /* 1E648 8002DE48 3200C2A4 */  sh         $v0, 0x32($a2)
    /* 1E64C 8002DE4C 40000224 */  addiu      $v0, $zero, 0x40
    /* 1E650 8002DE50 0400C2A4 */  sh         $v0, 0x4($a2)
    /* 1E654 8002DE54 0A80023C */  lui        $v0, %hi(D_8009B0F4)
    /* 1E658 8002DE58 F4B0428C */  lw         $v0, %lo(D_8009B0F4)($v0)
    /* 1E65C 8002DE5C 10000324 */  addiu      $v1, $zero, 0x10
    /* 1E660 8002DE60 0600C3A4 */  sh         $v1, 0x6($a2)
    /* 1E664 8002DE64 24104400 */  and        $v0, $v0, $a0
    /* 1E668 8002DE68 0A80013C */  lui        $at, %hi(D_8009B0F4)
    /* 1E66C 8002DE6C F4B022AC */  sw         $v0, %lo(D_8009B0F4)($at)
    /* 1E670 8002DE70 0A80023C */  lui        $v0, %hi(D_8009B0F4)
    /* 1E674 8002DE74 F4B0428C */  lw         $v0, %lo(D_8009B0F4)($v0)
    /* 1E678 8002DE78 0100033C */  lui        $v1, (0x10000 >> 16)
    /* 1E67C 8002DE7C 3000C0A4 */  sh         $zero, 0x30($a2)
    /* 1E680 8002DE80 25104300 */  or         $v0, $v0, $v1
    /* 1E684 8002DE84 0A80013C */  lui        $at, %hi(D_8009B0F4)
    /* 1E688 8002DE88 F4B022AC */  sw         $v0, %lo(D_8009B0F4)($at)
    /* 1E68C 8002DE8C 02000224 */  addiu      $v0, $zero, 0x2
    /* 1E690 8002DE90 4600C2A0 */  sb         $v0, 0x46($a2)
    /* 1E694 8002DE94 3800C28C */  lw         $v0, 0x38($a2)
    /* 1E698 8002DE98 0A80033C */  lui        $v1, %hi(D_8009B118)
    /* 1E69C 8002DE9C 18B1638C */  lw         $v1, %lo(D_8009B118)($v1)
    /* 1E6A0 8002DEA0 C0120200 */  sll        $v0, $v0, 11
    /* 1E6A4 8002DEA4 0800C3AC */  sw         $v1, 0x8($a2)
    /* 1E6A8 8002DEA8 00086324 */  addiu      $v1, $v1, 0x800
    /* 1E6AC 8002DEAC 1C00C2AC */  sw         $v0, 0x1C($a2)
    /* 1E6B0 8002DEB0 C7B70008 */  j          .L8002DF1C
    /* 1E6B4 8002DEB4 0C00C3AC */   sw        $v1, 0xC($a2)
  .L8002DEB8:
    /* 1E6B8 8002DEB8 DCFF043C */  lui        $a0, (0xFFDCFFFF >> 16)
    /* 1E6BC 8002DEBC FFFF8434 */  ori        $a0, $a0, (0xFFDCFFFF & 0xFFFF)
    /* 1E6C0 8002DEC0 00080224 */  addiu      $v0, $zero, 0x800
    /* 1E6C4 8002DEC4 1C00C2AC */  sw         $v0, 0x1C($a2)
    /* 1E6C8 8002DEC8 0A80023C */  lui        $v0, %hi(D_8009B0F4)
    /* 1E6CC 8002DECC F4B0428C */  lw         $v0, %lo(D_8009B0F4)($v0)
    /* 1E6D0 8002DED0 0A80033C */  lui        $v1, %hi(D_8009B118)
    /* 1E6D4 8002DED4 18B1638C */  lw         $v1, %lo(D_8009B118)($v1)
    /* 1E6D8 8002DED8 24104400 */  and        $v0, $v0, $a0
    /* 1E6DC 8002DEDC 0A80013C */  lui        $at, %hi(D_8009B0F4)
    /* 1E6E0 8002DEE0 F4B022AC */  sw         $v0, %lo(D_8009B0F4)($at)
    /* 1E6E4 8002DEE4 0C00C3AC */  sw         $v1, 0xC($a2)
    /* 1E6E8 8002DEE8 0800C3AC */  sw         $v1, 0x8($a2)
    /* 1E6EC 8002DEEC C7B70008 */  j          .L8002DF1C
    /* 1E6F0 8002DEF0 4600C5A0 */   sb        $a1, 0x46($a2)
  .L8002DEF4:
    /* 1E6F4 8002DEF4 0200C2A4 */  sh         $v0, 0x2($a2)
    /* 1E6F8 8002DEF8 00010224 */  addiu      $v0, $zero, 0x100
    /* 1E6FC 8002DEFC 0400C2A4 */  sh         $v0, 0x4($a2)
    /* 1E700 8002DF00 04000224 */  addiu      $v0, $zero, 0x4
    /* 1E704 8002DF04 0A80053C */  lui        $a1, %hi(D_8009B118)
    /* 1E708 8002DF08 18B1A58C */  lw         $a1, %lo(D_8009B118)($a1)
    /* 1E70C 8002DF0C 2120C000 */  addu       $a0, $a2, $zero
    /* 1E710 8002DF10 0000C0A4 */  sh         $zero, 0x0($a2)
    /* 1E714 8002DF14 7A07020C */  jal        func_80081DE8
    /* 1E718 8002DF18 0600C2A4 */   sh        $v0, 0x6($a2)
  .L8002DF1C:
    /* 1E71C 8002DF1C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 1E720 8002DF20 00000000 */  nop
    /* 1E724 8002DF24 0800E003 */  jr         $ra
    /* 1E728 8002DF28 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8002DD74
