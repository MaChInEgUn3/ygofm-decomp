nonmatching func_8005C6A0, 0xC8

glabel func_8005C6A0
    /* 4CEA0 8005C6A0 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 4CEA4 8005C6A4 1800B0AF */  sw         $s0, 0x18($sp)
    /* 4CEA8 8005C6A8 21808000 */  addu       $s0, $a0, $zero
    /* 4CEAC 8005C6AC 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 4CEB0 8005C6B0 2000BFAF */  sw         $ra, 0x20($sp)
    /* 4CEB4 8005C6B4 0000038E */  lw         $v1, 0x0($s0)
    /* 4CEB8 8005C6B8 8003023C */  lui        $v0, (0x3800000 >> 16)
    /* 4CEBC 8005C6BC 06006210 */  beq        $v1, $v0, .L8005C6D8
    /* 4CEC0 8005C6C0 2188A000 */   addu      $s1, $a1, $zero
    /* 4CEC4 8005C6C4 0980023C */  lui        $v0, %hi(func_80089E20)
    /* 4CEC8 8005C6C8 0400038E */  lw         $v1, 0x4($s0)
    /* 4CECC 8005C6CC 209E4224 */  addiu      $v0, $v0, %lo(func_80089E20)
    /* 4CED0 8005C6D0 D5710108 */  j          .L8005C754
    /* 4CED4 8005C6D4 000062AC */   sw        $v0, 0x0($v1)
  .L8005C6D8:
    /* 4CED8 8005C6D8 0680023C */  lui        $v0, %hi(func_8005C7BC)
    /* 4CEDC 8005C6DC 0400038E */  lw         $v1, 0x4($s0)
    /* 4CEE0 8005C6E0 BCC74224 */  addiu      $v0, $v0, %lo(func_8005C7BC)
    /* 4CEE4 8005C6E4 000062AC */  sw         $v0, 0x0($v1)
    /* 4CEE8 8005C6E8 1B0E2492 */  lbu        $a0, 0xE1B($s1)
    /* 4CEEC 8005C6EC 0400058E */  lw         $a1, 0x4($s0)
    /* 4CEF0 8005C6F0 80200400 */  sll        $a0, $a0, 2
    /* 4CEF4 8005C6F4 E0018424 */  addiu      $a0, $a0, 0x1E0
    /* 4CEF8 8005C6F8 7627020C */  jal        func_80089DD8
    /* 4CEFC 8005C6FC 21202402 */   addu      $a0, $s1, $a0
    /* 4CF00 8005C700 21280000 */  addu       $a1, $zero, $zero
    /* 4CF04 8005C704 0400048E */  lw         $a0, 0x4($s0)
    /* 4CF08 8005C708 4C27020C */  jal        func_80089D30
    /* 4CF0C 8005C70C 21804000 */   addu      $s0, $v0, $zero
    /* 4CF10 8005C710 10004010 */  beqz       $v0, .L8005C754
    /* 4CF14 8005C714 00000000 */   nop
  .L8005C718:
    /* 4CF18 8005C718 21200000 */  addu       $a0, $zero, $zero
    /* 4CF1C 8005C71C 4C27020C */  jal        func_80089D30
    /* 4CF20 8005C720 1000A527 */   addiu     $a1, $sp, 0x10
    /* 4CF24 8005C724 07004010 */  beqz       $v0, .L8005C744
    /* 4CF28 8005C728 00000000 */   nop
    /* 4CF2C 8005C72C 1000A48F */  lw         $a0, 0x10($sp)
    /* 4CF30 8005C730 DA71010C */  jal        func_8005C768
    /* 4CF34 8005C734 00000000 */   nop
    /* 4CF38 8005C738 1400A38F */  lw         $v1, 0x14($sp)
    /* 4CF3C 8005C73C C6710108 */  j          .L8005C718
    /* 4CF40 8005C740 000062AC */   sw        $v0, 0x0($v1)
  .L8005C744:
    /* 4CF44 8005C744 1B0E2292 */  lbu        $v0, 0xE1B($s1)
    /* 4CF48 8005C748 00000000 */  nop
    /* 4CF4C 8005C74C 21105000 */  addu       $v0, $v0, $s0
    /* 4CF50 8005C750 1B0E22A2 */  sb         $v0, 0xE1B($s1)
  .L8005C754:
    /* 4CF54 8005C754 2000BF8F */  lw         $ra, 0x20($sp)
    /* 4CF58 8005C758 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 4CF5C 8005C75C 1800B08F */  lw         $s0, 0x18($sp)
    /* 4CF60 8005C760 0800E003 */  jr         $ra
    /* 4CF64 8005C764 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_8005C6A0
