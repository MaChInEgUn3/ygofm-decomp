nonmatching func_8005B36C, 0x16C

glabel func_8005B36C
    /* 4BB6C 8005B36C 21408000 */  addu       $t0, $a0, $zero
    /* 4BB70 8005B370 2158A000 */  addu       $t3, $a1, $zero
    /* 4BB74 8005B374 03000991 */  lbu        $t1, 0x3($t0)
    /* 4BB78 8005B378 0000048D */  lw         $a0, 0x0($t0)
    /* 4BB7C 8005B37C 2150C000 */  addu       $t2, $a2, $zero
    /* 4BB80 8005B380 1400A28F */  lw         $v0, 0x14($sp)
    /* 4BB84 8005B384 1080033C */  lui        $v1, %hi(D_800FE240)
    /* 4BB88 8005B388 40E2638C */  lw         $v1, %lo(D_800FE240)($v1)
    /* 4BB8C 8005B38C 23100200 */  negu       $v0, $v0
    /* 4BB90 8005B390 FF004530 */  andi       $a1, $v0, 0xFF
    /* 4BB94 8005B394 000064AC */  sw         $a0, 0x0($v1)
    /* 4BB98 8005B398 1080063C */  lui        $a2, %hi(D_800FE240)
    /* 4BB9C 8005B39C 40E2C68C */  lw         $a2, %lo(D_800FE240)($a2)
    /* 4BBA0 8005B3A0 0200A104 */  bgez       $a1, .L8005B3AC
    /* 4BBA4 8005B3A4 04000825 */   addiu     $t0, $t0, 0x4
    /* 4BBA8 8005B3A8 0700A524 */  addiu      $a1, $a1, 0x7
  .L8005B3AC:
    /* 4BBAC 8005B3AC 1800A28F */  lw         $v0, 0x18($sp)
    /* 4BBB0 8005B3B0 00000000 */  nop
    /* 4BBB4 8005B3B4 23100200 */  negu       $v0, $v0
    /* 4BBB8 8005B3B8 FF004330 */  andi       $v1, $v0, 0xFF
    /* 4BBBC 8005B3BC C3100500 */  sra        $v0, $a1, 3
    /* 4BBC0 8005B3C0 02006104 */  bgez       $v1, .L8005B3CC
    /* 4BBC4 8005B3C4 1F004430 */   andi      $a0, $v0, 0x1F
    /* 4BBC8 8005B3C8 07006324 */  addiu      $v1, $v1, 0x7
  .L8005B3CC:
    /* 4BBCC 8005B3CC FF00E730 */  andi       $a3, $a3, 0xFF
    /* 4BBD0 8005B3D0 80100300 */  sll        $v0, $v1, 2
    /* 4BBD4 8005B3D4 E0034230 */  andi       $v0, $v0, 0x3E0
    /* 4BBD8 8005B3D8 00E2033C */  lui        $v1, (0xE2000000 >> 16)
    /* 4BBDC 8005B3DC 25104300 */  or         $v0, $v0, $v1
    /* 4BBE0 8005B3E0 0200E104 */  bgez       $a3, .L8005B3EC
    /* 4BBE4 8005B3E4 25208200 */   or        $a0, $a0, $v0
    /* 4BBE8 8005B3E8 0700E724 */  addiu      $a3, $a3, 0x7
  .L8005B3EC:
    /* 4BBEC 8005B3EC 1000A28F */  lw         $v0, 0x10($sp)
    /* 4BBF0 8005B3F0 00000000 */  nop
    /* 4BBF4 8005B3F4 FF004330 */  andi       $v1, $v0, 0xFF
    /* 4BBF8 8005B3F8 C0110700 */  sll        $v0, $a3, 7
    /* 4BBFC 8005B3FC 007C4230 */  andi       $v0, $v0, 0x7C00
    /* 4BC00 8005B400 02006104 */  bgez       $v1, .L8005B40C
    /* 4BC04 8005B404 25208200 */   or        $a0, $a0, $v0
    /* 4BC08 8005B408 07006324 */  addiu      $v1, $v1, 0x7
  .L8005B40C:
    /* 4BC0C 8005B40C C3100300 */  sra        $v0, $v1, 3
    /* 4BC10 8005B410 1F004230 */  andi       $v0, $v0, 0x1F
    /* 4BC14 8005B414 C0130200 */  sll        $v0, $v0, 15
    /* 4BC18 8005B418 25108200 */  or         $v0, $a0, $v0
    /* 4BC1C 8005B41C 0400C2AC */  sw         $v0, 0x4($a2)
    /* 4BC20 8005B420 0800C524 */  addiu      $a1, $a2, 0x8
    /* 4BC24 8005B424 21200001 */  addu       $a0, $t0, $zero
    /* 4BC28 8005B428 08002011 */  beqz       $t1, .L8005B44C
    /* 4BC2C 8005B42C FFFF2325 */   addiu     $v1, $t1, -0x1
    /* 4BC30 8005B430 FFFF0624 */  addiu      $a2, $zero, -0x1
  .L8005B434:
    /* 4BC34 8005B434 0000828C */  lw         $v0, 0x0($a0)
    /* 4BC38 8005B438 04008424 */  addiu      $a0, $a0, 0x4
    /* 4BC3C 8005B43C FFFF6324 */  addiu      $v1, $v1, -0x1
    /* 4BC40 8005B440 0000A2AC */  sw         $v0, 0x0($a1)
    /* 4BC44 8005B444 FBFF6614 */  bne        $v1, $a2, .L8005B434
    /* 4BC48 8005B448 0400A524 */   addiu     $a1, $a1, 0x4
  .L8005B44C:
    /* 4BC4C 8005B44C FF00073C */  lui        $a3, (0xFFFFFF >> 16)
    /* 4BC50 8005B450 FFFFE734 */  ori        $a3, $a3, (0xFFFFFF & 0xFFFF)
    /* 4BC54 8005B454 80300900 */  sll        $a2, $t1, 2
    /* 4BC58 8005B458 00E2023C */  lui        $v0, (0xE2000000 >> 16)
    /* 4BC5C 8005B45C 1080043C */  lui        $a0, %hi(D_800FE240)
    /* 4BC60 8005B460 40E2848C */  lw         $a0, %lo(D_800FE240)($a0)
    /* 4BC64 8005B464 00FF083C */  lui        $t0, (0xFF000000 >> 16)
    /* 4BC68 8005B468 2118C400 */  addu       $v1, $a2, $a0
    /* 4BC6C 8005B46C 080062AC */  sw         $v0, 0x8($v1)
    /* 4BC70 8005B470 02002225 */  addiu      $v0, $t1, 0x2
    /* 4BC74 8005B474 030082A0 */  sb         $v0, 0x3($a0)
    /* 4BC78 8005B478 FFFF4431 */  andi       $a0, $t2, 0xFFFF
    /* 4BC7C 8005B47C 80200400 */  sll        $a0, $a0, 2
    /* 4BC80 8005B480 0C00C624 */  addiu      $a2, $a2, 0xC
    /* 4BC84 8005B484 0400628D */  lw         $v0, 0x4($t3)
    /* 4BC88 8005B488 1080053C */  lui        $a1, %hi(D_800FE240)
    /* 4BC8C 8005B48C 40E2A58C */  lw         $a1, %lo(D_800FE240)($a1)
    /* 4BC90 8005B490 21108200 */  addu       $v0, $a0, $v0
    /* 4BC94 8005B494 0000A38C */  lw         $v1, 0x0($a1)
    /* 4BC98 8005B498 0000428C */  lw         $v0, 0x0($v0)
    /* 4BC9C 8005B49C 24186800 */  and        $v1, $v1, $t0
    /* 4BCA0 8005B4A0 24104700 */  and        $v0, $v0, $a3
    /* 4BCA4 8005B4A4 25186200 */  or         $v1, $v1, $v0
    /* 4BCA8 8005B4A8 0000A3AC */  sw         $v1, 0x0($a1)
    /* 4BCAC 8005B4AC 0400628D */  lw         $v0, 0x4($t3)
    /* 4BCB0 8005B4B0 2130A600 */  addu       $a2, $a1, $a2
    /* 4BCB4 8005B4B4 1080013C */  lui        $at, %hi(D_800FE240)
    /* 4BCB8 8005B4B8 40E226AC */  sw         $a2, %lo(D_800FE240)($at)
    /* 4BCBC 8005B4BC 21208200 */  addu       $a0, $a0, $v0
    /* 4BCC0 8005B4C0 0000828C */  lw         $v0, 0x0($a0)
    /* 4BCC4 8005B4C4 2428A700 */  and        $a1, $a1, $a3
    /* 4BCC8 8005B4C8 24104800 */  and        $v0, $v0, $t0
    /* 4BCCC 8005B4CC 25104500 */  or         $v0, $v0, $a1
    /* 4BCD0 8005B4D0 0800E003 */  jr         $ra
    /* 4BCD4 8005B4D4 000082AC */   sw        $v0, 0x0($a0)
endlabel func_8005B36C
