nonmatching func_8002C6C8, 0x120

glabel func_8002C6C8
    /* 1CEC8 8002C6C8 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 1CECC 8002C6CC 0F80023C */  lui        $v0, %hi(D_800EAD88)
    /* 1CED0 8002C6D0 1400B1AF */  sw         $s1, 0x14($sp)
    /* 1CED4 8002C6D4 88AD5124 */  addiu      $s1, $v0, %lo(D_800EAD88)
    /* 1CED8 8002C6D8 0F80023C */  lui        $v0, %hi(D_800E9D90)
    /* 1CEDC 8002C6DC 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 1CEE0 8002C6E0 909D5324 */  addiu      $s3, $v0, %lo(D_800E9D90)
    /* 1CEE4 8002C6E4 0F80023C */  lui        $v0, %hi(D_800F2848)
    /* 1CEE8 8002C6E8 2000B4AF */  sw         $s4, 0x20($sp)
    /* 1CEEC 8002C6EC 48285424 */  addiu      $s4, $v0, %lo(D_800F2848)
    /* 1CEF0 8002C6F0 58038293 */  lbu        $v0, %gp_rel(D_8009B260)($gp)
    /* 1CEF4 8002C6F4 1800B2AF */  sw         $s2, 0x18($sp)
    /* 1CEF8 8002C6F8 08001224 */  addiu      $s2, $zero, 0x8
    /* 1CEFC 8002C6FC 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1CF00 8002C700 1C003026 */  addiu      $s0, $s1, 0x1C
    /* 1CF04 8002C704 2400BFAF */  sw         $ra, 0x24($sp)
    /* 1CF08 8002C708 FE004230 */  andi       $v0, $v0, 0xFE
    /* 1CF0C 8002C70C 580382A3 */  sb         $v0, %gp_rel(D_8009B260)($gp)
  .L8002C710:
    /* 1CF10 8002C710 00000392 */  lbu        $v1, 0x0($s0)
    /* 1CF14 8002C714 00000000 */  nop
    /* 1CF18 8002C718 80006230 */  andi       $v0, $v1, 0x80
    /* 1CF1C 8002C71C 24004010 */  beqz       $v0, .L8002C7B0
    /* 1CF20 8002C720 20006230 */   andi      $v0, $v1, 0x20
    /* 1CF24 8002C724 05004014 */  bnez       $v0, .L8002C73C
    /* 1CF28 8002C728 00000000 */   nop
    /* 1CF2C 8002C72C 58038293 */  lbu        $v0, %gp_rel(D_8009B260)($gp)
    /* 1CF30 8002C730 00000000 */  nop
    /* 1CF34 8002C734 01004234 */  ori        $v0, $v0, 0x1
    /* 1CF38 8002C738 580382A3 */  sb         $v0, %gp_rel(D_8009B260)($gp)
  .L8002C73C:
    /* 1CF3C 8002C73C 590380A3 */  sb         $zero, %gp_rel(D_8009B261)($gp)
    /* 1CF40 8002C740 00000392 */  lbu        $v1, 0x0($s0)
    /* 1CF44 8002C744 FEFF0586 */  lh         $a1, -0x2($s0)
    /* 1CF48 8002C748 40006230 */  andi       $v0, $v1, 0x40
    /* 1CF4C 8002C74C 04004014 */  bnez       $v0, .L8002C760
    /* 1CF50 8002C750 40006234 */   ori       $v0, $v1, 0x40
    /* 1CF54 8002C754 000002A2 */  sb         $v0, 0x0($s0)
    /* 1CF58 8002C758 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 1CF5C 8002C75C FEFF02A6 */  sh         $v0, -0x2($s0)
  .L8002C760:
    /* 1CF60 8002C760 0400628E */  lw         $v0, 0x4($s3)
    /* 1CF64 8002C764 FCFF0486 */  lh         $a0, -0x4($s0)
    /* 1CF68 8002C768 F8FF068E */  lw         $a2, -0x8($s0)
    /* 1CF6C 8002C76C F0FF02AE */  sw         $v0, -0x10($s0)
    /* 1CF70 8002C770 0800628E */  lw         $v0, 0x8($s3)
    /* 1CF74 8002C774 21382002 */  addu       $a3, $s1, $zero
    /* 1CF78 8002C778 5C0391AF */  sw         $s1, %gp_rel(D_8009B264)($gp)
    /* 1CF7C 8002C77C AC18050C */  jal        func_801462B0
    /* 1CF80 8002C780 ECFF02AE */   sw        $v0, -0x14($s0)
    /* 1CF84 8002C784 21200000 */  addu       $a0, $zero, $zero
    /* 1CF88 8002C788 2C1E020C */  jal        func_800878B0
    /* 1CF8C 8002C78C 21288000 */   addu      $a1, $a0, $zero
    /* 1CF90 8002C790 0E008486 */  lh         $a0, 0xE($s4)
    /* 1CF94 8002C794 341E020C */  jal        func_800878D0
    /* 1CF98 8002C798 00000000 */   nop
    /* 1CF9C 8002C79C 59038393 */  lbu        $v1, %gp_rel(D_8009B261)($gp)
    /* 1CFA0 8002C7A0 01000224 */  addiu      $v0, $zero, 0x1
    /* 1CFA4 8002C7A4 02006214 */  bne        $v1, $v0, .L8002C7B0
    /* 1CFA8 8002C7A8 00000000 */   nop
    /* 1CFAC 8002C7AC 000000A2 */  sb         $zero, 0x0($s0)
  .L8002C7B0:
    /* 1CFB0 8002C7B0 20001026 */  addiu      $s0, $s0, 0x20
    /* 1CFB4 8002C7B4 FFFF5226 */  addiu      $s2, $s2, -0x1
    /* 1CFB8 8002C7B8 D5FF4016 */  bnez       $s2, .L8002C710
    /* 1CFBC 8002C7BC 20003126 */   addiu     $s1, $s1, 0x20
    /* 1CFC0 8002C7C0 58038293 */  lbu        $v0, %gp_rel(D_8009B260)($gp)
    /* 1CFC4 8002C7C4 2400BF8F */  lw         $ra, 0x24($sp)
    /* 1CFC8 8002C7C8 2000B48F */  lw         $s4, 0x20($sp)
    /* 1CFCC 8002C7CC 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 1CFD0 8002C7D0 1800B28F */  lw         $s2, 0x18($sp)
    /* 1CFD4 8002C7D4 1400B18F */  lw         $s1, 0x14($sp)
    /* 1CFD8 8002C7D8 1000B08F */  lw         $s0, 0x10($sp)
    /* 1CFDC 8002C7DC 01004230 */  andi       $v0, $v0, 0x1
    /* 1CFE0 8002C7E0 0800E003 */  jr         $ra
    /* 1CFE4 8002C7E4 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_8002C6C8
