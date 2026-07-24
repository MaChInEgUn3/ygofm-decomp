nonmatching func_8007CB48, 0x94

glabel func_8007CB48
    /* 6D348 8007CB48 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 6D34C 8007CB4C 1400B1AF */  sw         $s1, 0x14($sp)
    /* 6D350 8007CB50 2188A000 */  addu       $s1, $a1, $zero
    /* 6D354 8007CB54 1000B0AF */  sw         $s0, 0x10($sp)
    /* 6D358 8007CB58 FF009030 */  andi       $s0, $a0, 0xFF
    /* 6D35C 8007CB5C 1800BFAF */  sw         $ra, 0x18($sp)
    /* 6D360 8007CB60 F7F2010C */  jal        func_8007CBDC
    /* 6D364 8007CB64 21200002 */   addu      $a0, $s0, $zero
    /* 6D368 8007CB68 0980033C */  lui        $v1, %hi(D_80093898)
    /* 6D36C 8007CB6C 98386324 */  addiu      $v1, $v1, %lo(D_80093898)
    /* 6D370 8007CB70 00006290 */  lbu        $v0, 0x0($v1)
    /* 6D374 8007CB74 00000000 */  nop
    /* 6D378 8007CB78 10004230 */  andi       $v0, $v0, 0x10
    /* 6D37C 8007CB7C 04004010 */  beqz       $v0, .L8007CB90
    /* 6D380 8007CB80 02000224 */   addiu     $v0, $zero, 0x2
    /* 6D384 8007CB84 080062AC */  sw         $v0, 0x8($v1)
    /* 6D388 8007CB88 0C000224 */  addiu      $v0, $zero, 0xC
    /* 6D38C 8007CB8C 0C0062AC */  sw         $v0, 0xC($v1)
  .L8007CB90:
    /* 6D390 8007CB90 0F80023C */  lui        $v0, %hi(D_800F5F88)
    /* 6D394 8007CB94 885F428C */  lw         $v0, %lo(D_800F5F88)($v0)
    /* 6D398 8007CB98 00000000 */  nop
    /* 6D39C 8007CB9C 0A004010 */  beqz       $v0, .L8007CBC8
    /* 6D3A0 8007CBA0 00000000 */   nop
    /* 6D3A4 8007CBA4 E8FF628C */  lw         $v0, -0x18($v1)
    /* 6D3A8 8007CBA8 00000000 */  nop
    /* 6D3AC 8007CBAC 06004010 */  beqz       $v0, .L8007CBC8
    /* 6D3B0 8007CBB0 21200002 */   addu      $a0, $s0, $zero
    /* 6D3B4 8007CBB4 0F80023C */  lui        $v0, %hi(D_800F5F88)
    /* 6D3B8 8007CBB8 885F428C */  lw         $v0, %lo(D_800F5F88)($v0)
    /* 6D3BC 8007CBBC 00000000 */  nop
    /* 6D3C0 8007CBC0 09F84000 */  jalr       $v0
    /* 6D3C4 8007CBC4 21282002 */   addu      $a1, $s1, $zero
  .L8007CBC8:
    /* 6D3C8 8007CBC8 1800BF8F */  lw         $ra, 0x18($sp)
    /* 6D3CC 8007CBCC 1400B18F */  lw         $s1, 0x14($sp)
    /* 6D3D0 8007CBD0 1000B08F */  lw         $s0, 0x10($sp)
    /* 6D3D4 8007CBD4 0800E003 */  jr         $ra
    /* 6D3D8 8007CBD8 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8007CB48
