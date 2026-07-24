nonmatching func_8007AFA4, 0x144

glabel func_8007AFA4
    /* 6B7A4 8007AFA4 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 6B7A8 8007AFA8 1800BFAF */  sw         $ra, 0x18($sp)
    /* 6B7AC 8007AFAC 1400B1AF */  sw         $s1, 0x14($sp)
    /* 6B7B0 8007AFB0 45F3010C */  jal        func_8007CD14
    /* 6B7B4 8007AFB4 1000B0AF */   sw        $s0, 0x10($sp)
    /* 6B7B8 8007AFB8 46004014 */  bnez       $v0, .L8007B0D4
    /* 6B7BC 8007AFBC 21100000 */   addu      $v0, $zero, $zero
    /* 6B7C0 8007AFC0 21180000 */  addu       $v1, $zero, $zero
    /* 6B7C4 8007AFC4 1080023C */  lui        $v0, %hi(D_800F8390)
    /* 6B7C8 8007AFC8 90834224 */  addiu      $v0, $v0, %lo(D_800F8390)
    /* 6B7CC 8007AFCC 000040AC */  sw         $zero, 0x0($v0)
    /* 6B7D0 8007AFD0 040040AC */  sw         $zero, 0x4($v0)
    /* 6B7D4 8007AFD4 080040AC */  sw         $zero, 0x8($v0)
    /* 6B7D8 8007AFD8 0F80023C */  lui        $v0, %hi(D_800F5DF0)
    /* 6B7DC 8007AFDC F05D4224 */  addiu      $v0, $v0, %lo(D_800F5DF0)
    /* 6B7E0 8007AFE0 200040AC */  sw         $zero, 0x20($v0)
    /* 6B7E4 8007AFE4 100040AC */  sw         $zero, 0x10($v0)
    /* 6B7E8 8007AFE8 000040AC */  sw         $zero, 0x0($v0)
    /* 6B7EC 8007AFEC 240040A0 */  sb         $zero, 0x24($v0)
    /* 6B7F0 8007AFF0 140040A0 */  sb         $zero, 0x14($v0)
    /* 6B7F4 8007AFF4 040040A0 */  sb         $zero, 0x4($v0)
  .L8007AFF8:
    /* 6B7F8 8007AFF8 0F80013C */  lui        $at, %hi(D_800F5DF5)
    /* 6B7FC 8007AFFC 21082300 */  addu       $at, $at, $v1
    /* 6B800 8007B000 F55D20A0 */  sb         $zero, %lo(D_800F5DF5)($at)
    /* 6B804 8007B004 0F80013C */  lui        $at, %hi(D_800F5E05)
    /* 6B808 8007B008 21082300 */  addu       $at, $at, $v1
    /* 6B80C 8007B00C 055E20A0 */  sb         $zero, %lo(D_800F5E05)($at)
    /* 6B810 8007B010 0F80013C */  lui        $at, %hi(D_800F5E15)
    /* 6B814 8007B014 21082300 */  addu       $at, $at, $v1
    /* 6B818 8007B018 155E20A0 */  sb         $zero, %lo(D_800F5E15)($at)
    /* 6B81C 8007B01C 01006324 */  addiu      $v1, $v1, 0x1
    /* 6B820 8007B020 08006228 */  slti       $v0, $v1, 0x8
    /* 6B824 8007B024 F4FF4014 */  bnez       $v0, .L8007AFF8
    /* 6B828 8007B028 21880000 */   addu      $s1, $zero, $zero
    /* 6B82C 8007B02C 0F80103C */  lui        $s0, %hi(D_800F5E20)
    /* 6B830 8007B030 205E1026 */  addiu      $s0, $s0, %lo(D_800F5E20)
  .L8007B034:
    /* 6B834 8007B034 24EA010C */  jal        func_8007A890
    /* 6B838 8007B038 21200002 */   addu      $a0, $s0, $zero
    /* 6B83C 8007B03C 01003126 */  addiu      $s1, $s1, 0x1
    /* 6B840 8007B040 0800222A */  slti       $v0, $s1, 0x8
    /* 6B844 8007B044 FBFF4014 */  bnez       $v0, .L8007B034
    /* 6B848 8007B048 18001026 */   addiu     $s0, $s0, 0x18
    /* 6B84C 8007B04C 07000324 */  addiu      $v1, $zero, 0x7
    /* 6B850 8007B050 70000224 */  addiu      $v0, $zero, 0x70
    /* 6B854 8007B054 0F80013C */  lui        $at, %hi(D_800F5EE4)
    /* 6B858 8007B058 E45E20AC */  sw         $zero, %lo(D_800F5EE4)($at)
    /* 6B85C 8007B05C 0F80013C */  lui        $at, %hi(D_800F5EE0)
    /* 6B860 8007B060 E05E20AC */  sw         $zero, %lo(D_800F5EE0)($at)
    /* 6B864 8007B064 0F80013C */  lui        $at, %hi(D_800F5EE8)
    /* 6B868 8007B068 E85E20AC */  sw         $zero, %lo(D_800F5EE8)($at)
  .L8007B06C:
    /* 6B86C 8007B06C 0F80013C */  lui        $at, %hi(D_800F5EF0)
    /* 6B870 8007B070 21082200 */  addu       $at, $at, $v0
    /* 6B874 8007B074 F05E20AC */  sw         $zero, %lo(D_800F5EF0)($at)
    /* 6B878 8007B078 FFFF6324 */  addiu      $v1, $v1, -0x1
    /* 6B87C 8007B07C FBFF6104 */  bgez       $v1, .L8007B06C
    /* 6B880 8007B080 F0FF4224 */   addiu     $v0, $v0, -0x10
    /* 6B884 8007B084 0F80013C */  lui        $at, %hi(D_800F5F70)
    /* 6B888 8007B088 20EF010C */  jal        func_8007BC80
    /* 6B88C 8007B08C 705F20AC */   sw        $zero, %lo(D_800F5F70)($at)
    /* 6B890 8007B090 0880043C */  lui        $a0, %hi(func_8007ACF4)
    /* 6B894 8007B094 B2EF010C */  jal        func_8007BEC8
    /* 6B898 8007B098 F4AC8424 */   addiu     $a0, $a0, %lo(func_8007ACF4)
    /* 6B89C 8007B09C 0880043C */  lui        $a0, %hi(func_8007BB74)
    /* 6B8A0 8007B0A0 B5EF010C */  jal        func_8007BED4
    /* 6B8A4 8007B0A4 74BB8424 */   addiu     $a0, $a0, %lo(func_8007BB74)
    /* 6B8A8 8007B0A8 0880043C */  lui        $a0, %hi(func_8007BC48)
    /* 6B8AC 8007B0AC B8EF010C */  jal        func_8007BEE0
    /* 6B8B0 8007B0B0 48BC8424 */   addiu     $a0, $a0, %lo(func_8007BC48)
    /* 6B8B4 8007B0B4 0880043C */  lui        $a0, %hi(func_8007BAD0)
    /* 6B8B8 8007B0B8 AFEF010C */  jal        func_8007BEBC
    /* 6B8BC 8007B0BC D0BA8424 */   addiu     $a0, $a0, %lo(func_8007BAD0)
    /* 6B8C0 8007B0C0 A6F8010C */  jal        func_8007E298
    /* 6B8C4 8007B0C4 00000000 */   nop
    /* 6B8C8 8007B0C8 8EF7010C */  jal        func_8007DE38
    /* 6B8CC 8007B0CC 21200000 */   addu      $a0, $zero, $zero
    /* 6B8D0 8007B0D0 01000224 */  addiu      $v0, $zero, 0x1
  .L8007B0D4:
    /* 6B8D4 8007B0D4 1800BF8F */  lw         $ra, 0x18($sp)
    /* 6B8D8 8007B0D8 1400B18F */  lw         $s1, 0x14($sp)
    /* 6B8DC 8007B0DC 1000B08F */  lw         $s0, 0x10($sp)
    /* 6B8E0 8007B0E0 0800E003 */  jr         $ra
    /* 6B8E4 8007B0E4 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8007AFA4
