nonmatching func_8003CA5C, 0x120

glabel func_8003CA5C
    /* 2D25C 8003CA5C E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 2D260 8003CA60 1000B0AF */  sw         $s0, 0x10($sp)
    /* 2D264 8003CA64 7004908F */  lw         $s0, %gp_rel(D_8009B378)($gp)
    /* 2D268 8003CA68 1800BFAF */  sw         $ra, 0x18($sp)
    /* 2D26C 8003CA6C 1400B1AF */  sw         $s1, 0x14($sp)
    /* 2D270 8003CA70 800A010C */  jal        func_80042A00
    /* 2D274 8003CA74 21200002 */   addu      $a0, $s0, $zero
    /* 2D278 8003CA78 5A000286 */  lh         $v0, 0x5A($s0)
    /* 2D27C 8003CA7C 00000000 */  nop
    /* 2D280 8003CA80 2D004014 */  bnez       $v0, .L8003CB38
    /* 2D284 8003CA84 0F80023C */   lui       $v0, %hi(D_800E9ECE)
    /* 2D288 8003CA88 6C000392 */  lbu        $v1, 0x6C($s0)
    /* 2D28C 8003CA8C 01001124 */  addiu      $s1, $zero, 0x1
    /* 2D290 8003CA90 12007110 */  beq        $v1, $s1, .L8003CADC
    /* 2D294 8003CA94 02006228 */   slti      $v0, $v1, 0x2
    /* 2D298 8003CA98 05004010 */  beqz       $v0, .L8003CAB0
    /* 2D29C 8003CA9C 02000224 */   addiu     $v0, $zero, 0x2
    /* 2D2A0 8003CAA0 07006010 */  beqz       $v1, .L8003CAC0
    /* 2D2A4 8003CAA4 0F80023C */   lui       $v0, %hi(D_800E9ECE)
    /* 2D2A8 8003CAA8 CEF20008 */  j          .L8003CB38
    /* 2D2AC 8003CAAC 00000000 */   nop
  .L8003CAB0:
    /* 2D2B0 8003CAB0 12006210 */  beq        $v1, $v0, .L8003CAFC
    /* 2D2B4 8003CAB4 0F80023C */   lui       $v0, %hi(D_800E9ECE)
    /* 2D2B8 8003CAB8 CEF20008 */  j          .L8003CB38
    /* 2D2BC 8003CABC 00000000 */   nop
  .L8003CAC0:
    /* 2D2C0 8003CAC0 21200002 */  addu       $a0, $s0, $zero
    /* 2D2C4 8003CAC4 0401010C */  jal        func_80040410
    /* 2D2C8 8003CAC8 01000524 */   addiu     $a1, $zero, 0x1
    /* 2D2CC 8003CACC 40FF0224 */  addiu      $v0, $zero, -0xC0
    /* 2D2D0 8003CAD0 6C0011A2 */  sb         $s1, 0x6C($s0)
    /* 2D2D4 8003CAD4 CDF20008 */  j          .L8003CB34
    /* 2D2D8 8003CAD8 360002A6 */   sh        $v0, 0x36($s0)
  .L8003CADC:
    /* 2D2DC 8003CADC 760A010C */  jal        func_800429D8
    /* 2D2E0 8003CAE0 21200002 */   addu      $a0, $s0, $zero
    /* 2D2E4 8003CAE4 21200002 */  addu       $a0, $s0, $zero
    /* 2D2E8 8003CAE8 0401010C */  jal        func_80040410
    /* 2D2EC 8003CAEC 02000524 */   addiu     $a1, $zero, 0x2
    /* 2D2F0 8003CAF0 02000224 */  addiu      $v0, $zero, 0x2
    /* 2D2F4 8003CAF4 CDF20008 */  j          .L8003CB34
    /* 2D2F8 8003CAF8 6C0002A2 */   sb        $v0, 0x6C($s0)
  .L8003CAFC:
    /* 2D2FC 8003CAFC 21200002 */  addu       $a0, $s0, $zero
    /* 2D300 8003CB00 0401010C */  jal        func_80040410
    /* 2D304 8003CB04 21280000 */   addu      $a1, $zero, $zero
    /* 2D308 8003CB08 30000286 */  lh         $v0, 0x30($s0)
    /* 2D30C 8003CB0C 00000000 */  nop
    /* 2D310 8003CB10 D1FF4228 */  slti       $v0, $v0, -0x2F
    /* 2D314 8003CB14 07004010 */  beqz       $v0, .L8003CB34
    /* 2D318 8003CB18 6C0000A2 */   sb        $zero, 0x6C($s0)
    /* 2D31C 8003CB1C B0000424 */  addiu      $a0, $zero, 0xB0
    /* 2D320 8003CB20 60010224 */  addiu      $v0, $zero, 0x160
    /* 2D324 8003CB24 3FD6000C */  jal        func_800358FC
    /* 2D328 8003CB28 300002A6 */   sh        $v0, 0x30($s0)
    /* 2D32C 8003CB2C 30004224 */  addiu      $v0, $v0, 0x30
    /* 2D330 8003CB30 320002A6 */  sh         $v0, 0x32($s0)
  .L8003CB34:
    /* 2D334 8003CB34 0F80023C */  lui        $v0, %hi(D_800E9ECE)
  .L8003CB38:
    /* 2D338 8003CB38 CE9E4290 */  lbu        $v0, %lo(D_800E9ECE)($v0)
    /* 2D33C 8003CB3C 00000000 */  nop
    /* 2D340 8003CB40 80004230 */  andi       $v0, $v0, 0x80
    /* 2D344 8003CB44 08004014 */  bnez       $v0, .L8003CB68
    /* 2D348 8003CB48 01000224 */   addiu     $v0, $zero, 0x1
    /* 2D34C 8003CB4C 0A80033C */  lui        $v1, %hi(D_8009B398)
    /* 2D350 8003CB50 98B36394 */  lhu        $v1, %lo(D_8009B398)($v1)
    /* 2D354 8003CB54 00000000 */  nop
    /* 2D358 8003CB58 E0006330 */  andi       $v1, $v1, 0xE0
    /* 2D35C 8003CB5C 02006014 */  bnez       $v1, .L8003CB68
    /* 2D360 8003CB60 21100000 */   addu      $v0, $zero, $zero
    /* 2D364 8003CB64 01000224 */  addiu      $v0, $zero, 0x1
  .L8003CB68:
    /* 2D368 8003CB68 1800BF8F */  lw         $ra, 0x18($sp)
    /* 2D36C 8003CB6C 1400B18F */  lw         $s1, 0x14($sp)
    /* 2D370 8003CB70 1000B08F */  lw         $s0, 0x10($sp)
    /* 2D374 8003CB74 0800E003 */  jr         $ra
    /* 2D378 8003CB78 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8003CA5C
