nonmatching func_8005FC1C, 0x228

glabel func_8005FC1C
    /* 5041C 8005FC1C 0F80023C */  lui        $v0, %hi(D_800F5918)
    /* 50420 8005FC20 18594324 */  addiu      $v1, $v0, %lo(D_800F5918)
    /* 50424 8005FC24 0980023C */  lui        $v0, %hi(func_80089E20)
    /* 50428 8005FC28 209E4224 */  addiu      $v0, $v0, %lo(func_80089E20)
    /* 5042C 8005FC2C 06008214 */  bne        $a0, $v0, .L8005FC48
    /* 50430 8005FC30 21280000 */   addu      $a1, $zero, $zero
    /* 50434 8005FC34 1A7F0108 */  j          .L8005FC68
    /* 50438 8005FC38 FFFF0524 */   addiu     $a1, $zero, -0x1
  .L8005FC3C:
    /* 5043C 8005FC3C 0400658C */  lw         $a1, 0x4($v1)
    /* 50440 8005FC40 1B7F0108 */  j          .L8005FC6C
    /* 50444 8005FC44 FFFF023C */   lui       $v0, (0xFFFF0000 >> 16)
  .L8005FC48:
    /* 50448 8005FC48 0000628C */  lw         $v0, 0x0($v1)
    /* 5044C 8005FC4C 00000000 */  nop
    /* 50450 8005FC50 FAFF4410 */  beq        $v0, $a0, .L8005FC3C
    /* 50454 8005FC54 0100A524 */   addiu     $a1, $a1, 0x1
    /* 50458 8005FC58 5000A228 */  slti       $v0, $a1, 0x50
    /* 5045C 8005FC5C FAFF4014 */  bnez       $v0, .L8005FC48
    /* 50460 8005FC60 08006324 */   addiu     $v1, $v1, 0x8
    /* 50464 8005FC64 FFFF0524 */  addiu      $a1, $zero, -0x1
  .L8005FC68:
    /* 50468 8005FC68 FFFF023C */  lui        $v0, (0xFFFF0000 >> 16)
  .L8005FC6C:
    /* 5046C 8005FC6C 2418A200 */  and        $v1, $a1, $v0
    /* 50470 8005FC70 3000023C */  lui        $v0, (0x300000 >> 16)
    /* 50474 8005FC74 1F006210 */  beq        $v1, $v0, .L8005FCF4
    /* 50478 8005FC78 2B104300 */   sltu      $v0, $v0, $v1
    /* 5047C 8005FC7C 0E004014 */  bnez       $v0, .L8005FCB8
    /* 50480 8005FC80 1001023C */   lui       $v0, (0x1100000 >> 16)
    /* 50484 8005FC84 1000023C */  lui        $v0, (0x100000 >> 16)
    /* 50488 8005FC88 1A006210 */  beq        $v1, $v0, .L8005FCF4
    /* 5048C 8005FC8C 2B104300 */   sltu      $v0, $v0, $v1
    /* 50490 8005FC90 05004014 */  bnez       $v0, .L8005FCA8
    /* 50494 8005FC94 2000023C */   lui       $v0, (0x200000 >> 16)
    /* 50498 8005FC98 16006010 */  beqz       $v1, .L8005FCF4
    /* 5049C 8005FC9C 21108000 */   addu      $v0, $a0, $zero
    /* 504A0 8005FCA0 8F7F0108 */  j          .L8005FE3C
    /* 504A4 8005FCA4 00000000 */   nop
  .L8005FCA8:
    /* 504A8 8005FCA8 12006210 */  beq        $v1, $v0, .L8005FCF4
    /* 504AC 8005FCAC 21108000 */   addu      $v0, $a0, $zero
    /* 504B0 8005FCB0 8F7F0108 */  j          .L8005FE3C
    /* 504B4 8005FCB4 00000000 */   nop
  .L8005FCB8:
    /* 504B8 8005FCB8 45006210 */  beq        $v1, $v0, .L8005FDD0
    /* 504BC 8005FCBC 2B104300 */   sltu      $v0, $v0, $v1
    /* 504C0 8005FCC0 06004014 */  bnez       $v0, .L8005FCDC
    /* 504C4 8005FCC4 2001023C */   lui       $v0, (0x1200000 >> 16)
    /* 504C8 8005FCC8 0001023C */  lui        $v0, (0x1000000 >> 16)
    /* 504CC 8005FCCC 40006210 */  beq        $v1, $v0, .L8005FDD0
    /* 504D0 8005FCD0 21108000 */   addu      $v0, $a0, $zero
    /* 504D4 8005FCD4 8F7F0108 */  j          .L8005FE3C
    /* 504D8 8005FCD8 00000000 */   nop
  .L8005FCDC:
    /* 504DC 8005FCDC 3C006210 */  beq        $v1, $v0, .L8005FDD0
    /* 504E0 8005FCE0 3001023C */   lui       $v0, (0x1300000 >> 16)
    /* 504E4 8005FCE4 3A006210 */  beq        $v1, $v0, .L8005FDD0
    /* 504E8 8005FCE8 21108000 */   addu      $v0, $a0, $zero
    /* 504EC 8005FCEC 8F7F0108 */  j          .L8005FE3C
    /* 504F0 8005FCF0 00000000 */   nop
  .L8005FCF4:
    /* 504F4 8005FCF4 FFFFA330 */  andi       $v1, $a1, 0xFFFF
    /* 504F8 8005FCF8 15000224 */  addiu      $v0, $zero, 0x15
    /* 504FC 8005FCFC 30006210 */  beq        $v1, $v0, .L8005FDC0
    /* 50500 8005FD00 0780023C */   lui       $v0, %hi(func_8006A268)
    /* 50504 8005FD04 16006228 */  slti       $v0, $v1, 0x16
    /* 50508 8005FD08 0F004010 */  beqz       $v0, .L8005FD48
    /* 5050C 8005FD0C 0D000224 */   addiu     $v0, $zero, 0xD
    /* 50510 8005FD10 27006210 */  beq        $v1, $v0, .L8005FDB0
    /* 50514 8005FD14 0780023C */   lui       $v0, %hi(func_80069F94)
    /* 50518 8005FD18 0E006228 */  slti       $v0, $v1, 0xE
    /* 5051C 8005FD1C 05004010 */  beqz       $v0, .L8005FD34
    /* 50520 8005FD20 09000224 */   addiu     $v0, $zero, 0x9
    /* 50524 8005FD24 1A006210 */  beq        $v1, $v0, .L8005FD90
    /* 50528 8005FD28 0780023C */   lui       $v0, %hi(func_80069E44)
    /* 5052C 8005FD2C 0800E003 */  jr         $ra
    /* 50530 8005FD30 21108000 */   addu      $v0, $a0, $zero
  .L8005FD34:
    /* 50534 8005FD34 11000224 */  addiu      $v0, $zero, 0x11
    /* 50538 8005FD38 19006210 */  beq        $v1, $v0, .L8005FDA0
    /* 5053C 8005FD3C 0780023C */   lui       $v0, %hi(func_8006A0E8)
    /* 50540 8005FD40 0800E003 */  jr         $ra
    /* 50544 8005FD44 21108000 */   addu      $v0, $a0, $zero
  .L8005FD48:
    /* 50548 8005FD48 0D020224 */  addiu      $v0, $zero, 0x20D
    /* 5054C 8005FD4C 1A006210 */  beq        $v1, $v0, .L8005FDB8
    /* 50550 8005FD50 0780023C */   lui       $v0, %hi(func_8006A540)
    /* 50554 8005FD54 0E026228 */  slti       $v0, $v1, 0x20E
    /* 50558 8005FD58 05004010 */  beqz       $v0, .L8005FD70
    /* 5055C 8005FD5C 09020224 */   addiu     $v0, $zero, 0x209
    /* 50560 8005FD60 0D006210 */  beq        $v1, $v0, .L8005FD98
    /* 50564 8005FD64 0780023C */   lui       $v0, %hi(func_8006A3F0)
    /* 50568 8005FD68 0800E003 */  jr         $ra
    /* 5056C 8005FD6C 21108000 */   addu      $v0, $a0, $zero
  .L8005FD70:
    /* 50570 8005FD70 11020224 */  addiu      $v0, $zero, 0x211
    /* 50574 8005FD74 0C006210 */  beq        $v1, $v0, .L8005FDA8
    /* 50578 8005FD78 0780023C */   lui       $v0, %hi(func_8006A694)
    /* 5057C 8005FD7C 15020224 */  addiu      $v0, $zero, 0x215
    /* 50580 8005FD80 11006210 */  beq        $v1, $v0, .L8005FDC8
    /* 50584 8005FD84 0780023C */   lui       $v0, %hi(func_8006A814)
    /* 50588 8005FD88 0800E003 */  jr         $ra
    /* 5058C 8005FD8C 21108000 */   addu      $v0, $a0, $zero
  .L8005FD90:
    /* 50590 8005FD90 0800E003 */  jr         $ra
    /* 50594 8005FD94 449E4224 */   addiu     $v0, $v0, %lo(func_80069E44)
  .L8005FD98:
    /* 50598 8005FD98 0800E003 */  jr         $ra
    /* 5059C 8005FD9C F0A34224 */   addiu     $v0, $v0, %lo(func_8006A3F0)
  .L8005FDA0:
    /* 505A0 8005FDA0 0800E003 */  jr         $ra
    /* 505A4 8005FDA4 E8A04224 */   addiu     $v0, $v0, %lo(func_8006A0E8)
  .L8005FDA8:
    /* 505A8 8005FDA8 0800E003 */  jr         $ra
    /* 505AC 8005FDAC 94A64224 */   addiu     $v0, $v0, %lo(func_8006A694)
  .L8005FDB0:
    /* 505B0 8005FDB0 0800E003 */  jr         $ra
    /* 505B4 8005FDB4 949F4224 */   addiu     $v0, $v0, %lo(func_80069F94)
  .L8005FDB8:
    /* 505B8 8005FDB8 0800E003 */  jr         $ra
    /* 505BC 8005FDBC 40A54224 */   addiu     $v0, $v0, %lo(func_8006A540)
  .L8005FDC0:
    /* 505C0 8005FDC0 0800E003 */  jr         $ra
    /* 505C4 8005FDC4 68A24224 */   addiu     $v0, $v0, %lo(func_8006A268)
  .L8005FDC8:
    /* 505C8 8005FDC8 0800E003 */  jr         $ra
    /* 505CC 8005FDCC 14A84224 */   addiu     $v0, $v0, %lo(func_8006A814)
  .L8005FDD0:
    /* 505D0 8005FDD0 FFFFA330 */  andi       $v1, $a1, 0xFFFF
    /* 505D4 8005FDD4 15000224 */  addiu      $v0, $zero, 0x15
    /* 505D8 8005FDD8 14006210 */  beq        $v1, $v0, .L8005FE2C
    /* 505DC 8005FDDC 0780023C */   lui       $v0, %hi(func_8006AAFC)
    /* 505E0 8005FDE0 16006228 */  slti       $v0, $v1, 0x16
    /* 505E4 8005FDE4 05004010 */  beqz       $v0, .L8005FDFC
    /* 505E8 8005FDE8 0D000224 */   addiu     $v0, $zero, 0xD
    /* 505EC 8005FDEC 0B006210 */  beq        $v1, $v0, .L8005FE1C
    /* 505F0 8005FDF0 0780023C */   lui       $v0, %hi(func_8006A99C)
    /* 505F4 8005FDF4 0800E003 */  jr         $ra
    /* 505F8 8005FDF8 21108000 */   addu      $v0, $a0, $zero
  .L8005FDFC:
    /* 505FC 8005FDFC 0D020224 */  addiu      $v0, $zero, 0x20D
    /* 50600 8005FE00 08006210 */  beq        $v1, $v0, .L8005FE24
    /* 50604 8005FE04 0780023C */   lui       $v0, %hi(func_8006AC88)
    /* 50608 8005FE08 15020224 */  addiu      $v0, $zero, 0x215
    /* 5060C 8005FE0C 09006210 */  beq        $v1, $v0, .L8005FE34
    /* 50610 8005FE10 0780023C */   lui       $v0, %hi(func_8006ADE8)
    /* 50614 8005FE14 0800E003 */  jr         $ra
    /* 50618 8005FE18 21108000 */   addu      $v0, $a0, $zero
  .L8005FE1C:
    /* 5061C 8005FE1C 0800E003 */  jr         $ra
    /* 50620 8005FE20 9CA94224 */   addiu     $v0, $v0, %lo(func_8006A99C)
  .L8005FE24:
    /* 50624 8005FE24 0800E003 */  jr         $ra
    /* 50628 8005FE28 88AC4224 */   addiu     $v0, $v0, %lo(func_8006AC88)
  .L8005FE2C:
    /* 5062C 8005FE2C 0800E003 */  jr         $ra
    /* 50630 8005FE30 FCAA4224 */   addiu     $v0, $v0, %lo(func_8006AAFC)
  .L8005FE34:
    /* 50634 8005FE34 0800E003 */  jr         $ra
    /* 50638 8005FE38 E8AD4224 */   addiu     $v0, $v0, %lo(func_8006ADE8)
  .L8005FE3C:
    /* 5063C 8005FE3C 0800E003 */  jr         $ra
    /* 50640 8005FE40 00000000 */   nop
endlabel func_8005FC1C
