nonmatching func_8004C77C, 0xD0

glabel func_8004C77C
    /* 3CF7C 8004C77C 0A80023C */  lui        $v0, %hi(D_8009B458)
    /* 3CF80 8004C780 58B4428C */  lw         $v0, %lo(D_8009B458)($v0)
    /* 3CF84 8004C784 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 3CF88 8004C788 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 3CF8C 8004C78C 1800B2AF */  sw         $s2, 0x18($sp)
    /* 3CF90 8004C790 1400B1AF */  sw         $s1, 0x14($sp)
    /* 3CF94 8004C794 1000B0AF */  sw         $s0, 0x10($sp)
    /* 3CF98 8004C798 040840AC */  sw         $zero, 0x804($v0)
    /* 3CF9C 8004C79C 3A2F010C */  jal        func_8004BCE8
    /* 3CFA0 8004C7A0 000840A0 */   sb        $zero, 0x800($v0)
    /* 3CFA4 8004C7A4 0A80043C */  lui        $a0, %hi(D_8009B458)
    /* 3CFA8 8004C7A8 58B4848C */  lw         $a0, %lo(D_8009B458)($a0)
    /* 3CFAC 8004C7AC 00000000 */  nop
    /* 3CFB0 8004C7B0 FA078294 */  lhu        $v0, 0x7FA($a0)
    /* 3CFB4 8004C7B4 00000000 */  nop
    /* 3CFB8 8004C7B8 1D004010 */  beqz       $v0, .L8004C830
    /* 3CFBC 8004C7BC 21880000 */   addu      $s1, $zero, $zero
    /* 3CFC0 8004C7C0 18051224 */  addiu      $s2, $zero, 0x518
  .L8004C7C4:
    /* 3CFC4 8004C7C4 21809200 */  addu       $s0, $a0, $s2
    /* 3CFC8 8004C7C8 0000028E */  lw         $v0, 0x0($s0)
    /* 3CFCC 8004C7CC 21200002 */  addu       $a0, $s0, $zero
    /* 3CFD0 8004C7D0 CD2E010C */  jal        func_8004BB34
    /* 3CFD4 8004C7D4 040002AE */   sw        $v0, 0x4($s0)
    /* 3CFD8 8004C7D8 240000A2 */  sb         $zero, 0x24($s0)
    /* 3CFDC 8004C7DC 270000A2 */  sb         $zero, 0x27($s0)
    /* 3CFE0 8004C7E0 290000A2 */  sb         $zero, 0x29($s0)
    /* 3CFE4 8004C7E4 280000A2 */  sb         $zero, 0x28($s0)
    /* 3CFE8 8004C7E8 0A80033C */  lui        $v1, %hi(D_8009B458)
    /* 3CFEC 8004C7EC 58B4638C */  lw         $v1, %lo(D_8009B458)($v1)
    /* 3CFF0 8004C7F0 1C0002AE */  sw         $v0, 0x1C($s0)
    /* 3CFF4 8004C7F4 180000A6 */  sh         $zero, 0x18($s0)
    /* 3CFF8 8004C7F8 0408628C */  lw         $v0, 0x804($v1)
    /* 3CFFC 8004C7FC 00000000 */  nop
    /* 3D000 8004C800 03004010 */  beqz       $v0, .L8004C810
    /* 3D004 8004C804 00000000 */   nop
    /* 3D008 8004C808 7231010C */  jal        func_8004C5C8
    /* 3D00C 8004C80C 21200002 */   addu      $a0, $s0, $zero
  .L8004C810:
    /* 3D010 8004C810 0A80043C */  lui        $a0, %hi(D_8009B458)
    /* 3D014 8004C814 58B4848C */  lw         $a0, %lo(D_8009B458)($a0)
    /* 3D018 8004C818 00000000 */  nop
    /* 3D01C 8004C81C FA078294 */  lhu        $v0, 0x7FA($a0)
    /* 3D020 8004C820 01003126 */  addiu      $s1, $s1, 0x1
    /* 3D024 8004C824 2A102202 */  slt        $v0, $s1, $v0
    /* 3D028 8004C828 E6FF4014 */  bnez       $v0, .L8004C7C4
    /* 3D02C 8004C82C 2C005226 */   addiu     $s2, $s2, 0x2C
  .L8004C830:
    /* 3D030 8004C830 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 3D034 8004C834 1800B28F */  lw         $s2, 0x18($sp)
    /* 3D038 8004C838 1400B18F */  lw         $s1, 0x14($sp)
    /* 3D03C 8004C83C 1000B08F */  lw         $s0, 0x10($sp)
    /* 3D040 8004C840 21100000 */  addu       $v0, $zero, $zero
    /* 3D044 8004C844 0800E003 */  jr         $ra
    /* 3D048 8004C848 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8004C77C
