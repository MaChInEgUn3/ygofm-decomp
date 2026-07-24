nonmatching func_8007A634, 0xD8

glabel func_8007A634
    /* 6AE34 8007A634 0980023C */  lui        $v0, %hi(D_800937A4)
    /* 6AE38 8007A638 A437428C */  lw         $v0, %lo(D_800937A4)($v0)
    /* 6AE3C 8007A63C D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 6AE40 8007A640 1400B1AF */  sw         $s1, 0x14($sp)
    /* 6AE44 8007A644 0980113C */  lui        $s1, %hi(D_800937BD)
    /* 6AE48 8007A648 BD373126 */  addiu      $s1, $s1, %lo(D_800937BD)
    /* 6AE4C 8007A64C 2000BFAF */  sw         $ra, 0x20($sp)
    /* 6AE50 8007A650 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 6AE54 8007A654 1800B2AF */  sw         $s2, 0x18($sp)
    /* 6AE58 8007A658 1000B0AF */  sw         $s0, 0x10($sp)
    /* 6AE5C 8007A65C 00004290 */  lbu        $v0, 0x0($v0)
    /* 6AE60 8007A660 FFFF3326 */  addiu      $s3, $s1, -0x1
    /* 6AE64 8007A664 03005230 */  andi       $s2, $v0, 0x3
  .L8007A668:
    /* 6AE68 8007A668 64E4010C */  jal        func_80079190
    /* 6AE6C 8007A66C 00000000 */   nop
    /* 6AE70 8007A670 21804000 */  addu       $s0, $v0, $zero
    /* 6AE74 8007A674 1A000012 */  beqz       $s0, .L8007A6E0
    /* 6AE78 8007A678 04000232 */   andi      $v0, $s0, 0x4
    /* 6AE7C 8007A67C 0B004010 */  beqz       $v0, .L8007A6AC
    /* 6AE80 8007A680 02000232 */   andi      $v0, $s0, 0x2
    /* 6AE84 8007A684 0980023C */  lui        $v0, %hi(D_800934E4)
    /* 6AE88 8007A688 E434428C */  lw         $v0, %lo(D_800934E4)($v0)
    /* 6AE8C 8007A68C 00000000 */  nop
    /* 6AE90 8007A690 05004010 */  beqz       $v0, .L8007A6A8
    /* 6AE94 8007A694 00000000 */   nop
    /* 6AE98 8007A698 00002492 */  lbu        $a0, 0x0($s1)
    /* 6AE9C 8007A69C 0F80053C */  lui        $a1, %hi(D_800F5DB0)
    /* 6AEA0 8007A6A0 09F84000 */  jalr       $v0
    /* 6AEA4 8007A6A4 B05DA524 */   addiu     $a1, $a1, %lo(D_800F5DB0)
  .L8007A6A8:
    /* 6AEA8 8007A6A8 02000232 */  andi       $v0, $s0, 0x2
  .L8007A6AC:
    /* 6AEAC 8007A6AC EEFF4010 */  beqz       $v0, .L8007A668
    /* 6AEB0 8007A6B0 00000000 */   nop
    /* 6AEB4 8007A6B4 0980023C */  lui        $v0, %hi(D_800934E0)
    /* 6AEB8 8007A6B8 E034428C */  lw         $v0, %lo(D_800934E0)($v0)
    /* 6AEBC 8007A6BC 00000000 */  nop
    /* 6AEC0 8007A6C0 E9FF4010 */  beqz       $v0, .L8007A668
    /* 6AEC4 8007A6C4 00000000 */   nop
    /* 6AEC8 8007A6C8 00006492 */  lbu        $a0, 0x0($s3)
    /* 6AECC 8007A6CC 0F80053C */  lui        $a1, %hi(D_800F5DA8)
    /* 6AED0 8007A6D0 09F84000 */  jalr       $v0
    /* 6AED4 8007A6D4 A85DA524 */   addiu     $a1, $a1, %lo(D_800F5DA8)
    /* 6AED8 8007A6D8 9AE90108 */  j          .L8007A668
    /* 6AEDC 8007A6DC 00000000 */   nop
  .L8007A6E0:
    /* 6AEE0 8007A6E0 0980023C */  lui        $v0, %hi(D_800937A4)
    /* 6AEE4 8007A6E4 A437428C */  lw         $v0, %lo(D_800937A4)($v0)
    /* 6AEE8 8007A6E8 00000000 */  nop
    /* 6AEEC 8007A6EC 000052A0 */  sb         $s2, 0x0($v0)
    /* 6AEF0 8007A6F0 2000BF8F */  lw         $ra, 0x20($sp)
    /* 6AEF4 8007A6F4 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 6AEF8 8007A6F8 1800B28F */  lw         $s2, 0x18($sp)
    /* 6AEFC 8007A6FC 1400B18F */  lw         $s1, 0x14($sp)
    /* 6AF00 8007A700 1000B08F */  lw         $s0, 0x10($sp)
    /* 6AF04 8007A704 0800E003 */  jr         $ra
    /* 6AF08 8007A708 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_8007A634
    /* 6AF0C 8007A70C 00000000 */  nop
