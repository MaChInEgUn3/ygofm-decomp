nonmatching func_8007CF44, 0x178

glabel func_8007CF44
    /* 6D744 8007CF44 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 6D748 8007CF48 1800B2AF */  sw         $s2, 0x18($sp)
    /* 6D74C 8007CF4C 2190A000 */  addu       $s2, $a1, $zero
    /* 6D750 8007CF50 1400B1AF */  sw         $s1, 0x14($sp)
    /* 6D754 8007CF54 21888000 */  addu       $s1, $a0, $zero
    /* 6D758 8007CF58 FFFF0424 */  addiu      $a0, $zero, -0x1
    /* 6D75C 8007CF5C 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 6D760 8007CF60 5CD0010C */  jal        func_80074170
    /* 6D764 8007CF64 1000B0AF */   sw        $s0, 0x10($sp)
    /* 6D768 8007CF68 0980103C */  lui        $s0, %hi(D_800939F4)
    /* 6D76C 8007CF6C F4391026 */  addiu      $s0, $s0, %lo(D_800939F4)
    /* 6D770 8007CF70 F0FF038E */  lw         $v1, -0x10($s0)
    /* 6D774 8007CF74 00000000 */  nop
    /* 6D778 8007CF78 01006330 */  andi       $v1, $v1, 0x1
    /* 6D77C 8007CF7C 15006010 */  beqz       $v1, .L8007CFD4
    /* 6D780 8007CF80 000002AE */   sw        $v0, 0x0($s0)
    /* 6D784 8007CF84 ECFF028E */  lw         $v0, -0x14($s0)
    /* 6D788 8007CF88 00000000 */  nop
    /* 6D78C 8007CF8C 07004018 */  blez       $v0, .L8007CFAC
    /* 6D790 8007CF90 00000000 */   nop
    /* 6D794 8007CF94 E8FF048E */  lw         $a0, -0x18($s0)
    /* 6D798 8007CF98 E4FF058E */  lw         $a1, -0x1C($s0)
    /* 6D79C 8007CF9C 3CF9010C */  jal        func_8007E4F0
    /* 6D7A0 8007CFA0 00000000 */   nop
    /* 6D7A4 8007CFA4 29F40108 */  j          .L8007D0A4
    /* 6D7A8 8007CFA8 F4FF12AE */   sw        $s2, -0xC($s0)
  .L8007CFAC:
    /* 6D7AC 8007CFAC 8DF4010C */  jal        func_8007D234
    /* 6D7B0 8007CFB0 01000424 */   addiu     $a0, $zero, 0x1
    /* 6D7B4 8007CFB4 0980033C */  lui        $v1, %hi(D_800939FC)
    /* 6D7B8 8007CFB8 FC39638C */  lw         $v1, %lo(D_800939FC)($v1)
    /* 6D7BC 8007CFBC 00000000 */  nop
    /* 6D7C0 8007CFC0 38006010 */  beqz       $v1, .L8007D0A4
    /* 6D7C4 8007CFC4 00000000 */   nop
    /* 6D7C8 8007CFC8 ECFF028E */  lw         $v0, -0x14($s0)
    /* 6D7CC 8007CFCC 23F40108 */  j          .L8007D08C
    /* 6D7D0 8007CFD0 00000000 */   nop
  .L8007CFD4:
    /* 6D7D4 8007CFD4 ECFF028E */  lw         $v0, -0x14($s0)
    /* 6D7D8 8007CFD8 00000000 */  nop
    /* 6D7DC 8007CFDC 0D004018 */  blez       $v0, .L8007D014
    /* 6D7E0 8007CFE0 00000000 */   nop
    /* 6D7E4 8007CFE4 E8FF048E */  lw         $a0, -0x18($s0)
    /* 6D7E8 8007CFE8 E4FF058E */  lw         $a1, -0x1C($s0)
    /* 6D7EC 8007CFEC F4F8010C */  jal        func_8007E3D0
    /* 6D7F0 8007CFF0 00000000 */   nop
    /* 6D7F4 8007CFF4 E4FF028E */  lw         $v0, -0x1C($s0)
    /* 6D7F8 8007CFF8 E8FF038E */  lw         $v1, -0x18($s0)
    /* 6D7FC 8007CFFC ECFF048E */  lw         $a0, -0x14($s0)
    /* 6D800 8007D000 80100200 */  sll        $v0, $v0, 2
    /* 6D804 8007D004 21186200 */  addu       $v1, $v1, $v0
    /* 6D808 8007D008 FFFF8424 */  addiu      $a0, $a0, -0x1
    /* 6D80C 8007D00C E8FF03AE */  sw         $v1, -0x18($s0)
    /* 6D810 8007D010 ECFF04AE */  sw         $a0, -0x14($s0)
  .L8007D014:
    /* 6D814 8007D014 5CD0010C */  jal        func_80074170
    /* 6D818 8007D018 FFFF0424 */   addiu     $a0, $zero, -0x1
    /* 6D81C 8007D01C FCFF038E */  lw         $v1, -0x4($s0)
    /* 6D820 8007D020 00000000 */  nop
    /* 6D824 8007D024 B0046324 */  addiu      $v1, $v1, 0x4B0
    /* 6D828 8007D028 2A186200 */  slt        $v1, $v1, $v0
    /* 6D82C 8007D02C 02006010 */  beqz       $v1, .L8007D038
    /* 6D830 8007D030 FFFF0224 */   addiu     $v0, $zero, -0x1
    /* 6D834 8007D034 ECFF02AE */  sw         $v0, -0x14($s0)
  .L8007D038:
    /* 6D838 8007D038 ECFF028E */  lw         $v0, -0x14($s0)
    /* 6D83C 8007D03C 00000000 */  nop
    /* 6D840 8007D040 09004010 */  beqz       $v0, .L8007D068
    /* 6D844 8007D044 00000000 */   nop
    /* 6D848 8007D048 5CD0010C */  jal        func_80074170
    /* 6D84C 8007D04C FFFF0424 */   addiu     $a0, $zero, -0x1
    /* 6D850 8007D050 FCFF038E */  lw         $v1, -0x4($s0)
    /* 6D854 8007D054 00000000 */  nop
    /* 6D858 8007D058 B0046324 */  addiu      $v1, $v1, 0x4B0
    /* 6D85C 8007D05C 2A186200 */  slt        $v1, $v1, $v0
    /* 6D860 8007D060 10006010 */  beqz       $v1, .L8007D0A4
    /* 6D864 8007D064 00000000 */   nop
  .L8007D068:
    /* 6D868 8007D068 8DF4010C */  jal        func_8007D234
    /* 6D86C 8007D06C 01000424 */   addiu     $a0, $zero, 0x1
    /* 6D870 8007D070 0980033C */  lui        $v1, %hi(D_800939FC)
    /* 6D874 8007D074 FC39638C */  lw         $v1, %lo(D_800939FC)($v1)
    /* 6D878 8007D078 00000000 */  nop
    /* 6D87C 8007D07C 09006010 */  beqz       $v1, .L8007D0A4
    /* 6D880 8007D080 02001124 */   addiu     $s1, $zero, 0x2
    /* 6D884 8007D084 ECFF028E */  lw         $v0, -0x14($s0)
    /* 6D888 8007D088 00000000 */  nop
  .L8007D08C:
    /* 6D88C 8007D08C 03004104 */  bgez       $v0, .L8007D09C
    /* 6D890 8007D090 FF002432 */   andi      $a0, $s1, 0xFF
    /* 6D894 8007D094 05001124 */  addiu      $s1, $zero, 0x5
    /* 6D898 8007D098 FF002432 */  andi       $a0, $s1, 0xFF
  .L8007D09C:
    /* 6D89C 8007D09C 09F86000 */  jalr       $v1
    /* 6D8A0 8007D0A0 21284002 */   addu      $a1, $s2, $zero
  .L8007D0A4:
    /* 6D8A4 8007D0A4 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 6D8A8 8007D0A8 1800B28F */  lw         $s2, 0x18($sp)
    /* 6D8AC 8007D0AC 1400B18F */  lw         $s1, 0x14($sp)
    /* 6D8B0 8007D0B0 1000B08F */  lw         $s0, 0x10($sp)
    /* 6D8B4 8007D0B4 0800E003 */  jr         $ra
    /* 6D8B8 8007D0B8 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8007CF44
