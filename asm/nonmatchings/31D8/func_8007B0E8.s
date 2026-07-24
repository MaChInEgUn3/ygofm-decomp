nonmatching func_8007B0E8, 0x10C

glabel func_8007B0E8
    /* 6B8E8 8007B0E8 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 6B8EC 8007B0EC 1800BFAF */  sw         $ra, 0x18($sp)
    /* 6B8F0 8007B0F0 1400B1AF */  sw         $s1, 0x14($sp)
    /* 6B8F4 8007B0F4 23F3010C */  jal        func_8007CC8C
    /* 6B8F8 8007B0F8 1000B0AF */   sw        $s0, 0x10($sp)
    /* 6B8FC 8007B0FC 21180000 */  addu       $v1, $zero, $zero
    /* 6B900 8007B100 1080023C */  lui        $v0, %hi(D_800F8390)
    /* 6B904 8007B104 90834224 */  addiu      $v0, $v0, %lo(D_800F8390)
    /* 6B908 8007B108 000040AC */  sw         $zero, 0x0($v0)
    /* 6B90C 8007B10C 040040AC */  sw         $zero, 0x4($v0)
    /* 6B910 8007B110 080040AC */  sw         $zero, 0x8($v0)
    /* 6B914 8007B114 0F80023C */  lui        $v0, %hi(D_800F5DF0)
    /* 6B918 8007B118 F05D4224 */  addiu      $v0, $v0, %lo(D_800F5DF0)
    /* 6B91C 8007B11C 200040AC */  sw         $zero, 0x20($v0)
    /* 6B920 8007B120 100040AC */  sw         $zero, 0x10($v0)
    /* 6B924 8007B124 000040AC */  sw         $zero, 0x0($v0)
    /* 6B928 8007B128 240040A0 */  sb         $zero, 0x24($v0)
    /* 6B92C 8007B12C 140040A0 */  sb         $zero, 0x14($v0)
    /* 6B930 8007B130 040040A0 */  sb         $zero, 0x4($v0)
  .L8007B134:
    /* 6B934 8007B134 0F80013C */  lui        $at, %hi(D_800F5DF5)
    /* 6B938 8007B138 21082300 */  addu       $at, $at, $v1
    /* 6B93C 8007B13C F55D20A0 */  sb         $zero, %lo(D_800F5DF5)($at)
    /* 6B940 8007B140 0F80013C */  lui        $at, %hi(D_800F5E05)
    /* 6B944 8007B144 21082300 */  addu       $at, $at, $v1
    /* 6B948 8007B148 055E20A0 */  sb         $zero, %lo(D_800F5E05)($at)
    /* 6B94C 8007B14C 0F80013C */  lui        $at, %hi(D_800F5E15)
    /* 6B950 8007B150 21082300 */  addu       $at, $at, $v1
    /* 6B954 8007B154 155E20A0 */  sb         $zero, %lo(D_800F5E15)($at)
    /* 6B958 8007B158 01006324 */  addiu      $v1, $v1, 0x1
    /* 6B95C 8007B15C 08006228 */  slti       $v0, $v1, 0x8
    /* 6B960 8007B160 F4FF4014 */  bnez       $v0, .L8007B134
    /* 6B964 8007B164 21880000 */   addu      $s1, $zero, $zero
    /* 6B968 8007B168 0F80103C */  lui        $s0, %hi(D_800F5E20)
    /* 6B96C 8007B16C 205E1026 */  addiu      $s0, $s0, %lo(D_800F5E20)
  .L8007B170:
    /* 6B970 8007B170 24EA010C */  jal        func_8007A890
    /* 6B974 8007B174 21200002 */   addu      $a0, $s0, $zero
    /* 6B978 8007B178 01003126 */  addiu      $s1, $s1, 0x1
    /* 6B97C 8007B17C 0800222A */  slti       $v0, $s1, 0x8
    /* 6B980 8007B180 FBFF4014 */  bnez       $v0, .L8007B170
    /* 6B984 8007B184 18001026 */   addiu     $s0, $s0, 0x18
    /* 6B988 8007B188 07000324 */  addiu      $v1, $zero, 0x7
    /* 6B98C 8007B18C 70000224 */  addiu      $v0, $zero, 0x70
    /* 6B990 8007B190 0F80013C */  lui        $at, %hi(D_800F5EE4)
    /* 6B994 8007B194 E45E20AC */  sw         $zero, %lo(D_800F5EE4)($at)
    /* 6B998 8007B198 0F80013C */  lui        $at, %hi(D_800F5EE0)
    /* 6B99C 8007B19C E05E20AC */  sw         $zero, %lo(D_800F5EE0)($at)
    /* 6B9A0 8007B1A0 0F80013C */  lui        $at, %hi(D_800F5EE8)
    /* 6B9A4 8007B1A4 E85E20AC */  sw         $zero, %lo(D_800F5EE8)($at)
  .L8007B1A8:
    /* 6B9A8 8007B1A8 0F80013C */  lui        $at, %hi(D_800F5EF0)
    /* 6B9AC 8007B1AC 21082200 */  addu       $at, $at, $v0
    /* 6B9B0 8007B1B0 F05E20AC */  sw         $zero, %lo(D_800F5EF0)($at)
    /* 6B9B4 8007B1B4 FFFF6324 */  addiu      $v1, $v1, -0x1
    /* 6B9B8 8007B1B8 FBFF6104 */  bgez       $v1, .L8007B1A8
    /* 6B9BC 8007B1BC F0FF4224 */   addiu     $v0, $v0, -0x10
    /* 6B9C0 8007B1C0 0F80013C */  lui        $at, %hi(D_800F5F70)
    /* 6B9C4 8007B1C4 A6F8010C */  jal        func_8007E298
    /* 6B9C8 8007B1C8 705F20AC */   sw        $zero, %lo(D_800F5F70)($at)
    /* 6B9CC 8007B1CC 8EF7010C */  jal        func_8007DE38
    /* 6B9D0 8007B1D0 21200000 */   addu      $a0, $zero, $zero
    /* 6B9D4 8007B1D4 41F3010C */  jal        func_8007CD04
    /* 6B9D8 8007B1D8 00000000 */   nop
    /* 6B9DC 8007B1DC 01000224 */  addiu      $v0, $zero, 0x1
    /* 6B9E0 8007B1E0 1800BF8F */  lw         $ra, 0x18($sp)
    /* 6B9E4 8007B1E4 1400B18F */  lw         $s1, 0x14($sp)
    /* 6B9E8 8007B1E8 1000B08F */  lw         $s0, 0x10($sp)
    /* 6B9EC 8007B1EC 0800E003 */  jr         $ra
    /* 6B9F0 8007B1F0 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8007B0E8
