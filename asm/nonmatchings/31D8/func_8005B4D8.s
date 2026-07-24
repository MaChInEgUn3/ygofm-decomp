nonmatching func_8005B4D8, 0x124

glabel func_8005B4D8
    /* 4BCD8 8005B4D8 2160A000 */  addu       $t4, $a1, $zero
    /* 4BCDC 8005B4DC 00E1053C */  lui        $a1, (0xE1000200 >> 16)
    /* 4BCE0 8005B4E0 0002A534 */  ori        $a1, $a1, (0xE1000200 & 0xFFFF)
    /* 4BCE4 8005B4E4 00E6083C */  lui        $t0, (0xE6000001 >> 16)
    /* 4BCE8 8005B4E8 01000835 */  ori        $t0, $t0, (0xE6000001 & 0xFFFF)
    /* 4BCEC 8005B4EC 03008B90 */  lbu        $t3, 0x3($a0)
    /* 4BCF0 8005B4F0 0000828C */  lw         $v0, 0x0($a0)
    /* 4BCF4 8005B4F4 04008424 */  addiu      $a0, $a0, 0x4
    /* 4BCF8 8005B4F8 1080033C */  lui        $v1, %hi(D_800FE240)
    /* 4BCFC 8005B4FC 40E2638C */  lw         $v1, %lo(D_800FE240)($v1)
    /* 4BD00 8005B500 FFFF6925 */  addiu      $t1, $t3, -0x1
    /* 4BD04 8005B504 000062AC */  sw         $v0, 0x0($v1)
    /* 4BD08 8005B508 0300E230 */  andi       $v0, $a3, 0x3
    /* 4BD0C 8005B50C 40110200 */  sll        $v0, $v0, 5
    /* 4BD10 8005B510 25104500 */  or         $v0, $v0, $a1
    /* 4BD14 8005B514 1080033C */  lui        $v1, %hi(D_800FE240)
    /* 4BD18 8005B518 40E2638C */  lw         $v1, %lo(D_800FE240)($v1)
    /* 4BD1C 8005B51C 2128C000 */  addu       $a1, $a2, $zero
    /* 4BD20 8005B520 0C006A24 */  addiu      $t2, $v1, 0xC
    /* 4BD24 8005B524 040062AC */  sw         $v0, 0x4($v1)
    /* 4BD28 8005B528 08006011 */  beqz       $t3, .L8005B54C
    /* 4BD2C 8005B52C 080068AC */   sw        $t0, 0x8($v1)
    /* 4BD30 8005B530 FFFF0324 */  addiu      $v1, $zero, -0x1
  .L8005B534:
    /* 4BD34 8005B534 0000828C */  lw         $v0, 0x0($a0)
    /* 4BD38 8005B538 04008424 */  addiu      $a0, $a0, 0x4
    /* 4BD3C 8005B53C FFFF2925 */  addiu      $t1, $t1, -0x1
    /* 4BD40 8005B540 000042AD */  sw         $v0, 0x0($t2)
    /* 4BD44 8005B544 FBFF2315 */  bne        $t1, $v1, .L8005B534
    /* 4BD48 8005B548 04004A25 */   addiu     $t2, $t2, 0x4
  .L8005B54C:
    /* 4BD4C 8005B54C 80400B00 */  sll        $t0, $t3, 2
    /* 4BD50 8005B550 1080043C */  lui        $a0, %hi(D_800FE240)
    /* 4BD54 8005B554 40E2848C */  lw         $a0, %lo(D_800FE240)($a0)
    /* 4BD58 8005B558 00E6023C */  lui        $v0, (0xE6000000 >> 16)
    /* 4BD5C 8005B55C 21180401 */  addu       $v1, $t0, $a0
    /* 4BD60 8005B560 0C0062AC */  sw         $v0, 0xC($v1)
    /* 4BD64 8005B564 03006225 */  addiu      $v0, $t3, 0x3
    /* 4BD68 8005B568 0800E004 */  bltz       $a3, .L8005B58C
    /* 4BD6C 8005B56C 030082A0 */   sb        $v0, 0x3($a0)
    /* 4BD70 8005B570 1080033C */  lui        $v1, %hi(D_800FE240)
    /* 4BD74 8005B574 40E2638C */  lw         $v1, %lo(D_800FE240)($v1)
    /* 4BD78 8005B578 00000000 */  nop
    /* 4BD7C 8005B57C 0F006290 */  lbu        $v0, 0xF($v1)
    /* 4BD80 8005B580 00000000 */  nop
    /* 4BD84 8005B584 02004234 */  ori        $v0, $v0, 0x2
    /* 4BD88 8005B588 0F0062A0 */  sb         $v0, 0xF($v1)
  .L8005B58C:
    /* 4BD8C 8005B58C FF00063C */  lui        $a2, (0xFFFFFF >> 16)
    /* 4BD90 8005B590 FFFFC634 */  ori        $a2, $a2, (0xFFFFFF & 0xFFFF)
    /* 4BD94 8005B594 FFFFA430 */  andi       $a0, $a1, 0xFFFF
    /* 4BD98 8005B598 80200400 */  sll        $a0, $a0, 2
    /* 4BD9C 8005B59C 00FF073C */  lui        $a3, (0xFF000000 >> 16)
    /* 4BDA0 8005B5A0 0400828D */  lw         $v0, 0x4($t4)
    /* 4BDA4 8005B5A4 1080053C */  lui        $a1, %hi(D_800FE240)
    /* 4BDA8 8005B5A8 40E2A58C */  lw         $a1, %lo(D_800FE240)($a1)
    /* 4BDAC 8005B5AC 21108200 */  addu       $v0, $a0, $v0
    /* 4BDB0 8005B5B0 0000A38C */  lw         $v1, 0x0($a1)
    /* 4BDB4 8005B5B4 0000428C */  lw         $v0, 0x0($v0)
    /* 4BDB8 8005B5B8 24186700 */  and        $v1, $v1, $a3
    /* 4BDBC 8005B5BC 24104600 */  and        $v0, $v0, $a2
    /* 4BDC0 8005B5C0 25186200 */  or         $v1, $v1, $v0
    /* 4BDC4 8005B5C4 0000A3AC */  sw         $v1, 0x0($a1)
    /* 4BDC8 8005B5C8 0400828D */  lw         $v0, 0x4($t4)
    /* 4BDCC 8005B5CC 00000000 */  nop
    /* 4BDD0 8005B5D0 21208200 */  addu       $a0, $a0, $v0
    /* 4BDD4 8005B5D4 10000225 */  addiu      $v0, $t0, 0x10
    /* 4BDD8 8005B5D8 2110A200 */  addu       $v0, $a1, $v0
    /* 4BDDC 8005B5DC 0000838C */  lw         $v1, 0x0($a0)
    /* 4BDE0 8005B5E0 2428A600 */  and        $a1, $a1, $a2
    /* 4BDE4 8005B5E4 1080013C */  lui        $at, %hi(D_800FE240)
    /* 4BDE8 8005B5E8 40E222AC */  sw         $v0, %lo(D_800FE240)($at)
    /* 4BDEC 8005B5EC 24186700 */  and        $v1, $v1, $a3
    /* 4BDF0 8005B5F0 25186500 */  or         $v1, $v1, $a1
    /* 4BDF4 8005B5F4 0800E003 */  jr         $ra
    /* 4BDF8 8005B5F8 000083AC */   sw        $v1, 0x0($a0)
endlabel func_8005B4D8
