nonmatching func_8007CA5C, 0xEC

glabel func_8007CA5C
    /* 6D25C 8007CA5C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 6D260 8007CA60 FF008730 */  andi       $a3, $a0, 0xFF
    /* 6D264 8007CA64 02000224 */  addiu      $v0, $zero, 0x2
    /* 6D268 8007CA68 1300E214 */  bne        $a3, $v0, .L8007CAB8
    /* 6D26C 8007CA6C 1000BFAF */   sw        $ra, 0x10($sp)
    /* 6D270 8007CA70 0980063C */  lui        $a2, %hi(D_80093884)
    /* 6D274 8007CA74 8438C624 */  addiu      $a2, $a2, %lo(D_80093884)
    /* 6D278 8007CA78 0000C390 */  lbu        $v1, 0x0($a2)
    /* 6D27C 8007CA7C 0E000224 */  addiu      $v0, $zero, 0xE
    /* 6D280 8007CA80 0E006214 */  bne        $v1, $v0, .L8007CABC
    /* 6D284 8007CA84 FF008330 */   andi      $v1, $a0, 0xFF
    /* 6D288 8007CA88 2900C290 */  lbu        $v0, 0x29($a2)
    /* 6D28C 8007CA8C 0100C390 */  lbu        $v1, 0x1($a2)
    /* 6D290 8007CA90 00000000 */  nop
    /* 6D294 8007CA94 26104300 */  xor        $v0, $v0, $v1
    /* 6D298 8007CA98 80004230 */  andi       $v0, $v0, 0x80
    /* 6D29C 8007CA9C 05004010 */  beqz       $v0, .L8007CAB4
    /* 6D2A0 8007CAA0 0F000224 */   addiu     $v0, $zero, 0xF
    /* 6D2A4 8007CAA4 2000C2AC */  sw         $v0, 0x20($a2)
    /* 6D2A8 8007CAA8 03000224 */  addiu      $v0, $zero, 0x3
    /* 6D2AC 8007CAAC 1C00C7AC */  sw         $a3, 0x1C($a2)
    /* 6D2B0 8007CAB0 3C00C2AC */  sw         $v0, 0x3C($a2)
  .L8007CAB4:
    /* 6D2B4 8007CAB4 2900C3A0 */  sb         $v1, 0x29($a2)
  .L8007CAB8:
    /* 6D2B8 8007CAB8 FF008330 */  andi       $v1, $a0, 0xFF
  .L8007CABC:
    /* 6D2BC 8007CABC 05000224 */  addiu      $v0, $zero, 0x5
    /* 6D2C0 8007CAC0 1D006214 */  bne        $v1, $v0, .L8007CB38
    /* 6D2C4 8007CAC4 00000000 */   nop
    /* 6D2C8 8007CAC8 0980043C */  lui        $a0, %hi(D_80093898)
    /* 6D2CC 8007CACC 98388424 */  addiu      $a0, $a0, %lo(D_80093898)
    /* 6D2D0 8007CAD0 00008290 */  lbu        $v0, 0x0($a0)
    /* 6D2D4 8007CAD4 00000000 */  nop
    /* 6D2D8 8007CAD8 10004230 */  andi       $v0, $v0, 0x10
    /* 6D2DC 8007CADC 13004010 */  beqz       $v0, .L8007CB2C
    /* 6D2E0 8007CAE0 01000224 */   addiu     $v0, $zero, 0x1
    /* 6D2E4 8007CAE4 0F80033C */  lui        $v1, %hi(D_800F5F84)
    /* 6D2E8 8007CAE8 845F638C */  lw         $v1, %lo(D_800F5F84)($v1)
    /* 6D2EC 8007CAEC 02000224 */  addiu      $v0, $zero, 0x2
    /* 6D2F0 8007CAF0 080082AC */  sw         $v0, 0x8($a0)
    /* 6D2F4 8007CAF4 0C000224 */  addiu      $v0, $zero, 0xC
    /* 6D2F8 8007CAF8 0F006010 */  beqz       $v1, .L8007CB38
    /* 6D2FC 8007CAFC 0C0082AC */   sw        $v0, 0xC($a0)
    /* 6D300 8007CB00 E8FF828C */  lw         $v0, -0x18($a0)
    /* 6D304 8007CB04 00000000 */  nop
    /* 6D308 8007CB08 0B004010 */  beqz       $v0, .L8007CB38
    /* 6D30C 8007CB0C 00000000 */   nop
    /* 6D310 8007CB10 0F80023C */  lui        $v0, %hi(D_800F5F84)
    /* 6D314 8007CB14 845F428C */  lw         $v0, %lo(D_800F5F84)($v0)
    /* 6D318 8007CB18 00000000 */  nop
    /* 6D31C 8007CB1C 09F84000 */  jalr       $v0
    /* 6D320 8007CB20 05000424 */   addiu     $a0, $zero, 0x5
    /* 6D324 8007CB24 CEF20108 */  j          .L8007CB38
    /* 6D328 8007CB28 00000000 */   nop
  .L8007CB2C:
    /* 6D32C 8007CB2C 080082AC */  sw         $v0, 0x8($a0)
    /* 6D330 8007CB30 0B000224 */  addiu      $v0, $zero, 0xB
    /* 6D334 8007CB34 0C0082AC */  sw         $v0, 0xC($a0)
  .L8007CB38:
    /* 6D338 8007CB38 1000BF8F */  lw         $ra, 0x10($sp)
    /* 6D33C 8007CB3C 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 6D340 8007CB40 0800E003 */  jr         $ra
    /* 6D344 8007CB44 00000000 */   nop
endlabel func_8007CA5C
