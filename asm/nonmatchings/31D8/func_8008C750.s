nonmatching func_8008C750, 0x108

glabel func_8008C750
    /* 7CF50 8008C750 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 7CF54 8008C754 1400B1AF */  sw         $s1, 0x14($sp)
    /* 7CF58 8008C758 21888000 */  addu       $s1, $a0, $zero
    /* 7CF5C 8008C75C 1800BFAF */  sw         $ra, 0x18($sp)
    /* 7CF60 8008C760 1000B0AF */  sw         $s0, 0x10($sp)
    /* 7CF64 8008C764 0000238E */  lw         $v1, 0x0($s1)
    /* 7CF68 8008C768 0A001024 */  addiu      $s0, $zero, 0xA
    /* 7CF6C 8008C76C 14007010 */  beq        $v1, $s0, .L8008C7C0
    /* 7CF70 8008C770 0B006228 */   slti      $v0, $v1, 0xB
    /* 7CF74 8008C774 05004010 */  beqz       $v0, .L8008C78C
    /* 7CF78 8008C778 0B000224 */   addiu     $v0, $zero, 0xB
    /* 7CF7C 8008C77C 09006010 */  beqz       $v1, .L8008C7A4
    /* 7CF80 8008C780 21100000 */   addu      $v0, $zero, $zero
    /* 7CF84 8008C784 11320208 */  j          .L8008C844
    /* 7CF88 8008C788 00000000 */   nop
  .L8008C78C:
    /* 7CF8C 8008C78C 1C006210 */  beq        $v1, $v0, .L8008C800
    /* 7CF90 8008C790 14000224 */   addiu     $v0, $zero, 0x14
    /* 7CF94 8008C794 21006210 */  beq        $v1, $v0, .L8008C81C
    /* 7CF98 8008C798 21100000 */   addu      $v0, $zero, $zero
    /* 7CF9C 8008C79C 11320208 */  j          .L8008C844
    /* 7CFA0 8008C7A0 00000000 */   nop
  .L8008C7A4:
    /* 7CFA4 8008C7A4 0980043C */  lui        $a0, %hi(func_8008B974)
    /* 7CFA8 8008C7A8 74B98424 */  addiu      $a0, $a0, %lo(func_8008B974)
    /* 7CFAC 8008C7AC 0A80013C */  lui        $at, %hi(D_80099E98)
    /* 7CFB0 8008C7B0 3834020C */  jal        func_8008D0E0
    /* 7CFB4 8008C7B4 989E20AC */   sw        $zero, %lo(D_80099E98)($at)
    /* 7CFB8 8008C7B8 10320208 */  j          .L8008C840
    /* 7CFBC 8008C7BC 000030AE */   sw        $s0, 0x0($s1)
  .L8008C7C0:
    /* 7CFC0 8008C7C0 1080103C */  lui        $s0, %hi(D_800FE34C)
    /* 7CFC4 8008C7C4 4CE31026 */  addiu      $s0, $s0, %lo(D_800FE34C)
    /* 7CFC8 8008C7C8 0000028E */  lw         $v0, 0x0($s0)
    /* 7CFCC 8008C7CC 00000000 */  nop
    /* 7CFD0 8008C7D0 1C004014 */  bnez       $v0, .L8008C844
    /* 7CFD4 8008C7D4 01000224 */   addiu     $v0, $zero, 0x1
    /* 7CFD8 8008C7D8 20000426 */  addiu      $a0, $s0, 0x20
    /* 7CFDC 8008C7DC 34CE010C */  jal        func_800738D0
    /* 7CFE0 8008C7E0 01800534 */   ori       $a1, $zero, 0x8001
    /* 7CFE4 8008C7E4 06004104 */  bgez       $v0, .L8008C800
    /* 7CFE8 8008C7E8 100002AE */   sw        $v0, 0x10($s0)
    /* 7CFEC 8008C7EC FCFF0326 */  addiu      $v1, $s0, -0x4
    /* 7CFF0 8008C7F0 05000224 */  addiu      $v0, $zero, 0x5
    /* 7CFF4 8008C7F4 040062AC */  sw         $v0, 0x4($v1)
    /* 7CFF8 8008C7F8 11320208 */  j          .L8008C844
    /* 7CFFC 8008C7FC 01000224 */   addiu     $v0, $zero, 0x1
  .L8008C800:
    /* 7D000 8008C800 14000224 */  addiu      $v0, $zero, 0x14
    /* 7D004 8008C804 0980043C */  lui        $a0, %hi(func_8008C224)
    /* 7D008 8008C808 24C28424 */  addiu      $a0, $a0, %lo(func_8008C224)
    /* 7D00C 8008C80C 3834020C */  jal        func_8008D0E0
    /* 7D010 8008C810 000022AE */   sw        $v0, 0x0($s1)
    /* 7D014 8008C814 11320208 */  j          .L8008C844
    /* 7D018 8008C818 21100000 */   addu      $v0, $zero, $zero
  .L8008C81C:
    /* 7D01C 8008C81C 1080103C */  lui        $s0, %hi(D_800FE35C)
    /* 7D020 8008C820 5CE31026 */  addiu      $s0, $s0, %lo(D_800FE35C)
    /* 7D024 8008C824 0000048E */  lw         $a0, 0x0($s0)
    /* 7D028 8008C828 44CE010C */  jal        func_80073910
    /* 7D02C 8008C82C 00000000 */   nop
    /* 7D030 8008C830 01000224 */  addiu      $v0, $zero, 0x1
    /* 7D034 8008C834 FFFF0324 */  addiu      $v1, $zero, -0x1
    /* 7D038 8008C838 11320208 */  j          .L8008C844
    /* 7D03C 8008C83C 000003AE */   sw        $v1, 0x0($s0)
  .L8008C840:
    /* 7D040 8008C840 21100000 */  addu       $v0, $zero, $zero
  .L8008C844:
    /* 7D044 8008C844 1800BF8F */  lw         $ra, 0x18($sp)
    /* 7D048 8008C848 1400B18F */  lw         $s1, 0x14($sp)
    /* 7D04C 8008C84C 1000B08F */  lw         $s0, 0x10($sp)
    /* 7D050 8008C850 0800E003 */  jr         $ra
    /* 7D054 8008C854 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8008C750
