nonmatching func_8008BFA0, 0x188

glabel func_8008BFA0
    /* 7C7A0 8008BFA0 C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* 7C7A4 8008BFA4 2400B3AF */  sw         $s3, 0x24($sp)
    /* 7C7A8 8008BFA8 21988000 */  addu       $s3, $a0, $zero
    /* 7C7AC 8008BFAC 2800B4AF */  sw         $s4, 0x28($sp)
    /* 7C7B0 8008BFB0 21A0A000 */  addu       $s4, $a1, $zero
    /* 7C7B4 8008BFB4 2C00B5AF */  sw         $s5, 0x2C($sp)
    /* 7C7B8 8008BFB8 21A8C000 */  addu       $s5, $a2, $zero
    /* 7C7BC 8008BFBC 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 7C7C0 8008BFC0 1080113C */  lui        $s1, %hi(D_800FE35C)
    /* 7C7C4 8008BFC4 5CE33126 */  addiu      $s1, $s1, %lo(D_800FE35C)
    /* 7C7C8 8008BFC8 3000BFAF */  sw         $ra, 0x30($sp)
    /* 7C7CC 8008BFCC 2000B2AF */  sw         $s2, 0x20($sp)
    /* 7C7D0 8008BFD0 1800B0AF */  sw         $s0, 0x18($sp)
    /* 7C7D4 8008BFD4 0000228E */  lw         $v0, 0x0($s1)
    /* 7C7D8 8008BFD8 00000000 */  nop
    /* 7C7DC 8008BFDC 06004004 */  bltz       $v0, .L8008BFF8
    /* 7C7E0 8008BFE0 21900000 */   addu      $s2, $zero, $zero
    /* 7C7E4 8008BFE4 0180043C */  lui        $a0, %hi(D_80012574)
    /* 7C7E8 8008BFE8 1C3A020C */  jal        func_8008E870
    /* 7C7EC 8008BFEC 74258424 */   addiu     $a0, $a0, %lo(D_80012574)
    /* 7C7F0 8008BFF0 41300208 */  j          .L8008C104
    /* 7C7F4 8008BFF4 FFFF0224 */   addiu     $v0, $zero, -0x1
  .L8008BFF8:
    /* 7C7F8 8008BFF8 21206002 */  addu       $a0, $s3, $zero
    /* 7C7FC 8008BFFC 10003026 */  addiu      $s0, $s1, 0x10
    /* 7C800 8008C000 1D34020C */  jal        func_8008D074
    /* 7C804 8008C004 21280002 */   addu      $a1, $s0, $zero
    /* 7C808 8008C008 21200002 */  addu       $a0, $s0, $zero
    /* 7C80C 8008C00C 7439020C */  jal        func_8008E5D0
    /* 7C810 8008C010 21288002 */   addu      $a1, $s4, $zero
    /* 7C814 8008C014 FCFF33AE */  sw         $s3, -0x4($s1)
    /* 7C818 8008C018 ECFF3426 */  addiu      $s4, $s1, -0x14
    /* 7C81C 8008C01C 02001124 */  addiu      $s1, $zero, 0x2
  .L8008C020:
    /* 7C820 8008C020 21200002 */  addu       $a0, $s0, $zero
  .L8008C024:
    /* 7C824 8008C024 34CE010C */  jal        func_800738D0
    /* 7C828 8008C028 01000524 */   addiu     $a1, $zero, 0x1
    /* 7C82C 8008C02C 2C004104 */  bgez       $v0, .L8008C0E0
    /* 7C830 8008C030 00000000 */   nop
    /* 7C834 8008C034 3533020C */  jal        func_8008CCD4
    /* 7C838 8008C038 21200000 */   addu      $a0, $zero, $zero
    /* 7C83C 8008C03C DCFF038E */  lw         $v1, -0x24($s0)
    /* 7C840 8008C040 1080013C */  lui        $at, %hi(D_800FE3A0)
    /* 7C844 8008C044 06006018 */  blez       $v1, .L8008C060
    /* 7C848 8008C048 A0E322AC */   sw        $v0, %lo(D_800FE3A0)($at)
    /* 7C84C 8008C04C 0180043C */  lui        $a0, %hi(D_80012478)
    /* 7C850 8008C050 1C3A020C */  jal        func_8008E870
    /* 7C854 8008C054 78248424 */   addiu     $a0, $a0, %lo(D_80012478)
    /* 7C858 8008C058 21300208 */  j          .L8008C084
    /* 7C85C 8008C05C 21200000 */   addu      $a0, $zero, $zero
  .L8008C060:
    /* 7C860 8008C060 0980043C */  lui        $a0, %hi(func_8008BCF8)
    /* 7C864 8008C064 F8BC8424 */  addiu      $a0, $a0, %lo(func_8008BCF8)
    /* 7C868 8008C068 DCFF11AE */  sw         $s1, -0x24($s0)
    /* 7C86C 8008C06C 040080AE */  sw         $zero, 0x4($s4)
    /* 7C870 8008C070 080080AE */  sw         $zero, 0x8($s4)
    /* 7C874 8008C074 1080013C */  lui        $at, %hi(D_800FE358)
    /* 7C878 8008C078 3834020C */  jal        func_8008D0E0
    /* 7C87C 8008C07C 58E333AC */   sw        $s3, %lo(D_800FE358)($at)
    /* 7C880 8008C080 21200000 */  addu       $a0, $zero, $zero
  .L8008C084:
    /* 7C884 8008C084 21280000 */  addu       $a1, $zero, $zero
    /* 7C888 8008C088 3A33020C */  jal        func_8008CCE8
    /* 7C88C 8008C08C 1000A627 */   addiu     $a2, $sp, 0x10
    /* 7C890 8008C090 1080043C */  lui        $a0, %hi(D_800FE3A0)
    /* 7C894 8008C094 A0E3848C */  lw         $a0, %lo(D_800FE3A0)($a0)
    /* 7C898 8008C098 3533020C */  jal        func_8008CCD4
    /* 7C89C 8008C09C 00000000 */   nop
    /* 7C8A0 8008C0A0 1000A38F */  lw         $v1, 0x10($sp)
    /* 7C8A4 8008C0A4 03000224 */  addiu      $v0, $zero, 0x3
    /* 7C8A8 8008C0A8 DEFF6210 */  beq        $v1, $v0, .L8008C024
    /* 7C8AC 8008C0AC 21200002 */   addu      $a0, $s0, $zero
    /* 7C8B0 8008C0B0 05007114 */  bne        $v1, $s1, .L8008C0C8
    /* 7C8B4 8008C0B4 00000000 */   nop
    /* 7C8B8 8008C0B8 01005226 */  addiu      $s2, $s2, 0x1
    /* 7C8BC 8008C0BC 0500422A */  slti       $v0, $s2, 0x5
    /* 7C8C0 8008C0C0 D7FF4014 */  bnez       $v0, .L8008C020
    /* 7C8C4 8008C0C4 00000000 */   nop
  .L8008C0C8:
    /* 7C8C8 8008C0C8 02006014 */  bnez       $v1, .L8008C0D4
    /* 7C8CC 8008C0CC 05000224 */   addiu     $v0, $zero, 0x5
    /* 7C8D0 8008C0D0 1000A2AF */  sw         $v0, 0x10($sp)
  .L8008C0D4:
    /* 7C8D4 8008C0D4 1000A28F */  lw         $v0, 0x10($sp)
    /* 7C8D8 8008C0D8 41300208 */  j          .L8008C104
    /* 7C8DC 8008C0DC 00000000 */   nop
  .L8008C0E0:
    /* 7C8E0 8008C0E0 44CE010C */  jal        func_80073910
    /* 7C8E4 8008C0E4 21204000 */   addu      $a0, $v0, $zero
    /* 7C8E8 8008C0E8 5835020C */  jal        func_8008D560
    /* 7C8EC 8008C0EC 00000000 */   nop
    /* 7C8F0 8008C0F0 21200002 */  addu       $a0, $s0, $zero
    /* 7C8F4 8008C0F4 34CE010C */  jal        func_800738D0
    /* 7C8F8 8008C0F8 0080A536 */   ori       $a1, $s5, 0x8000
    /* 7C8FC 8008C0FC F0FF02AE */  sw         $v0, -0x10($s0)
    /* 7C900 8008C100 21100000 */  addu       $v0, $zero, $zero
  .L8008C104:
    /* 7C904 8008C104 3000BF8F */  lw         $ra, 0x30($sp)
    /* 7C908 8008C108 2C00B58F */  lw         $s5, 0x2C($sp)
    /* 7C90C 8008C10C 2800B48F */  lw         $s4, 0x28($sp)
    /* 7C910 8008C110 2400B38F */  lw         $s3, 0x24($sp)
    /* 7C914 8008C114 2000B28F */  lw         $s2, 0x20($sp)
    /* 7C918 8008C118 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 7C91C 8008C11C 1800B08F */  lw         $s0, 0x18($sp)
    /* 7C920 8008C120 0800E003 */  jr         $ra
    /* 7C924 8008C124 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel func_8008BFA0
