nonmatching func_8007A9AC, 0x60

glabel func_8007A9AC
    /* 6B1AC 8007A9AC 21280000 */  addu       $a1, $zero, $zero
    /* 6B1B0 8007A9B0 0F80023C */  lui        $v0, %hi(D_800F5EE8)
    /* 6B1B4 8007A9B4 E85E4224 */  addiu      $v0, $v0, %lo(D_800F5EE8)
    /* 6B1B8 8007A9B8 38FF4424 */  addiu      $a0, $v0, -0xC8
    /* 6B1BC 8007A9BC 000040AC */  sw         $zero, 0x0($v0)
    /* 6B1C0 8007A9C0 FCFF40AC */  sw         $zero, -0x4($v0)
    /* 6B1C4 8007A9C4 F8FF40AC */  sw         $zero, -0x8($v0)
  .L8007A9C8:
    /* 6B1C8 8007A9C8 03000324 */  addiu      $v1, $zero, 0x3
    /* 6B1CC 8007A9CC 03008224 */  addiu      $v0, $a0, 0x3
    /* 6B1D0 8007A9D0 000080AC */  sw         $zero, 0x0($a0)
    /* 6B1D4 8007A9D4 040080A0 */  sb         $zero, 0x4($a0)
  .L8007A9D8:
    /* 6B1D8 8007A9D8 050040A0 */  sb         $zero, 0x5($v0)
    /* 6B1DC 8007A9DC FFFF6324 */  addiu      $v1, $v1, -0x1
    /* 6B1E0 8007A9E0 FDFF6104 */  bgez       $v1, .L8007A9D8
    /* 6B1E4 8007A9E4 FFFF4224 */   addiu     $v0, $v0, -0x1
    /* 6B1E8 8007A9E8 0C0080AC */  sw         $zero, 0xC($a0)
    /* 6B1EC 8007A9EC 100080AC */  sw         $zero, 0x10($a0)
    /* 6B1F0 8007A9F0 140080AC */  sw         $zero, 0x14($a0)
    /* 6B1F4 8007A9F4 0100A524 */  addiu      $a1, $a1, 0x1
    /* 6B1F8 8007A9F8 0800A228 */  slti       $v0, $a1, 0x8
    /* 6B1FC 8007A9FC F2FF4014 */  bnez       $v0, .L8007A9C8
    /* 6B200 8007AA00 18008424 */   addiu     $a0, $a0, 0x18
    /* 6B204 8007AA04 0800E003 */  jr         $ra
    /* 6B208 8007AA08 00000000 */   nop
endlabel func_8007A9AC
