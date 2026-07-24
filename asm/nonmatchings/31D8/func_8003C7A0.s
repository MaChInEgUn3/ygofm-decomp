nonmatching func_8003C7A0, 0x12C

glabel func_8003C7A0
    /* 2CFA0 8003C7A0 7C048283 */  lb         $v0, %gp_rel(D_8009B384)($gp)
    /* 2CFA4 8003C7A4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2CFA8 8003C7A8 29004014 */  bnez       $v0, .L8003C850
    /* 2CFAC 8003C7AC 1000BFAF */   sw        $ra, 0x10($sp)
    /* 2CFB0 8003C7B0 0A80023C */  lui        $v0, %hi(D_8009B398)
    /* 2CFB4 8003C7B4 98B34294 */  lhu        $v0, %lo(D_8009B398)($v0)
    /* 2CFB8 8003C7B8 00000000 */  nop
    /* 2CFBC 8003C7BC 00A04230 */  andi       $v0, $v0, 0xA000
    /* 2CFC0 8003C7C0 23004010 */  beqz       $v0, .L8003C850
    /* 2CFC4 8003C7C4 00000000 */   nop
    /* 2CFC8 8003C7C8 0A80023C */  lui        $v0, %hi(D_8009B398)
    /* 2CFCC 8003C7CC 98B34294 */  lhu        $v0, %lo(D_8009B398)($v0)
    /* 2CFD0 8003C7D0 00000000 */  nop
    /* 2CFD4 8003C7D4 00204230 */  andi       $v0, $v0, 0x2000
    /* 2CFD8 8003C7D8 0C004010 */  beqz       $v0, .L8003C80C
    /* 2CFDC 8003C7DC 00000000 */   nop
    /* 2CFE0 8003C7E0 75048283 */  lb         $v0, %gp_rel(D_8009B37D)($gp)
    /* 2CFE4 8003C7E4 00000000 */  nop
    /* 2CFE8 8003C7E8 34004014 */  bnez       $v0, .L8003C8BC
    /* 2CFEC 8003C7EC 00000000 */   nop
    /* 2CFF0 8003C7F0 01000424 */  addiu      $a0, $zero, 0x1
    /* 2CFF4 8003C7F4 21108000 */  addu       $v0, $a0, $zero
    /* 2CFF8 8003C7F8 0A80013C */  lui        $at, %hi(D_8009B408)
    /* 2CFFC 8003C7FC 08B424A0 */  sb         $a0, %lo(D_8009B408)($at)
    /* 2D000 8003C800 750482A3 */  sb         $v0, %gp_rel(D_8009B37D)($gp)
    /* 2D004 8003C804 0BF20008 */  j          .L8003C82C
    /* 2D008 8003C808 00000000 */   nop
  .L8003C80C:
    /* 2D00C 8003C80C 75048283 */  lb         $v0, %gp_rel(D_8009B37D)($gp)
    /* 2D010 8003C810 00000000 */  nop
    /* 2D014 8003C814 29004010 */  beqz       $v0, .L8003C8BC
    /* 2D018 8003C818 00000000 */   nop
    /* 2D01C 8003C81C 21200000 */  addu       $a0, $zero, $zero
    /* 2D020 8003C820 0A80013C */  lui        $at, %hi(D_8009B408)
    /* 2D024 8003C824 08B420A0 */  sb         $zero, %lo(D_8009B408)($at)
    /* 2D028 8003C828 750480A3 */  sb         $zero, %gp_rel(D_8009B37D)($gp)
  .L8003C82C:
    /* 2D02C 8003C82C E81B010C */  jal        func_80046FA0
    /* 2D030 8003C830 00000000 */   nop
    /* 2D034 8003C834 B8FF000C */  jal        func_8003FEE0
    /* 2D038 8003C838 2F000424 */   addiu     $a0, $zero, 0x2F
    /* 2D03C 8003C83C 7C048483 */  lb         $a0, %gp_rel(D_8009B384)($gp)
    /* 2D040 8003C840 5AF1000C */  jal        func_8003C568
    /* 2D044 8003C844 00000000 */   nop
    /* 2D048 8003C848 2FF20008 */  j          .L8003C8BC
    /* 2D04C 8003C84C 00000000 */   nop
  .L8003C850:
    /* 2D050 8003C850 7C048283 */  lb         $v0, %gp_rel(D_8009B384)($gp)
    /* 2D054 8003C854 00000000 */  nop
    /* 2D058 8003C858 0F004010 */  beqz       $v0, .L8003C898
    /* 2D05C 8003C85C 00000000 */   nop
    /* 2D060 8003C860 0A80023C */  lui        $v0, %hi(D_8009B398)
    /* 2D064 8003C864 98B34294 */  lhu        $v0, %lo(D_8009B398)($v0)
    /* 2D068 8003C868 00000000 */  nop
    /* 2D06C 8003C86C C0004230 */  andi       $v0, $v0, 0xC0
    /* 2D070 8003C870 09004010 */  beqz       $v0, .L8003C898
    /* 2D074 8003C874 00000000 */   nop
    /* 2D078 8003C878 B8FF000C */  jal        func_8003FEE0
    /* 2D07C 8003C87C 07000424 */   addiu     $a0, $zero, 0x7
    /* 2D080 8003C880 7C048293 */  lbu        $v0, %gp_rel(D_8009B384)($gp)
    /* 2D084 8003C884 00000000 */  nop
    /* 2D088 8003C888 01004224 */  addiu      $v0, $v0, 0x1
    /* 2D08C 8003C88C 740482A3 */  sb         $v0, %gp_rel(D_8009B37C)($gp)
    /* 2D090 8003C890 2FF20008 */  j          .L8003C8BC
    /* 2D094 8003C894 00000000 */   nop
  .L8003C898:
    /* 2D098 8003C898 0A80023C */  lui        $v0, %hi(D_8009B398)
    /* 2D09C 8003C89C 98B34294 */  lhu        $v0, %lo(D_8009B398)($v0)
    /* 2D0A0 8003C8A0 00000000 */  nop
    /* 2D0A4 8003C8A4 20004230 */  andi       $v0, $v0, 0x20
    /* 2D0A8 8003C8A8 04004010 */  beqz       $v0, .L8003C8BC
    /* 2D0AC 8003C8AC 00000000 */   nop
    /* 2D0B0 8003C8B0 740480A3 */  sb         $zero, %gp_rel(D_8009B37C)($gp)
    /* 2D0B4 8003C8B4 B8FF000C */  jal        func_8003FEE0
    /* 2D0B8 8003C8B8 08000424 */   addiu     $a0, $zero, 0x8
  .L8003C8BC:
    /* 2D0BC 8003C8BC 1000BF8F */  lw         $ra, 0x10($sp)
    /* 2D0C0 8003C8C0 00000000 */  nop
    /* 2D0C4 8003C8C4 0800E003 */  jr         $ra
    /* 2D0C8 8003C8C8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8003C7A0
