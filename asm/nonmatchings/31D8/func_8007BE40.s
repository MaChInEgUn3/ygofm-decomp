nonmatching func_8007BE40, 0x7C

glabel func_8007BE40
    /* 6C640 8007BE40 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 6C644 8007BE44 0980063C */  lui        $a2, %hi(D_800938C4)
    /* 6C648 8007BE48 C438C624 */  addiu      $a2, $a2, %lo(D_800938C4)
    /* 6C64C 8007BE4C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 6C650 8007BE50 0000C28C */  lw         $v0, 0x0($a2)
    /* 6C654 8007BE54 00000000 */  nop
    /* 6C658 8007BE58 1400401C */  bgtz       $v0, .L8007BEAC
    /* 6C65C 8007BE5C 21100000 */   addu      $v0, $zero, $zero
    /* 6C660 8007BE60 BCFFC28C */  lw         $v0, -0x44($a2)
    /* 6C664 8007BE64 00000000 */  nop
    /* 6C668 8007BE68 0F004010 */  beqz       $v0, .L8007BEA8
    /* 6C66C 8007BE6C BCFFC724 */   addiu     $a3, $a2, -0x44
    /* 6C670 8007BE70 DCFFC38C */  lw         $v1, -0x24($a2)
    /* 6C674 8007BE74 01000224 */  addiu      $v0, $zero, 0x1
    /* 6C678 8007BE78 0C006214 */  bne        $v1, $v0, .L8007BEAC
    /* 6C67C 8007BE7C 21100000 */   addu      $v0, $zero, $zero
    /* 6C680 8007BE80 1F000224 */  addiu      $v0, $zero, 0x1F
    /* 6C684 8007BE84 1C00E2AC */  sw         $v0, 0x1C($a3)
    /* 6C688 8007BE88 02000224 */  addiu      $v0, $zero, 0x2
    /* 6C68C 8007BE8C DCFFC2AC */  sw         $v0, -0x24($a2)
    /* 6C690 8007BE90 0B000224 */  addiu      $v0, $zero, 0xB
    /* 6C694 8007BE94 FF008430 */  andi       $a0, $a0, 0xFF
    /* 6C698 8007BE98 ECEF010C */  jal        func_8007BFB0
    /* 6C69C 8007BE9C 2400E2AC */   sw        $v0, 0x24($a3)
    /* 6C6A0 8007BEA0 ABEF0108 */  j          .L8007BEAC
    /* 6C6A4 8007BEA4 00000000 */   nop
  .L8007BEA8:
    /* 6C6A8 8007BEA8 21100000 */  addu       $v0, $zero, $zero
  .L8007BEAC:
    /* 6C6AC 8007BEAC 1000BF8F */  lw         $ra, 0x10($sp)
    /* 6C6B0 8007BEB0 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 6C6B4 8007BEB4 0800E003 */  jr         $ra
    /* 6C6B8 8007BEB8 00000000 */   nop
endlabel func_8007BE40
