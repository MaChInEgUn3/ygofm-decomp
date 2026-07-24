nonmatching func_80012DB4, 0xA8

glabel func_80012DB4
    /* 35B4 80012DB4 90018297 */  lhu        $v0, %gp_rel(D_8009B098)($gp)
    /* 35B8 80012DB8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 35BC 80012DBC 00804230 */  andi       $v0, $v0, 0x8000
    /* 35C0 80012DC0 03004014 */  bnez       $v0, .L80012DD0
    /* 35C4 80012DC4 1000BFAF */   sw        $ra, 0x10($sp)
    /* 35C8 80012DC8 B3FD010C */  jal        func_8007F6CC
    /* 35CC 80012DCC 21200000 */   addu      $a0, $zero, $zero
  .L80012DD0:
    /* 35D0 80012DD0 B8018393 */  lbu        $v1, %gp_rel(D_8009B0C0)($gp)
    /* 35D4 80012DD4 C001828F */  lw         $v0, %gp_rel(D_8009B0C8)($gp)
    /* 35D8 80012DD8 00000000 */  nop
    /* 35DC 80012DDC 2A104300 */  slt        $v0, $v0, $v1
    /* 35E0 80012DE0 FBFF4014 */  bnez       $v0, .L80012DD0
    /* 35E4 80012DE4 00000000 */   nop
    /* 35E8 80012DE8 C001828F */  lw         $v0, %gp_rel(D_8009B0C8)($gp)
    /* 35EC 80012DEC 00000000 */  nop
    /* 35F0 80012DF0 B90182A3 */  sb         $v0, %gp_rel(D_8009B0C1)($gp)
    /* 35F4 80012DF4 FF004230 */  andi       $v0, $v0, 0xFF
    /* 35F8 80012DF8 02004010 */  beqz       $v0, .L80012E04
    /* 35FC 80012DFC 01000224 */   addiu     $v0, $zero, 0x1
    /* 3600 80012E00 B90182A3 */  sb         $v0, %gp_rel(D_8009B0C1)($gp)
  .L80012E04:
    /* 3604 80012E04 B9018293 */  lbu        $v0, %gp_rel(D_8009B0C1)($gp)
    /* 3608 80012E08 0A80033C */  lui        $v1, %hi(D_8009AFA4)
    /* 360C 80012E0C A4AF6390 */  lbu        $v1, %lo(D_8009AFA4)($v1)
    /* 3610 80012E10 01004224 */  addiu      $v0, $v0, 0x1
    /* 3614 80012E14 D00182AF */  sw         $v0, %gp_rel(D_8009B0D8)($gp)
    /* 3618 80012E18 02006014 */  bnez       $v1, .L80012E24
    /* 361C 80012E1C 02000524 */   addiu     $a1, $zero, 0x2
    /* 3620 80012E20 D0018593 */  lbu        $a1, %gp_rel(D_8009B0D8)($gp)
  .L80012E24:
    /* 3624 80012E24 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 3628 80012E28 0A80013C */  lui        $at, %hi(D_8009AFA3)
    /* 362C 80012E2C A3AF25A0 */  sb         $a1, %lo(D_8009AFA3)($at)
    /* 3630 80012E30 0A80013C */  lui        $at, %hi(D_8009AFA4)
    /* 3634 80012E34 A4AF20A0 */  sb         $zero, %lo(D_8009AFA4)($at)
    /* 3638 80012E38 C00182AF */  sw         $v0, %gp_rel(D_8009B0C8)($gp)
    /* 363C 80012E3C 5CD0010C */  jal        func_80074170
    /* 3640 80012E40 21200000 */   addu      $a0, $zero, $zero
    /* 3644 80012E44 C401828F */  lw         $v0, %gp_rel(D_8009B0CC)($gp)
    /* 3648 80012E48 1000BF8F */  lw         $ra, 0x10($sp)
    /* 364C 80012E4C 01004224 */  addiu      $v0, $v0, 0x1
    /* 3650 80012E50 C40182AF */  sw         $v0, %gp_rel(D_8009B0CC)($gp)
    /* 3654 80012E54 0800E003 */  jr         $ra
    /* 3658 80012E58 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80012DB4
